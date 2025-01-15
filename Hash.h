#pragma once
#include <string>
using namespace std;

class NodeH {
public:
    std::string name;
    double distance;
    int phone_no;
    int cpd;
    std::string pool;
    std::string beach;
    std::string BAR;
    NodeH* next;
    NodeH* prev;

    NodeH(string n, double d, int pn, int c, string pl, string sea, string bar);
};

class hashtable {
public:
    static const int size = 10;
    NodeH** table;

    hashtable();
    //~hashtable(); // Destructor to free memory

    int getHash(int phone_no);

    void insert(string str, double dis, int pn, int c, string pl, string sea, string bar);

    NodeH* search(int pn);

    void print();

    void Item_search(int phone_no);

    void Storage();
};

