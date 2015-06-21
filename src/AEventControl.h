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
			_playing = false;
			_sec = 0;
			_key = 0;
			_pauzing = false;

		}
		virtual ~AEventControl(){}

		virtual void delay()=0;
		virtual bool playing()=0;
		virtual void handleEvents()=0;
		virtual int kSelect()=0;

	protected:
		bool _playing,_pauzing;
		double _sec;
		int _key;

	};
} /* namespace a */

#endif /* SRC_AEVENTCONTROL_H_ */
