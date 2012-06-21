#ifndef CALCULATRICE_H
#define CALCULATRICE_H

/*! \file Calculatrice.h
 * \author Florian Dambrine, Olivia Reaney
 * \brief Fichier d'en-tete pour declaration de la classe Calculatrice
 */

#include "Pile.h"
#include "Fabrique.h"
#include "Gardien.h"
#include "LogSystem.h"

/*! \namespace LO21
 *  \brief Designe les classes definies dans le but du projet de LO21 P12
 */
namespace LO21{

    /*! \class Calculatrice
     *  Implementant le design pattern Singleton, la calculatrice est une classe unique servant a faire les operations sur les valeurs entrees.
     */
    class Calculatrice{
        private:
            static Calculatrice* _calc; /*! Attribut statique contenant le pointeur vers l'instanciation de la classe */
            Gardien* _gard; /*! Attribut contenant le pointeur vers le gardien de la classe */
            Pile* _pile; /*! Attribut contenant le pointeur vers la pile utilisee couramment par la classe */

            /*! \fn Calculatrice()
             * \brief Constructeur par defaut de la classe Calculatrice, prive car cette classe implemente un design pattern Singleton.
             *        Instancie un gardien afin de gerer les actions sur la calculatrice, ainsi qu'une pile pour stockage et affichage des expressions
             */
            Calculatrice():_gard(Gardien::getInstance()),_pile(new Pile()){}

            /*! \fn Calculatrice(const Calculatrice& c)
             * \brief Constructeur par copie de la classe Calculatrice, prive car cette classe implemente un design pattern Singleton.
             *        Permet de creer une pile a partir d'une pile deja existante
             * \param Calculatrice& c, qui ne sera pas modifiee durant la fonction
             */
            Calculatrice(const Calculatrice& c){
                delete _pile;
                _pile=c._pile->clone();
            }

            /*! \fn ~Calculatrice()
             * \brief Destructeur de la classe Calculatrice, prive car cette classe implemente un design pattern Singleton.
             *         Permet de supprimer de la memoire la pile utilisee par la calculatrice ainsi que le gardien.
             */
            ~Calculatrice(){
                delete _pile;
                Gardien::libereInstance();
            }
        public:

            /*! \fn Calculatrice& getInstance()
             * \brief Fonction qui permet de recuperer l'instance d'une calculatrice, et s'il n'en existe pas une existante, en cree une.
             *        Permet d'empecher la construction d'une calculatrice par l'utilisateur
             * \return Calculatrice&, une reference vers la calculatrice actuellement utilisee
             */
            static Calculatrice& getInstance();

            /*! \fn libereInstance()
             * \brief Fonction qui permet de supprimer l'instance d'une calculatrice
             *        Empeche l'utilisateur de faire directement appel au destructeur de la classe Calculatrice.
             */
            static void libereInstance();


            /*! \fn Pile* get_pile() const
             * \brief Retourne un pointeur vers la pile utilisee par la calculatrice.
             *
             * \return Pile*, un pointeur vers la pile actuellement utilisee par la calculatrice
             */
            Pile* get_pile() const{ return _pile; }

            /*! \fn set_pile(Pile* p)
             * \brief Modifie l'attribut _pile de la calculatrice en lui donnant le pointeur vers la nouvelle pile a utiliser
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
