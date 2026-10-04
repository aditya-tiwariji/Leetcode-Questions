class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Make sure nums1 is the smaller array to minimize binary search time
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;
        
        while (low <= high) {
            int i = (low + high) / 2;
            int j = (m + n + 1) / 2 - i;
            
            // Handle edge cases where partition is at the extreme ends
            int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRight1 = (i == m) ? INT_MAX : nums1[i];
            
            int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRight2 = (j == n) ? INT_MAX : nums2[j];
            
            // Check if we have found the correct partition
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // If total number of elements is odd
                if ((m + n) % 2 == 1) {
                    return max(maxLeft1, maxLeft2);
                }
                // If total number of elements is even
                return (double)(max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
            }
            else if (maxLeft1 > minRight2) {
                // We are too far right in nums1, move left
                high = i - 1;
            } else {
                // We are too far left in nums1, move right
                low = i + 1;
            }
        }
        
        return 0.0;
    }
};