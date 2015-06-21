/*
 * AUserInterfaceControl.h
 *
 *  Created on: 21 jun. 2015
 *      Author: Ruben
 */

#ifndef SRC_AUSERINTERFACECONTROL_H_
#define SRC_AUSERINTERFACECONTROL_H_

#include "ADisplayControl.h"
#include <string>

namespace a {

class AUserInterfaceControl {
public:
	AUserInterfaceControl(){
		text = "";
		x = 0;
		y = 0;
	}
	virtual ~AUserInterfaceControl(){}

	virtual void setText(std::string text, int x, int y)=0;

	virtual void Visualize(a::ADisplayControl *text)=0;
	virtual void Update(a::ADisplayControl *text)=0;
	virtual void Free(a::ADisplayControl *text)=0;

protected:
	int x,y;
	std::string text;

};

} /* namespace a */

#endif /* SRC_AUSERINTERFACECONTROL_H_ */
