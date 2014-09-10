#include <iostream>
#include <vector>

using namespace std;

int main(){
    while(true){
        int b,n;
        cin >> b >> n;
        if(b==0 && n==0){
            break;
        }
        else{
            vector<int> fee(n+1);
            vector<int> fun(n+1);
            int m=1;
            while(m<=n){
                cin >> fee[m] >> fun[m];
                m++;
            }
            vector< vector<int> > dp(b+1,vector<int>(n+1,0));
            for(int i=0;i<=b;i++){
                for(int j=0;j<=n;j++){
                    if(i==0||j==0){
                        dp[i][j]=0;
                    }
                    else{
                        if(fee[j]>i){
                            dp[i][j]=dp[i][j-1];
                        }
                        else{
                            dp[i][j]=max(fun[j]+dp[i-fee[j]][j-1],dp[i][j-1]);
                        }
                    }
                }
            }
            //cout << dp[b][n] << endl;
            int x=b;
            for(int i=b;i>0;i--){
                if(dp[i][n]==dp[i-1][n]){
                    x=i-1;
                }
                else{
                    break;
                }
            }
            cout << x << " " << dp[b][n] << endl;
        }
    }
}
