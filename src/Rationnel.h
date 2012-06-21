#ifndef RATIONNEL_H
#define RATIONNEL_H

/*! \file Rationnel.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tete pour declaration de la classe Rationnel
  */

#include <iostream>
#include "Nombre.h"
#include "Entier.h"

/*! \namespace LO21
 *  \brief Designe les classes definies dans le but du projet de LO21 P12
 */
namespace LO21{

    /*! \class Rationnel
     * \brief Classe permettant de gerer les nombres rationnels
     */
    class Rationnel: public Nombre {
        private:
            Entier _n; /*! Le numerateur de la fraction */
            Entier _d; /*! Le denominateur de la fraction */
        public:
            /*! \fn Constante& addition(const Constante& nb) const
             * \brief Gere l'addition entre un rationnel et une constante quelle qu'elle soit
             * \param nb une reference vers une constante
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            Constante& addition(const Constante& nb) const;

            /*! \fn Constante& soustraction(const Constante& nb) const
             * \brief Gere la soustraction entre un rationnel et une constante quelle qu'elle soit
             * \param nb une reference vers une constante
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            Constante& soustraction(const Constante& nb) const;

            /*! \fn Constante& multiplication(const Constante& nb) const
             * \brief Gere la multiplication entre un rationnel et une constante quelle qu'elle soit
             * \param nb une reference vers une constante
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            Constante& multiplication(const Constante& nb) const;

            /*! \fn Constante& divison(const Constante& nb) const
             * \brief Gere la division entre un rationnel et une constante quelle qu'elle soit
             * \param nb une reference vers une constante
             * \return Constante& une reference vers la constante creee a partir du resultat
             */
            Constante& division(const Constante& nb) const;

            /*! \fn QString toString() const
             * \brief Permet l'affichage textualise d'un rationnel
             * \return QString contenant le texte du rationnel
             */
            QString toString() const;

            /*! \fn void simplifier()
             * \brief Simplifie la fonction
             */
            void simplifier();

            /*! \fn Reel& toReel() const
             * \brief Transforme un rationnel en reel
             * \return Reel& une reference vers le resultat de la transformation
             */
            Reel& toReel() const;

            /*! \fn Entier& toEntier() const
             * \brief Transforme un rationnel en entier
             * \return Entier& une reference vers le resultat de la transformation
             */
            Entier& toEntier() const;

            /*! \fn Complexe& toComplexe() const
             * \brief Transforme un rationnel en complexe
             * \return Complexe& une reference vers le resultat de la transformation
             */
            Complexe& toComplexe() const;

            /*! \fn const Entier& get_n() const
             * \brief Retourne le numerateur du rationnel
             * \return const Entier& Une reference constante vers le numerateur du rationnel
             */
            const Entier& get_n() const{ return _n; }

            /*! \fn const Entier& get_d() const
             * \brief Retourne le denominateur du rationnel
             * \return const Entier& Une reference constante vers le denominateur du rationnel
             */
            const Entier& get_d() const{ return _d; }

            /*! \fn Rationnel(const Entier& x, const Entier& y)
             * \brief Constructeur de la classe Rationnel
             * \param x une reference vers un objet Entier representant le numerateur du rationnel
             * \param y une reference vers un objet Entier representant le denominateur du rationnel
             */
            Rationnel(const Entier& x, const Entier& y){
                _n=x;
                if(y.get_x()==0)
                    throw CalculatriceException(typeid(this).name(),MATHS,"Denominateur nul");
                _d=y;
            }

            /*! \fn Rationnel(unsigned int x=0, unsigned int y=1)
             * \brief Constructeur de la classe Rationnel
             * \param x un entier representant le numerateur du rationnel
             * \param y un entier representant le denominateur du rationnel
             */
            Rationnel(unsigned int x=0, unsigned int y=1){
                _n=Entier(x);
                if(y==0)
                    throw CalculatriceException(typeid(this).name(),MATHS,"Denominateur nul");
                _d=Entier(y);
            }

            /*! \fn Rationnel* clone() const
             * \brief Cree une copie de l'objet appelant
             * \return Rationnel* un pointeur vers le rationnel issu de la recopie de l'objet
             */
            Rationnel* clone() const;

    };
    //Fonctions
    /*! \class Entier pgcd(const Entier& a, const Entier& b)
     * \brief Calcule le plus grand denominateur commun entre deux entiers
     * \param a une reference vers un entier
     * \param b une reference vers un entier
     * \return Entier Un entier contenant le resultat calcule
     */
    Entier pgcd(const Entier& a, const Entier& b);

    /*! \fn Entier ppcm(const Entier& a, const Entier& b)
     * \brief Calcule le plus petit denominateur commun entre deux entiers
     * \param a une reference vers un entier
     * \param b une reference vers un entier
     * \return Entier un entier contenant le resultat calcule
     */
    Entier ppcm(const Entier& a, const Entier& b);
}

#endif // RATIONNEL_H
