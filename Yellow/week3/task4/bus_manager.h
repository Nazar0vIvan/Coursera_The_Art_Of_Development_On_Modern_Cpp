#pragma once

#include <map>
#include <string>
#include <vector>

#include "responses.h"

using namespace std;

class BusManager{
public:
  void AddBus(const string& bus, const vector<string>& stops);

  BusesForStopResponse GetBusesForStop(const string& stop) const;

  StopsForBusResponse GetStopsForBus(const string& bus) const;

  AllBusesResponse GetAllBuses() const;

private:
  map<string,vector<string>> busToStops;
  map<string,vector<string>> stopToBuses;
};


