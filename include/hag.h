/*
#												#
#		© Chillaxe, 2025, GPL Licence v3.		#
#												#
*/

#ifndef CX_HAG_DEF
#define CX_HAG_DEF

#include <stdint.h>

typedef struct hag_window_internal_s hag_window_internal;

typedef enum hag_gui_level_s {
	HAG_GUILEVEL_HARDWARE,
	HAG_GUILEVEL_SOFTWARE
} hag_gui_level;
typedef enum hag_os_s {
	HAG_OS_WIN32,
	HAG_OS_OSX,
	HAG_OS_LINUX
} hag_os;
typedef enum hag_api_s {
	HAG_API_DX11,
	HAG_API_DX12,
	HAG_API_OPENGL,
	HAG_API_VULKAN
} hag_api;
typedef enum hag_wsys_s {
	HAG_WSYS_WIN32,
	HAG_WSYS_COCOA,
	HAG_WSYS_X11,
	HAG_WSYS_WAYLAND
} hag_wsys;

typedef struct hag_texture_internal_s hag_texture_internal;

typedef struct hag_texture_s {
	hag_texture_internal* internal;
	uint16_t width, height;
	void* data;
} hag_texture;

typedef struct hag_gui_button_style_s {
	uint16_t padding_left, padding_right, padding_top, padding_bottom;
	uint16_t max_width, max_height;
	uint8_t round_borders_setting;
	union {
		struct {uint16_t border_radius_bl, border_radius_br, border_radius_tl, border_radius_tr;} border_radius;
		hag_texture* texture_corner;
	};
	hag_texture* texture_edge;
} hag_gui_button_style;

typedef struct hag_gui_style_s {
	hag_gui_button_style* button_style;
} hag_gui_style;

typedef struct hag_properties_s {
	hag_gui_level level;
	hag_api api;
	hag_os os;
	hag_wsys wsys;
} hag_properties;

typedef struct hag_gui_element_s {
	uint16_t width, height;
	uint16_t x, y;
	hag_gui_style* gui_style;
	void* addon;
} hag_gui_element;

typedef struct hag_button_element_s {
	hag_gui_element* base;
	void* onClick;
} hag_button_element;

typedef struct hag_gui_s {
	hag_gui_element *elements;
	uint16_t num_elements;
	hag_gui_style* gui_style;
} hag_gui;

typedef struct hag_window_s {
	hag_window_internal* internal;
	uint16_t width, height;
	char* title;
	hag_properties properties;
} hag_window;

uint8_t hagCreateWindow(const uint16_t width, const uint16_t height, const char* title, const hag_properties properties, hag_window* window);

uint8_t hagPollInput(hag_window* window);

#endif