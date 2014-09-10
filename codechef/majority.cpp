#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
//Moore voting algo
int main(){
    int t;
    cin >> t;
    while(t){
        int n;
        cin >> n;
        int m=0;
        vector<int> a(n);
        while(m<n){
            scanf("%d",&a[m]);
            m++;
        }
        int major=0;
        int cnt=0;
        for(int i=0;i<a.size();i++){
            if(a[major]==a[i]){
                cnt++;
            }
            else{
                cnt--;
            }
            if(cnt==0){
                major=i;
                cnt=1;
            }
        }
        int c=0;
        for(int i=0;i<a.size();i++){
            if(a[i]==a[major]){
                c++;
            }
        }
        if(c>n/2){
            cout << "YES " << a[major] << endl;
        }
        else{
            cout << "NO" << endl;
        }
        t--;
    }
}
