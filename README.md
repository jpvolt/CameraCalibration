
# CameraCalibration

Camera calibration is a C++/Python library for opencv that facilitates camera calibration. See too [CameraCalibrationGUI](https://github.com/jpvolt/CameraCalibrationGUI) , a GUI util to generate config files used by this library.
## **How to Install:**

**Python:**

    sudo pip3 install camcalib-jpvolt

**C++:** See *How to build* section.

## **Usage:**

**Python:**	  

    from camcalib import *
    
    width = 480 # image width
    height = 640 # image height
    path = "config/config.json" # config file path
    
    cal = Calibrate(path, width, height)
    
    while(True):#main loop
	#your code
	fixed = cal.fix(original_image)

**C++:**

    #include  <camcalib.hpp>
    #include  <opencv2/opencv.hpp>
    #include  <opencv2/imgproc/imgproc.hpp>
	
	int main(int argc, char* argv[]){
		CamCalib cal("path/to/config.json", img_width, img_height);
		
		for(;;){
		//your code
		cv::Mat fixed = cal.Fix(original_image);
		}
	}
    
for more examples, look at examples folder.
## **How to build:**
 *requirements:*
 - Linux machine
 - Cmake
 - Opencv3.4+
 - g++
 - `sudo apt install cmake g++`
 
 *Building:*
 - `git clone https://github.com/jpvolt/CameraCalibration`
 - `cd CameraCalibration `
 - `mkdir build`
 - `cd build`
 - `cmake ..`
 - `make -j4`
 - `sudo make install`
 

