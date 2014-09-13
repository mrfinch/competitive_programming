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
vector<int> v(500005);
vector<int> p(500005);
//vector< vector< pair<int,int> > > dp(2,vector< pair<int,int> >(500005,make_pair(0,0)));
ll fun(int n,ll sc,ll en,int cur){
    if(cur==n){
        return (sc+v[cur]);
    }
    if(cur==1 || en==0){
        return fun(n,sc,p[cur]-1,cur+1);
    }
    return max(fun(n,sc+v[cur],en-1,cur+1),fun(n,sc,p[cur]-1,cur+1));
}

int main()
{
    ios::sync_with_stdio(false);
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    int n;
    cin >> n;
    int m=1;
    while(m<n+1){
        cin >> v[m] >> p[m];
        m++;
    }
    ll score=0;
    ll en=0;
    ll res=fun(n,score,en,1);
    cout << res << endl;
}
