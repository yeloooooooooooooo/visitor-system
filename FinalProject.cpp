#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a Visitor
struct Visitor {
    int CodeNumber;
    string relation;
    string name;
    int age;
    string role;
};

// Display all Visitors
void displayVisitor(const vector<Visitor>& visitors) {
    if (visitors.empty()) {
        cout << "There are no visitors in the list.\n\n";
    } else {
        cout << "\nVisitor List:\n";
        for (const auto& visitor : visitors) {
            cout << "Code: " << visitor.CodeNumber 
                 << ", Name: " << visitor.name 
                 << ", Relation: " << visitor.relation 
                 << ", Age: " << visitor.age 
                 << ", Role: " << visitor.role << "\n";
        }
        cout << endl;
    }
}

// Add a new Visitor
void addVisitor(vector<Visitor>& visitors) {
    Visitor newVisitor;
    cout << "Enter Visitor Code: ";
    cin >> newVisitor.CodeNumber;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
    cout << "Enter Visitor Name: ";
    getline(cin, newVisitor.name);
    cout << "Enter Visitor Relation: ";
    getline(cin, newVisitor.relation);
    cout << "Enter Visitor Age: ";
    cin >> newVisitor.age;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
    cout << "Enter Visitor Role: ";
    getline(cin, newVisitor.role);

    visitors.push_back(newVisitor);
    cout << "Visitor has been added successfully.\n\n";
}

// Update an existing Visitor
void updateVisitor(vector<Visitor>& visitors) {
    if (visitors.empty()) {
        cout << "No visitors to update.\n\n";
        return;
    }

    int CodeNumber;
    cout << "Enter Visitor Code to update: ";
    cin >> CodeNumber;

    for (auto& visitor : visitors) {
        if (visitor.CodeNumber == CodeNumber) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            cout << "Enter new name (current: " << visitor.name << "): ";
            getline(cin, visitor.name);
            cout << "Enter new relation (current: " << visitor.relation << "): ";
            getline(cin, visitor.relation);
            cout << "Enter new age (current: " << visitor.age << "): ";
            cin >> visitor.age;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            cout << "Enter new role (current: " << visitor.role << "): ";
            getline(cin, visitor.role);

            cout << "Visitor record updated successfully.\n\n";
            return;
        }
    }
    cout << "Visitor with Code " << CodeNumber << " not found.\n\n";
}

// Delete a Visitor
void deleteVisitor(vector<Visitor>& visitors) {
    if (visitors.empty()) {
        cout << "No visitors to delete.\n\n";
        return;
    }

    int CodeNumber;
    cout << "Enter Visitor Code to delete: ";
    cin >> CodeNumber;

    for (auto it = visitors.begin(); it != visitors.end(); ++it) {
        if (it->CodeNumber == CodeNumber) {
            cout << "Visitor " << it->name << " with Code " << CodeNumber << " has been removed.\n\n";
            visitors.erase(it);
            return;
        }
    }
    cout << "Visitor with Code " << CodeNumber << " not found.\n\n";
}

// Main Function
int main() {
    vector<Visitor> visitors;
    int choice;

    while (true) {
        cout << "List of Visitors\n";
        cout << "1. View all visitors\n";
        cout << "2. Add a new visitor\n";
        cout << "3. Update a visitor record\n";
        cout << "4. Remove a visitor record\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayVisitor(visitors);
                break;
            case 2:
                addVisitor(visitors);
                break;
            case 3:
                updateVisitor(visitors);
                break;
            case 4:
                deleteVisitor(visitors);
                break;
            case 5:
                cout << "Exiting the program. Bye-Byeee!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n\n";
        }
    }
}
