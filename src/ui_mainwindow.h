/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Jun 21 19:31:39 2012
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
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
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
    QAction *actionReels;
    QAction *actionRationnels;
    QAction *actionDegr;
    QAction *actionRadian;
    QAction *actionComplexes;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionMasquerOptionsAvancees;
    QAction *actionMasquerPile;
    QAction *actionMasquerClavier;
    QAction *actionMasquerTrigo;
    QAction *actionSauvegarder;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_3;
    QRadioButton *radioButtonEntier;
    QRadioButton *radioButtonReel;
    QRadioButton *radioButtonRationnel;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_lastRes;
    QLineEdit *lineEdit_lastRes;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_2;
    QPushButton *btn7;
    QPushButton *btn4;
    QPushButton *btn1;
    QPushButton *btn3;
    QPushButton *btn2;
    QPushButton *btn6;
    QPushButton *btn5;
    QPushButton *btn9;
    QPushButton *btn8;
    QPushButton *btnEnter;
    QPushButton *btn0;
    QPushButton *btnDel;
    QGridLayout *gridLayout_4;
    QFrame *line_5;
    QPushButton *btnEval;
    QPushButton *btnCube;
    QPushButton *btnSqr;
    QPushButton *btnSqrt;
    QPushButton *btnSpace;
    QPushButton *btnDollar;
    QPushButton *btnPlus;
    QPushButton *btnMoins;
    QPushButton *btnMultiplier;
    QPushButton *btnDiviser;
    QFrame *line_3;
    QVBoxLayout *verticalLayout_7;
    QGridLayout *gridLayout_3;
    QPushButton *btnMod;
    QPushButton *btnInv;
    QPushButton *btnSign;
    QPushButton *btnPow;
    QPushButton *btnLog;
    QPushButton *btnLn;
    QPushButton *btnSinh;
    QPushButton *btnSin;
    QPushButton *btnCos;
    QPushButton *btnCosh;
    QPushButton *btnTan;
    QPushButton *btnTanh;
    QLabel *labelAvance;
    QLabel *labelTrigo;
    QPushButton *btnFactorielle;
    QFrame *line_7;
    QFrame *line;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *lastStack;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_X;
    QLineEdit *lineEditX;
    QFrame *line_4;
    QLabel *label_Y;
    QLineEdit *lineEditY;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *btnSwap;
    QPushButton *btnSum;
    QPushButton *btnMean;
    QPushButton *btnClear;
    QPushButton *btnDup;
    QPushButton *btnDrop;
    QFrame *line_6;
    QSpinBox *spinBox;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_5;
    QListWidget *listStack;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuOptions;
    QMenu *menuUnit_des_degr_s;
    QMenu *menuEdition;
    QMenu *menuAffichage;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;
    QToolBar *toolBar_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(740, 547);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionNouveau = new QAction(MainWindow);
        actionNouveau->setObjectName(QString::fromUtf8("actionNouveau"));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionEntiers = new QAction(MainWindow);
        actionEntiers->setObjectName(QString::fromUtf8("actionEntiers"));
        actionEntiers->setCheckable(true);
        actionEntiers->setChecked(false);
        actionEntiers->setEnabled(true);
        actionReels = new QAction(MainWindow);
        actionReels->setObjectName(QString::fromUtf8("actionReels"));
        actionReels->setCheckable(true);
        actionRationnels = new QAction(MainWindow);
        actionRationnels->setObjectName(QString::fromUtf8("actionRationnels"));
        actionRationnels->setCheckable(true);
        actionDegr = new QAction(MainWindow);
        actionDegr->setObjectName(QString::fromUtf8("actionDegr"));
        actionDegr->setCheckable(true);
        actionDegr->setChecked(false);
        actionRadian = new QAction(MainWindow);
        actionRadian->setObjectName(QString::fromUtf8("actionRadian"));
        actionRadian->setCheckable(true);
        actionComplexes = new QAction(MainWindow);
        actionComplexes->setObjectName(QString::fromUtf8("actionComplexes"));
        actionComplexes->setCheckable(true);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        actionMasquerOptionsAvancees = new QAction(MainWindow);
        actionMasquerOptionsAvancees->setObjectName(QString::fromUtf8("actionMasquerOptionsAvancees"));
        actionMasquerOptionsAvancees->setCheckable(true);
        actionMasquerPile = new QAction(MainWindow);
        actionMasquerPile->setObjectName(QString::fromUtf8("actionMasquerPile"));
        actionMasquerPile->setCheckable(true);
        actionMasquerClavier = new QAction(MainWindow);
        actionMasquerClavier->setObjectName(QString::fromUtf8("actionMasquerClavier"));
        actionMasquerClavier->setCheckable(true);
        actionMasquerTrigo = new QAction(MainWindow);
        actionMasquerTrigo->setObjectName(QString::fromUtf8("actionMasquerTrigo"));
        actionMasquerTrigo->setCheckable(true);
        actionSauvegarder = new QAction(MainWindow);
        actionSauvegarder->setObjectName(QString::fromUtf8("actionSauvegarder"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_5 = new QHBoxLayout(centralWidget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_7->addWidget(label_3);

        radioButtonEntier = new QRadioButton(centralWidget);
        radioButtonEntier->setObjectName(QString::fromUtf8("radioButtonEntier"));
        radioButtonEntier->setChecked(true);

        horizontalLayout_7->addWidget(radioButtonEntier);

        radioButtonReel = new QRadioButton(centralWidget);
        radioButtonReel->setObjectName(QString::fromUtf8("radioButtonReel"));

        horizontalLayout_7->addWidget(radioButtonReel);

        radioButtonRationnel = new QRadioButton(centralWidget);
        radioButtonRationnel->setObjectName(QString::fromUtf8("radioButtonRationnel"));

        horizontalLayout_7->addWidget(radioButtonRationnel);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font;
        font.setPointSize(16);
        label_4->setFont(font);

        horizontalLayout_8->addWidget(label_4);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaximumSize(QSize(16777215, 16777215));
        lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(lineEdit);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_lastRes = new QLabel(centralWidget);
        label_lastRes->setObjectName(QString::fromUtf8("label_lastRes"));
        label_lastRes->setFont(font);

        horizontalLayout_9->addWidget(label_lastRes);

        lineEdit_lastRes = new QLineEdit(centralWidget);
        lineEdit_lastRes->setObjectName(QString::fromUtf8("lineEdit_lastRes"));
        lineEdit_lastRes->setEnabled(false);
        lineEdit_lastRes->setLayoutDirection(Qt::LeftToRight);
        lineEdit_lastRes->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEdit_lastRes->setReadOnly(false);

        horizontalLayout_9->addWidget(lineEdit_lastRes);


        verticalLayout_2->addLayout(horizontalLayout_9);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        btn7 = new QPushButton(centralWidget);
        btn7->setObjectName(QString::fromUtf8("btn7"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn7->sizePolicy().hasHeightForWidth());
        btn7->setSizePolicy(sizePolicy);
        btn7->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(btn7, 0, 0, 1, 1);

        btn4 = new QPushButton(centralWidget);
        btn4->setObjectName(QString::fromUtf8("btn4"));
        sizePolicy.setHeightForWidth(btn4->sizePolicy().hasHeightForWidth());
        btn4->setSizePolicy(sizePolicy);
        btn4->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(btn4, 1, 0, 1, 1);

        btn1 = new QPushButton(centralWidget);
        btn1->setObjectName(QString::fromUtf8("btn1"));
        sizePolicy.setHeightForWidth(btn1->sizePolicy().hasHeightForWidth());
        btn1->setSizePolicy(sizePolicy);
        btn1->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(btn1, 2, 0, 1, 1);

        btn3 = new QPushButton(centralWidget);
        btn3->setObjectName(QString::fromUtf8("btn3"));
        sizePolicy.setHeightForWidth(btn3->sizePolicy().hasHeightForWidth());
        btn3->setSizePolicy(sizePolicy);
        btn3->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(btn3, 2, 3, 1, 1);

        btn2 = new QPushButton(centralWidget);
        btn2->setObjectName(QString::fromUtf8("btn2"));
        sizePolicy.setHeightForWidth(btn2->sizePolicy().hasHeightForWidth());
        btn2->setSizePolicy(sizePolicy);
        btn2->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(btn2, 2, 2, 1, 1);

        btn6 = new QPushButton(centralWidget);
        btn6->setObjectName(QString::fromUtf8("btn6"));
        sizePolicy.setHeightForWidth(btn6->sizePolicy().hasHeightForWidth());
        btn6->setSizePolicy(sizePolicy);
        btn6->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(btn6, 1, 3, 1, 1);

        btn5 = new QPushButton(centralWidget);
        btn5->setObjectName(QString::fromUtf8("btn5"));
        sizePolicy.setHeightForWidth(btn5->sizePolicy().hasHeightForWidth());
        btn5->setSizePolicy(sizePolicy);
        btn5->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(btn5, 1, 2, 1, 1);

        btn9 = new QPushButton(centralWidget);
        btn9->setObjectName(QString::fromUtf8("btn9"));
        sizePolicy.setHeightForWidth(btn9->sizePolicy().hasHeightForWidth());
        btn9->setSizePolicy(sizePolicy);
        btn9->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(btn9, 0, 3, 1, 1);

        btn8 = new QPushButton(centralWidget);
        btn8->setObjectName(QString::fromUtf8("btn8"));
        sizePolicy.setHeightForWidth(btn8->sizePolicy().hasHeightForWidth());
        btn8->setSizePolicy(sizePolicy);
        btn8->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(btn8, 0, 2, 1, 1);

        btnEnter = new QPushButton(centralWidget);
        btnEnter->setObjectName(QString::fromUtf8("btnEnter"));
        sizePolicy.setHeightForWidth(btnEnter->sizePolicy().hasHeightForWidth());
        btnEnter->setSizePolicy(sizePolicy);
        btnEnter->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        btnEnter->setFont(font1);

        gridLayout_2->addWidget(btnEnter, 3, 3, 1, 1);

        btn0 = new QPushButton(centralWidget);
        btn0->setObjectName(QString::fromUtf8("btn0"));
        sizePolicy.setHeightForWidth(btn0->sizePolicy().hasHeightForWidth());
        btn0->setSizePolicy(sizePolicy);
        btn0->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_2->addWidget(btn0, 3, 2, 1, 1);

        btnDel = new QPushButton(centralWidget);
        btnDel->setObjectName(QString::fromUtf8("btnDel"));
        sizePolicy.setHeightForWidth(btnDel->sizePolicy().hasHeightForWidth());
        btnDel->setSizePolicy(sizePolicy);
        btnDel->setMaximumSize(QSize(16777215, 16777215));
        btnDel->setFont(font1);

        gridLayout_2->addWidget(btnDel, 3, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 1, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setLineWidth(1);
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout_4->addWidget(line_5, 0, 0, 5, 1);

        btnEval = new QPushButton(centralWidget);
        btnEval->setObjectName(QString::fromUtf8("btnEval"));
        btnEval->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(btnEval, 4, 2, 1, 1);

        btnCube = new QPushButton(centralWidget);
        btnCube->setObjectName(QString::fromUtf8("btnCube"));
        btnCube->setMaximumSize(QSize(16777215, 16777215));
        QFont font2;
        font2.setBold(false);
        font2.setItalic(true);
        font2.setWeight(50);
        btnCube->setFont(font2);

        gridLayout_4->addWidget(btnCube, 2, 2, 1, 1);

        btnSqr = new QPushButton(centralWidget);
        btnSqr->setObjectName(QString::fromUtf8("btnSqr"));
        btnSqr->setMaximumSize(QSize(16777215, 16777215));
        btnSqr->setFont(font2);

        gridLayout_4->addWidget(btnSqr, 1, 2, 1, 1);

        btnSqrt = new QPushButton(centralWidget);
        btnSqrt->setObjectName(QString::fromUtf8("btnSqrt"));
        btnSqrt->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(btnSqrt, 0, 2, 1, 1);

        btnSpace = new QPushButton(centralWidget);
        btnSpace->setObjectName(QString::fromUtf8("btnSpace"));

        gridLayout_4->addWidget(btnSpace, 3, 2, 1, 1);

        btnDollar = new QPushButton(centralWidget);
        btnDollar->setObjectName(QString::fromUtf8("btnDollar"));

        gridLayout_4->addWidget(btnDollar, 4, 1, 1, 1);

        btnPlus = new QPushButton(centralWidget);
        btnPlus->setObjectName(QString::fromUtf8("btnPlus"));
        sizePolicy.setHeightForWidth(btnPlus->sizePolicy().hasHeightForWidth());
        btnPlus->setSizePolicy(sizePolicy);
        btnPlus->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(btnPlus, 0, 1, 1, 1);

        btnMoins = new QPushButton(centralWidget);
        btnMoins->setObjectName(QString::fromUtf8("btnMoins"));
        sizePolicy.setHeightForWidth(btnMoins->sizePolicy().hasHeightForWidth());
        btnMoins->setSizePolicy(sizePolicy);
        btnMoins->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(btnMoins, 1, 1, 1, 1);

        btnMultiplier = new QPushButton(centralWidget);
        btnMultiplier->setObjectName(QString::fromUtf8("btnMultiplier"));
        sizePolicy.setHeightForWidth(btnMultiplier->sizePolicy().hasHeightForWidth());
        btnMultiplier->setSizePolicy(sizePolicy);
        btnMultiplier->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(btnMultiplier, 2, 1, 1, 1);

        btnDiviser = new QPushButton(centralWidget);
        btnDiviser->setObjectName(QString::fromUtf8("btnDiviser"));
        sizePolicy.setHeightForWidth(btnDiviser->sizePolicy().hasHeightForWidth());
        btnDiviser->setSizePolicy(sizePolicy);
        btnDiviser->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_4->addWidget(btnDiviser, 3, 1, 1, 1);


        gridLayout->addLayout(gridLayout_4, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_3);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        btnMod = new QPushButton(centralWidget);
        btnMod->setObjectName(QString::fromUtf8("btnMod"));
        sizePolicy.setHeightForWidth(btnMod->sizePolicy().hasHeightForWidth());
        btnMod->setSizePolicy(sizePolicy);
        btnMod->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(btnMod, 1, 0, 1, 1);

        btnInv = new QPushButton(centralWidget);
        btnInv->setObjectName(QString::fromUtf8("btnInv"));
        btnInv->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(btnInv, 2, 2, 1, 1);

        btnSign = new QPushButton(centralWidget);
        btnSign->setObjectName(QString::fromUtf8("btnSign"));
        sizePolicy.setHeightForWidth(btnSign->sizePolicy().hasHeightForWidth());
        btnSign->setSizePolicy(sizePolicy);
        btnSign->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(btnSign, 1, 2, 1, 1);

        btnPow = new QPushButton(centralWidget);
        btnPow->setObjectName(QString::fromUtf8("btnPow"));
        sizePolicy.setHeightForWidth(btnPow->sizePolicy().hasHeightForWidth());
        btnPow->setSizePolicy(sizePolicy);
        btnPow->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(btnPow, 1, 1, 1, 1);

        btnLog = new QPushButton(centralWidget);
        btnLog->setObjectName(QString::fromUtf8("btnLog"));
        btnLog->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(btnLog, 2, 1, 1, 1);

        btnLn = new QPushButton(centralWidget);
        btnLn->setObjectName(QString::fromUtf8("btnLn"));
        btnLn->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(btnLn, 2, 0, 1, 1);

        btnSinh = new QPushButton(centralWidget);
        btnSinh->setObjectName(QString::fromUtf8("btnSinh"));
        btnSinh->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(btnSinh, 6, 0, 1, 1);

        btnSin = new QPushButton(centralWidget);
        btnSin->setObjectName(QString::fromUtf8("btnSin"));
        btnSin->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(btnSin, 5, 0, 1, 1);

        btnCos = new QPushButton(centralWidget);
        btnCos->setObjectName(QString::fromUtf8("btnCos"));
        btnCos->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(btnCos, 5, 1, 1, 1);

        btnCosh = new QPushButton(centralWidget);
        btnCosh->setObjectName(QString::fromUtf8("btnCosh"));
        btnCosh->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(btnCosh, 6, 1, 1, 1);

        btnTan = new QPushButton(centralWidget);
        btnTan->setObjectName(QString::fromUtf8("btnTan"));
        btnTan->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(btnTan, 5, 2, 1, 1);

        btnTanh = new QPushButton(centralWidget);
        btnTanh->setObjectName(QString::fromUtf8("btnTanh"));
        btnTanh->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(btnTanh, 6, 2, 1, 1);

        labelAvance = new QLabel(centralWidget);
        labelAvance->setObjectName(QString::fromUtf8("labelAvance"));
        QFont font3;
        font3.setItalic(true);
        labelAvance->setFont(font3);

        gridLayout_3->addWidget(labelAvance, 0, 0, 1, 3);

        labelTrigo = new QLabel(centralWidget);
        labelTrigo->setObjectName(QString::fromUtf8("labelTrigo"));
        labelTrigo->setFont(font3);

        gridLayout_3->addWidget(labelTrigo, 4, 0, 1, 3);

        btnFactorielle = new QPushButton(centralWidget);
        btnFactorielle->setObjectName(QString::fromUtf8("btnFactorielle"));
        btnFactorielle->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(btnFactorielle, 1, 3, 1, 1);

        line_7 = new QFrame(centralWidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_7, 3, 0, 1, 5);


        verticalLayout_7->addLayout(gridLayout_3);


        verticalLayout_2->addLayout(verticalLayout_7);


        horizontalLayout->addLayout(verticalLayout_2);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        lastStack = new QLineEdit(centralWidget);
        lastStack->setObjectName(QString::fromUtf8("lastStack"));
        lastStack->setEnabled(false);
        lastStack->setMaximumSize(QSize(16777215, 16777215));
        lastStack->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(lastStack);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_X = new QLabel(centralWidget);
        label_X->setObjectName(QString::fromUtf8("label_X"));

        horizontalLayout_3->addWidget(label_X);

        lineEditX = new QLineEdit(centralWidget);
        lineEditX->setObjectName(QString::fromUtf8("lineEditX"));

        horizontalLayout_3->addWidget(lineEditX);

        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_4);

        label_Y = new QLabel(centralWidget);
        label_Y->setObjectName(QString::fromUtf8("label_Y"));

        horizontalLayout_3->addWidget(label_Y);

        lineEditY = new QLineEdit(centralWidget);
        lineEditY->setObjectName(QString::fromUtf8("lineEditY"));

        horizontalLayout_3->addWidget(lineEditY);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        btnSwap = new QPushButton(centralWidget);
        btnSwap->setObjectName(QString::fromUtf8("btnSwap"));
        btnSwap->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(btnSwap);

        btnSum = new QPushButton(centralWidget);
        btnSum->setObjectName(QString::fromUtf8("btnSum"));
        btnSum->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(btnSum);

        btnMean = new QPushButton(centralWidget);
        btnMean->setObjectName(QString::fromUtf8("btnMean"));
        btnMean->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(btnMean);

        btnClear = new QPushButton(centralWidget);
        btnClear->setObjectName(QString::fromUtf8("btnClear"));
        btnClear->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(btnClear);

        btnDup = new QPushButton(centralWidget);
        btnDup->setObjectName(QString::fromUtf8("btnDup"));
        btnDup->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(btnDup);

        btnDrop = new QPushButton(centralWidget);
        btnDrop->setObjectName(QString::fromUtf8("btnDrop"));
        btnDrop->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(btnDrop);

        line_6 = new QFrame(centralWidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_6);

        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setValue(10);

        verticalLayout->addWidget(spinBox);


        horizontalLayout_2->addLayout(verticalLayout);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        listStack = new QListWidget(centralWidget);
        listStack->setObjectName(QString::fromUtf8("listStack"));
        listStack->setEnabled(false);
        listStack->setMaximumSize(QSize(16777215, 16777215));
        listStack->setLayoutDirection(Qt::LeftToRight);

        verticalLayout_5->addWidget(listStack);


        horizontalLayout_2->addLayout(verticalLayout_5);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout_3);


        horizontalLayout_6->addLayout(horizontalLayout);


        horizontalLayout_5->addLayout(horizontalLayout_6);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 740, 25));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        menuUnit_des_degr_s = new QMenu(menuOptions);
        menuUnit_des_degr_s->setObjectName(QString::fromUtf8("menuUnit_des_degr_s"));
        menuEdition = new QMenu(menuBar);
        menuEdition->setObjectName(QString::fromUtf8("menuEdition"));
        menuAffichage = new QMenu(menuBar);
        menuAffichage->setObjectName(QString::fromUtf8("menuAffichage"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);
        toolBar_3 = new QToolBar(MainWindow);
        toolBar_3->setObjectName(QString::fromUtf8("toolBar_3"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_3);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuEdition->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuBar->addAction(menuAffichage->menuAction());
        menuFichier->addAction(actionNouveau);
        menuFichier->addSeparator();
        menuFichier->addAction(actionSauvegarder);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuitter);
        menuFichier->addSeparator();
        menuOptions->addSeparator();
        menuOptions->addAction(menuUnit_des_degr_s->menuAction());
        menuOptions->addSeparator();
        menuOptions->addAction(actionComplexes);
        menuOptions->addSeparator();
        menuUnit_des_degr_s->addAction(actionRadian);
        menuUnit_des_degr_s->addSeparator();
        menuUnit_des_degr_s->addAction(actionDegr);
        menuUnit_des_degr_s->addSeparator();
        menuEdition->addAction(actionUndo);
        menuEdition->addSeparator();
        menuEdition->addAction(actionRedo);
        menuEdition->addSeparator();
        menuAffichage->addAction(actionMasquerOptionsAvancees);
        menuAffichage->addSeparator();
        menuAffichage->addAction(actionMasquerTrigo);
        menuAffichage->addSeparator();
        menuAffichage->addAction(actionMasquerPile);
        menuAffichage->addSeparator();
        menuAffichage->addAction(actionMasquerClavier);
        menuAffichage->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Calculatrice - Notation Polonaise Invers\303\251e", 0, QApplication::UnicodeUTF8));
        actionNouveau->setText(QApplication::translate("MainWindow", "Nouveau", 0, QApplication::UnicodeUTF8));
        actionNouveau->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+N", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0, QApplication::UnicodeUTF8));
        actionQuitter->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionEntiers->setText(QApplication::translate("MainWindow", "Entiers", 0, QApplication::UnicodeUTF8));
        actionReels->setText(QApplication::translate("MainWindow", "R\303\251els", 0, QApplication::UnicodeUTF8));
        actionRationnels->setText(QApplication::translate("MainWindow", "Rationnels", 0, QApplication::UnicodeUTF8));
        actionDegr->setText(QApplication::translate("MainWindow", "Degr\303\251", 0, QApplication::UnicodeUTF8));
        actionRadian->setText(QApplication::translate("MainWindow", "Radian", 0, QApplication::UnicodeUTF8));
        actionComplexes->setText(QApplication::translate("MainWindow", "Utilisation des complexes", 0, QApplication::UnicodeUTF8));
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", 0, QApplication::UnicodeUTF8));
        actionUndo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", 0, QApplication::UnicodeUTF8));
        actionRedo->setShortcut(QApplication::translate("MainWindow", "Ctrl+Y", 0, QApplication::UnicodeUTF8));
        actionMasquerOptionsAvancees->setText(QApplication::translate("MainWindow", "Masquer les options avanc\303\251es", 0, QApplication::UnicodeUTF8));
        actionMasquerPile->setText(QApplication::translate("MainWindow", "Masquer la pile", 0, QApplication::UnicodeUTF8));
        actionMasquerClavier->setText(QApplication::translate("MainWindow", "Masquer le clavier", 0, QApplication::UnicodeUTF8));
        actionMasquerTrigo->setText(QApplication::translate("MainWindow", "Masquer les fonctions trigonom\303\251triques", 0, QApplication::UnicodeUTF8));
        actionSauvegarder->setText(QApplication::translate("MainWindow", "Sauvegarder", 0, QApplication::UnicodeUTF8));
        actionSauvegarder->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Type de constantes : ", 0, QApplication::UnicodeUTF8));
        radioButtonEntier->setText(QApplication::translate("MainWindow", "Enti\303\250res", 0, QApplication::UnicodeUTF8));
        radioButtonReel->setText(QApplication::translate("MainWindow", "R\303\251elles", 0, QApplication::UnicodeUTF8));
        radioButtonRationnel->setText(QApplication::translate("MainWindow", "Rationnelles", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", ">", 0, QApplication::UnicodeUTF8));
        label_lastRes->setText(QApplication::translate("MainWindow", "<", 0, QApplication::UnicodeUTF8));
        btn7->setText(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        btn7->setShortcut(QApplication::translate("MainWindow", "7", 0, QApplication::UnicodeUTF8));
        btn4->setText(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        btn4->setShortcut(QApplication::translate("MainWindow", "4", 0, QApplication::UnicodeUTF8));
        btn1->setText(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        btn1->setShortcut(QApplication::translate("MainWindow", "1", 0, QApplication::UnicodeUTF8));
        btn3->setText(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        btn3->setShortcut(QApplication::translate("MainWindow", "3", 0, QApplication::UnicodeUTF8));
        btn2->setText(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        btn2->setShortcut(QApplication::translate("MainWindow", "2", 0, QApplication::UnicodeUTF8));
        btn6->setText(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        btn6->setShortcut(QApplication::translate("MainWindow", "6", 0, QApplication::UnicodeUTF8));
        btn5->setText(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        btn5->setShortcut(QApplication::translate("MainWindow", "5", 0, QApplication::UnicodeUTF8));
        btn9->setText(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        btn9->setShortcut(QApplication::translate("MainWindow", "9", 0, QApplication::UnicodeUTF8));
        btn8->setText(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        btn8->setShortcut(QApplication::translate("MainWindow", "8", 0, QApplication::UnicodeUTF8));
        btnEnter->setText(QApplication::translate("MainWindow", "\342\206\262", 0, QApplication::UnicodeUTF8));
        btnEnter->setShortcut(QApplication::translate("MainWindow", "Enter", 0, QApplication::UnicodeUTF8));
        btn0->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        btn0->setShortcut(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        btnDel->setText(QApplication::translate("MainWindow", "\342\206\220", 0, QApplication::UnicodeUTF8));
        btnDel->setShortcut(QApplication::translate("MainWindow", "Backspace", 0, QApplication::UnicodeUTF8));
        btnEval->setText(QApplication::translate("MainWindow", "EVAL", 0, QApplication::UnicodeUTF8));
        btnCube->setText(QApplication::translate("MainWindow", "x\302\263", 0, QApplication::UnicodeUTF8));
        btnSqr->setText(QApplication::translate("MainWindow", "x\302\262", 0, QApplication::UnicodeUTF8));
        btnSqr->setShortcut(QApplication::translate("MainWindow", "\302\262", 0, QApplication::UnicodeUTF8));
        btnSqrt->setText(QApplication::translate("MainWindow", "\342\210\232", 0, QApplication::UnicodeUTF8));
        btnSpace->setText(QApplication::translate("MainWindow", "\342\214\264", 0, QApplication::UnicodeUTF8));
        btnSpace->setShortcut(QApplication::translate("MainWindow", "Space", 0, QApplication::UnicodeUTF8));
        btnDollar->setText(QApplication::translate("MainWindow", "$", 0, QApplication::UnicodeUTF8));
        btnDollar->setShortcut(QApplication::translate("MainWindow", "$", 0, QApplication::UnicodeUTF8));
        btnPlus->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        btnPlus->setShortcut(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        btnMoins->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        btnMoins->setShortcut(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        btnMultiplier->setText(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        btnMultiplier->setShortcut(QApplication::translate("MainWindow", "*", 0, QApplication::UnicodeUTF8));
        btnDiviser->setText(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        btnDiviser->setShortcut(QApplication::translate("MainWindow", "/", 0, QApplication::UnicodeUTF8));
        btnMod->setText(QApplication::translate("MainWindow", "MOD", 0, QApplication::UnicodeUTF8));
        btnInv->setText(QApplication::translate("MainWindow", "INV", 0, QApplication::UnicodeUTF8));
        btnSign->setText(QApplication::translate("MainWindow", "SIGN", 0, QApplication::UnicodeUTF8));
        btnPow->setText(QApplication::translate("MainWindow", "POW", 0, QApplication::UnicodeUTF8));
        btnLog->setText(QApplication::translate("MainWindow", "LOG", 0, QApplication::UnicodeUTF8));
        btnLn->setText(QApplication::translate("MainWindow", "LN", 0, QApplication::UnicodeUTF8));
        btnSinh->setText(QApplication::translate("MainWindow", "SINH", 0, QApplication::UnicodeUTF8));
        btnSin->setText(QApplication::translate("MainWindow", "SIN", 0, QApplication::UnicodeUTF8));
        btnCos->setText(QApplication::translate("MainWindow", "COS", 0, QApplication::UnicodeUTF8));
        btnCosh->setText(QApplication::translate("MainWindow", "COSH", 0, QApplication::UnicodeUTF8));
        btnTan->setText(QApplication::translate("MainWindow", "TAN", 0, QApplication::UnicodeUTF8));
        btnTanh->setText(QApplication::translate("MainWindow", "TANH", 0, QApplication::UnicodeUTF8));
        labelAvance->setText(QApplication::translate("MainWindow", "Mode Avanc\303\251", 0, QApplication::UnicodeUTF8));
        labelTrigo->setText(QApplication::translate("MainWindow", "Mode Trigonom\303\251trique", 0, QApplication::UnicodeUTF8));
        btnFactorielle->setText(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        btnFactorielle->setShortcut(QApplication::translate("MainWindow", "!", 0, QApplication::UnicodeUTF8));
        label_X->setText(QApplication::translate("MainWindow", " X:", 0, QApplication::UnicodeUTF8));
        label_Y->setText(QApplication::translate("MainWindow", "Y:", 0, QApplication::UnicodeUTF8));
        btnSwap->setText(QApplication::translate("MainWindow", "SWAP(X,Y)", 0, QApplication::UnicodeUTF8));
        btnSum->setText(QApplication::translate("MainWindow", "SUM(X)", 0, QApplication::UnicodeUTF8));
        btnMean->setText(QApplication::translate("MainWindow", "MEAN(X)", 0, QApplication::UnicodeUTF8));
        btnClear->setText(QApplication::translate("MainWindow", "CLEAR", 0, QApplication::UnicodeUTF8));
        btnClear->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        btnDup->setText(QApplication::translate("MainWindow", "DUP", 0, QApplication::UnicodeUTF8));
        btnDup->setShortcut(QApplication::translate("MainWindow", "Return", 0, QApplication::UnicodeUTF8));
        btnDrop->setText(QApplication::translate("MainWindow", "DROP", 0, QApplication::UnicodeUTF8));
        btnDrop->setShortcut(QApplication::translate("MainWindow", "Backspace", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0, QApplication::UnicodeUTF8));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", 0, QApplication::UnicodeUTF8));
        menuUnit_des_degr_s->setTitle(QApplication::translate("MainWindow", "Unit\303\251 des degr\303\251s", 0, QApplication::UnicodeUTF8));
        menuEdition->setTitle(QApplication::translate("MainWindow", "Edition", 0, QApplication::UnicodeUTF8));
        menuAffichage->setTitle(QApplication::translate("MainWindow", "Affichage", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
        toolBar_2->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", 0, QApplication::UnicodeUTF8));
        toolBar_3->setWindowTitle(QApplication::translate("MainWindow", "toolBar_3", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
