#ifndef SMALLIMAGESET_HPP
#define SMALLIMAGESET_HPP

#include <string>
#include <vector>
#include "opencv2/highgui/highgui.hpp"
#include "SmallImage.hpp"

using namespace std;

class SmallImageSet {
public:
    SmallImageSet(string dirName);
    ~SmallImageSet();
    const vector<Mat*>& getSmallImageVector();

private:
    vector<SmallImage*> mSmallImageVector;
};

#endif
