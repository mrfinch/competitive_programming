#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(){
    while(true){
        string s;
        cin >> s;
        if(s[0]=='0' && s[1]=='0' && s[3]=='0'){
            break;
        }
        long long n;
        n=s[0]-'0'*10+s[1]-'0';
        string a="";
        a+=s[0];
        a+=s[1];

        for(int i=0;i<s[3]-'0';i++){
            a+="0";
        }
        //cout << a << endl;
        long long x=atoi(a.c_str());
        int cnt=0;
        long long t=x;
        while(x>1){
            cnt++;
            x=x>>1;
        }
        //cout << x << " " << cnt <<endl;;
        long long m=2*(t-(1<<(cnt)))+1;
        cout << m << endl;

    }

}
