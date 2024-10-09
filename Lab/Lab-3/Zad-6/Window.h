#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Window
{
private:
	string title;
	bool state;
public:
	Window();
	Window(string ttitle, bool sstate);
	~Window();

	virtual void draw(ostream& izlaz);
	void open();
	void close();

	void setState() { state = 1; }
	void resetState() { state = 0; }

	virtual bool confirm() { return 1; }
	virtual bool cancel() { return 0; }

	string getTitle() { return this->title; }

	bool jeVeci(Window* w) {
		if (this->title > w->title)
			return true;
		return false;
	}
};

