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
    string num2str(int num){
        if(num == 0) return "0";
        string rst = "";
        if(num < 0){
            rst += "-";
            num *= -1;
        }
        char str[10];
        int i = 0;
        while(num){
            str[i++] = num % 10 + '0';
            num /= 10;
        }
        char str2[10];
        int j = 0, n = i;
        while(j < n) str2[j++] = str[--i];
        str2[n] = '\0';
        return rst + string(str2);
    }

    // 注意不能修改path的值
    void createTreePaths(TreeNode* root, vector<string> &paths, string &path){
        if(root == NULL) return ;
        if(root->right == NULL && root->left == NULL){
            paths.push_back(path + num2str(root->val));
            return ;
        }

        string new_path = path + num2str(root->val) + "->";
        if(root->left != NULL){
            createTreePaths(root->left, paths, new_path);
        }
        if(root->right != NULL){
            createTreePaths(root->right, paths, new_path);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        string path = "";
        createTreePaths(root, paths, path);
        return paths;
    }
};
