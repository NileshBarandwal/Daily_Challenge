// 1598. Crawler Log Folder

class Solution {
public:
    int minOperations(vector<string>& logs) {
         stack<string> folderStack;
        
        for (const string& log : logs) {
            if (log == "../") {
                if (!folderStack.empty()) {
                    folderStack.pop();
                }
            } else if (log == "./") {
                // Do nothing, remain in the same folder
            } else {
                // Move to the child folder
                folderStack.push(log);
            }
        }
        
        return folderStack.size();
    }
};