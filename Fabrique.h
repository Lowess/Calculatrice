#ifndef FABRIQUE_H
#define FABRIQUE_H

/*! \file Calculatrice.h
  * \author Florian Dambrine, Olivia Reaney
  * \brief Fichier d'en-t�te pour d�claration de la classe Fabrique
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
 *  \brief D�signe les classes d�finies dans le but du projet de LO21 P12
 */
namespace LO21{

    /*! \enum enum_Fabrique
     * \brief Permet de d�terminer de quel type est la saisie de l'utilisateur afin de cr�er l'objet correspondant
     */
    enum enum_Fabrique {ENTIER, REEL, RATIONNEL, COMPLEXE, OPERATEUR_BINAIRE, OPERATEUR_UNAIRE, EXPRESSION};

    /*! \class Fabrique
     * \brief Classe impl�mentant le design pattern Singleton, servant � d�crypter la saisie utilisateur pour
     * pouvoir instancier les bons objets
     */
    class Fabrique{
        private:
            static Fabrique* _f; /*! Instance de la Fabrique pour une calculatrice */

            /*! \fn Fabrique()
             * \brief Constructeur par d�faut de la classe Fabrique
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
             * \brief Permet de r�organiser les diff�rents �l�ments obtenus apr�s suppression des espaces pour s�parer
             * les expressions des constantes
             * \param text la liste de cha�nes de caract�re obtenue apr�s suppression des espaces
             * \return QList<QString> une liste de cha�nes de caract�re r�organis�e
             */
            QList<QString> preTraitement(QList<QString>& text) const;

        public:

            /*! \fn static Fabrique& getInstance()
             * \brief Permet de demander la r�cup�ration de l'instance de Fabrique, et si elle n'est pas instanci�e, en cr�er une
             * \return Fabrique& la r�f�rence vers l'instance de Fabrique
             */
            static Fabrique& getInstance();

            /*! \fn static void libereInstance()
             * \brief Permet de demander la destruction de l'instance de Fabrique
             */
            static void libereInstance();

            //Permet de parser la chaine et de créer le bon type d'expression pour les empiler
            /*! \fn void creer(const QString& text) const
             * \brief Parse la cha�ne de caract�re pass�e en arguments et cr�� la classe correcte,
             * encapsul�e dans un pointeur d'Expression, afin d'�tre stock�e dans la pile
             * \param text la cha�ne � partir de laquelle les objets vont �tre cr��s
             */
            void creer(const QString& text) const;

    };

    /*! \fn enum_Fabrique getTypeSousChaine(const QString& ss)
     * \brief Renvoie le type de l'insertion par l'utilisateur
     * \param s la cha�ne de caract�res � tester
     * \return enum_Fabrique le type correspondant � la sous-cha�ne pass�e en argument
     */
    enum_Fabrique getTypeSousChaine(const QString& ss);

    /*! \fn bool isEntier(const QString& s)
     * \brief Teste si la cha�ne de caract�res pass�e en arguments repr�sente un entier
     * \param s la cha�ne de caract�res � tester
     * \return bool renvoie true si s est bien un entier, false sinon
     */
    bool isEntier(const QString& s);

    /*! \fn bool isReel(const QString& s)
     * \brief Teste si la cha�ne de caract�res pass�e en arguments repr�sente un r�el
     * \param s la cha�ne de caract�res � tester
     * \return bool renvoie true si s est bien un r�el, false sinon
     */
    bool isReel(const QString& s);

    /*! \fn bool isRationnel(const QString& s)
     * \brief Teste si la cha�ne de caract�res pass�e en arguments repr�sente un rationnel
     * \param s la cha�ne de caract�res � tester
     * \return bool renvoie true si s est bien un rationnel, false sinon
     */
    bool isRationnel(const QString& s);

    /*! \fn bool isComplexe(const QString& s)
     * \brief Teste si la cha�ne de caract�res pass�e en arguments repr�sente un complexe
     * \param s la cha�ne de caract�res � tester
     * \return bool renvoie true si s est bien un complexe, false sinon
     */
    bool isComplexe(const QString& s);

    /*! \fn bool isOperateurBinaire(const QString& s)
     * \brief Teste si la cha�ne de caract�res pass�e en arguments repr�sente un op�rateur binaire
     * \param s la cha�ne de caract�res � tester
     * \return bool renvoie true si s est bien un op�rateur binaire, false sinon
     */
    bool isOperateurBinaire(const QString& s);

    /*! \fn bool isOperateurUnaire(const QString& s)
     * \brief Teste si la cha�ne de caract�res pass�e en arguments repr�sente un op�rateur unaire
     * \param s la cha�ne de caract�res � tester
     * \return bool renvoie true si s est bien un op�rateur unaire, false sinon
     */
    bool isOperateurUnaire(const QString& s);

    /*! \fn bool isExpression(const QString& s)
     * \brief Teste si la cha�ne de caract�res pass�e en arguments repr�sente une expression
     * \param s la cha�ne de caract�res � tester
     * \return bool renvoie true si s est bien une expression, false sinon
     */
    bool isExpression(const QString& s);
}

/*! \fn Constante& division(const Constante& nb) const
 * \brief G�re la division d'une constante avec l'�valuation
 * \param nb une r�f�rence vers une constante
 * \return Constante& une r�f�rence vers la constante cr��e � partir du r�sultat
 */
QTextStream& operator<<(QTextStream& s, const LO21::enum_Fabrique& ef);

#endif // FABRIQUE_H
