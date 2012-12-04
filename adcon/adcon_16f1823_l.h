/*
 * File:   adcon_16f1823_l.h
 * Author: Master
 *
 * Created on 2012/07/18 21:03
 */

#ifndef	_ADCON_16F1823_L_H_
#define	_ADCON_16F1823_L_H_


/*****************************************************/
#define	ERR_FREQ	0xF0
/*---------------------------------------------------*/
/*****************************************************/

/*****************************************************/
static unsigned char	getFreq( unsigned long f_osc );
static void	getPortNumber( unsigned int num_port, unsigned char* port, unsigned char* number );
/*****************************************************/

#endif
