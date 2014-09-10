#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
int main(){
    string inp;
    cin >> inp;
    ll nb,ns,nc;
    cin >> nb >> ns >> nc;
    ll pb,ps,pc;
    cin >> pb >> ps >> pc;
    ll r;
    cin >> r;
    ll cb=0,cs=0,cc=0;
    for(int i=0;i<inp.size();i++){
        if(inp[i]=='B'){
            cb++;
        }
        else if(inp[i]=='S'){
            cs++;
        }
        else{
            cc++;
        }
    }
    ll low=0L;
    ll high = 10000000000000L;
    ll ans=0;
    ll x;
    ll z=0;
    //cout << low << "   " << high << endl;
    while(low<=high){
        x = low+(high-low)/2;
        ll cost = max(z,(cb*x-nb))*pb+max(z,(cs*x-ns))*ps+max(z,(cc*x-nc))*pc;
        //cout << x << " " << cost << endl;
        if(cost<r){
            low = x+1;
            ans=x;
        }
        else if(cost > r){
            high=x-1;
            //x=ans;
        }
        else{
            //cout << x << endl;
            //return x;
            ans=x;
            break;
        }
    }
    cout << ans << endl;
}
