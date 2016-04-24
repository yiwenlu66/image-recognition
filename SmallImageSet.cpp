#include <iostream>
#include <fstream>
#include "SmallImageSet.hpp"
#include "SmallImage.hpp"
#include "exceptions.hpp"

SmallImageSet::SmallImageSet(string listFileName)
{
    ifstream listFileStream(listFileName.c_str());
    string smallImageFileName;
    while (getline(listFileStream, smallImageFileName)) {
        mSmallImageVector.push_back(new SmallImage(smallImageFileName));
    }
    if (mSmallImageVector.empty()) {
        throw * (new EmptySmallImageListException());
    }
}

SmallImageSet::~SmallImageSet()
{
    for (auto item: mSmallImageVector) {
        delete item;
    }
}

const vector<SmallImage*>& SmallImageSet::getSmallImageVector()
{
    return mSmallImageVector;
}
