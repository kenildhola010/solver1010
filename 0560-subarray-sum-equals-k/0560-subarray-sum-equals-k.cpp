class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[0] = 1;
        int prefix = 0,ct = 0;

        for(int i=0;i<nums.size();i++)
        {
            prefix += nums[i];
            int remove  = prefix - k;
            ct += mp[remove];
            mp[prefix] +=1;
        }
        return ct;
    }
};