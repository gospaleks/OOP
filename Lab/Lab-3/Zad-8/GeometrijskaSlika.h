#pragma once
class GeometrijskaSlika
{
private:
	int R, G, B;
	double x, y;
public:
	GeometrijskaSlika();
	GeometrijskaSlika(int r, int g, int b, double xx = 0, double yy = 0);
	
	double rastojanjeFigure();
	void transliraj(int dx, int dy);
	virtual void show();
	bool jeVeca(GeometrijskaSlika* g);
protected:
	virtual double povrsina() = 0;
};

