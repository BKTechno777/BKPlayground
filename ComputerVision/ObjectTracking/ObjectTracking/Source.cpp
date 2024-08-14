#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
	VideoCapture capture(0);
	Mat image;
	String windowName = "InputImage";
	String trackingWindow = "Tracking Window";
	cv::namedWindow(windowName, cv::WINDOW_NORMAL);
	cv::namedWindow(trackingWindow, cv::WINDOW_NORMAL);

	if (capture.isOpened() != true)
	{
		cout << "Couldnt start the camera, Please check the connection" << endl;
	}
	else
	{
		Mat blurImage;
		Mat hsvImage;
		cv::Scalar lowerBound(60, 50, 50);
		cv::Scalar upperBound(100, 255, 255);
		while (true)
		{
			if (!capture.read(image))
			{
				cout << "Error capturing the image" << endl;
				break;
			}
			cv::GaussianBlur(image, blurImage, Size(5, 5),0);
			cv::cvtColor(blurImage, hsvImage, cv::COLOR_BGR2HSV);

			cv::Mat mask;
			cv::inRange(hsvImage, lowerBound, upperBound, mask);

			std::vector<vector<cv::Point>> contours;

			cv::findContours(mask, contours, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
			if (!contours.empty())
			{
				size_t largestContourIndex = 0;
				double maxArea = 0;

				for (size_t i = 0; i < contours.size(); i++)
				{
					double area = cv::contourArea(contours[i]);
					if (area > maxArea)
					{
						maxArea = area;
						largestContourIndex = i;
					}
				}

				cv::Rect boundingBox = cv::boundingRect(contours[largestContourIndex]);
				cv::rectangle(image, boundingBox, cv::Scalar(0, 255, 0), 2);
			}

			cv::imshow(windowName, image);
			cv::imshow(trackingWindow, mask);
			if (cv::waitKey(1) == 27)
			{
				break;
			}
			capture.release();
			cv::destroyAllWindows();
		}
	}

	return 0;
}