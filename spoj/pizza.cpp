#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    int i=0;
    int a14=0,a12=0,a34=0;

    while(i<n){
        string s;
        cin >> s;
        if(s[0]=='1' && s[2]=='4'){
            a14++;
        }
        else if(s[0]=='1' && s[2]=='2'){
            a12++;
        }
        else{
            a34++;
        }
        i++;
    }
    int out=0;
    while(a34 && a14){
        out++;
        a34--;
        a14--;
    }

    while(a14 && a12){
        out++;
        a12--;
        if(a14>1){
            a14-=2;
        }
        else{
            a14--;
        }
    }
    out+=(a12/2);
    a12=a12%2;
    out+=(a14/4);
    a14=a14%4;

    out+=a12;
    out+=a14;
    out+=a34;
    out++;
    cout << out << endl;
}
