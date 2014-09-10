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

ll func(ll mid,int n,int m){
    ll res=0;
    for(int i=1;i<=n;i++){
        res+=min(((mid-1)/i),ll(m));
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    ll k;
    cin >> n >> m >> k;
    ll l=1;
    ll r=(1LL*n*m)+1;
    ll x,mid;
    while(l<r){
        mid=(l+r)/2;
        x=func(mid,n,m);
        if(x<k){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    cout << l-1 << endl;
}
