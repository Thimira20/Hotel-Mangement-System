#pragma once

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Node {
public:
    int phone_no;
    string name;
    double distance;
    int cost;

    Node();
    Node( string n, double dis, int p, int c);
};

class Darray {
public:
    int size;
    int capacity;
    int top;
    Node* data;

    Darray();
   // Darray(int cap);
   

    void insertarr( string n, double dis, int p, int c);
    void distanceSort();
    void budgetSort();
    void print();
    void Storge();
    void adddata();

private:
   
    void swapNodes(Node& a, Node& b);
    void selectionSort(Node data[], int size, bool sortByDistance);
};



