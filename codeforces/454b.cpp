#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int m=0;
    while(m<n){
        cin >> a[m];
        m++;
    }
    int ind=-1;
    for(int i=0;i<a.size()-1;i++){
        if(a[i+1]<a[i]){
            ind=i+1;
            break;
        }
    }
    if(ind==-1){
        cout << 0 << endl;
    }
    else{
        vector<int> b(n);
        int j=0;
        for(int i=ind;i<a.size();i++){
            b[j]=a[i];
            j++;
        }
        for(int i=0;i<ind;i++){
            b[j]=a[i];
            j++;
        }
        bool sort=true;
        for(int i=0;i<b.size()-1;i++){
            if(b[i+1]<b[i]){
                sort=false;
                break;
            }
        }
        if(sort){
            cout << b.size()-ind << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
}
