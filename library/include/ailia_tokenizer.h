﻿/**
 * \~japanese
 * @file ailia_tokenizer.h
 * @brief ailia Tokenizer NLP TOKENIZER ライブラリ
 * @copyright AXELL CORPORATION, ax Inc.
 * @date 2024/07/26
 */

#ifndef INCLUDED_AILIA_TOKENIZER
#define INCLUDED_AILIA_TOKENIZER

/* エラーコードと構造体 */

#include "ailia.h"

/* 呼び出し規約 */

#if defined(_WIN64) || defined(_M_X64) || defined(__amd64__) || defined(__x86_64__) || defined(__APPLE__) || \
	defined(__ANDROID__) || defined(ANDROID) || defined(__linux__) || defined(NN_NINTENDO_SDK)
#define AILIA_API
#else
#define AILIA_API __stdcall
#endif

#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************
 * アルゴリズム定義
 **/

/**
 * \~japanese
 * @def AILIA_TOKENIZER_TYPE_WHISPER
 * @brief Whisper向けのトークナイザ
 *
 * \~english
 * @def AILIA_TOKENIZER_TYPE_WHISPER
 * @brief Tokenizer for Whisper
 */
#define AILIA_TOKENIZER_TYPE_WHISPER (0)

/**
 * \~japanese
 * @def AILIA_TOKENIZER_TYPE_CLIP
 * @brief Clip向けのトークナイザ
 *
 * \~english
 * @def AILIA_TOKENIZER_TYPE_CLIP
 * @brief Tokenizer for Clip
 */
#define AILIA_TOKENIZER_TYPE_CLIP (1)

/**
 * \~japanese
 * @def AILIA_TOKENIZER_TYPE_XLM_ROBERTA
 * @brief XLM_ROBERTA向けのトークナイザ
 *
 * \~english
 * @def AILIA_TOKENIZER_TYPE_XLM_ROBERTA
 * @brief Tokenizer for XLM_ROBERTA
 */
#define AILIA_TOKENIZER_TYPE_XLM_ROBERTA (2)

/**
 * \~japanese
 * @def AILIA_TOKENIZER_TYPE_MARIAN
 * @brief MARIAN向けのトークナイザ
 *
 * \~english
 * @def AILIA_TOKENIZER_TYPE_MARIAN
 * @brief Tokenizer for MARIAN
 */
#define AILIA_TOKENIZER_TYPE_MARIAN (3)

/**
 * \~japanese
 * @def AILIA_TOKENIZER_TYPE_BERT_JAPANESE_WORDPIECE
 * @brief Japanese BERT向けのトークナイザ
 * @details
 *   入力されたテキストは内部でNFKC形式でUnicode正規化を行います。
 *
 * \~english
 * @def AILIA_TOKENIZER_TYPE_BERT_JAPANESE_WORDPIECE
 * @brief Tokenizer for Japanese BERT
 * @details
 *   The input text is internally normalized in Unicode format using NFKC format.
 */
#define AILIA_TOKENIZER_TYPE_BERT_JAPANESE_WORDPIECE (4)

/**
 * \~japanese
 * @def AILIA_TOKENIZER_TYPE_BERT_JAPANESE_CHARACTER
 * @brief Japanese BERT向けのトークナイザ
 * @details
 *   入力されたテキストは内部でNFKC形式でUnicode正規化を行います。
 *
 * \~english
 * @def AILIA_TOKENIZER_TYPE_BERT_JAPANESE_CHARACTER
 * @brief Tokenizer for Japanese BERT
 * @details
 *   The input text is internally normalized in Unicode format using NFKC format.
 */
#define AILIA_TOKENIZER_TYPE_BERT_JAPANESE_CHARACTER (5)

