/** \file Calculatrice.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe Fabrique
  */

#ifndef FABRIQUE_H
#define FABRIQUE_H

#include <iterator>
#include <QString>
#include <QList>

#include "Pile.h"
#include "Expression.h"
#include "Entier.h"
#include "Reel.h"
#include "Rationnel.h"
#include "Exp.h"

/*! \namespace LO21
 *  \brief Désigne les classes définies dans le but du projet de LO21 P12
 */
namespace LO21{

/*! \class Complexe
 * \brief Classe permettant de gérer les nombres complexes
 */
    enum enum_Fabrique {ENTIER, REEL, RATIONNEL, COMPLEXE, OPERATEUR_BINAIRE, OPERATEUR_UNAIRE, EXPRESSION};

    /*! \class Complexe
     * \brief Classe permettant de gérer les nombres complexes
     */
    class Fabrique{
        private:
            static Fabrique* _f; /*! */

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            Fabrique(){}

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            Fabrique(const Fabrique& f){}

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            ~Fabrique(){}

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            QList<QString> preTraitement(QList<QString>& text) const;

        public:

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            static Fabrique& getInstance();

            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            static void libereInstance();

            //Permet de parser la chaine et de crÃ©er le bon type d'expression pour les empiler
            /*! \class Complexe
             * \brief Classe permettant de gérer les nombres complexes
             */
            void creer(const QString& text) const;

    };
    /*! \class Complexe
     * \brief Classe permettant de gérer les nombres complexes
     */
    enum_Fabrique getTypeSousChaine(const QString& ss); //Retourne le type de l'ins

    /*! \class Complexe
     * \brief Classe permettant de gérer les nombres complexes
     */
    bool isEntier(const QString& s);

    /*! \class Complexe
     * \brief Classe permettant de gérer les nombres complexes
     */
    bool isReel(const QString& s);

    /*! \class Complexe
     * \brief Classe permettant de gérer les nombres complexes
     */
    bool isRationnel(const QString& s);

    /*! \class Complexe
     * \brief Classe permettant de gérer les nombres complexes
     */
    bool isComplexe(const QString& s);

    /*! \class Complexe
     * \brief Classe permettant de gérer les nombres complexes
     */
    bool isOperateurBinaire(const QString& s);

    /*! \class Complexe
     * \brief Classe permettant de gérer les nombres complexes
     */
    bool isOperateurUnaire(const QString& s);

    /*! \class Complexe
     * \brief Classe permettant de gérer les nombres complexes
     */
    bool isExpression(const QString& s);
}

/*! \class Complexe
 * \brief Classe permettant de gérer les nombres complexes
 */
QTextStream& operator<<(QTextStream& s, const LO21::enum_Fabrique& ef);

#endif // FABRIQUE_H
