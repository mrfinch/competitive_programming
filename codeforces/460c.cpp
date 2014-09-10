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
    int n,mw,w;
    cin >> n >> mw >> w;
    //vector<int> a(n);
    map<long long,long long> m;
    int q=0;
    ll v;
    while(q<n){
        cin >> v;
        m[v]++;
        q++;
    }
    map<long long,long long>::iterator it;
    /*while(mw>0){
        int t=w;
        for(it=m.begin();it!=m.end();it++){
            if(m[it->first]>0 && t>0){
                //cout << m[it->first] << " " << it->first << endl;
                while(m[it->first]>0 && t>0){
                    m[it->first]=m[it->first]-1;
                    m[(it->first)+1]=m[(it->first)+1]+1;
                    t--;
                }
            }
            if(t==0)
                break;
        }
        mw--;
    }*/
    while(mw>0){
        int t=w;
        while(t>0){
            for(it=m.begin();it!=m.end();it++){
                if(m[it->first]>0){
                //cout << m[it->first] << " " << it->first << endl;
                    m[it->first]=m[it->first]-1;
                    m[(it->first)+1]=m[(it->first)+1]+1;
                    t--;
                    break;
                }
            }
        }
        mw--;
    }
    for(it=m.begin();it!=m.end();it++){
        if(m[it->first]>0){
            cout << it->first << endl;
            break;
        }
    }
}
