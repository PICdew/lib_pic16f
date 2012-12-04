/*************************************************************
2011�N�@5�N��H�ǁ@�����쐬
*************************************************************/
//PIC16F1938 Hi-Tech C Ver9.83,MPLAB Ver8.80
//CONFIG1��CONFIG2�ɕ�����B

__CONFIG( FOSC_INTOSC & WDTE_OFF & PWRTE_OFF & MCLRE_OFF & CP_OFF & CPD_OFF & BOREN_ON & CLKOUTEN_OFF & IESO_OFF & FCMEN_OFF );			
__CONFIG( WRT_OFF & VCAPEN_OFF & PLLEN_ON & STVREN_OFF & BORV_HI & LVP_OFF );

/*
 ----------CONFIG1----------
;bit0-2=�N���b�N����@FOSC<2:0>
 ; FOSC_ECH , 111 , �O���N���b�N�A���d�̓��[�h(4-32MHz): RA7:�N���b�N����
 ; FOSC_ECM , 110 , �O���N���b�N�A���d�̓��[�h(0.5-4MHz): RA7:�N���b�N����
 ; FOSC_ECL , 101 , �O���N���b�N�A��d�̓��[�h(0-0.5MHz): RA7:�N���b�N����
 ; FOSC_INTRC , 100 , �����N���b�N�ARA7�FI/O �s��
 ; FOSC_EXTRC , 011 , RA7�FRC�@�\
 ; FOSC_HS , 010 , �����g�������^�Z���~�b�N�U���q
 ; FOSC_XT , 001 , �����^�Z���~�b�N�U���q
 ; FOSC_LP , 000 , ����g�������U���q
 ;
 ;bit3-4=�E�H�b�`�h�b�O�^�C�}�[�C�l�[�u��
 ; WDTE
 ; WDTE_ON, 11 , �E�H�b�`�h�b�O�^�C�}�[�L��
 ; WDTE_NSLEEP, 10 ,���쎞�L���A�X���[�v������
 ; WDTE_SWDTEN, 01 ,WDTCON ���W�X�^�� SWDTEN �r�b�g�Ő��䂳���
 ; WDTE_OFF, 00 , �E�H�b�`�h�b�O�^�C�}�[����
 ;
 ;bit5=�p���[�A�b�v�^�C�}�[�C�l�[�u��
 ; PWRTE
 ; PWRTE_OFF , 1 , �p���[�A�b�v�^�C�}�[����
 ; PWRTE_ON , 0 , �p���[�A�b�v�^�C�}�[�L��
 ;
 ;bit6=RE3/MCLR �s���@�\�I��
 ; MCLRE
 ; LVP�r�b�g=1�̏ꍇ
 ; ���̐ݒ�͖��������
 ;
 ; LVP�r�b�g=0�̏ꍇ
 ; MCLRE_ON , 1 , MCLR �@�\�L��
 ; MCLRE_OFF , 0 , MCLR �@�\�����A���̓s���Ƃ��ē���
 ;
 ;bit7=�R�[�h�v���e�N�V����
 ; CP
 ; CP_OFF , 1 , �v���O�����������[�ی얳��
 ; CP_ON , 0 , �v���O�����������[�ی�L��
 ;
 ;bit8=�f�[�^�R�[�h�v���e�N�V����
 ; CPD
 ; CPD_OFF , 1 �f�[�^�������[�ی얳��
 ; CPD_ON , 0 , �f�[�^�������[�ی�L��
 ;
 ;bit89-10=�u���E���A�E�g���Z�b�g�I��
 ; BOREN_OFF , 00 , �u���E���A�E�g����
 ; BOREN_SBODEN , 01 , �\�t�g�E�F�A����ɂ��
 ; BOREN_NSLEEP , 10 , ���쒆�̓u���E���A�E�g�L���A�X���[�v���͖���
 ; BOREN_ON , 11, �u���E���A�E�g�L��
 ;
 ;bit11=�N���b�N�o�̓C�l�[�u�� �r�b�g
 ; CLKOUTEN
 ; CLKOUTEN_OFF , 1 ,�N���b�N�o�͋@�\����
 ; CLKOUTEN_ON , 0 , �N���b�N�o�͗L��
 ;  
 ;bit12=������O���N���b�N�ؑփC�l�[�u��
 ; IESO_ON ,1 , �����E�O���N���b�N�ؑ֗L��
 ; IESO_OFF ,0 , �����E�O���N���b�N�֖ؑ���
 ;
 ;bit13=�t�F�C���Z�[�t�N���b�N���j�^�[�C�l�[�u��
 ; FCMEN
 ; FCMEN_ON , 1 , �t�F�C���Z�[�t�N���b�N���j�^�[�L��
 ; FCMEN_OFF , 0 , �t�F�C���Z�[�t�N���b�N���j�^�[����
 ;
 ;bit12=��d���v���O���~���O�C�l�[�u��
 ; LVP
 ; LVP_OFF , 0 , ��d���v���O���~���O�����ARB3�̓f�W�^��I/O
 ; LVP_ON , 1 , ��d���v���O���~���O�L���A
 ;
 ;bit13=�C���T�[�L�b�g�f�o�b�K�[���[�h
 ;DEBUG
 ;DEBUG_ON , 0 , �C���T�[�L�b�g�f�o�b�O�L��
 ;DEBUG_OFF , 1 , �C���T�[�L�b�g�f�o�b�O����
 ;
 ;----------CONFIG2----------
 ;bit13=��d���v���O���~���O�C�l�[�u��
 ; LVP
 ; LVP_OFF , 0 , ��d���v���O���~���O�����ARB3�̓f�W�^��I/O
 ; LVP_ON , 1 , ��d���v���O���~���O�L��
 ;
 ;bit10=�u���E���A�E�g���Z�b�g�I��
 ;BORV
 ;BORV_HI , 0 , �u���E���A�E�g���Z�b�g��2.7V �ɐݒ�
 ;BORV_LO , 1 , �u���E���A�E�g���Z�b�g��1.9V �ɐݒ�
 ;
 ;bit9=�X�^�b�N�I�[�o�[�t���[�C�l�[�u��
 ;STVREN
 ;STVREN_OFF , 0 , �X�^�b�N�I�[�o�[�t���[�܂��̓A���_�[�t���[�̓��Z�b�g�𔭐������Ȃ� 
 ;STVREN_ON , 1 , �X�^�b�N�I�[�o�[�t���[�܂��̓A���_�[�t���[�̓��Z�b�g�𔭐�����
 ;
 ;bit8=PLL�C�l�[�u��
 ;PLL
 ;PLLEN_OFF, 0 ,PLL����
 ;PLLEN_ON , 1 ,PLL�L��
 ;
 ;bit4-5=�d�����M�����[�^ �L���p�V�^ �C�l�[�u�� �r�b�g
 ;VCAPEN_RA0, 00 , Vcap��RA0�ŗL�� 
 ;VCAPEN_RA5, 01 , Vcap��RA5�ŗL��
 ;VCAPEN_RA6, 10 , Vcap��RA6�ŗL��
 ;VCAPEN_OFF, 11 , Vcap�͖���
 ;
 ;bit0-1=�t���b�V���������[�Z���t���C�g�C�l�[�u��
 ;WRT
 ;WRT_ALL , 00 , ���ׂĕی�
 ;WRT_HALF , 10 , 0000h �` 01FFFh ��ی�A����ȊO�͏��������\
 ;WRT_BOOT , 01 , 0000h �` 01FFh ��ی�A����ȊO�͏��������\
 ;WRT_OFF ,11 , �ی얳��
 */
