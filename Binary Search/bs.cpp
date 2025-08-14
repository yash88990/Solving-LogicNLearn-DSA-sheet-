// iterative way

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0 , end = nums.size() -1;
        while(start <= end){
            int mid = start + ( end - start)/2;
            if(nums[mid] == target)return mid;
            else if(nums[mid] < target) start = mid + 1 ;
            else // nums[mid] > target
                end = mid - 1;
                
        }
        return -1;
        
    }
};



// reccursion 
class Solution {
public:
    int solve(vector<int>& nums, int target , int start , int end){
        if(start > end)return -1;
        int mid = start +(end - start )/2;
        if(nums[mid] == target)return mid;
        else if(nums[mid] < target){
            return solve(nums , target , mid + 1 , end);
        }else{
            return solve(nums , target , start , mid - 1);
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return solve(nums , target , 0 , nums.size()-1);
    }
};