/**
 * \~japanese
 * @def AILIA_TOKENIZER_TYPE_T5
 * @brief T5向けのトークナイザ
 * @details
 *   add_special_tokens=Trueと同様に末尾にEOSシンボルを挿入します。
 *   japanese_clipなど、add_special_tokens=Falseと同様の動作にする場合は、出力の末尾のEOSシンボルを削除してください。
 *
 * \~english
 * @def AILIA_TOKENIZER_TYPE_T5
 * @brief Tokenizer for T5
 * @details
 *   Inserts the EOS symbol at the end, similar to add_special_tokens=True.
 *   If you want the same behavior as add_special_tokens=False, such as japanese_clip, remove the EOS symbol at the end of the output.
 */
#define AILIA_TOKENIZER_TYPE_T5 (6)

/**
 * \~japanese
 * @def AILIA_TOKENIZER_TYPE_ROBERTA
 * @brief  RoBERTa向けのトークナイザ
 *
 * \~english
 * @def AILIA_TOKENIZER_TYPE_ROBERTA
 * @brief Tokenizer for RoBERTa
 */
#define AILIA_TOKENIZER_TYPE_ROBERTA (7)

/**
 * \~japanese
 * @def AILIA_TOKENIZER_TYPE_BERT
 * @brief  BERT向けのトークナイザ
 *
 * \~english
 * @def AILIA_TOKENIZER_TYPE_BERT
 * @brief Tokenizer for BERT
 */
#define AILIA_TOKENIZER_TYPE_BERT (8)

/**
 * \~japanese
 * @def AILIA_TOKENIZER_TYPE_GPT2
 * @brief  GPT2向けのトークナイザ
 *
 * \~english
 * @def AILIA_TOKENIZER_TYPE_GPT2
 * @brief Tokenizer for GPT2
 */
#define AILIA_TOKENIZER_TYPE_GPT2 (9)

/**
 * \~japanese
 * @def AILIA_TOKENIZER_TYPE_LLAMA
 * @brief  LLAMA向けのトークナイザ
 *
 * \~english
 * @def AILIA_TOKENIZER_TYPE_LLAMA
 * @brief Tokenizer for LLAMA
 */
#define AILIA_TOKENIZER_TYPE_LLAMA (10)

/****************************************************************
 * フラグ定義
 **/

/**
 * \~japanese
 * @def AILIA_TOKENIZER_FLAG_NONE
 * @brief フラグを設定しません
 *
 * \~english
 * @def AILIA_TOKENIZER_FLAG_NONE
 * @brief Default flag
 */
#define AILIA_TOKENIZER_FLAG_NONE (0)

/**
 * \~japanese
 * @def AILIA_TOKENIZER_FLAG_UTF8_SAFE
 * @brief UTF8として有効な文字のみ出力します
 *
 * \~english
 * @def AILIA_TOKENIZER_FLAG_UTF8_SAFE
 * @brief Output only characters valid as UTF8
 */
#define AILIA_TOKENIZER_FLAG_UTF8_SAFE (1)

/****************************************************************
 * トークナイズオブジェクトのインスタンス
 **/

struct AILIATokenizer;

/****************************************************************
 * Tokenizer API
 **/

/**
 * \~japanese
 * @brief トークナイズオブジェクトを作成します。
 * @param net トークナイザオブジェクトポインタへのポインタ
 * @param type AILIA_TOKENIZER_TYPE_*
 * @param flag AILIA_TOKENIZER_FLAG_*の論理和
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   トークナイズオブジェクトを作成します。
 *
 * \~english
 * @brief Creates a tokenizer instance.
 * @param net A pointer to the tokenizer instance pointer
 * @param type AILIA_TOKENIZER_TYPE_*
 * @param flag OR of AILIA_TOKENIZER_FLAG_*
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   Creates a tokenizer instance.
 */
int AILIA_API ailiaTokenizerCreate(struct AILIATokenizer** net, int type, int flags);

