/*
 * File:   adcon_16f1823.c
 * Author: Master
 *
 * Created on 2012/07/18 21:03
 */

#include	<xc.h>
#include	"adcon_16f1823.h"
#include	"adcon_16f1823_l.h"



/*****************************************************/
unsigned char	initAdcon( unsigned long f_osc, unsigned char vref )
{
	unsigned char	f_adc;

	f_adc	= getFreq( f_osc );

	if( f_adc == ERR_FREQ ){

		return	ERR_INIT_ADCON;

	}else{

		ADFM	= 0;
		ADCON1	|= f_adc << 4;

		switch( vref ){
		case	VREF_VDD_ADCON:
			ADCON1	|= 0b00000000;
			break;
		default:
			break;
		}

		ADON	= 1;

		return	0;
	}
}


/*---------------------------------------------------*/
static unsigned char	getFreq( unsigned long f_osc )
{
	const unsigned long	F_ADC_MIN = 16667, F_ADC_MAX = 1000000;
	const unsigned char	NUM_PRESCALE = 6;
	enum{
		PRESCALE_2 = 0, PRESCALE_4 = 1 , PRESCALE_8 = 2, PRESCALE_16 = 3, PRESCALE_32 = 4, PRESCALE_64 = 5 
	};

	unsigned long	f_adc, prescale = 2;
	unsigned char	i;

	for( i = 0; i < NUM_PRESCALE; i++ ){
		f_adc	= f_osc / prescale;
		prescale	*= 2;

		if( ( f_adc >= F_ADC_MIN ) && ( f_adc <= F_ADC_MAX ) ){
			break;
		}
	}

	switch( i ){
	case	PRESCALE_2:
		return	0b00000000;
	case	PRESCALE_4:
		return	0b00000100;
	case	PRESCALE_8:
		return	0b00000001;
	case	PRESCALE_16:
		return	0b00000101;
	case	PRESCALE_32:
		return	0b00000010;
	case	PRESCALE_64:
		return	0b00000110;
	default:
		return	ERR_FREQ;
	}
}

/*---------------------------------------------------*/

/*****************************************************/



/*****************************************************/

void	setPortAdcon( unsigned int num_port )
{
	unsigned char	port, number;

	getPortNumber( num_port, &port, &number );

	switch( port ){
	case	PORTNUM_A:
		TRISA	|= number;
		ANSELA	|= number;
		break;

	case	PORTNUM_C:
		TRISC	|= number;
		ANSELC	|= number;
		break;

	default:
		break;
	}
}



void	resetPortAdcon( unsigned int num_port )
{
	unsigned char	port, number;

	if( isPortReadyAdcon( num_port ) == TRUE ){
		getPortNumber( num_port, &port, &number );
		
		switch( port ){
		case	PORTNUM_A:
			ANSELA	&= ~number;
			TRISA	&= ~number;
			break;

		case	PORTNUM_C:
			ANSELC	&= ~number;
			TRISC	&= ~number;
			break;

		default:
			break;
		}
	}
}


/*---------------------------------------------------*/
static void	getPortNumber( unsigned int num_port, unsigned char* port, unsigned char* number )
{
	*port	= (unsigned char)(( num_port & 0xFF00 ) >> 8 ) ;
	*number	= (unsigned char)(num_port & 0x00FF);
}


bool	isPortReadyAdcon( unsigned int num_port )
{
	unsigned char	port, number;

	getPortNumber( num_port, &port, &number );

	switch( port ){
	case	PORTNUM_A:
		if( (TRISA & number) && ( ANSELA & number ) ){
			return	TRUE;
		}else{
			return	FALSE;
		}

	case	PORTNUM_C:
		if( (TRISC & number) && ( ANSELC & number ) ){
			return	TRUE;
		}else{
			return	FALSE;
		}

	default:
		return	FALSE;
	}
}

/*---------------------------------------------------*/

/*****************************************************/


/*****************************************************/
unsigned char	get8bitAdcon( unsigned int num_port )
{
	const unsigned int	WAIT_ACQUISITION = 100;
	unsigned int	i;

	if( isPortReadyAdcon( num_port ) == TRUE ){
		ADCON0	&=	0b00000001;

		switch( num_port ){
		case	ANALOG0:
			ADCON0	|= 0b00000001;
			break;
		case	ANALOG1:
			ADCON0	|= 0b00000101;
			break;
		case	ANALOG2:
			ADCON0	|= 0b00001001;
			break;
		case	ANALOG3:
			ADCON0	|= 0b00001101;
			break;
		case	ANALOG4:
			ADCON0	|= 0b00010001;
			break;
		case	ANALOG5:
			ADCON0	|= 0b00010101;
			break;
		case	ANALOG6:
			ADCON0	|= 0b00011001;
			break;
		case	ANALOG7:
			ADCON0	|= 0b00011101;
			break;
		default:
			break;
		}

		for( i = 0; i < WAIT_ACQUISITION; i++ );

		GO_nDONE	= 1;
		while( GO_nDONE );

		return	ADRESH;

	}else{
		return	0x00;
	}


}
