#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector< vector<int> > a(n,vector<int>(m));
    int i=0;
    int j=0;
    while(i<n){
        j=0;
        while(j<m){
            cin >> a[i][j];
            j++;
        }
        i++;
    }
    vector< vector<int> > dp(n,vector<int>(m));
    for(int i=0;i<m;i++){
        dp[0][i]=a[0][i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(j==0){
                dp[i][j]=a[i][j]+min(dp[i-1][j],dp[i-1][j+1]);
            }
            else if(j==m-1){
                dp[i][j]=a[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
            }
            else{
                int x=min(dp[i-1][j],dp[i-1][j-1]);
                x=min(x,dp[i-1][j+1]);
                dp[i][j]=a[i][j]+x;
            }
        }
    }
    int mn=INT_MAX;
    for(int i=0;i<m;i++){
        if(dp[n-1][i]<mn){
            mn=dp[n-1][i];
        }
    }
    cout << mn << endl;
}
