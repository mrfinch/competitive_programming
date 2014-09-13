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

int solve(int x,int y){
    if(x==0){
        if(y==0){
            return 0;
        }
        else{
            return 1;
        }
    }
    else{
        if(y==0)
            return 1;
        else{
            return 0;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> a(n);
    int r=0;
    for(int i=0;i<k;i++){
        a[i]=r^(s[i]-'0');
        r=(s[i]-'0');
    }
    r=0;
    for(int i=n-1;i>=n-k;i--){
        a[i]=r^(s[i+k-1]-'0');
        r=(s[i+k-1]-'0');
    }
    if(2*k<n){
        int t1=k;
        int t2=n-k-1;
        //cout << t1 << " " << t2 << endl;
        for(int i=t1;i<=t2;i++){
            int r=0;
            for(int j=i-1;j>i-k;j--){
                r=r^a[j];
            }
            a[i]=solve(s[i]-'0',r);
        }
    }
    for(int i=0;i<n;i++){
        cout << a[i];
    }
    cout << endl;
}
