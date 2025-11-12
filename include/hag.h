/*
#												#
#		© Chillaxe, 2025, GPL Licence v3.		#
#												#
*/

#ifndef CX_HAG_DEF
#define CX_HAG_DEF

#include <stdint.h>

typedef struct hag_window_internal_s hag_window_internal;

enum hag_gui_level {
	HAG_GUILEVEL_HARDWARE,
	HAG_GUILEVEL_SOFTWARE
};

enum hag_os {
	HAG_OS_WIN32,
	HAG_OS_OSX,
	HAG_OS_LINUX
};

enum hag_api {
	HAG_API_DX11,
	HAG_API_DX12,
	HAG_API_OPENGL,
	HAG_API_VULKAN
};

enum hag_wsys {
	HAG_WSYS_WIN32,
	HAG_WSYS_COCOA,
	HAG_WSYS_X11,
	HAG_WSYS_WAYLAND
};

typedef struct hag_gui_style_s {
	
} hag_gui_style;



typedef struct hag_properties_s {
	hag_gui_level gui_level;
	hag_api api;
	hag_os os;
	hag_wsys wsys;
} hag_properties;

typedef struct hag_window_s {
	hag_window_internal* internal;
	uint16_t width, height;
	hag_properties properties;
} hag_window;

typedef struct hag_gui_element_s {
	uint16_t width, height;
	hag_gui_style gui_style;
} hag_gui_element;

#endif