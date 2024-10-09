#pragma once
#include "Window.h"
class DocumentWindow : public Window
{
public:
	DocumentWindow();
	DocumentWindow(string ttitle);
	DocumentWindow(string ttitle, bool sstate);
	
	virtual void draw();
};

