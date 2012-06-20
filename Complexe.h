/** \file Complexe.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe Complexe
  */

#ifndef COMPLEXE_H
#define COMPLEXE_H

#include <iostream>
#include "Constante.h"
#include "Nombre.h"
#include <typeinfo>
#include <QString>

/*! \namespace LO21
 *  \brief Désigne les classes définies dans le but du projet de LO21 P12
 */
namespace LO21{

    class Entier;
    class Reel;
    class Rationnel;
    class Constante;

    /*! \class Complexe
     * \brief Classe permettant de gérer les nombres complexes
     */
    class Complexe:public Constante{
        private:
            const Nombre* _a; /*! Pointeur vers un nombre (Entier, Reel ou Rationnel) représentant la partie réelle du complexe */
            const Nombre* _b; /*! Pointeur vers un nombre (Entier, Reel ou Rationnel) représentant la partie imaginaire du complexe */

        public:
            //Complexe(const Nombre* a,const Nombre* b);

            /*! \fn Constante& addition(const Constante& nb) const
             * \brief Gère l'addition entre un complexe et une constante quelle qu'elle soit
             * \param a une référence vers une constante (avec vérification que celle-ci est un nombre et pas un complexe)
             * \param b une référence vers une constante (avec vérification que celle-ci est un nombre et pas un complexe)
             */
            Complexe(const Constante& a, const Constante& b);

            /*! \fn ~Complexe() const
             * \brief Destructeur de la classe Complexe
             */
            ~Complexe() {
                delete _a;
                delete _b;
            }

            /*! \fn const Nombre* get_a() const
             * \brief Retourne la partie réelle du complexe
             * \return const Nombre* un pointeur vers le nombre définissant la partie réelle du nombre complexe
             */
            const Nombre* get_a() const{ return _a; }

            /*! \fn const Nombre* get_b() const
             * \brief Retourne la partie imaginaire du complexe
             * \return const Nombre* un pointeur vers le nombre définissant la partie imaginaire du nombre complexe
             */
            const Nombre* get_b() const{ return _b; }

            /*! \fn QString toString() const
             * \brief Permet l'affichage textuel d'un nombre complexe
             * \return QString contenant le texte représentant le complexe
             */
            QString toString() const{
                return (QString(_a->toString() + "$" + _b->toString()));
            }

            /*! \fn Constante& module() const
             * \brief Calcule le module d'un complexe
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            Constante& module() const;

            /*! \fn Constante& addition(const Constante& nb) const
             * \brief Gère l'addition entre un complexe et une constante quelle qu'elle soit
             * \param nb une référence vers une constante
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            Constante& addition(const Constante& nb) const;

            /*! \fn Constante& soustraction(const Constante& nb) const
             * \brief Gère la soustraction entre un complexe et une constante quelle qu'elle soit
             * \param nb une référence vers une constante
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            Constante& soustraction(const Constante& nb) const;

            /*! \fn Constante& multiplication(const Constante& nb) const
             * \brief Gère la multiplication entre un complexe et une constante quelle qu'elle soit
             * \param nb une référence vers une constante
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            Constante& multiplication(const Constante& nb) const;

            /*! \fn Constante& division(const Constante& nb) const
             * \brief Gère la division entre un complexe et une constante quelle qu'elle soit
             * \param nb une référence vers une constante
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            Constante& division(const Constante& nb) const;

            /*! \fn Constante& SIGN() const
             * \brief Créé un complexe à partir de l'opposé de l'objet appelant
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            Constante& SIGN() const;

            /*! \fn Constante& SQR() const
             * \brief Effectue le carré d'un nombre complexe
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            Constante& SQR() const;

            /*! \fn Constante& CUBE() const
             * \brief Effectue le cube d'un nombre complexe
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            Constante& CUBE() const;

            /*! \fn Constante& hookOperation()
             * \brief
             * \return Constante&
             */
            Constante& hookOperation();

            /*! \fn Complexe* clone() const
             * \brief Créé un complexe à partir du complexe appelant
             * \return Constante* un pointeur vers le complexe créé par recopie
             */
            Complexe* clone() const;
    };
}

#endif // COMPLEXE_H
