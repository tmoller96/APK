#include <iostream>
#include <stdio.h>
class File
{
public:
  File(std::string fileName) //This constructor is the best as we can then move variable into the private variable. 
                              //If we instead would have used a const ref or a const char *, moving would not be possible.
  {
    fileName_ = std::move(fileName);
    const char *fn = fileName_.c_str();
    _fp            = fopen(fn, "r+");
    if (!_fp)
    {
      std::cout << "Failed to open file" << std::endl;
    }
  }

  File(const File &other) { _fp = other._fp; }

  File &operator=(const File &rhs)
  {
    if(_fp != nullptr)
      fclose(_fp);
    _fp = rhs._fp;
    return *this;
  }

  File(File &&other) noexcept 
  {
    _fp = std::move(other._fp);
    fileName_ = std::move(other.fileName_);
    other._fp = nullptr;
  }

  File &operator=(File &&rhs) noexcept
  {
    if (this != &rhs)
    {
      std::cout << "Closing file" << std::endl;

      if(_fp)
        fclose(_fp);

      _fp = nullptr;
      _fp = std::move(rhs._fp);
      rhs._fp = nullptr;
      fileName_ = std::move(rhs.fileName_);
    }
    return *this;
  }

  ~File()
  {
    std::cout << "Closing file" << std::endl;
    if(_fp != nullptr)
      fclose(_fp);
  }
  const std::string& fileName() const
  {
    return fileName_;
  }

  std::string read(int size)
  {
    char   buffer[size];
    size_t result = fread(buffer, sizeof(*buffer), size, _fp);
    if (result == size)
    {
      return std::string(buffer);
    }
    return "";
  }

  size_t write(const std::string &data)
  {
    size_t result = fwrite(data.c_str(), data.length(), data.length(), _fp);
    return result;
  }

private:
  FILE *_fp;
  std::string fileName_;
};