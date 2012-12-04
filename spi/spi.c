/***************************************
* 2011年度 5年 基板間通信処理
*
* Device	:PIC16F88,886,1827
*
* Author	:石倉万希斗
*
* Latest	:2011/09/19 17:12
*****************************************/

#include <xc.h>
#include "spi.h"

/****************************************/
/* SPI通信基本関数 */
char tradeSPI(unsigned char send_data, unsigned char *p_buffer)	//1バイト送受信
{
	/* SPI通信で1バイト通信を行う関数． */
	/* 正常終了したら，*p_bufferへ受信データを渡す． */
	
	/* 戻り値 */
	/*0:正常終了*/
	/*1:タイムアウトエラー*/

	enum{
		TIMEOUT	= 20000
	};
	
	unsigned int	i = 0;

	DEF_SSPBUF	= send_data;	//送信データセット
	
	while((!(SSPSTAT & 0x01)) && (i < TIMEOUT)){i++;}
	//エラー1:タイムアウトエラー
	if(i == TIMEOUT){return ERR_TIMEOUT;}

	*p_buffer	= DEF_SSPBUF;

	return	0;
}

/******************************************/


/******************************************/
/* 通信初期設定 */

#if defined _PIC16F1827_H_
void initializeSPI( unsigned char mode, unsigned char apfcon_sdo, unsigned char apfcon_ss )
#elif defined	_PIC16F1939_H_
void initializeSPI( unsigned char mode, unsigned char apfcon_ss )
#else
void initializeSPI( unsigned char mode )
#endif
{
#if	defined	_PIC16F88_H_
	/* 16F88 初期設定 */	
	
	//ポート設定
	TRISB1 = 1; //SDI
	TRISB2 = 0;	//SDO

	SMP = 0;
	CKP = 0;
	CKE = 0;//波形を選択

        switch( mode ){
            case    SPI_MASTER_MODE:
                TRISB4 = 0;	//SCK
            break;

            case    SPI_SLAVE_MODE_SS_ENABLE:
                TRISB4 = 1;	//SCK
                TRISB5  = 1;    //SS
                break;

            case    SPI_SLAVE_MODE_SS_DISABLE:
                TRISB4  = 1;	//SCK
                break;
            break;
        }

        SSPCON  |= mode;
        SSPEN   = 1;


#elif	defined	_PIC16F877A_H_
	/* 16F877A 初期設定 */

	//ポート設定
	TRISC4 = 1; //SDI
	TRISC5 = 0;	//SDO

	//レジスタ設定
	SMP = 0;
	CKP = 0;
	CKE = 0;//波形を選択

        switch( mode ){
            case    SPI_MASTER_MODE:
                TRISC3 = 0;	//SCK
            break;

            case    SPI_SLAVE_MODE_SS_ENABLE:
                TRISC3 = 1;	//SCK
                TRISA5 = 1; //SS
                break;

            case    SPI_SLAVE_MODE_SS_DISABLE:
                TRISC3 = 1;	//SCK
                break;
            break;
        }

        SSPCON  |= mode;
        SSPEN   = 1;


#elif	defined	_PIC16F886_H_
	/* 16F886 初期設定 */	
	
	//ポート設定
	TRISC4 = 1; //SDI
	TRISC5 = 0;	//SDO
	
	//レジスタ設定
	SMP = 0;
	CKP = 0;
	CKE = 0;//波形を選択

        switch( mode ){
            case    SPI_MASTER_MODE:
                TRISC3 = 0;	//SCK
            break;

            case    SPI_SLAVE_MODE_SS_ENABLE:
                TRISC3 = 1;	//SCK
                TRISA5 = 1; //SS
                break;

            case    SPI_SLAVE_MODE_SS_DISABLE:
                TRISC3 = 1;	//SCK
                break;
            break;
        }

        SSPCON  |= mode;
        SSPEN   = 1;

	
#elif	defined	_PIC16F1827_H_
	/* 16F1827 初期設定 */
	
	//ポート設定
	SDO1SEL	= apfcon_sdo;
	SS1SEL	= apfcon_ss;
	
	if(apfcon_sdo == SDO_RB2 ){
		TRISB2	= 0;
	}else{
		TRISA6	= 0;
	}

        TRISB1 = 1; //SDI1

        SSPSTAT = 0x00;

        switch( mode ){
            case    SPI_MASTER_MODE:
            	TRISB4 = 0;	//SCK1
            break;

            case    SPI_SLAVE_MODE_SS_ENABLE:
                TRISB4 = 1;	//SCK1

                if(apfcon_ss == 0){ //SS
                        TRISB5	= 1;
                }else{
                        TRISA5	= 1;
                }

                break;

            case    SPI_SLAVE_MODE_SS_DISABLE:
                TRISB4 = 1;	//SCK1
                break;
            break;
        }

        SSP1CON1  |= mode;
        SSP1CON1    |= 0x20;


#elif	defined	_PIC16F1939_H_
	/* 16F1939 初期設定 */
	
	//ポート設定
	SSSEL	= apfcon_ss;

	TRISC5	= 0;	//SDO
	TRISC4 = 1; //SDI

	SSPSTAT = 0x00;

	switch( mode ){
		case    SPI_MASTER_MODE:
			TRISC3 = 0;	//SCK
		break;

		case    SPI_SLAVE_MODE_SS_ENABLE:
			TRISC4 = 1;	//SCK

			if(apfcon_ss == SS_RA5){ //SS
					TRISA5	= 1;
			}else{
					TRISA0	= 1;
			}

			break;

		case    SPI_SLAVE_MODE_SS_DISABLE:
			TRISC4 = 1;	//SCK1
			break;

		default:
		break;
	}

	SSPCON1	= 0x00;
	SSPCON1  |= mode;
	SSPCON1    |= 0x20;


#endif
}


