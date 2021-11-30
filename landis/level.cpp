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
    vector<vector<int>> function(TreeNode* root)
    {
        queue<TreeNode* > que;
        vector<vector<int>> result;
        if(root != NULL) que.push(root);
        while(!que.empty())
        {
            int size = que.size();
            vector<int> vec;
            for(int i = 0;i < size;i++)
            {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if(node ->left) que.push(node->left);
                if(node->right) que.push(node->right);
            } 
            result.push_back(vec);  
        }
        return result;
    }
};

int main()
{
    Solution d;
    vector<vector<int >> result;
    TreeNode a(3),b(9),c(20),e(15),f(7);

    a.left = &b;
    a.right = &c;
    c.left = &e;
    c.right = &f;

    result = d.function(&a);
    reverse(result.begin(),result.end());
    
    for(int i = 0;i < result.size();i++ )
    {
        for (int j = 0; j < result[i].size();j++)
        {
            cout<<result[i][j]<<"   ";
        }
        cout<<endl;
    }

}