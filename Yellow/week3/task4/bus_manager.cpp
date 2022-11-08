#include "bus_manager.h"

using namespace std;

void BusManager::AddBus(const string &bus, const vector<string> &stops) {
  busToStops.insert(make_pair(bus, stops));
  for (const auto& stop : stops) {
    busToStops[stop].push_back(bus);
  }
}

BusesForStopResponse BusManager::GetBusesForStop(const string &stop) const {
  auto iter = stopToBuses.find(stop);
  if (iter == stopToBuses.end()) {
    return BusesForStopResponse{vector<string>()};
  }
  else{
    return BusesForStopResponse{iter->second};
  }
}

StopsForBusResponse BusManager::GetStopsForBus(const string &bus) const {
  // для каждой остановки stop автобуса bus вывести автобусы other_bus, у которых есть эта остановка stop
  vector<pair<string, vector<string>>> result;

  auto iter = busToStops.find(bus);
  if (iter != busToStops.end()) {
    for (const auto& stop : iter->second) {
      result.push_back(make_pair(stop, busToStops.at(stop)));
    }
  }
  return StopsForBusResponse{ bus, result };
}

AllBusesResponse BusManager::GetAllBuses() const
{
  return AllBusesResponse{ busToStops };
}
