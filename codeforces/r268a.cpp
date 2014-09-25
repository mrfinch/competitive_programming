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
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> s(n+1,0);
    vector<int> a(m);
    int j=0;
    while(j<m){
        cin >> a[j];
        s[a[j]]++;
        j++;
    }
    int x;
    cin >> x;
    vector<int> b(x);
    int i=0;
    while(i<x){
        cin >> b[i];
        s[b[i]]++;
        i++;
    }
    bool f=true;
    for(int i=1;i<=n;i++){
        if(s[i]==0){
            f=false;
            break;
        }
    }
    if(f==true){
        cout << "I become the guy." << endl;
    }
    else{
        cout << "Oh, my keyboard!" << endl;
    }
}
