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
struct node{
    node(int a,int b,int c){
        wid=a;ht=b;pos=c;
    }
    int wid,ht,pos;
};
bool fun(node x,node y){
    //return (a.wid<b.wid && a.ht<b.ht);
    if(x.wid == y.wid)	return x.ht < y.ht;
        return x.wid < y.wid;
}

int main()
{
    ios::sync_with_stdio(false);
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    int n,w,h;
    cin >> n >> w >> h;
    int m=0;
    vector<node> a;
    while(m<n){
        int t1,t2;
        cin >> t1 >> t2;
        if(t1>w && t2>h){
            a.push_back(node(t1,t2,m));
        }
        m++;
    }
    if(a.size()==0){
        cout << 0 << endl;
        return 0;
    }
    sort(a.begin(),a.end(),fun);
    vector< pair<int,int> > dp(a.size(),make_pair(1,-1));
    for(int i=0;i<a.size();i++){
        for(int j=0;j<i;j++){
            if(a[i].wid>a[j].wid && a[i].ht>a[j].ht){
                if(dp[i].first<dp[j].first+1){
                    dp[i].first=dp[j].first+1;
                    dp[i].second=j;
                }
            }
        }
    }
    int mx=-1,ind=-1;
    for(int i=0;i<a.size();i++){
        //cout << dp[i].first << " " << dp[i].second << "" << a[i].pos << endl;
        if(dp[i].first>mx){
            mx=dp[i].first;
            ind=i;
        }
    }
    cout << mx << endl;
    vector<int> ans;
    ans.push_back(a[ind].pos+1);
    while(dp[ind].second!=-1){
        ans.push_back(a[dp[ind].second].pos+1);
        ind=dp[ind].second;
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}
