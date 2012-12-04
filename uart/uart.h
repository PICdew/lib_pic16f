/*
 * File:   uarth
 * Author: Master
 *
 * Created on 2012/06/22 16:12
 */


#ifndef	_UART_H_
#define	_UART_H_

/* ---------------------------------- */
/* 動作クロックが定義されているかチェック */
/*
 * #ifndef	XTAL_FREQ
 * #error	XTAL_FREQ that remain the frequency of PIC must be defined!
 */
#define	XTAL_FREQ	32000000
/* ---------------------------------- */

/* ---------------------------------- */
/* ---------------------------------- */


/* ---------------------------------- */
void	initUart( unsigned long baudrate );
void	putcUart( char data );
void	putsUart( char* str );
unsigned char	getcUart( char* data );
inline void	interruptUart( void );
/* ---------------------------------- */


#endif
