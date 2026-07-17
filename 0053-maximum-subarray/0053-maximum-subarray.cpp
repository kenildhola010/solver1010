class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,start=0,end=0;;
        int mx = INT_MIN;
        int n = nums.size();
        int ans_start=-1, ans_end=-1;
        for(int i =0;i<n;i++)
        {
             if(sum == 0) start=i;
            sum+=nums[i];
           

            if(sum >mx)
            {
                mx = sum;
                ans_start=start;
                ans_end =i;
            }
            if(sum <0)
            {
                sum=0;
            }
        }

        for(int i = ans_start; i<=ans_end; i++)
        {
            cout <<nums[i] <<" ";
        }
        return mx;
        
    }
};