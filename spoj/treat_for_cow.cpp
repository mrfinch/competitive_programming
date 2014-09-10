#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int treats(vector<int> a,int i,int j,vector< vector<int> >& dp,int inc){
    //cout << i << " " << j << endl;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(j==i){
        dp[i][i]=inc*a[i];
        //cout << "fd " << inc*a[i] << endl;
        return dp[i][i];
    }
    if(i>a.size()-1 || j<0 || j>a.size()-1 || i<0){
        return 0;
    }
    dp[i][j] = max((inc*a[i])+treats(a,i+1,j,dp,inc+1),treats(a,i,j-1,dp,inc+1)+(inc*a[j]));
    //cout << i << " " << a[j] << " dh " << j << endl;
    //cout << dp[i][j] << endl;
    return dp[i][j];
    //return 0;
}

int main(){
    int n;
    cin >> n;
    vector< vector<int> > dp(n,vector<int>(n,-1));
    vector<int> a(n,0);
    int m=0;
    while(m<n){
        scanf("%d",&a[m]);
        m++;
    }
    int res = treats(a,0,n-1,dp,1);
    printf("%d\n",res);
}
