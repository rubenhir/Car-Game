/*
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 * Car.h
 *
 *  Created on: 23-mrt.-2015
 *      Author: ruben
 */

#include <string>

#ifndef SRC_AENTITY_H_
#define SRC_AENTITY_H_

#include "ADisplayControl.h"

namespace a {

class AEntity{
public:
	AEntity(){
		x = 0;
		y = 0;
		width=0;
		height=0;
		pointerWH=0;
	}
	virtual ~AEntity(){}

	virtual void MediaPath(std::string path)=0;
	virtual void position(int x, int y)=0;
	virtual int getX()=0;
	virtual int getY()=0;

	virtual void Visualize(a::ADisplayControl *_display) = 0;
	virtual void Update(a::ADisplayControl *_display) = 0;
	virtual void Free(a::ADisplayControl *_display)=0;
	// Visualisatie --> Die in een SDLCar effectief wordt voorgesteld

protected:
	std::string path, type;
	int *pointerWH,x,y,width,height;;

};

} /* namespace a */

#endif /* SRC_AENTITY_H_ */
