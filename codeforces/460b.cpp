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

int sum(int i){
    int x=0;
    int t=i;
    while(t!=0){
        x+=(t%10);
        t/=10;
    }
    return x;
}

long long power(int s,int a){
    ll x=1;
    int t=a;
    while(t>0){
        x*=s;
        t--;
    }
    //cout << x << endl;
    return x;
}
int main()
{
    ios::sync_with_stdio(false);
    int a,b,c;
    cin >> a >> b >> c;
    ll v;
    vector<int> q;
    //int m=sum(337);

    //v=pow(m,a);
    //cout << m << " " << pow(m,a)*b << endl;
    //v=v+c;
    //cout << v << " "<< v-1 << endl;
    //cout << power(72,5) << endl;
    //ll w=power(81,a);
    //ll j=1000000;
    //w=max(j,w);
    //ll k=1e9;
    //map<int,long long> m;
    for(int i=1;i<=81;i++){
        v=b*power(i,a)+c;
        if(v>0 && v<1000000000 && sum(v)==i){
            q.push_back(v);
        }
    }
    cout << q.size() << endl;
    for(int i=0;i<q.size();i++){
        cout << q[i] << " ";
    }
    cout << endl;
}
