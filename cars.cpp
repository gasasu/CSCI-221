#include <iostream>
#include <cmath>
using namespace std;
/*
(6 points) Write the code for a Car class. It should represent car objects that move from location
to location using fuel from their gas tank. Cars should have variables representing their position
in a two-dimensional space, their fuel efficiency in miles per gallon, the size of their fuel tank, and
how much fuel they currently have. Cars should also have a method moveto that tries to move to
new coordinates. If the car has enough fuel to drive to the new coordinates in a straight line, it
does so and returns true. If not, the car does not move and returns false.

*/

class Car{
public:
    Car();
    bool canmoveto(int x, int y);
    bool moveto(int x, int y);
    bool pmoveto(int x, int y);
    double getfuelcost(int x, int y);
    double refuel();
    double pfuel;
    double prefuel();
    bool pcanmoveto(int x, int y);
    double getfuel();
private:
    int pos_x;
    int pos_y;
    double mpg;
    double tankSize;
    double  fuel;
protected:
};

Car::Car(){
pos_x = 0;
pos_y = 0;
mpg = 5.0;
fuel = 20.0;
tankSize = 20.0;
pfuel = fuel;
};

bool Car::canmoveto(int x, int y){
double dist = sqrt(pow((x-pos_x),2) + pow((y-pos_y),2));
double fuel_used = dist / mpg;
if (fuel_used <= fuel){
    return true;
}
return false;
};
bool Car::pcanmoveto(int x, int y){
double dist = sqrt(pow((x-pos_x),2) + pow((y-pos_y),2));
double fuel_used = dist / mpg;
if (fuel_used <= pfuel){
    return true;
}
return false;
};
double Car::getfuelcost(int x, int y){
    double dist = sqrt(pow((x-pos_x),2) + pow((y-pos_y),2));
    return dist;
}
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
bool Car::pmoveto(int x, int y){
double dist = sqrt(pow((x-pos_x),2) + pow((y-pos_y),2));
double fuel_used = dist / mpg;
if (fuel_used <= pfuel){
    pos_x = x;
    pos_y = y;
    pfuel = pfuel - fuel_used;
    return true;
}
return false;
};
double Car::refuel(){
double b = tankSize - fuel;
fuel = tankSize;
return b;}

double Car::prefuel(){
double b = tankSize - pfuel;
pfuel = tankSize;
return b;}

double Car::getfuel(){
return fuel;}
/*
(4 points) Write a function that given an array of Cars and a point in two-dimensional space,
returns an array containing a copy of each of the cars that can move to that space. The input
array and the Cars in it should not be modified. The Cars in the output array should have the
moveto method called on them prior to returning. Make sure you are also returning the length of
the output array.

*/
struct result{
Car* resultarray;
int length;};
auto carList(Car carArray[], int targetX, int targetY, int size){
Car* resultarray = new Car[size];
int counter = 0;
for (int i=0; i<size; i++){
    if (carArray[i].canmoveto(targetX, targetY)){
        resultarray[counter] = carArray[i];
        counter++;
        carArray[i].moveto(targetX, targetY);
    }
}
return result{resultarray, counter};
}
/*
(c) (2 points) Write the code for a GasStation class. It should contain a location and a price in dollars
per gallon for refueling cars.

*/
class GasStation{
public:
    GasStation(int x, int y, int p){
        loc_x = x;
        loc_y = y;
        price = p;
    }
    int getlocationX() const{
    return loc_x;}
    int getlocationY() const{
    return loc_y;}
    int getprice() const{
    return price;}

private:
    int loc_x;
    int loc_y;
    int price;
};
/*
(d) (8 points) Write a modified version of your function for moving an array of cars that also takes an
array of GasStations. Cars that cannot directly move to the target location should check to see if
there is a suffix of the array of GasStations that they could move through (from earliest to latest
in the list) that would then allow them to move to the target location. (A suffix of the array is a
contiguous subset of the array containing the last element in the array.) You do not have to check
paths that are not suffixes of the list. If there is, they should be added to the output list as if they
could move there directly. In addition to the list of Cars being output, you should output a list of
the costs for each car to fill up its tank on the route to the location. (This is zero for the cars that
do not need to go to a GasStation.)
    */
struct output{
Car* res;
double* cost;};

auto modifiedCarlist(Car cararray[], GasStation gasarray[], int targetX, int targetY, int cararraylength, int gasarraylength){
int counter=0;

Car* result = new Car[cararraylength];
double* cost = new double[cararraylength];
for (int i=0; i<cararraylength; i++){
    if (cararray[i].canmoveto(targetX, targetY)){
        result[counter] = cararray[i];

        cararray[i].moveto(targetX, targetY);
        cost[counter] = 0;
        counter++;
    }
    else{
        int j = cararraylength -1; // start with last gasstation

        while (j>-1){
            double c = 0; // set cost = 0
            int x = gasarray[j].getlocationX(); // get gasstation location
            int y = gasarray[j].getlocationY();
            cararray[i].pfuel = cararray[i].getfuel(); // reset pfuel to the car's actual fuel for each iteration
            if (cararray[i].pcanmoveto(x,y)){ // if we can move to this gasstation
                cararray[i].pmoveto(x,y); // we move to the gasstation
                int m = j+1; // increment counter to the next gasstation
                double d = cararray[i].prefuel(); // get amount of fuel needed to fill tank
                c += d*gasarray[j].getprice(); // calculate cost
                while (m<cararraylength){ // while we are not at the last gasstation
                if (cararray[i].pcanmoveto(x,y)){ // if we can move to the next gasstation
                cararray[i].pmoveto(x,y); // move to the gasstation
                double d = cararray[i].prefuel(); // calculate amount of fuel needed to fill tank
                c += d*gasarray[m].getprice(); // calculate cost
                m++; // increment to next gasstation
                }
                else{
                    break; // if we can't move to gasstation, then break out and try next loop iteration
                }

            }
            if (m == cararraylength){ // if we found a suffix
        result[counter] = cararray[i]; // store our car in result
        cost[counter] = c; // store cost
        counter++; // increment counter
        break; // we break out of our outermost loop
            }

        }
        j--;
    }
}
}
return output{result, cost};
}
int main(){
    Car bmw;
    if (bmw.moveto(121,124)){
        cout<<"We made it" << endl;
    }
    else{
        cout << "Not enough fuel bro" << endl;
    }
return 0;
}
