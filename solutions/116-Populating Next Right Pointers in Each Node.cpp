/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
/* -------------------- Solution 1: BFS -------------------- */
/*class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;

        queue<TreeLinkNode *> que;
        que.push(root);
        TreeLinkNode *now, *pre = NULL;
        int i = 0, k = 1;
        while(!que.empty()){
            now = que.front();
            que.pop();

            if(pre) pre->next = now;

            i++;
            if(i == k){
                now->next = NULL;
                i = 0;
                k *= 2;
                pre = NULL;
            }else{
                pre = now;
            }

            if(now->left) que.push(now->left);
            if(now->right) que.push(now->right);
        }
    }
};*/

/* -------------------- Solution 2: next pointer -------------------- */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *p = root, *q;
        while(p){   //p指向树中每一层的第一个节点
            q = p;
            while(q){   //用q遍历每一层的节点
                if(q->left){
                    q->left->next = q->right;
                    if(q->right){
                        if(q->next){
                            q->right->next = q->next->left;
                        }else{
                            q->right->next = NULL;
                        }
                    }
                }
                q = q->next;
            }
            p = p->left;
        }
    }
};
