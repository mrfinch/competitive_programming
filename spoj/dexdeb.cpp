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
    //debra=true
    vector<bool> db(100001,false);
    db[1]=true;
    db[2]=false;db[3]=true;db[4]=true;
    for(int i=5;i<db.size();i++){
        if(db[i-1]==false || db[i-4]==false){
            db[i]=true;
        }
        else{
            db[i]=false;
        }
    }
    int t;
    cin >> t;
    while(t){
        int n;
        cin >> n;
        if(db[n]==true){
            cout << "Debra" << endl;
        }
        else{
            cout << "Dexter" << endl;
        }
        t--;
    }
}
