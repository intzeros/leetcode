//class Solution {
//public:
//    bool containsDuplicate(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        for(int i = 1; i < nums.size(); i++){
//            if(nums[i-1] == nums[i]){
//                return true;
//            }
//        }
//        return false;
//    }
//};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(int i = 0; i < nums.size(); i++){
            if(s.find(nums[i]) == s.end()){
                s.insert(nums[i]);
            }else{
                return true;
            }
        }
        return false;
    }
};
