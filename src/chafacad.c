#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
#include "chafacad.h"

Chafacad* init_chafacad() {
    Chafacad* chafacad = malloc(sizeof(Chafacad));

    if (chafacad == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for Chafacad\n");
        exit(EXIT_FAILURE);
    }

  chafacad->mode = 1;

  return chafacad;
}

/**
 * TODO: ESC to cancel the draw of the current point and if
 * there are no points return to normal mode
 */
void handle_draw_commands(Chafacad* chafacad) {
    if (chafacad->mode == MODE_DRAW && IsKeyPressed(KEY_ESCAPE)) {
        chafacad->mode = MODE_NORMAL;
    }
}

void draw_line(Chafacad* chafacad, Vector2* points, int* index) {
    if (chafacad->mode != MODE_DRAW) return;

    const Vector2 mousePosition = GetMousePosition();

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        points[*index] = mousePosition;
        (*index)++;
    }

    for (int i = 0; i < *index; i++) {
        if (points[i].x > 0 && points[i].y > 0) {
            if (points[i + 1].x > 0 && points[i + 1].y > 0) {
                DrawLineEx(points[i], points[i + 1], LINE_COMPLETED_THICKNESS, LINE_COLOR_PRIMARY);
            } else {
                DrawLineEx(points[i], mousePosition, LINE_GUIDE_THICKNESS, LINE_COLOR_SECONDARY);
            }
        }
    }
}
