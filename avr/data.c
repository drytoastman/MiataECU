
#include "PNPAddOns.h"
#include <avr/eeprom.h>

#define EEPROM_CONFIG_BASE 0
#define FLAGSOFFSET ((U8*)&data.flags - (U8*)&data)
#define IDLEOFFSET ((U8*)&data.idle - (U8*)&data)

#define INTGOFFSET ((U8*)&config.integratorIndex - (U8*)&config)
#define FILTOFFSET ((U8*)&config.filterIndex - (U8*)&config)
#define GAINOFFSET ((U8*)&config.gainIndex - (U8*)&config)


U8 signature[20] = "MS2Extra Addons v01";
U8 titlebar[60] = "MS2Extra Addon Board with some other text here    ----------";
ConfigData config;
IOData data;

unsigned char burnFlag;

void data_init()
{
	eeprom_read_block((void*)&config, EEPROM_CONFIG_BASE, sizeof(config));
	burnFlag = 0;
}

void data_burn()
{
	burnFlag = 1;
}

void config_changed(U8 offset, U8 length)
{
	if ((offset + length) < INTGOFFSET) // end is before our stuff
		return;
	if (offset > GAINOFFSET)  // start is after our stuff (which is weird)
		return

	knock_sensor_setting_changed();
}

void data_changed(U8 offset, U8 length)
{
	if ((offset + length) < IDLEOFFSET) // end is before our stuff
		return;
	if (offset > IDLEOFFSET)  // start is after our stuff
		return;

	idle_changed();
}

void data_main()
{
	if (burnFlag)
	{
		if (!eeprom_is_ready())
			return;
		burnFlag = 0;  // clear first incase it is set again while writing
		eeprom_update_block((void*)&config, EEPROM_CONFIG_BASE, sizeof(config));
	}
}


