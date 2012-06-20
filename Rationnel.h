#ifndef RATIONNEL_H
#define RATIONNEL_H

/*! \file Rationnel.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe Rationnel
  */

#include <iostream>
#include "Nombre.h"
#include "Entier.h"

/*! \namespace LO21
 *  \brief Désigne les classes définies dans le but du projet de LO21 P12
 */
namespace LO21{

    /*! \class Rationnel
     * \brief Classe permettant de gérer les nombres rationnels
     */
    class Rationnel: public Nombre {
        private:
            LO21::Entier _n; /*! Le numérateur de la fraction */
            LO21::Entier _d; /*! Le dénominateur de la fraction */
        public:
            /*! \fn Constante& addition(const Constante& nb) const
             * \brief Gère l'addition entre un rationnel et une constante quelle qu'elle soit
             * \param nb une référence vers une constante
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            Constante& addition(const Constante& nb) const;

            /*! \fn Constante& soustraction(const Constante& nb) const
             * \brief Gère la soustraction entre un rationnel et une constante quelle qu'elle soit
             * \param nb une référence vers une constante
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            Constante& soustraction(const Constante& nb) const;

            /*! \fn Constante& multiplication(const Constante& nb) const
             * \brief Gère la multiplication entre un rationnel et une constante quelle qu'elle soit
             * \param nb une référence vers une constante
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            Constante& multiplication(const Constante& nb) const;

            /*! \fn Constante& divison(const Constante& nb) const
             * \brief Gère la division entre un rationnel et une constante quelle qu'elle soit
             * \param nb une référence vers une constante
             * \return Constante& une référence vers la constante créée à partir du résultat
             */
            Constante& division(const Constante& nb) const;

            /*! \fn QString toString() const
             * \brief Permet l'affichage textualisé d'un rationnel
             * \return QString contenant le texte du rationnel
             */
            QString toString() const;

            /*! \fn void simplifier()
             * \brief Simplifie la fonction
             */
            void simplifier();

            /*! \fn Reel& toReel() const
             * \brief Transforme un rationnel en réel
             * \return Reel& une référence vers le résultat de la transformation
             */
            Reel& toReel() const;

            /*! \fn Entier& toEntier() const
             * \brief Transforme un rationnel en entier
             * \return Entier& une référence vers le résultat de la transformation
             */
            Entier& toEntier() const;

            /*! \fn Complexe& toComplexe() const
             * \brief Transforme un rationnel en complexe
             * \return Complexe& une référence vers le résultat de la transformation
             */
            Complexe& toComplexe() const;

            /*! \fn const Entier& get_n() const
             * \brief Retourne le numérateur du rationnel
             * \return const Entier& Une référence constante vers le numérateur du rationnel
             */
            const Entier& get_n() const{ return _n; }

            /*! \fn const Entier& get_d() const
             * \brief Retourne le dénominateur du rationnel
             * \return const Entier& Une référence constante vers le dénominateur du rationnel
             */
            const Entier& get_d() const{ return _d; }

            /*! \fn Rationnel(const Entier& x, const Entier& y)
             * \brief Constructeur de la classe Rationnel
             * \param x une référence vers un objet Entier représentant le numérateur du rationnel
             * \param y une référence vers un objet Entier représentant le dénominateur du rationnel
             */
            Rationnel(const Entier& x, const Entier& y){
                _n=x;
                if(y.get_x()==0)
                    throw CalculatriceException(typeid(this).name(),MATHS,"Denominateur nul");
                _d=y;
            }

            /*! \fn Rationnel(unsigned int x=0, unsigned int y=1)
             * \brief Constructeur de la classe Rationnel
             * \param x un entier représentant le numérateur du rationnel
             * \param y un entier représentant le dénominateur du rationnel
             */
            Rationnel(unsigned int x=0, unsigned int y=1){
                _n=Entier(x);
                if(y==0)
                    throw CalculatriceException(typeid(this).name(),MATHS,"Denominateur nul");
                _d=Entier(y);
            }

            /*! \fn Rationnel* clone() const
             * \brief Créé une copie de l'objet appelant
             * \return Rationnel* un pointeur vers le rationnel issu de la recopie de l'objet
             */
            Rationnel* clone() const;

    };
    //Fonctions
    /*! \class Entier pgcd(const Entier& a, const Entier& b)
     * \brief Calcule le plus grand dénominateur commun entre deux entiers
     * \param a une référence vers un entier
     * \param b une référence vers un entier
     * \return Entier Un entier contenant le résultat calculé
     */
    Entier pgcd(const Entier& a, const Entier& b);

    /*! \fn Entier ppcm(const Entier& a, const Entier& b)
     * \brief Calcule le plus petit dénominateur commun entre deux entiers
     * \param a une référence vers un entier
     * \param b une référence vers un entier
     * \return Entier un entier contenant le résultat calculé
     */
    Entier ppcm(const Entier& a, const Entier& b);
}

#endif // RATIONNEL_H
