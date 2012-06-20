#ifndef OPTION_H
#define OPTION_H

/*! \file Option.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-t�te pour d�claration de la classe Option
  */

#include <QString>
#include <QTextStream>
#include <typeinfo>
#include <QFile>

#include "MainWindow.h"
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
        bool _complexe; /*! D�termine si le mode complexe est activ� */
        bool _degre; /*! D�termine si le mode degr� est activ� */
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

        /*! \fn static Option& getInstance()
         * \brief R�cup�re l'instance cr��e de la classe Option, si celle-ci n'existe pas, la cr��
         * \return Option& une r�f�rence vers l'instance de la classe Option
         */
        static Option& getInstance();

        /*! \fn static void libereInstance()
         * \brief Demande la destruction de la classe Option
         */
        static void libereInstance();

        /*! \fn void set_typeDiv(TypeDiv s)
         * \brief Modifie le type de constante s�lectionn� par l'utilisateur
         * \param s le type de constante s�lectionn�
         */
        void set_typeDiv(TypeDiv s);
        void set_complexe(bool b){
            _complexe = b;
        }
        void set_degre(bool b){
            _degre= b;
        }

        /*! \fn TypeDiv get_typeDiv() const
         * \brief Retourne le type de constante s�lectionn�
         * \return TypeDiv le type de constante
         */
        TypeDiv get_typeDiv() const{ return _typeDiv; }
        bool get_degre() const{ return _degre; }
        bool get_complexe() const{ return _complexe; }

        /*! \fn void saveOptions()
         * \brief Sauvegarde dans un fichier les options s�lectionn�es � la fermeture de la calculatrice
         */
        void saveOptions();
    };
}

#endif // OPTION_H
