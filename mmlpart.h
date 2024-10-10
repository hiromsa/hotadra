#include <stdio.h>
#include <mmlparser.h>

/**
 * @brief ノートに関する属性
 */
typedef struct noteProperty {
    /**
     * @brief ノートの音量
     */
    int volume;
    /**
     * @brief ノートの長さ
     */
    int length;
    /**
     * @brief ノートのテンポ
     */
    int tempo;
    /**
     * @brief ノートのオクターブ
     */
    int octave;
} NoteProperty;

/**
 * @brief パート内の一つのコマンドとパラメータをまとめたクラス
 */
typedef struct note {

    /**
     * @brief MMLコマンド
     */
    MMLCommand mmlCommand;

    /**
     * @brief 音の長さ
     */
    int length;

    /**
     * @brief 音量
     */

    int volume;

    /**
     * @brief 音程
     */
    int octave;

} Note;


/**
 * @brief ノートに関する属性を初期化します。
 * @param noteProperty 
 */
void NoteProperty_initialize(NoteProperty* noteProperty) {
    noteProperty->volume = 15;
    noteProperty->length = 4;
    noteProperty->tempo = 120;
    noteProperty->octave = 3;
}

/**
 * @brief パート一つをまとめたクラス
 */
typedef struct part1 {

    /**
     * @brief パート内の一つのコマンドとパラメータをまとめたクラス
     */
    Note noteList[100];    

    /**
     * @brief パート内のノート数
     */
    int noteCount;

    /**
     * @brief ノートを追加します。
     */
    void (*addNote)(struct part1*, Note*);

} Part;


/**
 * @brief パート内のノートを追加します
 */
void Part_addNote(Part* part2, Note* note) {
    printf("test");
    part2->noteList[part2->noteCount]=*note;
    //part->addNote(part, note);
    //part->noteList[2]=note;
    // part->noteList[part->noteCount]=note;
    // part->noteCount++;
}


/**
 * @brief パートを初期化します。
 * @param part 
 */
void Part_initialize(Part* aPart) {
    aPart->addNote = Part_addNote;
}






