#include <iostream>
#include <math.h>
using namespace std;
//Not complete-TLE
long long gcd(int a,int b){
    //cout << a << " " << b << endl;
    if(a==b){
        return a;
    }
    else if(a>b){
        gcd(a-b,b);
    }
    else{
        gcd(a,b-a);
    }
}
int main(){
    long long t;
    cin >> t;
    while(t>0){
        long long n,m;
        cin >> n >> m;
        long long odd=0;
        long long mm = max(n,m);
        long long mim = min(n,m);
        if(mm%2==1){
            long long t1=mm/2;
            long long t2=(mm/2)+1;
            //bool x=true;
            if(mim%2==1){
                odd+=(mim/2+1)*t1;
                odd+=(mim/2)*t2;
            }
            else{
                odd+=(mim/2)*t1;
                odd+=(mim/2)*t2;
            }
            /*for(int i=1;i<=mim;i++){
                if(x){
                    odd+=t1;
                    x=false;
                }
                else{
                    odd+=t2;
                    x=true;
                }
            }*/
        }
        else{
            odd=mim*(mm/2);
        }
        /*
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=m;j++){
                if(((i+j)%2)==1){
                    odd++;
                }
            }
        }
        */
        long long total=n*m;
        //long long temp=max(n,m);
        /*for(int i=2;i<=odd;i++){
            while(odd%i==0 && total%i==0){
                odd/=i;
                total/=i;
            }
        }*/
        cout << "gth" << odd << " " << total;
        if(odd!=0 && total!=0){
        long long g = gcd(odd,total);
        odd = odd/g;
        total = total/g;
        }
        cout << "gth";
        cout << odd << "/" << total << endl;
        t--;
    }
}
