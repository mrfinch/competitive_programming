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

int main()
{
    ios::sync_with_stdio(false);
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    ll n,a,b;
    cin >> n >> a >> b;
    ll req=n*6;
    ll i=a;
    ll j=b;
    ll p=i*j;
    if(p>=req){
        cout << p << endl;
        cout << i << " " << j << endl;
        return 0;
    }
    ll x,y;
    ll res=2*req,k,l;
    ll t1=ceil(req/(b*1.0)),t2=req/(a*1.0);
    //cout << t1 << " " << t2 << endl;
    for(i=a;i<=t1;i++){
        for(j=b;j<=t2;j++){
            p=i*j;
            //cout << p << endl;
            if(p<req)
                continue;
            if(p>=req){
                if(p<res){
                    res=p;
                    k=i;l=j;
                }
                break;
            }
        }
    }
    cout << res << endl;
    cout << k << " " << l << endl;
}
