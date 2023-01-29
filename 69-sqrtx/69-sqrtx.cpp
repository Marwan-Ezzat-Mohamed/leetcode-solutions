class Solution {
public:
   long long mySqrt(long long x)
    {

        long long l = 0;
        long long r = x + 1;
        while (l < r)
        {
            long long m = (l + (r - l) / 2);
            if (m * m > x)
                r = m;
            else l = m + 1;
        }
        return (l - 1);
    }
};