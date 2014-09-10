#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

int led[10][7] =
        {
          //a b c d e f g
          { 0,0,0,0,0,0,1 },  // = 0
          { 1,0,0,1,1,1,1 },  // = 1
          { 0,0,1,0,0,1,0 },  // = 2
          { 0,0,0,0,1,1,0 },  // = 3
          { 1,0,0,1,1,0,0 },  // = 4
          { 0,1,0,0,1,0,0 },  // = 5
          { 0,1,0,0,0,0,0 },  // = 6
          { 0,0,0,1,1,1,1 },  // = 7
          { 0,0,0,0,0,0,0 },  // = 8
          { 0,0,0,1,1,0,0 }   // = 9
        };

int main()
{
    ios::sync_with_stdio(false);
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	int t;
    cin >> t;
    while(t){
       int n;
       cin >> n;
       vector< vector<int> > a;
       int m=0;
       while(m<n){
            string s;
            cin >> s;
            for(int i=0;i<7;i++){
                a[m].push_back(s[i]-'0');
            }
            cout << "m";
            m++;
       }
       vector< vector<int> > b;
       for(int i=0;i<n;i++){
            for(int j=0;j<10;i++){
                bool incl=true;
                for(int k=0;k<7;k++){
                    if(a[i][k]==1 && led[j][k]!=a[i][k]){
                        incl=false;
                    }
                }
                if(incl)
                    b[i].push_back(j);
            }
            cout << "hf";
       }
       for(int i=0;i<n;i++){
            for(int j=0;j<b[i].size();j++){
                cout << b[i][j] << " ";
            }
            cout << endl;
       }
       t--;
    }
}
