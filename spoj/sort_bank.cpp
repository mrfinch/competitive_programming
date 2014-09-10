#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdio>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t){
        int n;
        cin >> n;
        vector<string> a(n);
        map<string,int> c;
        int m=0;
        while(m<n){
            getline(cin,a[m]);
            c[a[m]]++;
            cout << a[m] << endl;
            m++;
        }
        map<string,int>::iterator it=c.begin();
        /*for(it=c.begin();it!=c.end();++it){
            cout << it->first << " " << it->second << endl;
        }*/
        t--;
    }
}
