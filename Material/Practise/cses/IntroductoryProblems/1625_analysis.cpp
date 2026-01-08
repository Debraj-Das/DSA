#include <iostream>
using namespace std;

const int N = 7;

int grid[N + 2][N + 2];
string path;
int total;

void search(int y, int x, int c) {
    if (grid[y][x]) return;

    if (y == N && x == 1) {
        if (c == N * N) total++;
        return;
    }

    bool down = grid[y + 1][x];
    bool up = grid[y - 1][x];
    bool left = grid[y][x - 1];
    bool right = grid[y][x + 1];
    if (down && up && !left && !right) return;
    if (!down && !up && left && right) return;

    char d = path[c - 1];
    grid[y][x] = 1;
    if (d == '?' || d == 'D') search(y + 1, x, c + 1);
    if (d == '?' || d == 'U') search(y - 1, x, c + 1);
    if (d == '?' || d == 'L') search(y, x - 1, c + 1);
    if (d == '?' || d == 'R') search(y, x + 1, c + 1);
    grid[y][x] = 0;
}

int main() {
    for (int i = 0; i <= N + 1; i++) {
        grid[0][i] = grid[N + 1][i] = 1;
        grid[i][0] = grid[i][N + 1] = 1;
    }

    cin >> path;
    search(1, 1, 1);
    cout << total << "\n";
}