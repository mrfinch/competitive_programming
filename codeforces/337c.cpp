#include <iostream>

using namespace std;
typedef long long ll;

int main(){
    ll n,m,k;
    cin >> n >> m >> k;
    ll ctr=0;
    bool x =true;
    ll cnt=0;
    ll ii=0;
    ll jj=0;
    ll wrong = n-m;
    ll correct = m;
    while(ii<correct && jj<wrong){
        if(x){
            ll i=ii+k-1;
            while(ii<i && ii<correct){
                cnt++;
                ctr++;
                ii++;
            }
            x=false;
        }
        else{
            if(jj<wrong){
                ctr=0;
                jj++;
                x=true;
            }
        }
        if(ctr==k){
            cnt=2*cnt;
        }
        cout << ctr << " " << cnt << endl;
    }
    while(ii<correct){
        ii++;
        ctr++;
        cnt++;
        if(ctr==k){
            cnt=2*cnt;
        }
    }
    cout << cnt << endl;
}
