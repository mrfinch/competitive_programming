#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t){
        string s;
        cin >> s;
        vector<string> suf(s.size());
        for(int i=0;i<s.size();i++){
            suf[i]=s.substr(i);
        }
        sort(suf.begin(),suf.end());
        /*for(int i=0;i<s.size();i++){
            cout << suf[i] << endl;
        }*/
        int res=suf[0].size();
        for(int i=1;i<suf.size();i++){
            int x=suf[i-1].size();
            int y=suf[i].size();
            int cnt=0;
            for(int j=0;j<min(x,y);j++){
                if(suf[i][j]==suf[i-1][j]){
                    cnt++;
                }
                else{
                    break;
                }
            }
            res+=(y-cnt);
        }
        cout << res << endl;
        t--;
    }
}
