#include <iostream>
#include "exceptions.hpp"
#include "BigImage.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

BigImage::BigImage(string fileName, int numRow, int numColumn)
    : mNumRow(numRow)
    , mNumColumn(numColumn)
{
    mImage = imread(fileName);
    if (mImage.empty()) {
        throw * (new CannotOpenImageException(fileName));
    }
    // TODO
}

BigImage::~BigImage()
{
    // TODO
}

void BigImage::match(const SmallImageSet& smallImageSet)
{
    // TODO
}

void BigImage::output()
{
    cout << "output" << endl;
    // TODO
}
