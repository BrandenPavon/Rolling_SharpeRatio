#ifndef DATAFEED_HPP
#define DATAFEED_HPP
#include <iostream>
#include <fstream>
#include <deque>
#include <string>
#include <utility> 

class DataFeed {
private: 
  //PRIVATE DATA
  std::ifstream csv_to_parse;
  // timestamp, price
  std::deque<std::pair<int, double>> data;
  double RunningPriceTotalSum{};
  int currentLine{};

public:
  // PUBLIC METHODS
  DataFeed(std::string& csv);
  DataFeed(std::string& csv, int stopatLineK);
  int PricesSize();
  double CalculateRunningPriceTotalSum();

  void readNextPrice();
  void populateData();
};

#endif 
