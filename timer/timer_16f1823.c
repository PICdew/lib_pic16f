/*
 * File:   timer_16f1823.c
 * Author: Master
 *
 * Created on 2012/07/19 14:21
 */

#include	<xc.h>
#include	"timer_16f1823.h"



/*****************************************************/
void	init0Timer( unsigned char clock, unsigned char	prescale )
{
	switch( clock ){
	case	CLOCK_FOSC_4_TIMER:
		TMR0CS	= 0;
		break;
	case	CLOCK_T0CKI_TIMER:
		TMR0CS	= 1;
		break;
	default:
		TMR0CS	= 0;
		break;
	}

	PSA	= 0;

	OPTION_REG	&= ~0b00000111;
	switch( prescale ){
	case	PRESCALE_2_TIMER:
		OPTION_REG	|= 0b00000000;
		break;
	case	PRESCALE_4_TIMER:
		OPTION_REG	|= 0b00000001;
		break;
	case	PRESCALE_8_TIMER:
		OPTION_REG	|= 0b00000010;
		break;
	case	PRESCALE_16_TIMER:
		OPTION_REG	|= 0b00000011;
		break;
	case	PRESCALE_32_TIMER:
		OPTION_REG	|= 0b00000100;
		break;
	case	PRESCALE_64_TIMER:
		OPTION_REG	|= 0b00000101;
		break;
	case	PRESCALE_128_TIMER:
		OPTION_REG	|= 0b00000110;
		break;
	case	PRESCALE_256_TIMER:
		OPTION_REG	|= 0b00000111;
		break;
	default:
		break;
	}

}

void	enableInterrupt0Timer( void )
{
	TMR0	= 0;
	TMR0IF	= 0;
	GIE	= 1;	PEIE	= 1;
	TMR0IE	= 1;
}



void	disableInterrupt0Timer( void )
{
	TMR0IE	= 0;
}
/*****************************************************/



/*****************************************************/
void	init1Timer( unsigned char clock, unsigned char prescale )
{
	T1CON	= 0x00;

	switch( clock ){
	case	CLOCK_FOSC_4_TIMER:
		T1CON	|= 0b00 << 6;
		break;
	default	:
		break;
	}

	switch( prescale ){
	case	PRESCALE_1_TIMER:
		T1CON	|= 0b00 << 4;
		break;
	case	PRESCALE_2_TIMER:
		T1CON	|= 0b01 << 4;
		break;
	case	PRESCALE_4_TIMER:
		T1CON	|= 0b10 << 4;
		break;
	case	PRESCALE_8_TIMER:
		T1CON	|= 0b11 << 4;
		break;
	default:
		break;
	}

	nT1SYNC	= 1;

	TMR1ON	= 1;
}


void	enableInterrupt1Timer( void )
{
	TMR1	= 0;
	TMR1IF	= 0;
	GIE	= 1;	PEIE	= 1;
	TMR1IE	= 1;
	
}



void	disableInterrupt1Timer( void )
{
	TMR1IE	= 0;
}
/*****************************************************/



/*****************************************************/
void	init2Timer( unsigned char prescale, unsigned char postscale )
{
	T2CON	= 0x00;

	T2CON	|= postscale << 3;

	switch( prescale ){
	case	PRESCALE_1_TIMER:
		T2CON	|= 0b00;
		break;
	case	PRESCALE_4_TIMER:
		T2CON	|= 0b01;
		break;
	case	PRESCALE_16_TIMER:
		T2CON	|= 0b10;
		break;
	case	PRESCALE_64_TIMER:
		T2CON	|= 0b11;
		break;
	default:
		break;
	}

	TMR2ON	= 1;
}


void	enableInterrupt2Timer( void )
{
	TMR2	= 0;
	TMR2IF	= 0;
	GIE	= 1;	PEIE	= 1;
	TMR2IE	= 1;
	
}



void	disableInterrupt2Timer( void )
{
	TMR2IE	= 0;
}
/*****************************************************/



/*****************************************************/
/*****************************************************/
