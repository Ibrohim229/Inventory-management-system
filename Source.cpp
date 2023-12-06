#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

struct Item {
    std::string name;
    int quantity;
    float price;
};

class Inventory {
private:
    using UnorderedMap = std::unordered_map<int, Item>;
    UnorderedMap items;
    int nextID;

public:
    Inventory() : nextID(1) {}

    void addItem(std::string name, int quantity, float price) {
        items[nextID++] = { name, quantity, price };
        cout << "Item added successfully.\n";
    }

    void removeItem(int id) {
        auto it = items.find(id);
        if (it != items.end()) {
            items.erase(it);
            cout << "Item removed successfully.\n";
        }
        else {
            cout << "Item not found.\n";
        }
    }

    void displayInventory() {
        if (items.empty()) {
            cout << "Inventory is empty.\n";
        }
        else {
            cout << "Inventory:\n";
            for (const auto& pair : items) {
                cout << "ID: " << pair.first << ", Name: " << pair.second.name
                    << ", Quantity: " << pair.second.quantity
                    << ", Price: " << pair.second.price << "\n";
            }
        }
    }

    void updateQuantity(int id, int newQuantity) {
        auto it = items.find(id);
        if (it != items.end()) {
            it->second.quantity = newQuantity;
            cout << "Quantity updated successfully.\n";
        }
        else {
            cout << "Item not found.\n";
        }
    }
};

int main() {
    Inventory inventory;
    int choice;
    do {
        cout << "\nInventory Management System\n";
        cout << "1. Add Item\n";
        cout << "2. Remove Item\n";
        cout << "3. Display Inventory\n";
        cout << "4. Update Quantity\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            string name;
            int quantity;
            float price;
            cout << "Enter item name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter quantity: ";
            cin >> quantity;
            cout << "Enter price: ";
            cin >> price;
            inventory.addItem(name, quantity, price);
            break;
        }
        case 2: {
            int id;
            cout << "Enter item ID to remove: ";
            cin >> id;
            inventory.removeItem(id);
            break;
        }
        case 3:
            inventory.displayInventory();
            break;
        case 4: {
            int id, newQuantity;
            cout << "Enter item ID to update quantity: ";
            cin >> id;
            cout << "Enter new quantity: ";
            cin >> newQuantity;
            inventory.updateQuantity(id, newQuantity);
            break;
        }
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 0);
    return 0;
}

