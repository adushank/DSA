class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        int n = arr.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({arr[i], i});
        }
        vector<int> ans(n, 0);
        
        int i=1;
        while (!pq.empty())
        {
            auto [value, index] = pq.top();
            
            pq.pop();
            ans[index] = i;
            if(value!=pq.top().first  )
            {
                
                i++;
            }
        }
        return ans;
        
        
    }
};