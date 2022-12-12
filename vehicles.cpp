#include <iostream>
#include <vector>
#include <math.h>
#include <list>
#include <memory>
#include <string>
#include <unordered_map>
using namespace std;


class Car{
public:
    Car();
    virtual bool canmoveto(int x, int y);
    virtual bool moveto(int x, int y);
    double refuel();
    virtual double getfuel();

protected:
    int pos_x;
    int pos_y;
    double mpg;
    double tankSize;
    double  fuel;
};

Car::Car(){
pos_x = 0;
pos_y = 0;
mpg = 5.0;
fuel = 20.0;
tankSize = 20.0;
};

bool Car::canmoveto(int x, int y){
double dist = sqrt(pow((x-pos_x),2) + pow((y-pos_y),2));
double fuel_used = dist / mpg;
if (fuel_used <= fuel){
    return true;
}
return false;
};

bool Car::moveto(int x, int y){
double dist = sqrt(pow((x-pos_x),2) + pow((y-pos_y),2));
double fuel_used = dist / mpg;
if (fuel_used <= fuel){
    pos_x = x;
    pos_y = y;
    fuel = fuel - fuel_used;
    return true;
}
return false;
};

double Car::refuel(){
double b = tankSize - fuel;
fuel = tankSize;
return b;}

double Car::getfuel(){
return fuel;}

/*
 (8 points) Create a Bus class. This class should inherit from the Car class. In addition, a Bus
should have three additional variables: a maximum number of passengers, a vector of the stop
numbers that passengers are getting off at. and a gas mileage penalty per passenger. Each element
in the vector represents a single passenger getting off at that stop. The Bus class should implement
a generateroute method that takes as input a starting stop, and returns an STD list of stops to
go to. The list of stops should be all of the unique elements in the passengers variable sorted in
ascending order, but starting with starting stop and wrapping around to smaller stop numbers. The
moveto method should be overridden to use extra gas based on the product of the current number
of passengers and the mileage per passenger penalty.

*/
class Bus : virtual public Car{
public:
    list<int> generateroute(int start);
    bool moveto(int x, int y);
    Bus(int p);
    int getposx() const{
    return pos_x;}
    int getposy() const{
    return pos_y;}
private:
    int max_passengers;
    vector <int> stop;
    double gmp;
    int passengers;
    };

Bus::Bus(int p){
max_passengers = 10;
gmp = 0.05;
passengers = p;
}
bool Bus::moveto(int x, int y){
double dist = sqrt(pow((x-pos_x),2) + pow((y-pos_y),2));
double fuel_used = dist / mpg;
fuel_used += passengers * gmp;
if (fuel_used <= fuel){
    pos_x = x;
    pos_y = y;
    fuel -= fuel_used;
    return true;
}
return false;
}
list<int> Bus::generateroute(int start) {
  vector<int> stops_vec(passengers.begin(), passengers.end());
  sort(stops_vec.begin(), stops_vec.end());  // sort the stops in ascending order
  vector<int>::iterator it = unique(stops_vec.begin(), stops_vec.end());  // remove duplicates
  stops_vec.resize(distance(stops_vec.begin(), it));

  // find the index of the starting stop in the vector of stops
  int start_idx = -1;
  for (int i = 0; i < stops_vec.size(); i++) {
    if (stops_vec[i] == start) {
      start_idx = i;
      break;
    }
  }

  // create the list of stops to go to by starting with the starting stop and wrapping around to smaller stop numbers
  list<int> stops;
  for (int i = start_idx; i < stops_vec.size(); i++) {
    stops.push_back(stops_vec[i]);
  }
  for (int i = 0; i < start_idx; i++) {
    stops.push_back(stops_vec[i]);
  }

  return stops;
}

#include <string>
#include <unordered_map>

class MedicalCenter {
public:
  // add a provider to the center with the given role
  void addProvider(const std::string& name, const std::string& role) {
    providers[name] = role;
  }

  // add a patient to the center with the given condition
  void addPatient(const std::string& name, const std::string& condition) {
    patients[name] = condition;
  }

  // get the role of the provider with the given name
  std::string getProviderRole(const std::string& name) const {
    return providers.at(name);
  }

  // get the condition of the patient with the given name
  std::string getPatientCondition(const std::string& name) const {
    return patients.at(name);
  }

private:
  // map from provider name to provider role
  std::unordered_map<std::string, std::string> providers;
  // map from patient name to patient condition
  std::unordered_map<std::string, std::string> patients;
};



class MedicalCenter {
public:
  // add a provider to the center with the given role
  void addProvider(const std::string& name, const std::string& role) {
    providers[name] = role;
  }

  // add a patient to the center with the given condition
  void addPatient(const std::string& name, const std::string& condition) {
    patients[name] = condition;
  }

  // get the role of the provider with the given name
  std::string getProviderRole(const std::string& name) const {
    return providers.at(name);
  }

  // get the condition of the patient with the given name
  std::string getPatientCondition(const std::string& name) const {
    return patients.at(name);
  }

private:
  // map from provider name to provider role
  std::unordered_map<std::string, std::string> providers;
  // map from patient name to patient condition
  std::unordered_map<std::string, std::string> patients;
};




std::vector<std::unique_ptr<Car>> moveCars(
    const std::vector<std::unique_ptr<Car>>& cars,
    int x,
    int y) {
  std::vector<std::unique_ptr<Car>> result;
  for (const auto& car : cars) {
    if (car->canmoveto(x, y)) {
      // create a copy of the car that can move to the given location
      auto copy = std::make_unique<Car>(*car);
      // move the copy to the given location
      copy->moveto(x, y);
      // add the copy to the result vector
      result.


int main(){
Bus b(6);
b.moveto(3,4);
cout << b.getfuel() << endl;
cout << b.getposx() << endl;
return 0;}
