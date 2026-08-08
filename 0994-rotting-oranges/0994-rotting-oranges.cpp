class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }

                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        int mints = 0;

        int dr[] = {-1, 0, 0, 1};
        int dc[] = {0, -1, 1, 0};

        while (!q.empty() && fresh) {

            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int rd = r + dr[d];
                    int cd = c + dc[d];

                    if (rd >= 0 && rd < n && cd >= 0 && cd < m &&
                        grid[rd][cd] == 1) {
                        grid[rd][cd] = 2;
                        q.push({rd, cd});
                        fresh--;
                    }
                }
            }

            mints++;
        }

        return fresh == 0 ? mints : -1;
    }
};