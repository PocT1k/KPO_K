#ifndef KPO_K_FIGURES
#define KPO_K_FIGURES

#include <windows.h>

//#pragma once


class Location;
class Point;

class MovingObject;
class Missile; //Снаряд


class Location {
protected:
	int x;
	int y;
public:
	Location(int x, int y);
};

class Point : public Location {
public:
	Point(int x, int y);
	virtual void show(HDC hdc);
};

class MovingObject : public Point {
public:
	MovingObject(int x, int y);
	virtual void move(int offsetX, int offsetY) = 0;
};

class Missile : public MovingObject {
protected:
	int weightContour = 1;
	int size = 101;
public:
	Missile(int x, int y);
	virtual void move(int offsetX, int offsetY) override;
	void onKeyDown(WPARAM wParam);
	void show(HDC hdc);
};


#endif
