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
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n;
    cin >> n;
    vector<int> a(n+1);
    int m=1;
    while(m<=n){
        cin >> a[m];
        m++;
    }
    vector<int> l(n+1);
    vector<int> r(n+1);
    for(int i=0;i<=n;i++){
        if(i==0||i==1){
            l[i]=0;
            continue;
        }
        l[i]=l[i-1]+(a[i-1]>=0?1:0);
    }
    for(int i=n;i>=0;i--){
        if(i==n){
            r[i]=0;
            continue;
        }
        r[i]=r[i+1]+(a[i+1]<=0?1:0);
    }
    int mx=100001;
    for(int i=1;i<=n;i++){
        if(i==1){
            if(a[i]>=0){
                if(l[i]+r[i]+1<mx){
                    //cout << i << " " << l[i] << " " << r[i] << endl;
                    mx=l[i]+r[i]+1;
                }
            }
            continue;
        }
        if(i==n){
            if(a[i]<=0){
                if(l[i]+r[i]+1<mx){
                    //cout << i << " " << l[i] << " " << r[i] << endl;
                    mx=l[i]+r[i]+1;
                }
            }
            continue;
        }
        if(a[i]==0){
            if(l[i]+r[i]+1<mx){
                //cout << i << " " << l[i] << " " << r[i] << endl;
                mx=l[i]+r[i]+1;
            }
        }
        else{
            if(l[i]+r[i]<mx){
                //cout << i << " " << l[i] << " " << r[i] << endl;
                mx=l[i]+r[i];
            }
        }
    }
    cout << mx << endl;
}
