#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))
#define NVIC_ST_CTRL_CLK_SRC    0x00000004
#define NVIC_ST_CTRL_ENABLE     0x00000001
#define NVIC_ST_RELOAD_M        0x00FFFFFF

void systick_initialize();
void systick_wait();
