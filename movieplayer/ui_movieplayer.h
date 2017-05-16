/********************************************************************************
** Form generated from reading UI file 'movieplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVIEPLAYER_H
#define UI_MOVIEPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_movieplayer
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *movieplayer)
    {
        if (movieplayer->objectName().isEmpty())
            movieplayer->setObjectName(QStringLiteral("movieplayer"));
        movieplayer->resize(489, 308);
        centralWidget = new QWidget(movieplayer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        movieplayer->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(movieplayer);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 489, 21));
        movieplayer->setMenuBar(menuBar);
        mainToolBar = new QToolBar(movieplayer);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        movieplayer->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(movieplayer);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        movieplayer->setStatusBar(statusBar);

        retranslateUi(movieplayer);

        QMetaObject::connectSlotsByName(movieplayer);
    } // setupUi

    void retranslateUi(QMainWindow *movieplayer)
    {
        movieplayer->setWindowTitle(QApplication::translate("movieplayer", "movieplayer", 0));
    } // retranslateUi

};

namespace Ui {
    class movieplayer: public Ui_movieplayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVIEPLAYER_H
