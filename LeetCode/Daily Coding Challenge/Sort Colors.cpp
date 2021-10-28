class Solution {
public:
    void swap(int& a, int& b){
        int aux = a;
        a = b;
        b = aux;
    }
    
    void sortColors(vector<int>& nums) {
        int c[3] = {0, 0, 0};
        for(auto a : nums) c[a]++;
            
        int it[3] = {0, c[0], c[0]+c[1]};
        for(; it[0] < c[0]; it[0]++){
            while(nums[it[0]] != 0){
                swap(nums[it[0]], nums[it[nums[it[0]]]++]);
            }
        }
        
        for(; it[1] < c[0]+c[1]; it[1]++){
            while(nums[it[1]] != 1){
                swap(nums[it[1]], nums[it[nums[it[1]]]++]);
            }
        }
        
    }
};