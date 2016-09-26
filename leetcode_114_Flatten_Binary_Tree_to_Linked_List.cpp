/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

Subscribe to see which companies asked this question

前序遍历的非递归方法
*/

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
    void flatten(TreeNode* root) {
        int _stack_size = 1;
        TreeNode* p = root;
        TreeNode* ret[5000] = { NULL};
        int ret_size = 0;
        
        _stack[0] = NULL;
        while(NULL != p )
        {
            ret[ret_size++] = p;
            
            if(NULL != p->right)
            {
                _stack[_stack_size++] = p->right;
            }
            
            if(NULL != p->left)
            {
                p = p->left;
            }
            else
            {
                p = _stack[--_stack_size];
                _stack[_stack_size] = NULL;
            }
        }
        
       for(int index = 0; index < ret_size; index++)
       {
           ret[index]->left = NULL;
           ret[index]->right = ret[index+1];
       }
        root = ret[0];
    }
private:
    TreeNode* _stack[5000] = {NULL};
};
