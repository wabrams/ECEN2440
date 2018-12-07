#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))
#define NVIC_ST_CTRL_CLK_SRC    0x00000004
#define NVIC_ST_CTRL_ENABLE     0x00000001
#define NVIC_ST_RELOAD_M        0x00FFFFFF

void systick_initialize(void)
{
  NVIC_ST_CTRL_R = 0;
  NVIC_ST_RELOAD_R = NVIC_ST_RELOAD_M;
  NVIC_ST_CURRENT_R = 0;
  NVIC_ST_CTRL_R = NVIC_ST_CTRL_ENABLE+NVIC_ST_CTRL_CLK_SRC;
}
void systick_wait(unsigned long delay)
{
  volatile unsigned long elapsedTime;
  unsigned long startTime = NVIC_ST_CURRENT_R;
  do
  {
    elapsedTime = (startTime-NVIC_ST_CURRENT_R)&0x00FFFFFF;
  }
  while(elapsedTime <= delay);
}
