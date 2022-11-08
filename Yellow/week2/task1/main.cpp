#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType{
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query{
  QueryType type;
  int stop_count;
  string bus;
  string stop;
  vector<string> stops;
};


istream& operator >> (istream& is, Query& q){
  string typeStr;
  is >> typeStr;
  if (typeStr == "NEW_BUS"){
    q.type = QueryType::NewBus;
    is >> q.bus;
    int stop_count = 0;
    is >> stop_count;
    q.stops.resize(stop_count);
    for (auto& stop : q.stops){
      is >> stop;
    }
  }
  else if (typeStr == "BUSES_FOR_STOP"){
    q.type = QueryType::BusesForStop;
    is >> q.stop;
  }
  else if (typeStr == "STOPS_FOR_BUS"){
    q.type = QueryType::StopsForBus;
    is >> q.bus;
  }
  else if (typeStr == "ALL_BUSES"){
    q.type = QueryType::AllBuses;
  }

  return is;
}

struct BusesForStopResponse{
  vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r)
{
  if (r.buses.empty()){
    os << "No stop";
  }
  else{
    for (const auto& bus : r.buses){
      os << bus << " ";
    }
  }
  return os;
}

struct StopsForBusResponse{
    string bus;
    // вектор остановок для конкретного автобуса, остановка - первый элемент пары,
    // а второй элемент - вектор автобусов этой остановки
    vector<pair<string, vector<string>>> stopsForBuses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r)
{
  if (r.stopsForBuses.empty()){
    os << "No bus";
  }
  else{
    bool first = true;
    for (const auto& stop_and_buses : r.stopsForBuses){
      if (!first){
        os << endl;
      }
      first = false;
      os << "Stop " << stop_and_buses.first << ":";
      if (stop_and_buses.second.size() == 1){
        os << " no interchange";
      }
      else{
        for (const auto& bus : stop_and_buses.second){
          if (bus != r.bus){
            os << " " << bus;
          }
        }
      }
    }
  }
  return os;
}

struct AllBusesResponse{
  map<string, vector<string>> busToStops;
};

ostream& operator << (ostream& os, const AllBusesResponse& r){
  if (r.busToStops.empty()){
    os << "No buses";
  }
  else{
    bool first = true;
    for (const auto& bus_and_stops : r.busToStops){
      if (!first){
        os << endl;
      }
      first = false;
      os << "Bus " << bus_and_stops.first << ":";
      for (const auto& stop : bus_and_stops.second){
        os << " " << stop;
      }
    }
  }
  return os;
}

class BusManager{
public:
  void AddBus(const string& bus, const vector<string>& stops){
    busToStops.insert(make_pair(bus, stops));
    for (const auto& stop : stops){
      stopToBuses[stop].push_back(bus);
    }
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const{
    if (!stopToBuses.count(stop)){
      return BusesForStopResponse{vector<string>()};
    }
    else{
      return BusesForStopResponse{stopToBuses.at(stop)};
    }
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const{
    // для каждой остановки stop автобуса bus вывести автобусы other_bus, у которых есть эта остановка stop
    vector<pair<string, vector<string>>> result;
    if (busToStops.count(bus) > 0){
      for (const auto& stop : busToStops.at(bus)){
        result.push_back(make_pair(stop, busToStops.at(stop)));
      }
    }
    return StopsForBusResponse{bus, result};
  }

  AllBusesResponse GetAllBuses() const{ return AllBusesResponse{ busToStops }; }

private:
    map<string,vector<string>> busToStops;
    map<string,vector<string>> stopToBuses;

};

// Не меняя тела функции main, реализуйте функции и классы выше

int main(){
  Query q;
  int query_count;
  cin >> query_count;
  BusManager bm;
  for (int i = 0; i < query_count; ++i){
    cin >> q;
    switch (q.type){
      case QueryType::NewBus:
        bm.AddBus(q.bus, q.stops);
        break;
      case QueryType::BusesForStop:
        cout << bm.GetBusesForStop(q.stop) << endl;
        break;
      case QueryType::StopsForBus:
        cout << bm.GetStopsForBus(q.bus) << endl;
        break;
      case QueryType::AllBuses:
        cout << bm.GetAllBuses() << endl;
        break;
    }
  }

  return 0;
}
