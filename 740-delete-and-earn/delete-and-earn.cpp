class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
      int mx = *max_element(nums.begin(), nums.end());
    int n =nums.size();
  // take or not take pattern 
  unordered_map<int,int>freq;
  
for(int i = 0; i < n; i++) {
    freq[nums[i]]++;
}
 vector<int>dp(mx +1,0);
  dp[0]=0;   // maximum gain after choosing 0;
  dp[1] =1*freq[1];  // maximum gain after choosing 1    
  //agar array me hoga to freq ki value aa jayegi warna 0 hogas
 
  for(int i=2;i<=mx;i++){
    int take =i*freq[i] + dp[i-2];
    int not_take = dp[i-1];
    dp[i]=max(take,not_take);
  }
  return dp[mx];

     
    }
};
        
 