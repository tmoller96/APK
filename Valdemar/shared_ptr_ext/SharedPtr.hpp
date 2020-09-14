template <class T>
class SharedPtr
{
private:
    T* _ptr;
    int* _count;
    
public:
    explicit SharedPtr()
    {

    }
    explicit SharedPtr(T* t) : _count(new int{1}), _ptr(t)
    {
    }
    template<typename T, typename D>
    SharedPtr(T* t, D d)
    {

    }
    //If this is not set to explicit then the following will compile as Constructor only takes 1 argument
    //void func()
    // {
    //     T obj(params);
    //     SharedPtr ptr(&t);
    //     if(SharedPtr == 3)
    //     {

    //     }
    //     else
    //     {
            
    //     }        
    // }
    //If set to explicit then error occurs compile time same goes for copy constructor
    explicit SharedPtr(const SharedPtr<T>& ptr) : _ptr(ptr._ptr), _count(ptr._count)
    {
        (*_count)++;
    } 
    SharedPtr<T>& operator=(const SharedPtr<T>& other)
    {
        if(this != &other)
        {
            if(_count == nullptr)
            {
                
            }
            else if((*_count)-- == 0)
            {
                delete _ptr;
                delete _count;
            }
            _ptr = other._ptr;
            _count = other._count;
            (*_count)++;
        }
        return *this;
    }
    virtual ~SharedPtr()
    {
        if(*_count <= 0)
        {
            delete _ptr;
            delete _count;
        }
        else 
        {
            (*_count)--;
        }
    }
    //Implements overload of * and -> for pointer like syntax
    T& operator*()
    {
        return *_ptr;
    }
    T* operator->()
    {
        return _ptr;
    }
    explicit operator bool()
    {
        return _ptr != nullptr;
    }
    template<typename U>
    bool operator ==(SharedPtr<U> &rhs)
    {
        return _ptr == rhs._ptr;
    }

};

