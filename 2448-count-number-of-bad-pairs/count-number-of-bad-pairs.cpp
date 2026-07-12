class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<long long, long long> freq;

        long long good = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            long long key = (long long)nums[i] - i;

            
            freq[key]++;
        }
        
        for (auto [el, cnt] : freq) {
    good += 1LL * cnt * (cnt - 1) / 2;
}

        long long total = 1LL * n * (n - 1) / 2;

        return total - good;

        
    }
};