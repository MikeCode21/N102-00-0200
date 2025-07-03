#ifndef 	MSG_H
#define 	MSG_H

#define		KEY_INVALID					0 
#define		KEY_ID						  0xff
#define 	KEY_BREAK					  0x0100     //短按抬起
#define 	KEY_LONG					  0x0200     //长按
#define 	KEY_LONG_BREAK		  0x0300	//长按抬起
#define 	KEY_LONG_START		  0x0400	//长按开始   （按下一秒钟发出）

#define LONG_KEY_START_TIME				100   //长按开始时间
#define LONG_KEY_TIME							15    //长安发long key 时间间隔

#define 	KB_ACTIVE				1
#define 	IR_ACTIVE				2
#define 	FS_ACTIVE				3
#define 	VFD_ACTIVE			4
#define 	TOUTH_ACTIVE		5
#define 	SCAN_ACTIVE			6
#define 	NO_ACTIVE				0

#define   SET_MSG_CHANNEL(n)   (n<<12)


#define K1					0x0001
#define K2					0x0002
#define K3					0x0003
#define K4					0x0004
#define K5					0x0005
#define K6					0x0006
#define K7					0x0007
#define K8					0x0008
#define K9					0x0009
#define K10					0x000a
#define K11					0x000b
#define K12					0x000c
#define K13					0x000d
#define K14					0x000e
#define K15					0x000f
#define K16					0x0010
#define K17					0x0011
#define K18					0x0012
#define K19					0x0013
#define K20					0x0014
#define K21					0x0015
#define K22					0x0016
#define K23					0x0017
#define K24					0x0018
#define K25					0x0019
#define K26					0x001a
#define K27					0x001b
#define K28					0x001c
#define K29					0x001d
#define K30					0x001e
#define K31					0x001f

#define K1_BREAK					0x0101
#define K2_BREAK					0x0102
#define K3_BREAK					0x0103
#define K4_BREAK					0x0104
#define K5_BREAK					0x0105
#define K6_BREAK					0x0106
#define K7_BREAK					0x0107
#define K8_BREAK					0x0108
#define K9_BREAK					0x0109
#define K10_BREAK					0x010a
#define K11_BREAK					0x010b
#define K12_BREAK					0x010c
#define K13_BREAK					0x010d
#define K14_BREAK					0x010e
#define K15_BREAK					0x010f
#define K16_BREAK					0x0110
#define K17_BREAK					0x0111
#define K18_BREAK					0x0112
#define K19_BREAK					0x0113
#define K20_BREAK					0x0114
#define K21_BREAK					0x0115
#define K22_BREAK					0x0116
#define K23_BREAK					0x0117
#define K24_BREAK					0x0118
#define K25_BREAK					0x0119
#define K26_BREAK					0x011a
#define K27_BREAK					0x011b
#define K28_BREAK					0x011c
#define K29_BREAK					0x011d
#define K30_BREAK					0x011e
#define K31_BREAK					0x011f

#define K1_LONG						0x0201
#define K2_LONG						0x0202
#define K3_LONG						0x0203
#define K4_LONG						0x0204
#define K5_LONG						0x0205
#define K6_LONG						0x0206
#define K7_LONG						0x0207
#define K8_LONG						0x0208
#define K9_LONG						0x0209
#define K10_LONG					0x020a
#define K11_LONG					0x020b
#define K12_LONG					0x020c
#define K13_LONG					0x020d
#define K14_LONG					0x020e
#define K15_LONG					0x020f
#define K16_LONG					0x0210
#define K17_LONG					0x0211
#define K18_LONG					0x0212
#define K19_LONG					0x0213
#define K20_LONG					0x0214
#define K21_LONG					0x0215
#define K22_LONG					0x0216
#define K23_LONG					0x0217
#define K24_LONG					0x0218
#define K25_LONG					0x0219
#define K26_LONG					0x021a
#define K27_LONG					0x021b
#define K28_LONG					0x021c
#define K29_LONG					0x021d
#define K30_LONG					0x021e
#define K31_LONG					0x021f

