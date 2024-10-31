#ifndef HOGE_H
#define HOGE_H


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
   int (*addCommand)(struct mmlCommandSet*, MMLCommand*);
} MMLCommandSet;

/**
 * @brief  MMLコマンドを初期化する
 * @param cmd 
 * @param str 
 */
void MMLCommand_initialize(MMLCommand* cmd, const char* str) {
    strncpy(cmd->command, str, sizeof(cmd->command) - 1);
    cmd->command[sizeof(cmd->command) - 1] = '\0'; // 終端文字を確保
}

/**
 * @brief MMLコマンドセットへ指定したコマンドを追加する
 * @param set 追加先のコマンドセット
 * @param str コマンド文字列
 * @return 
 */
int MMLCommandSet_addCommand(MMLCommandSet* mmlCommandSet, MMLCommand* mmlCommand) {
    if (mmlCommandSet->count >= COMMAND_LIST_LENGTH) {
        return -1; // エラー: 最大数を超えた
    }
    mmlCommandSet->commands[mmlCommandSet->count] = *mmlCommand;
    mmlCommandSet->count++;
    return 0; // 成功
}

// void MMLCommandSet_initialize(MMLCommandSet* set);

/**
 * @brief MMLコマンドセットを初期化する
 */
void MMLCommandSet_initialize(MMLCommandSet* commandSet) {

    // メソッドを追加
    commandSet->addCommand = MMLCommandSet_addCommand; // 関数ポインタの初期化

    // 各コマンドを初期化して追加する

    // a
    static MMLCommand mmlCommand_a;
    MMLCommand_initialize(&mmlCommand_a, "a");
    commandSet->addCommand(commandSet,&mmlCommand_a);

    // b
    static MMLCommand mmlCommand_b;
    MMLCommand_initialize(&mmlCommand_b, "b");
    commandSet->addCommand(commandSet,&mmlCommand_b);

    // c
    static MMLCommand mmlCommand_c;
    MMLCommand_initialize(&mmlCommand_c, "c");
    commandSet->addCommand(commandSet,&mmlCommand_c);

    // d
    static MMLCommand mmlCommand_d;
    MMLCommand_initialize(&mmlCommand_d, "d");
    commandSet->addCommand(commandSet,&mmlCommand_d);

    // e
    static MMLCommand mmlCommand_e;
    MMLCommand_initialize(&mmlCommand_e, "e");
    commandSet->addCommand(commandSet,&mmlCommand_e);

    // f
    static MMLCommand mmlCommand_f;
    MMLCommand_initialize(&mmlCommand_f, "f");
    commandSet->addCommand(commandSet,&mmlCommand_f);

    // g
    static MMLCommand mmlCommand_g;
    MMLCommand_initialize(&mmlCommand_g, "g");
    commandSet->addCommand(commandSet,&mmlCommand_g);

    // o
    static MMLCommand mmlCommand_o;
    MMLCommand_initialize(&mmlCommand_o, "o");
    commandSet->addCommand(commandSet,&mmlCommand_o);


}


int addCommand(MMLCommandSet* set, const char* str) {
    if (set->count >= COMMAND_LIST_LENGTH) {
        return -1; // エラー: 最大数を超えた
    }
    //initMMLCommand(&set->commands[set->count], str);
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

#endif // HOGE_H
