#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>

using namespace std;

// This prints all elements of an array
void OutputArray(int array[], int size) {  // creates a function that accepts the aray and the size of the array
    for (int i = 0; i < size; i++) {  // creates a for loop that runs while i is less than the size of the array
        cout << array[i] << ", ";  // outputs the index and a coma and space
    }
    cout << "\n\n\n\n\n\n\n\n";  // added this to visually seperate the arrays
}


// This recursively calls BinarySearch and iterates through elements of the list by subtracting one from the highest index in the array.
// If the index of the array has a value that is the same as the value we are searching for than it outputs element found and exits the function
// If the value is not in the array it will search all elements, output Not found, and exit the function

int binarySearch(int arr[], int low, int high, int searchedValue) {  // calls a function that accepts the array, the low variable, high variable and the SearchedValue
    
    if (high >= low) {  // this will recursively loop as long as the high variable is greater than the low variable
        int root = low + (high - low) / 2; // finds a variable in the center of the array, using this equation prevents buffer overflow
        if (arr[root] == searchedValue) {  // if the index we are checking is the searchedValue...
            cout << "Element Found  \n\n\n\n\n";  // outputs the element is found in the array
            return 0; // this ends the function
        } else if (arr[root] > searchedValue) {  // if the index we are check is greater than the searchedValue...
            return binarySearch(arr, low, root - 1, searchedValue);  // recursively calls the function, if the value is greater we will subtract one from the high variable
        } else {
            return binarySearch(arr, root + 1, high, searchedValue); // recursively calls the function, if the value is smaller we will add one to the low variable
        }
    } else {
        cout << "Not Found \n\n\n\n\n"; // outputs the searchedValue is not contained in the array
        return 0; // this ends the function
    }
}

int main() {  //main

    int array[1000] = {}; //empty list
    srand(time(NULL)); // seed the random number generator

    for (int i = 1; i < 1001; i++) {  // for loop that runs while i is less than 1,001
        int randomNumber = rand() % 1500;  // this genrates a random number under 1,500
        array[i - 1] = randomNumber;  //  utilizes the for loop  and i to select the index of the randomNumber array and enter the random number into the array at that index
    }

    int searchedValue = rand() % 1500;  // this genrates a random number under 1,500
    int arraySize = sizeof(array) / sizeof(array[0]);  // Finding the size of the array
    sort(array, array + arraySize);

    cout << "Searching for " << searchedValue << "\n\n"; // ouputs a line of text that tells you the value the search is preforming
    cout << "Original array: \n";  // ouputs a line of text
    OutputArray(array, arraySize - 1); // outputs the original array
    binarySearch(array, 0, arraySize - 1, searchedValue);  // calls the search function
    exit(0); // exits the program

}

