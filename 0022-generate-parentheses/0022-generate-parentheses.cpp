/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <map>
using namespace std;
class Solution
{
public:
    bool isValid(string &s)
    {
        int balance = 0;
        for (char c : s)
        {
            if (c == '(')
                balance++;
            else
                balance--;
            if (balance < 0)
                return false;
        }
        return (balance == 0);
    }

public:
    void gen(int n, string s, vector<string> &g)
    {

        if (s.size() > n)
            return;
        if (s.size() == n && isValid(s))
        {

            g.push_back(s);
        }

        gen(n, s + ")", g);
        gen(n, s + "(", g);
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        gen(n * 2, "", ans);

        return ans;
    }
};
// @lc code=end
