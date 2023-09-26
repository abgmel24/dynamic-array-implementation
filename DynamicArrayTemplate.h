//Used this to learn template files and what their syntax looks like
#ifndef DYNARRAY_H
#define DYNARRAY_H
#include <iostream>
#include <exception>

template <class T>
class ArrayList {
    public:
        ArrayList() {}
        ArrayList(int s) {
            maxSize = s;
            array = new T[s];
            numElements = 0;
        }

        ~ArrayList() {
            delete[] array;
        }

        void add(T item) {
            if(isFull()) {
                resize();
                add(item);
            }
            array[numElements++] = item;
        }

        T remove(int index) {
            if(isEmpty()) {
                throw std::runtime_error("cannot remove from empty dynamic array");
            }
            if(!isInRange(index)) {
                throw std::runtime_error("cannot access index out of bounds");
            }
            T temp = array[index];
            int i = index + 1;
            while(i < numElements) { //remove element and push elemnts
                array[i-1] = array[i];
                i++;
            }
            numElements--;
            return temp;
        }

        T access(int index) {
            if(!isInRange(index)) {
                throw std::runtime_error("cannot access index out of bounds");
            }
            return array[index];
        }

        int getSize() {
            return numElements;
        }

        bool isFull() {
            return numElements == maxSize;
        }
        bool isEmpty() {
            return numElements == 0;
        }

        void printArray() {
            for(int i = 0; i < numElements; ++i) {
                std::cout << array[i] << " ";
            }
            std::cout << std::endl;
        }

    private:
        T *array;
        int numElements;
        int maxSize;

        void resize() {
            T *arr = new T[numElements * 2];
            for(int i = 0; i < numElements; ++i) {
                array[i] = arr[i];
            }
            array = arr;
            delete[] arr;
            maxSize *= 2;
            std::cout << "resizing array" << std::endl;
        }
        bool isInRange(int index) {
            return (index >= 0) && (index <= maxSize);
        }
};
#endif