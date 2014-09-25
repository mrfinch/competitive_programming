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

ll fun(int m,int n){
    if(m==n){
        return 1;
    }
    else{
        ll res=1;
        for(int i=1;i<=2;i++){
            res=(res*(n-i+1))%1000000007;
            res=(res/i)%1000000007;
        }
        return res%1000000007;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
    int t;
    cin >> t;
    int j=1;
    while(t){
        int m,n;
        cin >> m >> n;
        ll x;
        if(n==m){
            x=1;
        }
        else{
            if(m!=1){
                x=1;
                int y=n-m;
                for(int i=1;i<=y;i++){
                    x=(x*m)%1000000007;
                }
                x=(x*2)%1000000007;
            }
            else{
                x=1;
            }
        }
        for(int i=1;i<=m;i++){
            x=(x*i)%1000000007;
        }
        cout << "Case #" << j << ": " << x <<endl;
        t--;j++;
    }
}
