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

bool myfunc(pair<int,int> x,pair<int,int> y){
    return (x.first!=y.first?x.first<y.first:x.second<y.second);
}

int main()
{
    ios::sync_with_stdio(false);
    int n,s;
    cin >> n >> s;
    vector< pair<int,int> > a(n);
    int m=0;
    while(m<n){
        cin >> a[m].first >> a[m].second;
        m++;
    }
    sort(a.begin(),a.end(),myfunc);
    int c=-1;
    for(int i=0;i<a.size();i++){
        if(a[i].first>s || (a[i].first==s && a[i].second>0))
            break;
        else{
            if(a[i].second==0 || a[i].second==100){
                if(c==-1)
                    c=0;
                continue;
            }

            int h=100-a[i].second;
            if(h>c)
                c=h;
        }
    }
    cout << c << endl;
}
