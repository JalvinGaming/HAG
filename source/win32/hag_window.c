#include <hag.h>
#include <windows.h>

LRESULT CALLBACK wndProc(HWND hwnd, UINT umsg, WPARAM wp, LPARAM lp) {
	switch(umsg) {
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}
	return DefWindowProcA(hwnd, umsg, wp, lp);
}

typedef struct hag_window_internal_s {
	HWND hwnd;
	MSG msg;
} hag_window_internal;

uint8_t hagCreateWindow(const uint16_t width, const uint16_t height, const char* title, const hag_properties properties, hag_window* window) {
	WNDCLASSEXA wc = {0};
	wc.cbSize = sizeof(WNDCLASSEXA);
	wc.lpfnWndProc = wndProc;
	wc.lpszClassName = title;
	wc.hInstance = GetModuleHandleA(NULL);
	RegisterClassExA(&wc);
	window = (hag_window*)calloc(1, sizeof(hag_window));
	if (window == NULL) return 1;
	window->title = (char*)calloc(strlen(title) + 1, sizeof(char));
	if (window->title == NULL) return 1;
	memcpy(window->title, title, sizeof(char) * (strlen(title) + 1));
	window->internal = (hag_window_internal*)calloc(1, sizeof(hag_window_internal));
	if (window->internal == NULL) return 1;
	window->internal->hwnd = CreateWindowExA(0, title, title, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, width, height, NULL, NULL, GetModuleHandleA(NULL), NULL);
	ShowWindow(window->internal->hwnd, 1);
	window->width = width;
	window->height = height;
	window->properties = properties;
	return 0;
}

uint8_t hagPollInput(hag_window* window) {
	while (PeekMessageA(&window->internal->msg, NULL, 0, 0, PM_REMOVE)) {
		TranslateMessage(&window->internal->msg);
		DispatchMessageA(&window->internal->msg);
	}
	return 0;
}