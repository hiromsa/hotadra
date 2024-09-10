#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** 
 * @def コマンドの登録可能数
 */
#define COMMAND_LIST_LENGTH 30

/**
 * @brief MMLのコマンド一つを扱う構造体
 */
typedef struct mmlCommand {
    /**
     * @brief MML上でコマンドを表す文字列
     */
    char command[4]; // 4文字 + 終端文字
//    int test;
} MMLCommand;

/**
 * @brief すべてのMMLコマンドを保持する
 */
typedef struct mmlCommandSet {
    //! 
    MMLCommand commands[COMMAND_LIST_LENGTH]; // コマンドの配列
    int count;
   int (*addCommand)(struct mmlCommandSet*, const char*);
} MMLCommandSet;

void initMMLCommand(MMLCommand* cmd, const char* str) {
    strncpy(cmd->command, str, sizeof(cmd->command) - 1);
    cmd->command[sizeof(cmd->command) - 1] = '\0'; // 終端文字を確保
}

/**
 * @brief MMLコマンドセットへ指定したコマンドを追加する
 * @param set 追加先のコマンドセット
 * @param str コマンド文字列
 * @return 
 */
int MMLCommandSet_addCommand(MMLCommandSet* set, const char* str) {
    if (set->count >= COMMAND_LIST_LENGTH) {
        return -1; // エラー: 最大数を超えた
    }
    initMMLCommand(&set->commands[set->count], str);
    set->count++;
    return 0; // 成功
}

// MMLCommandSetの初期化関数
void initCommandSet(MMLCommandSet* set) {
    printf("ok1");
    //set->count = 0;
    printf("ok2");
    set->addCommand = MMLCommandSet_addCommand; // 関数ポインタの初期化
    printf("ok3");
    static MMLCommand mmlCommand_A;
//    set->addCommand(set,)
}

// コマンドを追加する関数
int addCommand(MMLCommandSet* set, const char* str) {
    if (set->count >= COMMAND_LIST_LENGTH) {
        return -1; // エラー: 最大数を超えた
    }
    initMMLCommand(&set->commands[set->count], str);
    set->count++;
    return 0; // 成功
}

// // コマンドセットを表示する関数
// void printCommandSet(const MMLCommandSet* set) {
//     // for (int i = 0; i < set->count; i++) {
//     //     printf("Command %d: %s\n", i, set->commands[i].command);
//     // }
// }

// void test() {
//     printf("test");
// }

/**
 * @brief 
 */
void initCommandList() {
    printf("OK");
    printf("OK");
    printf("OK2");
    static MMLCommandSet commandSet;
    printf("OK");
//    test();
    printf("OK");
    initCommandSet(&commandSet);

    printf("OK2");
    // コマンドを追加（メソッド風に呼び出し）
    // commandSet.addCommand(&commandSet, "c");
    // commandSet.addCommand(&commandSet, "d");
    // commandSet.addCommand(&commandSet, "e");

    printf("OK");

    // コマンドセットを表示
    //printCommandSet(&commandSet);
    
}

// typedef struct notetype {
//     int length;
//     int pitch;
//     int state;
//     int current_index;
// }note;

// typedef struct parttype {
//     int note_index;
//     int end;
//     int note_length;
//     note notes[5];    
// }part;

// // extern long heap (); 

// void parse_mml(char *part_mml,part *part1);
