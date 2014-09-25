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
    node(ll a,ll b,ll c,ll d){
        best=a;left=b;right=c;sum=d;
    }
    ll best,left,right,sum;
};

vector<node> tree(1000000,node(0,0,0,0));
vector<int> a(100005);

node combine(node l,node r){
    ll left=l.left;
    if(l.sum+r.left>left)
        left=l.sum+r.left;
    ll right=r.right;
    if(l.right+r.sum>right)
        right=l.right+r.sum;
    ll best=max(l.right+r.left,max(l.best,r.best));
    return node(best,left,right,l.sum+r.sum);
}

node fun(int pos,int st,int ed,int x,int y){
    //cout << st << " " << ed << " " << tree[pos].best << " " << pos << endl;
    if(x==st && y==ed){
        return tree[pos];
    }
    /*if(st>=x && ed<=y){
        return tree[pos];
    }*/
    int mid=(st+ed)/2;
    if(y<=mid){
        return fun(pos<<1,st,mid,x,y);
    }
    if(x>mid){
        return fun((pos<<1)+1,mid+1,ed,x,y);
    }

    //node i,j;
    node i=fun(2*pos,st,mid,x,mid);
    node j=fun(2*pos+1,mid+1,ed,mid+1,y);
    return combine(i,j);
}


node ans(int index, int from, int to, int a, int b) {
    if (from == a && to == b) {
        return tree[index];
    }
    int mid = (from+to)/2;
    if (b <= mid) {
        return ans((index<<1), from, mid, a, b);
    }
    if (a > mid) {
        return ans((index<<1) + 1, mid+1,to,a,b);
    }
    node l = ans((index<<1), from, mid, a, mid);
    node r = ans((index<<1) + 1, mid+1,to,mid+1,b);
    return combine(l,r);
}

node constructST(int pos,int st,int ed){
    if(st==ed){
        tree[pos]=node(a[st],a[st],a[st],a[st]);
        return tree[pos];
    }
    else{
        int mid=(st+ed)/2;
        node l=constructST(2*pos,st,mid);
        node r=constructST(2*pos+1,mid+1,ed);
        tree[pos]=combine(l,r);
        return tree[pos];
        //tree[pos]=max(max(tree[2*pos],tree[2*pos+1]),tree[2*pos]+tree[2*pos+1]);
        //cout << st << " " << ed << " " << tree[pos] << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int m=1;
    while(m<=n){
        cin >> a[m];
        m++;
    }
    constructST(1,1,n);
    int k;
    cin >> k;
    while(k){
        int x,y;
        cin >> x >> y;
        node res=fun(1,1,n,x,y);
        cout << res.best << endl;
        k--;
    }
}
