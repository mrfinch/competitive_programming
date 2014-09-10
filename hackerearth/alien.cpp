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
        string s1,s2;
        cin >> s1;
        cin >> s2;
        if(s1.find(s2)!=string::npos){
            cout << "YES" << endl;
        }
        else{

            for(int i=0;i<s2.size();i++){
                string x=s2.substr(i,1);
                if(s1.find(x)!=string::npos){
                    cout << "YES" << endl;
                    return 0;
                }
            }
            cout << "NO" << endl;
        }
        t--;
    }
}
