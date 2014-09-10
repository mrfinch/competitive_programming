#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }
    else{
        gcd(b,a%b);
    }
}
int main(){
    ll x,y,a,b;
    cin >> x >> y >> a >> b;
    //ll mm=max(x,y);
    //ll mi=min(x,y);
    //ll temp = mm;
    ll c=0;
    ll n = gcd(x,y);
    ll m=(x*y)/n;
    ll t = m;
    int i=1;
    //cout << m << endl;
    /*while(t<=b){
        if(t>=a && t<=b)
            c++;
        i++;
        t=i*m;
    }*/
    ll q=ceil(a/(m*1.0));
    ll w=floor(b/(m*1.0));
    c=w-q+1;
    /*
    for(int i=1;temp<=b;i++){
        temp=i*mm;
        if(temp%mi==0 && temp>=a && temp<=b){
            c++;
        }
    }*/
    cout << c << endl;
}
