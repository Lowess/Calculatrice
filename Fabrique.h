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

/**
  * Implementation du DP Singleton
  *
**/
namespace Calculatrice{

    enum enum_Fabrique {ENTIER, REEL, RATIONNEL, COMPLEXE, OPERATEUR_BINAIRE, OPERATEUR_UNAIRE};

    class Fabrique{
        private:
            static Fabrique* _f;

            Fabrique(){}
            Fabrique(const Fabrique& f){}
            ~Fabrique(){}

        public:
            static Fabrique& getInstance();
            static void libereInstance();

            //Permet de parser la chaine et de créer le bon type d'expression pour les empiler
            void creer(const QString& text) const;

    };
    enum_Fabrique getTypeSousChaine(const QString& ss); //Retourne le type de l'ins
    bool isEntier(const QString& s);
    bool isReel(const QString& s);
    bool isRationnel(const QString& s);
    bool isComplexe(const QString& s);
    bool isOperateurBinaire(const QString& s);
    bool isOperateurUnaire(const QString& s);
<<<<<<< HEAD

=======
>>>>>>> d50d9c44f71eff56d4eada027bfcd613b1693de1
}

//operator<<
QTextStream& operator<<(QTextStream& s, const Calculatrice::enum_Fabrique& ef);

#endif // FABRIQUE_H
