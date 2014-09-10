#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
using namespace std;

long long gold(map<long long,long long> &dp,long long n){
    if(n<0){
        return 0;
    }
    if(n==0){
        return n;
    }
    if(dp.find(n)!=dp.end()){
        return dp[n];
    }
    dp[n]=max(gold(dp,n/2)+gold(dp,n/3)+gold(dp,n/4),n);
    return dp[n];
}

int main(){
    long long n;

    //while(scanf("%d",&n)!=EOF){
    while(cin>>n){
        //vector<long long> dp(n+1,0);
        map<long long,long long> dp;
        /*dp[0]=0;
        for(long long i=1;i<=n;i++){
            dp[i]=max(dp[i/2]+dp[i/3]+dp[i/4],i);
        }
        cout << dp[n] << endl;*/
        long long x=gold(dp,n);
        cout << x << endl;
    }
}
