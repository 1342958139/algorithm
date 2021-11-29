#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int n): val(n),left(NULL),right(NULL){}
};

class Solution{
    public:
    vector<int> function(TreeNode* node)
    {
        stack<TreeNode *> td;
        vector<int> result;
        if(node != NULL) td.push(node);
        while(!td.empty())
        {
            TreeNode *cur = td.top();
            if(cur != NULL)
            {
                td.pop();
                if(cur->right) td.push(cur->right);
                if(cur->left)  td.push(cur->left);
                td.push(cur);
                td.push(NULL);
            }else{
                td.pop();
                cur = td.top();
                td.pop();
                result.push_back(cur->val);
            }
        }
        return result;
    }

    vector<int> function2(TreeNode * root)
    {   
        stack<TreeNode *> st;
        vector<int> result;
        if(root != NULL) st.push(root);

        while(!st.empty())
        {
            TreeNode* node = st.top();
            if(node != NULL)
            {
                st.pop();
                if(node->right) st.push(node->right);
                st.push(node);
                st.push(NULL);
                if(node->left) st.push(node->left);
            }
            else{
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }

    vector<int> function3(TreeNode *root)
    {
        stack<TreeNode *> st;
        vector<int> result;
        if(root != NULL) st.push(root);
        while(!st.empty())
        {
            TreeNode* node = st.top();
            if(node != NULL)
            {
                st.pop();
                st.push(node);
                st.push(NULL);
                if(node->right) st.push(node->right);
                if(node->left) st.push(node->left);
            }
            else{
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
};

int main()
{
    Solution d;
    vector<int > result;
    TreeNode a(1),b(2),c(3);
    a.right = &b;
    b.left = &c;

    result = d.function3(&a);
    for(int i = 0;i < result.size();i++)
        cout<<result[i]<<endl;

}