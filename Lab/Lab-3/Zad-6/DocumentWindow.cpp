#include "DocumentWindow.h"

DocumentWindow::DocumentWindow()
	:Window("Document Window", 0){
}

DocumentWindow::DocumentWindow(string ttitle)
	:Window(ttitle, 0) {
}

DocumentWindow::DocumentWindow(string ttitle, bool sstate)
	:Window(ttitle, sstate){
}

void DocumentWindow::draw()
{
	cout << "DocumentWindow nacrtan" << endl;
}
