/*************************************************************
2011年　5年回路班　日下作成
*************************************************************/
//PIC16F1938 Hi-Tech C Ver9.83,MPLAB Ver8.80
//CONFIG1とCONFIG2に分ける。

__CONFIG( FOSC_INTOSC & WDTE_OFF & PWRTE_OFF & MCLRE_OFF & CP_OFF & CPD_OFF & BOREN_ON & CLKOUTEN_OFF & IESO_OFF & FCMEN_OFF );			
__CONFIG( WRT_OFF & VCAPEN_OFF & PLLEN_ON & STVREN_OFF & BORV_HI & LVP_OFF );

/*
 ----------CONFIG1----------
;bit0-2=クロック制御　FOSC<2:0>
 ; FOSC_ECH , 111 , 外部クロック、高電力モード(4-32MHz): RA7:クロック入力
 ; FOSC_ECM , 110 , 外部クロック、中電力モード(0.5-4MHz): RA7:クロック入力
 ; FOSC_ECL , 101 , 外部クロック、低電力モード(0-0.5MHz): RA7:クロック入力
 ; FOSC_INTRC , 100 , 内部クロック、RA7：I/O ピン
 ; FOSC_EXTRC , 011 , RA7：RC機能
 ; FOSC_HS , 010 , 高周波数水晶／セラミック振動子
 ; FOSC_XT , 001 , 水晶／セラミック振動子
 ; FOSC_LP , 000 , 低周波数水晶振動子
 ;
 ;bit3-4=ウォッチドッグタイマーイネーブル
 ; WDTE
 ; WDTE_ON, 11 , ウォッチドッグタイマー有効
 ; WDTE_NSLEEP, 10 ,動作時有効、スリープ時無効
 ; WDTE_SWDTEN, 01 ,WDTCON レジスタの SWDTEN ビットで制御される
 ; WDTE_OFF, 00 , ウォッチドッグタイマー無効
 ;
 ;bit5=パワーアップタイマーイネーブル
 ; PWRTE
 ; PWRTE_OFF , 1 , パワーアップタイマー無効
 ; PWRTE_ON , 0 , パワーアップタイマー有効
 ;
 ;bit6=RE3/MCLR ピン機能選択
 ; MCLRE
 ; LVPビット=1の場合
 ; この設定は無視される
 ;
 ; LVPビット=0の場合
 ; MCLRE_ON , 1 , MCLR 機能有効
 ; MCLRE_OFF , 0 , MCLR 機能無効、入力ピンとして動作
 ;
 ;bit7=コードプロテクション
 ; CP
 ; CP_OFF , 1 , プログラムメモリー保護無効
 ; CP_ON , 0 , プログラムメモリー保護有効
 ;
 ;bit8=データコードプロテクション
 ; CPD
 ; CPD_OFF , 1 データメモリー保護無効
 ; CPD_ON , 0 , データメモリー保護有効
 ;
 ;bit89-10=ブラウンアウトリセット選択
 ; BOREN_OFF , 00 , ブラウンアウト無効
 ; BOREN_SBODEN , 01 , ソフトウェア制御による
 ; BOREN_NSLEEP , 10 , 動作中はブラウンアウト有効、スリープ中は無効
 ; BOREN_ON , 11, ブラウンアウト有効
 ;
 ;bit11=クロック出力イネーブル ビット
 ; CLKOUTEN
 ; CLKOUTEN_OFF , 1 ,クロック出力機能無効
 ; CLKOUTEN_ON , 0 , クロック出力有効
 ;  
 ;bit12=内部･外部クロック切替イネーブル
 ; IESO_ON ,1 , 内部・外部クロック切替有効
 ; IESO_OFF ,0 , 内部・外部クロック切替無効
 ;
 ;bit13=フェイルセーフクロックモニターイネーブル
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
 ;bit13=低電圧プログラミングイネーブル
 ; LVP
 ; LVP_OFF , 0 , 低電圧プログラミング無効、RB3はデジタルI/O
 ; LVP_ON , 1 , 低電圧プログラミング有効
 ;
 ;bit10=ブラウンアウトリセット選択
 ;BORV
 ;BORV_HI , 0 , ブラウンアウトリセットを2.7V に設定
 ;BORV_LO , 1 , ブラウンアウトリセットを1.9V に設定
 ;
 ;bit9=スタックオーバーフローイネーブル
 ;STVREN
 ;STVREN_OFF , 0 , スタックオーバーフローまたはアンダーフローはリセットを発生させない 
 ;STVREN_ON , 1 , スタックオーバーフローまたはアンダーフローはリセットを発生する
 ;
 ;bit8=PLLイネーブル
 ;PLL
 ;PLLEN_OFF, 0 ,PLL無効
 ;PLLEN_ON , 1 ,PLL有効
 ;
 ;bit4-5=電圧レギュレータ キャパシタ イネーブル ビット
 ;VCAPEN_RA0, 00 , VcapはRA0で有効 
 ;VCAPEN_RA5, 01 , VcapはRA5で有効
 ;VCAPEN_RA6, 10 , VcapはRA6で有効
 ;VCAPEN_OFF, 11 , Vcapは無効
 ;
 ;bit0-1=フラッシュメモリーセルフライトイネーブル
 ;WRT
 ;WRT_ALL , 00 , すべて保護
 ;WRT_HALF , 10 , 0000h ～ 01FFFh を保護、それ以外は書き換え可能
 ;WRT_BOOT , 01 , 0000h ～ 01FFh を保護、それ以外は書き換え可能
 ;WRT_OFF ,11 , 保護無効
 */
