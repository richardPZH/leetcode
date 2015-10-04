/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> hashMap;
        for(int i = 0; i < nums.size(); ++i){
            if(hashMap.find(nums[i]) != hashMap.end() && (i - hashMap[nums[i]] <= k)){
                return true;
            }else{
                hashMap[nums[i]] =i;
            }
        }
        return false;
       
    }
};