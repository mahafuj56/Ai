#include <iostream>
using namespace std;

void Toh(int n, char src, char aux, char dest) {
    if (n == 0) return; // base case
    Toh(n-1, src, dest, aux);               // move n-1 disks to auxiliary peg
    cout << "Move disk " << n << " from " << src << " to " << dest << endl;
    Toh(n-1, aux, src, dest);               // move n-1 disks to destination peg
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    Toh(n, 'A', 'B', 'C');                  // source=A, auxiliary=B, destination=C
    return 0;
}
