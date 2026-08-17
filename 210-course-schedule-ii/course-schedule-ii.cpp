class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> inorder(numCourses,0);

        for(int i=0;i<numCourses;i++){
            for(int it : adj[i]){
                inorder[it]++;
            }
        }

        queue<int> q;

        for(int i=0;i<numCourses;i++){
            if(inorder[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int it : adj[node]){
                inorder[it]--;
                if(inorder[it] == 0) q.push(it);
            }
        }
        if(ans.size() == numCourses) return ans;
        return {};
    }
};