#define CHAFACAD "ChafaCAD"
#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 600
#define FONT_SIZE_BASE 16
#define FONT_SIZE_MD 20
#define FONT_SIZE_SPACING 0.12
#define BACKGROUND_COLOR_PRIMARY CLITERAL(Color){ 17, 17, 17, 255 }
#define BACKGROUND_COLOR_SECONDARY CLITERAL(Color){ 25, 25, 25, 255 }
#define TEXT_COLOR_PRIMARY CLITERAL(Color){ 238, 238, 238, 255 }
#define TEXT_COLOR_SECONDARY CLITERAL(Color){ 246, 238, 180, 255 }
#define TEXT_COLOR_TERTIARY CLITERAL(Color){ 96, 96, 96, 255 }
#define LINE_COLOR_PRIMARY CLITERAL(Color){ 238, 238, 238, 255 }
#define LINE_COLOR_SECONDARY CLITERAL(Color){ 246, 238, 180, 255 }
#define LINE_COLOR_TERTIARY CLITERAL(Color){ 96, 96, 96, 255 }
#define LINE_COMPLETED_THICKNESS 2
#define LINE_GUIDE_THICKNESS 1
#define BORDER_COLOR_PRIMARY CLITERAL(Color){ 58, 58, 58, 255 }
#define BORDER_COLOR_SECONDARY CLITERAL(Color){ 131, 106, 33, 255 }
#define MODE_NORMAL_TEXT "Normal"
#define MODE_DRAW_TEXT "Draw"

typedef enum {
    MODE_NORMAL = 0,
    MODE_DRAW = 1,
} Mode;

typedef struct Chafacad {
  Mode mode;
  Font defaultFont;
} Chafacad;

Chafacad* init_chafacad();

void handle_draw_commands(Chafacad* chafacad);

void draw_line(Chafacad* chafacad, Vector2* point1, Vector2* point2);
