#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int i=1;
    int m1=0;
    int m2=0;
    int t1,t2,k;
    while(i<n){

        cin >> t1 >> t2 >> k;
        if(t1>m1 && k==2){
            m1=t1;
        }
        if(t2>m2 && k==2){
            m2=t2;
        }
        i++;
    }
    int x=max(m1,m2);
    int y=min(m1,m2);
    cout << x-y << endl;
    for(int i=x;i>y;i--){
        cout << i << " ";
    }
    cout << endl;

}
