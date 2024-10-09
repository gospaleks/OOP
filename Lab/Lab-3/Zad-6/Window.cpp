#include "Window.h"
#include <fstream>
using namespace std;
Window::Window()
{
	title = "Window";
	state = 0;
}

Window::Window(string ttitle, bool sstate)
	:title(ttitle), state(sstate) { }

Window::~Window()
{
}

void Window::draw(ostream& izlaz)
{
	izlaz << title << ", " << state << endl;
}

void Window::open()
{
	state = 1;
}

void Window::close()
{
	state = 0;
}




