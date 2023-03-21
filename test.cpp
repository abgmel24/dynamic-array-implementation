#include "DynamicArrayTemplate.h"
int main(int argc, char **argv) {
    int size = 5;
    ArrayList<int> *list = new ArrayList<int>(5); 

    for(int i = 0; i < size; ++i) { //testing add()
        std::cout << "adding " << i << std::endl;
        list->add(i);
        std::cout << "accessing at index " << i << ": " << list->access(i) << std::endl;
    }
    std::cout << "Array: ";
    list->printArray();
    std::cout << "Array is full (T/F): " << list->isFull() << std::endl;

    for(int i = 0; i < 5; ++i) { //testing remove() and isEmtpy()
        std::cout << "removing " << list->remove(0) << " at index 0" << std::endl;
    }
    std::cout << "Array: ";
    list->printArray();
    std::cout << "Array is empty (T/F): " << list->isEmpty() << std::endl;
}