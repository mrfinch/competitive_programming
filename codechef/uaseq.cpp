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
    int n,k;
    cin >> n >> k;
    int m=0;
    vector<int> a(n);
    while(m<n){
        cin >> a[m];
        m++;
    }
    vector<int> d(n-1);
    for(int i=0;i<d.size();i++){
        d[i]=a[i+1]-a[i];
    }
    int ind=0;
    int c=0;
    for(int i=0;i<d.size()-1;i++){
        if(d[i+1]-d[i]==0){
            if(c==0)
                ind=i;
            c++;
            if(c==k)
                break;
        }
        else{
            c=0;
        }
    }
    int diff=-1;
    if(c==k){
    for(int i=0;i<d.size();i++){
        if(i<ind || i>ind+k-1){
            diff=d[i];
            break;
            }
        }
    }
    else{

    }

    if(ind==0 && c==k){
        for(int i=a.size()-2;i>=0;i--){
            a[i]=a[i+1]-diff;
        }
    }
    else{
        for(int i=1;i<a.size();i++){
            a[i]=a[i-1]-diff;
        }
    }
    for(int i=0;i<a.size();i++){
        cout << a[i] << " ";
    }
    cout << endl;
}
