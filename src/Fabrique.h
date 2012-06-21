#ifndef FABRIQUE_H
#define FABRIQUE_H

/*! \file Calculatrice.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tete pour declaration de la classe Fabrique
  */

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
 *  \brief Designe les classes definies dans le but du projet de LO21 P12
 */
namespace LO21{

    /*! \enum enum_Fabrique
     * \brief Permet de determiner de quel type est la saisie de l'utilisateur afin de creer l'objet correspondant
     */
    enum enum_Fabrique {ENTIER, REEL, RATIONNEL, COMPLEXE, OPERATEUR_BINAIRE, OPERATEUR_UNAIRE, EXPRESSION};

    /*! \class Fabrique
     * \brief Classe implementant le design pattern Singleton, servant a decrypter la saisie utilisateur pour
     * pouvoir instancier les bons objets
     */
    class Fabrique{
        private:
            static Fabrique* _f; /*! Instance de la Fabrique pour une calculatrice */

            /*! \fn Fabrique()
             * \brief Constructeur par defaut de la classe Fabrique
             */
            Fabrique(){}

            /*! \fn Fabrique(const Fabrique& f)
             * \brief Constructeur par recopie de la classe Fabrique
             * \param f une instance de la classe Fabrique
             */
            Fabrique(const Fabrique& f){}

            /*! \fn ~Fabrique()
             * \brief Destructeur de la classe Fabrique
             */
            ~Fabrique(){}

            /*! \fn QList<QString> preTraitement(QList<QString>& text) const
             * \brief Permet de reorganiser les differents elements obtenus apres suppression des espaces pour separer
             * les expressions des constantes
             * \param text la liste de chaines de caractere obtenue apres suppression des espaces
             * \return QList<QString> une liste de chaines de caractere reorganisee
             */
            QList<QString> preTraitement(QList<QString>& text) const;

        public:

            /*! \fn static Fabrique& getInstance()
             * \brief Permet de demander la recuperation de l'instance de Fabrique, et si elle n'est pas instanciee, en creer une
             * \return Fabrique& la reference vers l'instance de Fabrique
             */
            static Fabrique& getInstance();

            /*! \fn static void libereInstance()
             * \brief Permet de demander la destruction de l'instance de Fabrique
             */
            static void libereInstance();

            //Permet de parser la chaine et de créer le bon type d'expression pour les empiler
            /*! \fn void creer(const QString& text) const
             * \brief Parse la chaine de caractere passee en arguments et cree la classe correcte,
             * encapsulee dans un pointeur d'Expression, afin d'etre stockee dans la pile
             * \param text la chaine a partir de laquelle les objets vont etre crees
             */
            void creer(const QString& text) const;

    };

    /*! \fn enum_Fabrique getTypeSousChaine(const QString& ss)
     * \brief Renvoie le type de l'insertion par l'utilisateur
     * \param s la chaine de caracteres a tester
     * \return enum_Fabrique le type correspondant a la sous-chaine passee en argument
     */
    enum_Fabrique getTypeSousChaine(const QString& ss);

    /*! \fn bool isEntier(const QString& s)
     * \brief Teste si la chaine de caracteres passee en arguments represente un entier
     * \param s la chaine de caracteres a tester
     * \return bool renvoie true si s est bien un entier, false sinon
     */
    bool isEntier(const QString& s);

    /*! \fn bool isReel(const QString& s)
     * \brief Teste si la chaine de caracteres passee en arguments represente un reel
     * \param s la chaine de caracteres a tester
     * \return bool renvoie true si s est bien un reel, false sinon
     */
    bool isReel(const QString& s);

    /*! \fn bool isRationnel(const QString& s)
     * \brief Teste si la chaine de caracteres passee en arguments represente un rationnel
     * \param s la chaine de caracteres a tester
     * \return bool renvoie true si s est bien un rationnel, false sinon
     */
    bool isRationnel(const QString& s);

    /*! \fn bool isComplexe(const QString& s)
     * \brief Teste si la chaine de caracteres passee en arguments represente un complexe
     * \param s la chaine de caracteres a tester
     * \return bool renvoie true si s est bien un complexe, false sinon
     */
    bool isComplexe(const QString& s);

    /*! \fn bool isOperateurBinaire(const QString& s)
     * \brief Teste si la chaine de caracteres passee en arguments represente un operateur binaire
     * \param s la chaine de caracteres a tester
     * \return bool renvoie true si s est bien un operateur binaire, false sinon
     */
    bool isOperateurBinaire(const QString& s);

    /*! \fn bool isOperateurUnaire(const QString& s)
     * \brief Teste si la chaine de caracteres passee en arguments represente un operateur unaire
     * \param s la chaine de caracteres a tester
     * \return bool renvoie true si s est bien un operateur unaire, false sinon
     */
    bool isOperateurUnaire(const QString& s);

    /*! \fn bool isExpression(const QString& s)
     * \brief Teste si la chaine de caracteres passee en arguments represente une expression
     * \param s la chaine de caracteres a tester
     * \return bool renvoie true si s est bien une expression, false sinon
     */
    bool isExpression(const QString& s);
}

/*! \fn Constante& division(const Constante& nb) const
 * \brief Gere la division d'une constante avec l'evaluation
 * \param nb une reference vers une constante
 * \return Constante& une reference vers la constante creee a partir du resultat
 */
QTextStream& operator<<(QTextStream& s, const LO21::enum_Fabrique& ef);

#endif // FABRIQUE_H
