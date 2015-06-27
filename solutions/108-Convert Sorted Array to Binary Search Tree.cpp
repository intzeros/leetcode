/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* create(vector<int>& nums, int le, int ri){
        if(le > ri) return NULL;

        int mid = (le + ri) >> 1;
        TreeNode *p = new TreeNode(nums[mid]);
        TreeNode *left = create(nums, le, mid-1);
        TreeNode *right = create(nums, mid+1, ri);
        p->left = left;
        p->right = right;
        return p;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return create(nums, 0, nums.size()-1);
    }
};