#define K1_LONG_BREAK						0x0301
#define K2_LONG_BREAK						0x0302
#define K3_LONG_BREAK						0x0303
#define K4_LONG_BREAK						0x0304
#define K5_LONG_BREAK						0x0305
#define K6_LONG_BREAK						0x0306
#define K7_LONG_BREAK						0x0307
#define K8_LONG_BREAK						0x0308
#define K9_LONG_BREAK						0x0309
#define K10_LONG_BREAK					0x030a
#define K11_LONG_BREAK					0x030b
#define K12_LONG_BREAK					0x030c
#define K13_LONG_BREAK					0x030d
#define K14_LONG_BREAK					0x030e
#define K15_LONG_BREAK					0x030f
#define K16_LONG_BREAK					0x0310
#define K17_LONG_BREAK					0x0311
#define K18_LONG_BREAK					0x0312
#define K19_LONG_BREAK					0x0313
#define K20_LONG_BREAK					0x0314
#define K21_LONG_BREAK					0x0315
#define K22_LONG_BREAK					0x0316
#define K23_LONG_BREAK					0x0317
#define K24_LONG_BREAK					0x0318
#define K25_LONG_BREAK					0x0319
#define K26_LONG_BREAK					0x031a
#define K27_LONG_BREAK					0x031b
#define K28_LONG_BREAK					0x031c
#define K29_LONG_BREAK					0x031d
#define K30_LONG_BREAK					0x031e
#define K31_LONG_BREAK					0x031f


#define K1_LONG_START						0x0401
#define K2_LONG_START						0x0402
#define K3_LONG_START						0x0403
#define K4_LONG_START						0x0404
#define K5_LONG_START						0x0405
#define K6_LONG_START						0x0406
#define K7_LONG_START						0x0407
#define K8_LONG_START						0x0408
#define K9_LONG_START						0x0409
#define K10_LONG_START					0x040a
#define K11_LONG_START					0x040b
#define K12_LONG_START					0x040c
#define K13_LONG_START					0x040d
#define K14_LONG_START					0x040e
#define K15_LONG_START					0x040f
#define K16_LONG_START					0x0410
#define K17_LONG_START					0x0411
#define K18_LONG_START					0x0412
#define K19_LONG_START					0x0413
#define K20_LONG_START					0x0414
#define K21_LONG_START					0x0415
#define K22_LONG_START					0x0416
#define K23_LONG_START					0x0417
#define K24_LONG_START					0x0418
#define K25_LONG_START					0x0419
#define K26_LONG_START					0x041a
#define K27_LONG_START					0x041b
#define K28_LONG_START					0x041c
#define K29_LONG_START					0x041d
#define K30_LONG_START					0x041e
#define K31_LONG_START					0x041f

