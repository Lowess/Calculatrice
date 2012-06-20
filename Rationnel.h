#ifndef RATIONNEL_H
#define RATIONNEL_H

/*! \file Rationnel.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-t�te pour d�claration de la classe Rationnel
  */

#include <iostream>
#include "Nombre.h"
#include "Entier.h"

/*! \namespace LO21
 *  \brief D�signe les classes d�finies dans le but du projet de LO21 P12
 */
namespace LO21{

    /*! \class Rationnel
     * \brief Classe permettant de g�rer les nombres rationnels
     */
    class Rationnel: public Nombre {
        private:
            LO21::Entier _n; /*! Le num�rateur de la fraction */
            LO21::Entier _d; /*! Le d�nominateur de la fraction */
        public:
            /*! \fn Constante& addition(const Constante& nb) const
             * \brief G�re l'addition entre un rationnel et une constante quelle qu'elle soit
             * \param nb une r�f�rence vers une constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& addition(const Constante& nb) const;

            /*! \fn Constante& soustraction(const Constante& nb) const
             * \brief G�re la soustraction entre un rationnel et une constante quelle qu'elle soit
             * \param nb une r�f�rence vers une constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& soustraction(const Constante& nb) const;

            /*! \fn Constante& multiplication(const Constante& nb) const
             * \brief G�re la multiplication entre un rationnel et une constante quelle qu'elle soit
             * \param nb une r�f�rence vers une constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& multiplication(const Constante& nb) const;

            /*! \fn Constante& divison(const Constante& nb) const
             * \brief G�re la division entre un rationnel et une constante quelle qu'elle soit
             * \param nb une r�f�rence vers une constante
             * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
             */
            Constante& division(const Constante& nb) const;

            /*! \fn QString toString() const
             * \brief Permet l'affichage textualis� d'un rationnel
             * \return QString contenant le texte du rationnel
             */
            QString toString() const;

            /*! \fn void simplifier()
             * \brief Simplifie la fonction
             */
            void simplifier();

            /*! \fn Reel& toReel() const
             * \brief Transforme un rationnel en r�el
             * \return Reel& une r�f�rence vers le r�sultat de la transformation
             */
            Reel& toReel() const;

            /*! \fn Entier& toEntier() const
             * \brief Transforme un rationnel en entier
             * \return Entier& une r�f�rence vers le r�sultat de la transformation
             */
            Entier& toEntier() const;

            /*! \fn Complexe& toComplexe() const
             * \brief Transforme un rationnel en complexe
             * \return Complexe& une r�f�rence vers le r�sultat de la transformation
             */
            Complexe& toComplexe() const;

            /*! \fn const Entier& get_n() const
             * \brief Retourne le num�rateur du rationnel
             * \return const Entier& Une r�f�rence constante vers le num�rateur du rationnel
             */
            const Entier& get_n() const{ return _n; }

            /*! \fn const Entier& get_d() const
             * \brief Retourne le d�nominateur du rationnel
             * \return const Entier& Une r�f�rence constante vers le d�nominateur du rationnel
             */
            const Entier& get_d() const{ return _d; }

            /*! \fn Rationnel(const Entier& x, const Entier& y)
             * \brief Constructeur de la classe Rationnel
             * \param x une r�f�rence vers un objet Entier repr�sentant le num�rateur du rationnel
             * \param y une r�f�rence vers un objet Entier repr�sentant le d�nominateur du rationnel
             */
            Rationnel(const Entier& x, const Entier& y){
                _n=x;
                if(y.get_x()==0)
                    throw CalculatriceException(typeid(this).name(),MATHS,"Denominateur nul");
                _d=y;
            }

            /*! \fn Rationnel(unsigned int x=0, unsigned int y=1)
             * \brief Constructeur de la classe Rationnel
             * \param x un entier repr�sentant le num�rateur du rationnel
             * \param y un entier repr�sentant le d�nominateur du rationnel
             */
            Rationnel(unsigned int x=0, unsigned int y=1){
                _n=Entier(x);
                if(y==0)
                    throw CalculatriceException(typeid(this).name(),MATHS,"Denominateur nul");
                _d=Entier(y);
            }

            /*! \fn Rationnel* clone() const
             * \brief Cr�� une copie de l'objet appelant
             * \return Rationnel* un pointeur vers le rationnel issu de la recopie de l'objet
             */
            Rationnel* clone() const;

    };
    //Fonctions
    /*! \class Entier pgcd(const Entier& a, const Entier& b)
     * \brief Calcule le plus grand d�nominateur commun entre deux entiers
     * \param a une r�f�rence vers un entier
     * \param b une r�f�rence vers un entier
     * \return Entier Un entier contenant le r�sultat calcul�
     */
    Entier pgcd(const Entier& a, const Entier& b);

    /*! \fn Entier ppcm(const Entier& a, const Entier& b)
     * \brief Calcule le plus petit d�nominateur commun entre deux entiers
     * \param a une r�f�rence vers un entier
     * \param b une r�f�rence vers un entier
     * \return Entier un entier contenant le r�sultat calcul�
     */
    Entier ppcm(const Entier& a, const Entier& b);
}

#endif // RATIONNEL_H
