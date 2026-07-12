class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, long long> freq;

        long long good = 0;
        int n = rectangles.size();

        for (int i = 0; i < n; i++) {
            double w = rectangles[i][0];
            double h =rectangles[i][1];
            double key =  w/h;

            
            freq[key]++;
        }
        
        for (auto [el, cnt] : freq) {
    good += 1LL * cnt * (cnt - 1) / 2;
}

       

        return good;
        
    }
};