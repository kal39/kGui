typedef int WindowId;

typedef struct ComponentId {
	int winIdx;
	int compIdx;
} ComponentId;

typedef struct Label {
	char *text;
} Label;

typedef struct TextBox {
	int editable;
	char *text;
	void (*fn)(char *);
} TextBox;

typedef struct Button {
	char *text;
	void (*fn)();
	int pressed;
} Button;

typedef struct Component {
	int width;
	int height;
	int type;
	union {
		Label label;
		TextBox texbox;
		Button button;
	} data;
} Component;

typedef struct Window {
	int x, y;
	char *title;

	int cols, rows;
	int gridWidth, gridHeight;
	Component *components;
} Window;

typedef struct Settings {
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

	Settings settings;
} KGuiState;