#include "Figures.h"


Location::Location(int x, int y) {
	this->x = x;
	this->y = y;
}


Point::Point(int x, int y) : Location(x, y) {};

void Point::show(HDC hdc) {
	SetPixel(hdc, x, y, RGB(0, 0, 0));
}


Missile::Missile(int x, int y) : Point(x, y) {};

void Missile::move(int offsetX, int offsetY) {
	this->x += offsetX;
	this->y += offsetY;
}

void Missile::onKeyDown(WPARAM wParam) {
	int step = 5;
	switch (wParam) {
	case 'W':
		move(0, -step);
		break;
	case 'S':
		move(0, step);
		break;
	case 'A':
		move(-step, 0);
		break;
	case 'D':
		move(step, 0);
		break;
	}
}

void Missile::show(HDC hdc) {
	HPEN pen = CreatePen(PS_SOLID, weightLine, RGB(0, 0, 0));
	SelectObject(hdc, pen);


	Ellipse(hdc, 0 + x, 0 + y, size + x, size + y);


	HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
	SelectObject(hdc, blueBrush);

	HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, redPen);

	Ellipse(hdc, 100, 100, 300, 300);


	SelectObject(hdc, GetStockObject(BLACK_PEN));
	SelectObject(hdc, GetStockObject(NULL_BRUSH));
	DeleteObject(pen);
}
