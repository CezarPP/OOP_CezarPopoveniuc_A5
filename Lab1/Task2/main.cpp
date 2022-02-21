#include <iostream>
#include <cstring>

#define ll long long
using namespace std;
// this is actually the first task
ll customAtoi(char *s) {
    ll ans = 0;
    int N = (int) strlen(s), i = 0;
    while (s[i] == '0')
        i++;
    bool isNegative = false;
    if (s[i] == '-') {
        isNegative = true;
        i++;
    }
    for (; s[i] != 0 && s[i] != '\n' && s[i] != ' '; i++)
        ans = ans * 10 + (s[i] - '0');
    if (isNegative)
        ans = -ans;
    return ans;
}

int main() {
    ll sum = 0;
    FILE *fp;
    if (fopen_s(&fp, "in.txt", "r") != 0) {
        printf("Couldn't open file\n");
    } else {
        printf("File opened successfully!\n");
        char myString[200];
        while (fgets(myString, 200, fp))
            sum += customAtoi(myString);
    }
    printf("%lld", sum);
    return 0;
}
