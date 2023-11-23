#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int len = nums.size();
    for (int i = len - k; i < len; i++){
        int last = 0;
        int temp = nums[i];
        int end = nums.size()/k;
        if (i == nums.size()-1) end -= 1;
        for (int j = i, cnt = 0; cnt < end; j-=k, cnt++){
            if(j-k >= 0){
                nums[j] = nums[j-k];
                for (int &a : nums){
                    cout << a << " ";
                } cout << endl;
            }

            if(cnt == end-1){
                if (i > len-k){
                    nums[j] = last;
                }
                last = nums[j];
            }
        }
        int pos = (i+k) % nums.size();
        nums[pos] = temp;
    }
}

int main() {
    vector<int> hey = {1,2,3,4,5,6,7};
    rotate(hey, 2);
    for (int &a : hey){
        cout << a << " ";
    }
}
