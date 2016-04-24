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
    string result = "";
    split.pop_back();
    for (size_t i = 0; i < split.size(); ++i) {
        result += split[i];
        if (i < split.size() - 1) {
            result += ".";
        }
    }
    return result;
}

string stripDirectory(string fileName)
{
    string result, item;
    stringstream ss(fileName);
    while (getline(ss, item, '/')) {
        result = item;
    }
    return result;
}
