#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
map<int,int> m;
int findnum(int n,int s){
    if(n<0 || s<0)
        return 0;
    if(n<=s){
        return 1;
    }
    else{
        if(m.find(floor(n/2.0))!=m.end() && m.find(ceil(n/2.0))!=m.end()){
            return m[floor(n/2.0)]+m[ceil(n/2.0)];
        }
        else if(m.find(floor(n/2.0))!=m.end()){
            return m[floor(n/2.0)]+findnum(ceil(n/2.0),s);
        }
        else if(m.find(ceil(n/2.0))!=m.end()){
            return findnum(floor(n/2.0),s)+m[ceil(n/2.0)];
        }
        else
            return findnum(floor(n/2.0),s)+findnum(ceil(n/2.0),s);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int s;
    cin >> s;
    int t;
    cin >> t;
    while(t){
        int n;
        cin >> n;
        int x=findnum(n,s);
        m[n]=x;
        cout << x << endl;
        t--;
    }
}
