class Solution {
public:
    double gain(double pass, double total) {
        return (pass + 1.0) / (total + 1.0) - pass / total;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {

        priority_queue<vector<double>> pq;

        for (auto &x : classes) {
            double pass = x[0];
            double total = x[1];
            pq.push({gain(pass, total), pass, total});
        }

        while (extraStudents--) {
            auto cur = pq.top();
            pq.pop();

            double pass = cur[1] + 1;
            double total = cur[2] + 1;

            pq.push({gain(pass, total), pass, total});
        }

        double sum = 0;

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            sum += cur[1] / cur[2];
        }

        return sum / classes.size();
    }
};