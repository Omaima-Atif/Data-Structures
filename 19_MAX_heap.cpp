#include <iostream>
using namespace std;

void insertheap(int array[], int size, int value) {
    size = size + 1;
    array[size - 1] = value;
    int i = size - 1;
    while (i > 1) {
        int parent = i / 2;
        if (array[parent - 1] < array[i - 1]) {
            int temp = array[parent - 1];
            array[parent - 1] = array[i - 1];
            array[i - 1] = temp;
            i = parent;
        } else {
            return;
        }
    }
}


void maxHeapify(int array[], int size, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= size && array[left - 1] > array[largest - 1]) { // Corrected indexing
        largest = left;
    }
    if (right <= size && array[right - 1] > array[largest - 1]) { // Corrected indexing
        largest = right;
    }
    if (largest != i) {
        int temp = array[largest - 1]; // Corrected indexing
        array[largest - 1] = array[i - 1]; // Corrected indexing
        array[i - 1] = temp; // Corrected indexing
        maxHeapify(array, size, largest);
    }
}

void heapsort(int array[], int size) {
    for (int i = size / 2; i > 0; i--) { 
        maxHeapify(array, size, i);
    }

    for (int i = size; i > 1; i--) { 
        int temp = array[0]; 
        array[0] = array[i - 1]; 
        array[i - 1] = temp; 
        maxHeapify(array, i - 1, 1);
    }
}

int main() {
    int size;
    cout << "Enter size of array: " << endl;
    cin >> size;
    int array[size];
    int value;
    for (int i = 0; i < size; i++) { 
        cout << "ENTER VALUE TO BE INSERTED: " << endl;
        cin >> value;
        insertheap(array, i, value); 
    }
    heapsort(array, size);
    for(int i=0;i<size;i++){
        cout<< array[i]<<" ";
    }
    return 0;
}
