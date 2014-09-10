#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
typedef long long ll;
bool func(pair<ll,ll> a,pair<ll,ll> b){
    return a.second<b.second;
}
int main(){
        ll h,b,l;
        cin >> l >> b >> h;
        int i=0;
        vector< pair<ll,ll> > inp(h,make_pair(0,0));
        while(i<h){
            ll tk,ck;
            cin >> tk >> ck;
            inp[i].first = tk;
            inp[i].second = ck;
            i++;
        }
        ll t=0;
        for(int i=0;i<inp.size();i++){
            t+=inp[i].first;
        }
        if(t<(l*b)){
            cout << "Impossible" << endl;
            return 0;
        }
        sort(inp.begin(),inp.end(),func);
        ll num=0;
        i=0;
        ll c=0;
        while(num<(l*b)){
            if(inp[i].first<(l*b-num)){
                num+=inp[i].first;
                c+=(inp[i].first*inp[i].second);
                i++;
            }
            else{
                ll x = (l*b)-num;
                c+=(x*inp[i].second);
                num=l*b;
            }
        }
        cout << c << endl;
}
