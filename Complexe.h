/** \file Complexe.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-t�te pour d�claration de la classe Complexe
  */

#ifndef COMPLEXE_H
#define COMPLEXE_H

#include <iostream>
#include "Constante.h"
#include "Nombre.h"
#include <typeinfo>
#include <QString>

/*! \namespace LO21
 *  \brief D�signe les classes d�finies dans le but du projet de LO21 P12
 */
namespace LO21{

    class Entier;
    class Reel;
    class Rationnel;
    class Constante;

    /*! \class Complexe
     * \brief Classe permettant de g�rer les nombres complexes
     */
    class Complexe:public Constante{
        private:
            const Nombre* _a; /*! Pointeur vers un nombre (Entier, Reel ou Rationnel) repr�sentant la partie r�elle du complexe */
            const Nombre* _b; /*! Pointeur vers un nombre (Entier, Reel ou Rationnel) repr�sentant la partie imaginaire du complexe */

        public:
            //Complexe(const Nombre* a,const Nombre* b);

            /*! \fn Constante& addition(const Constante& nb) const
             * \brief G�re l'addition entre un complexe et une constante quelle qu'elle soit
             * \param a une r�f�rence vers une constante (avec v�rification que celle-ci est un nombre et pas un complexe)
             * \param b une r�f�rence vers une constante (avec v�rification que celle-ci est un nombre et pas un complexe)
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
             * \brief Retourne la partie r�elle du complexe
             * \return const Nombre* un pointeur vers le nombre d�finissant la partie r�elle du nombre complexe
             */
            const Nombre* get_a() const{ return _a; }

            /*! \fn const Nombre* get_b() const
             * \brief Retourne la partie imaginaire du complexe
             * \return const Nombre* un pointeur vers le nombre d�finissant la partie imaginaire du nombre complexe
             */
            const Nombre* get_b() const{ return _b; }

            /*! \fn QString toString() const
             * \brief Permet l'affichage textuel d'un nombre complexe
             * \return QString contenant le texte repr�sentant le complexe
             */
            QString toString() const{
                return (QString(_a->toString() + "$" + _b->toString()));
            }

            /*! \fn Constante& module() const
             * \brief Calcule le module d'un complexe
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& module() const;

            /*! \fn Constante& addition(const Constante& nb) const
             * \brief G�re l'addition entre un complexe et une constante quelle qu'elle soit
             * \param nb une r�f�rence vers une constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& addition(const Constante& nb) const;

            /*! \fn Constante& soustraction(const Constante& nb) const
             * \brief G�re la soustraction entre un complexe et une constante quelle qu'elle soit
             * \param nb une r�f�rence vers une constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& soustraction(const Constante& nb) const;

            /*! \fn Constante& multiplication(const Constante& nb) const
             * \brief G�re la multiplication entre un complexe et une constante quelle qu'elle soit
             * \param nb une r�f�rence vers une constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& multiplication(const Constante& nb) const;

            /*! \fn Constante& division(const Constante& nb) const
             * \brief G�re la division entre un complexe et une constante quelle qu'elle soit
             * \param nb une r�f�rence vers une constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& division(const Constante& nb) const;

            /*! \fn Constante& SIGN() const
             * \brief Cr�� un complexe � partir de l'oppos� de l'objet appelant
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& SIGN() const;

            /*! \fn Constante& SQR() const
             * \brief Effectue le carr� d'un nombre complexe
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& SQR() const;

            /*! \fn Constante& CUBE() const
             * \brief Effectue le cube d'un nombre complexe
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& CUBE() const;

            /*! \fn Constante& hookOperation()
             * \brief
             * \return Constante&
             */
            Constante& hookOperation();

            /*! \fn Complexe* clone() const
             * \brief Cr�� un complexe � partir du complexe appelant
             * \return Constante* un pointeur vers le complexe cr�� par recopie
             */
            Complexe* clone() const;
    };
}

#endif // COMPLEXE_H
