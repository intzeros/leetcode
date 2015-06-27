/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
/*class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *p = root;
        while(p){   //p指向树中每一层的第一个节点
            TreeLinkNode *q = p, *pre = NULL;   //用q遍历每一层的节点
            while(q){
                if(q->left){
                    if(pre) pre->next = q->left;

                    if(q->right){
                        q->left->next = q->right;
                        pre = q->right;
                    }else{
                        pre = q->left;
                    }
                }else if(q->right){
                    if(pre) pre->next = q->right;

                    pre = q->right;
                }
                q = q->next;
            }

            while(p){
                if(p->left){
                    p = p->left;
                    break;
                }else if(p->right){
                    p = p->right;
                    break;
                }else {
                    p = p->next;
                }
            }
        }
    }
};*/

/* ----------------- 简化版本 ------------------- */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *p = root;
        while(p){   //p指向树中每一层的第一个节点
            TreeLinkNode *q = p, *pre = NULL;   //用q遍历每一层的节点
            p = NULL;
            while(q){
                if(q->left){
                    if(!p) p = q->left;
                    q->left->next = q->right;
                    if(pre) pre->next = q->left;
                    pre = q->left;
                }
                if(q->right){
                    if(!p) p = q->right;
                    if(pre) pre->next = q->right;
                    pre = q->right;
                }
                q = q->next;
            }
        }
    }
};
