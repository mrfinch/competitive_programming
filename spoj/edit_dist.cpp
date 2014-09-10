#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t){
        string s1,s2;
        cin >> s1;
        cin >> s2;
        vector< vector<int> > dp(s1.size()+1,vector<int>(s2.size()+1));
        for(int i=0;i<=s1.size();i++){
            dp[i][0]=i;
        }
        for(int j=0;j<=s2.size();j++){
            dp[0][j]=j;
        }
        for(int i=1;i<=s1.size();i++){
            for(int j=1;j<=s2.size();j++){
                int x = dp[i][j-1]+1;
                int y = dp[i-1][j]+1;
                int z = (s1[i-1]==s2[j-1])?dp[i-1][j-1]:1+dp[i-1][j-1];
                dp[i][j] = min(x,y);
                dp[i][j] = min(dp[i][j],z);
            }
        }
        cout << dp[s1.size()][s2.size()] << endl;
        t--;
    }
}
