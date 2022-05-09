// the CommandManager class should implement a mini terminal that receive commands and dispatches them.
// example: copy a.jpg b.jpg
// this will search the map for a "copy" command, and if it finds it, it will invoke its callback with a vector made of {"a.jpg", "b.jpg"}
// no global variables allowed
#include <map>
#include <vector>
#include <string>
#include <iterator>
#include <functional>
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

class CommandManager {
private:
    map<string, function<void(vector<string>)>> commands;

public:
    void add(const string &name, function<void(vector<string>)> fn);

    void run() {
        auto toLowerString = [](const string &A) {
            string B = A;
            for (char &it: B)
                it = (char) tolower(it);
            return B;
        };
        while (true) {
            string crtLine;
            getline(cin, crtLine);
            if (toLowerString(crtLine) == "stop")
                break;
            char *s = new char[(int) crtLine.size() + 1];
            strcpy(s, crtLine.c_str());
            char *p = strtok(s, " ");
            char *commandName = p;
            vector<string> args;
            p = strtok(nullptr, " ");
            while (p) {
                string aux(p);
                args.emplace_back(p);
                p = strtok(nullptr, " ");
            }
            auto it = commands.find(commandName);
            if (it == commands.end()) {
                puts("Didn't find any command with that name\n");
            } else
                it->second(args);
            delete[] s;
        }
    }
};

void CommandManager::add(const string &name, function<void(vector<string>)> fn) {
    commands[name] = fn;
}

int main() {
    CommandManager manager;
    unsigned number_of_errors = 0;
    // prints pong!
    auto ping = [](const vector<string> &args) {
        cout << "pong!" << '\n';
    };
    auto count = [](const vector<string> &args) {
        cout << args.size() << '\n';
    };
    auto append = [&number_of_errors](vector<string> args) {
        ofstream fout;
        fout.open(args[0], ios_base::app);
        if (fout.fail())
            number_of_errors++;
        fout << ' ';
        for (size_t i = 1; i < args.size(); i++)
            fout << args[i] << ' ';
    };

    auto times = [cnt = 0](const vector<string> &args) mutable {
        cnt++;
        cout << cnt << '\n';
    };
    auto copy = [&number_of_errors](vector<string> args) {
        ifstream fin;
        ofstream fout;
        fin.open(args[0]);
        fout.open(args[1]);
        if (fin.fail() || fout.fail())
            number_of_errors++;
        string in;
        while (getline(fin, in)) {
            fout << in;
        }
    };
    auto sortSize = [](vector<string> args) {
        sort(args.begin(), args.end(), [](const string &A, const string &B) {
            return (A.size() < B.size() || (A.size() == B.size() && A < B));
        });
        for_each(args.begin(), args.end(), [](const string &A) {
            cout << A << ' ';
        });
        cout << '\n';
    };
    auto errors = [number_of_errors](const vector<string> &args) {
        cout << "The current error count is " << number_of_errors << '\n';
    };
    manager.add("ping", ping);
    manager.add("count", count);
    manager.add("append", append);
    manager.add("times", times);
    manager.add("copy", copy);
    manager.add("sort_size", sortSize);
    manager.add("errors", errors);
    manager.run();
    printf("number of errors: %u\ndone!\n", number_of_errors);
}