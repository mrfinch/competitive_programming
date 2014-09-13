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
vector<int> a(100005);
vector< pair<int,bool> > tree(270000,make_pair(0,false));

void constructST(int pos,int st,int ed){
    if(st==ed){
        tree[pos].first=0;
        tree[pos].second=true;
    }
    else{
        int mid=(st+ed)/2;
        constructST(2*pos,st,mid);
        constructST(2*pos+1,mid+1,ed);
        if(tree[2*pos].second==true && tree[2*pos].first%3==0){
            tree[pos].first++;
        }
        if(tree[2*pos+1].second==true && tree[2*pos+1].first%3==0){
            tree[pos].first++;
        }
        if(tree[2*pos].second==false){
            tree[pos].first+=tree[2*pos].first;
        }
        if(tree[2*pos+1].second==false){
            tree[pos].first+=tree[2*pos+1].first;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    int n,q;
    cin >> n >> q;
    constructST(1,1,n);  //n in included in tree
}
