class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() == 1)
        {
            return nums[0];
        }

        priority_queue<int,vector<int>,greater<int>> mnheap;

        //push the k elements in the min heap
       
        for( int i = 0; i < k ; i ++)
        {
            int element = nums[i];
            mnheap.push(element);
        }
         // traverse the rest
        for(int i = k; i < nums.size() ; i ++)
        {
            int element = nums[i];
        // if larger then pop heap and insert it
            if(element > mnheap.top())
            {
                mnheap.pop();
                mnheap.push(element);
            }
        }
        // the top element is the ans.
        int ans = mnheap.top();
        return ans;

       
        
    }
};