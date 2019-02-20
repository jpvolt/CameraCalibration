import cv2

class Calibrate:
    def __init__(self, path, w, h):
        self.config = cv2.FileStorage(path, cv2.FileStorage_READ)
        self.CamMat = self.config.getNode("cameraMatrix").mat()
        self.distCoeffs =  self.config.getNode("distCoeffs").mat()
        print(self.distCoeffs.shape)
        self.newCamMat, roi= cv2.getOptimalNewCameraMatrix(self.CamMat, self.distCoeffs,(w,h),1,(w,h))

    def fix(self, frame):
        return cv2.undistort(frame, self.CamMat, self.distCoeffs, self.newCamMat)                


    

