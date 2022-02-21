#include <bits/stdc++.h>

#define LEN_MAX 1005
using namespace std;
char s[LEN_MAX];

int main() {
    scanf("%[^\n]%*c", s);
    vector<string> words;
    char *p = strtok(s, " .,");
    while (p != nullptr) {
        string crt(p);
        words.push_back(crt);
        p = strtok(nullptr, " .,");
    }
    sort(words.begin(), words.end(), [](const string &A, const string &B) {
        return (A.size() > B.size() || (A.size() == B.size() && A < B));
    });
    for (const auto &it: words) {
        strcpy(s, it.c_str());
        printf("%s\n", s);
    }
    return 0;
}
