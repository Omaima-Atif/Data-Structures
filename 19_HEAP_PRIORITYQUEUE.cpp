#include <iostream>
using namespace std;

// Function to insert an element into the priority queue
void insertheap(int array[], int &size, int value) {
    size = size + 1;
    array[size - 1] = value;
    int i = size - 1;
    // Adjust the heap structure to maintain the heap property
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

// Function to extract the maximum priority element from the priority queue
int extractMax(int array[], int &size) {
    if (size < 1) {
        throw runtime_error("Heap underflow"); // Throw error if the heap is empty
    }
    int maxElement = array[0];
    array[0] = array[size - 1];
    size = size - 1;
    // Reconstruct the heap to maintain the heap property after extraction
    maxHeapify(array, size, 1);
    return maxElement;
}

// Function to adjust the heap structure to maintain the heap property
void maxHeapify(int array[], int size, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= size && array[left - 1] > array[largest - 1]) {
        largest = left;
    }
    if (right <= size && array[right - 1] > array[largest - 1]) {
        largest = right;
    }
    if (largest != i) {
        int temp = array[largest - 1];
        array[largest - 1] = array[i - 1];
        array[i - 1] = temp;
        maxHeapify(array, size, largest);
    }
}

// Function to view the maximum priority element without removing it
int peek(int array[], int size) {
    if (size < 1) {
        throw runtime_error("Heap is empty"); // Throw error if the heap is empty
    }
    return array[0];
}

int main() {
    int size;
    cout << "Enter size of priority queue: " << endl;
    cin >> size;
    int array[size];
    int value;
    // Insert elements into the priority queue
    for (int i = 0; i < size; i++) {
        cout << "Enter value to be inserted: " << endl;
        cin >> value;
        insertheap(array, i, value);
    }

    // View the maximum priority element without removing it
    cout << "Max priority element: " << peek(array, size) << endl;

    // Extract the maximum priority element from the priority queue
    cout << "Extracting max priority element: " << extractMax(array, size) << endl;

    // Display the updated priority queue after extraction
    cout << "Updated priority queue: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
