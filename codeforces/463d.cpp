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

vector<int> gv;
vector<int> gt;
vector< vector<int> > dp(1001,vector<int>(1001));
vector< vector<int> > a(1001,vector<int>(1001));
int func(vector<int> v){
    gt=gv;
    gv.erase(gv.begin(),gv.end());
    for(int i=0;i<v.size()+1;i++){
        for(int j=0;j<gt.size()+1;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(v[i-1]==gt[i-1]){
                dp[i][j]=1+dp[i-1][j-1];
                gv.push_back(v[i-1]);
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[v.size()][gt.size()];
}

int main()
{
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    cout << n << k;

    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            cout << i << " " << a[i][j] << " " << j << endl;
        }
    }
    cout << "ou";
    vector<int> v;
    vector<int> t;
    for(int i=0;i<n;i++){
        v.push_back(a[0][i]);
    }
    for(int j=0;j<n;j++){
        t.push_back(a[1][j]);
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
        cout << "rts";
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(v[i-1]==t[i-1]){
                dp[i][j]=1+dp[i-1][j-1];
                gv.push_back(v[i-1]);
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    int q=dp[n][n];
    for(int i=2;i<n;i++){
        q=func(a[i]);
    }
    cout << q << endl;
}
