#include <iostream>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t){
        int e,f;
        cin >> e >> f;
        int n;
        cin >> n;
        vector< pair<int,int> > inp(n);
        int m=0;
        while(m<n){
            cin >> inp[m].first;
            cin >> inp[m].second;
            m++;
        }
        vector<int> dp(f-e+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=f-e;i++){
            for(int j=0;j<inp.size();j++){
                if(inp[j].second>i){
                    continue;
                }
                else{
                    if(dp[i-inp[j].second]==INT_MAX){
                    	continue;
                    }
                    dp[i]=min(dp[i-inp[j].second]+inp[j].first,dp[i]);
                }
            }
        }
        if(dp[f-e]==INT_MAX){
            cout << "This is impossible." << endl;
        }
        else{
            cout << "The minimum amount of money in the piggy-bank is " << dp[f-e] << "." << endl;
        }
        t--;
    }
}
