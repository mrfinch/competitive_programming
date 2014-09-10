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

int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    int c=0;
    int i=0;
    while(n!=0){
        c++;
        n--;
        i++;
        if(i%m==0){
            n++;
        }
    }
    cout << c << endl;
}
