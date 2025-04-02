#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Product {
private:
    int id;
    string name;
    string article;
    string color;

public:
    Product();
    Product(int id, string name, string article, string color);

    int getId() const { return id; }
    string getName() const { return name; }
    string getArticle() const { return article; }
    string getColor() const { return color; }

    void setName(string newName) { name = newName; }
    void setArticle(string newArticle) { article = newArticle; }
    void setColor(string newColor) { color = newColor; }

    friend ostream& operator<<(ostream& out, const Product& p);
    friend istream& operator>>(istream& in, Product& p);

    string toString() const;
    void fromString(const string& str);
};

#endif
