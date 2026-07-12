class Solution {
    int rev(int i){
        string t = to_string(i);
        reverse(t.begin(),t.end());
        int ans =stoi(t);
        return ans;
    }

public:
    int countNicePairs(vector<int>& nums) {
        long long mod =1e9+7;
         unordered_map<long long, long long> freq;

        long long good = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            long long key = (long long)nums[i] - rev(nums[i]);

            
            freq[key]++;
        }
        
        for (auto [el, cnt] : freq) {
    good += 1LL * cnt * (cnt - 1) / 2;
}

        

        return  good%mod;
        
    }
};