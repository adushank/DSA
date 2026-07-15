class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int K) {
    int rows = grid.size();
    int cols = grid[0].size();

     const int INF = 1e9;
    // dp[i][j][k] -> shortest path to (i,j) 
    // Initialize everything to Infinity
    vector<vector<vector<int>>> dp(
        rows, vector<vector<int>>(
            cols,vector<int>(K + 1, INF)));

    // BFS queue stores states: {x, y,  k_used}
    queue<tuple<int, int, int>> q;

    // 1. Starting State
    int sx = 0, sy = 0;
    dp[sx][sy][0] = 0;
    q.push({sx, sy,  0});

    // Direction arrays for Up, Down, Left, Right
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [i, j,  k] = q.front();
        q.pop();

        // 2. State-Transfer
        for (int dir = 0; dir < 4; dir++) {
            int x = i + dx[dir];
            int y = j + dy[dir];

            
           if (x < 0 || x >= rows || y < 0 || y >= cols)
    continue;
                
                
                
                    
                    // Case A: Normal Walkable Cell (grid[x][y] == 0)
                    if (grid[x][y] == 0) {
                    if (dp[x][y][k] > dp[i][j][k] + 1) {
                        dp[x][y][k] = dp[i][j][k] + 1;
                        q.push({x, y,  k});
                    }}

                    // Case B: (grid[x][y] == 1)
                    if (grid[x][y] == 1) {
                        
                        if (k  < K) {
                           
                            if (dp[x][y][k + 1] > dp[i][j][k] + 1) {
                                dp[x][y][k + 1] = dp[i][j][k] + 1;
                                q.push({x, y,  k + 1});
                            }
                        
                    }
                }
            }
        }
    

    // 3. Answer: min(dp[ex][ey][0...K])
    int min_steps = INF;
   
        for (int k = 0; k <= K; k++) {
            min_steps = min(min_steps, dp[rows-1][cols-1][k]);
        }
    

    return (min_steps == INF) ? -1 : min_steps; // Return -1 if destination is unreachable

        
    }
};