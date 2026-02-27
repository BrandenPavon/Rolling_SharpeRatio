#ifndef DATAFEED_HPP
#define DATAFEED_HPP
#include <iostream>
#include <fstream>
#include <deque>
#include <string>

class DataFeed {
private: 
  //PRIVATE DATA
  std::ifstream csv_to_parse;
  std::deque<double> prices;
  double runningsum;


public:
  // PUBLIC METHODS
  DataFeed(std::string& csv);
  int PricesSize();
};

#endif 
