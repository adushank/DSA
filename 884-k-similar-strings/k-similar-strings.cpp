class Solution {


public:
    int kSimilarity(string s1, string s2) {
        unordered_set<string>vis;
        int n =s1.length();
        queue<pair<string,int>>q;
        q.push({s1,0});
        vis.insert(s1);
        while(!q.empty()){
            auto [curr,step]=q.front();
            q.pop();

           if (curr == s2)
                    return step;

                // First mismatch
                int i = 0;
                while (curr[i] == s2[i]){
                    i++;}
            //sabke liye nhi jo match nhi ho rha wahi swap karenge 
            
            // not match wale ko swap karenge 
            for(int j =i+1;j<n;j++){
                if (curr[j] == s2[i] && curr[j] != s2[j]){
                swap(curr[i], curr[j]);

                        if (!vis.count(curr)) {
                            vis.insert(curr);
                            q.push({curr,step +1});
                        }
                        swap(curr[i], curr[j]);
                        }

                        

            }
        }

       return -1;

        
    }
};