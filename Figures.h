#ifndef KPO_K_FIGURES
#define KPO_K_FIGURES
#pragma once

#include <windows.h>


class Location;
class Point;

class Wall;

class Missile; //Снаряд


class Location {
protected:
	double x;
	double y;
public:
	Location(double x, double y);
};

class Point : public Location {
public:
	Point(double x, double y);
	virtual void show(HDC hdc);
};

class Wall {
	int weightLine = 5;
	int border; //Где граница
	char type; //В какую сторону
public:
	Wall(int border, char type);
	void show(HDC hdc);
};

class Missile : public Point {
protected:
	int rContour = 3;
	int rFigure = 25;

	bool statical = true; //Может ли объект двигаться

	//Скрости
	double mSpeed = 0; //По модулю
	double xShift = 0;
	double yShift = 0;

	double xSpeed = 0; //Скорость по X
	double ySpeed = 0; //Скорость по Y
public:
	Missile(double x, double y);
	virtual void move(double offsetX, double offsetY);
	//void onKeyDown(WPARAM wParam);
	void show(HDC hdc);
};


#endif
