/*
 * File:   uarth
 * Author: Master
 *
 * Created on 2012/06/22 16:12
 */

/*
 * �g����
 *
 * 1.�g�������t�@�C����,"uart.h"���C���N���[�h����
 * 2.�v���W�F�N�g�ɁC"uart.c"��"fifo.c"�𓱓�����
 * 3.���荞�݊֐��ɁC"interruptUart();"��}������
 *
 * ���ӎ���
 * initUart�֐������s����ƁC�S�̊��荞�݋��Ȃ�тɎ��Ӌ@�튄�荞�݋����C�l�[�u������܂��D
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
	/* 1�o�C�g�f�[�^��UART�ő��M����֐�
	 * ����	
	 * char data	: ���M����1�o�C�g�f�[�^
	 * �Ԃ�l
	 * �Ȃ�
	 */

void	putsUart( char* str );
	/* ������𑗐M����
	 * ����	
	 * char* str	: ���M���镶����
	 * �Ԃ�l
	 * �Ȃ�
	 */

unsigned char	getcUart( char* data );
	/* ��M�o�b�t�@����1�o�C�g���o��
	 * ����
	 * char* data	: ���o�����f�[�^��ۑ�����A�h���X
	 * �Ԃ�l
	 * 0	: ����Ƀf�[�^��ǂ݂�����
	 * 1	: �f�[�^�����݂��Ȃ�
	 */

inline void	interruptUart( void );
/* ---------------------------------- */


#endif
