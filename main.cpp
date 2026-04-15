#include <iostream>
#include <exception>

#include "datafeed.hpp"
#include "performancemonitor.hpp"
#include "rollingsharpeengine.hpp"
#include "ringbuffer.hpp"
class ReturnCalculator {

};


class SharpePublisher {

};


double RiskFreeRateProvider();


int main() {
  RingBuffer<double> testbuffer(99, -0.1);
  testbuffer.push_back(0.1);
  testbuffer.push_back(0.2);
  testbuffer.push_back(0.3);
  std::cout << testbuffer.front() << '\n';
  testbuffer.pop_front();
  std::cout << testbuffer.front() << '\n';
  std::cout << testbuffer[0] << '\n';


  return 0;
  try {
    DataFeed df("testdata/test.csv", 5);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << '\n';
  }
  //RollingSharpeEngine rse(df);
  return 0;
}
