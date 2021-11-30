#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
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
    vector<int> function(TreeNode* root)
    {
        queue<TreeNode *> que;
        vector<int > result;
        TreeNode* node;
        if(root != NULL) que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            for(int i = 0;i < size;i++)
            {
                node = que.front();
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            result.push_back(node->val);
        }
        return result;
    }
};

int main()
{
    Solution d;
    vector<int > result;
    TreeNode a(1),b(2),c(3),e(5),f(4),g(10);

    a.left = &b;
    a.right = &c;
    b.right = &e;
    c.right = &f;
    f.left = &g;

    result = d.function(&a);
    for(int i = 0;i < result.size();i++)
    {
        cout<<result[i]<<endl;
    }

}