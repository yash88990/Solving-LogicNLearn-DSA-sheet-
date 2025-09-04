#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	//method 1 
// 	int t;
// 	cin>>t;
// 	while(t--){
// 	    vector<int>arr(3);
// 	    for(int i = 0 ; i< 3 ; i++)cin>>arr[i];
// 	    sort(arr.begin() , arr.end());
// 	    cout<<arr[1]<<endl;
// 	}
// 	return 0;



//....method 2 
    int t;
	cin>>t;
	while(t--){
	    int a, b, c;
        cin >> a >> b >> c;

        if ((a >= b && a <= c) || (a >= c && a <= b)) {
            cout << a << endl;
        } else if ((b >= a && b <= c) || (b >= c && b <= a)) {
            cout << b << endl;
        } else {
            cout << c << endl;
        }
	}
	return 0;
	
	


}
