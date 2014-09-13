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
    int t;
    cin >> t;
    while(t){
        string s1,s2;
        cin >> s1 >> s2;
        map<char,int> m;
        for(int i=0;i<s1.size();i++){
            m[s1[i]]++;
        }
        int c=0;
        for(int i=0;i<s2.size();i++){
            if(m[s2[i]]>0){
                c++;
                m[s2[i]]=0;
            }
        }
        cout << c << endl;
        t--;
    }
}
