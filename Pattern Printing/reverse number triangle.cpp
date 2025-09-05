void nNumberTriangle(int n) {
    // Write your code here.
    for(int i = 1 ; i<= n ; i++){
        int a = 1;
        for(int j = n ; j >= i ; j--){
            cout<<a<<" ";
            a++;
        }
        cout<<endl;
    }
}
