#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "raylib.h"
#include "chafacad.h"
#include "action-bar.h"

ActionBar* init_action_bar(int x, int y, int w, int h) {
    ActionBar* actionBar = malloc(sizeof(ActionBar));

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

    if (actionBar->isActive && IsKeyPressed(KEY_ESCAPE) && strlen(actionBar->content) == 0) {
        actionBar->isActive = false;
    }
}

void handle_action_bar_input(ActionBar* actionBar) {
    if (!actionBar->isActive) return;

    int keyPressed = GetCharPressed();
    int contentLength = strlen(actionBar->content);

    while (keyPressed > 0) {
        // The validation of the `ACTION_BAR_MAX_CONTENT` is subtracting 1 in order to add the final char as `NULL`
        if ((keyPressed >= 32 && keyPressed <= 125) && (contentLength <= (ACTION_BAR_MAX_CONTENT - 1))) {
            actionBar->content[contentLength] = (char)keyPressed;
            actionBar->content[contentLength + 1] = '\0';
        }

        keyPressed = GetCharPressed();
        contentLength = strlen(actionBar->content);
    }

    // TODO: Handle key pressed delete chars
    if (IsKeyPressed(KEY_BACKSPACE)) {
        if (contentLength > 0) {
            actionBar->content[contentLength - 1] = '\0';
        }
    }

    if (IsKeyPressed(KEY_ESCAPE)) {
        actionBar->content[0] = '\0';
    }
}

void draw_action_bar(ActionBar* actionBar, Font font) {
    if (!actionBar->isActive) return;

    const Rectangle rectangle = {actionBar->x, actionBar->y, actionBar->width, actionBar->height};
    const bool isTextEmpty = strlen(actionBar->content) == 0;
    const char* text = isTextEmpty ? ACTION_BAR_PLACEHOLDER : actionBar->content;
    const Color textColor = isTextEmpty ? TEXT_COLOR_TERTIARY : TEXT_COLOR_PRIMARY;
    const Vector2 textSize = MeasureTextEx(font, text, FONT_SIZE_MD, FONT_SIZE_SPACING);
    const int textXAxis = (int)((WINDOW_WIDTH - (int)(actionBar->width - (actionBar->width * ACTION_BAR_PADDING_PERCENTAGE))) / 2);
    const int textYAxis = (int)(actionBar->y + (int)(actionBar->height - textSize.y) / 2);
    const Vector2 textAxis = {textXAxis, textYAxis};
    
    DrawTextEx(font, text, textAxis, FONT_SIZE_MD, FONT_SIZE_SPACING, textColor);
    DrawRectangleRoundedLinesEx(rectangle, ACTION_BAR_ROUNDNESS, ACTION_BAR_SEGMENTS, ACTION_BAR_THICKNESS, BORDER_COLOR_SECONDARY);
}
