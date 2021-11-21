#include "kGui.h"

ComponentID add_component(ComponentID destId, int x, int y, Component component) {
	Component dest = kGS.components[destId];
	if (dest.type != 0) return -1;

	kGS.componentCount++;
	kGS.components = realloc(kGS.components, sizeof(Component) * kGS.componentCount);
	kGS.components[kGS.componentCount - 1] = component;

	dest.data.grid.components[x + y * dest.data.grid.cols] = kGS.componentCount - 1;

	return kGS.componentCount - 1;
}

void change_component_text(ComponentID compId, char *format, ...) {
	char *dest;

	switch (kGS.components[compId].type) {
		case 1:
			dest = kGS.components[compId].data.label.text;
			break;
		case 3:
			dest = kGS.components[compId].data.button.text;
			break;
		default:
			return;
	}

	char buff[MAX_TEXT_LENGTH];
	va_list args;
	va_start(args, format);
	vsnprintf(buff, MAX_TEXT_LENGTH, format, args);
	va_end(args);

	dest = realloc(dest, strlen(buff) + 1);
	memcpy(dest, buff, strlen(buff) + 1);
}

Component *_get_component(ComponentID compId) {
	return &kGS.components[compId];
}

void _draw_component(ComponentID compID, int x, int y) {
	if (compID < -1) return;
	Component *component = _get_component(compID);

	switch (component->type) {
		case 0:
			_draw_grid(&component->data.grid, x, y);
			break;
		case 1:
			_draw_label(&component->data.label, x, y);
			break;
		case 2:
			_draw_button(&component->data.button, x, y);
			break;
	}
}

void _process_component(ComponentID compID, int x, int y) {
	if (compID < -1) return;
	Component *component = _get_component(compID);

	switch (component->type) {
		case 0:
			_process_grid(&component->data.grid, x, y);
			break;
		case 2:
			_process_button(&component->data.button, x, y);
			break;
	}
}