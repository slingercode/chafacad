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

    Chafacad* chafacad = init_chafacad();
    StatusBar* statusBar = init_status_bar(STATUS_BAR_X, STATUS_BAR_Y, STATUS_BAR_WIDTH, STATUS_BAR_HEIGHT);
    ActionBar* actionBar = init_action_bar(ACTION_BAR_X, ACTION_BAR_Y, ACTION_BAR_WIDTH, ACTION_BAR_HEIGHT);

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, CHAFACAD);

    Vector2* point1 = malloc(sizeof(Vector2));
    Vector2* point2 = malloc(sizeof(Vector2));

    point1->x = -1;
    point1->y = -1;

    point2->x = -1;
    point2->y = -1;

    Font defaultFont = LoadFont("./assets/fonts/BerkeleyMono.otf");

    if (IsFontReady(defaultFont)) {
        SetTextureFilter(defaultFont.texture, TEXTURE_FILTER_BILINEAR);
    } else {
        defaultFont = GetFontDefault();
    }

    SetTargetFPS(60);
    SetExitKey(KEY_NULL);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BACKGROUND_COLOR_PRIMARY);

        {
            draw_status_bar(statusBar, chafacad, defaultFont);
        }

        {
            handle_action_bar_visibility(actionBar, chafacad);
            handle_action_bar_input(actionBar);
            draw_action_bar(actionBar, defaultFont);
        }

        {
            handle_draw_commands(chafacad);
            draw_line(chafacad, point1, point2);
        }

        EndDrawing();
    }

    free(point1);
    free(point2);

    free(chafacad);
    free(statusBar);
    free(actionBar);

    UnloadFont(defaultFont);
    CloseWindow();

    return 0;
}
