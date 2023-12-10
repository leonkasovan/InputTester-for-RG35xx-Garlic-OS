#ifndef CONFIG_H
#define CONFIG_H

#define VERSION             "1.0"

#define WINDOW_W            640             /* Window width              */
#define WINDOW_H            480             /* Window height             */
#define FPS				    30				/* Frames per second         */
#define FRAME_TIME     	    1000 / FPS      /* Duration of 1 frame in ms */
#define NO_BUTTONS          15              /* Number of buttons         */

/* SDL1.2 Button Code for RG35XX Koriki OS */
#define RG35XX_MENU_CODE      10            /* RG35xx button code */
#define RG35XX_UP_CODE        13            /* RG35xx button code */
#define RG35XX_RIGHT_CODE     16            /* RG35xx button code */
#define RG35XX_DOWN_CODE      14            /* RG35xx button code */
#define RG35XX_LEFT_CODE      15            /* RG35xx button code */
#define RG35XX_A_CODE         0             /* RG35xx button code */
#define RG35XX_B_CODE         1             /* RG35xx button code */
#define RG35XX_X_CODE         2             /* RG35xx button code */
#define RG35XX_Y_CODE         3             /* RG35xx button code */
#define RG35XX_SELECT_CODE    8             /* RG35xx button code */
#define RG35XX_START_CODE     9             /* RG35xx button code */
#define RG35XX_L1_CODE        4             /* RG35xx button code */
#define RG35XX_R1_CODE        5             /* RG35xx button code */
#define RG35XX_POWER     	  4             /* RG35xx button code */
#define RG35XX_L2_CODE        6             /* RG35xx button code */
#define RG35XX_R2_CODE        7             /* RG35xx button code */
#define RG35XX_AUDIO_INC      11            /* RG35xx button code */
#define RG35XX_AUDIO_DEC      12            /* RG35xx button code */

#define MENU_BUTTON         RG35XX_MENU_CODE  /* Code of the pressed button to exit the application                     */
#define MENU_BUTTON_INDEX   0               /* Button config list index of the pressed button to exit the application */
#define EXIT_PRESS_TIME     2000            /* Number of ms to press on menu to close the application                 */

#define BUTTON_NAME_LENGTH  6               /* Length of the text to be displayed under a button/image file name      */
#define FILE_PATH_LENGTH    20              /* Length of the file path: ./res/xxxxxx.png                              */

#define BUTTONS_CONFIG \
{\
	{NULL, NULL, {290, 120, 0, 0}, {300, 170, 0, 0}, "Menu", 	0, RG35XX_MENU_CODE},\
	{NULL, NULL, {100, 120, 0, 0}, {640,   0, 0, 0}, "Up", 	 	0, RG35XX_UP_CODE},    /* Print outside the screen - invisible */\
	{NULL, NULL, {169, 190, 0, 0}, {640,   0, 0, 0}, "Right",  	0, RG35XX_RIGHT_CODE}, /* Print outside the screen - invisible */\
	{NULL, NULL, {100, 260, 0, 0}, {640,   0, 0, 0}, "Down", 	0, RG35XX_DOWN_CODE},  /* Print outside the screen - invisible */\
	{NULL, NULL, { 30, 190, 0, 0}, {640,   0, 0, 0}, "Left",  	0, RG35XX_LEFT_CODE},  /* Print outside the screen - invisible */\
	{NULL, NULL, {540, 190, 0, 0}, {565, 250, 0, 0}, "A", 	 	0, RG35XX_A_CODE},\
	{NULL, NULL, {475, 255, 0, 0}, {500, 315, 0, 0}, "B", 	 	0, RG35XX_B_CODE},\
	{NULL, NULL, {476, 125, 0, 0}, {501, 185, 0, 0}, "X", 	 	0, RG35XX_X_CODE},\
	{NULL, NULL, {410, 190, 0, 0}, {435, 250, 0, 0}, "Y", 	 	0, RG35XX_Y_CODE},\
	{NULL, NULL, {240, 330, 0, 0}, {240, 390, 0, 0}, "Select", 	0, RG35XX_SELECT_CODE},\
	{NULL, NULL, {340, 330, 0, 0}, {343, 390, 0, 0}, "Start",  	0, RG35XX_START_CODE},\
	{NULL, NULL, {145,  15, 0, 0}, {163,  60, 0, 0}, "L1", 	 	0, RG35XX_L1_CODE},\
	{NULL, NULL, {220,  15, 0, 0}, {238,  60, 0, 0}, "L2", 	 	0, RG35XX_L2_CODE},\
	{NULL, NULL, {430,  15, 0, 0}, {449,  60, 0, 0}, "R1", 	 	0, RG35XX_R1_CODE},\
	{NULL, NULL, {355,  15, 0, 0}, {374,  60, 0, 0}, "R2", 	 	0, RG35XX_R2_CODE}\
}
#endif
