class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int ans=-1,level=0,maxi=INT_MIN;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            level++;
            int n = q.size();
            int temp=0;
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                temp+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
               
            }
             if(temp > maxi){
                  ans = level;
                  maxi = temp;
              }
        }
        return ans;
    }
};