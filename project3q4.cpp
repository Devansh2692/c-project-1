#include <iostream>
#include <limits> // for input clearing
using namespace std;

// Make sure all class definitions (Vehicle, Car, ElectricCar, etc., and VehicleRegistry) are already included above

void showMenu() {
    cout << "\n======= Vehicle Registry Menu =======\n";
    cout << "1. Add Vehicle\n";
    cout << "2. View All Vehicles\n";
    cout << "3. Search Vehicle by ID\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    VehicleRegistry registry;
    int choice;

    do {
        showMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // flush input

        switch (choice) {
            case 1: {
                int type;
                cout << "\nSelect Vehicle Type:\n";
                cout << "1. Sedan\n";
                cout << "2. SUV\n";
                cout << "3. Electric Car\n";
                cout << "4. Sports Car\n";
                cout << "5. Flying Car\n";
                cout << "Enter type: ";
                cin >> type;
                cin.ignore();

                string id, manu, model, fuel;
                int year, battery, speed, range;

                cout << "Enter Vehicle ID: ";
                getline(cin, id);
                cout << "Enter Manufacturer: ";
                getline(cin, manu);
                cout << "Enter Model: ";
                getline(cin, model);
                cout << "Enter Year: ";
                cin >> year;
                cin.ignore();

                switch (type) {
                    case 1: // Sedan
                        cout << "Enter Fuel Type: ";
                        getline(cin, fuel);
                        registry.addVehicle(new Sedan(id, manu, model, year, fuel));
                        cout << "Sedan added successfully.\n";
                        break;

                    case 2: // SUV
                        cout << "Enter Fuel Type: ";
                        getline(cin, fuel);
                        registry.addVehicle(new SUV(id, manu, model, year, fuel));
                        cout << "SUV added successfully.\n";
                        break;

                    case 3: // Electric Car
                        cout << "Enter Fuel Type: ";
                        getline(cin, fuel);
                        cout << "Enter Battery Capacity (kWh): ";
                        cin >> battery;
                        cin.ignore();
                        registry.addVehicle(new ElectricCar(id, manu, model, year, fuel, battery));
                        cout << "Electric Car added successfully.\n";
                        break;

                    case 4: // Sports Car
                        cout << "Enter Fuel Type: ";
                        getline(cin, fuel);
                        cout << "Enter Battery Capacity (kWh): ";
                        cin >> battery;
                        cout << "Enter Top Speed (km/h): ";
                        cin >> speed;
                        cin.ignore();
                        registry.addVehicle(new SportsCar(id, manu, model, year, fuel, battery, speed));
                        cout << "Sports Car added successfully.\n";
                        break;

                    case 5: // Flying Car
                        cout << "Enter Fuel Type: ";
                        getline(cin, fuel);
                        cout << "Enter Flight Range (km): ";
                        cin >> range;
                        cin.ignore();
                        registry.addVehicle(new FlyingCar(id, manu, model, year, fuel, range));
                        cout << "Flying Car added successfully.\n";
                        break;

                    default:
                        cout << "Invalid vehicle type.\n";
                        break;
                }
                break;
            }

            case 2:
                registry.displayAllVehicles();
                break;

            case 3: {
                string id;
                cout << "Enter Vehicle ID to search: ";
                getline(cin, id);
                Vehicle* found = registry.searchByID(id);
                if (found) {
                    cout << "\nVehicle found:\n";
                    found->displayInfo();
                } else {
                    cout << "Vehicle with ID '" << id << "' not found.\n";
                }
                break;
            }

            case 4:
                cout << "Exiting the program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

    } while (choice != 4);

    return 0;
}
