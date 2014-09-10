#include <iostream>
#include <map>

using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    map<ll,ll> x;
    bool happy=true;
    ll cnt=0;
    while(n!=1){
        ll m=0;
        ll t=n;
        while(t!=0){
            m+=((t%10)*(t%10));
            //t=t/10;
            t=t/10;
        }
        cnt++;
        //cout << m << endl;
        n=m;
        if(n==1){
            break;
        }
        else{
            if(x.find(n)==x.end()){
                x[n]=1;
            }
            else{
                happy=false;
                break;
            }
        }
    }
    if(!happy){
        cout << -1 << endl;
    }
    else{
        cout << cnt << endl;
    }
}
