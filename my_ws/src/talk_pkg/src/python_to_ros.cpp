#include "ros/ros.h"
#include "std_msgs/String.h"

// 回调函数，处理接收到的消息
void chatterCallback(const std_msgs::String::ConstPtr& msg) {
    ROS_INFO("Received: %s", msg->data.c_str());
}

int main(int argc, char **argv) {
    // 初始化ROS节点
    ros::init(argc, argv, "listener");

    // 创建节点句柄
    ros::NodeHandle nh;

    // 订阅话题 `/chatter`
    ros::Subscriber sub = nh.subscribe("/chatter", 1000, chatterCallback);

    // 进入自旋，等待消息
    ros::spin();

    return 0;
}
