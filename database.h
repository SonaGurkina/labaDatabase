#ifndef DATABASE_H
#define DATABASE_H

#include "product.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Database {
private:
    int capacity;
    int count;
    string filename;
	Product* products;
    static int nextID;

    void resize();

public:
    Database(string file);
    ~Database();

    void load();
    void save();
    void add(const Product& p);
    void display() const;
    void erase(int id);
    void edit(int id);
    void search(string article, string name) const;
};

#endif
