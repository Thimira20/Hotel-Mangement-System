#include "Hash.h"
#include <iostream>

using namespace std;

// Implementation of NodeH constructor
NodeH::NodeH(string n, double d, int pn, int c, string pl, string sea, string bar) {
    name = n;
    distance = d;
    phone_no = pn;
    cpd = c;
    pool = pl;
    beach = sea;
    BAR = bar;
    next = nullptr;
    prev = nullptr;

}

// Implementation of hashtable constructor
hashtable::hashtable() : table(new NodeH* [size] {nullptr}) {}

// Implementation of hashtable destructor
/*hashtable::~hashtable() {
    for (int i = 0; i < size; ++i) {
        NodeH* current = table[i];
        while (current != nullptr) {
            NodeH* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] table;
}*/

// Implementation of getHash function
int hashtable::getHash(int phone_no) {
    return phone_no % size;
}

// Implementation of insert function
void hashtable::insert(string str, double dis, int pn, int c, string pl, string sea, string bar) {
    int index = getHash(pn);

    NodeH* newNode = new NodeH(str, dis, pn, c, pl, sea, bar);

    if (table[index] == nullptr) {
        // No collision, insert the new node directly
        table[index] = newNode;
    }
    else {
        // Collision occurred, add the new node to the linked list
        NodeH* current = table[index];
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Implementation of search function
NodeH* hashtable::search(int pn) {
    int index = getHash(pn);
    NodeH* current = table[index];

    while (current != nullptr) {
        if (current->phone_no == pn) {
            return current; // Found the node with the given key
        }
        current = current->next;
    }

    return nullptr; // Key not found
}

// Implementation of print function
void hashtable::print() {
    for (int i = 0; i < size; i++) {
        NodeH* current = table[i];
        while (current != nullptr) {
            cout << current->cpd << "LKR ";
            cout << current->distance << "km ";
            cout << current->phone_no << " ";
            cout << current->name << endl;

            current = current->next;
        }
    }
    cout << endl;
}

// Implementation of Item_search function
void hashtable::Item_search(int phone_no) {
    NodeH* x = search(phone_no);
    if (x != nullptr) {
        cout << "Name: " << x->name << endl;
        cout << "Phone No: " << x->phone_no << endl;
        cout << "Distance: " << x->distance << "km" << endl;
        cout << "Cost per day: " << x->cpd << "LKR" << endl;
        cout << "Pool: " << x->pool << endl;
        cout << "Beach: " << x->beach << endl;
        cout << "BAR: " << x->BAR << endl;
    }
    else {
        cout << "Not found" << endl;
    }
}

void hashtable::Storage() {
    hashtable::insert("John", 10.5, 123456, 100, "Available", "Not Available", "Available");

    hashtable::insert("Jane", 15.3, 789012, 200, "Not Available", "Not Available", "Available");
    hashtable::insert("Bob", 8.7, 345678, 300, "Available", "Not Available", "Not Available");
    hashtable::insert("thimira", 5.99, 45468, 9333, "Available", "Not Available", "Available");


    }
////////////////////////////////////////////////////////////////////////////////

#include"Array.h"


using namespace std;

Node::Node() {
    phone_no = 1;
    name = "  ";
    distance = -1;
    cost = 0;
};

Node::Node(string n, double dis, int p, int c) {
    name = n;
    distance = dis;
    phone_no = p;
    cost = c;
};
/*
Darray::Darray() {
    size = 0;
    capacity = 0;
    top = 0;
    data = NULL;
}
*/

Darray::Darray() {
    size = 0;
    capacity = 10;
    top = 0;
    data = new Node[capacity];
}



void Darray::insertarr( string n, double dis, int p, int c) {
    if (size == capacity) {
        Node* temp = new Node[capacity + 10];
        for (int i = 0; i < size; i++) {
            /*temp[i].phone_no = data[i].phone_no;
            temp[i].name = data[i].name;
            temp[i].cost = data[i].cost;
            temp[i].distance = data[i].distance;
            */
            temp[i] = data[i];
        }

        delete[] data;
        data = temp;
        capacity += 10;
        
    }

    Node* newNode = new Node(n, dis, p, c);
    data[top++] = *newNode;
    //top++;
    size++;
}

void Darray::swapNodes(Node& a, Node& b) {
    Node temp = a;
    a = b;
    b = temp;
}

void Darray::selectionSort(Node data[], int size, bool sortByDistance) {
    for (int i = 0; i < size; i++) {
        int min_index = i;
        for (int j = size - 1; j > i; j--) {
            if ((sortByDistance && data[min_index].distance > data[j].distance)
                || (!sortByDistance && data[min_index].cost > data[j].cost)) {
                swapNodes(data[min_index], data[j]);
            }
        }
    }
}

void Darray::distanceSort() {
    selectionSort(data, size, true);
}

void Darray::budgetSort() {
    selectionSort(data, size, false);
}

void Darray::print() {
    for (int i = 0; i < size; i++) {
        cout << data[i].phone_no << " ";
        cout << data[i].cost << "LKR ";
        cout << data[i].distance << "km" << " ";
        cout << data[i].name << endl;
    }
    cout << endl;
}

void Darray::Storge() {
     Darray::insertarr("John", 10.5, 123456, 100);
     Darray::insertarr("Jane", 15.3, 789012, 200);
     Darray::insertarr("Bob", 8.7, 345678, 300);
     Darray::insertarr("thimira", 5.99, 45468, 9333);
}


void Darray::adddata() {
    string name, sea, bar, pl;
    double dis;
    int pn, c;

    hashtable h_item;
    

    cout << "name   : ";
    cin >> name;
    cout << "\ndistance   : ";
    cin >> dis;
    cout << "\nPhone No.   : ";
    cin >> pn;
    cout << "\nCost per day   : ";
    cin >> c;
    cout << "\nBeach   : ";
    cin >> sea;
    cout << "\nBAR   : ";
    cin >> bar;
    cout << "\nPool   : ";
    cin >> pl;

    // Assuming insert function in hashtable takes parameters in order (string, double, int, int, string, string, string)
    h_item.insert(name, dis, pn, c, pl, sea, bar);

    // Assuming insertarr function in Darray takes parameters in order (string, double, int, int)
    Darray::insertarr(name, dis, pn, c);
};





























































/**
class NodeH {
public:
    string name;
    double distance;
    int phone_no;
    int cpd;
    string pool;
    string beach;
    string BAR;
    NodeH* next;
    NodeH* prev;

    /*NodeH(string n, double d, int pn, int c, string pl, string sea, string bar)
        : name(n), distance(d), phone_no(pn), cpd(c), pool(pl), beach(sea), BAR(bar), next(nullptr), prev(nullptr) {}*/
/*
    NodeH(string n, double d, int pn, int c, string pl, string sea, string bar) {
        name = n;
        distance = d;
        phone_no = pn;
        cpd = c;
        pool = pl;
        beach = sea;
        BAR = bar;
        next = nullptr;
        prev = nullptr;

    }
};

class hashtable {
public:
    static const int size = 10;
    NodeH** table;

    hashtable() : table(new NodeH* [size] {nullptr}) {}

    int getHash(int phone_no) {
        return phone_no % size;
    }

    void insert(string str, double dis, int pn, int c, string pl, string sea, string bar) {
        int index = getHash(pn);

        NodeH* newNode = new NodeH(str, dis, pn, c, pl, sea, bar);

        if (table[index] == nullptr) {
            // No collision, insert the new node directly
            table[index] = newNode;
        }
        else {
            // Collision occurred, add the new node to the linked list
            NodeH* current = table[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
    }

    NodeH* search(int pn) {
        int index = getHash(pn);
        NodeH* current = table[index];

        while (current != nullptr) {
            if (current->phone_no == pn) {
                return current; // Found the node with the given key
            }
            current = current->next;
        }

        return nullptr; // Key not found
    }

    void print() {
        for (int i = 0; i < size; i++) {
            NodeH* current = table[i];
            while (current != nullptr) {
                cout << current->cpd << "LKR ";
                cout << current->distance << "km ";
                cout << current->phone_no << " ";
                cout << current->name << endl;

                current = current->next;
            }
        }
        cout << endl;
    }

    void Item_search(int phone_no) {
        NodeH* x = search(phone_no);
        if (x != nullptr) {
            cout << "Name: " << x->name << endl;
            cout << "Phone No: " << x->phone_no << endl;
            cout << "Distance: " << x->distance << "km" << endl;
            cout << "Cost per day: " << x->cpd << "LKR" << endl;
            cout << "Pool: " << x->pool << endl;
            cout << "Beach: " << x->beach << endl;
            cout << "BAR: " << x->BAR << endl;
        }
        else {
            cout << "Not found" << endl;
        }
    }
};*/