/**
 * @author DALLAGI Sami (p1807154) GHODHBANI Chouaïb(p1914024) JEBNOUNI Mohamed (p1712808)
 * @version 0.1
 * @file Pixel.h
 */
#ifndef PIXEL_H
#define PIXEL_H

/**
 * @brief Classe Pixel, représente un pixel et contient 3 'couleurs' r,g,b
 *
 */
class Pixel{

 private :

   unsigned char r,g,b;  // les composantes du pixel, unsigned char en C++

 public :

    /**
     * @brief Constructeur de la classe: initialise le pixel à la couleur noire
     *
     */
    Pixel();

    /**
     * @brief Constructeur de la classe: initialise r,g,b avec les paramètres nr,ng,nb
     *
     * @param nr quantité de rouge
     * @param ng quantité de vert
     * @param nb quantité de bleu
     */
    Pixel(unsigned char nr, unsigned char ng, unsigned char nb);


   /**
    * @brief Accesseur : récupère la composante rouge du pixel
    *
    * @return int
    */
   unsigned char getRouge () const;

   /**
    * @brief Accesseur : récupère la composante verte du pixel
    *
    * @return int
    */
   unsigned char getVert () const;

   /**
    * @brief Accesseur : récupère la composante bleue du pixel
    *
    * @return int
    */
   unsigned char getBleu () const;

   /**
    * @brief Mutateur : modifie la composante rouge du pixel
    *
    * @param nr quantité de rouge
    */
   void setRouge (unsigned char nr);

   /**
    * @brief Mutateur : modifie la composante verte du pixel
    *
    * @param nv quantité de vert
    */
   void setVert (unsigned char nv);

   /**
    * @brief Mutateur : modifie la composante bleue du pixel
    *
    * @param nb quantité de bleu
    */
   void setBleu (unsigned char nb);

};

#endif // PIXEL_H
