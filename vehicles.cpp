#include <iostream>
#include <vector>
#include <math.h>
#include <list>
#include <memory>
#include <string>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;


class Car{
public:
    Car();
    virtual bool canmoveto(int x, int y);
    virtual bool moveto(int x, int y);
    double refuel();
    virtual double getfuel();
    ~Car() = default;
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
    ~Bus() = default;
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
// updated moveto function to include gas mileage penalty per passenger
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
  vector<int> stops_vec(stop.begin(), stop.end());
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

/*
Create a MedicalCenter class. This class should contain a data structure that lists the
providers at the center and their roles, as well as another data structure that lists the patients at
that center and their condition. Both roles and conditions should be represented with strings.
*/

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

private:
  // map from provider name to provider role
  std::unordered_map<std::string, std::string> providers;
  // map from patient name to patient condition
  std::unordered_map<std::string, std::string> patients;
};


/*
Create an Ambulance Class. This class should inherit functionality from both a Car and
a MedicalCenter. In addition, an ambulance should have three additional variables: a maximum
capacity of patients, a maximum total capacity of patients and providers, and a gas mileage penalty
per person. The moveto method should be overridden to use extra gas based on the product of the
current capacity of the ambulance and the mileage per person penalty.
*/
class Ambulance: virtual public Car, virtual public MedicalCenter{
public:
    bool moveto(int x, int y);
    Ambulance();
    ~Ambulance() = default;
private:
    int max_patients;
    int max_capacity;
    int capacity;
    double gmp;
};

Ambulance::Ambulance(){
capacity = 0;
gmp = 0.05;
max_patients = 10;
max_capacity = 20;
}

bool Ambulance::moveto(int x, int y){
double dist = sqrt(pow((x-pos_x),2) + pow((y-pos_y),2));
double fuel_used = dist / mpg;
fuel_used += capacity * gmp;
if (fuel_used <= fuel){
    pos_x = x;
    pos_y = y;
    fuel -= fuel_used;
    return true;
}
return false;
}
/*
Write a function that takes as input a vector of unique pointers to Cars and a point in
two-dimensional space. The function should return a vector containing a copy of each of the cars
that can move to that space. The input array and the Cars in it should not be modified. The
Cars in the output array should have the moveto method called on them prior to returning. Your
function should be able to handle instances of Cars, Buses, and Ambulances in the input vector.
Each should use the proper moveto method.
*/

std::vector <Car*> moveCars( std::vector<std::unique_ptr<Car>>& cars,int x,int y) {
  std::vector<Car*> result;
  for (const auto& car : cars) {
    if (car->canmoveto(x, y)) {
      // create a copy of the car that can move to the given location
      auto *newptr = car.get(); // returns pointer to car object
      auto cpy = *newptr; // creates a copy of the car object
      // move the copy to the given location
      auto *copy = &cpy; // creates a pointer to the new object
      copy->moveto(x, y);
      // add the copy to the result vector
      result.push_back(copy);}
  }
  return result;
}


int main(){
    vector <std::unique_ptr <Car> > lista;
    std::unique_ptr<Car> car = std::make_unique<Car>();
    std::unique_ptr<Car> bus = std::make_unique<Bus>(7);
    std::unique_ptr<Car> ambulance = std::make_unique<Ambulance>();
    Ambulance amb;
    Car *mv = &amb;
    cout << ambulance->moveto(3,4) << endl;
    cout << mv->moveto(1,2) << endl;
    cout << amb.moveto(2,3) << endl;
return 0;
}
