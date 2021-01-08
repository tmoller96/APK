template <typename T>
class MyArray
{
private:
    int size_;
    T *container_;
public:
    explicit MyArray(int n){
        
    }
    MyArray(MyArray<T> const &rhs)
    {

    }
    ~MyArray();
};
