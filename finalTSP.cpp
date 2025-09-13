#include <iostream>
using namespace std;

int N = 4;

// Function to swap two elements
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

// Function to calculate cost of a path
int pathCost(int path[], int graph[4][4]){
    int cost = 0;
    for(int i=0; i<N; i++)
        cost += graph[path[i]][path[i+1]];
    return cost;
}

// Recursive function to generate all permutations
void permute(int arr[], int l, int r, int graph[4][4], int &min_cost, int best_path[]){
    if(l == r){
        int cost = pathCost(arr, graph);
        if(cost < min_cost){
            min_cost = cost;
            for(int i=0;i<=N;i++) best_path[i] = arr[i];
        }
        return;
    }
    for(int i=l;i<=r;i++){
        swap(arr[l], arr[i]);
        permute(arr, l+1, r, graph, min_cost, best_path);
        swap(arr[l], arr[i]); // backtrack
    }
}

int main(){
    int graph[4][4] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int cities[5] = {0,1,2,3,0}; // last 0 to return start
    int min_cost = 999999;
    int best_path[5];

    permute(cities, 1, N-1, graph, min_cost, best_path);

    cout << "Adjacency Matrix (Graph):\n";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) cout << graph[i][j] << " ";
        cout << endl;
    }

    cout << "\nNumber of cities: " << N << endl;
    cout << "\nOptimal Path: ";
    for(int i=0;i<=N;i++) cout << best_path[i]+1 << " ";
    cout << "\nMinimum Cost: " << min_cost << endl;

    return 0;
}
