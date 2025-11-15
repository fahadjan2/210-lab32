// COMSC-210 | Lab 33 | Fahad Fawad Ahmad 
// IDE used: Visual Studio
#include <iostream>
#include <deque>
#include "Car.h"

using namespace std;

const int INIT_SIZE = 2;
const int LANES_SIZE = 4;
const int LEAVE_PROB = 46;
const int JOIN_PROB = 39;
const int LANE_PROB = 15;

int main() {
    srand(time(0));
    deque<deque<Car>> lanes;

    //Populating each lane with 2 cars
    for (int i = 0; i < LANES_SIZE; i++) {
        deque<Car> car;
        for (int i = 0; i < INIT_SIZE; i++) {
            Car newCar;
            car.push_back(newCar);
        }
        lanes.push_back(car);
    }
    cout << endl;

    //Printing initial queue
    cout << "Initial queue:" << endl;
    int lanecount = 1;
    for (auto it : lanes) {
        cout << "Lane " << lanecount++ << endl;
        for (auto it2 : it) {
            it2.print();
        }
    }

    lanecount = 1;
    for (int i = 0; i < 20; i++) {
        for (auto cars : lanes) {
            int chances = rand() % 100 + 1;
            cout << "Time: " << i + 1 << endl;

            if (chances <= LEAVE_PROB) { //Pays toll and leaves
                cout << "Lane: " << lanecount << " Car paid: ";
                cars[0].print();
                cars.pop_front();
            } else if (chances <= LEAVE_PROB + JOIN_PROB) { //New car joins
                cout << "Lane: " << lanecount << " Joined lane: ";
                Car newcar;
                cars.push_back(newcar);
                newcar.print();
            } else { //Rear car shifts lanes
                cars.pop_back();
            }
        
            lanecount++;
        }
        
        //Queue printing
        lanecount = 1;
        for (auto cars : lanes) {
            cout << "Lane " << lanecount++ << " Queue:" << endl;
            for (int i = 0; i < cars.size(); i++) {
                cout << "    ";
                cars[i].print();
            }
            cout << endl;
        }
    }
}