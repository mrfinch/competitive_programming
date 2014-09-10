#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int gcd(long long a,long long b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> inp(n);
    int i=0;
    while(i<n){
        scanf("%d",&inp[i]);
        i++;
    }
    sort(inp.begin(),inp.end());
    long long sum=0;
    long long t=0;
    long long c=0;
    do{
        for(int i=0;i<inp.size();i++){
            if(i==0){
                t+=inp[i];
            }
            else{
                t+=abs(inp[i]-inp[i-1]);
            }
        }
        sum+=t;
        t=0;
        c++;
    }while(next_permutation(inp.begin(),inp.end()));
    if(sum!=0 && c!=0){
        long long g=gcd(sum,c);
        cout << sum/g << " " << c/g << endl;
    }
    else{
        cout << sum << " " << c << endl;
    }
}
