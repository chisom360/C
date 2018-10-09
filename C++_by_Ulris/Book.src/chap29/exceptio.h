// exceptio.h : Exception classes for file access
// -------------------------------------------------
#ifndef _EXCEPTIO_H
#define _EXCEPTIO_H

#include <string>
#include <iostream>
using namespace std;

class FileError
{
  private:
    string filename;
  public:
    FileError(const string& file) : filename(file) { }
    string getName() const{ return filename; }
};

class OpenError : public FileError
{
  public:
    OpenError(const string& file) : FileError(file) { }
};

class ReadError : public FileError
{
  public:
    ReadError(const string& file) : FileError(file) { }
};

class WriteError : public FileError
{
  public:
    WriteError(const string& file) : FileError(file) { }
};

#endif
