class Solution {
public:
    int digE[10][4]; // digit -> exponents of (2,3,5,7)
    vector<vector<vector<vector<int>>>> memo;

    void initDigits() {
        int arr[10][4] = {
            {0,0,0,0}, {0,0,0,0}, {1,0,0,0}, {0,1,0,0}, {2,0,0,0},
            {0,0,1,0}, {1,1,0,0}, {0,0,0,1}, {3,0,0,0}, {0,2,0,0}
        };
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 4; j++) digE[i][j] = arr[i][j];
    }

    int minLen(int a, int b, int c, int d) {
        if (a == 0 && b == 0 && c == 0 && d == 0) return 0;
        int &res = memo[a][b][c][d];
        if (res != -1) return res;
        res = INT_MAX;
        for (int dig = 2; dig <= 9; dig++) {
            int na = max(0, a - digE[dig][0]), nb = max(0, b - digE[dig][1]);
            int nc = max(0, c - digE[dig][2]), nd = max(0, d - digE[dig][3]);
            if (na == a && nb == b && nc == c && nd == d) continue;
            int sub = minLen(na, nb, nc, nd);
            if (sub != INT_MAX) res = min(res, 1 + sub);
        }
        return res;
    }

    bool buildSmallest(int a, int b, int c, int d, int m, string &out) {
        if (minLen(a, b, c, d) > m) return false;
        out.resize(m);
        for (int pos = 0; pos < m; pos++) {
            int remain = m - pos - 1;
            for (int dig = 1; dig <= 9; dig++) {
                int na = max(0, a - digE[dig][0]), nb = max(0, b - digE[dig][1]);
                int nc = max(0, c - digE[dig][2]), nd = max(0, d - digE[dig][3]);
                if (minLen(na, nb, nc, nd) <= remain) {
                    out[pos] = '0' + dig;
                    a = na; b = nb; c = nc; d = nd;
                    break;
                }
            }
        }
        return true;
    }

    string smallestNumber(string num, long long t) {
        initDigits();
        int a = 0, b = 0, c = 0, d = 0;
        long long tt = t;
        while (tt % 2 == 0) { a++; tt /= 2; }
        while (tt % 3 == 0) { b++; tt /= 3; }
        while (tt % 5 == 0) { c++; tt /= 5; }
        while (tt % 7 == 0) { d++; tt /= 7; }
        if (tt != 1) return "-1";

        memo.assign(a+1, vector<vector<vector<int>>>(b+1,
                    vector<vector<int>>(c+1, vector<int>(d+1, -1))));

        int L = num.size();
        int ML = minLen(a, b, c, d);

        if (ML <= L) {
            bool zeroFree = true;
            int ea = 0, eb = 0, ec = 0, ed = 0;
            for (char ch : num) {
                if (ch == '0') { zeroFree = false; break; }
                int dg = ch - '0';
                ea += digE[dg][0]; eb += digE[dg][1];
                ec += digE[dg][2]; ed += digE[dg][3];
            }
            if (zeroFree && ea >= a && eb >= b && ec >= c && ed >= d) return num;

            int firstZero = L;
            for (int i = 0; i < L; i++) if (num[i] == '0') { firstZero = i; break; }

            vector<array<int,4>> pref(L + 1, {0,0,0,0});
            for (int i = 0; i < L; i++) {
                pref[i+1] = pref[i];
                if (num[i] != '0') {
                    int dg = num[i] - '0';
                    for (int k = 0; k < 4; k++) pref[i+1][k] += digE[dg][k];
                }
            }

            int maxI = min(firstZero, L - 1);
            for (int i = maxI; i >= 0; i--) {
                for (int dg = num[i]-'0'+1; dg <= 9; dg++) {
                    int ea2 = pref[i][0] + digE[dg][0], eb2 = pref[i][1] + digE[dg][1];
                    int ec2 = pref[i][2] + digE[dg][2], ed2 = pref[i][3] + digE[dg][3];
                    int ra = max(0, a-ea2), rb = max(0, b-eb2);
                    int rc = max(0, c-ec2), rd = max(0, d-ed2);
                    int remainLen = L - i - 1;
                    if (minLen(ra, rb, rc, rd) <= remainLen) {
                        string suffix;
                        buildSmallest(ra, rb, rc, rd, remainLen, suffix);
                        return num.substr(0, i) + char('0'+dg) + suffix;
                    }
                }
            }
        }

        int M = max(L + 1, ML);
        string res;
        buildSmallest(a, b, c, d, M, res);
        return res;
    }
};