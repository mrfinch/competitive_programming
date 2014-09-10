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
        string s;
        cin >> s;
        ll res=1;
        for(int i=0;i<s.size();i++){
            if(i%2==0){
                if(s[i]=='l'){
                    res=(2*res)%1000000007;
                }
                else{
                    res=(2*res+2)%1000000007;
                }
            }
            else{
                if(s[i]=='l'){
                    res=(2*res-1)%1000000007;
                }
                else{
                    res=(2*res+1)%1000000007;
                }
            }
        }
        cout << res << endl;
        t--;
    }
}
