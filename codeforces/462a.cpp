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

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector< vector<char> > a(n,vector<char>(n));
    int i=0;
    while(i<n){
        int j=0;
        while(j<n){
            cin >> a[i][j];
            j++;
        }
        i++;
    }
    bool y=true;
    if(n==1){
        cout << "YES" << endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            int x;
            if(i==0&&j==0){
                x=(a[i][j+1]=='o'?1:0)+(a[i+1][j]=='o'?1:0);
            }
            else if(i==n-1&&j==n-1){
                x=(a[i][j-1]=='o'?1:0)+(a[i-1][j]=='o'?1:0);
            }
            else if(i==n-1&&j==0){
                x=(a[i-1][j]=='o'?1:0)+(a[i][j+1]=='o'?1:0);
            }
            else if(i==0&&j==n-1){
                x=(a[i+1][j]=='o'?1:0)+(a[i][j-1]=='o'?1:0);
            }
            else if(i==0){
                x=(a[i][j-1]=='o'?1:0)+(a[i][j+1]=='o'?1:0)+(a[i+1][j]=='o'?1:0);
            }
            else if(j==0){
                x=(a[i][j+1]=='o'?1:0)+(a[i-1][j]=='o'?1:0)+(a[i+1][j]=='o'?1:0);
            }
            else if(i==n-1){
                x=(a[i][j-1]=='o'?1:0)+(a[i][j+1]=='o'?1:0)+(a[i-1][j]=='o'?1:0);
            }
            else if(j==n-1){
                x=(a[i][j-1]=='o'?1:0)+(a[i-1][j]=='o'?1:0)+(a[i+1][j]=='o'?1:0);
            }
            else{
                x=(a[i][j-1]=='o'?1:0)+(a[i][j+1]=='o'?1:0)+(a[i-1][j]=='o'?1:0)+(a[i+1][j]=='o'?1:0);
            }
            if(x%2!=0){
                //cout << i << " " << j << x <<endl;
                y=false;
                break;
            }
        }
        if(y==false)
            break;
    }
    if(y==true){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
