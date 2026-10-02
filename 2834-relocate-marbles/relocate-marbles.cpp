class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& fr, vector<int>& to) {
        // struct move{
        //     int from;
        //     int to;
        // };

        // vector<move>arr;
        // for(int i =0; i< moveFrom.size(); i++){
        //     arr.push_back({moveFrom[i],moveTo[i]});
        // }
        // sort(arr.begin(),arr.end(),[](const auto& a,const auto& b){
        //     a.first < b.first
        // });
        // vector<int>ans;
        // unordered_set<int>st;
        // unordered_map<int,int>mpp;
        // for(int i= 0; i< moveFrom.size();i++){
        //     mpp[moveFrom[i]] = moveTo[i];
        // }
        // for(int i= 0; i< nums.size();i++){
        //     while(mpp.find(nums[i]) !=mpp.end()){
        //         nums[i] = mpp[nums[i]];
        //     }
        //     st.insert(nums[i]);
        // }
        // for(auto it : st){
        //     ans.push_back(it);
        // }
        // sort(ans.begin(),ans.end());
        // return ans;
                    map<int,int> pos;
            
            for(int i = 0;i<nums.size();i++) pos[nums[i]]++; // Storing count of marble in map
            
            for(int i = 0;i<fr.size();i++){
                    int from = fr[i];
                    int too = to[i];
                    
                    if(pos.count(from)){
                            int marble  = pos[from]; // Find number of marble at prev position
                            pos.erase(from); // Erase from map
                            pos[too] = marble; // Insert at new position
                    }
            }
            
            vector<int> ans;
            
            for(auto [a,b] : pos)  ans.push_back(a); // Insert new positions to answer
            
            return ans;
    }
};