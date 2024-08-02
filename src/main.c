#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "raylib.h"
#include "chafacad.h"
#include "action-bar.h"
#include "status-bar.h"

int main(void) {
    SetTraceLogLevel(LOG_ALL);

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, CHAFACAD);

    Chafacad* chafacad = init_chafacad();
    StatusBar* statusBar = init_status_bar(STATUS_BAR_X, STATUS_BAR_Y, STATUS_BAR_WIDTH, STATUS_BAR_HEIGHT);
    ActionBar* actionBar = init_action_bar(ACTION_BAR_X, ACTION_BAR_Y, ACTION_BAR_WIDTH, ACTION_BAR_HEIGHT);

    Vector2* point1 = malloc(sizeof(Vector2));
    Vector2* point2 = malloc(sizeof(Vector2));

    point1->x = -1;
    point1->y = -1;

    point2->x = -1;
    point2->y = -1;

    SetTargetFPS(60);
    SetExitKey(KEY_NULL);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BACKGROUND_COLOR_PRIMARY);

        {
            draw_status_bar(statusBar, chafacad);
        }

        {
            handle_action_bar_visibility(actionBar, chafacad);
            handle_action_bar_input(actionBar);
            draw_action_bar(actionBar, chafacad);
        }

        {
            handle_draw_commands(chafacad);
            draw_line(chafacad, point1, point2);
        }

        EndDrawing();
    }

    UnloadFont(chafacad->defaultFont);
    CloseWindow();

    free(point1);
    free(point2);

    free(chafacad);
    free(statusBar);
    free(actionBar);

    return 0;
}
