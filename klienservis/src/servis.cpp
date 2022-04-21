#include "ros/ros.h"
#include "klienservis/tambah.h"

bool add(klienservis::tambah::Request &req, klienservis::tambah::Response &res){
    res.sum = req.A + req.B;
    ROS_INFO("req : A=%d, B=%d", (int)req.A, (int)req.B);
    ROS_INFO("Res : %d", (int)res.sum);
    return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_ints_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("add_two_ints", add);
  ROS_INFO("Ready to add two ints.");
  ros::spin();

  return 0;
}