#include <iostream>
#include <deque>
#include "Car.h"

using namespace std;

const int INIT_SIZE = 2;

int main() {
    deque<Car> cars;

    for (int i = 0; i < INIT_SIZE; i++) {
        Car newCar;
        cars.push_back(newCar);
        newCar.print();
    }

    
}