#ifndef KPO_K_FIGURES
#define KPO_K_FIGURES
#pragma once

#include <windows.h>
#include <cmath>


class Location;
class Point;
class Wall;
class Missile; //������

//class Sizes;


class Location {
protected:
	float x;
	float y;
public:
	Location(float x, float y);
};

class Point : public Location {
public:
	Point(float x, float y);
	virtual void show(HDC hdc);
};

class Wall {
	int weightLine = 5;
	int border; //��� �������
	char type; //� ����� �������
public:
	Wall(int border, char type);
	void show(HDC hdc);
};

class Missile : public Point {
protected:
	int rContour = 3;
	int rFigure = 25;

	bool statical = true; //����� �� ������ ���������

	//�������
	float mSpeed = 0; //�� ������
	//float xSpeed = 0;
	//float ySpeed = 0;

	float mShift = 0;
	float mShiftNew = 0;
	float ratioShift = 0;
	float xShift = 0; //�������� �� X
	float yShift = 0; //�������� �� Y
public:
	Missile(float x, float y);
	void setShift(float xShift, float yShift);
	virtual void move();
	//void onKeyDown(WPARAM wParam);
	void show(HDC hdc);
};

class Sizes {
public:
	RECT window = { 0, 0, 1000, 500 };
};


#endif
