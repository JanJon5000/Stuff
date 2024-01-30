#include <iostream>
#include <math.h>
using namespace std;

float multi_factorial(int n, int multi = 1){
    float ans = 1;
    for(int i=2;i<=n;i+=multi){
        ans *= i;
    }
    return ans;
}

int sub_factorial(int n, int multi = 1){
    int ans = multi_factorial(n);
    double s = 0;
    for(int k=0;k<=n;k++){
        s += pow(-1, k)/multi_factorial(k);
    }
    return ans*s;
}

int prime_num(int n){
    int ans = 1;
    for(int i = 1; i <= pow(2, n); i++){
        double s = 0;
        for(int j=1;j<=i;j++){
            s += floor(cos((3.14159265359*(multi_factorial(j-1)+1))/j));
        }
        ans += floor(pow(n/s, 1/n));
    }
    return ans;
}

// int prime_num2(int n){
//     return floor((int(multi_factorial(n, 1))%(n+1))/n)*(n-1)+2;
// }

int main(){
    for(int i=1;i<=10;i++){
        cout << i << ' ' << prime_num(i) << endl;
    }
    return 0;
}