#include <iostream>
#include <fstream>
#include <string>
#include "datafeed.hpp"
#include "performancemonitor.hpp"
#include "rollingsharpeengine.hpp"

class ReturnCalculator {

};


class SharpePublisher {

};


double RiskFreeRateProvider();


int main() {
  DataFeed df("test.csv", 5);
  //RollingSharpeEngine rse(df);
  return 0;
}
