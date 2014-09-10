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
    int n,m;
    cin >> n >> m;
    int i=1;
    vector<int> a(n+1);
    while(i<=n){
        cin >> a[i];
        i++;
    }
    i=0;
    int ind=1;
    while(i<m){
        char s;
        int x;
        cin >> s >> x;
        if(s=='A' || s=='C'){
            if(s=='A')
                x=n-x;
            if(x==n)
                continue;
            ind=(ind+x)%n;
            if(ind==0){
                ind=n;
            }
        }
        else{
            int y=(ind+x-1)%n;
            if(y==0){
                y=n;
            }
            cout << a[y] << endl;
        }
        i++;
    }
}
