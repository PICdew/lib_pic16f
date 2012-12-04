/*
 * File:   timer_16f1823.h
 * Author: Master
 *
 * Created on 2012/07/19 14:21
 */

#ifndef	_TIMER_16F1823_H_
#define	_TIMER_16F1823_H_



/*****************************************************/
#define	CLOCK_FOSC_4_TIMER	0x00
#define	CLOCK_T0CKI_TIMER	0x01

#define	PRESCALE_1_TIMER	1
#define	PRESCALE_2_TIMER	2
#define	PRESCALE_4_TIMER	4
#define	PRESCALE_8_TIMER	8
#define	PRESCALE_16_TIMER	16
#define	PRESCALE_32_TIMER	32
#define	PRESCALE_64_TIMER	64
#define	PRESCALE_128_TIMER	128
#define	PRESCALE_256_TIMER	256

#define	POSTSCALE_1_TIMER	0b0000
#define	POSTSCALE_2_TIMER	0b0001
#define	POSTSCALE_3_TIMER	0b0010
#define	POSTSCALE_4_TIMER	0b0011
#define	POSTSCALE_5_TIMER	0b0100
#define	POSTSCALE_6_TIMER	0b0101
#define	POSTSCALE_7_TIMER	0b0110
#define	POSTSCALE_8_TIMER	0b0111
#define	POSTSCALE_9_TIMER	0b1000
#define	POSTSCALE_10_TIMER	0b1001
#define	POSTSCALE_11_TIMER	0b1010
#define	POSTSCALE_12_TIMER	0b1011
#define	POSTSCALE_13_TIMER	0b1100
#define	POSTSCALE_14_TIMER	0b1101
#define	POSTSCALE_15_TIMER	0b1110
#define	POSTSCALE_16_TIMER	0b1111
/*****************************************************/



/*****************************************************/
#define	transUsToTimer( second, f_osc, prescale )\
	((unsigned int)( (f_osc) / 1000000  * (second) / (prescale) ))
/*****************************************************/

/*****************************************************/
void	init0Timer( unsigned char clock, unsigned char	prescale );
void	enableInterrupt0Timer( void );
void	disableInterrupt0Timer( void );

void	init1Timer( unsigned char clock, unsigned char prescale );
void	enableInterrupt1Timer( void );
void	disableInterrupt1Timer( void );

void	init2Timer( unsigned char prescale, unsigned char postscale );
void	enableInterrupt2Timer( void );
void	disableInterrupt2Timer( void );
/*****************************************************/

#endif
