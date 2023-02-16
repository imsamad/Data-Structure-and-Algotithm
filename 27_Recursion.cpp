#include<iostream>
using namespace std;

int naturalSum(int num){
    return !num ? 0 : naturalSum(num-1)  + num;
}

int factorial(int num) {
    return num <=1 ? 1 : factorial(num-1) * num;
}

int power(int num,int expo) {
    return expo == 1 ? num : power(num,expo - 1) * num;
}

int fibonacci(int n) {
    static int * memo = new int[n];
    int x;
    if(n<=1){
        memo[n]=n;
        cout<<n<<" ";
        return n;
    }

    if(!memo[n-2]) memo[n-2] = fibonacci(n-2); 
    if(!memo[n-1]) memo[n-1] = fibonacci(n-1); 
    int res = memo[n-2] + memo[n-1];
    cout<<res<<" "; 
    return res;
}

long double taylor(long double x,long double n) {
    static long double xP=1,fac = 1;
    
    if(n==0) return 1;
    
    long double res = taylor(x,n-1);

    xP*=x; fac*=n;

    return res + xP/fac;
}

long double taylorByHorner(long double x,long double n) {
    static long double res = 1;
    if(!n) return res;
    res=1+res * (x/n);
    return taylorByHorner(x,n-1);;
}

int nCr(int n,int r) {
    if(n==r || r==0) return 1;

    return nCr(n-1,r-1) + nCr(n-1,r);
}

// permutaion of string
// hanoiTower

int main() {
    cout<<"Naural Sum "<<naturalSum(3)<<endl;
    cout<<"factorial "<<factorial(4)<<endl;
    cout<<"power "<<power(3,3)<<endl;
    cout<<"fibonacci "<<fibonacci(4)<<endl;
    cout<<"nCr "<<nCr(4,2)<<endl;
    cout<<"taylor "<<taylor(10,10)<<endl;
    cout<<"taylorByHorner "<<taylorByHorner(10,10)<<endl;
    return 0;
}