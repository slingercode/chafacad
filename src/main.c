#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "raylib.h"
#include "chafacad.h"
#include "action-bar.h"

int main(void) {
    SetTraceLogLevel(LOG_ALL);
    ActionBar* actionBar = init_action_bar(ACTION_BAR_X, ACTION_BAR_Y, ACTION_BAR_WIDTH, ACTION_BAR_HEIGHT);

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, CHAFACAD);

    SetTargetFPS(60);
    SetExitKey(KEY_NULL);

    Font defaultFont = LoadFont("./assets/fonts/BerkeleyMono.otf");

    if (IsFontReady(defaultFont)) {
        SetTextureFilter(defaultFont.texture, TEXTURE_FILTER_BILINEAR);
    } else {
        defaultFont = GetFontDefault();
    }

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BACKGROUND_COLOR_PRIMARY);

        {
            handle_action_bar_visibility(actionBar);
            handle_action_bar_input(actionBar);
            draw_action_bar(actionBar, defaultFont);
        }

        EndDrawing();
    }

    UnloadFont(defaultFont);
    free(actionBar);
    CloseWindow();

    return 0;
}
