/*
 * AEventControl.h
 *
 *  Created on: 4-mei-2015
 *      Author: ruben
 */

#ifndef SRC_AEVENTCONTROL_H_
#define SRC_AEVENTCONTROL_H_

namespace a {

class AEventControl {
	public:
		AEventControl(){
			_running = false;
			_pauzing = false,
			_time = 0;
			_key = 0;
		}
		virtual ~AEventControl(){}

		virtual void handleEvents()=0;
		virtual void setDelayTime(double time)=0;
		virtual void delay()=0;
		virtual bool running()=0;
		virtual bool pauzing()=0;
		virtual int keyselection()=0;

	protected:
		bool _running,_pauzing;
		double _time;
		int _key;

	};
} /* namespace a */

#endif /* SRC_AEVENTCONTROL_H_ */
