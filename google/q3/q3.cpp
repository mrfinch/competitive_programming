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
ll c=0;
ll n,k;
string res;
vector<string> ans;
int fun(ll x,string s,ll st,ll cl){
    //cout << s << " " << x << endl;
    if(cl>st){
        return -1;
    }
    if(x<0){
        return -1;
    }
    if(x==0 && s.empty()==false){
        c++;
        //cout << s << " " << c <<endl;
        //ans.push_back(s);
        if(c==k){
            res=s;
            return -1;
        }


    }

    if(x==2*n){
        string s="(";
        fun(x-1,s,1,0);
    }
    else{
        string y=s;
        if(st==cl){
            y=y+"(";
            fun(x-1,y,st+1,cl);
        }
        else if(st==n){
            fun(x-1,y+")",st,cl+1);
        }
        else{
            fun(x-1,y+"(",st+1,cl);
            fun(x-1,y+")",st,cl+1);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
	freopen("inputl.txt", "rt", stdin);
	freopen("outputl.txt", "wt", stdout);
	int t;
	cin >> t;
	int m=1;
	while(t){
        cin >> n >> k;
        string s="";
        c=0;
        res="";
        fun(2*n,s,0,0);
        if(res.empty()==false){
            cout << "Case #" << m << ": " << res <<endl;
        }
        else{
            cout << "Case #" << m << ": " << "Doesn't Exist!" <<endl;
        }
        t--;m++;
	}
}
