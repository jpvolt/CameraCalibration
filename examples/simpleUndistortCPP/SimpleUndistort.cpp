#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <camcalib.hpp>
using namespace cv;


int main(int argc, char* argv[]){
    
    VideoCapture cap(0);
    if(cap.isOpened()){
        Mat frame, corrected;
        cap >> frame;
        CamCalib calib("config.json", frame.cols, frame.rows);
        while(true){
            cap >> frame;
            corrected = calib.Fix(frame);
            imshow("corrected", corrected);
            if(waitKey(30) >= 0) break;
        }
    }
}