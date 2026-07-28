class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        string current_number = "";
        string current_string = "";

        for (char ch : s) {
            if (isdigit(ch)) {
                current_number += ch;
            }
            else if(ch == '[') {
                st.push(current_string);
                st.push(current_number);

                current_string = "";
                current_number = "";
            }
            else if (ch == ']') {
                int previous_number = stoi(st.top());
                st.pop();

                string previous_string = st.top();
                st.pop();

                string temp = "";
                for (int i = 0; i < previous_number; i++)
                    temp += current_string;

                current_string = previous_string + temp;
            }
            else {
                current_string += ch;
            }
        }
        return current_string;
    }
};