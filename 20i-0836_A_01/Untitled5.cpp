#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1005; // Define a maximum value for the number of locations

int n;
vector<vector<int>> cost(3, vector<int>(MAXN));

// Function to compute minimum cost
int GetMinCost(int start, int end) {
    vector<vector<int>> dp(3, vector<int>(MAXN, INT_MAX));

    // Initialize the dp array
    for (int i = 1; i <= n; i++) {
        for (int j = start; j <= end; j++) {
            dp[j][i] = cost[j][i] + min(dp[j][i - 1], dp[(j + 1) % 3][i - 1] + 5);
        }
    }

    // Calculate the minimum cost from all layers
    int minCost = INT_MAX;
    for (int layer = 0; layer < 3; layer++) {
        minCost = min(minCost, dp[layer][end]);
    }

    return minCost;
}

int main() {
    cin >> n;

    // Read the costs for different modes of transportation
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    int start = 0, end = 3; // Change these values as needed

    int minCost = GetMinCost(start, end);
    cout << "Minimum Cost: " << minCost << endl;

    return 0;
}

