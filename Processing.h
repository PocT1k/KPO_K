#ifndef KPO_K_PROCESSING
#define KPO_K_PROCESSING
#pragma once

#include <windows.h>

#include "Figures.h"


extern Missile missile;
extern Wall wall;


VOID CALLBACK TimerProc1(HWND hWnd, UINT message, UINT_PTR idEvent, DWORD dwTime) {
	missile.move();
}

VOID CALLBACK TimerProc2(HWND hWnd, UINT message, UINT_PTR idEvent, DWORD dwTime) {
	InvalidateRect(hWnd, NULL, TRUE);
}

#endif