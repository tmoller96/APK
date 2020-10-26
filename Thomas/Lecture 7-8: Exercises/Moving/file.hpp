#include <iostream>

class File
{
private:
    FILE *fptr_;
public:
    File(std::string fileName);
    ~File();
    File(File&& other) noexcept;
    File& operator=(File&& other) noexcept;
    File(const File &other);
    File& operator=(const File& other);
    void Read();
    void Write();
};

File::File(std::string fileName)
{
    std::string path = "./files/" + fileName;
    fptr_ = fopen(path.c_str(), "w+");
}

File::~File()
{
    if(fptr_ != nullptr)
    {
        fclose(fptr_);
    }
}

File::File(File&& other) noexcept : fptr_{std::move(other.fptr_)}
{
    other.fptr_ = nullptr;
}

File& File::operator=(File&& other) noexcept
{
    if(this != &other)
    {
        delete fptr_;
        fptr_ = nullptr;
        std::swap(other.fptr_, fptr_);
    }
    return *this;
}

File::File(const File &other)
{
    fptr_ = other.fptr_;
}

File& File::operator=(const File& other)
{
    fptr_ = other.fptr_;
    return *this;
}

void File::Read(){

}

void File::Write() {

}
