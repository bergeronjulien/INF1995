/*
 * Nom: Machine a etat
 * Copyright (C) 2005 Matthew Khouzam
 * License http://www.gnu.org/copyleft/gpl.html GNU/GPL
 * Description: Ceci est un exemple de machine a etat simple
 * Version: 1.1
 * 
 * Fichier: tp3_1.cpp
 * Par: Julien Bergeron (1829496) et Loic Bellemare-Alford (1846135)
 * Fait le: 27 janvier 2017
 * Derni're modification: 27 janvier 2017
 */


#include <avr/io.h> 
#define F_CPU 8000000
#include <util/delay.h>

 void delay_ms(unsigned int milliseconds)
 {
   while(milliseconds > 0)
   {
      _delay_ms(1);
      milliseconds--;
    }
 }

int main()
{
  	DDRA = 0xff; // PORT A est en mode sortie
  	DDRB = 0xff; // PORT B est en mode sortie
  	DDRC = 0xff; // PORT C est en mode sortie
  	DDRD = 0x00; // PORT D est en mode entree

  	PORTB = 0x00;
	int i = 0;
	double a = 0;
	bool ouvert = false;

	const double f60HZ = 1000 / 60;
	//const double 400HZ = 1 / 400; 

	//enum intensite {
	//	R0,
	//	R25,
	//	R50,
	//	R75,
	//	R100
	//};

	//enum INTENSITE = intensite;


	while(i < 600000){
		if(i % 120000) {
			a += f60HZ;
		}

		if(ouvert) {
			PORTB = 0x01;
			delay_ms(a);
		} else {
			PORTB = 0x00;
			delay_ms(f60HZ - a);
		}
		ouvert = !ouvert;

		i++;
	}




  return 0; 
}
