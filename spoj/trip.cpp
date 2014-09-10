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
map<string,int> m[81][81];

void func(string s1,string s2,int i,int j,set<string>& s,vector< vector<int> >& dp,string w){
    cout << w << endl;
    if(m[i][j].find(w)!=m[i][j].end())
        return;
    if(i==0||j==0){
        s.insert(w);
    }
    else if(s1[i-1]==s2[j-1]){
        w=s1[i-1]+w;
        func(s1,s2,i-1,j-1,s,dp,w);
    }
    else if(dp[i-1][j]>dp[i][j-1]){
        func(s1,s2,i-1,j,s,dp,w);
    }
    else if(dp[i][j-1]>dp[i-1][j]){
        func(s1,s2,i,j-1,s,dp,w);
    }
    else{
        func(s1,s2,i-1,j,s,dp,w);
        func(s1,s2,i,j-1,s,dp,w);
    }
    m[i][j][w]=1;
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t){
        string s1,s2;
        cin>>s1;
        cin>>s2;
        vector< vector<int> > dp(s1.size()+1,vector<int>(s2.size()+1,0));
        for(int i=1;i<s1.size()+1;i++){
            for(int j=1;j<s2.size()+1;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        set<string> s;

        func(s1,s2,s1.size(),s2.size(),s,dp,"");
        //sort(s.begin(),s.end());
        set<string>::iterator it;
        for(it=s.begin();it!=s.end();it++){
            cout << *it << endl;
        }
        t--;
    }
}
