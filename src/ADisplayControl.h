/*
 * ADisplayControl.h
 *
 *  Created on: 15-apr.-2015
 *      Author: ruben
 */

#ifndef SRC_ADISPLAYCONTROL_H_
#define SRC_ADISPLAYCONTROL_H_

#include <string>

namespace a {

class ADisplayControl {
public:
	ADisplayControl(){}
	virtual ~ADisplayControl(){}

	//Loads image at specified path
	virtual bool loadMedia(std::string path, std::string type)=0;
	virtual void putrender()=0;
	virtual void clearRender() = 0;

	//Loads text at specified path
	virtual bool drawText(std::string textureText, int x, int y, std::string type)=0;
	virtual void renderText(std::string type, int x, int y)=0;

	//Deallocates texture
	virtual void free(std::string type)=0;

	//Renders texture at given point
	virtual void render(std::string type, int x, int y, int w, int h)=0;

	//Gets image dimensions
	virtual int *getSize()=0;

protected:
	//Image dimensions
	int size[2];
};


} /* namespace a */

#endif /* SRC_ADISPLAYCONTROL_H_ */
