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

    int index = 0;
    Vector2 points[LINES_SIZES];

    for (int i = 0; i < LINES_SIZES; i++) {
        points[i] = (Vector2){-1, -1};
    }

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
            draw_line(chafacad, points, &index);
        }

        EndDrawing();
    }

    free(chafacad);
    free(statusBar);
    free(actionBar);

    UnloadFont(defaultFont);
    CloseWindow();

    return 0;
}
