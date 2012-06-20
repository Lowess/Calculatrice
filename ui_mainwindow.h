/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Jun 21 00:35:33 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNouveau;
    QAction *actionQuitter;
    QAction *actionEntiers;
    QAction *actionR_els;
    QAction *actionRationnels;
    QAction *actionDegr;
    QAction *actionRadian;
    QAction *actionUtilisation_des_complexes;
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QPushButton *btn7;
    QPushButton *btn8;
    QPushButton *btn9;
    QPushButton *btn4;
    QPushButton *btn5;
    QPushButton *btn6;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QPushButton *btnEnter;
    QPushButton *btn0;
    QPushButton *btnDel;
    QGridLayout *gridLayout_4;
    QPushButton *btnMoins;
    QPushButton *btnMultiplier;
    QPushButton *btnDiviser;
    QPushButton *btnMod;
    QPushButton *btnSign;
    QPushButton *btnPlus;
    QPushButton *btnPow;
    QFrame *line_3;
    QSpacerItem *verticalSpacer_3;
    QGridLayout *gridLayout_3;
    QPushButton *btnSin;
    QPushButton *btnCos;
    QPushButton *btnTan;
    QPushButton *btnSinh;
    QPushButton *btnCosh;
    QPushButton *btnTanh;
    QPushButton *btnLn;
    QPushButton *btnLog;
    QPushButton *btnInv;
    QPushButton *btnSqrt;
    QPushButton *btnSqr;
    QPushButton *btnCube;
    QPushButton *btnFactorielle;
    QPushButton *btnEval;
    QFrame *line;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lastStack;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *btnSwap;
    QPushButton *btnSum;
    QPushButton *btnMean;
    QPushButton *btnClear;
    QPushButton *btnDup;
    QPushButton *btnDrop;
    QFrame *line_2;
    QListWidget *listStack;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuOptions;
    QMenu *menuType_de_constantes;
    QMenu *menuUnit_des_degr_s;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(906, 473);
        actionNouveau = new QAction(MainWindow);
        actionNouveau->setObjectName(QString::fromUtf8("actionNouveau"));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionEntiers = new QAction(MainWindow);
        actionEntiers->setObjectName(QString::fromUtf8("actionEntiers"));
        actionEntiers->setCheckable(true);
        actionR_els = new QAction(MainWindow);
        actionR_els->setObjectName(QString::fromUtf8("actionR_els"));
        actionRationnels = new QAction(MainWindow);
        actionRationnels->setObjectName(QString::fromUtf8("actionRationnels"));
        actionDegr = new QAction(MainWindow);
        actionDegr->setObjectName(QString::fromUtf8("actionDegr"));
        actionDegr->setCheckable(true);
        actionDegr->setChecked(true);
        actionRadian = new QAction(MainWindow);
        actionRadian->setObjectName(QString::fromUtf8("actionRadian"));
        actionUtilisation_des_complexes = new QAction(MainWindow);
        actionUtilisation_des_complexes->setObjectName(QString::fromUtf8("actionUtilisation_des_complexes"));
        actionUtilisation_des_complexes->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 871, 397));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaximumSize(QSize(16777215, 16777215));
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_2->addWidget(lineEdit);

        verticalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        btn7 = new QPushButton(verticalLayoutWidget);
        btn7->setObjectName(QString::fromUtf8("btn7"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn7->sizePolicy().hasHeightForWidth());
        btn7->setSizePolicy(sizePolicy);
        btn7->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(btn7, 0, 0, 1, 1);

        btn8 = new QPushButton(verticalLayoutWidget);
        btn8->setObjectName(QString::fromUtf8("btn8"));
        sizePolicy.setHeightForWidth(btn8->sizePolicy().hasHeightForWidth());
        btn8->setSizePolicy(sizePolicy);
        btn8->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(btn8, 0, 2, 1, 1);

        btn9 = new QPushButton(verticalLayoutWidget);
        btn9->setObjectName(QString::fromUtf8("btn9"));
        sizePolicy.setHeightForWidth(btn9->sizePolicy().hasHeightForWidth());
        btn9->setSizePolicy(sizePolicy);
        btn9->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(btn9, 0, 3, 1, 1);

        btn4 = new QPushButton(verticalLayoutWidget);
        btn4->setObjectName(QString::fromUtf8("btn4"));
        sizePolicy.setHeightForWidth(btn4->sizePolicy().hasHeightForWidth());
        btn4->setSizePolicy(sizePolicy);
        btn4->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(btn4, 1, 0, 1, 1);

        btn5 = new QPushButton(verticalLayoutWidget);
        btn5->setObjectName(QString::fromUtf8("btn5"));
        sizePolicy.setHeightForWidth(btn5->sizePolicy().hasHeightForWidth());
        btn5->setSizePolicy(sizePolicy);
        btn5->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(btn5, 1, 2, 1, 1);

        btn6 = new QPushButton(verticalLayoutWidget);
        btn6->setObjectName(QString::fromUtf8("btn6"));
        sizePolicy.setHeightForWidth(btn6->sizePolicy().hasHeightForWidth());
        btn6->setSizePolicy(sizePolicy);
        btn6->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(btn6, 1, 3, 1, 1);

        btn1 = new QPushButton(verticalLayoutWidget);
        btn1->setObjectName(QString::fromUtf8("btn1"));
        sizePolicy.setHeightForWidth(btn1->sizePolicy().hasHeightForWidth());
        btn1->setSizePolicy(sizePolicy);
        btn1->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(btn1, 2, 0, 1, 1);

        btn2 = new QPushButton(verticalLayoutWidget);
        btn2->setObjectName(QString::fromUtf8("btn2"));
        sizePolicy.setHeightForWidth(btn2->sizePolicy().hasHeightForWidth());
        btn2->setSizePolicy(sizePolicy);
        btn2->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(btn2, 2, 2, 1, 1);

        btn3 = new QPushButton(verticalLayoutWidget);
        btn3->setObjectName(QString::fromUtf8("btn3"));
        sizePolicy.setHeightForWidth(btn3->sizePolicy().hasHeightForWidth());
        btn3->setSizePolicy(sizePolicy);
        btn3->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(btn3, 2, 3, 1, 1);

        btnEnter = new QPushButton(verticalLayoutWidget);
        btnEnter->setObjectName(QString::fromUtf8("btnEnter"));
        sizePolicy.setHeightForWidth(btnEnter->sizePolicy().hasHeightForWidth());
        btnEnter->setSizePolicy(sizePolicy);
        btnEnter->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(btnEnter, 3, 3, 1, 1);

        btn0 = new QPushButton(verticalLayoutWidget);
        btn0->setObjectName(QString::fromUtf8("btn0"));
        sizePolicy.setHeightForWidth(btn0->sizePolicy().hasHeightForWidth());
        btn0->setSizePolicy(sizePolicy);
        btn0->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(btn0, 3, 2, 1, 1);

        btnDel = new QPushButton(verticalLayoutWidget);
        btnDel->setObjectName(QString::fromUtf8("btnDel"));
        sizePolicy.setHeightForWidth(btnDel->sizePolicy().hasHeightForWidth());
        btnDel->setSizePolicy(sizePolicy);
        btnDel->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(btnDel, 3, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 1, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        btnMoins = new QPushButton(verticalLayoutWidget);
        btnMoins->setObjectName(QString::fromUtf8("btnMoins"));
        sizePolicy.setHeightForWidth(btnMoins->sizePolicy().hasHeightForWidth());
        btnMoins->setSizePolicy(sizePolicy);
        btnMoins->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(btnMoins, 1, 1, 1, 1);

        btnMultiplier = new QPushButton(verticalLayoutWidget);
        btnMultiplier->setObjectName(QString::fromUtf8("btnMultiplier"));
        sizePolicy.setHeightForWidth(btnMultiplier->sizePolicy().hasHeightForWidth());
        btnMultiplier->setSizePolicy(sizePolicy);
        btnMultiplier->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(btnMultiplier, 2, 1, 1, 1);

        btnDiviser = new QPushButton(verticalLayoutWidget);
        btnDiviser->setObjectName(QString::fromUtf8("btnDiviser"));
        sizePolicy.setHeightForWidth(btnDiviser->sizePolicy().hasHeightForWidth());
        btnDiviser->setSizePolicy(sizePolicy);
        btnDiviser->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(btnDiviser, 3, 1, 1, 1);

        btnMod = new QPushButton(verticalLayoutWidget);
        btnMod->setObjectName(QString::fromUtf8("btnMod"));
        sizePolicy.setHeightForWidth(btnMod->sizePolicy().hasHeightForWidth());
        btnMod->setSizePolicy(sizePolicy);
        btnMod->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(btnMod, 1, 2, 1, 1);

        btnSign = new QPushButton(verticalLayoutWidget);
        btnSign->setObjectName(QString::fromUtf8("btnSign"));
        sizePolicy.setHeightForWidth(btnSign->sizePolicy().hasHeightForWidth());
        btnSign->setSizePolicy(sizePolicy);
        btnSign->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(btnSign, 2, 2, 1, 1);

        btnPlus = new QPushButton(verticalLayoutWidget);
        btnPlus->setObjectName(QString::fromUtf8("btnPlus"));
        sizePolicy.setHeightForWidth(btnPlus->sizePolicy().hasHeightForWidth());
        btnPlus->setSizePolicy(sizePolicy);
        btnPlus->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(btnPlus, 0, 1, 1, 1);

        btnPow = new QPushButton(verticalLayoutWidget);
        btnPow->setObjectName(QString::fromUtf8("btnPow"));
        sizePolicy.setHeightForWidth(btnPow->sizePolicy().hasHeightForWidth());
        btnPow->setSizePolicy(sizePolicy);
        btnPow->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(btnPow, 0, 2, 1, 1);


        gridLayout->addLayout(gridLayout_4, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        line_3 = new QFrame(verticalLayoutWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_3);

        verticalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_3);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        btnSin = new QPushButton(verticalLayoutWidget);
        btnSin->setObjectName(QString::fromUtf8("btnSin"));
        sizePolicy.setHeightForWidth(btnSin->sizePolicy().hasHeightForWidth());
        btnSin->setSizePolicy(sizePolicy);
        btnSin->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(btnSin, 0, 0, 1, 1);

        btnCos = new QPushButton(verticalLayoutWidget);
        btnCos->setObjectName(QString::fromUtf8("btnCos"));
        sizePolicy.setHeightForWidth(btnCos->sizePolicy().hasHeightForWidth());
        btnCos->setSizePolicy(sizePolicy);
        btnCos->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(btnCos, 0, 1, 1, 1);

        btnTan = new QPushButton(verticalLayoutWidget);
        btnTan->setObjectName(QString::fromUtf8("btnTan"));
        sizePolicy.setHeightForWidth(btnTan->sizePolicy().hasHeightForWidth());
        btnTan->setSizePolicy(sizePolicy);
        btnTan->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(btnTan, 0, 2, 1, 1);

        btnSinh = new QPushButton(verticalLayoutWidget);
        btnSinh->setObjectName(QString::fromUtf8("btnSinh"));
        sizePolicy.setHeightForWidth(btnSinh->sizePolicy().hasHeightForWidth());
        btnSinh->setSizePolicy(sizePolicy);
        btnSinh->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(btnSinh, 1, 0, 1, 1);

        btnCosh = new QPushButton(verticalLayoutWidget);
        btnCosh->setObjectName(QString::fromUtf8("btnCosh"));
        sizePolicy.setHeightForWidth(btnCosh->sizePolicy().hasHeightForWidth());
        btnCosh->setSizePolicy(sizePolicy);
        btnCosh->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(btnCosh, 1, 1, 1, 1);

        btnTanh = new QPushButton(verticalLayoutWidget);
        btnTanh->setObjectName(QString::fromUtf8("btnTanh"));
        sizePolicy.setHeightForWidth(btnTanh->sizePolicy().hasHeightForWidth());
        btnTanh->setSizePolicy(sizePolicy);
        btnTanh->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(btnTanh, 1, 2, 1, 1);

        btnLn = new QPushButton(verticalLayoutWidget);
        btnLn->setObjectName(QString::fromUtf8("btnLn"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnLn->sizePolicy().hasHeightForWidth());
        btnLn->setSizePolicy(sizePolicy1);
        btnLn->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(btnLn, 2, 0, 1, 1);

        btnLog = new QPushButton(verticalLayoutWidget);
        btnLog->setObjectName(QString::fromUtf8("btnLog"));
        sizePolicy1.setHeightForWidth(btnLog->sizePolicy().hasHeightForWidth());
        btnLog->setSizePolicy(sizePolicy1);
        btnLog->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(btnLog, 2, 1, 1, 1);

        btnInv = new QPushButton(verticalLayoutWidget);
        btnInv->setObjectName(QString::fromUtf8("btnInv"));
        sizePolicy.setHeightForWidth(btnInv->sizePolicy().hasHeightForWidth());
        btnInv->setSizePolicy(sizePolicy);
        btnInv->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(btnInv, 3, 0, 1, 1);

        btnSqrt = new QPushButton(verticalLayoutWidget);
        btnSqrt->setObjectName(QString::fromUtf8("btnSqrt"));
        sizePolicy.setHeightForWidth(btnSqrt->sizePolicy().hasHeightForWidth());
        btnSqrt->setSizePolicy(sizePolicy);
        btnSqrt->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(btnSqrt, 4, 0, 1, 1);

        btnSqr = new QPushButton(verticalLayoutWidget);
        btnSqr->setObjectName(QString::fromUtf8("btnSqr"));
        sizePolicy.setHeightForWidth(btnSqr->sizePolicy().hasHeightForWidth());
        btnSqr->setSizePolicy(sizePolicy);
        btnSqr->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(btnSqr, 4, 1, 1, 1);

        btnCube = new QPushButton(verticalLayoutWidget);
        btnCube->setObjectName(QString::fromUtf8("btnCube"));
        sizePolicy.setHeightForWidth(btnCube->sizePolicy().hasHeightForWidth());
        btnCube->setSizePolicy(sizePolicy);
        btnCube->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(btnCube, 4, 2, 1, 1);

        btnFactorielle = new QPushButton(verticalLayoutWidget);
        btnFactorielle->setObjectName(QString::fromUtf8("btnFactorielle"));
        sizePolicy.setHeightForWidth(btnFactorielle->sizePolicy().hasHeightForWidth());
        btnFactorielle->setSizePolicy(sizePolicy);
        btnFactorielle->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(btnFactorielle, 3, 1, 1, 1);

        btnEval = new QPushButton(verticalLayoutWidget);
        btnEval->setObjectName(QString::fromUtf8("btnEval"));
        sizePolicy.setHeightForWidth(btnEval->sizePolicy().hasHeightForWidth());
        btnEval->setSizePolicy(sizePolicy);
        btnEval->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(btnEval, 3, 2, 1, 1);


        verticalLayout_2->addLayout(gridLayout_3);


        horizontalLayout->addLayout(verticalLayout_2);

        line = new QFrame(verticalLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lastStack = new QLineEdit(verticalLayoutWidget);
        lastStack->setObjectName(QString::fromUtf8("lastStack"));
        lastStack->setEnabled(false);
        lastStack->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_3->addWidget(lastStack);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnSwap = new QPushButton(verticalLayoutWidget);
        btnSwap->setObjectName(QString::fromUtf8("btnSwap"));
        sizePolicy.setHeightForWidth(btnSwap->sizePolicy().hasHeightForWidth());
        btnSwap->setSizePolicy(sizePolicy);
        btnSwap->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(btnSwap);

        btnSum = new QPushButton(verticalLayoutWidget);
        btnSum->setObjectName(QString::fromUtf8("btnSum"));
        sizePolicy.setHeightForWidth(btnSum->sizePolicy().hasHeightForWidth());
        btnSum->setSizePolicy(sizePolicy);
        btnSum->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(btnSum);

        btnMean = new QPushButton(verticalLayoutWidget);
        btnMean->setObjectName(QString::fromUtf8("btnMean"));
        sizePolicy.setHeightForWidth(btnMean->sizePolicy().hasHeightForWidth());
        btnMean->setSizePolicy(sizePolicy);
        btnMean->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(btnMean);

        btnClear = new QPushButton(verticalLayoutWidget);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));
        sizePolicy.setHeightForWidth(btnClear->sizePolicy().hasHeightForWidth());
        btnClear->setSizePolicy(sizePolicy);
        btnClear->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(btnClear);

        btnDup = new QPushButton(verticalLayoutWidget);
        btnDup->setObjectName(QString::fromUtf8("btnDup"));
        sizePolicy.setHeightForWidth(btnDup->sizePolicy().hasHeightForWidth());
        btnDup->setSizePolicy(sizePolicy);
        btnDup->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(btnDup);

        btnDrop = new QPushButton(verticalLayoutWidget);
        btnDrop->setObjectName(QString::fromUtf8("btnDrop"));
        sizePolicy.setHeightForWidth(btnDrop->sizePolicy().hasHeightForWidth());
        btnDrop->setSizePolicy(sizePolicy);
        btnDrop->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(btnDrop);


        horizontalLayout_2->addLayout(verticalLayout);

        line_2 = new QFrame(verticalLayoutWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_2);

        listStack = new QListWidget(verticalLayoutWidget);
        listStack->setObjectName(QString::fromUtf8("listStack"));
        listStack->setEnabled(false);
        listStack->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(listStack);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 906, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        menuType_de_constantes = new QMenu(menuOptions);
        menuType_de_constantes->setObjectName(QString::fromUtf8("menuType_de_constantes"));
        menuUnit_des_degr_s = new QMenu(menuOptions);
        menuUnit_des_degr_s->setObjectName(QString::fromUtf8("menuUnit_des_degr_s"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuFichier->addAction(actionNouveau);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);
        menuOptions->addAction(menuType_de_constantes->menuAction());
        menuOptions->addAction(menuUnit_des_degr_s->menuAction());
        menuOptions->addAction(actionUtilisation_des_complexes);
        menuType_de_constantes->addAction(actionEntiers);
        menuType_de_constantes->addAction(actionR_els);
        menuType_de_constantes->addAction(actionRationnels);
        menuUnit_des_degr_s->addAction(actionDegr);
        menuUnit_des_degr_s->addAction(actionRadian);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionNouveau->setText(QApplication::translate("MainWindow", "Nouveau", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0, QApplication::UnicodeUTF8));
        actionEntiers->setText(QApplication::translate("MainWindow", "Entiers", 0, QApplication::UnicodeUTF8));
        actionR_els->setText(QApplication::translate("MainWindow", "R\303\251els", 0, QApplication::UnicodeUTF8));
        actionRationnels->setText(QApplication::translate("MainWindow", "Rationnels", 0, QApplication::UnicodeUTF8));
        actionDegr->setText(QApplication::translate("MainWindow", "Degr\303\251", 0, QApplication::UnicodeUTF8));
        actionRadian->setText(QApplication::translate("MainWindow", "Radian", 0, QApplication::UnicodeUTF8));
        actionUtilisation_des_complexes->setText(QApplication::translate("MainWindow", "Utilisation des complexes", 0, QApplication::UnicodeUTF8));
        btn7->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        btn7->setShortcut(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        btn8->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        btn8->setShortcut(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        btn9->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        btn9->setShortcut(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        btn4->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        btn4->setShortcut(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        btn5->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        btn5->setShortcut(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        btn6->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        btn6->setShortcut(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        btn1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        btn1->setShortcut(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        btn2->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        btn2->setShortcut(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        btn3->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        btn3->setShortcut(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        btnEnter->setText(QApplication::translate("MainWindow", "ENTER", 0, QApplication::UnicodeUTF8));
        btn0->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        btnDel->setText(QApplication::translate("MainWindow", "DEL", 0, QApplication::UnicodeUTF8));
        btnMoins->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        btnMultiplier->setText(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        btnDiviser->setText(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        btnMod->setText(QApplication::translate("MainWindow", "MOD", 0, QApplication::UnicodeUTF8));
        btnSign->setText(QApplication::translate("MainWindow", "SIGN", 0, QApplication::UnicodeUTF8));
        btnPlus->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        btnPow->setText(QApplication::translate("MainWindow", "POW", 0, QApplication::UnicodeUTF8));
        btnSin->setText(QApplication::translate("MainWindow", "SIN", 0, QApplication::UnicodeUTF8));
        btnCos->setText(QApplication::translate("MainWindow", "COS", 0, QApplication::UnicodeUTF8));
        btnTan->setText(QApplication::translate("MainWindow", "TAN", 0, QApplication::UnicodeUTF8));
        btnSinh->setText(QApplication::translate("MainWindow", "SINH", 0, QApplication::UnicodeUTF8));
        btnCosh->setText(QApplication::translate("MainWindow", "COSH", 0, QApplication::UnicodeUTF8));
        btnTanh->setText(QApplication::translate("MainWindow", "TANH", 0, QApplication::UnicodeUTF8));
        btnLn->setText(QApplication::translate("MainWindow", "LN", 0, QApplication::UnicodeUTF8));
        btnLog->setText(QApplication::translate("MainWindow", "LOG", 0, QApplication::UnicodeUTF8));
        btnInv->setText(QApplication::translate("MainWindow", "INV", 0, QApplication::UnicodeUTF8));
        btnSqrt->setText(QApplication::translate("MainWindow", "SQRT", 0, QApplication::UnicodeUTF8));
        btnSqr->setText(QApplication::translate("MainWindow", "SQR", 0, QApplication::UnicodeUTF8));
        btnCube->setText(QApplication::translate("MainWindow", "CUBE", 0, QApplication::UnicodeUTF8));
        btnFactorielle->setText(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        btnEval->setText(QApplication::translate("MainWindow", "EVAL", 0, QApplication::UnicodeUTF8));
        btnSwap->setText(QApplication::translate("MainWindow", "SWAP", 0, QApplication::UnicodeUTF8));
        btnSum->setText(QApplication::translate("MainWindow", "SUM", 0, QApplication::UnicodeUTF8));
        btnMean->setText(QApplication::translate("MainWindow", "MEAN", 0, QApplication::UnicodeUTF8));
        btnClear->setText(QApplication::translate("MainWindow", "CLEAR", 0, QApplication::UnicodeUTF8));
        btnClear->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        btnDup->setText(QApplication::translate("MainWindow", "DUP", 0, QApplication::UnicodeUTF8));
        btnDup->setShortcut(QApplication::translate("MainWindow", "Return", 0, QApplication::UnicodeUTF8));
        btnDrop->setText(QApplication::translate("MainWindow", "DROP", 0, QApplication::UnicodeUTF8));
        btnDrop->setShortcut(QApplication::translate("MainWindow", "Backspace", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0, QApplication::UnicodeUTF8));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", 0, QApplication::UnicodeUTF8));
        menuType_de_constantes->setTitle(QApplication::translate("MainWindow", "Type de constantes", 0, QApplication::UnicodeUTF8));
        menuUnit_des_degr_s->setTitle(QApplication::translate("MainWindow", "Unit\303\251 des degr\303\251s", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
