#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
#include "raymath.h"
#include "chafacad.h"

Chafacad* init_chafacad() {
    Chafacad* chafacad = malloc(sizeof(Chafacad));

    if (chafacad == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for Chafacad\n");
        exit(EXIT_FAILURE);
    }

    const Font berkeleyFont = LoadFont("./assets/fonts/BerkeleyMono.otf");

    chafacad->mode = 1;
    chafacad->defaultFont = IsFontReady(berkeleyFont) ? berkeleyFont : GetFontDefault();

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

void draw_line(Chafacad* chafacad, Vector2* point1, Vector2* point2) {
    if ((point1->x != -1 && point1->y != -1) && (point2->x != -1 && point2->y != -1)) {
        DrawLineEx(*point1, *point2, LINE_GUIDE_THICKNESS, LINE_COLOR_PRIMARY);
    }

    if (chafacad->mode != MODE_DRAW) return;

    const Vector2 mousePosition = GetMousePosition();

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && (point1->x == -1 || point1->y == -1)) {
        *point1 = mousePosition;
    }

    if (point1->x != -1 && point1->y != -1) {
        Vector2 lineReference;

        const float distance = Vector2Distance(*point1, mousePosition);

        lineReference.x = (point1->x + distance);
        lineReference.y = point1->y;

        DrawLineEx(*point1, mousePosition, LINE_GUIDE_THICKNESS, LINE_COLOR_SECONDARY);
        DrawLineEx(*point1, lineReference, 0.5, LINE_COLOR_TERTIARY);
    }
}
