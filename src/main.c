#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "raylib.h"

#define CHAFACAD "ChafaCAD"
#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 600
#define FONT_SIZE_MD 20
#define BACKGROUND_COLOR_PRIMARY CLITERAL(Color){ 17, 17, 17, 255 }
#define BACKGROUND_COLOR_SECONDARY CLITERAL(Color){ 25, 25, 25, 255 }
#define TEXT_COLOR_PRIMARY CLITERAL(Color){ 238, 238, 238, 255 }
#define TEXT_COLOR_SECONDARY CLITERAL(Color){ 246, 238, 180, 255 }
#define TEXT_COLOR_TERTIARY CLITERAL(Color){ 34, 34, 34, 255 }
#define BORDER_COLOR_PRIMARY CLITERAL(Color){ 58, 58, 58, 255 }
#define BORDER_COLOR_SECONDARY CLITERAL(Color){ 131, 106, 33, 255 }

#define ACTION_BAR_WIDTH 800
#define ACTION_BAR_HEIGHT 40
#define ACTION_BAR_X (int)((WINDOW_WIDTH - ACTION_BAR_WIDTH) / 2)
#define ACTION_BAR_Y 100
#define ACTION_BAR_SEGMENTS 32
#define ACTION_BAR_ROUNDNESS 0.5
#define ACTION_BAR_THICKNESS 1.5
#define ACTION_BAR_PADDING_PERCENTAGE 0.10

typedef struct ActionBar {
    int x;
    int y;
    int width;
    int height;
    bool isActive;
    char content[256];
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
    actionBar->content[0] = '\0';

    return actionBar;
}

void handle_action_bar_visibility(ActionBar* actionBar) {
    if (!actionBar->isActive && ((IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT)) && IsKeyDown(KEY_ENTER))) {
        actionBar->isActive = true;
    }

    if (actionBar->isActive && IsKeyPressed(KEY_ESCAPE)) {
        actionBar->isActive = false;
        actionBar->content[0] = '\0';
    }
}

void handle_action_bar_input(ActionBar* actionBar) {
    if (!actionBar->isActive) return;

    int keyPressed = GetCharPressed();

    while (keyPressed > 0) {
        int contentLength = strlen(actionBar->content);

         if (keyPressed >= 32 && keyPressed <= 125) {
            actionBar->content[contentLength] = (char)keyPressed;
            actionBar->content[contentLength + 1] = '\0';
        }

        keyPressed = GetCharPressed();
    }

    if (IsKeyPressed(KEY_BACKSPACE)) {
        int contentLength = strlen(actionBar->content);

        if (contentLength > 0) {
            actionBar->content[contentLength - 1] = '\0';
        }
    }
}

void draw_action_bar(ActionBar* actionBar) {
    if (!actionBar->isActive) return;

    Rectangle rectangle = (Rectangle){actionBar->x, actionBar->y, actionBar->width, actionBar->height};

    DrawRectangleRoundedLinesEx(
        rectangle,
        ACTION_BAR_ROUNDNESS,
        ACTION_BAR_SEGMENTS,
        ACTION_BAR_THICKNESS,
        BORDER_COLOR_SECONDARY
    );

    const int x = ((WINDOW_WIDTH - (int)(actionBar->width - (actionBar->width * ACTION_BAR_PADDING_PERCENTAGE))) / 2);
    const int y = (actionBar->y + (int)(actionBar->height / 4));

    /** TODO: Improve logic of the text coordinates, the text always should be in the center of the `height` */
    if (strlen(actionBar->content) == 0) {
        DrawText("Type a command", x, y, FONT_SIZE_MD, TEXT_COLOR_TERTIARY);
    } else {
        DrawText(actionBar->content, x, y, FONT_SIZE_MD, TEXT_COLOR_PRIMARY);
    }
}

int main(void) {
    SetTraceLogLevel(LOG_ALL);
    ActionBar* actionBar = init_action_bar(ACTION_BAR_X, ACTION_BAR_Y, ACTION_BAR_WIDTH, ACTION_BAR_HEIGHT);

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, CHAFACAD);

    SetTargetFPS(60);
    SetExitKey(KEY_NULL);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BACKGROUND_COLOR_PRIMARY);

        {
            handle_action_bar_visibility(actionBar);
            handle_action_bar_input(actionBar);
            draw_action_bar(actionBar);
        }

        EndDrawing();
    }

    free(actionBar);
    CloseWindow();

    return 0;
}
