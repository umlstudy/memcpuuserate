/*
 * Control.h
 *
 *  Created on: 2018. 2. 19.
 *      Author: syasyasya
 */

#ifndef MAIN_CPP_UI_CONTROL_H_
#define MAIN_CPP_UI_CONTROL_H_

#include <windef.h>
#include "Widget.h"

//namespace test {

class Control : public Widget {
public:
	Control(RECT rect);
	virtual ~Control();

	RECT getBounds() const {
		return bounds;
	}

private:
	void setBounds(RECT bounds) {
		this->bounds = bounds;
	}

	RECT bounds;
protected:
	LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
};

//} /* namespace test */

#endif /* MAIN_CPP_UI_CONTROL_H_ */
