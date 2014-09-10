#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> x(n,0);
    vector<int> y(n,0);
    vector<int> cnt(100001,0);
    vector<int> h(n,0);
    vector<int> a(n,0);
    int i=0;
    while(i<n){
        cin >> x[i] >> y[i];
        i++;
    }
    /*
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(x[i]==y[j] && y[i]==x[j]){
                h[i]+=2;h[j]+=2;
            }
            else if(x[i]!=y[j] && y[i]!=x[j]){
                h[i]++;a[i]++;h[j]++;a[j]++;
            }
            else if(x[i]==y[j] && y[i]!=x[j]){
                h[j]+=2;a[i]++;h[i]++;
            }
            else if(x[i]!=y[j] && y[i]==x[j]){
                h[i]+=2;a[j]++;h[j]++;
            }
        }

    }
    */
    for(int i=0;i<n;i++){
        cnt[x[i]]++;
    }
    for(int i=0;i<n;i++){
        h[i]=n-1;
        h[i]+=cnt[y[i]];
        a[i]=2*(n-1)-h[i];
    }
    for(int i=0;i<n;i++){
        cout << h[i] << " " << a[i] << endl;
    }
}
