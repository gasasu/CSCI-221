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
    double getfuelcost(int x, int y);
    double refuel();
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
};

bool Car::canmoveto(int x, int y){
double dist = sqrt(pow((x-pos_x),2) + pow((y-pos_y),2));
double fuel_used = dist / mpg;
if (fuel_used <= fuel){
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

double Car::refuel(){
double b = tankSize - fuel;
fuel = tankSize;
return b;}
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
        int j = gasarraylength-1;
        double f = 0;
        while (j>0){
                if (j==gasarraylength) break;
                double p=0;
            int a = gasarray[j].getlocationX();
        int b = gasarray[j].getlocationY();
        int c = gasarray[j].getprice();
        if (cararray[i].canmoveto(a,b)){
         cararray[i].moveto(a,b);
         p = cararray[i].refuel();
            f += p*c;
            j++;
        }
        else{
            j--;
        }
        }
    if (j==gasarraylength){
       result[counter] = cararray[i];
        cost[counter] = f;
        counter++;
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
