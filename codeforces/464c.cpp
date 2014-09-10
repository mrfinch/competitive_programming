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
string s;

string func(int m,int p){
    char c;
    for(int i=m;i<s.size();i++){
        if(i==m){
           c=s[i]+1;
        }
        else{
            c='a';
        }
        while(c<('a'+p)){
            if(i-1>=0 && s[i-1]==c){
                c++;
            }
            else if(i-2>=0 && s[i-2]==c){
                c++;
            }
            else{
                break;
            }
        }
        if(c>='a'+p){
            return "";
        }
        else{
            s[i]=c;
        }
    }
    return s;
}

int main()
{
    ios::sync_with_stdio(false);
    int n,p;
    cin >> n >> p;
    cin >> s;
    for(int i=s.size()-1;i>=0;i--){
        string x=func(i,p);
        if(x.empty()==false){
            cout << x << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
