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
        string s,x;
        cin >> s;
        x=s[0];
        for(int i=1;i<s.size();i++){
            if(s[i]!=x[x.size()-1]){
                x+=s[i];
            }
        }
        cout << s.size()-x.size() << endl;
        t--;
    }
}
