void seeding(int n) {
	// Write your code here.
	for(int i = 1 ; i <= n ; i++){
		for(int j = n ; j >= i ; j--){
			cout<<"* ";
		}
		cout<<endl;
	}
}
