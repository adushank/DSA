// class Solution {
// public:
//     int countDays(int days, vector<vector<int>>& meetings) {
//         int n =meetings.size();
// set<int> st;
// for(int i=0;i<n;i++){
//     int start = meetings[i][0];
//     int end = meetings[i][1];

//    for(int j=start;j<=end;j++){
    
//         st.insert(j);}
//     }

// int count = st.size();
// int ans = days - count;
// return ans ;
  
// //approach 1 jo bhi intervals given h un days ko sets me daal denge 
// //fir total number of days me se set ke size ko subtract kar denge 
// // will give TLE 
// //Time Complexity


        
//     }
// };


class Solution {
public:
    int countDays(int days, vector<vector<int>>& intervals) {
       
        
        int count =0;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>merged;
        merged.push_back(intervals[0]);
        for(int i=0;i<intervals.size();i++){
             int s1 =merged.back()[0];
            int e1 =merged.back()[1];
            int s2 =intervals[i][0];
            int e2 =intervals[i][1];
            if(s2<=e1){
                  merged.back()[0]= min(s1,s2);
                merged.back()[1]= max(e1,e2);

            }
            else{int prev_end =merged.back()[1];
                 int next_start =intervals[i][0];
                 count +=next_start - prev_end -1;
                
                merged.push_back(intervals[i]);}
        }

        if(merged[0][0]!=1){
            count +=merged[0][0]-1;
        }

        if(merged[merged.size()-1][1]!=days){
            count +=  days - merged[merged.size()-1][1];
        }

        return count;}};