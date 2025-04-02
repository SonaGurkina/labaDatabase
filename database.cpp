#include "database.h"

int Database::nextID = 1;

Database::Database(string file) : capacity(5), count(0), filename(file) {
    products = new Product[capacity];
    load();
}

Database::~Database() {
    save();
    delete[] products;
}

void Database::resize() {
    capacity *= 2;
    Product* newArr = new Product[capacity];
    for (int i = 0; i < count; i++)
        newArr[i] = products[i];
    delete[] products;
    products = newArr;
}

void Database::load() {
    ifstream file(filename);
    if (!file.is_open()) {
        count = 0;
        nextID = 1;
        return;
    }

    file >> count >> nextID;
    file.ignore();

    if (count > capacity) {
        capacity = count + 5;
        delete[] products;
        products = new Product[capacity];
    }

    string line;
    for (int i = 0; i < count; i++) {
        getline(file, line);
        products[i].fromString(line);
    }
    file.close();
}

void Database::save() {
    ofstream file(filename);
    if (!file.is_open()) return;

    file << count << "\n" << nextID << "\n";
    for (int i = 0; i < count; i++)
        file << products[i].toString() << "\n";
    file.close();
}

void Database::add(const Product& p) {
    if (count == capacity) resize();
    products[count++] = Product(nextID++, p.getName(), p.getArticle(), p.getColor());
    cout << "Product added.\n";
}

void Database::display() const {
    if (count == 0) {
        cout << "Database is empty.\n";
        return;
    }
    for (int i = 0; i < count; i++)
        cout << products[i] << "\n";
}

void Database::erase(int id) {
    for (int i = 0; i < count; i++) {
        if (products[i].getId() == id) {
            for (int j = i; j < count - 1; j++)
                products[j] = products[j + 1];
            count--;
            cout << "Product deleted.\n";
            return;
        }
    }
    cout << "Product not found.\n";
}

void Database::edit(int id) {
    for (int i = 0; i < count; i++) {
        if (products[i].getId() == id) {
            cout << "Current details:\n" << products[i] << "\n";
            Product temp;
            cin >> temp;
            products[i] = Product(id, temp.getName(), temp.getArticle(), temp.getColor());
            cout << "Product updated.\n";
            return;
        }
    }
    cout << "Product not found.\n";
}

void Database::search(string article, string name) const {
    bool found = false;
    for (int i = 0; i < count; i++) {
        if (products[i].getArticle() == article || products[i].getName() == name) {
            cout << products[i] << "\n";
            found = true;
        }
    }
    if (!found) cout << "Product not found.\n";
}
