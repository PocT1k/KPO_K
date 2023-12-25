#ifndef KPO_K_FIGURES
#define KPO_K_FIGURES

#include <windows.h>

//#pragma once


class Location;
class Point;

class MovingObject;
class Missile; //������


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

class MovingObject : public Point {
public:
	MovingObject(double x, double y);
	virtual void move(double offsetX, double offsetY) = 0;
};

class Missile : public MovingObject {
protected:
	int rContour = 3;
	int rFigure = 25;

	bool statical = true; //����� �� ������ ���������

	//�������
	double mSpeed = 0; //�� ������
	double xShift = 0;
	double yShift = 0;

	double xSpeed = 0; //�������� �� X
	double ySpeed = 0; //�������� �� Y
public:
	Missile(double x, double y);
	virtual void move(double offsetX, double offsetY) override;
	void onKeyDown(WPARAM wParam);
	void show(HDC hdc);
};


#endif
