#include "commands.h"

Commands::Commands() {}

Commands::~Commands() {}

void Commands::addFilePath()
{
	clearScreen();

	cout << endl << "\t********** Enter File Path : **********" << endl << endl;

	cout << endl << "\t\tExample: C:\\Pictures\\image8.jpg" << endl << endl;

	cout << "\t\tFile path: ";
	cin >> filePath;

	const char toReplace = '\\';
	const char replacement = '/';

	replace(filePath.begin(), filePath.end(), toReplace, replacement);

	setPreferences();
}

void Commands::setPreferences()
{
	cv::Mat image = cv::imread(filePath);

	if (image.empty()) {
		cout << endl << "\t\tFile path is not correct, please try again!" << endl;
		cout << endl << "\t\tTo continue, pres Enter!" << endl;

		cin.get();
		cin.get();
		cv::waitKey(0);

		return;
	}

	cv::imshow("Image Original", image);

	cv::Mat imageGray;
	cv::Mat imageBlur;
	cv::Mat imageCanny;
	cv::Mat imageDilatation;
	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(2, 2));

	cv::cvtColor(image, imageGray, cv::ColorConversionCodes::COLOR_BGR2GRAY);
	cv::GaussianBlur(image, imageBlur, cv::Size(1, 1), 3, 0);
	cv::Canny(imageBlur, imageCanny, 75, 250);
	cv::dilate(imageCanny, imageDilatation, kernel);

	getContours(imageDilatation, image);

	cv::imshow("Image", image);

	cv::waitKey(0);

	cout << endl << endl << "\t\tTo continue, pres Enter!";

	cin.get();
	cin.get();
	cv::waitKey(0);
}

void Commands::getContours(cv::Mat imageDilatation, cv::Mat image)
{
	int area;
	float peri;

	vector<vector<cv::Point>> contours;
	vector<cv::Vec4i> hierarchy;

	cv::findContours(imageDilatation, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

	cout << endl << "\t\tFound objects on image = " << contours.size();

	vector<vector<cv::Point>> conPoly(contours.size());
	vector<cv::Rect> boundRect(contours.size());

	for (int i = 0; i < contours.size(); i++)
	{
		area = cv::contourArea(contours[i]);

		if (area > 100)
		{
			peri = cv::arcLength(contours[i], true);
			cv::approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			boundRect[i] = boundingRect(conPoly[i]);

			cv::rectangle(image, boundRect[i].tl(), boundRect[i].br(), cv::Scalar(0, 0, 255), 2);
		}
	}
}

void clearScreen()
{
#if defined _WIN32
	system("cls");
#elif defined (__APPLE__)
	system("clear");
#endif
}