#include <iostream>
using namespace std;

const int INF = 1e9;
int N;                    // Number of cities
int dist[20][20];         // Distance matrix
int dp[1<<20][20];        // DP table

int tsp(int mask, int pos){
    if(mask == (1<<N)-1) return dist[pos][0];     // all cities visited
    if(dp[mask][pos] != -1) return dp[mask][pos];

    int ans = INF;
    for(int city=0; city<N; city++){
        if(!(mask & (1<<city))){ // if not visited
            int newCost = dist[pos][city] + tsp(mask|(1<<city), city);
            if(newCost < ans) ans = newCost;
        }
    }
    return dp[mask][pos] = ans;
}

int main(){
    cout<<"Enter number of cities: ";
    cin>>N;

    cout<<"Enter distance matrix:\n";
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin>>dist[i][j];

    for(int i=0;i<(1<<N);i++)
        for(int j=0;j<N;j++)
            dp[i][j] = -1;

    cout<<"Minimum TSP cost: "<<tsp(1,0)<<endl;
}
