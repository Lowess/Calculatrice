#ifndef OPTION_H
#define OPTION_H

/*! \file Option.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tete pour declaration de la classe Option
  */

#include <QString>
#include <QTextStream>
#include <typeinfo>
#include <QFile>

#include "CalculatriceException.h"
#include "LogSystem.h"

/*Template method : singleton*/

/*! \enum TypeDiv
 * \brief Definit les differents types de constantes a creer par la Fabrique
 * et le type de retour des divisions
 */
enum TypeDiv {MENU_ENTIER, MENU_REEL, MENU_RATIONNEL};

/*! \namespace LO21
 *  \brief Designe les classes definies dans le but du projet de LO21 P12
 */
namespace LO21{
    /*! \class Option
     * \brief Classe permettant de gerer les options gerees par l'utilisateur, implementant
     * le design pattern Singleton
     */
    class Option {
    private:        
        TypeDiv _typeDiv; /*! Le type des constantes selectionne */
        bool _complexe; /*! Determine si le mode complexe est active */
        bool _degre; /*! Determine si le mode degre est active */
        static Option* _option; /*! L'instance de la classe Option */

        /*! \fn Option()
         * \brief Constructeur de la classe
         */
        Option():_complexe(false), _degre(false), _typeDiv(MENU_ENTIER){}
        ~Option(){}
        Option(const Option&){}

    public:

        /*! \fn static Option& getInstance()
         * \brief Recupere l'instance creee de la classe Option, si celle-ci n'existe pas, la cree
         * \return Option& une reference vers l'instance de la classe Option
         */
        static Option& getInstance();

        /*! \fn static void libereInstance()
         * \brief Demande la destruction de la classe Option
         */
        static void libereInstance();

        /*! \fn void set_typeDiv(TypeDiv s)
         * \brief Modifie le type de constante selectionne par l'utilisateur
         * \param s le type de constante selectionne
         */
        void set_typeDiv(TypeDiv s);
        void set_complexe(bool b){
            _complexe = b;
        }
        void set_degre(bool b){
            _degre= b;
        }

        /*! \fn TypeDiv get_typeDiv() const
         * \brief Retourne le type de constante selectionne
         * \return TypeDiv le type de constante
         */
        TypeDiv get_typeDiv() const{ return _typeDiv; }
        bool get_degre() const{ return _degre; }
        bool get_complexe() const{ return _complexe; }

        /*! \fn void saveOptions()
         * \brief Sauvegarde dans un fichier les options selectionnees a la fermeture de la calculatrice
         */
        void saveOptions();

        /*! \class Complexe
         * \brief Classe permettant de gerer les nombres complexes
         */
        QString toString() const;

    };
}

#endif // OPTION_H
