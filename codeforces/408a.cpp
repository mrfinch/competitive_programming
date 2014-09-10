#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    int m=0;
    while(m<n){
        cin >> v[m];
        m++;
    }
    int min=99999;
    for(int i=0;i<v.size();i++){
        int x=0;
        int j=0;
        while(j<v[i]){
            int inp;
            cin >> inp;
            x+=(inp*5);
            j++;
        }
        x+=(v[i]*15);
        if(x<min){
            min=x;
        }
    }
    cout << min << endl;
}
