#include <iostream>

using namespace std;

int main(){
    int e1,f1,s1,m1,e2,f2,s2,m2;
    while(true){
        cin>>e1>>f1>>s1>>m1>>e2>>f2>>s2>>m2;
        if(e1==-1 && f1==-1 && s1==-1 && m1==-1){
            break;
        }
        if(e1==0 && f1==0 && s1==0 && m1==0){
            cout << 0 << " " << 0 << " " << 0 << " " << 0 << endl;
            continue;
        }
        int e3,f3,s3,m3;
        for(int i=1;i<1001;i++){
            e3=i*e2;f3=i*f2;s3=i*s2;m3=i*m2;
            if(e3>=e1 && f3>=f1 && s3>=s1 && m3>=m1){
                //cout << i << endl;
                break;
            }
        }
        cout << e3-e1 << " " << f3-f1 << " " <<s3-s1 << " " << m3-m1 << endl;
    }
}
