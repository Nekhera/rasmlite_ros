#include <ros/ros.h>
#include "RASMlite/mapper/decimation.h"

using namespace pcl;

ros::Publisher point_pub;

void pointcloudCallback(const PointCloud<PointXYZ>::ConstPtr &cloud) {
  PointCloud<PointXYZ>::Ptr cloud_ref(new PointCloud<PointXYZ>(*cloud));
  RASMlite::decimation::process(cloud_ref);
  point_pub.publish(cloud_ref);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "decimation_node");
  ros::NodeHandle nh;
  ros::Subscriber sub_cloud = nh.subscribe<PointCloud<PointXYZ>>("/points2", 1, pointcloudCallback);

  point_pub = nh.advertise<PointCloud<PointXYZRGB>>("/points/decimated", 1);
  ros::spin();
  return 0;
}
