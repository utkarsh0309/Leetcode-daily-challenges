class Solution
{
    public:
        void getPath(TreeNode *root, vector<TreeNode*> &path, vector<TreeNode*> current, TreeNode *target)
        {
            if (!root) return;

            if (root == target)
            {
                current.push_back(root);
                path = current;
                return;
            }

            current.push_back(root);
            getPath(root->left, path, current, target);
            getPath(root->right, path, current, target);
            current.pop_back();
        }
    void find(TreeNode *root, TreeNode *never, int level, int k, vector<int> &ans)
    {
        if (!root or root == never) return;

        if (level == k)
        {
            ans.push_back(root->val);
            return;
        }

        find(root->left, never, level + 1, k, ans);
        find(root->right, never, level + 1, k, ans);
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> ans;
        vector<TreeNode*> path, current;
        getPath(root, path, current, target); //(step 1)

        int n = path.size();
        int start = n - k, v = 1; //(step 3)
	
		//(nullptr because no element below the target node is processed)
        find(path[n - 1], nullptr, 0, k, ans); //(step 2)
        
        for (int i = n - 2; i >= 0 and n >= start; i--) //(step 4)
        {
			//(step 5 & 6, exclude path[i+1] which is already processed)
            find(path[i], path[i + 1], 0, k - v, ans); 
            v++;
        }
        return ans; //(step 7)
    }
};