
/**
 * @brief MMLパーサー
 */
typedef struct mmlPaser {
   void (*parse)(struct mmlCommandSet*);
} MMLParser;



/**
 * @brief  MMLパーサーを初期化する
 * @param cmd 
 * @param str 
 */
void MMLParser_initialize(MMLParser* parser, MMLCommandSet* cmd) {
}
