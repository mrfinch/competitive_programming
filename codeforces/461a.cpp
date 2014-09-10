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
    ll n;
    cin >> n;
    vector<int> a(n);
    int i=0;
    while(i<n){
        cin>>a[i];
        i++;
    }
    sort(a.rbegin(),a.rend());
    vector<ll> dp(n);
    dp[0]=a[0];
    for(int i=1;i<dp.size();i++){
        dp[i]=a[i]+dp[i-1];
    }
    ll c=0;
    int j=a.size()-1;
    for(int i=dp.size()-1;i>=0;i--){
        if(i==dp.size()-1){
            c+=dp[i];
        }
        else{
            c+=(dp[i]+a[j]);
            j--;
        }
    }
    cout << c << endl;
}
