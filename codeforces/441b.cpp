#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct valera{
    valera(int a,int b){
        day=a;
        fruit=b;
    }
    int day;
    int fruit;
};

bool func(valera a,valera b){
    if(a.day!=b.day)
        return a.day<b.day;
    else
        return a.fruit>b.fruit;
}
int main(){
    int n,v;
    cin >> n >> v;
    int max=0;
    int i=0;
    vector<valera> inp(n+1,valera(0,0));
    int t1,t2;
    while(i<n){
        cin >> t1 >> t2;
        if(t1>max){
            max=t1;
        }
        inp[i+1].day=t1;
        inp[i+1].fruit=t2;
        i++;
    }


    sort(inp.begin()+1,inp.end(),func);
    /*for(int i=1;i<n+1;i++){
        cout << inp[i].day << " " << inp[i].fruit << endl;
    }
*/
    int total=0;
    for(int i=1;i<max+2;i++){
        int ii=1;
        int sum=0;
        while(sum<v && ii<n+1){
            if(inp[ii].fruit==0){
                ii++;
                //cout << "e " << inp[ii].fruit << endl;
            }
            else if(inp[ii].day+1<i){
                ii++;

                //cout << "g " << inp[ii].fruit << endl;
            }
            else if(inp[ii].fruit>=(v-sum)){
                inp[ii].fruit-=(v-sum);
                sum=v;
                //cout << "h " << inp[ii].fruit << endl;
            }
            else{
                sum+=inp[ii].fruit;

                inp[ii].fruit=0;
                //cout << "t " << inp[ii].fruit << endl;
                ii++;
            }
        }
        total+=sum;
        //cout << sum << endl;
    }
    cout << total << endl;
    /*
    for(int i=1;i<n+1;i++){
        cout << inp[i].day << " " << inp[i].fruit << endl;
    }
    */
}
