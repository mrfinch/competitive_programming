#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t){
        int r,c;
        cin >> r >> c;
        if(r%2!=0 && c%2!=0){
            if(r>c){
                cout << "D" << endl;
            }
            else{
                cout << "R" << endl;
            }
        }
        else if(r%2==0 && c%2==0){
            if(r>c){
                cout << "U" << endl;
            }
            else{
                cout << "L" << endl;
            }
        }
        else if(r%2!=0 && c%2==0){
            if(r<c){
                cout << "R" << endl;
            }
            else{
                cout << "U" << endl;
            }
        }
        else{
            if(r<c){
                cout << "L" << endl;
            }
            else{
                cout << "D" << endl;
            }
        }
        t--;
    }
}
