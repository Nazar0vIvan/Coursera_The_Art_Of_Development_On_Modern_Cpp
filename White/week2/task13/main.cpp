#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

// BUSES_FOR_STOP
void PrintBusesForStop(map<string, vector<string>>& stops2buses, const string& stop){
  if (stops2buses.count(stop) == 0){
    cout << "No stop" << endl;
  }
  else{
    for (const string& bus : stops2buses[stop]){
      cout << bus << " ";
    }
    cout << endl;
  }
}

// STOPS_FOR_BUS
void PrintStopsForBus(map<string, vector<string>>& buses2stops, map<string, vector<string>>& stops2buses, const string& bus){
  if (buses2stops.count(bus) == 0){
    cout << "No bus" << endl;
  }
  else{
    for (const string& stop : buses2stops[bus]){
      cout << "Stop " << stop << ": ";

      if (stops2buses[stop].size() == 1){
        cout << "no interchange";
      }
      else{
        for (const string& other_bus : stops2buses[stop]){
          if (bus != other_bus){
            cout << other_bus << " ";
          }
        }
      }
      cout << endl;
    }
  }
}

// ALL_BUSES
void PrintAllBuses(const map<string, vector<string>>& buses_to_stops){
  if (buses_to_stops.empty()){
    cout << "No buses" << endl;
  } else{
    for (const auto& bus_item : buses_to_stops){
      cout << "Bus " << bus_item.first << ": ";
      for (const string& stop : bus_item.second){
        cout << stop << " ";
      }
      cout << endl;
    }
  }
}

int main(){
  int q;
  cin >> q;

  map<string, vector<string>> buses2stops, stops2buses;

  for (int i = 0; i < q; ++i){
    string operation_code;
    cin >> operation_code;

    if (operation_code == "NEW_BUS"){
      string bus;
      cin >> bus;
      int stop_count;
      cin >> stop_count;

      vector<string>& stops = buses2stops[bus];
      stops.resize(stop_count);

      for (string& stop : stops){
        cin >> stop;
        stops2buses[stop].push_back(bus);
      }
    }
    else if (operation_code == "BUSES_FOR_STOP"){
      string stop;
      cin >> stop;
      PrintBusesForStop(stops2buses, stop);

    }
    else if (operation_code == "STOPS_FOR_BUS"){
      string bus;
      cin >> bus;
      PrintStopsForBus(buses2stops, stops2buses, bus);

    }
    else if (operation_code == "ALL_BUSES"){
      PrintAllBuses(buses2stops);
    }
  }

  return 0;
}
