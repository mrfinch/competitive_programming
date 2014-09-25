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
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    int p,q,l,r;
    cin >> p >> q >> l >> r;
    vector<int> a(p);
    vector<int> b(p);
    int h=0;
    map<int,int> m;
    while(h<p){
        cin >> a[h] >> b[h];
        for(int i=a[h];i<=b[h];i++){
            m[i]=1;
        }
        h++;
    }
    vector<int> c(q);
    vector<int> d(q);
    h=0;
    while(h<q){
        cin >> c[h] >> d[h];
        h++;
    }
    int cnt=0;
    map<int,int>::iterator it;
    for(int i=l;i<=r;i++){
        for(int j=0;j<q;j++){
            //check(c[j]+l,d[j]+l);
            int x=c[j]+i;
            int y=d[j]+i;
            bool f=false;
            for(int k=x;k<=y;k++){
                if(m.find(k)!=m.end()){
                    cnt++;
                    f=true;
                    break;
                }
            }
            if(f==true)
                break;
        }
    }
    cout << cnt << endl;
}
