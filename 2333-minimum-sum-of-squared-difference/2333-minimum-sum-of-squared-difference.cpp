
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        long long k = 1LL * k1 + k2;
        vector<int> diff;
        long long total = 0;
        int mx = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            diff.push_back(d);
            total += d;
            mx = max(mx, d);
        }

        if (total <= k) return 0;

        int low = 0, high = mx;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long ops = 0;

            for (int d : diff) {
                ops += max(0, d - mid);
            }

            if (ops <= k)
                high = mid;
            else
                low = mid + 1;
        }

        long long ans = 0;

        for (int &d : diff) {
            k -= max(0, d - low);
            d = min(d, low);
        }

        for (int &d : diff) {
            if (k == 0) break;
            if (d == low && d > 0) {
                d--;
                k--;
            }
        }

        for (int d : diff) {
            ans += 1LL * d * d;
        }

        return ans;
    }
};

