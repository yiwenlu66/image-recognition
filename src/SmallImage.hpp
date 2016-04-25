#ifndef SMALLIMAGE_HPP
#define SMALLIMAGE_HPP

#include <string>
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

class SmallImage {
public:
    SmallImage(string fileName);
    const Mat& getImage();
    string getName();

private:
    Mat mImage;
    string mName;
};

#endif
