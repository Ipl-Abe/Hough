#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/gighgui.hpp>

int main(){
cv::Mat src_img = cv::imread("./sample.png",1);
if(!src_img.data)return -1;

    cv::Mat dst_img, work_img;
    dst_img = src_img.clone();
    cv::cvtColor(src_img,work_img,CV_BGR2GRAY);
    
    //Hough変換のための前処理（平滑化を行わないと誤検出が発生しやすい）
    cv::GauusianBlur(work_img,work_img,cv::Siz(11,11),2,2);

    //Hough変換による円の検出と検出した円の描画
    std::vector<cv::Vec3f> circles;
    cv::HoughCircles(work_img,circles,CV_HOUGH_GRDIENT,1,100,20,50);

    std::vector<cv::Vec3f>::iterator it = circles.begin();
    for(;it!=circles;++it){
	cv::Point center(cv::saturate_cast<int>((*it)[0]),cv::saturate_cast<int>((*it)[1]);
	int radius = cv::saturate_cast<int>((*it)[2]);
	cv::circle(dst_img,center,radius,cv::Scalar(0,0,255),2);
    }

    cv::namedWindow("HoughCircles",CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
    cv::imshow("HoughCircles",dst_img);
    cv::waitKey(0);
}

