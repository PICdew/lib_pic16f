/***************************************
* 2011年度 5年 基板間通信処理 スレーブ側ヘッダ
*
* Device	:PIC16F88,886,1827,877A
*
* Author	:石倉万希斗
*
* Latest	:2011/09/19 17:12
*****************************************/

#ifndef	_SPI_H_
#define	_SPI_H_

/******************************/
/* デバイス分別 */
#if	defined	_PIC16F88_H_
#define	DEF_SSPBUF	SSPBUF	//SPIバッファレジスタの名前

#elif	defined	_PIC16F886_H_
#define	DEF_SSPBUF	SSPBUF	//SPIバッファレジスタの名前

#elif	defined	_PIC16F1827_H_
#define	DEF_SSPBUF	SSP1BUF	//SPIバッファレジスタの名前
#define SDO_RB2 0
#define SDO_RA6 1
#define SS_RB5  0
#define SS_RA5  1

#elif   defined _PIC16F877A_H_
#define DEF_SSPBUF  SSPBUF

#elif   defined _PIC16F1939_H_
#define DEF_SSPBUF  SSPBUF
#define	SS_RA5	0
#define	SS_RA0	1

#elif
#error	This device is not supported in "corresp" library. 

#endif
/******************************/


/******************************/
#define SPI_MASTER_MODE  0b00000000
#define SPI_SLAVE_MODE_SS_ENABLE  0b00000100
#define SPI_SLAVE_MODE_SS_DISABLE  0b00000101
/******************************/

/******************************/
#define ERR_TIMEOUT 1
/******************************/

/*********************************/
/* 初期設定系 */

#if defined _PIC16F1827_H_
void initializeSPI( unsigned char mode, unsigned char apfcon_sdo, unsigned char apfcon_ss );
#elif defined	_PIC16F1939_H_
void initializeSPI( unsigned char mode, unsigned char apfcon_ss );
#else
void initializeSPI( unsigned char mode );
#endif
/*	引数
	mode	: SPIのモード
	apfcon_sdo	: APFCON0 bit6 - SDO1SEL の値(16F1827以外はDont care)
	apfcon_ss	: APFCON0 bit5 - SDO1SEL の値(16F1827以外はDont care)
	
*/

/***********
* 実効データやりとり系
************/
char    tradeSPI(char send_data, char* p_buffer);
	/* 1バイトデータをやりとりする関数 */
	
	/* 引数 */
	// send_data	: 送信する1バイトデータ
	// *p_buffer	:　受信データを保存するバッファのアドレス
	
	/* 返り値 */
	// 0	: 正常終了
	// 1	: 命令受信時タイムアウトエラー
	// 2	: 実効データ送受信時タイムアウトエラー
	// 3	: その他エラー

#endif  /* _SPI_H_ */
