class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();

        int ans = 0;
        int cnt = 0;

        for(int i=0;i<k;i++){
            if(blocks[i] == 'W'){
                cnt++;
            }
        }

        ans = cnt;

        for(int i=k;i<n;i++){
            if(blocks[i-k] == 'W'){
                cnt--;
            }

            if(blocks[i] == 'W'){
                cnt++;
            }

            ans = min(ans,cnt);
        }
        return ans;
    }
};