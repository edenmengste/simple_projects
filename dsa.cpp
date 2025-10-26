#include <iostream>
#include <algorithm>

using namespace std;

void simple_sort(int list[], int n);

void linear_search(int list[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(list[i] == key) {
            cout << "Key found at index: " << i << endl;
            return;
        }
    }
    cout << "Key not found\n\n";
}

void simple_sort(int list[], int n) {
    for(int i = 0; i <= n - 2; i++) {
        for(int j = i + 1; j <= n - 1; j++) {
            if(list[i] > list[j]) {
                int temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
    cout << "Sorted array using Simple Sort: ";
    for (int i = 0; i < n; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

void binary_search(int list[], int n, int key) {

    int sorted_list[50];
    copy(list, list + n, sorted_list);
    simple_sort(sorted_list, n);

    int left = 0, right = n - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        
        if(sorted_list[mid] == key) {
            cout << "Key found at index: " << mid << endl;
            return;
        } else if(sorted_list[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << "Key not found\n\n";
}

void BubbleSort(int list[], int n) { 
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++){
            if (list[j] > list[j+1]) {
            temp = list[j];
            list[j] = list[j+1];
            list[j+1] = temp;
            }
        }
    }
    cout << "Sorted array using Bubble Sort: ";
    for (int i = 0; i < n; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

void selectionSort(int list[], int n) {
    int minIndex, temp, j;
    for (int i = 0; i <= n - 2; i++) {
        minIndex = i;
        for (j = i + 1; j <= n - 1; j++) {
            if (list[j] < list[minIndex])
                minIndex = j;
        }
        if (minIndex != i) {
            temp = list[i];
            list[i] = list[minIndex];
            list[minIndex] = temp;
        }
    }
    cout << "Sorted array using Selection Sort: ";
    for (int i = 0; i < n; i++){
        cout << list[i] << " ";
    }
    cout << endl;
}

void InsertionSort(int list[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (list[j - 1] > list[j]) {
                int temp = list[j];
                list[j] = list[j - 1];
                list[j - 1] = temp;
            } else {
                break;
            }
        }
    }

    cout << "Sorted array using Insertion Sort: ";
    for (int i = 0; i < n; i++){
        cout << list[i] << " ";
    }
    cout << endl;
}



int main() {
    int main_choice, search_choice, sorting_choice;
    int searchArray[50], search_array_size = 0;
    int sortArray[50], sort_array_size = 0;
    bool searchEntered = false, sortEntered = false;

    do {
        cout << "\n   Main Menu \n";
        cout << "1. Searching algorithm\n";
        cout << "2. Sorting algorithm\n";
        cout << "0. Exit\n";
        cout << "Enter a choice: ";
        cin >> main_choice;

        switch(main_choice) {
            case 1: {
                do {
                    cout <<endl<< "Searching Algorithms\n";
                    cout << "1. Linear Search\n";
                    cout << "2. Binary Search\n";
                    cout << "0. Back to main menu\n";
                    cout << "Enter your choice: ";
                    cin >> search_choice;

                    if(search_choice == 0) break;

                    if(!searchEntered){
                        cout << "Enter number of elements for searching array: ";
                        cin >> search_array_size;
                        if (search_array_size > 50 || search_array_size <= 0) {
                            cout << "Invalid size. Returning to search menu.\n";
                            continue;
                        }
                        cout << "Enter elements: ";
                        for(int i = 0; i < search_array_size; i++) {
                            cin >> searchArray[i];
                        }
                        searchEntered = true;
                    }

                    int key;
                    cout << "Enter key to search: ";
                    cin >> key;

                    switch(search_choice){
                        case 1:
                            linear_search(searchArray, search_array_size, key); 
                            break;
                        case 2:
                            binary_search(searchArray, search_array_size, key);
                            break;
                        default:
                            cout<< "Invalid choice, please try again\n";
                    }

                } while(search_choice != 0);
                break;
            }

            case 2: {
                do {
                    cout <<endl<<"Sorting Algorithms\n";
                    cout << "1. Simple Sort\n";
                    cout << "2. Bubble Sorting\n";
                    cout << "3. Selection Sorting\n";
                    cout << "4. Insertion Sorting\n";
                    cout << "0. Back to main menu\n";
                    cout << "Enter your choice: ";
                    cin >> sorting_choice;

                    if(sorting_choice == 0) break;

                    if(!sortEntered){
                        cout << "Enter number of elements for sorting array: ";
                        cin >> sort_array_size;
                         if (sort_array_size > 50 || sort_array_size <= 0) {
                            cout << "Invalid size. Returning to sort menu.\n";
                            continue;
                        }
                        cout << "Enter elements: ";
                        for(int i = 0; i < sort_array_size; i++)
                            cin >> sortArray[i];
                        sortEntered = true;
                    }

                    int current_array[50];
                    copy(sortArray, sortArray + sort_array_size, current_array);

                    switch(sorting_choice){
                        case 1:
                            simple_sort(current_array, sort_array_size);
                            break;
                        case 2:
                            BubbleSort(current_array, sort_array_size);
                            break;
                        case 3:
                            selectionSort(current_array, sort_array_size);
                            break;
                        case 4:
                            InsertionSort(current_array, sort_array_size);
                            break;
                        default:
                            cout << "Invalid choice, please try again\n";
                    }

                } while(sorting_choice != 0);

                sortEntered = false; 
                break;
            }

            case 0:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid choice. Try again\n";
        }

    } while(main_choice != 0);

    return 0;
}