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

ll euler(int n){
    ll res=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            res-=res/i;
        }
        while(n%i==0){
            n=n/i;
        }
    }
    if(n>1)
        res-=res/n;
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    int t;
    cin >> t;
    while(t){
        int n;
        cin >> n;
        ll x=euler(n);
        cout << x << endl;
        t--;
    }
}