///////////////////////////////////////////////////////////
#define KEY_NEXT											K1
#define KEY_NEXT_LONG									K1_LONG
#define KEY_NEXT_BREAK								K1_BREAK
#define KEY_NEXT_LONG_START						K1_LONG_START
#define KEY_NEXT_LONG_BREAK						K1_LONG_BREAK
/////////////////////////////////////////////////////
#define KEY_PREVIOUS									K2
#define KEY_PREVIOUS_LONG							K2_LONG
#define KEY_PREVIOUS_BREAK						K2_BREAK
#define KEY_PREVIOUS_LONG_START				K2_LONG_START
#define KEY_PREVIOUS_LONG_BREAK				K2_LONG_BREAK
//////////////////////////////////////////////////////
#define KEY_POWER											K3
#define KEY_POWER_BREAK								K3_BREAK
#define KEY_POWER_LONG								K3_LONG
#define KEY_POWER_LONG_START					K3_LONG_START
#define KEY_POWER_LONG_BREAK					K3_LONG_BREAK
/////////////////////////////////////////////////////
#define KEY_FUNCTION									K4
#define KEY_FUNCTION_BREAK						K4_BREAK
#define KEY_FUNCTION_LONG							K4_LONG
#define KEY_FUNCTION_LONG_START				K4_LONG_START
/////////////////////////////////////////////////////
#define KEY_VOL_UP										K5
#define KEY_VOL_UP_BREAK							K5_BREAK
#define KEY_VOL_UP_LONG_START					K5_LONG_START
#define KEY_VOL_UP_LONG								K5_LONG
////////////////////////////////////////////////////
#define KEY_VOL_DN										K6
#define KEY_VOL_DN_BREAK							K6_BREAK
#define KEY_VOL_DN_LONG_START					K6_LONG_START
#define KEY_VOL_DN_LONG								K6_LONG
///////////////////////////////////////////////////
#define KEY_BAND											K7
#define KEY_BAND_BREAK								K7_BREAK
#define KEY_BAND_LONG_START						K7_LONG_START	
#define KEY_BAND_LONG									K7_LONG
///////////////////////////////////////////////////
#define KEY_CLOCK											K8
#define KEY_CLOCK_BREAK								K8_BREAK
#define KEY_CLOCK_LONG_START					K8_LONG_START
#define KEY_CLOCK_LONG								K8_LONG
///////////////////////////////////////////////////
#define KEY_ALARM											K9
#define KEY_ALARM_BREAK								K9_BREAK
#define KEY_ALARM_LONG_START					K9_LONG_START
#define KEY_ALARM_LONG								K9_LONG
///////////////////////////////////////////////////
#define KEY_EQ												K10
#define KEY_EQ_BREAK									K10_BREAK
#define KEY_EQ_LONG_START							K10_LONG_START
#define KEY_EQ_LONG										K10_LONG
///////////////////////////////////////////////////
#define KEY_MUTE											K11
#define KEY_MUTE_BREAK								K11_BREAK
#define KEY_MUTE_LONG_START						K11_LONG_START
#define KEY_MUTE_LONG									K11_LONG
///////////////////////////////////////////////////
#define KEY_MODE											K12
#define KEY_MODE_BREAK								K12_BREAK
#define KEY_MODE_LONG_START						K12_LONG_START
#define KEY_MODE_LONG									K12_LONG
///////////////////////////////////////////////////
#define KEY_TUN_UP										K13
#define KEY_TUN_UP_BREAK							K13_BREAK
#define KEY_TUN_UP_LONG_START					K13_LONG_START
#define KEY_TUN_UP_LONG								K13_LONG
///////////////////////////////////////////////////
#define KEY_TUN_DN										K14
#define KEY_TUN_DN_BREAK							K14_BREAK
#define KEY_TUN_DN_LONG_START					K14_LONG_START
#define KEY_TUN_DN_LONG								K14_LONG
///////////////////////////////////////////////////
#define KEY_SLEEP											K15
#define KEY_SLEEP_BREAK								K15_BREAK
#define KEY_SLEEP_LONG_START					K15_LONG_START
#define KEY_SLEEP_LONG								K15_LONG
///////////////////////////////////////////////////
#define KEY_CD												K16
#define KEY_CD_BREAK									K16_BREAK
#define KEY_CD_LONG_START							K16_LONG_START
#define KEY_CD_LONG										K16_LONG
///////////////////////////////////////////////////
#define KEY_TUNER											K17
#define KEY_TUNER_BREAK								K17_BREAK
#define KEY_TUNER_LONG_START					K17_LONG_START
#define KEY_TUNER_LONG								K17_LONG
///////////////////////////////////////////////////
#define KEY_TAPE											K18
#define KEY_TAPE_BREAK								K18_BREAK
#define KEY_TAPE_LONG_START						K18_LONG_START
#define KEY_TAPE_LONG									K18_LONG
///////////////////////////////////////////////////
#define KEY_AUX												K19
#define KEY_AUX_BREAK									K19_BREAK
#define KEY_AUX_LONG_START						K19_LONG_START
#define KEY_AUX_LONG									K19_LONG
///////////////////////////////////////////////////
#define KEY_USB												K20
#define KEY_USB_BREAK									K20_BREAK
#define KEY_USB_LONG_START						K20_LONG_START
#define KEY_USB_LONG									K20_LONG
///////////////////////////////////////////////////
#define KEY_SNOOZE										K21
#define KEY_SNOOZE_BREAK							K21_BREAK
#define KEY_SNOOZE_LONG_START				  K21_LONG_START
#define KEY_SNOOZE_LONG								K21_LONG
///////////////////////////////////////////////////
#define KEY_HBASS											K22
#define KEY_HBASS_BREAK								K22_BREAK
#define KEY_HBASS_LONG_START				  K22_LONG_START
#define KEY_HBASS_LONG								K22_LONG
///////////////////////////////////////////////////
#define KEY_INFO											K23
#define KEY_INFO_BREAK								K23_BREAK
#define KEY_INFO_LONG_START				  	K23_LONG_START
#define KEY_INFO_LONG									K23_LONG
///////////////////////////////////////////////////
#define KEY_STMO											K24
#define KEY_STMO_BREAK								K24_BREAK
#define KEY_STMO_LONG_START				  	K24_LONG_START
#define KEY_STMO_LONG									K24_LONG
///////////////////////////////////////////////////
#define KEY_SET												K25
#define KEY_SET_BREAK									K25_BREAK
#define KEY_SET_LONG_START				  	K25_LONG_START
#define KEY_SET_LONG									K25_LONG
///////////////////////////////////////////////////
#define KEY_ENTER											K26
#define KEY_ENTER_BREAK								K26_BREAK
#define KEY_ENTER_LONG_START				  K26_LONG_START
#define KEY_ENTER_LONG								K26_LONG
///////////////////////////////////////////////////
#define KEY_PLAY											K27
#define KEY_PLAY_BREAK								K27_BREAK
#define KEY_PLAY_LONG_START						K27_LONG_START
#define KEY_PLAY_LONG									K27_LONG
#define KEY_PLAY_LONG_BREAK						K27_LONG_BREAK
///////////////////////////////////////////////////
#define KEY_STOP											K28
#define KEY_STOP_BREAK								K28_BREAK
#define KEY_STOP_LONG_START						K28_LONG_START
///////////////////////////////////////////////////
#define KEY_PROG											K29
#define KEY_PROG_LONG_START						K29_LONG_START
#define KEY_PROG_LONG									K29_LONG
#define KEY_PROG_BREAK								K29_BREAK
///////////////////////////////////////////////////
#define KEY_MEMO_UP										K30
#define KEY_MEMO_UP_LONG_START				K30_LONG_START
#define KEY_MEMO_UP_LONG							K30_LONG
#define KEY_MEMO_UP_BREAK							K30_BREAK
///////////////////////////////////////////////////
#define KEY_MEMO_DN										K31
#define KEY_MEMO_DN_LONG_START				K31_LONG_START
#define KEY_MEMO_DN_LONG							K31_LONG
#define KEY_MEMO_DN_BREAK							K31_BREAK
///////////////////////////////////////////////////	
#define KEY_INTRO										 	 32
#define KEY_INTRO_LONG_START					(32|KEY_LONG_START)
#define KEY_INTRO_LONG								(32|KEY_LONG)
#define KEY_INTRO_BREAK								(32|KEY_BREAK)
///////////////////////////////////////////////////	
#define KEY_FOLDER_UP								 	 33
#define KEY_FOLDER_UP_LONG_START			(33|KEY_LONG_START)
#define KEY_FOLDER_UP_LONG						(33|KEY_LONG)
#define KEY_FOLDER_UP_BREAK						(33|KEY_BREAK)
///////////////////////////////////////////////////	
#define KEY_FOLDER_DN								 	 34
#define KEY_FOLDER_DN_LONG_START			(34|KEY_LONG_START)
#define KEY_FOLDER_DN_LONG						(34|KEY_LONG)
#define KEY_FOLDER_DN_BREAK						(34|KEY_BREAK)
///////////////////////////////////////////////////	
#define KEY_MENU								 	 		 35
#define KEY_MENU_LONG_START						(35|KEY_LONG_START)
#define KEY_MENU_LONG									(35|KEY_LONG)
#define KEY_MENU_BREAK								(35|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_SCROL_UP								 	 36
#define KEY_SCROL_UP_LONG_START				(36|KEY_LONG_START)
#define KEY_SCROL_UP_LONG							(36|KEY_LONG)
#define KEY_SCROL_UP_BREAK						(36|KEY_BREAK)
///////////////////////////////////////////////////	
#define KEY_SCROL_DN								 	 37
#define KEY_SCROL_DN_LONG_START				(37|KEY_LONG_START)
#define KEY_SCROL_DN_LONG							(37|KEY_LONG)
#define KEY_SCROL_DN_BREAK						(37|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_RANDOM								 	 	 38
#define KEY_RANDOM_LONG_START					(38|KEY_LONG_START)
#define KEY_RANDOM_LONG								(38|KEY_LONG)
#define KEY_RANDOM_BREAK							(38|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_REPEAT								 	 	 39
#define KEY_REPEAT_LONG_START					(39|KEY_LONG_START)
#define KEY_REPEAT_LONG								(39|KEY_LONG)
#define KEY_REPEAT_BREAK							(39|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_BT								 	 	 			40
#define KEY_BT_LONG_START							(40|KEY_LONG_START)
#define KEY_BT_LONG										(40|KEY_LONG)
#define KEY_BT_BREAK									(40|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_PREVIOUS_10								 41
#define KEY_PREVIOUS_10_LONG_START		(41|KEY_LONG_START)
#define KEY_PREVIOUS_10_LONG					(41|KEY_LONG)
#define KEY_PREVIOUS_10_BREAK					(41|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_NEXT_10								 			41
#define KEY_NEXT_10_LONG_START				(41|KEY_LONG_START)
#define KEY_NEXT_10_LONG							(41|KEY_LONG)
#define KEY_NEXT_10_BREAK							(41|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_DEL								 					42
#define KEY_DEL_LONG_START						(42|KEY_LONG_START)
#define KEY_DEL_LONG									(42|KEY_LONG)
#define KEY_DEL_BREAK									(42|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_OPEN								 				43
#define KEY_OPEN_LONG_START						(43|KEY_LONG_START)
#define KEY_OPEN_LONG									(43|KEY_LONG)
#define KEY_OPEN_BREAK								(43|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_SEARCH_UP								 		44
#define KEY_SEARCH_UP_LONG_START			(44|KEY_LONG_START)
#define KEY_SEARCH_UP_LONG						(44|KEY_LONG)
#define KEY_SEARCH_UP_BREAK						(44|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_SEARCH_DN								 		45
#define KEY_SEARCH_DN_LONG_START			(45|KEY_LONG_START)
#define KEY_SEARCH_DN_LONG						(45|KEY_LONG)
#define KEY_SEARCH_DN_BREAK						(45|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_MODE_PROG								 		46
#define KEY_MODE_PROG_LONG_START			(46|KEY_LONG_START)
#define KEY_MODE_PROG_LONG						(46|KEY_LONG)
#define KEY_MODE_PROG_BREAK						(46|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_T_MODE_PROG								 	47
#define KEY_T_MODE_PROG_LONG_START			(47|KEY_LONG_START)
#define KEY_T_MODE_PROG_LONG						(47|KEY_LONG)
#define KEY_T_MODE_PROG_BREAK						(47|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_RDS								 					48
#define KEY_RDS_LONG_START			  			(48|KEY_LONG_START)
#define KEY_RDS_LONG						  			(48|KEY_LONG)
#define KEY_RDS_BREAK										(48|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_PTY								 					49
#define KEY_PTY_LONG_START			  			(49|KEY_LONG_START)
#define KEY_PTY_LONG						  			(49|KEY_LONG)
#define KEY_PTY_BREAK										(49|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_REC								 					50
#define KEY_REC_LONG_START			  			(50|KEY_LONG_START)
#define KEY_REC_LONG						  			(50|KEY_LONG)
#define KEY_REC_BREAK										(50|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_DIMMER								 			 51
#define KEY_DIMMER_LONG_START			  		(51|KEY_LONG_START)
#define KEY_DIMMER_LONG						  		(51|KEY_LONG)
#define KEY_DIMMER_BREAK								(51|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_DISPLAY								 			 52
#define KEY_DISPLAY_LONG_START			  	(52|KEY_LONG_START)
#define KEY_DISPLAY_LONG						  	(52|KEY_LONG)
#define KEY_DISPLAY_BREAK								(52|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_ALARM1								 			 53
#define KEY_ALARM1_LONG_START			  		(53|KEY_LONG_START)
#define KEY_ALARM1_LONG						  		(53|KEY_LONG)
#define KEY_ALARM1_BREAK								(53|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_ALARM2								 			 54
#define KEY_ALARM2_LONG_START			  		(54|KEY_LONG_START)
#define KEY_ALARM2_LONG						  		(54|KEY_LONG)
#define KEY_ALARM2_BREAK								(54|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_ALARM2								 			 54
#define KEY_ALARM2_LONG_START			  		(54|KEY_LONG_START)
#define KEY_ALARM2_LONG						  		(54|KEY_LONG)
#define KEY_ALARM2_BREAK								(54|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_BASS_UP												55
#define KEY_BASS_UP_LONG_START					(KEY_BASS_UP|KEY_LONG_START)
#define KEY_BASS_UP_LONG								(KEY_BASS_UP|KEY_LONG)
#define KEY_BASS_UP_BREAK								(KEY_BASS_UP|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_BASS_DN												56
#define KEY_BASS_DN_LONG_START					(KEY_BASS_DN|KEY_LONG_START)
#define KEY_BASS_DN_LONG								(KEY_BASS_DN|KEY_LONG)
#define KEY_BASS_DN_BREAK								(KEY_BASS_DN|KEY_BREAK)
///////////////////////////////////////////////////

