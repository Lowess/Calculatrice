#ifndef OPTION_H
#define OPTION_H

/** \file Option.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-t�te pour d�claration de la classe Option
  */

#include <QString>
#include <QTextStream>
#include <typeinfo>
#include <QFile>
#include "CalculatriceException.h"
#include "LogSystem.h"

/*Template method : singleton*/

/*! \enum TypeDiv
 * \brief D�finit les diff�rents types de constantes � cr�er par la Fabrique
 * et le type de retour des divisions
 */
enum TypeDiv {MENU_ENTIER, MENU_REEL, MENU_RATIONNEL};

/*! \namespace LO21
 *  \brief D�signe les classes d�finies dans le but du projet de LO21 P12
 */
namespace LO21{
    /*! \class Option
     * \brief Classe permettant de g�rer les options g�r�es par l'utilisateur, impl�mentant
     * le design pattern Singleton
     */
    class Option {
    private:        
        TypeDiv _typeDiv; /*! Le type des constantes s�lectionn� */
        bool _complexe, _degre; /*! Si les modes complexe et degr� sont actifs ou pas */
        static Option* _option; /*! L'instance de la classe Option */

        /*! \fn Option()
         * \brief Constructeur de la classe
         */
        Option():_complexe(false), _degre(false), _typeDiv(MENU_ENTIER){}

        /*! \fn void switchDegre(bool d)
         * \brief Permet de changer le mode des degr�s pour les op�rations trigonom�triques
         * \param d est true si le mode Degre est activ�, false sinon
         */
        void switchDegre(bool d){
            _degre = d;
        }

        /*! \fn void switchComplexe(bool c)
         * \brief Permet de changer le mode des complexes pour permettre leur cr�ation et leur stockage dans la pile
         * \param c est true si le mode complexe est activ�, false sinon
         */
        void switchComplexe(bool c){
            _complexe = c;
        }

    public:

        /*! \fn void switchComplexe(bool c)
         * \brief Permet de changer le mode des complexes pour permettre leur cr�ation et leur stockage dans la pile
         * \param c est true si le mode complexe est activ�, false sinon
         */
        static Option& getInstance();

        /*! \class Complexe
         * \brief Classe permettant de g�rer les nombres complexes
         */
        static void libereInstance();

        /*! \class Complexe
         * \brief Classe permettant de g�rer les nombres complexes
         */
        void set_typeDiv(TypeDiv s);
        void set_complexe(bool b){
            _complexe = b;
        }
        void set_degre(bool b){
            _degre= b;
        }

        /*! \class Complexe
         * \brief Classe permettant de g�rer les nombres complexes
         */
        TypeDiv get_typeDiv() const{ return _typeDiv; }
        bool get_degre() const{ return _degre; }
        bool get_complexe() const{ return _complexe; }


        /*! \class Complexe
         * \brief Classe permettant de g�rer les nombres complexes
         */
        QString toString() const;

    };
}

#endif // OPTION_H
