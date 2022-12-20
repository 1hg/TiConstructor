#define USE_HEXDUMP
#define USE_WAIT8
#define USE_CPU_SPEED
#include "../../lib/essentials.c"
#include "../../lib/textio.c"
#include "../../lib/misc.c"
#include "../../lib/userinput.c"
#include "../../lib/variables.c"

#include "../../lib/greyscale.c"
// #define NO_USE_SWAP
// #define NO_USE_CLEAR

#define X_LINE 8
#define Y_MULT 		add	hl,hl \
				   	ld e, l   \
				   	add	hl,hl \
				   	add	hl,de \
				   	add	hl,de 
#define GREYSCALE_SPRITES
#include "../../lib/spritemanager.c"





#define dataName addAppVarObj("gryCfg") // need to add type data to appVar name
#include "calibration.c"

const char ONE_DATA[] ={0b11111111, 0b10000000, 0b10000000, 0b10000001, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000001, 0b10000000, 0b10000000, 0b11111111, 0b11111111, 0b00000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b11000001, 0b00000001, 0b00000001, 0b11111111, 0b11111111, 0b10000000, 0b10000000, 0b10000001, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000001, 0b10000000, 0b10000000, 0b11111111, 0b11111111, 0b00000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b10000001, 0b11000001, 0b00000001, 0b00000001, 0b11111111};
#define ONE_WIDTH 16/8
#define ONE_HEIGHT 16
const char two_DATA[] ={0b11111111, 0b10000000, 0b10000000, 0b10000011, 0b10000100, 0b10000000, 0b10000000, 0b10000000, 0b10000001, 0b10000010, 0b10000100, 0b10000111, 0b10000000, 0b10000000, 0b10000000, 0b11111111, 0b11111111, 0b00000001, 0b00000001, 0b10000001, 0b01000001, 0b01000001, 0b01000001, 0b10000001, 0b00000001, 0b00000001, 0b00000001, 0b11000001, 0b00000001, 0b00000001, 0b00000001, 0b11111111, 0b11111111, 0b10000000, 0b10000000, 0b10000011, 0b10000100, 0b10000000, 0b10000000, 0b10000000, 0b10000001, 0b10000010, 0b10000100, 0b10000111, 0b10000000, 0b10000000, 0b10000000, 0b11111111, 0b11111111, 0b00000001, 0b00000001, 0b10000001, 0b01000001, 0b01000001, 0b01000001, 0b10000001, 0b00000001, 0b00000001, 0b00000001, 0b11000001, 0b00000001, 0b00000001, 0b00000001, 0b11111111};
#define two_WIDTH 16/8
#define two_HEIGHT 16
const char four_DATA[] ={0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000001, 0b10000010, 0b10000100, 0b10000111, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b11111111, 0b11111111, 0b00000001, 0b00000001, 0b01000001, 0b11000001, 0b01000001, 0b01000001, 0b01000001, 0b11000001, 0b01000001, 0b01000001, 0b01000001, 0b01000001, 0b00000001, 0b00000001, 0b11111111};
#define four_WIDTH 16/8
#define four_HEIGHT 16
const char eight_DATA[] ={0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b10000000, 0b10000000, 0b10000001, 0b10000010, 0b10000010, 0b10000010, 0b10000001, 0b10000010, 0b10000010, 0b10000010, 0b10000001, 0b10000000, 0b10000000, 0b10000000, 0b11111111, 0b11111111, 0b00000001, 0b00000001, 0b10000001, 0b01000001, 0b01000001, 0b01000001, 0b10000001, 0b01000001, 0b01000001, 0b01000001, 0b10000001, 0b00000001, 0b00000001, 0b00000001, 0b11111111};
#define eight_WIDTH 16/8
#define eight_HEIGHT 16


