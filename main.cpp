#include <iostream>
#include "arraylist.h"
using namespace std;

int main() {
    int size;
    cout << "Enter a value: ";
    cin >> size;
    
    List* list = new ArrayList();

    list->add(10);
    list->add(20);
    list->add(30);
    list->remove(5);
    list->add(40);
    list->add(50);
    list->add(60);
    list->print();
    int value = list->get(0);
    cout << value << endl;

    return 0;
}