#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t){
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        int m=0;
        while(m<n){
            cin >> a[m];
            m++;
        }
        sort(a.begin(),a.end());

        int min=INT_MAX;
        k--;
        for(int i=0;i+k<n;i++){
            if(a[i+k]-a[i]<min){
                min=a[i+k]-a[i];
            }
        }
        cout << min << endl;
        t--;
    }
}
