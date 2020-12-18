#include <memory_resource>
template <typename T, typename Alloc, typename... CtorArgs>
T *new_object(Alloc alloc, CtorArgs &&... ctor_args)
{
  T *t = static_cast<T *>(alloc.resource()->allocate(sizeof(T), alignof(T)));
  try
  {
    alloc.construct(t, forward<CtorArgs>(ctor_args)...);
  }
  catch (...)
  {
    alloc.resource()->deallocate(t, sizeof(T), alignof(T));
    throw;
  }
  return t;
}

template <typename Alloc, typename T> void delete_object(Alloc alloc, T *t)
{
  alloc.destroy(t);
  alloc.resource()->deallocate(t, sizeof(T), alignof(T));
}
