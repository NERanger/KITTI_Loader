#include <iostream>
#include <string>

#include <opencv2/opencv.hpp>

#include <pcl/visualization/cloud_viewer.h>

#include "KittiLoader.hpp"

using std::cout;
using std::cerr;
using std::endl;
using std::string;

int main(int argc, char const *argv[]){
    if(argc != 2){
        cerr << "Usage: ./kitti_loader <path-to-kitti-sequence>" << endl;
        return EXIT_FAILURE;
    }

    string path(argv[1]);
    bool if_success = false;
    KittiLoader dataset(path, if_success);

    if(!if_success){
        cerr << "Fail to load dataset." << endl;
        return EXIT_FAILURE;
    }

    pcl::visualization::CloudViewer cloud_viewer("Point Cloud");
    for(size_t i = 0; i < dataset.Size() ; ++i){
        KittiFrame f = dataset[i];
        cv::imshow("Left", f.left_img);
        cv::imshow("Right", f.right_img);
        cloud_viewer.showCloud(f.ptcloud);

        cv::waitKey(10);
    }
    
    return EXIT_SUCCESS;
}
