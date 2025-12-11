class Solution {
public:
    bool isBalanced(char u, char v) {
        if ((u == '(' && v == ')') || (u == '{' && v == '}') ||
            (u == '[' && v == ']'))
            return true;
        else {
            return false;
        }
    }

    bool isValid(string s) {
        bool ok = true;
        stack<char> st;
        for (auto u : s) {
            if (u == '(' || u == '{' || u == '[') {
                st.push(u);
            }

            else {

                if (st.empty()) {
                    ok = false;
                    break;
                }

                else {

                    if (isBalanced(st.top(), u))

                    {
                        st.pop();
                    } else {
                        ok = false;
                    }
                }
            }
        }

        if (!st.empty())
            ok = false;

        return ok;
    }
};