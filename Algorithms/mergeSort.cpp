/**
 * DATE: 2024.07.10
 * INTUITION: let's use the Merge Sort Algorithm. I'm practicing D&C.
 * 
 * TC: O(NlogN) - O(N) iteration for each recursive call - there are O(logN) recursive calls
 * SC: O(N) - there's only this `temp` vector being used in the merging step
 * 
 * TOIMPROVE: I think I did pretty fair. 
 * I used l and r to merge in-place without making copies of new sorted arrays every recursion
 */
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
    void mergeSort(vector<int> &nums, int l, int r) {
        if (l == r) return;

        int mid = l + (r-l)/2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid+1, r);
        
        // put the left sorted part and right sorted part back into the array
        int p1 = l, p2 = mid+1;
        vector<int> temp; temp.resize(r-l+1);
        int i = 0;
        while (p1 <= mid && p2 <= r) {
            if (nums[p1] < nums[p2])
                temp[i++] = nums[p1++];
            else
                temp[i++] = nums[p2++];
        }
        if (p1 > mid)
            while (p2 <= r) temp[i++] = nums[p2++];
        else if (p2 > r)
            while (p1 <= mid) temp[i++] = nums[p1++];

        // copy back the temp into array from l to r
        for (const auto &t : temp) {
            nums[l++] = t;
        }
        
        return;
    }
};