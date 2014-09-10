#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(){
    ll n,m;
    cin >> n >> m;
    ll x=n+(2*n);
    //vector<int> inp(x+1,0);
    ll a=1+n+1;
    ll c=1;
    ll y=(1+n+n+1+2*n)/2;
    //int i;
    //cout << y << " dh" <<endl;
    /*for(i=a;i<=y;i++){
        inp[i]=c;
        c++;
    }
    c--;
    c--;
    //cout << i << " jh" << endl;
    for(;i<=(n+(2*n));i++){
        inp[i]=c;
        c--;
    }*/
    ll mid=y-a+1;
	//cout << "m " << mid << " " << y << " " << a <<endl;
    while(m){
        ll q;
        cin >> q;
        if(q<a){
            cout << 0 << endl;
        }
        else if(q<y){
            ll b=y-q;
            ll out=mid-b;
            cout << out << endl;
        }
        else if(q==y){
            cout << mid << endl;
        }
        else if(q>y){
            ll b=q-y;
            ll out=mid-b;
            cout << out << endl;
        }
        m--;
    }
}
