#include <iostream>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    if(n<(2*k+1)){
        cout << -1 << endl;
        return 0;
    }
    cout << n*k << endl;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<=k;j++){
            int x;
            if(((i+j)%n)==0){
                x=i+j;
            }
            else{
                x=(i+j)%n;
            }
            cout << i << " " << x << endl;
        }
    }
}
