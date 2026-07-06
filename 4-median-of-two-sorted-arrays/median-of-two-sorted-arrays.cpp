class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

//          vector<int>ans;
//          int i=0;
//             int j=0;
//             while(i<nums1.size()&&j<nums2.size()){
//                 if (nums1[i]<nums2[j]){
//                     ans.push_back(nums1[i]);
//                     i++;
//                 }
//                 else{
//                     ans.push_back(nums2[j]);
//                     j++;
//                 }}
//                    // Add remaining elements from nums1
//         while (i < nums1.size()) {
//             ans.push_back(nums1[i]);
//             i++;
//         }

//         // Add remaining elements from nums2
//         while (j < nums2.size()) {
//             ans.push_back(nums2[j]);
//             j++;
//         }
//             int n=ans.size();
//             double res;
//             if(n%2==0){
//                 res= (ans[n/2]+ans[(n/2)-1])/2.0;
//             }
//             else{
//                 res= ans[n/2];
//             }
//             return res;
//     }
// };

  int n1 = nums1.size(), n2 = nums2.size();
    int n = n1 + n2;             // total length
    int ind1 = n / 2 - 1;        // index of first middle (for even case)
    int ind2 = n / 2;            // index of second middle
    int i = 0, j = 0, cnt = 0;   // pointers + merged count
    
    int ind1el = -1, ind2el = -1;  // to store the elements at ind1 and ind2

    // Merge process (like merge step of merge sort)
    while (i < n1 && j < n2) {
        if (nums1[i] < nums2[j]) {
            if (cnt == ind1) ind1el = nums1[i];
            if (cnt == ind2) ind2el = nums1[i];
            cnt++;
            i++;
        } else {
            if (cnt == ind1) ind1el = nums2[j];
            if (cnt == ind2) ind2el = nums2[j];
            cnt++;
            j++;
        }
    }

    // If elements left in nums1[]
    while (i < n1) {
        if (cnt == ind1) ind1el = nums1[i];
        if (cnt == ind2) ind2el = nums1[i];
        cnt++;
        i++;
    }

    // If elements left in nums2[]
    while (j < n2) {
        if (cnt == ind1) ind1el = nums2[j];
        if (cnt == ind2) ind2el = nums2[j];
        cnt++;
        j++;
    }

    // If odd length -> both ind1 and ind2 are same, else take average
    if (n % 2 == 1) {
        return ind2el; 
    } else {
        return (ind1el + ind2el) / 2.0;
    }
}
};








//   if (nums1.size() > nums2.size()) 
//             return findMedianSortedArrays(nums2, nums1);

//         int n1 = nums1.size(), n2 = nums2.size();
//         int low = 0, high = n1;
//         int half = (n1 + n2 + 1) / 2;

//         while (low <= high) {
//             int i = (low + high) / 2;     // partition in nums1
//             int j = half - i;             // partition in nums2

//             int left1  = (i == 0) ? INT_MIN : nums1[i-1];
//             int right1 = (i == n1) ? INT_MAX : nums1[i];
//             int left2  = (j == 0) ? INT_MIN : nums2[j-1];
//             int right2 = (j == n2) ? INT_MAX : nums2[j];

//             if (left1 <= right2 && left2 <= right1) {
//                 // Valid partition
//                 if ((n1 + n2) % 2 == 0) {
//                     return (max(left1, left2) + min(right1, right2)) / 2.0;
//                 } else {
//                     return max(left1, left2);
//                 }
//             } 
//             else if (left1 > right2) {
//                 // Too many elements taken from nums1
//                 high = i - 1;
//             } else {
//                 // Too few elements taken from nums1
//                 low = i + 1;
//             }
//         }

//         return 0.0; // should never reach here
//     }
// };