const char sixteen_DATA[] ={0b11111111, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b11111111, 0b11111111, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11110111, 0b11100111, 0b11110111, 0b11110111, 0b11110111, 0b11110111, 0b11110111, 0b11100011, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b10001111, 0b01111111, 0b01111111, 0b00001111, 0b01110111, 0b01110111, 0b01110111, 0b10001111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111};
#define sixteen_WIDTH 16/8
#define sixteen_HEIGHT 16
const char thirtytwo_DATA[] ={0b11111111, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b11111111, 0b11111111, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b00000001, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11100011, 0b11011101, 0b11111101, 0b11111101, 0b11100011, 0b11111101, 0b11111101, 0b11111101, 0b11000011, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11000111, 0b10111011, 0b11111011, 0b11111011, 0b11110111, 0b11101111, 0b11011111, 0b10111111, 0b10000011, 0b11111111, 0b11111111, 0b11111111, 0b11111111};
#define thirtytwo_WIDTH 16/8
#define thirtytwo_HEIGHT 16
const char sixtyfour_DATA[] ={0b11111111, 0b10000000, 0b10000000, 0b10000000, 0b10011100, 0b10100000, 0b10100000, 0b10111000, 0b10100100, 0b10100101, 0b10100100, 0b10011000, 0b10000000, 0b10000000, 0b10000000, 0b11111111, 0b11111111, 0b00000001, 0b00000001, 0b00000001, 0b00010001, 0b00110001, 0b01010001, 0b01010001, 0b10010001, 0b11111001, 0b00010001, 0b00010001, 0b00000001, 0b00000001, 0b00000001, 0b11111111, 0b11111111, 0b10000000, 0b10000000, 0b10000000, 0b10011000, 0b10100000, 0b10100000, 0b10111000, 0b10100100, 0b10100100, 0b10100100, 0b10011000, 0b10000000, 0b10000000, 0b10000000, 0b11111111, 0b11111111, 0b00000001, 0b00000001, 0b00000001, 0b00010001, 0b00110001, 0b01010001, 0b01010001, 0b10010001, 0b11111001, 0b00010001, 0b00010001, 0b00000001, 0b00000001, 0b00000001, 0b11111111};
#define sixtyfour_WIDTH 16/8
#define sixtyfour_HEIGHT 16









void set(){
	char* dataLoc=getOrCreateVar(dataName, 20)+2; 

	if (!(dataLoc[0] == 0x69 && dataLoc[3] == 0x69)){
		dataLoc[0] = 0x69;
		dataLoc[1] = 0x9F;
		dataLoc[2] = 0x15;
		dataLoc[3] = 0x69;
	}
	*(char*)(0x85A6) = dataLoc[1];
	*(char*)(0x85A6+1) = dataLoc[2];
}

void real_main(){
	clearScreen();
	setCpuSpeed(3);
	clearGreyScaleBuffer();

	set();


	INIT_GREYSCALE();
	
	*(char*)WAIT_LOC = *(char*)(0x85A6);
	*(char*)CONTRAST_LOC = *(char*)(0x85A6+1);
	
	setCpuSpeed(3);
	// greyPutSprite(10, 5, Untitled4_WIDTH, Untitled4_HEIGHT, Untitled4_DATA);

	*((char*)MAX_COL)=8;
	*((char*)START_COL) = COL_START_CONST+1;

	*((char*)START_ROW) = ROW_CONST;
	*((char*)END_ROW) = ROW_END_CONST;


	greyPutSprite(0, 0, ONE_WIDTH, ONE_HEIGHT, ONE_DATA);
	greyPutSprite(16, 0, two_WIDTH, two_HEIGHT, two_DATA);
	greyPutSprite(32, 0, four_WIDTH, four_HEIGHT, four_DATA);
	greyPutSprite(32+16, 0, eight_WIDTH, eight_HEIGHT, eight_DATA);
	greyPutSprite(0, 16, sixteen_WIDTH, sixteen_HEIGHT, sixteen_DATA);
	greyPutSprite(16, 16, thirtytwo_WIDTH, thirtytwo_HEIGHT, thirtytwo_DATA);
	greyPutSprite(32, 16, sixtyfour_WIDTH, sixtyfour_HEIGHT, sixtyfour_DATA);

	greyPutSprite(32+16, 32+16, ONE_WIDTH, ONE_HEIGHT, ONE_DATA);

	while (1){
		wait(4);
		
		scanKeys();
		if (skClear == lastPressedKey())
			break;
		else if (skMode == lastPressedKey()){
			calibration_loop();
			clearScreen();
			clearGreyScaleBuffer();

			greyPutSprite(0, 0, ONE_WIDTH, ONE_HEIGHT, ONE_DATA);
			greyPutSprite(16, 0, two_WIDTH, two_HEIGHT, two_DATA);
			greyPutSprite(32, 0, four_WIDTH, four_HEIGHT, four_DATA);
			// greyPutSprite(0, 8, sixteen_WIDTH, sixteen_HEIGHT, sixteen_DATA);
			// greyPutSprite(16, 8, thirtytwo_WIDTH, thirtytwo_HEIGHT, thirtytwo_DATA);
			// greyPutSprite(32, 8, sixtyfour_WIDTH, sixtyfour_HEIGHT, sixtyfour_DATA);
		}

	}

	archive(dataName);


}

void main() {
	clearScreen();
	resetPen();


	real_main();



	

}