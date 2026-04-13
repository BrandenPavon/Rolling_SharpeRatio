#ifndef RINGBUFFER_HPP
#define RINGBUFFER_HPP

#include <cstdlib>
#include <vector>
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
  buffer[tail] = value;
  tail = (tail + 1) % capacity;
}

template <typename T>
void RingBuffer<T>::pop_front() {
  // buffer[head+1];
  head = (head + 1) % capacity;
}

// T& operator[](size_t i);
// const T& operator[](size_t i) const;
//  // Access head and tail
template <typename T>
T& RingBuffer<T>::front() {
  return buffer[head];
}
template <typename T>
T& RingBuffer<T>::back() {
  return buffer[tail];
}

#endif
