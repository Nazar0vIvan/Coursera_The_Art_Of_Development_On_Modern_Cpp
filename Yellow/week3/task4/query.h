#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  int stop_count;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q);


