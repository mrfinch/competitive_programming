#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
int main(){
    ll n,m;
    cin >> n >> m;
    int i=1;
    vector<ll> inp(m+1,0);
    while(i<m+1){
        cin >> inp[i];
        i++;
    }
    sort(inp.begin(),inp.end());
    if(inp[1]==1){
        cout << "NO" << endl;
        return 0;
    }
    if(inp[inp.size()-1]==n){
        cout << "NO" << endl;
        return 0;
    }
    bool fall=false;
    for(int i=2;i<inp.size()-1;i++){
        if(inp[i]-inp[i-1]==1 && inp[i+1]-inp[i]==1){
            fall=true;
            break;
        }
    }
    if(fall){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
}
