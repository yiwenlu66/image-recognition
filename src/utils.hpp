#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

string stripExtension(string fileName); 
string stripDirectory(string fileName);

double matchAlgorithm(const Mat& image1, const Mat& image2);

#endif
