#ifndef KPO_K_FIGURES
#define KPO_K_FIGURES

#include <windows.h>


class Location;
class Point;
class Face;


class Location
{
protected:
	int x;
	int y;
public:
	Location(int x, int y);
};

class Point : public Location
{
public:
	Point(int x, int y);
	virtual void show(HDC hdc);
	virtual void move(int offsetX, int offsetY);
};

class Face : public Point
{
protected:
	int weightLine = 4;
public:
	Face(int x, int y);
	void onKeyDown(WPARAM wParam);
	void show(HDC hdc);
};

#endif
