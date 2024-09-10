#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <mz700beep.h>
#include <mmlparser.h>
// #include <malloc.h>


// #define MEMERY_POOL_SIZE 1024
// uint8_t memoryPool[MEMERY_POOL_SIZE];

// //  自前のmalloc
// void* hota_malloc(size_t size) {
//     static uint8_t* nextFree = memoryPool;
//     uint8_t* result = nextFree;
//     nextFree += size;
//     return result;
// }

// typedef struct test {
//     int arr[20]; 
// } Test;

// void main() {
//     printf("OK4");
//     printf("OK5");
//     static Test test;
//     printf("OK6");
// }


part beep_part1 = {0,0,5,
    {
        {50,3416,0,0},
        {100,3044,0,0},
        {50,2712,0,0},
        {100,2564,0,0},
        {50,2283,0,0}
    }
};


void main(void) {

    initCommandList();

    // mallinit();
    return 0;

    mz700_beep_init();

    part *part1 = &beep_part1;
    char *part_mml = "o4c4d8e16f8g2";
    //parse_mml(part_mml,part1);

    // part *part1 = (part*)malloc(sizeof(part*)*1);
    // note *notes = (note*)malloc(sizeof(note*)*5);
    // part1->notes = notes;

    uint16_t play_pitch;
    while(part1->end==0) {
        mz700_beep_frame(part1);
        csleep(1);
    }
    mz700_beep_off();

    // free(part1);
    // free(notes);

    //   char** dname;
    // char found_lcd1602;
    // char buf[10];

    // cnt = iotfindc("device/i2c_a");
    // if (cnt == -1) return 1;

    // dname = (char**)malloc(sizeof(char*) * cnt);

    // cnt = iotfind("device/i2c_a", dname);
    // if (cnt == -1) return 1;

    // found_lcd1602 = 0;
    // for (i = 0; i < cnt; i++)
    // {
    //     if (strcmp(dname[i], SLAVE_ADDR_LCD1602) == 0) found_lcd1602 = 1;
    //     free(dname[i]);
    // }

    // free(dname);
}

// void parse_mml(char *part_mml,part *part1) {
//     int i = 0;
//     char *command_buff = "     ";
//     char *parameter_buff = "     ";
//     int sharp = 0;
//     int do_parse_command = 0;
//     // int tone_no = 0;    
//     while(part_mml[i] != '\0'){
//         int is_command = 0;
//         int is_param = 0;
//         printf("%c ", part_mml[i]);
//         switch (part_mml[i])
//         {
//             case 'a':
//                 do_parse_command = 1;
//                 is_command = 1;
//                 break;
//             case 'b':
//                 do_parse_command = 1;
//                 is_command = 1;
//                 break;
//             case 'c':
//                 do_parse_command = 1;
//                 is_command = 1;
//                 break;
//             case 'd':
//                 do_parse_command = 1;
//                 is_command = 1;
//                 break;
//             case 'e':
//                 do_parse_command = 1;
//                 is_command = 1;
//                 break;
//             case 'f':
//                 do_parse_command = 1;
//                 is_command = 1;
//                 break;
//             case 'g':
//                 is_command = 1;
//                 do_parse_command = 1;
//                 break;
//             case '0':
//                 is_command = 1;
//                 do_parse_command = 1;
//                 break;
//             default:
//                 break;
//         }

//         i++;
//     }
// }




