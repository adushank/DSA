class Solution {
public:
#define ll long long
    int firstMissingPositive(vector<int>& nums) {
        int n =nums.size();
        
        int i = 0;
      while (i < n) {
     ll correct = (ll)nums[i] - 1;   // or nums[i] for 0-based

    if (nums[i] >= 1 && nums[i] <= n && nums[i] != nums[correct]) {
        swap(nums[i], nums[correct]);
    } else {
        i++;
    }
}
for(int i=0;i<n;i++){
    if(nums[i]!=i+1){
        return i+1;
    }
}
return n+1 ;           //  nums =   [1]    ans =2  (one of the test cases is this to handle this n+1 is returned)

    }
};