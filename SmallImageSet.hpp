#ifndef SMALLIMAGESET_HPP
#define SMALLIMAGESET_HPP

#include <string>
#include <vector>
#include "opencv2/highgui/highgui.hpp"
#include "SmallImage.hpp"

using namespace std;

class SmallImageSet {
public:
    SmallImageSet(string listFileName);
    ~SmallImageSet();
    const vector<SmallImage*>& getSmallImageVector();

private:
    vector<SmallImage*> mSmallImageVector;
};

#endif
