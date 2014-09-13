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

vector<int> a(105);

int main()
{
    ios::sync_with_stdio(false);
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    int t;
    cin >> t;
    while(t){
        int n;
        cin >> n;
        int m=0;
        ll s=0;
        while(m<n){
            cin >> a[m];
            s+=a[m];
            m++;
        }
        double avg;
        avg=s/(n*1.0);
        int c=0;
        for(int i=0;i<n;i++){
            if(a[i]*1.0>avg){
                c++;
            }
        }
        cout << c << endl;
        t--;
    }
}
