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
  // Use a deque for data because it allows push pop operations and faster grow time than vector, tradeoff: memory is in chunks
  std::deque<std::pair<uint64_t, double>> data;
  
  uint8_t windowSize{};

  double RunningPriceTotalSum{};
  double RunningPriceTotalSumSquared{};
  // double r = log(price_t / price_{t-1}) simple return
  // add r_new to running sum both, subtract r_old
  // mean = RunningPriceTotalSum / windowSize;
  // variance  = (RunningPriceTotalSumSquared / windowSize) - mean * mean;
  // double sharpe = (mean - rf) / std; std = sqrt(variance)

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
