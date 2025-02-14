#include <ros/ros.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "initial_pose_publisher");
    ros::NodeHandle nh;

    // 创建一个publisher，发布到话题"/initialpose"，消息类型为geometry_msgs::PoseWithCovarianceStamped
    ros::Publisher initial_pose_pub = nh.advertise<geometry_msgs::PoseWithCovarianceStamped>("/initialpose", 10);

    // 设置初始位姿
    geometry_msgs::PoseWithCovarianceStamped initial_pose;
    initial_pose.header.stamp = ros::Time::now();
    initial_pose.header.frame_id = "map"; // 假设初始位姿是在地图坐标系中发布的

    // 设置位姿
    initial_pose.pose.pose.position.x = 1.0;
    initial_pose.pose.pose.position.y = 2.0;
    initial_pose.pose.pose.position.z = 0.0;
    initial_pose.pose.pose.orientation.w = 1.0; // 四元数的w分量，代表无旋转
    initial_pose.pose.pose.orientation.x = 0.0;
    initial_pose.pose.pose.orientation.y = 0.0;
    initial_pose.pose.pose.orientation.z = 0.0;
    
    for(int i=0;i<36;i++)
    {
	initial_pose.pose.covariance[i] = 0.0;
    }
    initial_pose.pose.covariance[0] = 0.25;
    initial_pose.pose.covariance[7] = 0.25;
    initial_pose.pose.covariance[35] = 0.06853892;

    // 发布初始位姿
    ros::Rate loop_rate(10);
    while(ros::ok())
    {   
    	initial_pose_pub.publish(initial_pose);
	loop_rate.sleep();
    }     
    return 0;

}

