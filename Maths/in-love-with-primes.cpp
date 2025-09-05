#include <iostream>
using namespace std;

bool isprime(int n){
    if(n <= 1)return false;
    for(int i = 2 ; i * i <= n ; i++){
        if( n % i == 0)return false;
    }
    return true;
}

bool canBeDivided(int n ){
    for(int i = 2 ;i <= n/2 ; i++){
        if(isprime(i) && isprime(n - i))return true;
    }
    return false;
} 


int main() {
   int tc;
   cin>>tc;
   while(tc--){
    int n ;
    cin>>n;
    if(canBeDivided(n))cout<<"Deepa"<<endl;
    else cout<<"Arjit"<<endl;
   }

    return 0;
}
