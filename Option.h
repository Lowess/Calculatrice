#ifndef OPTION_H
#define OPTION_H

/*! \file Option.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe Option
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
 * \brief Définit les différents types de constantes à créer par la Fabrique
 * et le type de retour des divisions
 */
enum TypeDiv {MENU_ENTIER, MENU_REEL, MENU_RATIONNEL};

/*! \namespace LO21
 *  \brief Désigne les classes définies dans le but du projet de LO21 P12
 */
namespace LO21{
    /*! \class Option
     * \brief Classe permettant de gérer les options gérées par l'utilisateur, implémentant
     * le design pattern Singleton
     */
    class Option {
    private:
        TypeDiv _typeDiv; /*! Le type des constantes sélectionné */
        bool _complexe; /*! Détermine si le mode complexe est activé */
        bool _degre; /*! Détermine si le mode degré est activé */
        static Option* _option; /*! L'instance de la classe Option */

        /*! \fn Option()
         * \brief Constructeur de la classe
         */
        Option():_complexe(false), _degre(false), _typeDiv(MENU_ENTIER){}

        /*! \fn void switchDegre(bool d)
         * \brief Permet de changer le mode des degrés pour les opérations trigonométriques
         * \param d est true si le mode Degre est activé, false sinon
         */
        void switchDegre(bool d){
            _degre = d;
        }

        /*! \fn void switchComplexe(bool c)
         * \brief Permet de changer le mode des complexes pour permettre leur création et leur stockage dans la pile
         * \param c est true si le mode complexe est activé, false sinon
         */
        void switchComplexe(bool c){
            _complexe = c;
        }

    public:

        /*! \fn static Option& getInstance()
         * \brief Récupère l'instance créée de la classe Option, si celle-ci n'existe pas, la créé
         * \return Option& une référence vers l'instance de la classe Option
         */
        static Option& getInstance();

        /*! \fn static void libereInstance()
         * \brief Demande la destruction de la classe Option
         */
        static void libereInstance();

        /*! \fn void set_typeDiv(TypeDiv s)
         * \brief Modifie le type de constante sélectionné par l'utilisateur
         * \param s le type de constante sélectionné
         */
        void set_typeDiv(TypeDiv s);
        void set_complexe(bool b){
            _complexe = b;
        }
        void set_degre(bool b){
            _degre= b;
        }

        /*! \fn TypeDiv get_typeDiv() const
         * \brief Retourne le type de constante sélectionné
         * \return TypeDiv le type de constante
         */
        TypeDiv get_typeDiv() const{ return _typeDiv; }
        bool get_degre() const{ return _degre; }
        bool get_complexe() const{ return _complexe; }

        /*! \fn void saveOptions()
         * \brief Sauvegarde dans un fichier les options sélectionnées à la fermeture de la calculatrice
         */
        void saveOptions();
    };
}

#endif // OPTION_H
