/*
 * power_savings.cpp
 *
 * Created: 9/24/2015 9:34:28 AM
 *  Author: HELLO
 */ 
#define F_CPU 125000UL

#include<util/delay.h>
#include <avr/power.h>
#include <avr/io.h>
#include "libs/Arduino.h"

void powerSaving();


int main(void)
{
	
	_delay_ms(1000);
	
	init();
	
	
	RCCTRL=1;
	
	_delay_ms(1000);
	
	
	clock_prescale_set(clock_div_8);
	_delay_ms(1000);
	
	powerSaving();
	
	DDRD|=(1<<5);
	
	Serial1.begin(1200);
	Serial1.println("Makey");
	
	while(1)
    {PORTD^=(1<<5);
	_delay_ms(1000);
	}

	
}



void powerSaving()
{
	//Save power but shutting down unused peripherals since we're running on coin cell
	
	PRR0|=(1<<PRTWI)|(1<<PRTIM1)|(1<<PRTIM2)|(1<<PRSPI)|(1<<PRADC); //shuts down TWI,Timer1,SPI & ADC
	PRR1|=(1<<PRTIM3)|(1<<4);               //shuts down Timer4, Timer3, USART1
}