/*
	Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

	For example:
	Given binary tree {3,9,20,#,#,15,7},
	    3
	   / \
	  9  20
	    /  \
	   15   7
	return its level order traversal as:
	[
	  [3],
	  [9,20],
	  [15,7]
	]
	confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution 
{
public:
    vector<vector<int> > levelOrder(TreeNode *root) 
    {
        vector<vector<int> > res;

        if(root == NULL)    
        	return res;

        queue<TreeNode *> q[2];
        int dep = 0;
        q[dep].push(root);

        while(!q[dep].empty())
        {
            vector<int> tmp;

            while(!q[dep].empty())
            {
                TreeNode *p = q[dep].front();
                q[dep].pop();
                tmp.push_back(p->val);

                if(p->left)     
                	q[dep^1].push(p->left);

                if(p->right)    
                	q[dep^1].push(p->right);
            }

            res.push_back(tmp);
            dep ^= 1;
        }

        return res;
    }
};

