#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t){
        string s;
        cin >> s;
        vector< vector<short> > dp(s.size(),vector<short>(s.size(),0));
        for(int i=1;i<s.size();i++){
            for(int j=0,k=i;k<s.size();k++,j++){
                dp[j][k]=(s[j]==s[k])?dp[j+1][k-1]:1+(min(dp[j+1][k],dp[j][k-1]));
            }
        }
        cout << dp[0][s.size()-1] << endl;
        t--;
    }
}
