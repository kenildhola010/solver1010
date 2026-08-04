class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) 
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;
        while (left <= right) {
            // Partition nums1
            int i = left + (right - left) / 2;
            // Partition nums2 so that left halves together have (m+n+1)/2 elements
            int j = (m + n + 1) / 2 - i;

            // Handle edge cases with INT_MIN/INT_MAX
            int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRight1 = (i == m) ? INT_MAX : nums1[i];
            int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRight2 = (j == n) ? INT_MAX : nums2[j];

            // Check if partition is correct
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // If total length is odd, median is max of left parts
                if ((m + n) % 2 == 1)
                    return max(maxLeft1, maxLeft2);
                // If even, median is average of max of left and min of right
                else
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
            }
            // Move partition in nums1 to left
            else if (maxLeft1 > minRight2) {
                right = i - 1;
            }
            // Move partition in nums1 to right
            else {
                left = i + 1;
            }
        }
        // Should never reach here
        return 0.0;
    }
};