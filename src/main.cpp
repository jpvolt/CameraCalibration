#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>

using namespace cv;
class CamCalib{
    private:
    Mat CamMat;
    Mat distCoeffs;
    Mat newCamMat;
    

    public:
    CamCalib(std::string filepath, int height, int width){
        Size imsize;
        imsize.height = height;
        imsize.width = width;
        FileStorage fs(filepath, FileStorage::READ);
        fs["cameraMatrix"] >> CamMat;
        fs["distCoeffs"] >> distCoeffs;
        newCamMat = getOptimalNewCameraMatrix(CamMat, distCoeffs, imsize, 1.0f, imsize);
    }
    Mat Fix(Mat img){
        Mat correctedframe;
        undistort(img, correctedframe, CamMat, distCoeffs, newCamMat);
        return correctedframe;
    }
};

