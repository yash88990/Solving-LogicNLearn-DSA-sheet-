int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.
    int start = 0 , end = n-1 , ans = n;
    while(start <= end){
        int  mid = start + (end - start )/2;
        if(arr[mid] > x){
            ans = mid;
            end = mid - 1;

        }else{
            start = mid + 1;
        }
    }	
    return ans;
}
