/*************************************************************
2011年　5年回路班　日下作成
*************************************************************/
//PIC6F886 Hi-Tech C Ver9.81,MPLAB Ver8.63
//CONFIG1とCONFIG2に分ける。

__CONFIG(FOSC_INTRC_NOCLKOUT & WDTE_OFF & PWRTE_OFF & MCLRE_OFF & CPD_OFF & BOREN_OFF & BOREN_OFF & IESO_OFF & FCMEN_OFF & LVP_OFF & DEBUG_OFF ); 
__CONFIG(BOR4V_BOR40V & WRT_OFF); 

/*
 ----------CONFIG1----------
 ;bit0-2=クロック制御　FOSC<2:0>
 ; FOSC_EXTRC_CLKOUT , 111 , RA6：クロック出力、RA7：RC 発振入力
 ; FOSC_EXTRC_NOCLKOUT , 110 , RA6：I/O ピン、RA7：RC 発振入力
 ; FOSC_INTRC_CLKOUT , 101 , RA6：クロック出力、RA7：I/O ピン
 ; FOSC_INTRC_NOCLKOUT , 100 , RA6：I/O ピン、RA7：I/O ピン、内部クロック
 ; FOSC_EC , 011 , RA6：I/O ピン、RA7：クロック入力
 ; FOSC_HS , 010 , 高周波数水晶／セラミック振動子
 ; FOSC_XT , 001 , 水晶／セラミック振動子
 ; FOSC_LP , 000 , 低周波数水晶振動子
 ;
 ;bit3=ウォッチドッグタイマーイネーブル
 ; WDTE
 ; WDTE_ON, 1 , ウォッチドッグタイマー有効
 ; WDTE_OFF, 0 , ウォッチドッグタイマー無効
 ;
 ;bit4=パワーアップタイマーイネーブル
 ; PWRTE
 ; PWRTE_OFF , 1 , パワーアップタイマー無効
 ; PWRTE_ON , 0 , パワーアップタイマー有効
 ;
 ;bit5=RE3/MCLR ピン機能選択
 ; MCLRE
 ; MCLRE_ON , 1 , MCLR 機能有効
 ; MCLRE_OFF , 0 , MCLR 機能無効、入力ピンとして動作
 ;
 ;bit6=コードプロテクション
 ; CP
 ; CP_OFF , 1 , プログラムメモリー保護無効
 ; CP_ON , 0 , プログラムメモリー保護有効
 ;
 ;bit7=データコードプロテクション
 ; CPD
 ; CPD_OFF , 1 データメモリー保護無効
 ; CPD_ON , 0 , データメモリー保護有効
 ;
 ;bit8-9=ブラウンアウトリセット選択
 ; BOREN_OFF , 00 , ブラウンアウト無効
 ; BOREN_SBODEN , 01 , ソフトウェア制御による
 ; BOREN_NSLEEP , 10 , 動作中はブラウンアウト有効、スリープ中は無効
 ; BOREN_ON , 11, ブラウンアウト有効
 ;
 ;bit10=内部･外部クロック切替イネーブル
 ; IESO_ON ,1 , 内部・外部クロック切替有効
 ; IESO_OFF ,0 , 内部・外部クロック切替無効
 ;
 ;bit11=フェイルセーフクロックモニターイネーブル
 ; FCMEN
 ; FCMEN_ON , 1 , フェイルセーフクロックモニター有効
 ; FCMEN_OFF , 0 , フェイルセーフクロックモニター無効
 ;
 ;bit12=低電圧プログラミングイネーブル
 ; LVP
 ; LVP_OFF , 0 , 低電圧プログラミング無効、RB3はデジタルI/O
 ; LVP_ON , 1 , 低電圧プログラミング有効、
 ;
 ;bit13=インサーキットデバッガーモード
 ;DEBUG
 ;DEBUG_ON , 0 , インサーキットデバッグ有効
 ;DEBUG_OFF , 1 , インサーキットデバッグ無効
 ;
 ;----------CONFIG2----------
 ;bit8=ブラウンアウトリセット選択
 ;BOR4V
 ;BOR4V_BOR21V , 0 , ブラウンアウトリセットを2.1V に設定
 ;BOR4V_BOR40V , 1, ブラウンアウトリセットを4.0V に設定
 ;
 ;bit9-10=フラッシュメモリーセルフライトイネーブル
 ;WRT<1:0>
 ;WRT_256 , 00 , 0000h ～ 00FFh を保護、それ以外は書き換え可能
 ;WRT_1FOURTH , 01 , 0000h ～ 07FFh を保護、それ以外は書き換え可能
 ;WRT_HALF , 10 , 0000h ～ 0FFFh を保護、それ以外は書き換え可能
 ;WRT_OFF ,11
 */