#ifndef KPO_K_PROCESSING
#define KPO_K_PROCESSING
#pragma once

#include <windows.h>

#include "Figures.h"


extern Missile missile(25, 25);
extern Wall wall(255, 'r');

VOID CALLBACK TimerProc(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime) {
	//missile.move(1, 0.1);
	InvalidateRect(hwnd, NULL, TRUE);
}

#endif