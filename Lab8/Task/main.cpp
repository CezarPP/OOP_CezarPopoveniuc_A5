#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <map>
#include <queue>

using namespace std;

struct compareClass {
    bool operator()(const pair<string, int> &a, const pair<string, int> &b) {
        return !(a.second > b.second || (a.second == b.second && a.first < b.first));
    }
};


int main() {
    priority_queue<string, vector<pair<string, int>>, compareClass> q;
    const char sep[] = " .,!?";
    string phrase;
    map<string, int> m;
    ifstream fin("text.in");

    getline(fin, phrase);
    size_t i = phrase.find_first_not_of(sep);
    while (i != std::string::npos) {
        string crtWord;
        size_t j;
        for (j = i; j < phrase.size() and strchr(sep, phrase[j]) == nullptr; j++)
            crtWord += phrase[j];
        for (char &it: crtWord)
            it = (char) tolower(it);
        m[crtWord]++;
        i = phrase.find_first_not_of(sep, j);
    }

    for (const auto &it: m)
        q.push(make_pair(it.first, it.second));
    while (!q.empty()) {
        cout << q.top().first << ' ' << q.top().second << '\n';
        q.pop();
    }

    return 0;
}
