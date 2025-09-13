#include <iostream>
using namespace std;

int N = 4;

// Swap
void swap(int &a,int &b){int t=a;a=b;b=t;}

// Calculate path cost
int cost(int path[], int g[4][4]){
    int c=0;
    for(int i=0;i<N;i++) c+=g[path[i]][path[i+1]];
    return c;
}

// Recursive permutation
void perm(int p[], int l, int r, int g[4][4], int &minc, int best[]){
    if(l==r){
        int c=cost(p,g);
        if(c<minc){minc=c; for(int i=0;i<=N;i++) best[i]=p[i];}
        return;
    }
    for(int i=l;i<=r;i++){
        swap(p[l],p[i]);
        perm(p,l+1,r,g,minc,best);
        swap(p[l],p[i]);
    }
}

int main(){
    int g[4][4]={{0,10,15,20},{10,0,35,25},{15,35,0,30},{20,25,30,0}};
    int p[5]={0,1,2,3,0},best[5],minc=999999;
    perm(p,1,N-1,g,minc,best);

    cout<<"Graph:\n";
    for(int i=0;i<N;i++){for(int j=0;j<N;j++) cout<<g[i][j]<<" "; cout<<endl;}
    cout<<"\nOptimal Path: ";
    for(int i=0;i<=N;i++) cout<<best[i]+1<<" ";
    cout<<"\nMinimum Cost: "<<minc<<endl;
}
