#include "HandCursor.h"
#include <vector>
#include <Windows.h>
#include <WindowsX.h>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <opencv\cv.h>
#include <opencv\highgui.h>
using namespace std;
using namespace cv;

#include "yolo_v2_class.hpp"
#include "demo.h"
#include <opencv2\opencv.hpp>
#pragma comment(lib,"opencv_core249.lib")
#pragma comment(lib,"opencv_imgproc249.lib")
#pragma comment(lib,"opencv_highgui249.lib")

void draw_boxes(cv::Mat mat_img, std::vector<bbox_t> result_vec) {
    for (auto &i : result_vec) {
        cv::rectangle(mat_img, cv::Rect(i.x, i.y, i.w, i.h), cv::Scalar(50, 200, 50), 3);
        cv::imshow("window name", mat_img);
        cv::waitKey(0);
    }
}
std::string cfg = "yolo-voc.cfg";
std::string weights = "yolo-voc.weights";
void detector() {
    cout << cfg << endl;
    Detector detector(cfg,weights);
    //cv::VideoCapture capture(0);
    //if (!capture.isOpened()) {
    //    std::cerr << "could not open camera" << std::endl;
    //    return;
    //}
    //while (true) {
    //    bool frame_valid = true;
    //    cv::Mat frame;
    //    try {
    //        capture >> frame;
    //    }
    //    catch (cv::Exception e) {
    //        std::cerr << "Exception occured Ignoring frame.." << e.err << endl;
    //        frame_valid = false;
    //    }
    //    if (frame_valid) {
    //        //std::vector<bbox_t> result_vec = detector.detect(frame);
    //        //for (auto &i : result_vec)
    //        //    cv::rectangle(frame, cv::Rect(i.x, i.y, i.w, i.h), cv::Scalar(50, 200, 50), 3);
    //    }

    //    cv::imshow("webcam", frame);
    //    if (cv::waitKey(30) >= 30) break;
    //}
}
int main() 
{
    detector();
    //Handcursor();
}
