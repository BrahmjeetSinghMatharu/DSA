class Solution {
public:
    int calculate(string s) {
        long long number = 0;
        long long result = 0;
        int sign = 1;

        stack<int> st;
        int n = s.length();

        for(int i=0;i<n;i++){
            char ch = s[i];
            
            // we are making the number
            if(isdigit(ch)){
                number = (number*10) + (ch - '0'); 
            }
            else if(ch == '+'){
                // number already ban chuka hai
                // now we are just adding in result
                result += (number * sign);
                number = 0;
                sign = 1;
            }
            else if(ch == '-'){
                // number already ban chuka hai
                // now we are just adding in result
                result += (number * sign);
                number = 0;
                sign = -1;
            }
            else if(ch == '('){
                st.push(result);
                st.push(sign);
                result = 0;
                number = 0;
                sign = 1; 
            }
            else if(ch == ')'){
                result += (number * sign);  // bracket ke andar ka result
                number = 0;

                int stack_sign = st.top();
                st.pop();
                int stack_res = st.top();
                st.pop();

                result *= stack_sign;
                result += stack_res;
            }
        }
        result += (number*sign);
        return (int)result;
    }
};