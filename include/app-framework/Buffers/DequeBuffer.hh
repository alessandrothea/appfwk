#ifndef app_framework_Buffers_DequeBuffer_hh
#define app_framework_Buffers_DequeBuffer_hh

#include "app-framework-base/Buffers/Buffer.hh"

#include <deque>
#include <functional>

namespace appframework{

  template <class T>
  class DequeBuffer : public Buffer {
    
  public:

    DequeBuffer();

    void Configure();
    
    size_t size() { return fDeque.size(); }
    size_t capacity() { return fCapacity; }

    size_t sizeBytes() { return fDeque.size()*sizeof(T); }
    size_t capacityBytes() { return fCapacity*sizeof(T); }
    
    int push(const T&); ///push one on, return new size if successful, -1 if not
    int pop(T&);        ///pop one off, return new size if successful, -1 if not

    //std::deque<T>::iterator findFirst(std::function<bool(const T&)> pred) const;
    //std::deque<T>::iterator findLast(std::function<bool(const T&)> pred) const;

  private:
    
    std::deque<T> fDeque;
    size_t        fCapacity;

  };

}


#endif //app_framework_Buffers_Buffer_hh
