#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <utility>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n,0);
    int m=0;
    vector<long long> dp(100005,0);
    vector<long long> f(100005,0);
    int mx=-1;
    while(m<n){
        scanf("%d",&a[m]);
        f[a[m]]++;
        if(a[m]>mx){
            mx=a[m];
        }
        m++;
    }
    dp[1]=f[1];
    //dp[2]=max(dp[1],f[2]*2);
    for(int i=2;i<=mx;i++){
        dp[i]=max(f[i]*i+dp[i-2],dp[i-1]);
    }
    cout << dp[mx] << endl;
}
