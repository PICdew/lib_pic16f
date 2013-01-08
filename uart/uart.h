/*
 * File:   uarth
 * Author: Master
 *
 * Created on 2012/06/22 16:12
 */

/*
 * 使い方
 *
 * 1.使いたいファイルで,"uart.h"をインクルードする
 * 2.プロジェクトに，"uart.c"と"fifo.c"を導入する
 * 3.割り込み関数に，"interruptUart();"を挿入する
 *
 * 注意事項
 * initUart関数を実行すると，全体割り込み許可ならびに周辺機器割り込み許可がイネーブルされます．
 */

#ifndef	_UART_H_
#define	_UART_H_

#if	!defined(_PIC16F1823_H_) && !defined(_PIC16F1939_H_) && !defined(_PIC16F1827_H_) && !defined(_PIC16F1509_H_)
#error	This Device is NOT surported in UART library.
#endif

/* ---------------------------------- */
#if	defined(_PIC16F1823_H_)
void	initUart( unsigned long baudrate, unsigned long xtal_freq, unsigned char txsel, unsigned char rxsel );
#define	TX_RC4	0
#define	TX_RA0	1
#define	RX_RC5	0
#define	RX_RA1	1
#elif	defined(_PIC16F1827_H_)
void	initUart( unsigned long baudrate, unsigned long xtal_freq, unsigned char txsel, unsigned char rxsel );
#define	TX_RB2	0
#define	TX_RB5	1
#define	RX_RB1	0
#define	RX_RB2	1
#elif	defined(_PIC16F1939_H_)
void	initUart( unsigned long baudrate, unsigned long xtal_freq );
#elif	defined(_PIC16F1509_H_)
void	initUart( unsigned long baudrate, unsigned long xtal_freq );
#endif
/* ---------------------------------- */



/* ---------------------------------- */
void	putcUart( char data );
	/* 1バイトデータをUARTで送信する関数
	 * 引数	
	 * char data	: 送信する1バイトデータ
	 * 返り値
	 * なし
	 */

void	putsUart( char* str );
	/* 文字列を送信する
	 * 引数	
	 * char* str	: 送信する文字列
	 * 返り値
	 * なし
	 */

unsigned char	getcUart( char* data );
	/* 受信バッファから1バイト取り出す
	 * 引数
	 * char* data	: 取り出したデータを保存するアドレス
	 * 返り値
	 * 0	: 正常にデータを読みだした
	 * 1	: データが存在しない
	 */

inline void	interruptUart( void );
/* ---------------------------------- */


#endif
