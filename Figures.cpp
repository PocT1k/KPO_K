#include "Figures.h"


extern Sizes sizes;


Location::Location(float x, float y) {
	this->x = x;
	this->y = y;
}


Point::Point(float x, float y) : Location(x, y) {};

void Point::show(HDC hdc) {
	SetPixel(hdc, x, y, RGB(0, 0, 0));
}


Wall::Wall(int border, char type) {
	this->border = border;
	switch (type){
	case 'r':
	case 'l':
	case 't':
	case 'b':
		this->type = type;
		break;
	default:
		MessageBox(NULL, L"Некорректная стена", L"Ошибка", MB_OK | MB_ICONINFORMATION);
		exit(1);
		break;
	}
}

void Wall::show(HDC hdc) {
	HPEN pen = CreatePen(PS_SOLID, this->weightLine * 2 + 1, RGB(0, 0, 0));
	SelectObject(hdc, pen);

	switch (this->type){
	case 'r':
		MoveToEx(hdc, this->border + weightLine, 0, NULL);
		LineTo(hdc,this->border + weightLine, sizes.window.bottom);
		break;
	case 'l':
		break;
	case 't':
		break;
	case 'b':
		break;
	default:
		break;
	}

	SelectObject(hdc, GetStockObject(BLACK_PEN));
	DeleteObject(pen);
}


Missile::Missile(float x, float y) : Point(x, y) {};

void Missile::setShift(float xShift, float yShift) {
	this->xShift += xShift;
	this->yShift += yShift;
}

void Missile::move() {
	if (xShift == 0 || yShift == 0) {
		xShift = 0;
		yShift = 0;

		return;
	}
	//Изменение координат
	x += xShift;
	y += yShift;

	//Перерасчёт скорости
	mShift = pow(xShift * xShift + yShift * yShift, 0.5); //Получение модуля скорости
	mShiftNew = mShift - 5 / mShift; //Применение формулы изменения скорости

	if (mShiftNew < 0.01) {
		xShift = 0;
		yShift = 0;

		return;
	}

	ratioShift = mShiftNew / mShift; //Высчитывание коэфециэнта уменьшения скорости
	//Пересчёт
	xShift = xShift * ratioShift;
	yShift = yShift * ratioShift;
}

//void Missile::onKeyDown(WPARAM wParam) {
//	int step = 5;
//	switch (wParam) {
//	case 'W':
//		move(0, -step);
//		break;
//	case 'S':
//		move(0, step);
//		break;
//	case 'A':
//		move(-step, 0);
//		break;
//	case 'D':
//		move(step, 0);
//		break;
//	}
//}

void Missile::show(HDC hdc) {
	HPEN pen = CreatePen(PS_SOLID, rContour * 2 + 1, RGB(127, 127, 127)); //Предконтур
	SelectObject(hdc, pen);
	HBRUSH brush = CreateSolidBrush(RGB(191, 191, 191)); //Заливка
	SelectObject(hdc, brush);
	Ellipse(hdc, x - rFigure + rContour + 0.5, y - rFigure + rContour + 0.5,
		x + rFigure - rContour + 0.5, y + rFigure - rContour + 0.5);
	SelectObject(hdc, GetStockObject(NULL_BRUSH));
	DeleteObject(brush);

	pen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0)); //Контур
	SelectObject(hdc, pen);
	Ellipse(hdc, x - rFigure + 0.5, y - rFigure + 0.5, x + rFigure + 0.5, y + rFigure + 0.5);

	SelectObject(hdc, GetStockObject(BLACK_PEN));
	DeleteObject(pen);
}
