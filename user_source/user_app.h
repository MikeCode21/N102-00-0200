#ifndef USER_APP_H
#define USER_APP_H
//////////////////////////////////////////////////
void user_init();
void user_app_proc();


/*********************IO口引脚配置************************* */
//数码管和LED灯，正反扫IO配置
#define             p_smg_com1          P13
#define             p_smg_com2          P12
#define             p_smg_com3          P11
#define             p_smg_com4          P10
#define             p_smg_com5          P20
#define             p_smg_ae            P17
#define             p_smg_bf            P16
#define             p_smg_cg            P15
#define             p_smg_dp            P14

//继电器、可控硅IO口配置
#define             p_scr               P27
#define             p_rly1              P30
#define             p_rly2              P31

//蜂鸣器IO口配置
#define             p_buzzer            P04

//编码器IO口配置
#define             p_sw_a              P07
#define             p_sw_b              P06
#define             p_sw_key            P05

//温度传感器IO口配置
#define             p_temp_t1           P25
#define             p_temp_t2           P24
#define             p_temp_t3           P23

/////////////////////////////////////////////////
/**********************IO口引脚模式配置*********************** */
//数码管和LED灯
//输入模式
#define             p_smg_com1_in       P13_CFG_INPUT_PULL_NO
#define             p_smg_com2_in       P12_CFG_INPUT_PULL_NO 
#define             p_smg_com3_in       P11_CFG_INPUT_PULL_NO
#define             p_smg_com4_in       P10_CFG_INPUT_PULL_NO
#define             p_smg_com5_in       P20_CFG_INPUT_PULL_NO
#define             p_smg_ae_in         P17_CFG_INPUT_PULL_NO
#define             p_smg_bf_in         P16_CFG_INPUT_PULL_NO
#define             p_smg_cg_in         P15_CFG_INPUT_PULL_NO
#define             p_smg_dp_in         P14_CFG_INPUT_PULL_NO

//输出模式
#define             p_smg_com1_out      P13_CFG_OUTPUT_PULL_NO
#define             p_smg_com2_out      P12_CFG_OUTPUT_PULL_NO
#define             p_smg_com3_out      P11_CFG_OUTPUT_PULL_NO
#define             p_smg_com4_out      P10_CFG_OUTPUT_PULL_NO
#define             p_smg_com5_out      P20_CFG_OUTPUT_PULL_NO
#define             p_smg_ae_out        P17_CFG_OUTPUT_PULL_NO
#define             p_smg_bf_out        P16_CFG_OUTPUT_PULL_NO
#define             p_smg_cg_out        P15_CFG_OUTPUT_PULL_NO
#define             p_smg_dp_out        P14_CFG_OUTPUT_PULL_NO

//蜂鸣器
//输入模式
#define             p_buz_in            P04_CFG_INPUT_PULL_NO

//输出模式
#define             p_buz_out           P04_CFG_OUTPUT_PULL_NO

//继电器和可控硅
//输出模式
#define             p_scr               P27_CFG_OUTPUT_PULL_NO
#define             p_rly1              P30_CFG_OUTPUT_PULL_NO
#define             p_rly2              P31_CFG_OUTPUT_PULL_NO

//编码器
//输入模式
#define            p_sw_a               P07_CFG_INPUT_PULL_UP
#define            p_sw_b               P06_CFG_INPUT_PULL_UP
#define            p_sw_key             P05_CFG_INPUT_PULL_UP

//温度传感器
//输入模式
#define            p_temp_t1            P25_CFG_INPUT_PULL_NO
#define            p_temp_t2            P24_CFG_INPUT_PULL_NO
#define            p_temp_t3            P23_CFG_INPUT_PULL_NO

/**********************IO口引脚电平配置*********************** */
//数码管和LED灯
#define            p_smg_com1_H        P13 = 1
#define            p_smg_com1_L        P13 = 0
#define            p_smg_com2_H        P12 = 1
#define            p_smg_com2_L        P12 = 0
#define            p_smg_com3_H        P11 = 1
#define            p_smg_com3_L        P11 = 0
#define            p_smg_com4_H        P10 = 1
#define            p_smg_com4_L        P10 = 0
#define            p_smg_com5_H        P20 = 1
#define            p_smg_com5_L        P20 = 0
#define            p_smg_ae_H          P17 = 1
#define            p_smg_ae_L          P17 = 0
#define            p_smg_bf_H          P16 = 1
#define            p_smg_bf_L          P16 = 0
#define            p_smg_cg_H          P15 = 1
#define            p_smg_cg_L          P15 = 0
#define            p_smg_dp_H          P14 = 1
#define            p_smg_dp_L          P14 = 0

//蜂鸣器
#define            p_buz_H             P04 = 1
#define            p_buz_L             P04 = 0

//继电器、可控硅
#define            p_scr_H               P27 = 1
#define            p_scr_L               P27 = 0
#define            p_rly1_H              P30 = 1
#define            p_rly1_L              P30 = 0
#define            p_rly2_H              P31 = 1
#define            p_rly2_L              P31 = 0





#endif
