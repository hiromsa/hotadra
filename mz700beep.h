#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mz700_beep_init();
void mz700_beep_on(uint16_t);
void mz700_beep_off();


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

typedef struct notetype {
    int length;
    int pitch;
    int state;
    int current_index;
}note;

typedef struct parttype {
    int note_index;
    int end;
    int note_length;
    note notes[100];    
}part;

int beep_map[88][2] = {
    {0, 32541},
    {1, 30715},
    {2, 28991},
    {20, 27364},
    {21, 25828},
    {22, 24379},
    {23, 23010},
    {24, 21719},
    {26, 20500},
    {27, 19349},
    {28, 18263},
    {29, 17238},
    {16, 16271},
    {17, 15358},
    {18, 14496},
    {36, 13682},
    {37, 12914},
    {38, 12189},
    {39, 11505},
    {40, 10859},
    {42, 10250},
    {43, 9675},
    {44, 9132},
    {45, 8619},
    {32, 8135},
    {33, 7679},
    {34, 7248},
    {52, 6841},
    {53, 6457},
    {54, 6095},
    {55, 5753},
    {56, 5430},
    {58, 5125},
    {59, 4837},
    {60, 4566},
    {61, 4310},
    {48, 4068},
    {49, 3839},
    {50, 3624},
    {68, 3420},
    {69, 3229},
    {70, 3047},
    {71, 2876},
    {72, 2715},
    {74, 2562},
    {75, 2419},
    {76, 2283},
    {77, 2155},
    {64, 2034},
    {65, 1920},
    {66, 1812},
    {84, 1710},
    {85, 1614},
    {86, 1524},
    {87, 1438},
    {88, 1357},
    {90, 1281},
    {91, 1209},
    {92, 1141},
    {93, 1077},
    {80, 1017},
    {81, 960},
    {82, 906},
    {100, 855},
    {101, 807},
    {102, 762},
    {103, 719},
    {104, 679},
    {106, 641},
    {107, 605},
    {108, 571},
    {109, 539},
    {96, 508},
    {97, 480},
    {98, 453},
    {116, 428},
    {117, 404},
    {118, 381},
    {119, 360},
    {120, 339},
    {122, 320},
    {123, 302},
    {124, 285},
    {125, 269},
    {112, 254},
    {113, 240},
    {114, 226},
    {130, 214}
};

void mz700_beep_frame(part *part1);

void mz700_beep_frame(part *part1) {
    uint16_t play_pitch;
    note *note1 = &part1->notes[part1->note_index];
    if (note1->state == 0 ) {
        play_pitch = note1->pitch;
        mz700_beep_on(play_pitch);
        printf("\nSOUND");
        note1->state = 1;
    }
    note1->current_index++;
    if (note1->current_index >= note1->length) {
        part1->note_index++;
        if (part1->note_index>=part1->note_length) {
            part1->end = 1;
        }
    }
}

