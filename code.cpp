// COMSC-210 | Lab 32 | Fahad Fawad Ahmad 
// IDE used: Visual Studio
#include <iostream>
#include <deque>
#include "Car.h"

using namespace std;

const int INIT_SIZE = 2;

int main() {
    srand(time(0));
    deque<Car> cars;

    cout << "Initial queue:" << endl;
    for (int i = 0; i < INIT_SIZE; i++) {
        Car newCar;
        cars.push_back(newCar);
        newCar.print();
    }
    cout << endl;

    int count = 1;
    while (!cars.empty()) {
        int chances = rand() % 100 + 1;
        cout << "Time: " << count << "\nOperation: ";

        if (chances <= 55) { //Pays toll and leaves
            cout << "Car paid: ";
            cars[0].print();
            cars.pop_front();
        } else { //New car joins
            cout << "Joined lane: ";
            Car newcar;
            cars.push_back(newcar);
            newcar.print();
        }
        
        //Queue printing
        cout << "Queue:" << endl;
        for (int i = 0; i < cars.size(); i++) {
            cout << "    ";
            cars[i].print();
        }
        cout << endl;
    
        count++;
    }
    cout << "Empty" << endl;
}