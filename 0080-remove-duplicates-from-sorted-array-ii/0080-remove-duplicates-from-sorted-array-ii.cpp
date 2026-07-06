class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int st=1,end=nums.size()-1,count=1,pt=1;
        if(nums.empty()){
            return 0;
        }
        while(st<=end){
            if(nums[st-1]==nums[st]){
                if(count<2){
                    count++;
                    nums[pt]=nums[st];
                    pt++;
                }
            }
            else{
                nums[pt]=nums[st];
                count=1;
                pt++;
            }
            st++;
        }
    return pt; 
    }
};