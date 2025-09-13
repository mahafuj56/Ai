1  #include <iostream>
2  using namespace std;
3
4  char b[9] = {'1','2','3','4','5','6','7','8','9'};
5
6  void show() {
7      for (int i=0; i<9; i+=3) {
8          cout<<" "<<b[i]<<" | "<<b[i+1]<<" | "<<b[i+2]<<"\n";
9          if (i<6) cout<<"---+---+---\n";
10     }
11 }
12
13 bool win() {
14     int w[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
15     for (int i=0;i<8;i++)
16         if (b[w[i][0]]==b[w[i][1]] && b[w[i][1]]==b[w[i][2]])
17             return true;
18     return false;
19 }
20
21 bool draw() {
22     for (int i=0;i<9;i++)
23         if (b[i]!='X' && b[i]!='O') return false;
24     return true;
25 }
26
27 int main() {
28     int p=1,m; char mark;
29     while (true) {
30         show();
31         mark = (p==1)?'X':'O';
32         cout<<"Player "<<p<<" ("<<mark<<") choose (1-9): ";
33         cin>>m;
34
35         if (m<1 || m>9 || b[m-1]=='X' || b[m-1]=='O') {
36             cout<<"Invalid!\n"; continue;
37         }
38
39         b[m-1]=mark;
40         if (win()) { show(); cout<<"Player "<<p<<" wins!\n"; break; }
41         if (draw()){ show(); cout<<"Draw!\n"; break; }
42         p = 3-p;
43     }
44     return 0;
45 }
