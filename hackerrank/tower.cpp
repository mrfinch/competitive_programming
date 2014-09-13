#include <cmath>
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <bitset>
#include <memory.h>
#include <functional>
#include <queue>
#include <fstream>
#include <ctime>
#include <deque>
#include <utility>
#include <stack>
#include <sstream>
#include <list>
#include <cctype>
#include <numeric>
#include <iomanip>
#include <assert.h>
#include <climits>

using namespace std;

typedef long long ll;
//ll res=0;
vector<int> a(20);
map<ll,ll> b;
ll fun(ll n,int k){
    cout << n << endl;
    if(b.find(n)!=b.end()){
        //cout << n << " her " << b[n] << endl;
        return b[n];
    }
    if(n==0){
        //res=(res+1)%1000000007;
        return 1LL;
    }

    if(n<0)
        return 0LL;
    ll t=0LL;
    for(int i=0;i<k;i++){
        t+=fun(n-a[i],k)%1000000007;
    }
    b[n]=t%1000000007;
    return b[n];
}
int main()
{
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    int k;
    cin >> k;
    int m=0;
    while(m<k){
        cin >> a[m];
        m++;
    }
    if(k==1){
        if(n%a[0]==0){
            cout << 1+1 << endl;
            return 0;
        }
        else{
            cout << 0 << endl;
            return 0;
        }
    }
/*    fun(n,k);
    res=(2*res)%1000000007;
    cout << res << endl;
*/
    map<ll,ll> b;
    /*for(int i=0;i<k;i++){
        b[a[i]]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<k;j++){
            b[i]=(b[i]+(i-a[j]>0?b[i-a[j]]:0))%1000000007;
        }
    }*/
    ll x=fun(n,k);
    //b[n]=(2*b[n])%1000000007;
    x=(2*x)%1000000007;
    cout << x << endl;
    return 0;
}
