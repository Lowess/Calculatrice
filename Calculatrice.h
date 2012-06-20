#ifndef CALCULATRICE_H
#define CALCULATRICE_H

/*! \file Calculatrice.h
 * \author Florian Dambrine, Olivia Reaney
 * \brief Fichier d'en-t�te pour d�claration de la classe Calculatrice
 */

#include "Pile.h"
#include "Fabrique.h"
#include "Gardien.h"
#include "LogSystem.h"

/*! \namespace LO21
 *  \brief D�signe les classes d�finies dans le but du projet de LO21 P12
 */
namespace LO21{

    /*! \class Calculatrice
     *  Impl�mentant le design pattern Singleton, la calculatrice est une classe unique servant � faire les op�rations sur les valeurs entr�es.
     */
    class Calculatrice{
        private:
            static Calculatrice* _calc; /*! Attribut statique contenant le pointeur vers l'instanciation de la classe */
            Gardien* _gard; /*! Attribut contenant le pointeur vers le gardien de la classe */
            Pile* _pile; /*! Attribut contenant le pointeur vers la pile utilis�e couramment par la classe */

            /*! \fn Calculatrice()
             * \brief Constructeur par d�faut de la classe Calculatrice, priv� car cette classe impl�mente un design pattern Singleton.
             *        Instancie un gardien afin de g�rer les actions sur la calculatrice, ainsi qu'une pile pour stockage et affichage des expressions
             */
            Calculatrice():_gard(Gardien::getInstance()),_pile(new Pile()){}

            /*! \fn Calculatrice(const Calculatrice& c)
             * \brief Constructeur par copie de la classe Calculatrice, priv� car cette classe impl�mente un design pattern Singleton.
             *        Permet de cr�er une pile � partir d'une pile d�j� existante
             * \param Calculatrice& c, qui ne sera pas modifi�e durant la fonction
             */
            Calculatrice(const Calculatrice& c){
                delete _pile;
                _pile=c._pile->clone();
            }

            /*! \fn ~Calculatrice()
             * \brief Destructeur de la classe Calculatrice, priv� car cette classe impl�mente un design pattern Singleton.
             *         Permet de supprimer de la m�moire la pile utilis�e par la calculatrice ainsi que le gardien.
             */
            ~Calculatrice(){
                delete _pile;
                Gardien::libereInstance();
            }
        public:

            /*! \fn Calculatrice& getInstance()
             * \brief Fonction qui permet de r�cup�rer l'instance d'une calculatrice, et s'il n'en existe pas une existante, en cr�� une.
             *        Permet d'emp�cher la construction d'une calculatrice par l'utilisateur
             * \return Calculatrice&, une r�f�rence vers la calculatrice actuellement utilis�e
             */
            static Calculatrice& getInstance();

            /*! \fn libereInstance()
             * \brief Fonction qui permet de supprimer l'instance d'une calculatrice
             *        Emp�che l'utilisateur de faire directement appel au destructeur de la classe Calculatrice.
             */
            static void libereInstance();


            /*! \fn Pile* get_pile() const
             * \brief Retourne un pointeur vers la pile utilis�e par la calculatrice.
             *
             * \return Pile*, un pointeur vers la pile actuellement utilis�e par la calculatrice
             */
            Pile* get_pile() const{ return _pile; }

            /*! \fn set_pile(Pile* p)
             * \brief Modifie l'attribut _pile de la calculatrice en lui donnant le pointeur vers la nouvelle pile � utiliser
             *
             * \param Pile* p, un pointeur vers la pile qu'on veut utiliser dans la calculatrice
             */
            void set_pile(Pile* p) {
                _pile=p;
                qDebug() << "Taille de la pile courante" << _pile->size();
            }

            /*! \fn Gardien* get_gardien() const
             * \brief Retourne un pointeur vers le gardien surveillant la calculatrice
             *
             * \return Gardien*, un pointeur vers le gardien surveillant actuellement la pile
             */
            Gardien* get_gardien() const{ return _gard; }

    };
}
#endif // CALCULATRICE_H
