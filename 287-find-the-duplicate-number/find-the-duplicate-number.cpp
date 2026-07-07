class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        int n =nums.size();

        while (i < nums.size()) {
            int correct = nums[i] - 1;

if (nums[i] >= 1 && nums[i] <= n && nums[i] != nums[correct]) {  
                  swap(nums[i], nums[correct]);
            } else {
                
                i++;
            }
        }
        for(int i=0;i<n;i++){
    if(nums[i]!=i+1){
        return nums[i];
    }
}

        return -1;
    }
};