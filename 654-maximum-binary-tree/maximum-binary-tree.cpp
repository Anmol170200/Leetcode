class Solution {
public:
    // s->start, e->end, side=0 means left side and side=1 denotes right side
    void help(TreeNode* root, vector<int>&v,int s,int e,int side){
        if(s<0  || s>=e){
            return;
        }
        // first find max value's ind in current window
        int mx=s;
        for(int i = s; i<e ; i++){
            if(v[mx]<v[i])
                mx = i;
        }
        // make new node with value equal to max val
        TreeNode* nw = new TreeNode(v[mx]);
        //insert it to appropriate site
        if(side == 0){
            root->left = nw;
        }else{
            root->right = nw;
        }
        // recursivley make left and right side 
        help(nw,v,s,mx,0);
        help(nw,v,mx+1,e,1);
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // make the root node
        int mx=0;
        for(int i=0;i<nums.size();i++)
            if(nums[mx]<nums[i])mx = i;
        
        TreeNode* nw_ = new TreeNode(nums[mx]);
        // divide the array into two part 
        //prefix subarray is inserted to left of root
        help(nw_,nums,0,mx,0);
        //suffix subarray to right of it
        help(nw_,nums,mx+1,nums.size(),1);
        return nw_;
    }
};