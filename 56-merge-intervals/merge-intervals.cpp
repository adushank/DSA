class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
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
            else{merged.push_back(intervals[i]);}
        }
        return merged;
        
    }
};