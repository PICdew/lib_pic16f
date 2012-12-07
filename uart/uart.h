/*
 * File:   uarth
 * Author: Master
 *
 * Created on 2012/06/22 16:12
 */

#ifndef	_UART_H_
#define	_UART_H_

#if	!defined(_PIC16F1823_H_) && !defined(_PIC16F1939_H_) && !defined(_PIC16F1827_H_)
#error	This Device is NOT surported in UART library.
#endif

/* ---------------------------------- */
/* 動作クロックが定義されているかチェック */
/*
 * #ifndef	XTAL_FREQ
 * #error	XTAL_FREQ that remain the frequency of PIC must be defined!
 */
#define	XTAL_FREQ	32000000
/* ---------------------------------- */

/* ---------------------------------- */
#if	defined(_PIC16F1823_H_)
void	initUart( unsigned long baudrate, unsigned char txsel, unsigned char rxsel );
#define	TX_RC4	0
#define	TX_RA0	1
#define	RX_RC5	0
#define	RX_RA1	1
#elif	defined(_PIC16F1827_H_)
void	initUart( unsigned long baudrate, unsigned char txsel, unsigned char rxsel );
#define	TX_RB2	0
#define	TX_RB5	1
#define	RX_RB1	0
#define	RX_RB2	1
#elif	defined(_PIC16F1939_H_)
void	initUart( unsigned long baudrate );
#endif
/* ---------------------------------- */



/* ---------------------------------- */
void	putcUart( char data );
void	putsUart( char* str );
unsigned char	getcUart( char* data );
inline void	interruptUart( void );
/* ---------------------------------- */


#endif
