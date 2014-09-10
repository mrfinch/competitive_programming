#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(){
    vector<int> a(256,0);
    string s;
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        if(s[i]=='{' || s[i]=='}' || s[i]==',' || s[i]==' '){
            continue;
        }
        else{
            if(a[s[i]]==0){
                a[s[i]]++;
            }
        }
    }
    ll cnt=0;
    for(int i=0;i<256;i++){
        cnt+=a[i];
    }
    cout << cnt << endl;
}
