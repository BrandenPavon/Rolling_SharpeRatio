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
  RingBuffer(size_t capacity); // Constructor
  
  void push_front(T value); // push at head
  void push_back(T value); // push at tail
  void pop_front(T value); // pop head
  void pop_tail(T value); // pop tail
  
  // Random access
  T& operator[](size_t i);
  const T& operator[](size_t i) const;

  // Access head and tail
  T& front(); // oldest
  T& back();  // newest
};

#endif