/**
 * \~japanese
 * @brief モデルファイルを読み込みます。
 * @param net トークナイザオブジェクトポインタへのポインタ
 * @param path SentencePieceのモデルファイルのパス
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   SentencePieceのモデルファイルを読み込みます。AILIA_TOKENIZER_TYPE_XLM_ROBERTAもしくはAILIA_TOKENIZER_TYPE_MARIANの場合のみ必要です。
 *
 * \~english
 * @brief Open model file.
 * @param net A pointer to the tokenizer instance pointer
 * @param path Path for SentencePiece
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   Open a model file for SentencePiece. This API only requires for AILIA_TOKENIZER_TYPE_XLM_ROBERTA or AILIA_TOKENIZER_TYPE_MARIAN.
 */
int AILIA_API ailiaTokenizerOpenModelFileA(struct AILIATokenizer* net, const char *path);
int AILIA_API ailiaTokenizerOpenModelFileW(struct AILIATokenizer* net, const wchar_t *path);

/**
 * \~japanese
 * @brief 辞書ファイルを読み込みます。
 * @param net トークナイザオブジェクトポインタへのポインタ
 * @param path Mecabの辞書ファイルのパス
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   Mecabの辞書ファイルを読み込みます。AILIA_TOKENIZER_TYPE_BERT_JAPANESE_XXXの場合のみ必要です。
 *
 * \~english
 * @brief Open dictionary file.
 * @param net A pointer to the tokenizer instance pointer
 * @param path Path for dictionary of Mecab
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   Open a model file for Mecab. This API only requires for AILIA_TOKENIZER_TYPE_BERT_JAPANESE_XXX.
 */
int AILIA_API ailiaTokenizerOpenDictionaryFileA(struct AILIATokenizer* net, const char *path);
int AILIA_API ailiaTokenizerOpenDictionaryFileW(struct AILIATokenizer* net, const wchar_t *path);

/**
 * \~japanese
 * @brief 単語ファイルを読み込みます。
 * @param net トークナイザオブジェクトポインタへのポインタ
 * @param path 単語ファイルのパス
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   単語ファイル (ROBERTAとWHISPERとGPT2はjson、それ以外はtxt) を読み込みます。
 *
 * \~english
 * @brief Open vocab file.
 * @param net A pointer to the tokenizer instance pointer
 * @param path Path for Vocab file
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   Open a vocab file (json for ROBERTA or WHISPER or GPT2, txt for others).
 */
int AILIA_API ailiaTokenizerOpenVocabFileA(struct AILIATokenizer* net, const char *path);
int AILIA_API ailiaTokenizerOpenVocabFileW(struct AILIATokenizer* net, const wchar_t *path);

/**
 * \~japanese
 * @brief マージファイルを読み込みます。
 * @param net トークナイザオブジェクトポインタへのポインタ
 * @param path マージファイルのパス
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   マージファイル (txt) を読み込みます。AILIA_TOKENIZER_TYPE_ROBERTAもしくはAILIA_TOKENIZER_TYPE_WHISPERもしくはAILIA_TOKENIZER_TYPE_GPT2の場合のみ有効です。
 *
 * \~english
 * @brief Open merges file.
 * @param net A pointer to the tokenizer instance pointer
 * @param path Path for merges file
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   Open a merge file (txt). This API only requires for AILIA_TOKENIZER_TYPE_ROBERTA or AILIA_TOKENIZER_TYPE_WHISPER or AILIA_TOKENIZER_TYPE_GPT2.
 */
int AILIA_API ailiaTokenizerOpenMergeFileA(struct AILIATokenizer* net, const char *path);
int AILIA_API ailiaTokenizerOpenMergeFileW(struct AILIATokenizer* net, const wchar_t *path);

/**
 * \~japanese
 * @brief 追加トークンファイルを読み込みます。
 * @param net トークナイザオブジェクトポインタへのポインタ
 * @param path スペシャルトークンファイルのパス
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   追加トークンファイル (json) を読み込みます。AILIA_TOKENIZER_TYPE_WHISPERの場合のみ有効です。
 *
 * \~english
 * @brief Open added tokens file.
 * @param net A pointer to the tokenizer instance pointer
 * @param path Path for special token file
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   Open a added tokens file (json). This API only requires for AILIA_TOKENIZER_TYPE_WHISPER.
 */
