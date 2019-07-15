// Generated by gencpp from file dbw_mkz_msgs/SteeringReport.msg
// DO NOT EDIT!


#ifndef DBW_MKZ_MSGS_MESSAGE_STEERINGREPORT_H
#define DBW_MKZ_MSGS_MESSAGE_STEERINGREPORT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace dbw_mkz_msgs
{
template <class ContainerAllocator>
struct SteeringReport_
{
  typedef SteeringReport_<ContainerAllocator> Type;

  SteeringReport_()
    : header()
    , steering_wheel_angle(0.0)
    , steering_wheel_angle_cmd(0.0)
    , steering_wheel_torque(0.0)
    , speed(0.0)
    , enabled(false)
    , override(false)
    , timeout(false)
    , fault_wdc(false)
    , fault_bus1(false)
    , fault_bus2(false)
    , fault_calibration(false)
    , fault_power(false)  {
    }
  SteeringReport_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , steering_wheel_angle(0.0)
    , steering_wheel_angle_cmd(0.0)
    , steering_wheel_torque(0.0)
    , speed(0.0)
    , enabled(false)
    , override(false)
    , timeout(false)
    , fault_wdc(false)
    , fault_bus1(false)
    , fault_bus2(false)
    , fault_calibration(false)
    , fault_power(false)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef float _steering_wheel_angle_type;
  _steering_wheel_angle_type steering_wheel_angle;

   typedef float _steering_wheel_angle_cmd_type;
  _steering_wheel_angle_cmd_type steering_wheel_angle_cmd;

   typedef float _steering_wheel_torque_type;
  _steering_wheel_torque_type steering_wheel_torque;

   typedef float _speed_type;
  _speed_type speed;

   typedef uint8_t _enabled_type;
  _enabled_type enabled;

   typedef uint8_t _override_type;
  _override_type override;

   typedef uint8_t _timeout_type;
  _timeout_type timeout;

   typedef uint8_t _fault_wdc_type;
  _fault_wdc_type fault_wdc;

   typedef uint8_t _fault_bus1_type;
  _fault_bus1_type fault_bus1;

   typedef uint8_t _fault_bus2_type;
  _fault_bus2_type fault_bus2;

   typedef uint8_t _fault_calibration_type;
  _fault_calibration_type fault_calibration;

   typedef uint8_t _fault_power_type;
  _fault_power_type fault_power;





  typedef boost::shared_ptr< ::dbw_mkz_msgs::SteeringReport_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dbw_mkz_msgs::SteeringReport_<ContainerAllocator> const> ConstPtr;

}; // struct SteeringReport_

typedef ::dbw_mkz_msgs::SteeringReport_<std::allocator<void> > SteeringReport;

typedef boost::shared_ptr< ::dbw_mkz_msgs::SteeringReport > SteeringReportPtr;
typedef boost::shared_ptr< ::dbw_mkz_msgs::SteeringReport const> SteeringReportConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dbw_mkz_msgs::SteeringReport_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dbw_mkz_msgs::SteeringReport_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace dbw_mkz_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'dbw_mkz_msgs': ['/home/guilins/catkin_ws/src/SDC_Capstone_Project/ros/src/dbw_mkz_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::dbw_mkz_msgs::SteeringReport_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dbw_mkz_msgs::SteeringReport_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dbw_mkz_msgs::SteeringReport_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dbw_mkz_msgs::SteeringReport_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dbw_mkz_msgs::SteeringReport_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dbw_mkz_msgs::SteeringReport_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dbw_mkz_msgs::SteeringReport_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6f32c1fc98edaf75e24a770b2ae3abfc";
  }

  static const char* value(const ::dbw_mkz_msgs::SteeringReport_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6f32c1fc98edaf75ULL;
  static const uint64_t static_value2 = 0xe24a770b2ae3abfcULL;
};

template<class ContainerAllocator>
struct DataType< ::dbw_mkz_msgs::SteeringReport_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dbw_mkz_msgs/SteeringReport";
  }

  static const char* value(const ::dbw_mkz_msgs::SteeringReport_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dbw_mkz_msgs::SteeringReport_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n\
\n\
# Steering Wheel\n\
float32 steering_wheel_angle      # rad\n\
float32 steering_wheel_angle_cmd  # rad\n\
float32 steering_wheel_torque     # Nm\n\
\n\
# Vehicle Speed\n\
float32 speed                     # m/s\n\
\n\
# Status\n\
bool enabled  # Enabled\n\
bool override # Driver override\n\
bool timeout  # Command timeout\n\
\n\
# Watchdog Counter\n\
bool fault_wdc\n\
\n\
# Faults\n\
bool fault_bus1\n\
bool fault_bus2\n\
bool fault_calibration\n\
bool fault_power\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::dbw_mkz_msgs::SteeringReport_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dbw_mkz_msgs::SteeringReport_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.steering_wheel_angle);
      stream.next(m.steering_wheel_angle_cmd);
      stream.next(m.steering_wheel_torque);
      stream.next(m.speed);
      stream.next(m.enabled);
      stream.next(m.override);
      stream.next(m.timeout);
      stream.next(m.fault_wdc);
      stream.next(m.fault_bus1);
      stream.next(m.fault_bus2);
      stream.next(m.fault_calibration);
      stream.next(m.fault_power);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SteeringReport_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dbw_mkz_msgs::SteeringReport_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dbw_mkz_msgs::SteeringReport_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "steering_wheel_angle: ";
    Printer<float>::stream(s, indent + "  ", v.steering_wheel_angle);
    s << indent << "steering_wheel_angle_cmd: ";
    Printer<float>::stream(s, indent + "  ", v.steering_wheel_angle_cmd);
    s << indent << "steering_wheel_torque: ";
    Printer<float>::stream(s, indent + "  ", v.steering_wheel_torque);
    s << indent << "speed: ";
    Printer<float>::stream(s, indent + "  ", v.speed);
    s << indent << "enabled: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.enabled);
    s << indent << "override: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.override);
    s << indent << "timeout: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.timeout);
    s << indent << "fault_wdc: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.fault_wdc);
    s << indent << "fault_bus1: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.fault_bus1);
    s << indent << "fault_bus2: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.fault_bus2);
    s << indent << "fault_calibration: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.fault_calibration);
    s << indent << "fault_power: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.fault_power);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DBW_MKZ_MSGS_MESSAGE_STEERINGREPORT_H
