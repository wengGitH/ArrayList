#include <iostream>
#include "arraylist.h"
using namespace std;

int main() {
    ArrayList* list = new ArrayList();

    list->add(5);
    list->add(10);
    list->add(15);
    list->addAt(21, 4); // starts at 1
    list->addAt(21, 5);
    list->addAt(21, 6);
    list->remove(21);
    list->add(20);
    list->remove(21);
    list->removeAt(0); // starts at 0
    list->addAt(28, 1);
    list->print();

    return 0;
}