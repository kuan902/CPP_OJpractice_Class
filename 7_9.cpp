#include <iostream>
#include <string>
#include <vector>
using namespace std;

class FilePath {
private:
    string path;
public:
    FilePath(string p) : path(p) {}

    string simplifyPath() {
        vector<string> stack;
        int n = path.size();
        int i = 0;

        while (i < n) {
            while (i < n && path[i] == '/') i++;
            if (i == n) break;

            int start = i;
            while (i < n && path[i] != '/') i++;
            string part = path.substr(start, i - start);

            if (part == ".") {
                continue;
            } else if (part == "..") {
                if (!stack.empty()) stack.pop_back();
            } else {
                stack.push_back(part);
            }
        }

        if (stack.empty()) return "/";
        string res;
        for (string &s : stack) {
            res += "/" + s;
        }
        return res;
    }
};

int main() {
    string path;
    while (cin >> path) {
        FilePath fp(path);
        cout << fp.simplifyPath() << endl;
    }
    return 0;
}