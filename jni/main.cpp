#include "projectorCamera.h"
#include  "AstraData.h"
#include "Htime.h"

string intTostring(int num)
{
	stringstream ss;
	ss << num;
	string out;
	ss >> out;

	return out;
}

int  main(int argc, char* argv[])
{
	ProjectorCamera rsPeojection;
	rsPeojection.calibrationFixed(); 
	//rsPeojection.screenRoi = Rect(30,0,300,200);

	AstraData astradata;
	astradata.init_IR();
	cv::Mat outImg, outImg1, outImg2, outImg3, sumImg, averaImg, binary, lastIr, finalMap;
	vector<cv::Mat> histHands;
	vector<vector<int>> histVal(100);
	int frameId(0);
	while (1)
	{
		astradata.getData_IR();
		if (astradata.cvRawImg16U.empty() || astradata.cvIrImg.empty())
			continue;

		//get depth data
		cv::Mat depthImg, colorImg, foregImg, distanTras;
		depthImg = astradata.cvRawImg16U.clone();
		colorImg = astradata.cvIrImg.clone();
		depthImg.convertTo(depthImg, CV_32F);
		cv::flip(colorImg, colorImg, 1);
		cv::flip(depthImg, depthImg, 1);		
		
		rsPeojection.depthImg = depthImg;
		if (!rsPeojection.calibrated) rsPeojection.calibrationFixed();
		rsPeojection.processing(colorImg, depthImg);
		

	}
	return 0;
}