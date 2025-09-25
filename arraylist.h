#include <iostream>
#include "list.h"
#include<cmath>
#define INITIAL_CAPACITY 5
#define GROWTH_FACTOR 1.5
using namespace std;

class ArrayList : public List {
    int* array;
    int index;
    int length;
    int capacity = INITIAL_CAPACITY;

    void dynamic_expand()
    {
        int new_size = ceil(capacity * GROWTH_FACTOR);
        int* new_array = (int*) realloc(array, new_size * sizeof(int));
        if(new_array)
        {
            array = new_array;
            capacity = new_size;
        }
    }

    void dynamic_shrink()
    {
        int new_size = ceil(capacity * 0.75);
        int* new_array = (int*) realloc(array, new_size * sizeof(int));
        if(new_array)
        {
            array = new_array;
            capacity = new_size;
        }
    }
    public:
        ArrayList() {
            array = (int*) malloc(INITIAL_CAPACITY * sizeof(int));
            index = 0;
            length = INITIAL_CAPACITY;
        }

        ~ArrayList()
        {
            free(array);
        }

        ArrayList(int size) {
            array = new int[size];
            index = 0;
            length = size;
        }

        void add(int num) 
        {
            if(index == capacity) 
            {
                dynamic_expand();
            }
            array[index++] = num;
            // if(index == length) 
            // {
            //     cout << "Array is full, cannot add more elements." << endl;
            //     return;
            // }
            // array[index++] = num;
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
            
            removeAt(pos);
            if(index <= 2.0/3.0 * capacity)
            {
                dynamic_shrink();
            }
            // for(int i=pos; i<index-1; i++) {
            //     array[i] = array[i + 1];
            // }
            // index--;

            return pos + 1;
        };

        void print() 
        {
            cout<<"Current Capacity: "<<index<<" / "<<capacity<<endl;

            for(int i = 0; i < index; i++)
            {
                cout<<array[i]<<" ";
            }

            for (int i = index; i < capacity; i++) 
            {
                cout <<"? ";
            }
            cout << endl;
        };
};