#define KEY_TREBLE_UP										 57
#define KEY_TREBLE_UP_LONG_START				(KEY_TREBLE_UP|KEY_LONG_START)
#define KEY_TREBLE_UP_LONG							(KEY_TREBLE_UP|KEY_LONG)
#define KEY_TREBLE_UP_BREAK							(KEY_TREBLE_UP|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_TREBLE_DN										58
#define KEY_TREBLE_DN_LONG_START				(KEY_TREBLE_DN|KEY_LONG_START)
#define KEY_TREBLE_DN_LONG							(KEY_TREBLE_DN|KEY_LONG)
#define KEY_TREBLE_DN_BREAK							(KEY_TREBLE_DN|KEY_BREAK)
///////////////////////////////////////////////////

/*****************************数字按键****************************************/
///////////////////////////////////////////////////
#define KEY_0														80
#define KEY_0_LONG_START								(KEY_0|KEY_LONG_START)
#define KEY_0_LONG											(KEY_0|KEY_LONG)
#define KEY_0_BREAK											(KEY_0|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_1														81
#define KEY_1_LONG_START								(KEY_1|KEY_LONG_START)
#define KEY_1_LONG											(KEY_1|KEY_LONG)
#define KEY_1_BREAK											(KEY_1|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_2														82
#define KEY_2_LONG_START								(KEY_2|KEY_LONG_START)
#define KEY_2_LONG											(KEY_2|KEY_LONG)
#define KEY_2_BREAK											(KEY_2|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_3														83
#define KEY_3_LONG_START								(KEY_3|KEY_LONG_START)
#define KEY_3_LONG											(KEY_3|KEY_LONG)
#define KEY_3_BREAK											(KEY_3|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_4														84
#define KEY_4_LONG_START								(KEY_4|KEY_LONG_START)
#define KEY_4_LONG											(KEY_4|KEY_LONG)
#define KEY_4_BREAK											(KEY_4|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_5														85
#define KEY_5_LONG_START								(KEY_5|KEY_LONG_START)
#define KEY_5_LONG											(KEY_5|KEY_LONG)
#define KEY_5_BREAK											(KEY_5|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_6														86
#define KEY_6_LONG_START								(KEY_6|KEY_LONG_START)
#define KEY_6_LONG											(KEY_6|KEY_LONG)
#define KEY_6_BREAK											(KEY_6|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_7														87
#define KEY_7_LONG_START								(KEY_7|KEY_LONG_START)
#define KEY_7_LONG											(KEY_7|KEY_LONG)
#define KEY_7_BREAK											(KEY_7|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_8														88
#define KEY_8_LONG_START								(KEY_8|KEY_LONG_START)
#define KEY_8_LONG											(KEY_8|KEY_LONG)
#define KEY_8_BREAK											(KEY_8|KEY_BREAK)
///////////////////////////////////////////////////
#define KEY_9														89
#define KEY_9_LONG_START								(KEY_9|KEY_LONG_START)
#define KEY_9_LONG											(KEY_9|KEY_LONG)
#define KEY_9_BREAK											(KEY_9|KEY_BREAK)
///////////////////////////////////////////////////
///////////////////////////////////////////////////
#define KEY_10														90
#define KEY_10_LONG_START								(KEY_10|KEY_LONG_START)
#define KEY_10_LONG											(KEY_10|KEY_LONG)
#define KEY_10_BREAK										(KEY_10|KEY_BREAK)
///////////////////////////////////////////////////
#ifdef HAVE_FS_KEY
	void _fs_msg_init(void);
	u16_t _fs_get_key(void);
	void Fs_ScanVol(void);
#endif

#ifdef HAVE_AD_KEY
	void _adkey_init(void);
	u8_t _adkey_get_msg(void);
#endif

#ifdef HAVE_IR_KEY
	void _ir_msg_init(void);
	u8_t _ir_get_msg(void);
#endif
#ifdef HAVE_TOUCH_KEY
	void _touch_init(void);
	u8_t _touth_get_msg(void);
#endif

#ifdef HAVE_SCAN_KEY
	void _scan_init(void);
	u8_t _scan_get_msg(void);
#endif
void msg_initial(void);
void _get_msg(void);
void _set_key_invalid(void);
void msg_timer_proc(void);
void IRC_init(void);
#endif