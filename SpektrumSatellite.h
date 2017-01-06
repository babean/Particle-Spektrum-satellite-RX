//SpektrumSattelite Receiver Libriary
#ifndef _SPECTRUMRECEIVER_H_
#define _SPECTRUMRECEIVER_H_

#if defined (PARTICLE)
#include "application.h"
#else
#include "Arduino.h"
#endif


class SpektrumSatellite
{
	public:
		void begin();
		bool getFrame();
		uint16_t getChannelValue(int);
		uint16_t getThro();
		uint16_t getAile();
		uint16_t getElev();
		uint16_t getRudd();
		uint16_t getGear();
		uint16_t getPitc();
		uint16_t getAux2();
		uint16_t getAux3();
		uint16_t getAux4();
		bool getTrans();
	private:
		int data;
		int errors;
		int bindtype;

		uint16_t chVal[9];
		int chan_id;
		unsigned long time;
};


#endif /* _SPECTRUMRECEIVER_H_ */
