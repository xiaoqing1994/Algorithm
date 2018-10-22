class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        //中序遍历, iterative method
        vector<int> nodes;
        stack<TreeNode*> todo;
        TreeNode* cur = root;
        while (cur || !todo.empty()) {
            if (cur) {
                todo.push(cur);
                // cout<<"cur is not null "<<cur->val<<endl;
                cur = cur -> left;
            }
            else {
                cur = todo.top();
                // cout<<"top todo "<<cur->val<<endl;
                todo.pop();
                nodes.push_back(cur -> val);
                cur = cur -> right;
            }
        }
        return nodes;

    }
};

/*To see all the solution see
https://leetcode.com/explore/learn/card/queue-stack/232/practical-application-stack/1383/discuss/31231/C++-Ierative-Recursive-and-Morris-Traversal*/
