class Solution {
  public:

    int getReq(vector < int > & piles, int num) {
      int cnt = 0;
      for (auto &x: piles) {
        int op = ceil((double) x / (double) num);
        cnt += op;
      }

      return cnt;
    }
  int minEatingSpeed(vector < int > & piles, int h) {
    double sum = 0;
    int mx = 0;
    for (auto &x: piles) {
      sum += x;
      mx = max(mx, x);
    }

    int initial = ceil(sum / (double) h);
    int l = initial, r = mx;
    int mid;
    while (l < r) {
      mid = (l + r) >> 1;
      int req = getReq(piles, mid);
      if (req > h) {
        l = mid + 1;
      } else {
        r = mid;
      }

    }
    return r;
  }
};