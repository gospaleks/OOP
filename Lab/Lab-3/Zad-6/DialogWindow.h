#pragma once
#include "Window.h"
class DialogWindow : public Window
{
public:
	DialogWindow();
	DialogWindow(string ttitle);
	DialogWindow(string ttitle, bool sstate);
	virtual void draw();

	bool confirm();
	bool cancel();
};

