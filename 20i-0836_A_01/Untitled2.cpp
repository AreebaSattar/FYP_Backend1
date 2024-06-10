#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
const int numRows = 4; // Number of rows in the file
    const int numCols = 8;
void fillMissingWithZeros(int arr[numRows][numCols]) {
    for (int i = 0; i < numRows; i++) {
        int prevNum = arr[i][0]; // Initialize prevNum with the first number in the row
        for (int j = 1; j < numCols; j++) {
            if (arr[i][j] == 0) {
                break; // Stop when a 0 is encountered
            }
            if (arr[i][j] != prevNum + 1) {
                // Fill in the missing numbers with 0s
                for (int k = prevNum + 1; k < arr[i][j]; k++) {
                    arr[i][k] = 0;
                }
            }
            prevNum = arr[i][j];
        }
    }
}

int main() {
     // Maximum number of columns in the matrix
    int arr[3][numCols] = {0}; // Initialize the 2D array with 0s

    ifstream file("Q1T2.txt"); // Open the file for reading
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }
   
    // Loop through each line in the file
    for (int i = 0; i < numRows; i++) {
        string line;
       
        getline(file, line); // Read a line from the file
        istringstream iss(line);
         if(i==0)
        continue;
        int j = 0; // Column index

        // Parse each number and store it in the array
        while (j < numCols && iss >> arr[i-1][j]) {
            j++;
        }
    }

    file.close(); // Close the file
  //fillMissingWithZeros(arr);
    // Print the 2D array
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

