class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int S = 0, s = 0;
        for(int x : nums) S += x;
        for(int i = 0; i < nums.size(); i++) {s += nums[i]; if(s-nums[i] == S-s) return i;}
        return -1;
    }
};