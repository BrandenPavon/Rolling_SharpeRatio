#include "datafeed.hpp"
#include <string>
#include <iostream>
#include <utility>

#include <fstream>
#include <sstream>
int DataFeed::PricesSize() {
  return data.size(); 
}
DataFeed::DataFeed(std::string& csv) {

  csv_to_parse.open(csv);
  if (!csv_to_parse) throw "File does not exist";

  std::string line{};
  while (std::getline(csv_to_parse, line)) {
    std::istringstream iss(line);
    std::string value{};
    //
    std::pair<int, double> datapair;

    std::getline(iss, value, ',');
    datapair.first = std::stoi(value);

    std::getline(iss, value, ',');
    datapair.second = std::stoi(value);

    data.push_back(datapair);
  }
};


