#include <cmath>
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <bitset>
#include <memory.h>
#include <functional>
#include <queue>
#include <fstream>
#include <ctime>
#include <deque>
#include <utility>
#include <stack>
#include <sstream>
#include <list>
#include <cctype>
#include <numeric>
#include <iomanip>
#include <assert.h>
#include <climits>

using namespace std;

typedef long long ll;

ll dp[2][1001][1001];
int p[2][1001][1001];

int main()
{
    ios::sync_with_stdio(false);
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    int n;
    cin >> n;
    vector< vector<ll> > a(n,vector<ll>(n));
    vector< vector<ll> > two(n,vector<ll>(n));
    vector< vector<ll> > five(n,vector<ll>(n));
    int i=0;
    bool flag=false;
    int x=-1,y=-1;
    while(i<n){
        int j=0;
        while(j<n){
            cin >> a[i][j];
            if(a[i][j]==0){
                flag=true;
                a[i][j]=10LL;
                x=i;y=j;
            }
            while(a[i][j]%2==0){
                two[i][j]++;
                a[i][j]/=2;
            }
            while(a[i][j]%5==0){
                five[i][j]++;
                a[i][j]/=5;
            }
            j++;
        }
        i++;
    }
    //1-R,2-D
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0){
                dp[0][i][j]=two[i][j];
                dp[1][i][j]=five[i][j];
                p[0][i][j]=p[1][i][j]=0;
            }
            else if(i==0){
                dp[0][i][j]=dp[0][i][j-1]+two[i][j];
                dp[1][i][j]=dp[1][i][j-1]+five[i][j];
                p[0][i][j]=p[1][i][j]=1;
            }
            else if(j==0){
                dp[0][i][j]=dp[0][i-1][j]+two[i][j];
                dp[1][i][j]=dp[1][i-1][j]+five[i][j];
                p[0][i][j]=p[1][i][j]=2;
            }
            else{
                dp[0][i][j]=min(dp[0][i-1][j],dp[0][i][j-1])+two[i][j];
                dp[1][i][j]=min(dp[1][i-1][j],dp[1][i][j-1])+five[i][j];

                if(dp[0][i-1][j]<dp[0][i][j-1])
                    p[0][i][j]=1;
                else
                    p[0][i][j]=2;

                if(dp[1][i-1][j]<dp[1][i][j-1])
                    p[1][i][j]=1;
                else
                    p[1][i][j]=2;
            }
        }
    }
    string s="";
    if(flag && dp[0][n-1][n-1]>1 && dp[1][n-1][n-1]>1){
        cout << 1 << endl;
        for(int i = 0; i < y; i ++){
			cout << "R";
		}

		for(int i = 0; i < n - 1; i ++){
			cout << "D";
		}
		for(int i = y; i < n - 1; i ++){
			cout << "R";
		}

		cout << "\n";
        return 0;
    }
    int z;
    if(dp[0][n-1][n-1]<dp[1][n-1][n-1]){
        cout << dp[0][n-1][n-1] << endl;
        z=0;
    }
    else{
        cout << dp[1][n-1][n-1] << endl;
        z=1;
    }
    x=n-1,y=n-1;
    while(x!=0 && y!=0){
        if(dp[z][x-1][y] < dp[z][x][y-1]){
            s+="D";
            x--;
        }
        else{
            s+="R";
            y--;
        }
        //cout << x << " " << y << endl;
    }
    while(x!=0){
        s+="D";
        x--;
    }
    while(y!=0){
        s+="R";
        y--;
    }
    reverse(s.begin(),s.end());
    cout << s << endl;
}
