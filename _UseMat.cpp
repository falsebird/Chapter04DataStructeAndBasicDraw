#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void useMat() {
	Mat I = Mat::eye(4, 4, CV_64F);
	I.at<double>(1, 1) = CV_PI;
	cout << "\nI = " << I << ";\n" << endl;

	Mat r = Mat(10, 3, CV_8UC3);
	randu(r, Scalar::all(0), Scalar::all(255));

	//�˶δ����OpenCV2��Ϊ��
	//cout << "r (OpenCVĬ�Ϸ��) = " << r << ";" << endl << endl;
	//cout << "r (Python���) = " << format(r,"python") << ";" << endl << endl;
	//cout << "r (Numpy���) = " << format(r,"numpy") << ";" << endl << endl;
	//cout << "r (���ŷָ����) = " << format(r,"csv") << ";" << endl<< endl;
	//cout << "r (C���Է��) = " << format(r,"C") << ";" << endl << endl;
	//�˶δ����OpenCV3��Ϊ��
	cout << "r (OpenCVĬ�Ϸ��) = " << r << ";" << endl << endl;
	cout << "r (Python���) = " << format(r, Formatter::FMT_PYTHON) << ";" << endl << endl;
	cout << "r (Numpy���) = " << format(r, Formatter::FMT_NUMPY) << ";" << endl << endl;
	cout << "r (���ŷָ����) = " << format(r, Formatter::FMT_CSV) << ";" << endl << endl;
	cout << "r (C���Է��) = " << format(r, Formatter::FMT_C) << ";" << endl << endl;


	Point2f p(6, 2);
	cout << "��2ά�㡿p = " << p << ";\n" << endl;

	Point3f p3f(8, 2, 0);
	cout << "��3ά�㡿p3f = " << p3f << ";\n" << endl;

	vector<float> v;
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);

	cout << "������Mat��vector��shortvec = " << Mat(v) << ";\n" << endl;

	vector<Point2f> points(20);
	for (size_t i = 0; i < points.size(); ++i)
		points[i] = Point2f((float)(i * 5), (float)(i % 7));

	cout << "����ά��������points = " << points << ";";

	getchar();//��������˳�
}

int main(int, char**) {

	

	return 0;

}