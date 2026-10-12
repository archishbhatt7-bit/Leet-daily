class Solution {
public:
    int dist(int a, int b) {
        int d = abs(a - b);
        return min(d, 10 - d);
    }

    int minRotations(int n, string s) {
        vector<int> pre(n), suff(n);

        pre[0] = dist(0, s[0] - '0');

        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] +
                     dist(s[i - 1] - '0', s[i] - '0');
        }

        suff[n - 1] = 0;

        for (int i = n - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] +
                      dist(s[i] - '0', s[i + 1] - '0');
        }

        int ans = pre[n - 1];
        int last = s[n - 1] - '0';

        for (int i = 0; i < n; i++) {
            int left = (i == 0) ? 0 : pre[i - 1];
            int prev = (i == 0) ? 0 : s[i - 1] - '0';

            int newCost = left + dist(prev, last) + suff[i];
            ans = min(ans, newCost);
        }

        return ans;
    }
};