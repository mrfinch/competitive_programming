#include <iostream>
#include <stdio.h>
using namespace std;

int print(double t,int x,double a){
    if(x==1){
        printf("%.9f %.9f\n",a-t,0.0);
    }
    else if(x==2){
        printf("%.9f %.9f\n",a,a-t);
    }
    else if(x==3){
        printf("%.9f %.9f\n",t,a);
    }
    else{
        printf("%.9f %.9f\n",0.0,t);
    }
    //cout << "hr" << endl;
    return 0;
}

int main(){
    double a,d;
    cin >> a >> d;
    int n;
    cin >> n;
    int m=0;
    int k=1;
    double y=d;
    while(m<n){
        d=(k*1.0)*y;
        k++;
        double sum=0;
        int x=1;
        //cout << int(d) << endl;
        while(true){
            sum+=a;
            //cout << sum << endl;
            double t=0;
            if(sum>=d){
                t=sum-d;
                print(t,x,a);
                //cout << t << "    " << x << endl;
                break;
            }
            x++;
            if(x==5){
                x=1;
            }

        }
        //cout << "m " << m << endl;
        m++;
    }
}
