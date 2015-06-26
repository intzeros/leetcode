/* -------------------- Solution 1: Sort -------------------- */
typedef struct Node {
    int num;
    int idx;
    Node(int _num, int _idx) : num(_num), idx(_idx) {}
}Node;

int cmp(const Node &n1, const Node &n2){
    if(n1.num == n2.num){
        return n1.idx < n2.idx;
    }else{
        return n1.num < n2.num;
    }
}

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<Node> vec;
        for(int i = 0; i < nums.size(); i++){
            vec.push_back(Node(nums[i], i));
        }
        sort(vec.begin(), vec.end(), cmp);
        for(int i = 0; i < vec.size(); i++){
            int j = i+1;
            while(j < vec.size() && (long long)vec[j].num - (long long)vec[i].num <= t){
                if(abs(vec[i].idx - vec[j].idx) <= k){
                    return true;
                }
                j++;
            }
        }
        return false;
    }
};


/* -------------------- Solution 2: Hash -------------------- */
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t < 0) return false;

        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            int key = nums[i] / max(1, t);
            //由于nums[i]可能为负数，故还要加上 abs(nums[i]-m[key])<=t 的限制条件.
            //e.g. nums={-3,3}, k=2, t=4.
            if(m.find(key) != m.end() && abs((long)nums[i] - (long)m[key]) <= t ||
               m.find(key-1) != m.end() && abs((long)nums[i] - (long)m[key-1]) <= t ||
               m.find(key+1) != m.end() && abs((long)nums[i] - (long)m[key+1]) <= t){
                return true;
            }else{
                m.insert(make_pair(key, nums[i]));  // or: pair<int,int>(key, nums[i])
            }

            if(i >= k){
                m.erase(nums[i-k] / max(1,t));
                //注：以上不能写成 m.erase(m.begin());
                //因unordered_map是无序的，不能保证m.begin()对应的就是nums[0]的值.
            }
        }
        return false;
    }
};
