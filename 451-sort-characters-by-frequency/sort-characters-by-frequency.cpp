class Solution {
public:
    string frequencySort(string s) {
       unordered_map<char, int> freq;
int n = s.length();
for(int i = 0; i < n; i++) {
    freq[s[i]]++;
}
    priority_queue<pair<int, char>> pq;
for(auto it : freq) {
    pq.push({it.second, it.first});
}
string t = "";
while(!pq.empty()) {

    auto p = pq.top();
    pq.pop();

    while(p.first--)
        t += p.second;
}
return t;
        
        
    }
};