int AILIA_API ailiaTokenizerOpenAddedTokensFileA(struct AILIATokenizer* net, const char *path);
int AILIA_API ailiaTokenizerOpenAddedTokensFileW(struct AILIATokenizer* net, const wchar_t *path);

/**
 * \~japanese
 * @brief コンフィグファイルを読み込みます。
 * @param net トークナイザオブジェクトポインタへのポインタ
 * @param path コンフィグファイルのパス
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   トークナイザコンフィグファイル (json) を読み込みます。AILIA_TOKENIZER_TYPE_BERTの場合のみ有効です。
 *
 * \~english
 * @brief Open tokenizer config file.
 * @param net A pointer to the tokenizer instance pointer
 * @param path Path for config file
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   Open a tokenizer config file (json). This API only requires for AILIA_TOKENIZER_TYPE_BERT.
 */
int AILIA_API ailiaTokenizerOpenTokenizerConfigFileA(struct AILIATokenizer* net, const char *path);
int AILIA_API ailiaTokenizerOpenTokenizerConfigFileW(struct AILIATokenizer* net, const wchar_t *path);

/**
 * \~japanese
 * @brief エンコードを行います。
 * @param net トークナイザオブジェクトポインタ
 * @param text エンコードするテキスト(UTF8)
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   認識した結果はailiaTokenizerGetTokens APIで取得します。
 *   split_special_tokens=Trueと同様に、Special Tokenは分割して文字列として扱われます。
 *
 * \~english
 * @brief Perform encode
 * @param net A tokenizer instance pointer
 * @param text Text for encode (UTF8)
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   Get the encoded result with ailiaTokenizerGetTokens API.
 *   Just like with split_special_tokens=True, Special Tokens are treated as strings by splitting them.
 */
int AILIA_API
ailiaTokenizerEncode(struct AILIATokenizer* net, const char *utf8);

/**
 * \~japanese
 * @brief スペシャルトークンを含んだエンコードを行います。
 * @param net トークナイザオブジェクトポインタ
 * @param text エンコードするテキスト(UTF8)
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   認識した結果はailiaTokenizerGetTokens APIで取得します。
 *   split_special_tokens=Falseと同様に、Special Tokenを出力します。
 *
 * \~english
 * @brief Perform encode with special tokens
 * @param net A tokenizer instance pointer
 * @param text Text for encode (UTF8)
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   Get the encoded result with ailiaTokenizerGetTokens API.
 *   Similarly to split_special_tokens=False, special tokens will be output.
 */
int AILIA_API
ailiaTokenizerEncodeWithSpecialTokens(struct AILIATokenizer* net, const char *utf8);

/**
 * \~japanese
 * @brief トークンの数を取得します。
 * @param net   トークナイザオブジェクトポインタ
 * @param count  オブジェクト数
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 *
 * \~english
 * @brief Gets the number of tokens.
 * @param net   A tokenizer instance pointer
 * @param count  The number of objects
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 */
int AILIA_API ailiaTokenizerGetTokenCount(struct AILIATokenizer* net, unsigned int* count);

/**
 * \~japanese
 * @brief トークンを取得します。
 * @param net   トークナイザオブジェクトポインタ
 * @param tokens トークン
 * @param count  格納先トークン数
 * @param 
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   ailiaTokenizerEncode() を一度も実行していない場合は \ref AILIA_STATUS_INVALID_STATE が返ります。
 *
 * \~english
 * @brief Gets the tokens.
 * @param net   A tokenizer instance pointer
 * @param tokens Token
 * @param count  Token count
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   If  ailiaTokenizerEncode()  is not run at all, the function returns  \ref AILIA_STATUS_INVALID_STATE .
 */
int AILIA_API ailiaTokenizerGetTokens(struct AILIATokenizer* net, int* tokens, unsigned int count);

