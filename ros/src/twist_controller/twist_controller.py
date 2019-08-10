from pid import PID
from lowpass import LowPassFilter
from yaw_controller import YawController
import rospy

GAS_DENSITY = 2.858
ONE_MPH = 0.44704
Max_Brake=400

class Controller(object):
    def __init__(self, vehicle_mass, fuel_capacity, brake_deadband, decel_limit, accel_limit, wheel_radius, wheel_base, steer_ratio, max_lat_accel, max_steer_angle):
        min_speed=0.1
        self.yaw_controller=YawController(wheel_base, steer_ratio, min_speed, max_lat_accel, max_steer_angle)
        kp=0.3
        ki=0.1
        kd=0
        mn=0
        mx=0.5
        self.throttle_controller=PID(kp, ki, kd, mn, mx)
        tau=0.5
        ts=0.02
        self.vel_lpf=LowPassFilter(tau, ts)
        self.last_time=rospy.get_time()
        self.vehicle_mass=vehicle_mass
        self.fuel_capacity=fuel_capacity
        self.brake_deadband=brake_deadband
        self.decel_limit=decel_limit
        self.accel_limit=accel_limit
        self.wheel_base=wheel_base
        self.wheel_radius=wheel_radius

    def control(self, linear_vel, angular_vel, current_vel, dbw_enabled):
        # Return throttle, brake, steer
        rospy.logwarn("Angular vel: {0}".format(angular_vel))
        rospy.logwarn("Target vel = linear_vel: {0}".format(linear_vel))
        rospy.logwarn("Target angular vel = angular_vel: {0}".format(angular_vel))
        rospy.logwarn("Current velocity: {0}".format(current_vel))
        rospy.logwarn("Filtered vel: {}".format(self.vel_lpf.get()))
        if not dbw_enabled:
            self.throttle_controller.reset()
            return 0, 0, 0
        current_vel=self.vel_lpf.filt(current_vel)

        steering=self.yaw_controller.get_steering(linear_vel, angular_vel, current_vel)
        rospy.logwarn("yaw_controller steering : {}".format(steering))

        vel_error=linear_vel-current_vel
        rospy.logwarn("vel_error : {}".format(vel_error))
        self.last_vel=current_vel
        current_time=rospy.get_time()
        sample_time=current_time-self.last_time
        #vel_decel=vel_error/sample_time #variable never used
        self.last_time=current_time

        throttle=self.throttle_controller.step(vel_error, sample_time)
        rospy.logwarn("throttle by PID controller : {}".format(throttle))
        brake=0

        if linear_vel==0 and current_vel<0.1 : #1.5 might be an issue and might keep car stuck 
            throttle=0
            brake=700       # update to hold the vehicle at stop
        elif throttle<0.1 and vel_error<0 :
            throttle=0
            decel=max(vel_error, self.decel_limit)
            brake=abs(decel)*self.vehicle_mass*self.wheel_radius #Torque N*m Newton Metre 
            #brake=min(abs(decel)*self.vehicle_mass*self.wheel_radius, Max_Brake)
            
        rospy.logwarn("*OUTPUT**throttle{} **brake {} **steering {}".format(throttle, brake, steering))
        return throttle, brake, steering