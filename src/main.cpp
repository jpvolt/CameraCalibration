#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include "camcalib.hpp"
#include <new>
using namespace cv;

CamCalib::CamCalib(std::string filepath, int height, int width){
        Size imsize;
        imsize.height = height;
        imsize.width = width;
        FileStorage fs(filepath, FileStorage::READ);
        fs["cameraMatrix"] >> CamMat;
        fs["distCoeffs"] >> distCoeffs;
        newCamMat = getOptimalNewCameraMatrix(CamMat, distCoeffs, imsize, 1.0f, imsize);
}
Mat CamCalib::Fix(Mat img){
        Mat correctedframe;
        undistort(img, correctedframe, CamMat, distCoeffs, newCamMat);
        return correctedframe;
}


extern "C"  //Tells the compile to use C-linkage for the next scope.
{
    //Note: The interface this linkage region needs to use C only.  
    void * CreateInstanceOfClass(char path[], int w, int h)
    {
        // Note: Inside the function body, I can use C++. 
        return new(std::nothrow) CamCalib(path, h, w);
    }

    //Thanks Chris. 
    void DeleteInstanceOfClass (void *ptr)
    {
         delete ptr; 
    }

} //End C linkage scope.