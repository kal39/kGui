#include "kGui.h"

ComponentId add_component(WindowId id, int x, int y, Component c) {
	Window *w = &kGS.windows[id];

	w->components[x + y * w->cols] = c;
	if (c.width > w->gridWidth) w->gridWidth = c.width;
	if (c.height > w->gridHeight) w->gridHeight = c.height;

	return (ComponentId){id, x + y * w->cols};
}

void remove_component(ComponentId id) {
	kGS.windows[id.winIdx].components[id.compIdx] = EMPTY_COMPONENT;
}

ComponentId get_component_id(WindowId id, int x, int y) {
	return (ComponentId){id, x + y * kGS.windows[id].cols};
}