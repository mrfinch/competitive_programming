#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n){
        double a,b,c,d;
        cin >>a>>b>>c>>d;
        double res;
        double s=(a+b+c+d)/2;
        res=(s-a)*(s-b)*(s-c)*(s-d);
        double out=sqrt(res);
        cout << setprecision(12);
        cout << out << endl;
        n--;
    }
}
