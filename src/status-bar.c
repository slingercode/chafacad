#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
#include "chafacad.h"
#include "status-bar.h"

StatusBar* init_status_bar(int x, int y, int w, int h) {
    StatusBar* statusBar = malloc(sizeof(StatusBar));

    if (statusBar == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for Status Bar\n");
        exit(EXIT_FAILURE);
    }

    statusBar->x = x;
    statusBar->y = y;
    statusBar->width = w;
    statusBar->height = h;

    return statusBar;
}

void draw_status_bar(StatusBar* statusBar, Chafacad* chafacad, Font font) {
    const char* modeText = chafacad->mode == MODE_NORMAL ? MODE_NORMAL_TEXT : MODE_DRAW_TEXT;
    const Vector2 modeTextSize = MeasureTextEx(font, modeText, FONT_SIZE_BASE, FONT_SIZE_SPACING);
    const int modeTextXAxis = STATUS_BAR_PADDING;
    const int modeTextYAxis = (int)(statusBar->y + (int)(statusBar->height - modeTextSize.y) / 2);
    const Vector2 modeTextAxis = {modeTextXAxis, modeTextYAxis};

    const Vector2 mousePosition = GetMousePosition();
    char mouseText[STATUS_BAR_MOUSE_COORDINATES_STR_SIZE];
    snprintf(mouseText, sizeof(mouseText), "(%.0f, %.0f)", mousePosition.x, mousePosition.y);

    const Vector2 mouseAxisTextSize = MeasureTextEx(font, mouseText, FONT_SIZE_BASE, FONT_SIZE_SPACING);
    const int mouseTextXAxis = (int)((WINDOW_WIDTH - mouseAxisTextSize.x) - STATUS_BAR_PADDING);
    const int mouseTextYAxis = (int)(statusBar->y + (int)(statusBar->height - mouseAxisTextSize.y) / 2);
    const Vector2 mouseTextAxis = {mouseTextXAxis, mouseTextYAxis};

    DrawRectangle(statusBar->x, statusBar->y, statusBar->width, statusBar->height, BACKGROUND_COLOR_SECONDARY);
    DrawTextEx(font, modeText, modeTextAxis, FONT_SIZE_BASE, FONT_SIZE_SPACING, TEXT_COLOR_PRIMARY);
    DrawTextEx(font, mouseText, mouseTextAxis, FONT_SIZE_BASE, FONT_SIZE_SPACING, TEXT_COLOR_PRIMARY);
}
