#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mz700_beep_init();
void mz700_beep_on(uint16_t);
void mz700_beep_off();

void main(void) {

    mz700_beep_init();
    uint16_t play_pitch_array[10] = {3416,3044,2712,2564,2283,3416,3044,2712,2564,2283}; //O4CDEFG
    for (int i = 0; i < 10; i++) {
        uint16_t play_pitch = play_pitch_array[i];
        mz700_beep_on(play_pitch);
        printf("\nSOUND");
        csleep(1);
    }
     mz700_beep_off();

}


void mz700_beep_init() {
#asm
    LD A,1
    LD (0E008h),A 

    LD HL,0E007h
    LD (HL),36h

    ret
#endasm
}

void mz700_beep_on(uint16_t pitch) {
#asm
    LD IX,2
    ADD IX,SP

    LD B,(IX+1)
    LD C,(IX)

    LD HL,0E004h
    LD (HL),C
    LD (HL),B

    ret
#endasm
}

void mz700_beep_off() {
#asm
    XOR   A
    LD    (0E008h), A  
    ret
#endasm
}