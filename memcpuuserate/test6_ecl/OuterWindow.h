/*
 * OuterWindow.h
 *
 *  Created on: 2018. 2. 19.
 *      Author: syasyasya
 */

#ifndef MAIN_CPP_UI_OUTERWINDOW_H_
#define MAIN_CPP_UI_OUTERWINDOW_H_

#include "Control.h"

//namespace test {

class OuterWindow : public Control {
public:
	OuterWindow(RECT rect) ;
	BOOL init(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow);
	virtual ~OuterWindow();
};

//} /* namespace test */

#endif /* MAIN_CPP_UI_OUTERWINDOW_H_ */
