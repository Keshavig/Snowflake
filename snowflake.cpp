#include <cmath>
#include <iostream>

#include "./depend/raylib/include/raylib.h"

constexpr int SCREEN_FACTOR = 80;
constexpr int WIDTH = 16*SCREEN_FACTOR;
constexpr int HEIGHT =  9*SCREEN_FACTOR;
constexpr int BRANCHES = 10;
constexpr float BRANCH_ANGLE = 2*3.141592/(float)BRANCHES;
constexpr float BRANCH_LEN = 1.8*SCREEN_FACTOR;

constexpr float THICK = 5.0f;

typedef Vector2 vec2;

void drawBranches(const int branches, const vec2 center, const float thickness, float hue, const float len, const size_t level) {
    if (level <= 0) return;
    float branch_angle = 2*PI/branches;
    vec2 branch = {.x = 0, .y = 0};

    for (size_t i = 0; i <= BRANCHES-1; ++i) {
        branch = { center.x + static_cast<float>(cos(branch_angle * i)) * len, center.y + static_cast<float>(sin(branch_angle * i)) * len};
        DrawLineEx(center, branch, thickness, ColorFromHSV(hue, 1.0, 1.0));
        drawBranches(branches, branch, thickness*0.8, hue+50.0f, len*0.5, level-1);
    }

}

int main(void) {
    static int numberOfBranches, flakesLevel;
    std::cout << "Enter #Branches and Flakes Level: ";
    std::cin >> numberOfBranches >> flakesLevel;

    InitWindow(WIDTH, HEIGHT, "Hello From Raylib");

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        if (GetKeyPressed() == KEY_C || GetKeyPressed() == KEY_Q) {
            CloseWindow();
            return 0;
        }

        drawBranches(numberOfBranches, {static_cast<float>(GetScreenWidth() * 0.5), static_cast<float>(GetScreenHeight() * 0.5)}, THICK, 150.0f, BRANCH_LEN, flakesLevel);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
