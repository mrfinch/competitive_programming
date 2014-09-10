#include <iostream>
#include <string>

using namespace std;

int main(){
    string inp;
    cin >> inp;
    int i=0;
    long long cnt=0;
    int temp=0;
    size_t f;
    while((f=inp.find("bear",i))!=string::npos){
        if(i==0){
            //cnt++;
            temp=f;
            f++;
            //cout << f << " " << inp.size() << endl;
            cnt+=f*(inp.size()-(temp+3));
            i++;
        }
        else{
            cnt+=(f-(temp))*(inp.size()-(f+3));
            i=f+1;
            temp=f;
        }
    }
    cout << cnt << endl;
}
