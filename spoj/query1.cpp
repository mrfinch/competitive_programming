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
    vector<int> a(n);
    vector<int> l(n);
    int m=0;
    ll x=0;
    while(m<n){
        cin >> a[m];
        if(a[m]>0){
            x=x+a[m];
            l[m]=x;
        }
        else{
            l[m]=0;
            x=0;
        }
        m++;
    }
    int k;
    cin >> k;
    while(k){
        ll s=0;
        ll mx=0;
        int i,j;
        cin >> i >> j;
        /*for(int x=i-1;x<j;x++){
            if(a[x]>0){
                s+=a[x];
                if(s>mx){
                    mx=s;
                }
            }
            else{
                s=0;
            }
        }*/
        if(i==1){
            cout << l[j-1] << endl;
        }
        else{
            cout << l[j-1]-l[i-2] << endl;
        }
        //cout << mx << endl;
        k--;
    }
}
