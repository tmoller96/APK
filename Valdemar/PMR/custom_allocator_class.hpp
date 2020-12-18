#include "helpers.cpp"
#include <memory_resource>
#include <vector>
class CustomAllocatorDtoClass
{
public:
  using allocator_type = std::pmr::polymorphic_allocator<std::byte>;

  CustomAllocatorDtoClass(allocator_type alloc = {})
      : _alloc(alloc), _randomDouble(10.03231), _randomInt(103124)
  {
    _data = static_cast<char *>(
        alloc.resource()->allocate(sizeof(char) * 20, alignof(char)));
  }

  //   // Copy constructors:
  //   CustomAllocatorDtoClass(const CustomAllocatorDtoClass &other) {}

  //   CustomAllocatorDtoClass(const CustomAllocatorDtoClass &other,
  //                           allocator_type                 alloc)
  //   {
  //   }

  // Copy assignment
  //   CustomAllocatorDtoClass &operator=(const CustomAllocatorDtoClass &other)
  //   {}

  ~CustomAllocatorDtoClass()
  {
    _alloc.resource()->deallocate(_data, sizeof(char) * 20, alignof(char));
  }
  allocator_type get_allocator() { return _alloc; }

private:
  allocator_type _alloc;
  int            _randomInt;
  double         _randomDouble;
  char *         _data;
};

class CustomAllocatorClass
{
  using allocator_type = std::pmr::polymorphic_allocator<std::byte>;

public:
  CustomAllocatorClass(allocator_type alloc = {}) {
      for(int i = 0; i < 10; ++i) {
          objects.emplace_back();
      }
  }

  allocator_type get_allocator() { return _alloc; }

private:
  allocator_type                            _alloc;
  std::pmr::vector<CustomAllocatorDtoClass> objects;
};