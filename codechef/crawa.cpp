#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t){
        int x,y;
        cin >> x >> y;
        int mn,mx;
        if(x==0 && y==0){
            cout << "YES" << endl;
            t--;
            continue;
        }
        if(x%2==1 && x>=0){
            int t=(x-1)/2;
            mn=-2*t;
            mx=2*t+2;
            if(y<=mx && y>=mn){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else if(x<0){
                //int m=abs(x);
                if(x%2==0){
                    int t=abs(x)/2;
                    mn=-1*2*t;
                    mx=2*t;
                    if(y<=mx && y>=mn){
                        cout << "YES" << endl;
                    }
                    else{
                        cout << "NO" << endl;
                    }
                }
            }
        else if(y%2==0 && y>=0){
            mn=-1*y;
            mx=y+1;
            if(x<=mx && x>=mn){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else if(y%2==0 && y<0){
            mn=-1*y;
            mx=y+1;
            if(x<=mx && x>=mn){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else{
            cout << "NO" << endl;
        }

        t--;
    }
}
