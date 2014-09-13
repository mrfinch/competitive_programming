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
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    int c1=n*a;
    int x,y;
    ll z;
    ll res=c1;
    for(int i=1;i<=1005;i++){
        x=i*m;
        y=n-x;
        y=max(0,y);
        z=(i*b)+(y*a);
        res=min(z,res);
    }
    cout << res << endl;
}
