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
  std::deque<std::pair<double, double>> prices;
  double RunningPriceTotalSum{};
  int currentLine{};

public:
  // PUBLIC METHODS
  DataFeed(std::string& csv);
  int PricesSize();
  double CalculateRunningPriceTotalSum();

  void readNextPrice();
  void populateData();
};

#endif 
