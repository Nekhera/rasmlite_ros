#include "RASMlite/mapper/decimation.h"

using namespace pcl;

ros::Publisher point_pub;

int main(int argc, char **argv) {
  ros::init(argc, argv, "decimation_node");
  ros::NodeHandle nh;
  point_pub = nh.advertise<PointCloud<PointXYZRGB>>("/points/decimated", 1);

  nh.subscribe("/points2", 1, RASMlite::decimation::pointcloudCallback);
  ros::spin();
  return 0;
}
