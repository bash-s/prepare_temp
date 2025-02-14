import roslibpy

# 连接到ROS Bridge
client = roslibpy.Ros(host='localhost', port=9090)
client.run()

# 检查连接状态
if client.is_connected:
    print('Connected to ROS Bridge')

# 发布消息到ROS话题 `/chatter`
talker = roslibpy.Topic(client, '/chatter', 'std_msgs/String')
while True:
    talker.publish(roslibpy.Message({'data': 'Hello, ROS from non-ROS environment!'}))

# 关闭连接
client.terminate()
