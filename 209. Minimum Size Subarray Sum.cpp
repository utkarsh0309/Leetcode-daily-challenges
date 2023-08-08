class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int n=nums.size(),s=0,j=0,ans=INT_MAX,i=0;s=nums[0];
        while(i<n&&j<n){
            if(s>=k){ans=min(ans,i-j+1);s-=nums[j];j++;}
            else{i++;if(i>=n){continue;}s+=nums[i];}
        }
        return ans==INT_MAX?0:ans;
    }
};