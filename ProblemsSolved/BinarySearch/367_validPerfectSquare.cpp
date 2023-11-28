//
// Created by Gun woo Kim on 11/25/23.
//
bool isPerfectSquare(int num) {
    int l = 0, r = num-1;
    if (num == 1) return true;
    while (l <= r){
        int mid = l + (r-l)/2;
        double sqrt = double(num)/mid;
        if (mid == sqrt){
            return true;
        }
        else if (mid < sqrt){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return false;
}