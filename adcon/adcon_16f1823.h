/*
 * File:   adcon_16f1823.h
 * Author: Master
 *
 * Created on 2012/07/18 21:03
 */

#ifndef	_ADCON_16F1823_H_
#define	_ADCON_16F1823_H_


/*****************************************************/
#ifndef	FALSE
#define	FALSE	0
#endif
#ifndef	TRUE
#define	TRUE	1
#endif
typedef	unsigned char bool;
/*****************************************************/


/*****************************************************/
#define	PORTNUM_A	0x00
#define	PORTNUM_C	0x02

#define	ANALOG0	(PORTNUM_A << 8) | 0x0001
#define	ANALOG1	(PORTNUM_A << 8) | 0x0002
#define	ANALOG2	(PORTNUM_A << 8) | 0x0004
#define	ANALOG3	(PORTNUM_A << 8) | 0x0010
#define	ANALOG4	(PORTNUM_C << 8) | 0x0001
#define	ANALOG5	(PORTNUM_C << 8) | 0x0002
#define	ANALOG6	(PORTNUM_C << 8) | 0x0004
#define	ANALOG7	(PORTNUM_C << 8) | 0x0008

/*---------------------------------------------------*/
#define	VREF_VDD_ADCON	0
/*---------------------------------------------------*/
#define	ERR_INIT_ADCON	1
/*---------------------------------------------------*/
/*****************************************************/





/*****************************************************/
unsigned char	initAdcon( unsigned long f_osc, unsigned char vref );
void	setPortAdcon( unsigned int num_port );
void	resetPortAdcon( unsigned int num_port );
unsigned char	get8bitAdcon( unsigned int num_port );
unsigned int	get10bitAdcon( unsigned int num_port );
bool	isPortReadyAdcon( unsigned int num_port );
/*****************************************************/


#endif
