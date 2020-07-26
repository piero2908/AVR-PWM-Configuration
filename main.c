/*
 * PWM_main.c
 *
 * Created: 06/10/2018 09:56:46 a.m.
 * Author : Laptop
 */ 
//PWM USANDO EL TMR0
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

void pin_config(){
	DDRD |= (1<<PORTD6);
}

void tmr0_config(){
	TCCR0B |= (1<<CS00);
	TCCR0A |= (0<<COM0A0)|(1<<COM0A1)|(1<<WGM00)|(1<<WGM01)|(1<<WGM02);
	
}

int main(void)
{
	uint8_t brillo;
    pin_config();
	tmr0_config();
    while (1) 
    {
		for(brillo = 0; brillo < 255; ++brillo){
			_delay_ms(50);
			OCR0A = brillo;
		}
		for(brillo = 255; brillo > 0; --brillo){
			_delay_ms(50);
			OCR0A = brillo;
		}
    }
}

