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
    int n;
    cin >> n;
    vector< vector<int> > a(n+1,vector<int>(n+1));
    int i=1;
    vector<ll> d1(2*(n+1)+1,0);
    vector<ll> d2(2*(n+1)+1,0);
    while(i<=n){
        int j=1;
        while(j<=n){
            cin >> a[i][j];
            d1[i+j]+=a[i][j];
            d2[n+i-j]+=a[i][j];
            j++;
        }
        i++;
    }
    pair<int,int> s[2]; //0-odd,1-even
    vector<ll> v(2,-1);
    ll t;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            t=d1[i+j]+d2[n+i-j]-a[i][j];
            if((i+j)%2==0){
                if(t>v[1]){
                    v[1]=t;
                    s[1].first=i;s[1].second=j;
                }
            }
            else{
                if(t>v[0]){
                    v[0]=t;
                    s[0].first=i;s[0].second=j;
                }
            }
        }
    }
    ll res=v[0]+v[1];
    cout << res << endl;
    cout << s[0].first << " " << s[0].second << " " << s[1].first << " " << s[1].second << endl;
}
