#include <iostream>

using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    int a2=0;
    int a3=0;
    int a5=0;
    int b2=0;
    int b3=0;
    int b5=0;
    while(a%2==0){
        a=a/2;
        a2++;
    }
    while(a%3==0){
        a=a/3;
        a3++;
    }
    while(a%5==0){
        a=a/5;
        a5++;
    }
    while(b%2==0){
        b=b/2;
        b2++;
    }
    while(b%3==0){
        b=b/3;
        b3++;
    }
    while(b%5==0){
        b=b/5;
        b5++;
    }
    if(a!=b){
        cout << -1 << endl;
    }
    else{
        int cnt=0;
        if(a2>b2){
            cnt+=(a2-b2);
        }
        else{
            cnt+=(b2-a2);
        }
        if(a3>b3){
            cnt+=(a3-b3);
        }
        else{
            cnt+=(b3-a3);
        }
        if(a5>b5){
            cnt+=(a5-b5);
        }
        else{
            cnt+=(b5-a5);
        }
        cout << cnt << endl;
    }
}
