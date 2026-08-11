class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mpp(26,0);

        // Store frequency in vector/map
        for(char &ch : tasks){
            mpp[ch-'A']++;
        }

        int time = 0;
        priority_queue<int> pq;

        // Store the frequency in the priority queue
        for(int i=0;i<26;i++){
            if(mpp[i]>0) pq.push(mpp[i]);
        }

        while(!pq.empty()){
            vector<int> temp;

            // Start executing a set of tasks
            for(int i=1;i<=n+1;i++){
                // Pick the tasks with most frequency & execute them
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            // Push the executed set of tasks back into the queue
            for(int &freq : temp){
                if(freq>0) pq.push(freq);
            }

            if(pq.empty()) time += temp.size();
            else time += n+1;
        }
        return time;
    }
};