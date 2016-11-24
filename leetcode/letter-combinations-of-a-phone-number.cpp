
class Solution {
public:
    string a[10] = {
        "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    vector<int> stack;
    vector<string> input;
    
    vector<string> letterCombinations(string digits) {
        cout<<"input: "<<digits<<endl;
        
        stack.clear();
        input.clear();
        vector<string> ret;
        for (char ch : digits) {
            stack.push_back(0);
            input.push_back(a[ch - '1']);
        }
        int stackTop = stack.size() - 1;
        cout<<stackTop<<endl;
        while (stackTop >= 0) {
            if (stackTop == stack.size() - 1) {
                ret.push_back(getStackS());
                stack[stackTop] += 1;
                if (stack[stackTop] >= input[stackTop].size()) {
                    stack[stackTop] = 0;
                    stackTop -= 1;
                    if (stackTop < 0) break;
                    stack[stackTop] += 1;
                }
            } else {
                if (stack[stackTop] >= input[stackTop].size()) {
                    stack[stackTop] = 0;
                    stackTop -= 1;
                    if (stackTop < 0) break;
                    stack[stackTop] += 1;
                } else {
                    stackTop += 1;
                }
            }
            
        }
        return ret;
    }
    
    string getStackS() {
        string ret = "";
        for (int i=0; i<stack.size(); i++) {
            ret.push_back(input[i][stack[i]]);
        }
        return ret;
    }
};
