#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string s;
    cin >> s;
    vector< vector<int> > dp(s.size(),vector<int>(s.size(),0));
    //long long c=0;
    long long odd=0;
    long long even=0;
    //cout << s.size() << endl;
    for(int i=0;i<s.size();i++){
        dp[i][i]=1;
        //c++;
        odd++;
        //cout << odd << endl;
    }
    //cout << odd << endl;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]){
            dp[i][i+1]=1;
            //c++;
            even++;
        }
    }

    for(int i=2;i<s.size();i++){
        for(int j=0;j+i<s.size();j++){
            if(s[j]==s[j+i]){
                if(dp[j+1][j+i-1]==1){
                    dp[j][j+i]=1;
                    //c++;
                    if((i+1)%2==0){
                        even++;
                    }
                    else{
                        odd++;
                    }
                    //cout << s.substr(j,i+1) << odd << " " << even << i+1 << endl;
                }
                else{
                    if(s[j+i-1]==s[j+i]){
                        if(dp[j+1][j+i-2]==1){
                            dp[j+1][j+i-1]=1;
                            if((i+1)%2==0){
                                even++;
                            }
                            else{
                                odd++;
                            }
                        }
                    }
                    else if(s[j]==s[j+1]){
                        if(dp[j+2][j+i-1]==1){
                            dp[j+1][j+i-1]=1;
                            if((i+1)%2==0){
                                even++;
                            }
                            else{
                                odd++;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << even << " " << odd << endl;
}
