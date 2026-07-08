class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> pos;
        vector<long long> prefHash;
        vector<long long> prefSum;
        vector<long long> power10(n + 1);

        power10[0] = 1;
        for (int i = 1; i <= n; i++)
            power10[i] = (power10[i - 1] * 10) % MOD;

        prefHash.push_back(0);
        prefSum.push_back(0);

        // Compress non-zero digits
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                int d = s[i] - '0';
                pos.push_back(i);

                long long curHash = (prefHash.back() * 10 + d) % MOD;
                prefHash.push_back(curHash);

                prefSum.push_back(prefSum.back() + d);
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            auto itL = lower_bound(pos.begin(), pos.end(), l);
            auto itR = upper_bound(pos.begin(), pos.end(), r);

            int L = itL - pos.begin();
            int R = itR - pos.begin() - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L + 1;

            long long number =
                (prefHash[R + 1] -
                 prefHash[L] * power10[len] % MOD +
                 MOD) % MOD;

            long long sum =
                prefSum[R + 1] - prefSum[L];

            ans.push_back(number * (sum % MOD) % MOD);
        }

        return ans;
    }
};