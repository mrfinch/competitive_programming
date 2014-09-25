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
    freopen("inputl.txt", "rt", stdin);
	freopen("outputl.txt", "wt", stdout);
    int t;
    cin >> t;
    int y=1;
    while(t){
        int n,k;
        cin >> n >> k;
        vector< pair<int,bool> > a(n,make_pair(0,false));
        int m=0;
        while(m<n){
            cin >> a[m].first;
            m++;
        }
        int x=ceil(n/3.0);
        int ind=-1;
        int diff=-1,l=-1,c=0;
        for(int i=0;i<x+1;i++){
            l=-1,c=0;
            bool f=false;
            for(int i=0;i<a.size();i++){
                if(a[i].second==true){
                    continue;
                }
                else{
                    //cout << l << " " << a[i].first << " " << diff << endl;
                    if(l==-1){
                        l=a[i].first;
                        c=0;
                    }
                    else{
                        diff=a[i].first-l;
                        if(diff==k){
                            c++;
                            if(c==1){
                                ind=i;
                            }
                            l=a[i].first;
                        }
                        else{
                            c=0;ind=-1;l=a[i].first;
                        }
                        if(c==2){
                            f=true;
                            break;
                        }
                    }
                    //cout << l << " " << a[i].first << " " << diff << " " << c << endl;

                }
            }
            if(f==true){
                a[ind].second=true;
                int k=ind-1;
                while(a[k].second==true){
                    k--;
                }
                a[k].second=true;
                k=ind+1;
                while(a[k].second==true){
                    k++;
                }
                a[k].second=true;
            }
            else{
                break;
            }
        }
        int cnt=0;
        for(int i=0;i<a.size();i++){
            if(a[i].second==false)
                cnt++;
        }
        cout << "Case #" << y << ": " << cnt <<endl;
        t--;y++;
    }
}
