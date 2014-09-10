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
    vector<int> a(500006);
    a[0]=0;
    map<int,int> m;
    m[0]=1;
    for(int i=1;i<=500005;i++){
        int x=a[i-1]-i;
        if(x>0 && m.find(x)==m.end()){
            a[i]=x;
            m[x]=1;
        }
        else{
            a[i]=a[i-1]+i;
            m[a[i-1]+i]=1;
        }
    }
    while(true){
        int n;
        cin >> n;
        if(n==-1){
            break;
        }

        cout << a[n] << endl;
    }
}
