/**
 * @author DALLAGI Sami (p1807154) GHODHBANI Chouaïb(p1914024) JEBNOUNI Mohamed (p1712808)
 * @version 0.1
 * @file Image.h
 */
#ifndef IMAGE_H
#define IMAGE_H

#include "Pixel.h"
#include <string>

/**
 * @brief Classe Image, représente une image sous la forme d'un tableau de pixels
 *        de dimensions dimx, dimy
 *
 */
class Image
{
public:
    /**
     * @brief Constructeur par défaut de la classe: initialise dimx et dimy à 0
              ce constructeur n'alloue pas de pixel
     *
     */
    Image();
    /**
     * @brief Constructeur de la classe: initialise dimx et dimy (après vérification)
              puis alloue le tableau de pixel dans le tas (image noire)
     *
     * @param dimensionX taille horizontale de l'image
     * @param dimensionY taille verticale de l'image
     */
    Image(int dimensionX, int dimensionY);
    /**
     * @brief Destructeur de la classe: déallocation de la mémoire du tableau de pixels
              et mise à jour des champs dimx et dimy à 0
     * @param dimensionX défini la taille horizontale de l'Image
     * @param dimensionY défini la taille verticale de l'Image
     *
     * */
    ~Image();

    /**
     * @brief Accesseur : récupère le pixel original de coordonnées (x,y) en vérifiant leur validité
              la formule pour passer d'un tab 2D à un tab 1D est tab[y*dimx+x]
     *
     * @param x position en x du Pixel que l'on souhaite récupérer
     * @param y position en y du Pixel que l'on souhaite placer
     * @return Pixel renvoie un Pixel
     */
    Pixel& getPix(int x, int y) const;

    /**
     * @brief Mutateur : modifie le pixel de coordonnées (x,y)
     *
     * @param x position en x du Pixel que l'on souhaite placer
     * @param y position en y du Pixel que l'on souhaite placer
     * @param couleur Pixel de couleur couleur
     */
    void setPix(int x, int y, const Pixel& couleur);

    /**
     * @brief Dessine un rectangle plein de la couleur dans l'image (en utilisant setPix, indices en paramètre compris)
     *
     * @param Xmin Position en x du minimum
     * @param Ymin Position y du minimum
     * @param Xmax Position x du maximum
     * @param Ymax Position y du maximum
     * @param couleur Pixel de couleur couleur
     */

    void dessinerRectangle(int Xmin, int Ymin, int Xmax, int Ymax, const Pixel& couleur);

    /**
     * @brief Efface l'image en la remplissant de la couleur en paramètre
     *
     * @param couleur Pixel de couleur couleur
     */
    void effacer(const Pixel& couleur);
    /**
     * @brief Effectue une série de tests vérifiant que le module fonctionne et
              que les données membres de l'objet sont conformes
     *
     */
    void testRegression();

    /**
     * @brief Sauve l'image créée dans le fichier filename
     *
     * @param filename chaîne de caractères qui décrit le nom du fichier et son emplacement
     */
    void sauver(const std::string & filename) const;
    /**
     * @brief Ouvre une image depuis le fichier issu du chemin filename
     *
     * @param filename chaîne de caractères qui décrit le nom du fichier et son emplacement
     */
    void ouvrir(const std::string & filename);
    /**
     * @brief Affiche les valeurs des pixels dans la console
     *
     */
    void afficherConsole();
    /**
     * @brief Affiche l'image dans une fenêtre SDL2
     */
    void afficher();

private:
    Pixel* tab;
    int dimx, dimy;
};

#endif // IMAGE_H
