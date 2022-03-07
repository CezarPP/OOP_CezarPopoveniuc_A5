#include "Canvas.h"
int main() {
    int width = 60, height = 60;
    Canvas c(width, height);
    c.DrawRect(20, 20, 40, 40, 'r');
    c.FillRect(10, 10, 15, 15, 'a');
    c.DrawCircle(10, 10, 4, 'c');
    c.FillCircle(40, 40, 5, 'g');
    c.SetPoint(1, 2, 'y');
    c.DrawLine(1, 1, 50, 50, 'l');
    c.DrawLine(4, 5, 10, 20, 'l');
    c.Print();
    return 0;
}
