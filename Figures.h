#ifndef KPO_K_FIGURES
#define KPO_K_FIGURES

#include <windows.h>


class Location;
class Point;
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

class Missile : public Point {
protected:
	int weightLine = 1;
	int size = 101;
public:
	Missile(int x, int y);
	virtual void move(int offsetX, int offsetY);
	void onKeyDown(WPARAM wParam);
	void show(HDC hdc);
};

#endif
