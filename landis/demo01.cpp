#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
    public:
    void traversal(TreeNode* cur,vector<int>& vec)
    {
        if(cur == NULL) return;
        traversal(cur->left,vec);
        vec.push_back(cur->val);
        traversal(cur->right,vec);
    }
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> result;
        traversal(root,result);
        return result;
    }
};

class Solution2{
    public:
    vector<int > preorderTraversal(TreeNode* root)
    {
        stack<TreeNode*> st;
        vector<int> result;
        if(root == NULL) return result;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        return result;
    }

    vector<int> preorderTraversal2(TreeNode* root)
    {
        vector<int> result;
        stack<TreeNode* >st;
        TreeNode* cur = root;
        while(cur != NULL || !st.empty())
        {
            if(cur != NULL)
            {
                st.push(cur);
                cur = cur->left;
            }else{
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        return result;
    }

    vector<int> preorderTraversal3(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode* > st;
        if(root == NULL) return result;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

int main()
{
    vector<int > b;
    TreeNode a(1),d(2),e(3);
    Solution c;
    Solution2 f;
    a.right = &d;
    d.left = &e;

    //b = c.preorderTraversal(&a);
    
    b = f.preorderTraversal3(&a);
    for(int i = 0;i < b.size();i++)
       cout << b[i] << endl;
}