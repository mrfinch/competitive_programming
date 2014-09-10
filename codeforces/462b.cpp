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

int main()
{
    ios::sync_with_stdio(false);
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> a(26,0);
    for(int i=0;i<s.size();i++){
        a[s[i]-'A']++;
    }
    sort(a.rbegin(),a.rend());
    ll c=0;

    for(int i=0;i<a.size();i++){
        if(k==0)
            break;
        if(a[i]>=k){
            c+=(k*k);
            k=0;
            break;
        }
        else if(a[i]<k){
            c+=(a[i]*a[i]);
            k-=a[i];
        }

    }
    cout << c << endl;
}
