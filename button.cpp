#define F_CPU 1000000L
#include <avr/io.h>
#include "delay.h"
#include "wiringt84.h"



int main()
{ 
    int led = B1;
    int button = A7;
    pinMode(led, OUTPUT);
    pinMode(button, INPUT_PULLUP);
  	
    for (;;) 
    {
		if( (digitalRead(button)) == false){
			digitalWrite(led, HIGH) ; // turn on LED
		}else{
			digitalWrite(led, LOW); // turn off LED
		}
	}
	return 0 ;
}
