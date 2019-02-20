#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
class CamCalib{
    private:
    cv::Mat CamMat;
    cv::Mat distCoeffs;
    cv::Mat newCamMat;
    public:
    CamCalib(std::string filepath, int height, int width);
    cv::Mat Fix(cv::Mat img);
};