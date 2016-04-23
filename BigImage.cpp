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
    int height = mImage.rows, width = mImage.cols;
    mBlockSize.height = height / numRow;
    mBlockSize.width = width / numColumn;
    for (int i = 0; i < numRow; ++i) {
        for (int j = 0; j < numColumn; ++j) {
            Rect blockArea(j * mBlockSize.width, i * mBlockSize.height, mBlockSize.width, mBlockSize.height);
            mBlocks.push_back(new Mat(mImage, blockArea));
        }
    }
}

BigImage::~BigImage()
{
    for (auto block: mBlocks) {
        delete block;
    }
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
