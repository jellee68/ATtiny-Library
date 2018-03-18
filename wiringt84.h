#define HIGH 1
#define LOW  0
#define INPUT 0
#define OUTPUT 1
#define INPUT_PULLUP 2

#define A0	13
#define A1 	12
#define	A2 	11
#define A3	10
#define A4	9
#define A5	8
#define	A6	7
#define A7	6
#define B0 	2
#define B1  3
#define B2  5
#define B3  4


void pinMode ( int pin , int direction)
{
	bool pullUp ;
	if (
	direction == 3)
	{
		pullUp = true;
		direction = 0;
	}
	switch (pin)
	{
		case A0:
			DDRA = ( direction<<DDA0); // PORTA PA0 direction
			if ( pullUp == true)
			{
				PORTA |=(1<<PA0); // Enable pull up resistor
			}
			break ;
		case A1:
			DDRA = ( direction<<DDA1); // PORTA PA1 direction
			if ( pullUp == true)
			{
				PORTA |=(1<<PA1); // Enable pull up resistor
			}
			break ;
		case A2:
			DDRA = ( direction<<DDA2); // PORTA PA2 direction
			if ( pullUp == true)
			{
				PORTA |=(1<<PA2); // Enable pull up resistor
			}
			break ;
		case A3:
			DDRA = ( direction<<DDA3); // PORTA PA3 direction
			if ( pullUp == true)
			{
				PORTA |=(1<<PA3); // Enable pull up resistor
			}
			break ;
		case A4:
			DDRA = ( direction<<DDA4); // PORTA PA4 direction
			if ( pullUp == true)
			{
				PORTA |=(1<<PA4); // Enable pull up resistor
			}
			break ;
		case A5:
			DDRA = ( direction<<DDA5); // PORTA PA5 direction
			if ( pullUp == true)
			{
				PORTA |=(1<<PA5); // Enable pull up resistor
			}			
			break ;
		case A6:
			DDRA = ( direction<<DDA6); // PORTA PA6 direction
			if ( pullUp == true)
			{
				PORTA |=(1<<PA6); // Enable pull up resistor
			}
			break ;	
		case A7:
			DDRA = ( direction<<DDA7); // PORTA PA7 direction
			if ( pullUp == true)
			{
				PORTA |=(1<<PA7); // Enable pull up resistor
			}
			break ;
		case B0:
			DDRB = ( direction<<DDB0); // PORTA PB0 direction
			if ( pullUp == true)
			{
				PORTB |=(1<<PB0); // Enable pull up resistor
			}
			break ;
		case B1:
			DDRB = ( direction<<DDB1); // PORTA PB1 direction
			if ( pullUp == true)
			{
				PORTB |=(1<<PB1); // Enable pull up resistor
			}
			break ;
		case B2:
			DDRB = ( direction<<DDB2); // PORTA PB2 direction
			if ( pullUp == true)
			{
				PORTB |=(1<<PB2); // Enable pull up resistor
			}
			break ;
		case B3:
			DDRB = ( direction<<DDB3); // PORTA PB3 direction
			if ( pullUp == true)
			{
				PORTB |=(1<<PB3); // Enable pull up resistor
			}
			break ;
			
		default:
			break;
	}
}


void digitalWrite(int pin, int condition)
{
	switch (pin)
	{
		case A0:
			PORTA = (condition<<PORTA0);
			break;
		case A1:
			PORTA = (condition<<PORTA1);
			break;
		case A2:
			PORTA = (condition<<PORTA2);
			break;	
		case A3:
			PORTA = (condition<<PORTA3);
			break;
		case A4:
			PORTA = (condition<<PORTA4);
			break;
		case A5:
			PORTA = (condition<<PORTA5);
			break;
		case A6:
			PORTA = (condition<<PORTA6);
			break;
		case A7:
			PORTA = (condition<<PORTA7);
			break;
			
		case B0:
			PORTB = (condition<<PORTB0);
			break;	
		case B1:
			PORTB = (condition<<PORTB1);
			break;
		case B2:
			PORTB = (condition<<PORTB2);
			break;	
		case B3:
			PORTB = (condition<<PORTB3);
			break;	
				
		default:
			break;
	}
}
	
bool digitalRead(int pin)
{
	bool state = true;
	
	switch (pin)
	{
		case A0:
			state = (PINA & (1<<PINA0));
			break;
		case A1:
			state = (PINA & (1<<PINA1));
			break;
		case A2:
			state = (PINA & (1<<PINA2));
			break;
		case A3:
			state = (PINA & (1<<PINA3));
			break;
		case A4:
			state = (PINA & (1<<PINA4));
			break;
		case A5:
			state = (PINA & (1<<PINA5));
			break;
		case A6:
			state = (PINA & (1<<PINA6));
			break;
		case A7:
			state = (PINA & (1<<PINA7));
			break;
		
			
			
		case B0:
			state = (PINB & (1<<PINB0));
			break;
		case B1:
			state = (PINB & (1<<PINB1));
			break;
		case B2:
			state = (PINB & (1<<PINB2));
			break;
		case B3:
			state = (PINB & (1<<PINB3));
			break;
	}
			
	return state;
}

/*Notes
* 					______
* 				VCC|1	14|GND
* 				PB0|2	13|PA0
* 	 	 _____	PB1|3	12|PA1
* 		(RESET)	PB3|4	11|PA2
* 				PB2|5	10|PA3
* 				PA7|6	 9|PA4	(SCL)
* 		(MOSI)	PA6|7	 8|PA5  (MISO)
* 				   --------
*  
*/


