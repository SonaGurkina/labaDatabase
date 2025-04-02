#include "product.h"

Product::Product() : id(0), name(""), article(""), color("") {}

Product::Product(int id, string name, string article, string color)
    : id(id), name(name), article(article), color(color) {}

ostream& operator<<(ostream& out, const Product& p) {
    out << "ID: " << p.id << ", name: " << p.name << ", article: " << p.article << ", color: " << p.color;
    return out;
}

istream& operator>>(istream& in, Product& p) {
    cout << "Enter name: ";
    getline(in >> ws, p.name);
    cout << "Enter article: ";
    getline(in >> ws, p.article);
    cout << "Enter color: ";
    getline(in >> ws, p.color);
    return in;
}

string Product::toString() const {
    stringstream ss;
    ss << id << "," << name << "," << article << "," << color;
    return ss.str();
}

void Product::fromString(const string& str) {
    stringstream ss(str);
    string temp;
    getline(ss, temp, ',');
    id = stoi(temp);
    getline(ss, name, ',');
    getline(ss, article, ',');
    getline(ss, color, ',');
}
