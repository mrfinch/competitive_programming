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
    string s;
    cin >> s;
    int m;
    cin >> m;
    while(m){
        char c;
        cin >> c;
        if(c=='C'){
            int l,r;
            char a;
            cin >> l >> r >> a;
            for(int i=l-1;i<r;i++){
                s[i]=a;
            }
            //cout << s << endl;
        }
        else if(c=='S'){
            int l1,r1,l2,r2;
            cin >> l1 >> r1 >> l2 >> r2;
            string k=s.substr(0,l1-1);
            string p=s.substr(r2-1);
            string x=s.substr(l1-1,l1-r1+1);
            string y=s.substr(l2-1,l2-r2+1);
            s=k+y+x+p;
            //cout << s << endl;
        }
        else if(c=='R'){
            int l,r;
            cin >> l >> r;
            reverse(s.begin()+l-1,s.begin()+r);
            //cout << s << endl;
        }
        else if(c=='W'){
            int l,r;
            cin >> l >> r;
            string x=s.substr(l-1,r-l+1);
            cout << x << endl;
        }
        else if(c=='H'){
            int l1,l2,l;
            cin >> l1 >> l2 >> l;
            int i=0;
            int c=0;
            while(i<l && l2<s.size()){
                if(s[l1-1]!=s[l2-1]){
                    c++;
                }
                l1++;l2++;i++;
            }
            cout << c << endl;
        }
        m--;
    }
}
