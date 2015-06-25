class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> s;
        for(int i = 0; i < nums.size(); i++){
            if(s.find(nums[i]) == s.end()){
                s.insert(nums[i]);
            }else{
                return true;
            }

            if(i >= k){
                s.erase(nums[i-k]);
            }
        }
        return false;
    }
};
