#include <genesis.h>
#include "version.h"
#include "gfx.h"

void run_intro(void);
void run_game(void);

void run_intro() {
	u16 i;
	
	VDP_drawText("WITCH", 10, 13);
	VDP_drawText(VERSION, 1, 27);
	
	for(i=0; i<150; i++) {
		VDP_waitVSync();
	}
}

void run_game() {
	u16 ind=TILE_USERINDEX;
    VDP_setPaletteColors(PAL0, (u16*)foreground.palette->data, 16);
    VDP_drawImageEx(PLAN_A, &foreground, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, ind), 0, 0, FALSE, TRUE);
}

int main(void)
{
	VDP_setScreenWidth320();
	SPR_init(0, 0, 0);
    
    run_intro();
    VDP_resetScreen();
    run_game();

    while(TRUE)
    {
        VDP_waitVSync();
    }

    return 0;
}

