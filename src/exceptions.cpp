#include <string>
#include "exceptions.hpp"

using namespace std;

CannotOpenImageException::CannotOpenImageException(string fileName)
    : mFileName(fileName)
{
}

CannotOpenImageException::~CannotOpenImageException() throw()
{
}

const char* CannotOpenImageException::what() const throw()
{
    static string str = "Error opening " + mFileName + ": file not found or is not a valid image.";
    return str.c_str();
}

const char* EmptySmallImageListException::what() const throw()
{
    return "Error loading small image list.";
}
