#include "gpio.h"
#include "gpiote.h"


/*
	  GPIO0->PIN_CNF[21] = 1; //Row 1
	  GPIO0->PIN_CNF[22] = 1; //Row 2
	  GPIO0->PIN_CNF[15] = 1; //Row 3
	  GPIO0->PIN_CNF[24] = 1; //Row 4
	  GPIO0->PIN_CNF[19] = 1; //Row 5
*/

void gpiote_init()
{ 
    GPIOTE->CONFIG[0] = 0x1; 
    GPIOTE->CONFIG[0] |= (BUTTON_A_PIN) << 8;

    for (int i = 1; i < 6; i++) {
        GPIOTE->CONFIG[i] = 0x3;
        GPIOTE->CONFIG[i] |= 0x0 << PORT_SELECT_BIT;
    
    }
    //set pins
    GPIOTE->CONFIG[1] |= 21 << 8;
    GPIOTE->CONFIG[2] |= 22 << 8;
    GPIOTE->CONFIG[3] |= 15 << 8;
    GPIOTE->CONFIG[4] |= 24 << 8;
    GPIOTE->CONFIG[5] |= 19 << 8;


}