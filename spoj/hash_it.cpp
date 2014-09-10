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
        int n;
        cin >> n;
        int h=0;
        map<int,string> m;
        map<string,int> mp;
        while(h<n){
            string s1;
            cin >> s1;
            string x=s1.substr(4);
            if(s1.substr(0,3)=="ADD"){
                if(mp.find(x)!=mp.end()){h++;continue;}
                int c=0;
                for(int i=0;i<x.size();i++){
                    c+=((i+1)*int(x[i]));
                }
                c=19*c;
                c=c%101;
                if(m.find(c)!=m.end()){
                    int y;
                    for(int j=1;j<=19;j++){
                        y=(c+(j*j)+(23*j))%101;
                        if(m.find(y)==m.end()){
                            m[y]=x;
                            mp[x]=y;
                            break;
                        }
                    }
                }
                else{
                    m[c]=x;
                    mp[x]=c;
                }
            }
            else{
                if(mp.find(x)==mp.end()){h++;continue;}
                int g=mp[x];
                m.erase(g);
                mp.erase(x);
            }
            h++;
        }
        map<int,string>::iterator it;
        cout << m.size() << endl;
        for(it=m.begin();it!=m.end();it++){
            cout << it->first << ":" << it->second << endl;
        }
        t--;
    }
}
