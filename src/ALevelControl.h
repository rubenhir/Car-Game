/*
 * ALevelControl.h
 *
 *  Created on: 20 jun. 2015
 *      Author: Ruben
 */

#ifndef SRC_ALEVELCONTROL_H_
#define SRC_ALEVELCONTROL_H_

namespace a {

class ALevelControl {
	public:
		ALevelControl(){
			level = 1;
			score = 0;
			warnings = 0;
		}
		virtual ~ALevelControl(){}

		// getFunctions
		virtual int getLevel()=0;
		virtual int getScore()=0;
		virtual int getWarnings()=0;

		// setFunctions
		virtual void setLevel(int level)=0;
		virtual void setScore(int score)=0;
		virtual void giveWarning()=0;

	protected:
		int level,score,warnings;
};


} /* namespace a */

#endif /* SRC_ALEVELCONTROL_H_ */
