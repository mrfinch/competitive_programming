#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

int gcd(int a,int b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}
int main(){
    int t;
    cin >> t;
    while(t){
        int a;
        string b;
        cin >> a >> b;
        int rem;
        string q="";
        for(int i=0;i<b.size();i++){
            if(a==0){
                break;
            }
            q=q+b[i];
            int m=atoi(q.c_str());
            if(m>=a){
                m=m%a;
                stringstream ss;
                ss << m;
                q=ss.str();
            }
            else{

            }
        }
        rem=atoi(q.c_str());
        if(a!=0){
            int out=gcd(a,rem);
            cout << out << endl;
        }
        else{
            cout << b << endl;
        }
        t--;
    }
}
