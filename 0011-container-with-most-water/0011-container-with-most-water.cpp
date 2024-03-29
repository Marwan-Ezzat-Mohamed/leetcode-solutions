class Solution {
  public: int maxArea(vector < int > & height) {

    int l = 0, r = height.size() - 1;
    long long ans = 0;

    while (l != r && r > l) {
      // if moving the right pointer will be bigger than left pointer 

      long long h = min(height[l], height[r]);
      long long cur = h * (r - l);
      ans = max(ans, cur);

      if (height[l] < height[r]) l++;
      else if (height[l] > height[r]) r--;
      else {
        l++;
        r--;
      }

    }

    return ans;

  }

};