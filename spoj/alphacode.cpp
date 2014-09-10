#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string s;
    while(cin >> s){
        if(s.size()==1 && s[0]=='0'){
            break;
        }
        vector<int> a(s.size());
        for(int i=0;i<s.size();i++){
            a[i]=s[i]-'0';
        }
        if(a[0]==0){
            cout << 0 << endl;
        }
        else if(a.size()==1){
            cout << 1 << endl;
        }
        else if(a[a.size()-1]==0 && a[a.size()-2]>2){
            cout << 0 << endl;
        }
        else{
            vector<int> dp(a.size(),0);
            if(a[a.size()-1]!=0){
                dp[a.size()-1]=1;
                }
            if(a.size()>=2){
                if(a[a.size()-2]==1 && a[a.size()-1]!=0){
                    dp[a.size()-2]=2;
                }
                else if(a[a.size()-2]==1 && a[a.size()-1]==0){
                    dp[a.size()-2]=1;
                }
                else if(a[a.size()-2]==2 && a[a.size()-1]<=6 && a[a.size()-1]>0){
                    dp[a.size()-2]=2;
                }
                else if(a[a.size()-2]==0){
                    dp[a.size()-2]=0;
                }
                else{
                    dp[a.size()-2]=1;
                }
            }
            bool none=false;
            for(int i=a.size()-3;i>=0;i--){
                if(a[i]>2 && a[i+1]==0){
                    none=true;
                    break;
                }
                if(a[i]==0){
                    dp[i]=0;
                }
                else{
                    if(a[i]==1){ // && a[i+1]!=0
                        dp[i]=dp[i+1]+dp[i+2];
                    }
                    else if(a[i]==2 && a[i+1]<=6){ // && a[i+1]>0
                        dp[i]=dp[i+1]+dp[i+2];
                    }
                    else{
                        dp[i]=dp[i+1];
                    }
                }
            }
            if(none){
                cout << 0 << endl;
            }
            else{
                cout << dp[0] << endl;
            }
        }
    }
}

