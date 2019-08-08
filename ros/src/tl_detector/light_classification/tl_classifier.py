from styx_msgs.msg import TrafficLight
#from pathlib import Path
import rospy
import tensorflow as tf
import cv2
import numpy as np
import os
import yaml

NUM_CLASSES = 4
MIN_SCORE_THR = .4

class TLClassifier(object):
    def __init__(self):
        # load classifier
        self.light_state = TrafficLight.UNKNOWN

        graph_to_load = 'frozen_inference_graph.pb'

        # Choose model for simulator or for real driving
        # if self.is_real:
        config_string = rospy.get_param("/traffic_light_config")
        self.config = yaml.load(config_string)
        self.is_real=self.config['is_site']
        if self.is_real:
            model_name = 'real_ssd_model_tf_1_4'
            rospy.loginfo("In real site environment...use {}/{}".format(
                model_name, graph_to_load))
        else:
            model_name = 'ssd_model_10000_tf_1_4'
            rospy.loginfo("In simulator environment...use {}/{}".format(
                model_name, graph_to_load))

        #p = Path(__file__).parents[4]
        #model_path = str(p) + '/traffic_light_classifier/' + model_name + '/' + graph_to_load
        model_path = '../../../traffic_light_classifier/' + model_name + '/' + graph_to_load
        rospy.logwarn("model_path={}".format(model_path))

        # Load saved model
        self.detection_graph = tf.Graph()
        with self.detection_graph.as_default():
            od_graph_def = tf.GraphDef()
            with tf.gfile.GFile(model_path, 'rb') as fid:
                serialized_graph = fid.read()
                od_graph_def.ParseFromString(serialized_graph)
                tf.import_graph_def(od_graph_def, name='')

        rospy.loginfo("TL Classifier ---> Model Loaded!")
        
        # Tensorflow session for detection
        config = tf.ConfigProto()
        config.gpu_options.allow_growth = True
        self.sess = tf.Session(graph=self.detection_graph, config=config)

        # Input and output Tensors for detection_graph
        self.image_tensor = self.detection_graph.get_tensor_by_name('image_tensor:0')
        
        self.num_detections = self.detection_graph.get_tensor_by_name('num_detections:0')
        self.detection_scores = self.detection_graph.get_tensor_by_name('detection_scores:0')
        self.detection_classes = self.detection_graph.get_tensor_by_name('detection_classes:0')
        self.detection_boxes = self.detection_graph.get_tensor_by_name('detection_boxes:0')
        
        self.category_index = {1: {'id': 1, 'name': 'Green'}, 2: {'id': 2, 'name': 'Red'}, 3: {'id': 3, 'name': 'Yellow'}, 4: {'id': 4, 'name': 'off'}}


    def get_classification(self, image):
        """Determines the color of the traffic light in the image
        Args:
            image (cv::Mat): image containing the traffic light
        Returns:
            int: ID of traffic light color (specified in styx_msgs/TrafficLight)
        """

        # TODO implement light color prediction
        # Preparing image
        image_rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
        image_np = np.expand_dims(image_rgb, axis=0)

        # Detection
        with self.detection_graph.as_default():
            (det_boxes, det_scores, det_classes, num) = self.sess.run([self.detection_boxes, self.detection_scores,
                self.detection_classes, self.num_detections],
                feed_dict={self.image_tensor: image_np})

        scores = np.squeeze(det_scores)
        classes = np.squeeze(det_classes).astype(np.int32)
        boxes = np.squeeze(det_boxes)

        total_scores = { "Red": 0, "Yellow": 0, "Green": 0, "off": 0}
        
        count = 0
        for i in range(0, num):
            if scores is not None:
                score = scores[i]
                if score > MIN_SCORE_THR:
                    count += 1
                    class_name = self.category_index[classes[i]]['name']
                    total_scores[class_name] += score

        max_score = 0
        category = 'off'
        print(total_scores)
        for key in total_scores.keys():
            if count > 0:
                total_scores[key] /= (count * 1.0)
            
            if total_scores[key] > max_score:
                max_score = total_scores[key]
                category = key

        if category == 'Red':
            self.light_state = TrafficLight.RED
        elif category == 'Yellow':
            self.light_state = TrafficLight.YELLOW
        elif category == 'Green':
            self.light_state = TrafficLight.GREEN
        elif category=='off':
            self.light_state = TrafficLight.UNKNOWN
        if category=='off':
            category='Unknown'
        rospy.loginfo("TL Classifier ----> Detected TL state:" + category)
        return self.light_state
