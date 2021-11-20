typedef int WindowId;
typedef int ComponentID;

typedef struct Component Component;
typedef struct Grid {
	int cols;
	int rows;

	int cellWidth;
	int cellHeight;

	ComponentID *components;
} Grid;

typedef struct Label {
	char *text;
} Label;

typedef struct TextBox {
	char *text;
	void (*fn)(char *);
} TextBox;

typedef struct Button {
	char *text;
	int width;
	int height;
	void (*fn)();
	int pressed;
} Button;

typedef struct Component {
	int type;
	union {
		Grid grid;
		Label label;
		TextBox texbox;
		Button button;
	} data;
} Component;

typedef struct Window {
	int x, y;
	char *title;

	ComponentID grid;
} Window;

typedef struct Settings {
	int padding;

	int fontSize;
	Color fontColor;

	Color windowColor;

	int titleBarHeight;
	Color titleBarColor;

	int borderSize;
	Color borderColor;

	int buttonBorderSize;
	Color buttonReleasedColor;
	Color buttonPressedColor;

} Settings;

typedef struct KGuiState {
	int windowCount;
	Window *windows;

	int componentCount;
	Component *components;

	Settings settings;
} KGuiState;