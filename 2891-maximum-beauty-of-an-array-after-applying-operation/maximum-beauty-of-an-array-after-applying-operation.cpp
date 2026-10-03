class Solution {
public:

    // int maxi(vector<int>&nums){
    //     int maxo = 0;
    //     for(int i =0 ; i< nums.size() ; i++){
    //         maxo = max(maxo,nums[i]);
    //     }
    //     return maxo;
    // }

    int maximumBeauty(vector<int>& nums, int k) {
        // //maximum overlapping intervals , 
        // struct Interval{
        //     int start;
        //     int end;
        // };
        // vector<Interval>nu(nums.size());
        // for(int i=0; i< nums.size(); i++){
        //     nu[i] = {nums[i]-k,nums[i]+k};
        // }

        // sort(nu.begin(),nu.end(),[](const auto& a,const auto& b){
        //    return a.start < b.start;
        // });

        // vector<int>ans;
        // for(int i =0; i< nu.size() ; i++){
        //     int count = 0;
        //     int ed = nu[i].end;
        //     for(int j = i +1; j < nu.size(); j++){
        //         if(ed >= nu[j].start){
        //             count++;
        //         }
        //         else{

        //             break;
        //         }
        //     }
        //     ans.push_back(count);
        // }
        // return maxi(ans)+1;
        // Sort the array first
        sort(nums.begin(), nums.end());
        
        int left = 0;
        int maxBeauty = 0;
        
        // Expand the window with the right pointer
        for (int right = 0; right < nums.size(); right++) {
            // If the current window is invalid (difference > 2k), shrink from the left
            while (nums[right] - nums[left] > 2 * k) {
                left++;
            }
            
            // Update the maximum overlapping items found so far
            maxBeauty = max(maxBeauty, right - left + 1);
        }
        
        return maxBeauty;
    }   
};