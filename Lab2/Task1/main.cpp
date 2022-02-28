#include "NumberList.h"

int main() {
    NumberList N{};
    N.Init();
    N.Add(3);
    N.Add(1);
    N.Add(10);
    // add some numbers
    N.Print();
    // print them
    N.Sort();
    // sort them
    N.Print();
    N.Init(); // make a new list
    for (int i = 1; i <= 100; i++)
        if (N.Add(i) == 0)
            break;
    // adds until full
    N.Print();
    return 0;
}
