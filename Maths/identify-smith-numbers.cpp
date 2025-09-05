int digitsum(int n){
    int sum = 0;
    while(n != 0){
        int digit = n % 10;
        sum += digit;
        n /= 10;
    }
    return sum;
}

bool prime(int n){
   if(n <= 1)return false;
   for(int i = 2 ; i * i < n ; i++)
        if(n % i == 0)return false;
   return true;
}
int solve(int n) {
    if(prime(n))return 0;
    int originalsum = digitsum(n);
    int factorsum = 0;
    int num = n;
    //factor out 2s
    while (num % 2 == 0) {
        factorsum += digitsum(2);
        num /= 2;
    }
    // Factor out odd primes starting from 3
    for (int i = 3; i * i <= num; i += 2) {
        while (num % i == 0) {
            factorsum += digitsum(i);
            num /= i;
        }
    }
    if (num > 1) {
        factorsum += digitsum(num);
    }
    
    // Compare the two sums
    return (originalsum == factorsum) ? 1 : 0;

}
