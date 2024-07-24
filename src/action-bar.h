#include "raylib.h"
#include "chafacad.h"

#define ACTION_BAR_WIDTH 800
#define ACTION_BAR_HEIGHT 40
#define ACTION_BAR_X (int)((WINDOW_WIDTH - ACTION_BAR_WIDTH) / 2)
#define ACTION_BAR_Y 100
#define ACTION_BAR_MAX_CONTENT 256
#define ACTION_BAR_SEGMENTS 32
#define ACTION_BAR_ROUNDNESS 0.5
#define ACTION_BAR_THICKNESS 1.5
#define ACTION_BAR_PLACEHOLDER "Type a command"
#define ACTION_BAR_PADDING_PERCENTAGE 0.10

typedef struct ActionBar {
    int x;
    int y;
    int width;
    int height;
    bool isActive;
    char content[ACTION_BAR_MAX_CONTENT];
} ActionBar;

ActionBar* init_action_bar(int x, int y, int w, int h);

void handle_action_bar_visibility(ActionBar* actionBar);

void handle_action_bar_input(ActionBar* actionBar);

void draw_action_bar(ActionBar* actionBar, Font font);
