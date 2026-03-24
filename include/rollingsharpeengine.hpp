#ifndef ROLLINGSHARPEENGINE_HPP
#define ROLLINGSHARPEENGINE_HPP
#include "datafeed.hpp"
#include "performancemonitor.hpp"


class RollingSharpeEngine {
private:
  DataFeed dataF;
  PerformanceMonitor perfMonitor;
  

public:
  RollingSharpeEngine(DataFeed df);
  //RollingSharpeEngine(const RollingSharpeEngine&);
  //virtual ~RollingSharpeEngine();



};

#endif
