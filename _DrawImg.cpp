#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

#define WINDOS_WITH 600//定义窗口大小的宏
#define WINDOS_NAME1 "【绘制图1】"
#define WINDOS_NAME2 "【绘制图2】"

//----------------------自定义画椭圆----------------------
void drawEllipse(Mat img , double angle ) {
	int thickness = 2;
	int lineType = 8;
	ellipse(img,
		Point(WINDOS_WITH / 2, WINDOS_WITH / 2),
		Size(WINDOS_WITH / 4, WINDOS_WITH / 16),
		angle,
		0,
		360,
		Scalar(255, 129, 0),
		thickness,
		lineType);
}

//----------------------------画实心圆-----------------
void DrawFilledCircle(Mat img ,Point center) {
	int thickness = -1;
	int lineType = 8;

	circle(img,
		center,
		WINDOS_WITH / 32,
		Scalar(0, 0, 255),
		thickness,
		lineType);
}
 
//------------------------------画凹多边形-------------------
void DrawPolygon(Mat img) {
	int lineType = 8;

	Point rookPoints[1][20];
	rookPoints[0][0]  = Point(     WINDOS_WITH / 4,  7  * WINDOS_WITH / 8);
	rookPoints[0][1]  = Point(3  * WINDOS_WITH / 4,  7  * WINDOS_WITH / 8);
	rookPoints[0][2]  = Point(3  * WINDOS_WITH / 4,  7  * WINDOS_WITH / 16);
	rookPoints[0][3]  = Point(11 * WINDOS_WITH / 16, 13 * WINDOS_WITH / 16);
	rookPoints[0][4]  = Point(19 * WINDOS_WITH / 32, 3  * WINDOS_WITH / 8);
	rookPoints[0][5]  = Point(3  * WINDOS_WITH / 4,  3  * WINDOS_WITH / 8);
	rookPoints[0][6]  = Point(3  * WINDOS_WITH / 4,       WINDOS_WITH / 8);
	rookPoints[0][7]  = Point(26 * WINDOS_WITH / 40,      WINDOS_WITH / 8);
	rookPoints[0][8]  = Point(26 * WINDOS_WITH / 40,      WINDOS_WITH / 4);
	rookPoints[0][9]  = Point(22 * WINDOS_WITH / 40,      WINDOS_WITH / 4);
	rookPoints[0][10] = Point(22 * WINDOS_WITH / 40,      WINDOS_WITH / 8);
	rookPoints[0][11] = Point(18 * WINDOS_WITH / 40,      WINDOS_WITH / 8);
	rookPoints[0][12] = Point(18 * WINDOS_WITH / 40,      WINDOS_WITH / 4);
	rookPoints[0][13] = Point(14 * WINDOS_WITH / 40,      WINDOS_WITH / 4);
	rookPoints[0][14] = Point(14 * WINDOS_WITH / 40,      WINDOS_WITH / 8);
	rookPoints[0][15] = Point(     WINDOS_WITH / 4,       WINDOS_WITH / 8);
	rookPoints[0][16] = Point(     WINDOS_WITH / 4, 3  *  WINDOS_WITH / 8);
	rookPoints[0][17] = Point(13 * WINDOS_WITH / 32, 3 *  WINDOS_WITH / 8);
	rookPoints[0][18] = Point(5  * WINDOS_WITH / 16,13 *  WINDOS_WITH / 16);
	rookPoints[0][19] = Point(     WINDOS_WITH / 4, 13 *  WINDOS_WITH / 16);

	const Point* ppt[1] = { rookPoints[0] };
	int npt[] = { 20 };
	fillPoly(img,
		ppt,
		npt,
		1,
		Scalar(255, 0, 255),
		lineType);
}

//---------------------------画线--------------------
void DrawLine(Mat img , Point start , Point end) {
	int thickness = 1;
	int lineType = 8;
	line(img,
		start,
		end,
		Scalar(50, 50, 50),
		thickness,
		lineType);

}

void testMain() {
	Mat atomImage = Mat::zeros(WINDOS_WITH, WINDOS_WITH, CV_8UC3);
	Mat rookImage = Mat::zeros(WINDOS_WITH, WINDOS_WITH, CV_8UC3);

	//画椭圆
	drawEllipse(atomImage, 0);
	drawEllipse(atomImage, 45);
	drawEllipse(atomImage, 90);
	drawEllipse(atomImage, 135);
	//画实心圆
	DrawFilledCircle(atomImage, Point(WINDOS_WITH / 2, WINDOS_WITH / 2));

	
	//画多边形
	DrawPolygon(rookImage);
	
	//画矩形
	rectangle(rookImage,
		Point(0, 7 * WINDOS_WITH / 8),
		Point(WINDOS_WITH, WINDOS_WITH),
		Scalar(199, 199, 199),
		-1,
		8);
	//画线
	DrawLine(rookImage, Point(0, 15 * WINDOS_WITH / 16), Point(WINDOS_WITH, 15 * WINDOS_WITH / 16));

	imshow(WINDOS_NAME1, atomImage);
	moveWindow(WINDOS_NAME1, 0, 0);//移动窗口的位置
	imshow(WINDOS_NAME2, rookImage);
	moveWindow(WINDOS_NAME2, WINDOS_WITH, 0);
	cv::waitKey(0);
}

int main(int, char**) {
	
	testMain();
	return 0;
}
