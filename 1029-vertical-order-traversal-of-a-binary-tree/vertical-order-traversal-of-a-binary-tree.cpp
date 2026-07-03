class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> columnTable;
        queue<pair<TreeNode*, pair<int, int>>> bfsQueue;
        bfsQueue.push({root, {0, 0}});

        while (!bfsQueue.empty()) {

            auto current = bfsQueue.front();
            bfsQueue.pop();

            TreeNode* currentNode = current.first;
            int column = current.second.first;
            int row = current.second.second;

            columnTable[column][row].insert(currentNode->val);

            if (currentNode->left) {
                bfsQueue.push({currentNode->left, {column - 1, row + 1}});
            }

            if (currentNode->right) {
                bfsQueue.push({currentNode->right, {column + 1, row + 1}});
            }
        }

        vector<vector<int>> result;

        for (auto& columnEntry : columnTable) {

            vector<int> currentColumn;
            for (auto& rowEntry : columnEntry.second) {
                currentColumn.insert(
                    currentColumn.end(),
                    rowEntry.second.begin(),
                    rowEntry.second.end()
                );
            }
            result.push_back(currentColumn);
        }
        return result;
    }
};