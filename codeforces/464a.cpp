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
    string s;
    cin >> s;
    if(s[0]=='0'){
        cout << 1 << endl;
    }
    else{
        int i=0,cnt=0;
        while(i<s.size() && s[i]!='0'){
            i++;cnt++;
        }
        if(cnt<n){
            cout << cnt+1 << endl;
        }
        else{
            cout << cnt << endl;
        }
    }
}
