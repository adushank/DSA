class Solution {

public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n1 = firstList.size();
int n2 = secondList.size();
vector<vector<int>> ans;


for(int i=0; i<n1; i++){ 
    int j=0;
while( j<n2){
    int s1 = firstList[i][0];
    int e1 = firstList[i][1];
    int s2 = secondList[j][0];
    int e2 = secondList[j][1];
    if(s1<=e2 && s2<=e1){
        ans.push_back({max(s1,s2),min(e1,e2)});
        
        

    
    }
    j++;

}}
return ans ;

    }
};