#include "DynArray.h"
int main(int argc, char **argv) {
    int size = 5;
    ArrayList<int> *list = new ArrayList<int>(5); 

    for(int i = 0; i < size; ++i) {
        list->add(i);
    }
    list->printArray();

    for(int i = 0; i < 6; ++i) {
        list->remove(0);
    }
    list->printArray();
}