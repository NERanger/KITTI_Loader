# KITTI Loader

A simple loader for [KITTI](http://www.cvlibs.net/datasets/kitti/eval_odometry.php) odometry dataset

## Feature

* Stereo image loading
* LiDAR pointcloud loading

## Usage

```cpp
string path(argv[1]);     // Path to KITTI dataset sequence
bool if_success = false;  // Marker indicating if dataset obj is created successfully
KittiLoader dataset(path, if_success);  // Constructing dataset object

// Check if dataset obj successfully created
if(!if_success){
    cerr << "Fail to load dataset." << endl;
    return EXIT_FAILURE;
}

for(size_t i = 0; i < dataset.Size() ; ++i){
    KittiFrame f = dataset[i];
    // Your operations on data
}
```

## Dependencies

* OpenCV (Tested on OpenCV 3.4)
* PCL

## Build

```shell
mkdir build
cd build
cmake ..
make
```

## Example

An example is given in `example.cc`