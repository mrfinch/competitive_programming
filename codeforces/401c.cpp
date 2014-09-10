#include <iostream>
#include <string>

using namespace std;
typedef long long ll;
int main(){
    ll n0,n1;
    cin >> n0 >> n1;
    if(n1>(n0*n0+2)){
        cout << -1 << endl;
        return 0;
    }
    bool x=true;
    string out="";
    while(n0>0 && n1>0){
        if(x){
            if(n1-n0<2){
                out+="1";
                n1--;
            }
            else{
                out+="11";
                n1-=2;
            }
            x=false;
        }
        else{
            out+="0";
            n0--;
            x=true;
        }
    }
    while(n1>0){
        out+="1";
        n1--;
    }
    cout << out << endl;
}
