#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>
#include <simplecpp>

using namespace std;

mutex mtx; // Mutex for synchronizing access to shared variables

// Enum for elevator direction
enum class Direction {
    UP,
    DOWN,
    IDLE
};

// Class for representing an elevator
class Elevator {
private:
    int currentFloor;
    int maxCapacity;
    Direction direction;
    bool emergencyMode;
    vector<bool> floorRequests;

public:
    Elevator(int numFloors, int capacity) : currentFloor(0), maxCapacity(capacity), direction(Direction::IDLE), emergencyMode(false) {
        floorRequests.resize(numFloors, false);
    }

    // Request elevator to go to a specific floor
    void requestFloor(int floor) {
        floorRequests[floor] = true;
        if (direction == Direction::IDLE) {
            if (floor > currentFloor)
                direction = Direction::UP;
            else if (floor < currentFloor)
                direction = Direction::DOWN;
            else
                direction = Direction::IDLE; // Same floor, stay idle
        }
    }

    // Move elevator to the next floor based on current direction
    void move() {
        if (emergencyMode) {
            cout << "Elevator is in emergency mode. Stopping at nearest floor." << endl;
            return;
        }

        if (direction == Direction::UP) {
            if (currentFloor < floorRequests.size() - 1) {
                currentFloor++;
            } else {
                direction = Direction::DOWN; // Change direction at the top floor
                currentFloor--;
            }
        } else if (direction == Direction::DOWN) {
            if (currentFloor > 0) {
                currentFloor--;
            } else {
                cout << "Elevator has reached the ground floor. Stopping." << endl;
                direction = Direction::IDLE; // Stop at ground floor
            }
        }

        cout << "Elevator is now at floor " << currentFloor << endl;
        // Check if the current floor has a pending request
        if (floorRequests[currentFloor]) {
            cout << "Opening doors at floor " << currentFloor << endl;
            std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate door opening time
            cout << "Closing doors at floor " << currentFloor << endl;
            floorRequests[currentFloor] = false; // Clear the request for this floor
            // Check if there are any remaining requests in the current direction
            if (direction == Direction::UP && all_of(floorRequests.begin() + currentFloor + 1, floorRequests.end(), [](bool req) { return !req; })) {
                direction = Direction::DOWN; // Change direction if no more requests going up
            } else if (direction == Direction::DOWN && all_of(floorRequests.begin(), floorRequests.begin() + currentFloor, [](bool req) { return !req; })) {
                direction = Direction::UP; // Change direction if no more requests going down
            }
        }
    }

    // Activate emergency mode
    void activateEmergency() {
        emergencyMode = true;
    }

    // Deactivate emergency mode
    void deactivateEmergency() {
        emergencyMode = false;
    }

    // Get the current floor of the elevator
    int getCurrentFloor() const {
        return currentFloor;
    }
};

// Function to draw elevator and current floor
void drawElevator(int currentFloor) {
    int windowHeight = 500;
    int windowWidth = 500;
    initCanvas("Elevator Simulation", windowWidth, windowHeight);

    int elevatorX = 50;
    int elevatorY = 50 + (windowHeight / 10) * (9 - currentFloor);

    Rectangle elevator(elevatorX, elevatorY, 50, 50);
    elevator.setFill(true);
    elevator.setColor(COLOR("blue"));
    elevator.imprint();

    int floorY = 50;
    for (int i = 0; i < 10; ++i) {
        Text floorText(25, floorY, to_string(i));
        floorY += windowHeight / 10;
    }

    Text currentFloorText(75, 450, "Current Floor: " + to_string(currentFloor));
    currentFloorText.imprint();

    wait(2);
    closeCanvas();
}

// Function to simulate elevator movement
void moveElevator(int &currentFloor) {
    while (true) {
        // Simulate elevator movement
        this_thread::sleep_for(chrono::seconds(2));

        // Update elevator position
        mtx.lock(); // Lock mutex before updating shared variable
        currentFloor = (currentFloor + 1) % 10; // Move up to next floor (loops from 9 to 0)
        mtx.unlock(); // Unlock mutex after updating shared variable

        // Redraw elevator with updated position
        drawElevator(currentFloor);
    }
}

// Function to get valid floor input (0 to 9)
int getValidFloor() {
    int floor;
    while (true) {
        cin >> floor;
        if (cin.fail() || floor < 0 || floor > 9) {
            // Clear input buffer to prevent infinite loop
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid floor number. Please enter a number between 0 and 9." << endl;
        } else {
            return floor;
        }
    }
}

int main() {
    const int numFloors = 10; // Number of floors in the building
    const int capacity = 10; // Maximum capacity of the elevator

    Elevator elevator(numFloors, capacity);

    cout << "Welcome to the Elevator Simulator!" << endl;
    cout << "Press Enter to request the elevator." << endl;
    cout << "Type 'exit' to quit." << endl;

    thread graphicsThread(moveElevator, std::ref(elevator.getCurrentFloor())); // Start graphics thread

    string input;
    while (true) {
        getline(cin, input);
        if (input == "exit") {
            break;
        } else if (input.empty()) {
            mtx.lock(); // Lock mutex before accessing shared variable
            int requestedFloor;
            cout << "Enter the floor you want to go to (0 to 9): ";
            cin >> requestedFloor;
            mtx.unlock(); // Unlock mutex after accessing shared variable

            // Validate floor input
            if (requestedFloor < 0 || requestedFloor > 9) {
                cout << "Invalid floor number. Please enter a number between 0 and 9." << endl;
                continue;
            }

            // Request elevator to the specified floor
            elevator.requestFloor(requestedFloor);
        } else {
            cout << "Invalid command. Please try again." << endl;
        }
    }

    graphicsThread.join(); // Wait for graphics thread to finish

    return 0;
}
