pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
    int s = 0 , e = n-1 , f = -1 , c = -1;
    //floor
    while(s <= e){
        int m =  s + ( e - s)/2;
        if(a[m] <= x){
            f = a[m];
            s = m +1;
        }else e = m - 1;
    }
    s = 0 , e = n-1;
    //ceil
    while(s <= e){
        int m = s + ( e - s )/2;
        if(a[m] >= x){
            c = a[m];
            e = m - 1;
        }else s = m + 1;
    }
    return {f , c};
}
