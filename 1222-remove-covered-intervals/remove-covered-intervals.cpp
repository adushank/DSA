class Solution {  
public:

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
          
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>contained_intervals;
        
        contained_intervals.push_back(intervals[0]);

        for(int i=1;i<intervals.size();i++){
            int s1 =contained_intervals.back()[0];
            int e1 =contained_intervals.back()[1];
            int s2 =intervals[i][0];
            int e2 =intervals[i][1];

            if(s2>=s1 &&  e1>=e2 || s2<=s1 &&  e1<=e2){
                 
                contained_intervals.back()[0]= min(s1,s2);
                contained_intervals.back()[1]=max(e1,e2);

            }
            else{contained_intervals.push_back(intervals[i]);}
        }
        
      
        int count =contained_intervals.size();
        return count;
    
    
        
    }
};