#include <iostream>
using namespace std;

const int N = 4;

// Function to find minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Recursive TSP function
int tsp(int mask, int pos, int dist[N][N], int dp[16][N]) {
    if (mask == (1 << N) - 1) return dist[pos][0]; // All cities visited, return to start
    if (dp[mask][pos] != -1) return dp[mask][pos];

    int ans = 1000000; // Infinity
    for (int city = 0; city < N; city++) {
        if (!(mask & (1 << city))) { // If city is not visited
            ans = min(ans, dist[pos][city] + tsp(mask | (1 << city), city, dist, dp));
        }
    }
    dp[mask][pos] = ans;
    return ans;
}

int main() {
    int dist[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int dp[16][N]; // 2^N x N
    for (int i = 0; i < 16; i++)
        for (int j = 0; j < N; j++)
            dp[i][j] = -1;

    cout << "Minimum TSP cost: " << tsp(1, 0, dist, dp) << endl;
    return 0;
}
