#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>
#include "commands.h"

using namespace std;

class Commands
{

public:

	Commands();
	~Commands();

	void addFilePath();
	void setPreferences();
	void getContours(cv::Mat imageDilatation, cv::Mat image);

private:

	string filePath;

};

void clearScreen();

#endif // COMMANDS_H