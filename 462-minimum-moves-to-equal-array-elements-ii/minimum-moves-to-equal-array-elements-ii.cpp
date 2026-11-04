class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int med = 0;
        if(n%2 == 0){
            med = (nums[(n-1)/2]+nums[(n-1)/2 +1])/2;
        }
        else med  = nums[(n-1)/2];
        long long moves = 0;
        for(int i =0; i< n; i++){
            moves = moves + abs(nums[i]-med);
        }
        return moves;
    }
};
