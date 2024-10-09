#include "DialogWindow.h"

DialogWindow::DialogWindow()
	:Window("Dialog Window", 0) {
}

DialogWindow::DialogWindow(string ttitle)
	:Window(ttitle, 0){
}

DialogWindow::DialogWindow(string ttitle, bool sstate)
	:Window(ttitle, sstate){
}

void DialogWindow::draw()
{
	cout << "DialogWindow nacrtan" << endl;
}

bool DialogWindow::confirm()
{
	setState();
	return true;
}

bool DialogWindow::cancel()
{
	resetState();
	return false;
}

