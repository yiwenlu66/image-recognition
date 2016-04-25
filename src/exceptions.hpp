#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <string>

using namespace std;

class CannotOpenImageException : public exception {
public:
    CannotOpenImageException(string fileName);
    virtual ~CannotOpenImageException() throw();
    virtual const char* what() const throw();

private:
    string mFileName;
};

class EmptySmallImageListException : public exception {
public:
    virtual const char* what() const throw();
};


#endif
