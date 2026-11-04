class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int max = nums[nums.size()-1];
        int moves = 0;
        for(int i : nums){
            moves = moves + max-i;
        }
        return moves;
    }
};