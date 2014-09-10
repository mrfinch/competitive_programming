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

string res;

void func(ll n){
    //cout << res << " " << n <<endl;
    if(n<=0){
        return;
    }
    else if(n%2==0){
        res="6"+res;
        func((n-2)/2);
    }
    else{
        res="5"+res;
        func((n-1)/2);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t){
        ll n;
        cin >> n;
        res="";
        func(n);
        cout << res << endl;
        t--;
    }
}
