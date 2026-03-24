#ifndef DATAFEED_HPP
#define DATAFEED_HPP
#include <iostream>
#include <fstream>
#include <deque>
#include <string>
#include <cstdint>
#include <cstddef>
#include <utility> 

class DataFeed {
private: 
  //PRIVATE DATA
  std::ifstream csv_to_parse;
  // timestamp, price
  std::deque<std::pair<uint64_t, double>> data;
  double RunningPriceTotalSum{};
  uint64_t currentLine{};

public:
  DataFeed(std::string csv, uint64_t stopatLineK = 0);

// We are deleting the copy constructor as the DataFeed class deals with streams
// and files (I/O operations) which cannot be copied
  
  DataFeed(const DataFeed&) = delete;
  DataFeed& operator=(const DataFeed&) = delete;
// We need to use the move constructor/move operator to use it
// since we can not use the copy constructor
  DataFeed(DataFeed&& newDF);
  DataFeed& operator=(DataFeed&& newDF);

  size_t PricesSize();
  double CalculateRunningPriceTotalSum();

  void changeCSV(std::string csv);
  void changeCurrentLine(uint64_t k);
  void readNextPrice();
  void populateData();
};

#endif 
