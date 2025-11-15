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

    //Printing initial queue
    cout << "Initial queue:" << endl;
    int lanecount = 1;
    for (auto it : lanes) {
        cout << "Lane " << lanecount++ << endl;
        for (auto it2 : it) {
            it2.print();
        }
    }
    cout << endl;

    for (int i = 0; i < 20; i++) {
        cout << "Time: " << i + 1 << endl;
        lanecount = 1;
        for (int currentlane = 0; currentlane < lanes.size(); currentlane++) {
            int chances = rand() % 100 + 1;
            bool join = false;
            if (lanes[currentlane].empty()) { //If lane is empty
                if (chances <= 50 ) //50/50 on join
                    join = true;
            }

            if (chances <= LEAVE_PROB && !lanes[currentlane].empty()) { //Pays toll and leaves
                cout << "Lane: " << lanecount << " Paid: ";
                lanes[currentlane][0].print();
                lanes[currentlane].pop_front();
            } else if (chances <= (LEAVE_PROB + JOIN_PROB) || join == true) { //New car joins
                cout << "Lane: " << lanecount << " Joined lane: ";
                Car newcar;
                lanes[currentlane].push_back(newcar);
                newcar.print();
            } else if (!lanes[currentlane].empty()) { //Rear car shifts lanes
                cout << "Lane: " << lanecount << " Switched: ";
                Car lastcar = lanes[currentlane].back();
                lastcar.print();

                int randomLane = lanecount; //Makes sure its not the same lane switched to
                while (randomLane == lanecount) {
                    randomLane = rand() % 4 + 1;
                }

                //Switches lane
                lanes[randomLane - 1].push_back(lastcar);
                lanes[currentlane].pop_back();
            }
        
            lanecount++;
        }
        
        //Queue printing
        lanecount = 1;
        for (auto cars : lanes) {
            cout << "Lane " << lanecount++ << " Queue:" << endl;
            if (cars.empty()) {
                cout << "    Empty" << endl;
            }
            for (int i = 0; i < cars.size(); i++) {
                cout << "    ";
                cars[i].print();
            }
            cout << endl;
        }
    }
}