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

void inorder(vector<int>& tree,int pos,int sz){
    if(pos>sz){
        return;
    }
    inorder(tree,2*pos,sz);
    cout << tree[pos] << " " << pos <<endl;
    inorder(tree,2*pos+1,sz);
}

int findMin(vector<int>& tree,int cst,int ced,int qi,int qj,int pos){
    //cout << cst << " " << ced << " " << pos << " " << tree[pos] << endl;
    if(qi<=cst && qj>=ced){
        //cout << cst << " " << ced << " " << pos << " " << tree[pos] << endl;
        return tree[pos];
    }
    if(qi>ced || qj<cst){
        return -1;
    }
    int mid=(cst+ced)/2;
    //cout << mid << endl;
    int p1=findMin(tree,cst,mid,qi,qj,2*pos);
    int p2=findMin(tree,mid+1,ced,qi,qj,2*pos+1);
    if(p1==-1 && p2!=-1){
        return p2;
    }
    if(p2==-1  && p1!=-1){
        return p1;
    }
    if(p1==-1 && p2==-1)
        return -1;
    if(p1<p2){
        return p1;
    }
    else{
        return p2;
    }
}

//works when value updated is less than its original value
void update(vector<int>& tree,int pos,int st,int ed,int c_ind,int c_val){
    //cout << pos << " " << st << " " << ed << endl;
    if(c_ind<st && c_ind>ed){
        return;
    }
    if(st==ed){
        if(c_ind==st){
            cout << pos << " " << st << " " << ed << endl;
            tree[pos]=c_val;
        }
        return;
    }
    if(c_ind>=st && c_ind<=ed){
        cout << pos << " " << st << " " << ed << endl;
        tree[pos]=min(tree[pos],c_val);
    }

    int mid=(st+ed)/2;
    update(tree,2*pos,st,mid,c_ind,c_val);
    update(tree,2*pos+1,mid+1,ed,c_ind,c_val);
}

void constructST(vector<int>& tree,vector<int>& a,int pos,int st,int ed){
    if(st==ed){
        tree[pos]=a[st];
        //cout << tree[pos] << " " << pos << endl;
    }
    else{
        int mid=(st+ed)/2;
        constructST(tree,a,2*pos,st,mid);
        constructST(tree,a,2*pos+1,mid+1,ed);
        if(tree[2*pos]<=tree[2*pos+1]){
            tree[pos]=tree[2*pos];
        }
        else{
            tree[pos]=tree[2*pos+1];
        }
        //cout << tree[pos] << " " << pos << endl;
    }
    //cout << tree[pos] << " " << pos << " " << st << " " << ed <<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    vector<int> a(10);
    for(int i=0;i<10;i++){
        a[i]=i;
    }
    int sz=2*pow(2,ceil(log2(10)))-1;
    //cout << sz;
    vector<int> m(sz+1,0);
    constructST(m,a,1,1,a.size()-1);
    //inorder(m,1,sz);
    for(int i=1;i<sz+1;i++){
        //cout << m[i] << endl;
    }
    int x=findMin(m,1,a.size()-1,1,3,1);
    cout << x << endl;
    a[1]=0;
    update(m,1,1,a.size()-1,1,0);
    x=findMin(m,1,a.size()-1,1,3,1);
    cout << x << endl;
}
