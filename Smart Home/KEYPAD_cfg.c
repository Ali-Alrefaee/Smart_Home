#include "STD_Types.h"

#include "KEYPAD_cfg.h"
#include "KEYPAD_priv.h"

tstrKeyPadCfg KEYPAD_astrCfg[KEYPAD_MAX_NUM]=
{
	/*Cfg keypad 0*/
	{
		/*input pins*/
		{16 , 17 , 18 , 19},
		/*output pins*/
		{20 , 21 , 22 },
		{
			{1   ,  2  , 3  },
			{4   ,  5  , 6  },
			{7   ,  8  , 9  },
			{'*' ,  0  ,'#' }
		},
		/* input num for each keypad*/
		4,
		/* Output num for each keypad*/
		3
	
	}
};
