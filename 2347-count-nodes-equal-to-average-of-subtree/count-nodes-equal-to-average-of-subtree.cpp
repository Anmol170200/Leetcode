class Solution {
private:
    pair<int, int> helper(TreeNode* root, int& result) {
        if (!root) return { 0, 0 };

        auto l = helper(root->left, result);
        auto r = helper(root->right, result);

        int sum = l.first + r.first + root->val;
        int num = l.second + r.second + 1;

        if (sum / num == root->val)
            result++;
        
        return { sum, num };
    }

public:
    int averageOfSubtree(TreeNode* root) {
        int result = 0;
        (void)helper(root, result);
        return result;
    }
};