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

class MyException : exception {
protected:
    string exceptionString;
public:
    MyException(const string &s) {
        exceptionString = s;
    }

    const char *what() const noexcept override {
        return exceptionString.c_str();
    }
};

struct OpenFileException : MyException {
    OpenFileException(const string &fileName) : MyException(fileName) {
        string cantOpen = "can't open file ";
        exceptionString = cantOpen + exceptionString;
    }
};

struct ReadFileException : MyException {
    ReadFileException(const string &fileName) : MyException(fileName) {
        string cantRead = "can't read file ";
        exceptionString = cantRead + exceptionString;
    }
};

struct WriteFileException : MyException {
    WriteFileException(const string &fileName) : MyException(fileName) {
        string cantRead = "can't write file ";
        exceptionString = cantRead + exceptionString;
    }
};

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
            if(crtLine.empty())
                continue;
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
            } else {
                try {
                    it->second(args);
                }
                catch (MyException &e) {
                    cerr << e.what() << '\n';
                }
                catch (bad_alloc &e) {
                    cerr << "Bad alloc " << e.what() << '\n';
                }
                catch (exception &e) {
                    cerr << "Some other exception occurred\n";
                    cerr << e.what() << '\n';
                }
            }
            delete[] s;
        }
    }
};

void CommandManager::add(const string &name, function<void(vector<string>)> fn) {
    commands[name] = fn;
}

int main() {
    CommandManager manager;
    // prints pong!
    auto ping = [](const vector<string> &args) {
        cout << "pong!" << '\n';
        if (!cout)
            throw WriteFileException("Stdout");
    };
    auto count = [](const vector<string> &args) {
        cout << args.size() << '\n';
        if (!cout)
            throw WriteFileException("Stdout");
    };
    auto append = [](vector<string> args) {
        ofstream fout;
        fout.open(args[0], ios_base::app);
        if (fout.fail())
            throw OpenFileException(args[0]);
        fout << ' ';
        if (!fout)
            throw WriteFileException(args[0]);
        for (size_t i = 1; i < args.size(); i++) {
            fout << args[i] << ' ';
            if (!fout)
                throw WriteFileException(args[0]);
        }
    };

    auto times = [cnt = 0](const vector<string> &args) mutable {
        cnt++;
        cout << cnt << '\n';
        if (!cout)
            throw WriteFileException("Stdout");
    };
    auto copy = [](vector<string> args) {
        ifstream fin;
        ofstream fout;
        fin.open(args[0], ifstream::binary);
        fout.open(args[1], ifstream::binary);
        if (fin.fail())
            throw OpenFileException(args[0]);
        if (fout.fail())
            throw OpenFileException(args[1]);
        char buf[4096];
        while (true) {
            size_t read = fin.readsome(buf, 4096);
            if (!fin)
                throw ReadFileException(args[0]);
            fout.write(buf, 4096);
            if (!fout)
                throw WriteFileException(args[1]);
            if (read != 4096)
                break;
        }
    };
    auto sortSize = [](vector<string> args) {
        sort(args.begin(), args.end(), [](const string &A, const string &B) {
            return (A.size() < B.size() || (A.size() == B.size() && A < B));
        });
        for_each(args.begin(), args.end(), [](const string &A) {
            cout << A << ' ';
            if (!cout)
                throw WriteFileException("Stdout");
        });
        cout << '\n';
        if (!cout)
            throw WriteFileException("Stdout");
    };
    auto allocateSomeMemory = [](vector<string> args) {
        int amount = strtol(args[0].c_str(), nullptr, 10);
        char *newMemoryPtr = new char[amount];
        return newMemoryPtr;
    };

    manager.add("ping", ping);
    manager.add("count", count);
    manager.add("append", append);
    manager.add("times", times);
    manager.add("copy", copy);
    manager.add("sort_size", sortSize);
    manager.add("allocate", allocateSomeMemory);
    manager.run();
}