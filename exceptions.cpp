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
    static string str = "Cannot open " + mFileName + ": file not found or is not a valid image.";
    return str.c_str();
}
