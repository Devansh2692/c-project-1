#include <iostream>
#include <string>
using namespace std;

const int MAX_VEHICLES = 100; // Maximum capacity

class VehicleRegistry {
private:
    Vehicle* vehicles[MAX_VEHICLES]; // Array of pointers to Vehicle
    int count;

public:
    VehicleRegistry() : count(0) {}

    ~VehicleRegistry() {
        for (int i = 0; i < count; ++i) {
            delete vehicles[i]; // Clean up dynamically allocated vehicles
        }
    }

    bool addVehicle(Vehicle* v) {
        if (count < MAX_VEHICLES) {
            vehicles[count++] = v;
            return true;
        }
        return false;
    }

    void displayAllVehicles() const {
        if (count == 0) {
            cout << "No vehicles registered.\n";
            return;
        }

        for (int i = 0; i < count; ++i) {
            cout << "----- Vehicle " << (i + 1) << " -----\n";
            vehicles[i]->displayInfo();
            cout << endl;
        }
    }

    Vehicle* searchByID(const string& id) const {
        for (int i = 0; i < count; ++i) {
            if (vehicles[i]->getVehicleID() == id) {
                return vehicles[i];
            }
        }
        return nullptr;
    }
};
