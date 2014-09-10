#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t){
        string s;
        cin >> s;
        int all9=true;
        vector<int> a(s.size());
        for(int i=0;i<s.size();i++){
            a[i]=s[i]-'0';
            if(s[i]-'0'!=9){
                all9=false;
            }
        }
        if(all9){
            printf("1");
            for(int i=0;i<s.size()-1;i++){
                printf("0");
            }
            printf("1\n");
        }
        else{
            if(s.size()==1){
                cout << a[0]+1 << endl;
            }
            else{
                int mid,mid2,i,j;
                if(s.size()%2==0){
                    j=s.size()/2;
                    i=j-1;
                    mid=i;
                }
                else{
                    i=s.size()/2;
                    j=i;
                    mid=i;
                }
                mid2=j;
                while(i>=0){
                    //cout << " hf " << i << endl;
                    if(a[i]==a[j]){
                        i--;j++;
                    }
                    else{
                        break;
                    }
                }
                //cout << i << " gnnf" << endl;
                int temp=mid;
                if(i==-1){
                    //it is a palin find next palin
                    int carry = (a[temp]+1)/10;
                    a[temp]=(a[temp]+1)%10;
                    temp--;
                    if(carry!=1){
                        int t1=mid;int t2=mid2;
                        while(t1>=0){
                            a[t2]=a[t1];
                            t2++;t1--;
                        }
                        for(int i=0;i<a.size();i++){
                            printf("%d",a[i]);
                        }
                        printf("\n");
                    }
                    else{
                        while(carry==1 && temp>=0){
                            carry=(a[temp]+1)/10;
                            a[temp]=(a[temp]+1)%10;
                            temp--;
                        }
                        int t1=mid;int t2=mid2;
                        while(t1>=0){
                            a[t2]=a[t1];
                            t2++;t1--;
                        }
                        for(int i=0;i<a.size();i++){
                            printf("%d",a[i]);
                        }
                        printf("\n");
                    }

                }
                else{
                    if(a[i]>a[j]){
                        int t1=mid;int t2=mid2;
                        while(t1>=0){
                            a[t2]=a[t1];
                            t2++;t1--;
                        }
                        for(int i=0;i<a.size();i++){
                            printf("%d",a[i]);
                        }
                        printf("\n");
                    }
                    else{
                        int temp=mid;
                        int carry = (a[temp]+1)/10;
                        a[temp]=(a[temp]+1)%10;
                        temp--;

                        while(carry==1 && temp>=0){
                            carry=(a[temp]+1)/10;
                            a[temp]=(a[temp]+1)%10;
                            temp--;
                        }
                        int t1=mid;int t2=mid2;
                        while(t1>=0){
                            a[t2]=a[t1];
                            t2++;t1--;
                        }
                        for(int i=0;i<a.size();i++){
                            printf("%d",a[i]);
                        }
                        printf("\n");
                    }
                }
            }

        }
        t--;
    }
}
