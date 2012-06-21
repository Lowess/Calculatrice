#ifndef COMPLEXE_H
#define COMPLEXE_H

/*! \file Complexe.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tete pour declaration de la classe Complexe
  */

#include <iostream>
#include "Constante.h"
#include "Nombre.h"
#include <typeinfo>
#include <QString>

/*! \namespace LO21
 *  \brief Designe les classes definies dans le but du projet de LO21 P12
 */
namespace LO21{

    class Entier;
    class Reel;
    class Rationnel;
    class Constante;

    /*! \class Complexe
     * \brief Classe permettant de gerer les nombres complexes
     */
    class Complexe:public Constante{
        private:
            const Nombre* _a; /*! Pointeur vers un nombre (Entier, Reel ou Rationnel) representant la partie reelle du complexe */
            const Nombre* _b; /*! Pointeur vers un nombre (Entier, Reel ou Rationnel) representant la partie imaginaire du complexe */

        public:
            /*! \fn Constante& addition(const Constante& nb) const
             * \brief Gere l'addition entre un complexe et une constante quelle qu'elle soit
             * \param a une reference vers une constante (avec verification que celle-ci est un nombre et pas un complexe)
             * \param b une reference vers une constante (avec verification que celle-ci est un nombre et pas un complexe)
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
             * \brief Retourne la partie reelle du complexe
             * \return const Nombre* un pointeur vers le nombre definissant la partie reelle du nombre complexe
             */
            const Nombre* get_a() const{ return _a; }

            /*! \fn const Nombre* get_b() const
             * \brief Retourne la partie imaginaire du complexe
             * \return const Nombre* un pointeur vers le nombre definissant la partie imaginaire du nombre complexe
             */
            const Nombre* get_b() const{ return _b; }

            /*! \fn QString toString() const
             * \brief Permet l'affichage textuel d'un nombre complexe
             * \return QString contenant le texte representant le complexe
             */
            QString toString() const{
                return (QString(_a->toString() + "$" + _b->toString()));
            }

            /*! \fn Constante& module() const
             * \brief Calcule le module d'un complexe
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            Constante& module() const;

            /*! \fn Constante& addition(const Constante& nb) const
             * \brief Gere l'addition entre un complexe et une constante quelle qu'elle soit
             * \param nb une reference vers une constante
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            Constante& addition(const Constante& nb) const;

            /*! \fn Constante& soustraction(const Constante& nb) const
             * \brief Gere la soustraction entre un complexe et une constante quelle qu'elle soit
             * \param nb une reference vers une constante
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            Constante& soustraction(const Constante& nb) const;

            /*! \fn Constante& multiplication(const Constante& nb) const
             * \brief Gere la multiplication entre un complexe et une constante quelle qu'elle soit
             * \param nb une reference vers une constante
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            Constante& multiplication(const Constante& nb) const;

            /*! \fn Constante& division(const Constante& nb) const
             * \brief Gere la division entre un complexe et une constante quelle qu'elle soit
             * \param nb une reference vers une constante
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            Constante& division(const Constante& nb) const;

            /*! \fn Constante& SIGN() const
             * \brief Cree un complexe a partir de l'oppose de l'objet appelant
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            Constante& SIGN() const;

            /*! \fn Constante& SQR() const
             * \brief Effectue le carre d'un nombre complexe
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            Constante& SQR() const;

            /*! \fn Constante& CUBE() const
             * \brief Effectue le cube d'un nombre complexe
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            Constante& CUBE() const;

            /*! \fn Constante& hookOperation()
             * \brief Permet de vérifier le type d'opération et de constante pour instancier correctement un objet
             * \return Constante& Une reference vers une constante instanciee
             */
            Constante& hookOperation();

            /*! \fn Complexe* clone() const
             * \brief Cree un complexe a partir du complexe appelant
             * \return Constante* un pointeur vers le complexe cree par recopie
             */
            Complexe* clone() const;
    };
}

#endif // COMPLEXE_H
