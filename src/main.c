#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "raylib.h"

#define CHAFACAD "ChafaCAD"
#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 600

#define ACTION_BAR_WIDTH 800
#define ACTION_BAR_HEIGHT 40
#define ACTION_BAR_Y 100
#define ACTION_BAR_SEGMENTS 32
#define ACTION_BAR_ROUNDNESS 0.5
#define ACTION_BAR_THICKNESS 2.0
#define ACTION_BAR_BORDER_COLOR CLITERAL(Color){ 255, 247, 184, 255 }

const int actionBarInitialX = (WINDOW_WIDTH - ACTION_BAR_WIDTH) / 2;

typedef struct ActionBar {
    int x;
    int y;
    int width;
    int height;
    bool isActive;
} ActionBar;

ActionBar* init_action_bar(int x, int y, int w, int h) {
    ActionBar* actionBar = (ActionBar*)malloc(sizeof(ActionBar));

    if (actionBar == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for Action Bar\n");
        exit(EXIT_FAILURE);
    }

    actionBar->x = x;
    actionBar->y = y;
    actionBar->width = w;
    actionBar->height = h;
    actionBar->isActive = false;

    return actionBar;
}

void handle_action_bar_visibility(ActionBar* actionBar) {
    if (!actionBar->isActive && ((IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT)) && IsKeyDown(KEY_ENTER))) {
        actionBar->isActive = true;
    }

    if (actionBar->isActive && IsKeyPressed(KEY_ESCAPE)) {
        actionBar->isActive = false;
    }
}

void draw_action_bar(ActionBar* actionBar) {
    DrawRectangleRoundedLinesEx(
        (Rectangle){actionBar->x, actionBar->y, actionBar->width, actionBar->height},
        ACTION_BAR_ROUNDNESS,
        ACTION_BAR_SEGMENTS,
        ACTION_BAR_THICKNESS,
        ACTION_BAR_BORDER_COLOR
    );

    DrawText("Test", actionBar->x + 10, actionBar->y + 14, 16, ACTION_BAR_BORDER_COLOR);
}

int main(void) {
    ActionBar* actionBar = init_action_bar(actionBarInitialX, ACTION_BAR_Y, ACTION_BAR_WIDTH, ACTION_BAR_HEIGHT);

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, CHAFACAD);

    SetTargetFPS(60);
    SetExitKey(KEY_NULL);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        handle_action_bar_visibility(actionBar);

        if (actionBar->isActive) {
            draw_action_bar(actionBar);
        }

        EndDrawing();
    }

    free(actionBar);
    CloseWindow();

    return 0;
}
