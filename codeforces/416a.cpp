#include <iostream>
#include <string>

using namespace std;

int main(){
    int mi=2*(1e-9);
    int ma=2*(1e9);
    int n;
    cin >> n;
    int i=0;
    while(i<n){
        int x;
        string s,yn;
        cin >> s >> x >> yn;
       // cout << s << x << yn << endl;
        if((s==">" && yn=="Y") || (s=="<=" && yn=="N")){
     //       cout << 1 << endl;
            if(x+1>mi){
                mi=x+1;
            }
        }
        else if((s==">=" && yn=="Y") || (s=="<" && yn=="N")){
     //       cout << 2 << endl;
            if(x>mi){
                mi=x;
            }
        }
        else if((s=="<" && yn=="Y") || (s==">=" && yn=="N")){
   //         cout << 3 << endl;
            if(x-1<ma){
                ma=x-1;
            }
        }
        else{
 //               cout << 4 << endl;
            if(x<ma){
                ma=x;
            }
        }
        i++;
    }
    //cout << mi << " " << ma << endl;
    if(ma<mi && ma>=0 && mi>=0){
        cout << "Impossible" << endl;
    }
    else if(ma<0 && mi<0 && ma>mi){
        cout << "Impossible";
    }
    else{
        cout << mi << endl;
    }
}
