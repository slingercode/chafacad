#include "raylib.h"
#include "chafacad.h"

#define STATUS_BAR_WIDTH WINDOW_WIDTH
#define STATUS_BAR_HEIGHT 40
#define STATUS_BAR_X 0
#define STATUS_BAR_Y (int)(WINDOW_HEIGHT - STATUS_BAR_HEIGHT)
#define STATUS_BAR_PADDING_PERCENTAGE 0.05
#define STATUS_BAR_PADDING (int)((WINDOW_WIDTH * STATUS_BAR_PADDING_PERCENTAGE) / 2)

typedef struct StatusBar {
    int x;
    int y;
    int width;
    int height;
} StatusBar;

StatusBar* init_status_bar(int x, int y, int w, int h);

void draw_status_bar(StatusBar* statusBar, Font font);
