#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mz700beep.h>

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
    note notes[5];    
}part;

part beep_part1 = {0,0,5,
    {
        {50,3416,0,0},
        {100,3044,0,0},
        {50,2712,0,0},
        {100,2564,0,0},
        {50,2283,0,0}
    }
};

void mz700_beep_frame(part *part1);

void main(void) {

    mz700_beep_init();

    part *part1 = &beep_part1;
    uint16_t play_pitch;
    while(part1->end==0) {
        mz700_beep_frame(part1);
        csleep(1);
    }
    mz700_beep_off();
}

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

