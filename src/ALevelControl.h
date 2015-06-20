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
			startTicks=0;
			pausedTicks=0;
			paused=false;
			started=false;
		}
		virtual ~ALevelControl(){}

		//Clock actions
		virtual void start()=0;
		virtual void stop()=0;
		virtual void pause()=0;
		virtual void unpause()=0;

		//Gets time
		virtual int get_ticks()=0;
		virtual double get_sec()=0;

		//Checks the status
		virtual bool is_started()=0;
		virtual bool is_paused()=0;

	protected:
			int startTicks;
			int pausedTicks;
			bool paused;
			bool started;
};


} /* namespace a */

#endif /* SRC_ALEVELCONTROL_H_ */
