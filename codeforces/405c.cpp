#include <iostream>
#include <stdio.h>
#include <vector>
#include <sstream>
using namespace std;
/*
void rowflip(int r,vector< vector<int> >& in){
    for(int i=1;i<in.size();i++){
        in[r][i]=1-in[r][i];
        //cout << in[r][i] << endl;
    }
    in[r][r]=1-in[r][r];
}

void colflip(int c,vector< vector<int> >& in){
    for(int i=1;i<in.size();i++){
        in[i][c]=1-in[i][c];
        //cout << in[i][c] << endl;;
    }
    in[c][c]=1-in[c][c];
}
*/
int main(){
    int n;
    scanf("%d",&n);
    //vector< vector<int> > inp(n+1,vector<int>(n+1,0));
    vector<int> inp(n+1,0);
    int i=1;
    int sum=0;
    while(i<n+1){
        int j=1;
        while(j<n+1){
            int t;
            scanf("%d",&t);
            if(i==j){
                inp[i]=t;
                sum=(sum+t)%2;
            }
            j++;
        }
        i++;
    }
    string output="";
    int q;
    scanf("%d",&q);
    while(q>0){
        int t;
        scanf("%d",&t);
        if(t==1){
            int r;
            scanf("%d",&r);
            //rowflip(r,inp);
            sum=(((sum-inp[r])%2)+2)%2;;
            inp[r]=1-inp[r];
            sum=(((sum+inp[r])%2)+2)%2;;
        }
        else if(t==2){
            int c;
            scanf("%d",&c);
            //colflip(c,inp);
            sum=(((sum-inp[c])%2)+2)%2;
            inp[c]=1-inp[c];
            sum=(((sum+inp[c])%2)+2)%2;
        }
        else{
            //int out=0;
            /*for(int i=1;i<n+1;i++){
                for(int j=1;j<n+1;j++){
                    out=(out+(inp[i][j]*inp[j][i]))%2;
                }
            }*/
            /*
            for(int i=1;i<n+1;i++){
                out=(out+inp[i])%2;
            }*/
            printf("%d",sum);
            /*stringstream ss;
            ss << out;
            output+=ss.str();*/
        }
        q--;
    }
    /*for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            cout << inp[i][j] << " ";
        }
        cout << endl;
    }*/
    //printf("%s",output.c_str());
}
