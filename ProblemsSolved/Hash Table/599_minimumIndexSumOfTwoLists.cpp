//
// Created by Gun woo Kim on 11/28/23.
//
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    unordered_map<string, int> hashmap1, hashmapSum;
    vector<string> res = {};
    for (int i = 0; i < list1.size(); i++){
        hashmap1[list1[i]] = i;
    }
    int min = 2000;
    for (int i = 0; i < list2.size(); i++){
        if (hashmap1.count(list2[i]) > 0){
            int sum = hashmap1[list2[i]] + i;
            if (sum == min){
                res.push_back(list2[i]);
            }
            else if (sum < min){
                res.clear();
                res.push_back(list2[i]);
                min = sum;
            }
        }
    }
    return res;
}