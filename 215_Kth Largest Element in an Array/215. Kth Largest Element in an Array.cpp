/************************************************************
Find the kth largest element in an unsorted array. 
Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

a simple solution is using algorithm.sort() to make the array in order, then take the k-1 position
furthermore, this question just need the k-th largest element, means other elements are not required set in order.
so we can rewrite the quick sort
************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    int partition(vector<int>& nums, int left, int right) {
        int pivor = nums[left];
        int i = left, j = right;
        
        while(i < j) {
            while(i < j && pivor >= nums[j]) {
                j--;
            }
            
            nums[i] = nums[j];
            while(i < j && pivor <= nums[i]) {
                i++;
            }
            
            nums[j] = nums[i];
        }
        nums[i] = pivor;
        return i;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size()-1;
        while(1) {
            int pivor = partition(nums, left, right);
            if (pivor == k-1) {
                return nums[pivor];
            }
            if (pivor < k-1) {
                left = pivor+1;
            }
            else {
                right = pivor-1;
            }
        }
    }
};

int main() {
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout << Solution().findKthLargest(nums, k);
    return 0;
}