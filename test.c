#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mz700beep.h>

struct note {
    int length;
    int curent_index;
    int pitch;
};

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

