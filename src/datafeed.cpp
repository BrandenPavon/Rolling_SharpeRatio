#include "datafeed.hpp"
#include <string>
#include <iostream>
#include <utility>
#include <cstdint>
#include <cstddef>
#include <stdexcept>
#include <fstream>
#include <sstream>

// delete copy constructor and copy operator


size_t DataFeed::PricesSize() {
  return data.size(); 
}

// stopatLineK defaults to 0
DataFeed::DataFeed(std::string csv, uint64_t stopatLineK) {
  csv_to_parse.open(csv);
  if (!csv_to_parse) throw std::runtime_error("File does not exist");;
  std::string line{};
  uint64_t currentline{1};
  

  // condition statement ends at EOF or line K if arguement given
  while (std::getline(csv_to_parse, line) && (currentline <= stopatLineK || stopatLineK == 0) ) {
    std::istringstream iss(line);
    std::string value{};
    //
    std::pair<int, double> datapair;

    std::getline(iss, value, ',');
    datapair.first = static_cast<uint64_t>(std::stoull(value));

    std::getline(iss, value, ',');
    datapair.second = std::stod(value);

    data.push_back(datapair);
    currentline++;
  }
}

void DataFeed::changeCSV(std::string csv) {
  csv_to_parse.open(csv);

};
void DataFeed::changeCurrentLine(uint64_t k) {};

