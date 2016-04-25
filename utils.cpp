#include "utils.hpp"
#include <sstream>
#include <vector>
#include "opencv2/imgproc/imgproc.hpp"

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

double matchAlgorithm(const Mat& image1, const Mat& image2)
{
    Mat imageHSV1, imageHSV2;
    cvtColor(image1, imageHSV1, COLOR_BGR2HSV);
    cvtColor(image2, imageHSV2, COLOR_BGR2HSV);
    int h_bins = 50, s_bins = 60;
    int histSize[] = { h_bins, s_bins };
    float h_ranges[] = { 0, 180 };
    float s_ranges[] = { 0, 256 };
    const float* ranges[] = { h_ranges, s_ranges };
    int channels[] = { 0, 1 };
    MatND hist1, hist2;
    calcHist(&imageHSV1, 1, channels, Mat(), hist1, 2, histSize, ranges, true, false);
    normalize(hist1, hist1, 0, 1, NORM_MINMAX, -1, Mat());
    calcHist(&imageHSV2, 1, channels, Mat(), hist2, 2, histSize, ranges, true, false);
    normalize(hist2, hist2, 0, 1, NORM_MINMAX, -1, Mat());
    return 1 / compareHist(hist1, hist2, CV_COMP_BHATTACHARYYA);
}
