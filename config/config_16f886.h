/*************************************************************
2011�N�@5�N��H�ǁ@�����쐬
*************************************************************/
//PIC6F886 Hi-Tech C Ver9.81,MPLAB Ver8.63
//CONFIG1��CONFIG2�ɕ�����B

__CONFIG(FOSC_INTRC_NOCLKOUT & WDTE_OFF & PWRTE_OFF & MCLRE_OFF & CPD_OFF & BOREN_OFF & BOREN_OFF & IESO_OFF & FCMEN_OFF & LVP_OFF & DEBUG_OFF ); 
__CONFIG(BOR4V_BOR40V & WRT_OFF); 

/*
 ----------CONFIG1----------
 ;bit0-2=�N���b�N����@FOSC<2:0>
 ; FOSC_EXTRC_CLKOUT , 111 , RA6�F�N���b�N�o�́ARA7�FRC ���U����
 ; FOSC_EXTRC_NOCLKOUT , 110 , RA6�FI/O �s���ARA7�FRC ���U����
 ; FOSC_INTRC_CLKOUT , 101 , RA6�F�N���b�N�o�́ARA7�FI/O �s��
 ; FOSC_INTRC_NOCLKOUT , 100 , RA6�FI/O �s���ARA7�FI/O �s���A�����N���b�N
 ; FOSC_EC , 011 , RA6�FI/O �s���ARA7�F�N���b�N����
 ; FOSC_HS , 010 , �����g�������^�Z���~�b�N�U���q
 ; FOSC_XT , 001 , �����^�Z���~�b�N�U���q
 ; FOSC_LP , 000 , ����g�������U���q
 ;
 ;bit3=�E�H�b�`�h�b�O�^�C�}�[�C�l�[�u��
 ; WDTE
 ; WDTE_ON, 1 , �E�H�b�`�h�b�O�^�C�}�[�L��
 ; WDTE_OFF, 0 , �E�H�b�`�h�b�O�^�C�}�[����
 ;
 ;bit4=�p���[�A�b�v�^�C�}�[�C�l�[�u��
 ; PWRTE
 ; PWRTE_OFF , 1 , �p���[�A�b�v�^�C�}�[����
 ; PWRTE_ON , 0 , �p���[�A�b�v�^�C�}�[�L��
 ;
 ;bit5=RE3/MCLR �s���@�\�I��
 ; MCLRE
 ; MCLRE_ON , 1 , MCLR �@�\�L��
 ; MCLRE_OFF , 0 , MCLR �@�\�����A���̓s���Ƃ��ē���
 ;
 ;bit6=�R�[�h�v���e�N�V����
 ; CP
 ; CP_OFF , 1 , �v���O�����������[�ی얳��
 ; CP_ON , 0 , �v���O�����������[�ی�L��
 ;
 ;bit7=�f�[�^�R�[�h�v���e�N�V����
 ; CPD
 ; CPD_OFF , 1 �f�[�^�������[�ی얳��
 ; CPD_ON , 0 , �f�[�^�������[�ی�L��
 ;
 ;bit8-9=�u���E���A�E�g���Z�b�g�I��
 ; BOREN_OFF , 00 , �u���E���A�E�g����
 ; BOREN_SBODEN , 01 , �\�t�g�E�F�A����ɂ��
 ; BOREN_NSLEEP , 10 , ���쒆�̓u���E���A�E�g�L���A�X���[�v���͖���
 ; BOREN_ON , 11, �u���E���A�E�g�L��
 ;
 ;bit10=������O���N���b�N�ؑփC�l�[�u��
 ; IESO_ON ,1 , �����E�O���N���b�N�ؑ֗L��
 ; IESO_OFF ,0 , �����E�O���N���b�N�֖ؑ���
 ;
 ;bit11=�t�F�C���Z�[�t�N���b�N���j�^�[�C�l�[�u��
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
 ;bit8=�u���E���A�E�g���Z�b�g�I��
 ;BOR4V
 ;BOR4V_BOR21V , 0 , �u���E���A�E�g���Z�b�g��2.1V �ɐݒ�
 ;BOR4V_BOR40V , 1, �u���E���A�E�g���Z�b�g��4.0V �ɐݒ�
 ;
 ;bit9-10=�t���b�V���������[�Z���t���C�g�C�l�[�u��
 ;WRT<1:0>
 ;WRT_256 , 00 , 0000h �` 00FFh ��ی�A����ȊO�͏��������\
 ;WRT_1FOURTH , 01 , 0000h �` 07FFh ��ی�A����ȊO�͏��������\
 ;WRT_HALF , 10 , 0000h �` 0FFFh ��ی�A����ȊO�͏��������\
 ;WRT_OFF ,11
 */