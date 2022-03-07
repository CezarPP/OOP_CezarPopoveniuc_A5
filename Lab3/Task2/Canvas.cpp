#include <cstdlib>
#include <iostream>
#include <cmath>
#include "Canvas.h"


Canvas::Canvas(int width, int height) {
    N = width;
    M = height;
    m = (char **) malloc(N * sizeof(char *));
    for (int i = 0; i < N; i++)
        m[i] = (char *) malloc(M * sizeof(char));
    Clear();
}

int euclideanDistanceInt(int a, int b, int x, int y) {
    return (int) sqrt((a - x) * (a - x) + (b - y) * (b - y));
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (euclideanDistanceInt(x, y, i, j) == ray)
                m[i][j] = ch;
}


void Canvas::FillCircle(int x, int y, int ray, char ch) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (euclideanDistanceInt(x, y, i, j) <= ray)
                m[i][j] = ch;
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    for (int j = left; j <= right; j++)
        m[top][j] = m[bottom][j] = ch;
    for (int i = top; i <= bottom; i++)
        m[i][left] = m[i][right] = ch;
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for (int i = top; i <= bottom; i++)
        for (int j = left; j <= right; j++)
            m[i][j] = ch;
}

void Canvas::SetPoint(int x, int y, char ch) {
    m[x][y] = ch;
}

void Canvas::Print() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            std::cout << m[i][j];
        std::cout << '\n';
    }
}

void Canvas::Clear() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            m[i][j] = ' ';
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    double panta = (double) (y2 - y1) / (double) (x2 - x1);
    double n = (double) y2 - (double) (panta * (double) x2);
    for (int x = x1; x <= x2; x++) {
        int y = (int) round(panta * (double) x + n);
        SetPoint(x, y, ch);
    }
}