/**
 * \~japanese
 * @brief ワードIDを取得します。
 * @param net   トークナイザオブジェクトポインタ
 * @param word_ids ワードID
 * @param count  格納先トークン数
 * @param 
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   ailiaTokenizerEncode() を一度も実行していない場合は \ref AILIA_STATUS_INVALID_STATE が返ります。
 *   AILIA_TOKENIZER_TYPE_ROBERTAとAILIA_TOKENIZER_TYPE_BERTの場合のみ有効です。
 *
 * \~english
 * @brief Gets the word ID.
 * @param net   A tokenizer instance pointer
 * @param word_ids Word ID
 * @param count  Token count
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   If  ailiaTokenizerEncode()  is not run at all, the function returns  \ref AILIA_STATUS_INVALID_STATE .
 *   This is valid only for AILIA_TOKENIZER_TYPE_ROBERTA and AILIA_TOKENIZER_TYPE_BERT.
 */
int AILIA_API ailiaTokenizerGetWordIDs(struct AILIATokenizer* net, int* word_ids, unsigned int count);

/**
 * \~japanese
 * @brief 開始文字位置を取得します。
 * @param net   トークナイザオブジェクトポインタ
 * @param char_starts 開始文字位置
 * @param count  格納先トークン数
 * @param 
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   ailiaTokenizerEncode() を一度も実行していない場合は \ref AILIA_STATUS_INVALID_STATE が返ります。
 *   AILIA_TOKENIZER_TYPE_ROBERTAとAILIA_TOKENIZER_TYPE_BERTの場合のみ有効です。
 *   各トークンに対応するUTF32単位での開始文字位置が返ります。
 *
 * \~english
 * @brief Gets the Char start positions.
 * @param net   A tokenizer instance pointer
 * @param char_starts Character start position
 * @param count  Token count
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   If  ailiaTokenizerEncode()  is not run at all, the function returns  \ref AILIA_STATUS_INVALID_STATE .
 *   This is valid only for AILIA_TOKENIZER_TYPE_ROBERTA and AILIA_TOKENIZER_TYPE_BERT.
 *   The character start positions in UTF-32 units corresponding to each token are returned.
 */
int AILIA_API ailiaTokenizerGetCharStarts(struct AILIATokenizer* net, int* char_starts, unsigned int count);

/**
 * \~japanese
 * @brief 終了文字位置を取得します。
 * @param net   トークナイザオブジェクトポインタ
 * @param char_ends 終了文字位置
 * @param count  格納先トークン数
 * @param 
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   ailiaTokenizerEncode() を一度も実行していない場合は \ref AILIA_STATUS_INVALID_STATE が返ります。
 *   AILIA_TOKENIZER_TYPE_ROBERTAとAILIA_TOKENIZER_TYPE_BERTの場合のみ有効です。
 *   各トークンに対応するUTF32単位での終了文字位置が返ります。
 *
 * \~english
 * @brief Gets the Char end positions.
 * @param net   A tokenizer instance pointer
 * @param char_ends Char end position
 * @param count  Token count
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   If  ailiaTokenizerEncode()  is not run at all, the function returns  \ref AILIA_STATUS_INVALID_STATE .
 *   This is valid only for AILIA_TOKENIZER_TYPE_ROBERTA and AILIA_TOKENIZER_TYPE_BERT.
 *   The character end positions in UTF-32 units corresponding to each token are returned.
 */
int AILIA_API ailiaTokenizerGetCharEnds(struct AILIATokenizer* net, int* char_ends, unsigned int count);

/**
 * \~japanese
 * @brief デコードを行います。
 * @param net トークナイザオブジェクトポインタ
 * @param tokens デコードするトークン
 * @param token_count トークンの数
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   デコードした結果はailiaTokenizerGetText APIで取得します。
 *   skip_special_tokens=Trueと同様に、Special Tokenは出力しません。
 *
 * \~english
 * @brief Perform decode
 * @param net A tokenizer instance pointer
 * @param tokens Tokens for decode
 * @param token_count The number of tokens
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   Get the decoded result with ailiaTokenizerGetText API.
 *   Similarly to skip_special_tokens=True, special tokens will not be output.
 */
