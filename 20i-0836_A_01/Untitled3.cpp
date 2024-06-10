#include <iostream>

int main() {
    int numRows = 3;
    int numCols = 8;
    
    int arr[numRows][numCols] = {
        {1, 2, 3, 4, 6, 7, 8, 0},
        {1, 2, 3, 4, 5, 6, 7, 8},
        {1, 2, 3, 5, 6, 7, 8,0}
    };
    
    for (int row = 0; row < numRows; row++) {
        int col = 1;
        while (col < numCols) {
            if (arr[row][col] != 0 && arr[row][col] != arr[row][col - 1] + 1) {
                // Shift numbers to the right
                for (int shiftCol = numCols - 2; shiftCol >= col; shiftCol--) {
                    arr[row][shiftCol + 1] = arr[row][shiftCol];
                }
                arr[row][col] = 0;
                col++;
            }
            col++;
        }
    }
    
    // Print the modified array
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            std::cout << arr[row][col] << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}

