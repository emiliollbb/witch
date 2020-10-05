#include <genesis.h>
#include "version.h"

void run_intro(void);

void run_intro() {
	u16 i;
	
	VDP_drawText("WITCH", 10, 13);
	VDP_drawText(VERSION, 1, 27);
	
	for(i=0; i<150; i++) {
		VDP_waitVSync();
	}
}

int main(void)
{
    run_intro();
    VDP_resetScreen();

    while(TRUE)
    {
        VDP_waitVSync();
    }

    return 0;
}

