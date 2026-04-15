#ifndef RINGBUFFER_HPP
#define RINGBUFFER_HPP

#include <cstdlib>
#include <vector>
#include <cassert>
template <typename T>
class RingBuffer {
private:
  std::vector<T> buffer;
  size_t capacity;
  size_t head;
  size_t tail;
public: 
  RingBuffer(size_t capacity, T defaultValue); // Constructor
  
  void push_back(T value); // push at tail
  void pop_front(); // pop head
  
  // Random access
  T& operator[](size_t i);
  const T& operator[](size_t i) const;

  // Access head and tail
  T& front(); // oldest
  T& back();  // newest

  size_t size() const;  // get size
};


template <typename T>
RingBuffer<T>::RingBuffer(size_t capacity, T defaultValue) {
  RingBuffer::capacity = capacity;
  RingBuffer::head = 0;
  RingBuffer::tail = 0;
  buffer.resize(capacity + 1, defaultValue);

}

template <typename T>
void RingBuffer<T>::push_back(T value) {
  if ((tail + 1) % (capacity + 1) == head) return;
  buffer[tail] = value;
  tail = (tail + 1) % (capacity + 1);
}

template <typename T>
void RingBuffer<T>::pop_front() {
  if (head == tail) return;
  // buffer[head+1];
  head = (head + 1) % (capacity + 1);
}

template <typename T>
T& RingBuffer<T>::operator[](size_t i) {
  assert(i < size());
  i = (head + i)  % (capacity + 1);
  return buffer[i];
};

template <typename T>
const T& RingBuffer<T>::operator[](size_t i) const {
  assert(i < size());
  i = (head + i) % (capacity + 1);
  const T& ref = buffer[i];
  return ref;
};
//  // Access head and tail
template <typename T>
T& RingBuffer<T>::front() {
  assert(head != tail);
  return buffer[head];
}
template <typename T>
T& RingBuffer<T>::back() {
  assert(head != tail);
  return buffer[(tail + capacity) % (capacity + 1)];
}

template <typename T>
size_t RingBuffer<T>::size() const {
  return (tail + (capacity + 1) - head) % (capacity + 1);
}
#endif
