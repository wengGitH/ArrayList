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
            length = INITIAL_CAPACITY;
        }

        ArrayList(int size) {
            array = new int[size];
            index = 0;
            length = size;
        }

        void add(int num) {
            if(index == length) {
                cout << "Array is full, cannot add more elements." << endl;
                return;
            }
            array[index++] = num;
        }

        void removeAt(int pos) {
            if(pos < 0 || pos >= index) {
                cout << "Index out of bounds." << endl;
                return;
            }
            
            for (int i = pos + 1; i < index; i++) {
                array[i - 1] = array[i];
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

        void addAt(int num, int pos) {
            if(pos < 1 || pos > index+1 || index == length) return;

            for(int i=index-1; i >= pos-1; i--) {
                array[i+1] = array[i];
            }

            array[pos-1] = num;
            index++;
        };

        int remove(int num) {
            int pos = -1;

            for(int i=0; i<index; i++) {
                if(array[i] == num) {
                    pos = i;
                    break;
                }
            }

            if(pos == -1) return pos;

            for(int i=pos; i<index-1; i++) {
                array[i] = array[i + 1];
            }
            index--;

            return pos + 1;
        };

        void print() {
            for (int i = 0; i < index; i++) {
                cout << array[i] << " ";
            }
            cout << endl;
        };
};