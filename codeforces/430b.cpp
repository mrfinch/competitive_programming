#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,k,x;
    cin >> n >> k >> x;
    vector<int> inp(n,0);
    int m=0;
    while(m<n){
        cin >> inp[m];
        m++;
    }
    int temp=-1;
    for(int i=0;i<inp.size()-1;i++){
        if(inp[i]==x && inp[i+1]==x){
            temp=i;
            break;
        }
    }
    if(temp==0){
        for(int i=1;i<inp.size()-1;i++){
            if(inp[i]==x && inp[i+1]==x){
                temp=i;
                break;
            }
        }
    }
    int cnt=0;
    //cout << temp << " temp" << endl;
    if(temp!=-1){
        int temp2=0;
        for(int i=temp;i<inp.size();i++){
            if(inp[i]==x){
                temp2=i;
            }
            else{
                break;
            }
        }
        //cout << temp2 << " temp2" << endl;
        cnt+=temp2-temp+1;
        inp.erase(inp.begin()+temp,inp.begin()+temp2+1);
        /*for(int i=0;i<inp.size();i++){
            cout << "in " << inp[i] << endl;
        }*/
        while(true){
            temp=-1;
            temp2=-1;
            if(inp.size()<3)
                break;
            for(int i=0;i<inp.size()-2;i++){
                if(inp[i]==inp[i+1] && inp[i+1]==inp[i+2]){
                    temp=i;
                    break;
                }
            }
            //cout << temp << " astemp" << endl;
            if(temp==-1)
                break;
            int k=temp;
            while(k<inp.size()-1){
                if(inp[k]==inp[k+1]){
                    temp2=k;
                    k++;
                }
                else
                    break;
            }
            inp.erase(inp.begin()+temp,inp.begin()+temp2+2);
            cnt+=temp2-temp+2;
        }
        cout << cnt << endl;
    }
    else{
        cout << 0 << endl;
    }

}
