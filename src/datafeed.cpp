#include "datafeed.hpp"
#include <string>
#include <cmath>
#include <iostream>
#include <utility>
#include <cstdint>
#include <cstddef>
#include <stdexcept>
#include <fstream>
#include <sstream>

// delete copy constructor and copy operator
#define DEFAULT_WINDOW 1000
#define DEFAULT_VALUE 0
size_t DataFeed::PricesSize() { return TimestampRingBuffer.size(); }
// stopatLineK defaults to 0



DataFeed::DataFeed(std::string csv, uint64_t stopatLineK)
  : TimestampRingBuffer(DEFAULT_WINDOW, DEFAULT_VALUE),
    PriceRingBuffer(DEFAULT_WINDOW, DEFAULT_VALUE),
    PriceReturnsRingBuffer(DEFAULT_WINDOW, DEFAULT_VALUE) {
  
}

void DataFeed::changeCSV(std::string csv) {
  csv_to_parse.open(csv);

};

void DataFeed::changeCurrentLine(uint64_t k) {};

void DataFeed::addNewPrice(double price) {
  //double SimpleReturn = std::log(price / data.back().second);
  //RunningPriceReturnSum += SimpleReturn;
  //RunningPriceReturnSumSquared += SimpleReturn*SimpleReturn;
};
