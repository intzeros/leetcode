class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int le = 0, ri = nums.size()-1, mid;
        while(le <= ri){
            mid = (le + ri) >> 1;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                le = mid+1;
            }else{
                ri = mid-1;
            }
        }
        if(target > nums[mid]) return mid+1;
        else return mid;
    }
};
