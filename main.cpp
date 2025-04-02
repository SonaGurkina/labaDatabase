#include "database.h"

using namespace std;

void menu() {
    cout << "\nMenu:\n";
    cout << "1. Show all products\n";
    cout << "2. Add product\n";
    cout << "3. Delete product\n";
    cout << "4. Edit product\n";
    cout << "5. Search product\n";
    cout << "0. Exit\n";
}

int main() {
    Database db("database.txt");
    int choice, id;
    string name, article;

    do {
        menu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: db.display(); break;
            case 2: { Product p; cin >> p; db.add(p); } break;
            case 3: cout << "Enter ID: "; cin >> id; db.erase(id); break;
            case 4: cout << "Enter ID: "; cin >> id; db.edit(id); break;
            case 5: cout << "Enter article: "; cin >> article; db.search(article, ""); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
