#include "ringbuffer.hpp"
#include <cstdlib>

template <typename T>
RingBuffer<T>::RingBuffer(size_t capacity) {
  RingBuffer::capacity = capacity;
  RingBuffer::head = 0;
  RingBuffer::tail = 0;
  buffer.resize(capacity + 1, 0);

}
template <typename T>
void RingBuffer<T>::push_front(T value) {
  // buffer[head+1];
  head = (head + 1) % capacity;
}
// T& operator[](size_t i);
// const T& operator[](size_t i) const;
//  // Access head and tail
//T& front(); // oldest
//T& back();  // newest

