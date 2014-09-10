#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    string inp;
    cin >> inp;
    vector<int> b(n,0);
    for(int i=0;i<inp.size();i++){
        if(inp[i]=='.')
            continue;
        if(inp[i]=='L'){
            int x=-1;
            for(int j=i;j>=0;j--){
                if(inp[j]=='R')
                    break;
                b[j]=b[j]+x;
                x--;
            }
        }
        if(inp[i]=='R'){
            int x=1;
            for(int j=i;j<inp.size();j++){
                if(inp[j]=='L')
                    break;
                b[j]=b[j]+x;
                x++;
            }
        }
    }
    int cnt=0;
    for(int i=0;i<b.size();i++){
        if(inp[i]=='L' || inp[i]=='R')
            continue;
        if(b[i]==0){
            cnt++;
        }
    }
    cout << cnt << endl;
}
