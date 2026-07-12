// class Solution {
// public:
//     int subarraysDivByK(vector<int>& nums, int k) {
//                unordered_map<long long, int> mp; 
//     long long sum = 0;
//     int count = 0;
//    mp[0]=1;

//     for (int i = 0; i < nums.size(); i++) {
//         sum += nums[i];

     

//         // Case 2: Subarray from mp[sum-k]+1 to i
//         int rem = ((sum % k) + k) % k;
//         if (mp.find(rem) != mp.end()) {
//             count+= mp[rem];
//         }

//         // Store first occurrence only
       
//             mp[rem] ++;;
//         }
    
//     return count;
// }
    
// };



class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
               unordered_map<long long, int> freq; 
    long long sum = 0;
    int count = 0;
   freq[0]=1;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];

     

        // Case 2: Subarray from mp[sum-k]+1 to i
        int rem = ((sum % k) + k) % k;
       count+= freq[rem];
        

        // Store first occurrence only
       
            freq[rem] ++;;
        }
    
    return count;
}
    
};