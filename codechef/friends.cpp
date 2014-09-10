#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector< vector<int> > inp(n,vector<int>(n));
    int m=0;
    while(m<n){
        string s;
        cin >> s;
        for(int i=0;i<s.size();i++){
            inp[m][i]=s[i]-'0';
        }
        m++;
    }
    long long cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
                continue;
            if(inp[i][j]==1)
                continue;
            for(int k=0;k<n;k++){
                if(k==i)
                    continue;
                if(inp[k][j]==1){
                    //inp[i][j]=1;
                    cnt++;
                    break;
                }
            }
        }
    }
    cout << cnt << endl;
}
