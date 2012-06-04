#ifndef FABRIQUE_H
#define FABRIQUE_H

#include <iterator>
#include <QString>
#include <QList>

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

            Expression* creer(const QString& text) const;

    };
    enum_Fabrique getTypeSousChaine(const QString& ss); //Retourne le type de l'ins
    bool isEntier(const QString& s);
    bool isReel(const QString& s);
    bool isRationnel(const QString& s);
    bool isComplexe(const QString& s);
    bool isOperateurBinaire(const QString& s);
    bool isOperateurUnaire(const QString& s);



}
//operator<<
QTextStream& operator<<(QTextStream& s, const Calculatrice::enum_Fabrique& ef);

#endif // FABRIQUE_H
