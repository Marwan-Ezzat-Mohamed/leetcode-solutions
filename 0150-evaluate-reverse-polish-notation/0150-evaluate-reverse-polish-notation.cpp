class Solution
{
public:
    bool is_digits(string str)
    {
        if (str[0] == '-')
        {
            str.erase(str.begin());
        }

        return str.size() && str.find_first_not_of("0123456789") == std::string::npos;
    }

public:
    int evalRPN(vector<string> &tokens)
    {

        stack<long long> numbers;
        for (auto x : tokens)
        {
            if (is_digits(x))
            {
                numbers.push(stoll(x));
                continue;
            }
            long long num2 = numbers.top();
            numbers.pop();
            long long num1 = numbers.top();
            numbers.pop();
            long long newNumber = 0;
            if (x == "*")
                newNumber = num1 * num2;
            if (x == "+")
                newNumber = num1 + num2;
            if (x == "-")
                newNumber = num1 - num2;
            if (x == "/")
                newNumber = num1 / num2;
            numbers.push(newNumber);
        }

        return numbers.top();
    }
};