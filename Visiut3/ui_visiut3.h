/********************************************************************************
** Form generated from reading UI file 'visiut3.ui'
**
** Created: Sun Feb 17 23:55:07 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISIUT3_H
#define UI_VISIUT3_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Visiut3
{
public:
    QAction *ActionNew;
    QAction *ActionOpen;
    QAction *ActionQuitter;
    QAction *ActionMirror;
    QAction *actionPropriete;
    QAction *ActionNegative;
    QAction *ActionSave;
    QAction *actionAbout;
    QAction *actionEffacer;
    QAction *actionSuppression;
    QAction *ActionCancel;
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuNew;
    QMenu *menuFiltres;
    QMenu *menuOutils;
    QMenu *menuEdition;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Visiut3)
    {
        if (Visiut3->objectName().isEmpty())
            Visiut3->setObjectName(QString::fromUtf8("Visiut3"));
        Visiut3->resize(933, 607);
        ActionNew = new QAction(Visiut3);
        ActionNew->setObjectName(QString::fromUtf8("ActionNew"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("Icone/page_white_add.png"), QSize(), QIcon::Normal, QIcon::On);
        ActionNew->setIcon(icon);
        ActionOpen = new QAction(Visiut3);
        ActionOpen->setObjectName(QString::fromUtf8("ActionOpen"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("Icone/folder_add.png"), QSize(), QIcon::Normal, QIcon::On);
        ActionOpen->setIcon(icon1);
        ActionQuitter = new QAction(Visiut3);
        ActionQuitter->setObjectName(QString::fromUtf8("ActionQuitter"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("Icone/door_in.png"), QSize(), QIcon::Normal, QIcon::On);
        ActionQuitter->setIcon(icon2);
        ActionMirror = new QAction(Visiut3);
        ActionMirror->setObjectName(QString::fromUtf8("ActionMirror"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("Icone/shading.png"), QSize(), QIcon::Disabled, QIcon::Off);
        ActionMirror->setIcon(icon3);
        actionPropriete = new QAction(Visiut3);
        actionPropriete->setObjectName(QString::fromUtf8("actionPropriete"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("Icone/help.png"), QSize(), QIcon::Normal, QIcon::On);
        actionPropriete->setIcon(icon4);
        ActionNegative = new QAction(Visiut3);
        ActionNegative->setObjectName(QString::fromUtf8("ActionNegative"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("Icone/color_wheel.png"), QSize(), QIcon::Normal, QIcon::On);
        ActionNegative->setIcon(icon5);
        ActionSave = new QAction(Visiut3);
        ActionSave->setObjectName(QString::fromUtf8("ActionSave"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("Icone/bullet_disk.png"), QSize(), QIcon::Normal, QIcon::On);
        ActionSave->setIcon(icon6);
        actionAbout = new QAction(Visiut3);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("Icone/heart.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon7);
        actionEffacer = new QAction(Visiut3);
        actionEffacer->setObjectName(QString::fromUtf8("actionEffacer"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("Icone/cancel.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEffacer->setIcon(icon8);
        actionSuppression = new QAction(Visiut3);
        actionSuppression->setObjectName(QString::fromUtf8("actionSuppression"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("Icone/cross.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSuppression->setIcon(icon9);
        ActionCancel = new QAction(Visiut3);
        ActionCancel->setObjectName(QString::fromUtf8("ActionCancel"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8("Icone/arrow_turn_left.png"), QSize(), QIcon::Normal, QIcon::Off);
        ActionCancel->setIcon(icon10);
        centralWidget = new QWidget(Visiut3);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 821, 511));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setMinimumSize(QSize(0, 192));
        graphicsView->setMouseTracking(true);
        graphicsView->setFrameShape(QFrame::StyledPanel);
        graphicsView->setFrameShadow(QFrame::Plain);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        QBrush brush(QColor(255, 255, 255, 0));
        brush.setStyle(Qt::NoBrush);
        graphicsView->setBackgroundBrush(brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::NoBrush);
        graphicsView->setForegroundBrush(brush1);
        graphicsView->setInteractive(true);
        graphicsView->setAlignment(Qt::AlignCenter);
        graphicsView->setRenderHints(QPainter::TextAntialiasing);
        graphicsView->setDragMode(QGraphicsView::NoDrag);
        graphicsView->setResizeAnchor(QGraphicsView::NoAnchor);
        Visiut3->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Visiut3);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 933, 20));
        menuNew = new QMenu(menuBar);
        menuNew->setObjectName(QString::fromUtf8("menuNew"));
        menuFiltres = new QMenu(menuBar);
        menuFiltres->setObjectName(QString::fromUtf8("menuFiltres"));
        menuOutils = new QMenu(menuBar);
        menuOutils->setObjectName(QString::fromUtf8("menuOutils"));
        menuEdition = new QMenu(menuBar);
        menuEdition->setObjectName(QString::fromUtf8("menuEdition"));
        Visiut3->setMenuBar(menuBar);
        statusBar = new QStatusBar(Visiut3);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Visiut3->setStatusBar(statusBar);
        toolBar = new QToolBar(Visiut3);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        Visiut3->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuNew->menuAction());
        menuBar->addAction(menuEdition->menuAction());
        menuBar->addAction(menuFiltres->menuAction());
        menuBar->addAction(menuOutils->menuAction());
        menuNew->addAction(ActionNew);
        menuNew->addAction(ActionOpen);
        menuNew->addAction(ActionSave);
        menuNew->addAction(ActionQuitter);
        menuFiltres->addAction(ActionNegative);
        menuFiltres->addAction(ActionMirror);
        menuEdition->addAction(ActionCancel);
        toolBar->addAction(ActionNew);
        toolBar->addAction(ActionOpen);
        toolBar->addAction(ActionSave);
        toolBar->addSeparator();
        toolBar->addAction(ActionNegative);
        toolBar->addAction(ActionMirror);
        toolBar->addSeparator();
        toolBar->addAction(ActionCancel);
        toolBar->addAction(actionAbout);
        toolBar->addSeparator();

        retranslateUi(Visiut3);
        QObject::connect(ActionQuitter, SIGNAL(triggered()), Visiut3, SLOT(close()));

        QMetaObject::connectSlotsByName(Visiut3);
    } // setupUi

    void retranslateUi(QMainWindow *Visiut3)
    {
        Visiut3->setWindowTitle(QApplication::translate("Visiut3", "VisIUT 3", 0, QApplication::UnicodeUTF8));
        ActionNew->setText(QApplication::translate("Visiut3", "New", 0, QApplication::UnicodeUTF8));
        ActionNew->setShortcut(QApplication::translate("Visiut3", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        ActionOpen->setText(QApplication::translate("Visiut3", "Ouvrir", 0, QApplication::UnicodeUTF8));
        ActionOpen->setIconText(QApplication::translate("Visiut3", "Ouvrir", 0, QApplication::UnicodeUTF8));
        ActionOpen->setShortcut(QApplication::translate("Visiut3", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        ActionQuitter->setText(QApplication::translate("Visiut3", "Quitter", 0, QApplication::UnicodeUTF8));
        ActionQuitter->setShortcut(QApplication::translate("Visiut3", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        ActionMirror->setText(QApplication::translate("Visiut3", "Mirroir", 0, QApplication::UnicodeUTF8));
        ActionMirror->setShortcut(QApplication::translate("Visiut3", "Ctrl+M", 0, QApplication::UnicodeUTF8));
        actionPropriete->setText(QApplication::translate("Visiut3", "Proprietes", 0, QApplication::UnicodeUTF8));
        actionPropriete->setShortcut(QApplication::translate("Visiut3", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        ActionNegative->setText(QApplication::translate("Visiut3", "Negatif", 0, QApplication::UnicodeUTF8));
        ActionNegative->setShortcut(QApplication::translate("Visiut3", "Ctrl+I", 0, QApplication::UnicodeUTF8));
        ActionSave->setText(QApplication::translate("Visiut3", "Enregistrer", 0, QApplication::UnicodeUTF8));
        ActionSave->setShortcut(QApplication::translate("Visiut3", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("Visiut3", "about", 0, QApplication::UnicodeUTF8));
        actionAbout->setShortcut(QApplication::translate("Visiut3", "Ctrl+A", 0, QApplication::UnicodeUTF8));
        actionEffacer->setText(QApplication::translate("Visiut3", "Effacer", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionEffacer->setToolTip(QApplication::translate("Visiut3", "Effacer l'image courante", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionEffacer->setShortcut(QApplication::translate("Visiut3", "Ctrl+E", 0, QApplication::UnicodeUTF8));
        actionSuppression->setText(QApplication::translate("Visiut3", "Suppression d\303\251finitive", 0, QApplication::UnicodeUTF8));
        ActionCancel->setText(QApplication::translate("Visiut3", "Annuler", 0, QApplication::UnicodeUTF8));
        ActionCancel->setShortcut(QApplication::translate("Visiut3", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        menuNew->setTitle(QApplication::translate("Visiut3", "Fichier", 0, QApplication::UnicodeUTF8));
        menuFiltres->setTitle(QApplication::translate("Visiut3", "Filtres", 0, QApplication::UnicodeUTF8));
        menuOutils->setTitle(QApplication::translate("Visiut3", "Outils", 0, QApplication::UnicodeUTF8));
        menuEdition->setTitle(QApplication::translate("Visiut3", "Edition", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("Visiut3", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Visiut3: public Ui_Visiut3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISIUT3_H
