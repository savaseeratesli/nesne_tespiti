#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	/*
	* //\opencv\sources\data\haarcascades
	//haarcascade_frontalface_default.xml i dosya klasörümüze kopyaladýk
	CascadeClassifier yuz;
	vector<Rect> yuz_tanima;

	yuz.load("haarcascade_frontalface_default.xml");

	Mat resim = imread("haar.jpg");

	Mat gri;

	cvtColor(resim, gri, COLOR_BGR2GRAY);

	yuz.detectMultiScale(gri, yuz_tanima);

	for (int i = 0; i < yuz_tanima.size(); i++)//Yüz tarama
	{
		rectangle(resim, yuz_tanima[i],Scalar(255,0,0),2);
	}

	imshow("Bulunan Yuz", resim);
	waitKey(0);

	*/

	//Webcam xml olusturma
	VideoCapture pozitif(0);

	if (!pozitif.isOpened())
	{
		cout << "Webcam Bulunamadi!";
		return -1;
	}

	int i = 0;
	while (true)
	{
		Mat okuma;

		bool kontrol = pozitif.read(okuma);

		cvtColor(okuma, okuma, COLOR_BGR2GRAY);
		resize(okuma, okuma,Size( 600, 500));

		if (!kontrol)
		{
			cout << "Frame Alinamadi!";
			break;
		}
		
		imshow("Webcam", okuma);

		if (waitKey(20) == 27)break;//20sn ESC bas çýk

		imwrite("p" + to_string(i) + ".jpg", okuma);
		waitKey(0);
		i++;

	}

}