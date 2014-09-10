#include <iostream>

using namespace std;

int main(){
    int x,y;
    cin >> x >> y;
    int m;
    cin >> m;
    if(m%6==1){
        x=x%1000000007;
        if(x<0){
            x=x+1000000007;
        }
        cout << x << endl;
    }
    else if(m%6==2){
        y=y%1000000007;
        if(y<0){
            y=y+1000000007;
        }
        cout << y << endl;
    }
    else if(m%6==3){
        int m=(y-x)%1000000007;;
        if(m<0){
            m=m+1000000007;
        }
        cout << m << endl;
    }
    else if(m%6==4){
        int m=(-1*x)%1000000007;
        if(m<0){
            m=m+1000000007;
        }
        cout << m << endl;
    }
    else if(m%6==5){
        int m=(-1*y)%1000000007;
        if(m<0){
            m=m+1000000007;
        }
        cout << m << endl;
    }
    else{
        int m=(-y+x)%1000000007;
        if(m<0){
            m=m+1000000007;
        }
        cout << m << endl;
    }
}
