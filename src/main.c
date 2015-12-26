/**
*****************************************************************************
**
**    Ahmed jaber Hamam
**
*****************************************************************************
*/

/* Includes */
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"


/* defines */
#define RCC_AHB1EN       (*((volatile unsigned long*)0x40023830))   //  enable registers
#define GPIOD_Mode       (*((volatile unsigned long*)0x40020c00))   //  make register(out_p or in_p or analog)
#define GPIOA_Mode       (*((volatile unsigned long*)0x40020000))   //  make register(out_p or in_p or analog)
#define GPIOD_OTYPER     (*((volatile unsigned long*)0x40020c04))   // type of register(push_pull or open drain)
#define GPIOA_OTYPER     (*((volatile unsigned long*)0x40020004))   // type of register(push_pull or open drain)
#define GPIOD_OSPEEDR    (*((volatile unsigned long*)0x40020c08))   // speed of register
#define GPIOA_OSPEEDR    (*((volatile unsigned long*)0x40020008))   // speed of register
#define GPIOD_PUPDR      (*((volatile unsigned long*)0x40020c0c))   // pull_up or pull_down
#define GPIOA_PUPDR      (*((volatile unsigned long*)0x4002000c))   // pull_up or pull_down
#define GPIOD_ODR      (*((volatile unsigned long*)0x40020c14))   //  set/reset register pins
#define GPIOA_IDRR       (*((volatile unsigned long*)0x40020010))   //  read in/p register


/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/


void delay( long  count)
	{
		while(count--)
		{

		}

	 }

int main(void)
{


    RCC_AHB1EN |= 0x00000009;    // enable register D and register A
   // delay(16000);
	GPIOD_Mode |= 0x01000000;    // pinD 12--> out
	GPIOA_Mode &= 0xfffffffc;    // pinA 0 --> in
	GPIOD_OTYPER &= 0xffffefff;  // pinD 12--> push_pull
	GPIOA_OTYPER |= 0x00000001;  // pinA 0--> open drain
	GPIOD_OSPEEDR |= 0x01000000; //speedD --> medium
	GPIOA_OSPEEDR |= 0x01000000; //speedA --> medium
	GPIOD_PUPDR &= 0xfcffffff;   // non pull_up /pull_down
	GPIOA_PUPDR |= 0x00000002;   //  pull_up


	 GPIOD_ODR &=0xffffefff;   ////reset pin 12



  /* Infinite loop */
  while (1)
  {
	if((GPIOA_IDRR & 0x00000001) == 0x00000001)
	{
		while((GPIOA_IDRR & 0x00000001) == 0x00000001)
		{}
		/* toggle pinD 12 */
		GPIOD_ODR ^= (1<<12);
		//delay(160000000000);

	}

  }
}


/*
 * Callback used by stm32f4_discovery_audio_codec.c.
 * Refer to stm32f4_discovery_audio_codec.h for more info.
 */
void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
