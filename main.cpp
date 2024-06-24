// Code

class Solution {
public:
    int longestValidParentheses(string s) 
    {
        stack<int> st;
        int count = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                st.push(i);

            else
            {
                if (!st.empty()) 
                {
                    if (s[st.top()] == '(') 
                        st.pop();
                    else 
                        st.push(i);
                }
                else 
                    st.push(i);
            }
        }
        if (st.empty())
            count = s.size();
        else
        {
            int a = s.size(), b = 0;
            while (!st.empty()) 
            {
                b = st.top(); st.pop();
                count = max(count, a - b - 1);
                a = b;
            }
            count = max(count, a);
        }
        return count;
    }
};
