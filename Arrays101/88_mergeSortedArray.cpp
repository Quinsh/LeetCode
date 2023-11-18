//
// Created by Gun woo Kim on 11/17/23.
//
#include <vector>
using namespace std;

void mergeSortedArray(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> merged(m+n);

    if (!nums2.empty()){
        for(int i=0, j=0, index=0; index < m+n; index++){
            if(i < m && j < n){
                if(nums1[i] < nums2[j]){
                    merged[index] = nums1[i];
                    i++;
                }
                else{
                    merged[index] = nums2[j];
                    j++;
                }
            }
            else{
                if(i == m){
                    merged[index] = nums2[j++];
                }
                else{
                    merged[index] = nums1[i++];
                }
            }
        }


        for(int i=0; i<nums1.size(); i++){
            nums1[i] = merged[i];
        }
    }

}