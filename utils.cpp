#include "utils.hpp"
#include <sstream>
#include <vector>

string stripExtension(string fileName)
{
    vector<string> split;
    stringstream ss(fileName);
    string item;
    while (getline(ss, item, '.')) {
        split.push_back(item);
    }
    split.pop_back();
    ss.clear();
    for (auto item : split) {
        ss << item << ".";
    }
    return ss.str();
}
