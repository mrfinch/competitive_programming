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
        vector< vector<int> > a(n,vector<int>(n));
        int i=0;
        int mx=INT_MIN;
        int x=-1;
        int y=-1;
        while(i<n){
            int j=0;
            while(j<n){
                cin >> a[i][j];
                if(a[i][j]>mx){
                    mx=a[i][j];
                    x=i;y=j;
                }
                j++;
            }
            i++;
        }
        map<int,int> m1;
        map<int,int> m2;
        int c=0;
        c+=mx;
        //cout << c << endl;
        m1[x]=1;
        m2[y]=1;
        int ct=1;
        while(ct<n){
            mx=INT_MIN;
            for(int i=0;i<n;i++){
                if(m1.find(i)!=m1.end())
                    continue;
            for(int j=0;j<n;j++){
                if(m2.find(j)!=m2.end())
                    continue;
                    if(a[i][j]>mx){
                        mx=a[i][j];x=i;y=j;
                    }
                }
            }
            c+=mx;
            //cout << c << " " << mx << endl;
            ct++;
            m2[y]=1;m1[x]=1;
        }
        cout << c << endl;
        t--;
    }
}
