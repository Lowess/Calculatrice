#ifndef FABRIQUE_H
#define FABRIQUE_H

/*! \file Calculatrice.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-tête pour déclaration de la classe Fabrique
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
 *  \brief Désigne les classes définies dans le but du projet de LO21 P12
 */
namespace LO21{

    /*! \enum enum_Fabrique
     * \brief Permet de déterminer de quel type est la saisie de l'utilisateur afin de créer l'objet correspondant
     */
    enum enum_Fabrique {ENTIER, REEL, RATIONNEL, COMPLEXE, OPERATEUR_BINAIRE, OPERATEUR_UNAIRE, EXPRESSION};

    /*! \class Fabrique
     * \brief Classe implémentant le design pattern Singleton, servant à décrypter la saisie utilisateur pour
     * pouvoir instancier les bons objets
     */
    class Fabrique{
        private:
            static Fabrique* _f; /*! Instance de la Fabrique pour une calculatrice */

            /*! \fn Fabrique()
             * \brief Constructeur par défaut de la classe Fabrique
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
             * \brief Permet de réorganiser les différents éléments obtenus après suppression des espaces pour séparer
             * les expressions des constantes
             * \param text la liste de chaînes de caractère obtenue après suppression des espaces
             * \return QList<QString> une liste de chaînes de caractère réorganisée
             */
            QList<QString> preTraitement(QList<QString>& text) const;

        public:

            /*! \fn static Fabrique& getInstance()
             * \brief Permet de demander la récupération de l'instance de Fabrique, et si elle n'est pas instanciée, en créer une
             * \return Fabrique& la référence vers l'instance de Fabrique
             */
            static Fabrique& getInstance();

            /*! \fn static void libereInstance()
             * \brief Permet de demander la destruction de l'instance de Fabrique
             */
            static void libereInstance();

            //Permet de parser la chaine et de crÃ©er le bon type d'expression pour les empiler
            /*! \fn void creer(const QString& text) const
             * \brief Parse la chaîne de caractère passée en arguments et créé la classe correcte,
             * encapsulée dans un pointeur d'Expression, afin d'être stockée dans la pile
             * \param text la chaîne à partir de laquelle les objets vont être créés
             */
            void creer(const QString& text) const;

    };

    /*! \fn enum_Fabrique getTypeSousChaine(const QString& ss)
     * \brief Renvoie le type de l'insertion par l'utilisateur
     * \param s la chaîne de caractères à tester
     * \return enum_Fabrique le type correspondant à la sous-chaîne passée en argument
     */
    enum_Fabrique getTypeSousChaine(const QString& ss);

    /*! \fn bool isEntier(const QString& s)
     * \brief Teste si la chaîne de caractères passée en arguments représente un entier
     * \param s la chaîne de caractères à tester
     * \return bool renvoie true si s est bien un entier, false sinon
     */
    bool isEntier(const QString& s);

    /*! \fn bool isReel(const QString& s)
     * \brief Teste si la chaîne de caractères passée en arguments représente un réel
     * \param s la chaîne de caractères à tester
     * \return bool renvoie true si s est bien un réel, false sinon
     */
    bool isReel(const QString& s);

    /*! \fn bool isRationnel(const QString& s)
     * \brief Teste si la chaîne de caractères passée en arguments représente un rationnel
     * \param s la chaîne de caractères à tester
     * \return bool renvoie true si s est bien un rationnel, false sinon
     */
    bool isRationnel(const QString& s);

    /*! \fn bool isComplexe(const QString& s)
     * \brief Teste si la chaîne de caractères passée en arguments représente un complexe
     * \param s la chaîne de caractères à tester
     * \return bool renvoie true si s est bien un complexe, false sinon
     */
    bool isComplexe(const QString& s);

    /*! \fn bool isOperateurBinaire(const QString& s)
     * \brief Teste si la chaîne de caractères passée en arguments représente un opérateur binaire
     * \param s la chaîne de caractères à tester
     * \return bool renvoie true si s est bien un opérateur binaire, false sinon
     */
    bool isOperateurBinaire(const QString& s);

    /*! \fn bool isOperateurUnaire(const QString& s)
     * \brief Teste si la chaîne de caractères passée en arguments représente un opérateur unaire
     * \param s la chaîne de caractères à tester
     * \return bool renvoie true si s est bien un opérateur unaire, false sinon
     */
    bool isOperateurUnaire(const QString& s);

    /*! \fn bool isExpression(const QString& s)
     * \brief Teste si la chaîne de caractères passée en arguments représente une expression
     * \param s la chaîne de caractères à tester
     * \return bool renvoie true si s est bien une expression, false sinon
     */
    bool isExpression(const QString& s);
}

/*! \fn Constante& division(const Constante& nb) const
 * \brief Gère la division d'une constante avec l'évaluation
 * \param nb une référence vers une constante
 * \return Constante& une référence vers la constante créée à partir du résultat
 */
QTextStream& operator<<(QTextStream& s, const LO21::enum_Fabrique& ef);

#endif // FABRIQUE_H
