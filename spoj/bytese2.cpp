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
    int t;
    cin >> t;
    while(t){
        int n;
        cin >> n;
        map<int,int> m;
        while(n){
            int a,b;
            cin >> a >> b;
            for(int i=a;i<=b;i++){
                m[i]++;
            }
            n--;
        }
        int mx=0;
        map<int,int>::iterator it;
        for(it=m.begin();it!=m.end();it++){
            if(it->second>mx){
                mx=it->second;
            }
        }
        cout << mx << endl;
        t--;
    }
}
