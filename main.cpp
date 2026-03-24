#include <iostream>
#include <exception>

#include "datafeed.hpp"
#include "performancemonitor.hpp"
#include "rollingsharpeengine.hpp"

class ReturnCalculator {

};


class SharpePublisher {

};


double RiskFreeRateProvider();


int main() {
  try {
    DataFeed df("testdata/test.csv", 5);
  } catch (const std::exception& e) {
    std::cerr << "Error: " << e.what() << '\n';
  }
  //RollingSharpeEngine rse(df);
  return 0;
}
