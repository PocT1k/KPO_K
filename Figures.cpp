#include "Figures.h"


Location::Location(double x, double y) {
	this->x = x;
	this->y = y;
}


Point::Point(double x, double y) : Location(x, y) {};

void Point::show(HDC hdc) {
	SetPixel(hdc, x, y, RGB(0, 0, 0));
}


MovingObject::MovingObject(double x, double y) : Point(x, y) {};


Missile::Missile(double x, double y) : MovingObject(x, y) {};

void Missile::move(double offsetX, double offsetY) {
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
	HPEN pen = CreatePen(PS_SOLID, rContour * 2 + 1, RGB(127, 127, 127)); //Контур
	SelectObject(hdc, pen);
	HBRUSH brush = CreateSolidBrush(RGB(191, 191, 191)); //Заливка
	SelectObject(hdc, brush);
	Ellipse(hdc, x - rFigure + rContour + 0.5, y - rFigure + rContour + 0.5,
		x + rFigure - rContour + 0.5, y + rFigure - rContour + 0.5);
	SelectObject(hdc, GetStockObject(NULL_BRUSH));

	pen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0)); //Контур
	SelectObject(hdc, pen);
	Ellipse(hdc, x - rFigure + 0.5, y - rFigure + 0.5, x + rFigure + 0.5, y + rFigure + 0.5);

	SelectObject(hdc, GetStockObject(BLACK_PEN));
	DeleteObject(pen);
}
