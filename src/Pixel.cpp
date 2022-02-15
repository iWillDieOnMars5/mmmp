/**
 * @author DALLAGI Sami (p1807154) GHODHBANI Chouaïb(p1914024) JEBNOUNI Mohamed (p1712808)
 * @version 0.1
 */
#include "Pixel.h"

// Constructeur par défaut de la classe: initialise le pixel à la couleur noire
Pixel::Pixel(){

    r = 0;
    g = 0;
    b = 0;

}

Pixel::Pixel(unsigned char nr, unsigned char ng, unsigned char nb){

	r = nr;

	g = ng;

	b = nb;

}

unsigned char Pixel::getRouge() const {

    return r;

}

unsigned char Pixel::getVert() const {

    return g;

}

unsigned char Pixel::getBleu() const {

    return b;

}

void Pixel::setRouge(unsigned char nr){

    r = nr;

}

void Pixel::setVert(unsigned char ng){

    g = ng;

}

void Pixel::setBleu(unsigned char nb){

    b = nb;

}
