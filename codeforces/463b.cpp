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
    int m=0;
    while(m<n){
        cin >> a[m];
        m++;
    }
    ll sum;
    ll mn=INT_MAX;
    sum=0-a[0];
    if(sum<mn)
        mn=sum;
    for(int i=0;i<a.size()-1;i++){
        sum+=(a[i]-a[i+1]);
        if(sum<mn)
            mn=sum;
    }
    if(mn<0){
        cout << -1*mn << endl;
    }
    else{
        cout << 0 << endl;
    }

}
