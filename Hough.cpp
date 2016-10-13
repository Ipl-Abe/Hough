#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/gighgui.hpp>

int main(){







    cv::Mat dst_img, work_img;
    dst_img = src_img.clone();
    cv::cvtColor(src_img,work_img,CV_BGR2GRAY);


}

