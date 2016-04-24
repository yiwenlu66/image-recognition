#include "SmallImage.hpp"
#include "exceptions.hpp"
#include "utils.hpp"

SmallImage::SmallImage(string fileName)
{
    mImage = imread(fileName);
    if (mImage.empty()) {
        throw * (new CannotOpenImageException(fileName));
    }
    mName = stripExtension(fileName);
}

const Mat& SmallImage::getImage()
{
    return mImage;
}

string SmallImage::getName()
{
    return mName;
}
