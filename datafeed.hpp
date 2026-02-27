#ifndef DATAFEED_HPP
#define DATAFEED_HPP
#include <iostream>
#include <fstream>
#include <string>

class DataFeed {
  
  std::ifstream csv_to_parse;
  std::deque<double> prices;
  double runningsum;
  DataFeed(std::string csv) {

  };
  int PricesSize() {
    return prices.size(); 
  }
};

#endif 
