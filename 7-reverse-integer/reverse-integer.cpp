class Solution {
public:
    int reverse(int x) {
        int reversed = 0;
        int max = INT_MAX/10;

        while(x != 0){
            if(abs(reversed) > max){
                return 0;
            }

            reversed = reversed*10;
            reversed += (x%10);
            x=x/10;
        }
        return reversed;
    }
};