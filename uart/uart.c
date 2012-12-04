/*
 * File:   uart.c
 * Author: Master
 *
 * Created on 2012/06/22 16:15
 */


#include	<xc.h>
#include	"uart.h"
#include	"lib/fifo.h"

/* ---------------------------------- */
fifo_t	fifo_transfer, fifo_receive;
/* ---------------------------------- */


/* ---------------------------------- */
void	initUart( unsigned long baudrate )
{
	unsigned int	x;
	unsigned int	int_spbrgh, int_spbrgl;

	initializeFIFO( &fifo_transfer );
	initializeFIFO( &fifo_receive );

	x	= ( ( XTAL_FREQ / baudrate ) / 64 ) - 1;

	int_spbrgh	= ( x & 0xFF00 ) >> 8;
	int_spbrgl	= x & 0x00FF;

	BRGH	= 0;	BRG16	= 0;
	SPBRGH	= (unsigned char)int_spbrgh;
	SPBRGL	= (unsigned char)int_spbrgl;

	SPEN	= 1;
	SYNC	= 0;

	RCIE	= 1;

	TXEN	= 1;
	CREN	= 1;

#ifdef	defined _PIC16F1823_H_
	TXCKSEL	= 0;	RXDTSEL	= 0;
	TRISC4	= 0;	TRISC5	= 1;
#elif	defined _PIC16F1939_H_
	TRISC6	= 0;	TRISC7	= 1;
#endif

}

/* ---------------------------------- */



/* ---------------------------------- */
inline void	interruptUart( void )
{
	unsigned char	buffer;

	if( RCIF ){
		buffer	= RCREG;
		putcFIFO( &fifo_receive, buffer );
	}
}
/* ---------------------------------- */



/* ---------------------------------- */
void	putsUart( char* str )
{
	unsigned int	i = 0;

	while( *(str + i) != '\0' ){
		putcUart( *(str + i) );
		i ++;
	}
}


void	putcUart( char data )
{
	TXREG	= data;
	while( !TXIF );
}
/* ---------------------------------- */


/* ---------------------------------- */
unsigned char	getcUart( char* data )
{
	unsigned char	err;

	err	= getBlockFIFO( &fifo_receive, data, 1 );

	if( err == 0 ){
		return	1;
	}else{
		return	0;
	}
}
/* ---------------------------------- */
