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

int main()
{
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    int m=0;
    while(m<n){
        cin >> a[m];
        m++;
    }
    if(n==2*k){
        cout << 1 << " " << k+1 << endl;
        return 0;
    }
    vector<ll> s(n);
    s[0]=a[0];
    for(int i=1;i<s.size();i++){
        s[i]=s[i-1]+a[i];
    }
    vector<ll> dp(n-k+1);
    int j=k-1;
    int b=0;
    for(int i=0;i<dp.size();i++){
        if(i==0){
            dp[i]=s[j];
            j++;
        }
        else{
            dp[i]=s[j]-s[b];
            b++;j++;
        }
    }
    int mi=-1;
    ll mx=-1;

    for(int i=0;i<dp.size();i++){
        if(dp[i]>mx){
            mx=dp[i];
            mi=i;
        }
    }
    //cout << mx << " " << mi << endl;
    int mi1=mi;
    mx=-1;
    mi=-1;
    int t1=mi1-(k-1);
    int t2=mi1+(k-1);
    //cout << t1 << " " << t2 << endl;
    for(int i=0;i<dp.size();i++){
        if(i>=t1 && i<=t2)
            continue;
        else{
            if(dp[i]>mx){
                mx=dp[i];
                mi=i;
            }
        }
    }
    int q=max(mi1+1,mi+1);
    int w=min(mi1+1,mi+1);
    //cout << mx << " " << mi << endl;
    cout << w << " " << q << endl;
}
