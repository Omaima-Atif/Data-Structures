#include <iostream>
using namespace std;

void maxInsert (int *arr, int i) {
    if (i == 0) {
		return;
	}
	else {
		int parent = (i-1)/2;
		
		if (arr[parent] < arr[i]) {
			int temp = arr[parent];
			arr[parent] = arr[i];
			
			
			arr[i] = temp;
			maxInsert (arr, parent);
		}
		else {
			return;
		}
	}
}

void minInsert (int *arr, int i) {
    if (i == 0) {
		return;
	}
	else {
		int parent = (i-1)/2;
		
		if (arr[parent] > arr[i]) {
			int temp = arr[parent];
			arr[parent] = arr[i];
			
			
			arr[i] = temp;
			minInsert (arr, parent);
		}
		else {
			return;
		}
	}
}

void search (int arr[], int num,int size) {
    int flag = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            cout << "Value found." << endl;
            flag = 1;
            return;
        }
    }

    if (flag == 0) {
        cout << "Value not found." << endl;
        return;
    }
}

void print (int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr [i] << " ";
    }
    cout << endl;
}

int main () {
    int size, val, ans;
    cout << "Enter size of array: " << endl;
    cin >> size;
    int arr[size];

	for (int i = 0; i < size; i++) {
		arr[i] = -1;
	}

    cout << "Max Heap? 1. Min Heap? 2. " << endl;
    cin >> ans;

    if (ans == 1) {
        while (ans != 0){
        cout << "Insert? 1. Search? 2. Print? 3. Delete? 4." << endl;
        cin >> ans;
        switch (ans) {
            case 1:
                for (int i = 0; i < size; i++) {
		            cout << "Enter value you want to enter in max heap: " << endl;
		            cin >> val;
		            if (arr[i] == -1) {
			            arr[i] = val;
			            maxInsert (arr, i);
		            }
	            }
                break;
            
            case 2:
                cout << "Enter value you want to search: " << endl;
		        cin >> val;
                search (arr, val, size);
                break;

            case 3:
                print (arr, size);
                break;

            case 4:
                cout << "Enter value you want to delete: " << endl;
		        cin >> val;
        }
        }
    }
    else if (ans == 2) {
        while (ans != 0){
        cout << "Insert? 1. Search? 2. Print? 3. Delete? 4." << endl;
        cin >> ans;
        switch (ans) {
            case 1:
                for (int i = 0; i < size; i++) {
		            cout << "Enter value you want to enter in min heap: " << endl;
		            cin >> val;
		            if (arr[i] == -1) {
			            arr[i] = val;
			            minInsert (arr, i);
		            }
	            }
                break;
            
            case 2:
                cout << "Enter value you want to search: " << endl;
		        cin >> val;
                search (arr, val, size);
                break;

            case 3:
                print (arr, size);
                break;

            case 4:
                cout << "Enter value you want to delete: " << endl;
		        cin >> val;
        }
        }
    }
}