int AILIA_API
ailiaTokenizerDecode(struct AILIATokenizer* net, const int *tokens, unsigned int token_count);

/**
 * \~japanese
 * @brief スペシャルトークンを含んだデコードを行います。
 * @param net トークナイザオブジェクトポインタ
 * @param tokens デコードするトークン
 * @param token_count トークンの数
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   デコードした結果はailiaTokenizerGetText APIで取得します。
 *   skip_special_tokens=Falseと同様に、Special Tokenを出力します。
 *
 * \~english
 * @brief Perform decode with special tokens
 * @param net A tokenizer instance pointer
 * @param tokens Tokens for decode
 * @param token_count The number of tokens
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   Get the decoded result with ailiaTokenizerGetText API.
 *   Similarly to skip_special_tokens=False, special tokens will be output.
 */
int AILIA_API
ailiaTokenizerDecodeWithSpecialTokens(struct AILIATokenizer* net, const int *tokens, unsigned int token_count);

/**
 * \~japanese
 * @brief テキストの長さを取得します。(NULL文字含む)
 * @param net   トークナイザオブジェクトポインタ
 * @param len  テキストの長さ
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 *
 * \~english
 * @brief Gets the size of text. (Include null)
 * @param net   A tokenizer instance pointer
 * @param len  The length of text
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 */
int AILIA_API ailiaTokenizerGetTextLength(struct AILIATokenizer* net, unsigned int* len);

/**
 * \~japanese
 * @brief テキストを取得します。
 * @param net   トークナイザオブジェクトポインタ
 * @param text  テキスト(UTF8)
 * @param len バッファサイズ
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   ailiaTokenizerDecode() を一度も実行していない場合は \ref AILIA_STATUS_INVALID_STATE が返ります。
 *
 * \~english
 * @brief Gets the decoded text.
 * @param net   A tokenizer instance pointer
 * @param text  Text(UTF8)
 * @param len  Buffer size
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   If  ailiaTokenizerDecode()  is not run at all, the function returns  \ref AILIA_STATUS_INVALID_STATE .
 */
int AILIA_API ailiaTokenizerGetText(struct AILIATokenizer* net, char* text, unsigned int len);

/**
 * \~japanese
 * @brief Vocabの数を取得します。
 * @param net   トークナイザオブジェクトポインタ
 * @param size  Vocabの要素数
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 *
 * \~english
 * @brief Gets the size of vocab. (Include null)
 * @param net   A tokenizer instance pointer
 * @param size  The size of vocab
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 */
int AILIA_API ailiaTokenizerGetVocabSize(struct AILIATokenizer* net, unsigned int* size);

/**
 * \~japanese
 * @brief Vocabの取得を行います。
 * @param net トークナイザオブジェクトポインタ
 * @param token トークン
 * @param vocab Vocabのテキスト(UTF8)
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   vocabを解放する必要はありません。
 *   vocabの有効期間は次にailiaTokenizer APIを呼び出すまでになります。
 *
 * \~english
 * @brief Perform encode
 * @param net A tokenizer instance pointer
 * @param token Token
 * @param text Text of vocab (UTF8)
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   There is no need to release the vocab.
 *   The validity period of the vocab will last until the next time the ailiaTokenizer API is called.
 */
int AILIA_API
ailiaTokenizerGetVocab(struct AILIATokenizer* net, int token, const char **vocab);

