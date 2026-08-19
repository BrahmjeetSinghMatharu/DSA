class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(),wordList.end());

        if(s.find(endWord) == s.end()){
            return 0;
        }
        
        queue<pair<string,int>> q;
        q.push({beginWord,1});

        while(!q.empty()){
            string word = q.front().first;
            int dis = q.front().second;
            q.pop();

            if(word == endWord) return dis;

            for(int i=0;i<word.length();i++){
                char original = word[i];
                for(int j=0;j<26;j++){
                    word[i] = 'a' + j;

                    if(s.find(word) != s.end()){
                        q.push({word,dis+1});
                        s.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};