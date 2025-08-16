#include <iostream>
#include "list.h"
#define INITIAL_CAPACITY 5
using namespace std;

class ArrayList : public List {
    int* array;
    int index;
    int length;

    public:
        ArrayList() {
            array = new int[INITIAL_CAPACITY];
            index = 0;
        }

        ArrayList(int size) {
            array = new int[size];
            index = 0;
            length = size;
        }

        void add(int num) {
            if(index == INITIAL_CAPACITY || index == length) {
                cout << "Array is full, cannot add more elements." << endl;
                return;
            }
            array[index++] = num;
        }

        void remove(int pos) {
            if(pos < 0 || pos >= index) {
                cout << "Index out of bounds." << endl;
                return;
            }
            
            for (int i = pos; i < index - 1; i++) {
                array[i] = array[i + 1];
            }
            index--;
        };

        int get(int pos) {
            if(pos < 0 || pos >= index) {
                cout << "Index out of bounds." << endl;
                return -1;
            }
            return array[pos];
        };

        void print() {
            for (int i = 0; i < index; i++) {
                cout << array[i] << " ";
            }
            cout << endl;
        };
};