#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct BusesForStopResponse {
  vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
  string bus;
  // вектор остановок для конкретного автобуса, остановка - первый элемент пары, а второй элемент - вектор автобусов этой остановки
  vector<pair<string,vector<string>>> stopsForBuses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
  map<string,vector<string>> busToStops;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);
