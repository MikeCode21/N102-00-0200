#ifndef LVD_H
#define LVD_H

#define LVDE(N)		(N<<7)
#define LVDS_reset		(1<<6)
#define LVDS_int		(0<<6)
#define LVDF		(1<<5) //LVD产生标志，该标志可以写1清除

#define LVSEL(N)		(N<<7)

#define LVDTH_2_2V		0
#define LVDTH_2_5V		1
#define LVDTH_2_7V		2
#define LVDTH_3_0V		3
#define LVDTH_3_3V		4
#define LVDTH_3_6V		5
#define LVDTH_3_9V		6
#define LVDTH_4_2V		7

void LVD_init(void);
void LVD_ISR_proc(void);
void LVD_proc(void);
#endif