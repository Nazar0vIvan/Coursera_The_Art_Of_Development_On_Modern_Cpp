#include "responses.h"

using namespace std;

ostream& operator << (ostream& os, const BusesForStopResponse& r)
{
  if (r.buses.empty()) {
    os << "No stop";
  }
  else {
    for (const auto& bus : r.buses) {
      os << bus << " ";
    }
  }
  return os;
}

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  if (r.stopsForBuses.empty()) {
    os << "No bus";
  }
  else {
    bool first = true;
    for (const auto& stop_and_buses : r.stopsForBuses) {
      if (!first) {
        os << endl;
      }
      first = false;
      os << "Stop " << stop_and_buses.first << ":";
      if (stop_and_buses.second.size() == 1) {
        os << " no interchange";
      }
      else {
        for (const auto& bus : stop_and_buses.second) {
          if (bus != r.bus) {
            os << " " << bus;
          }
        }
      }
    }
  }
  return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r)
{
  if (r.busToStops.empty()) {
    os << "No buses";
  }
  else {
    bool first = true;
    for (const auto& bus_and_stops : r.busToStops) {
      if (!first) {
        os << endl;
      }
      first = false;
      os << "Bus " << bus_and_stops.first << ":";
      for (const auto& stop : bus_and_stops.second) {
        os << " " << stop;
      }
    }
  }
  return os;
}
