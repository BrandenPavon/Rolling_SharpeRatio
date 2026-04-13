#include "ringbuffer.hpp"

template <typename T>
RingBuffer::RingBuffer(size_t size) {
  buffer.resize(size, 0);

};
void RingBuffer::push(T value) {
  
  return;
}
// T& operator[](size_t i);
// const T& operator[](size_t i) const;
//  // Access head and tail
//T& front(); // oldest
//T& back();  // newest

