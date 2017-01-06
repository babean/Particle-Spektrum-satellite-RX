//Lemon DSMX Satellite Receiver Libriary
#include "SpektrumSatellite.h"

void SpektrumSatellite::begin()
{
	Serial1.begin(115200);
}

bool SpektrumSatellite::getFrame(void)
{	
    while (Serial1.available() <18);
    time = millis();
    errors = Serial1.read();
    bindtype = Serial1.read();
    for (int i=0;i<7;i++){
        data = Serial1.read();
        chan_id = (data & 0x78)>>3;
        chVal[chan_id] = ((data & 0x07)<<8);
        chVal[chan_id] += Serial1.read();
    }
	return getTrans();
}

bool SpektrumSatellite::getTrans()
{
	if (millis() - time > 1000)
	{
		return false;
	}
	else	
	{
		return true;
	}
}

uint16_t SpektrumSatellite::getChannelValue(int channelId)
{
	return chVal[channelId];
}

uint16_t SpektrumSatellite::getThro()
{
	return getChannelValue(0);
}

uint16_t SpektrumSatellite::getAile()
{
	return getChannelValue(1);
}

uint16_t SpektrumSatellite::getElev()
{
	return getChannelValue(2);
}

uint16_t SpektrumSatellite::getRudd()
{
	return getChannelValue(3);
}

uint16_t SpektrumSatellite::getGear()
{
	return getChannelValue(4);
}

uint16_t SpektrumSatellite::getPitc()
{
	return getChannelValue(5);
}

uint16_t SpektrumSatellite::getAux2()
{
	return getChannelValue(6);
}

uint16_t SpektrumSatellite::getAux3()
{
	return getChannelValue(7);
}

uint16_t SpektrumSatellite::getAux4()
{
	return getChannelValue(8);
}
