#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
//map<int,int> m;
int main()
{
    ios::sync_with_stdio(false);
    //petr=true

    int t;
    cin >> t;
    while(t){
        int n;
        cin >> n;
        int c;
        if(((n-1)%3)==0)
            c=0;
        else if(((n-1)%3)==1)
            c=1;
        else
            c=2;
        cout << c << endl;
        t--;
    }
}
