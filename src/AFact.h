/*
 * AFact.h
 *
 *  Created on: 9-mrt.-2015
 *      Author: ruben
 */

#ifndef SRC_AFACT_H_
#define SRC_AFACT_H_

#include "ADisplayControl.h"
#include "AEventControl.h"
#include "AEntity.h"
#include "ALevelControl.h"
#include <string>

namespace a {

class AFact {
	public:
		AFact(){}
		virtual ~AFact(){}

		virtual AEntity* getEntity(std::string path, int x, int y) = 0;
		virtual ADisplayControl* getDisplayControl() = 0;
		virtual AEventControl* getEventControl() = 0;
		virtual ALevelControl* newLevel() = 0;

		virtual bool init(int sWidth, int sHeight)=0;
		virtual int isReady()=0;
	};

} /* namespace std */

#endif /* SRC_AFACT_H_ */
