#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Pose.h>
#include <vector>
#include <tf/transform_listener.h>

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "publish_trajectory_70");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal", 10);
    double points[9][2]={{5.06,-2.05},{5.23,-1.58},{5.03,-1.49},{4.74,-1.33},{4.21,-1.15},{4.08,-1.82},{4.55,-2.04},{4.83,-1.95},{4.91,-1.43}};//祝祖国70华诞生日快乐!

    ros::Rate rate(5.0);
    geometry_msgs::PoseStamped pose_msg;
    pose_msg.header.frame_id="map";
    pose_msg.pose.orientation=tf::createQuaternionMsgFromYaw(1.507);
    rate.sleep();
    for(int i=0;i<9;i++)
    {
        pose_msg.pose.position.x=points[i][0];
        pose_msg.pose.position.y=points[i][1];
        pub.publish(pose_msg);
        ROS_INFO("Publishing data...");
        rate.sleep();
    }
    return 0;
}