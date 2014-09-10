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
    vector<int> a(n+1);
    int m=1;
    while(m<=n){
        cin >> a[m];
        m++;
    }
    int i=1;
    int cnt=0;
    while(i<a.size()){
        if(a[i]==0){
            i++;
            //continue;
        }
        else{
            while(i<a.size() && a[i]==1){
                cnt++;
                i++;
            }
            if(i<a.size()){
                while(i<a.size() && a[i]==0){
                    i++;
                }
                if(a[i]==1){
                    cnt++;
                }
                /*if(i==a.size()-1){
                    cnt++;
                }*/
            }
        }
    }
    cout << cnt << endl;
}