/**
 * \~japanese
 * @brief SpecialTokenの追加を行います。
 * @param net トークナイザオブジェクトポインタ
 * @param tokens トークン(UTF8)
 * @param count 追加する個数
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 * @details
 *   AILIA_TOKENIZER_TYPE_ROBERTAおよびAILIA_TOKENIZER_TYPE_GPT2の場合のみ有効です。
 *
 * \~english
 * @brief Add SpecialToken
 * @param net A tokenizer instance pointer
 * @param tokens Token(UTF8)
 * @param count The number of tokens
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 * @details
 *   This is valid only for AILIA_TOKENIZER_TYPE_ROBERTA and AILIA_TOKENIZER_TYPE_GPT2.
 */
int AILIA_API
ailiaTokenizerAddSpecialTokens(struct AILIATokenizer* net, const char **tokens, unsigned int count);

/**
 * \~japanese
 * @brief トークナイズオブジェクトを破棄します。
 * @param net トークナイザオブジェクトポインタ
 *
 * \~english
 * @brief It destroys the tokenizer instance.
 * @param net A tokenizer instance pointer
 */
void AILIA_API ailiaTokenizerDestroy(struct AILIATokenizer* net);

/****************************************************************
 * Utility API
 **/

/**
 * \~japanese
 * @brief UTF8の文字をUTF32の文字に変換します。
 * @param utf32   UTF32の文字
 * @param processed_byte 消費したバイト数(UTF8)
 * @param utf8  UTF8の文字
 * @param utf8_len   バッファサイズ
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 *
 * \~english
 * @brief Convert UTF8 character to UTF32 character.
 * @param utf32   UTF32の文字
 * @param processed_byte Processed bytes on UTF8
 * @param utf8  UTF8の文字
 * @param utf8_len   Buffer Size
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 */
int AILIA_API ailiaTokenizerUtf8ToUtf32(unsigned int* utf32, unsigned int* processed_byte, const char* utf8, unsigned int utf8_len);

/**
 * \~japanese
 * @brief UTF32の文字をUTF8の文字に変換します。
 * @param utf8   UTF8の文字(4byte以上必要)
 * @param processed_byte 書き込んだ文字数(UTF8)
 * @param utf32  UTF32の文字
 * @return
 *   成功した場合は \ref AILIA_STATUS_SUCCESS 、そうでなければエラーコードを返す。
 *
 * \~english
 * @brief Convert UTF32 character to UTF8 character.
 * @param utf8   UTF8 character(Require greater than 4byte)
 * @param processed_byte Processed bytes on UTF8
 * @param utf32  UTF32 character
 * @return
 *   If this function is successful, it returns  \ref AILIA_STATUS_SUCCESS , or an error code otherwise.
 */
int AILIA_API ailiaTokenizerUtf32ToUtf8(char* utf8, unsigned int* processed_byte, unsigned int utf32);

#ifdef UNICODE
#define ailiaTokenizerOpenModelFile ailiaTokenizerOpenModelFileW
#define ailiaTokenizerOpenDictionaryFile ailiaTokenizerOpenDictionaryFileW
#define ailiaTokenizerOpenVocabFile ailiaTokenizerOpenVocabFileW
#define ailiaTokenizerOpenMergeFile ailiaTokenizerOpenMergeFileW
#define ailiaTokenizerOpenAddedTokensFile ailiaTokenizerOpenAddedTokensFileW
#define ailiaTokenizerOpenConfigFile ailiaTokenizerOpenConfigFileW
#else
#define ailiaTokenizerOpenModelFile ailiaTokenizerOpenModelFileA
#define ailiaTokenizerOpenDictionaryFile ailiaTokenizerOpenDictionaryFileA
#define ailiaTokenizerOpenVocabFile ailiaTokenizerOpenVocabFileA
#define ailiaTokenizerOpenMergeFile ailiaTokenizerOpenMergeFileA
#define ailiaTokenizerOpenAddedTokensFile ailiaTokenizerOpenAddedTokensFileA
#define ailiaTokenizerOpenTokenizerConfigFile ailiaTokenizerOpenTokenizerConfigFileA
#endif

#ifdef __cplusplus
}
#endif
#endif /* !defined(INCLUDED_AILIA_TOKENIZER) */
