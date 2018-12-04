/********************************************************************************
** Form generated from reading UI file 'openvideo.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENVIDEO_H
#define UI_OPENVIDEO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_openvideoClass
{
public:
    QWidget *centralWidget;
    QPushButton *play;
    QPushButton *detector;
    QRadioButton *yolov3;
    QRadioButton *head;
    QTextEdit *rtsp1;
    QLabel *label_2;
    QLineEdit *num1;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QTextEdit *rtsp2;
    QTextEdit *rtsp3;
    QTextEdit *rtsp4;
    QTextEdit *rtsp5;
    QTextEdit *rtsp6;
    QLineEdit *num2;
    QTextEdit *rtsp7;
    QTextEdit *rtsp8;
    QTextEdit *rtsp9;
    QTextEdit *rtsp10;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *num3;
    QLineEdit *num4;
    QLineEdit *num5;
    QLineEdit *num6;
    QLineEdit *num7;
    QLineEdit *num8;
    QLineEdit *num9;
    QLineEdit *num10;
    QLineEdit *sulv;
    QPushButton *ratio;
    QPushButton *rect1;
    QPushButton *rect2;
    QPushButton *rect3;
    QPushButton *rect4;
    QPushButton *rect5;
    QPushButton *rect6;
    QPushButton *rect7;
    QPushButton *rect8;
    QPushButton *rect9;
    QPushButton *rect10;
    QLabel *label;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QLabel *video0;
    QLabel *video1;
    QLabel *label_12;
    QLabel *label_13;
    QWidget *page_2;
    QLabel *video2;
    QLabel *video3;
    QLabel *label_14;
    QLabel *label_15;
    QWidget *page;
    QLabel *video4;
    QLabel *video5;
    QLabel *label_16;
    QLabel *label_17;
    QWidget *page_4;
    QLabel *video6;
    QLabel *video7;
    QLabel *label_22;
    QLabel *label_23;
    QWidget *page_5;
    QLabel *video8;
    QLabel *video9;
    QLabel *label_24;
    QLabel *label_25;
    QListWidget *listWidget;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;

    void setupUi(QMainWindow *openvideoClass)
    {
        if (openvideoClass->objectName().isEmpty())
            openvideoClass->setObjectName(QStringLiteral("openvideoClass"));
        openvideoClass->resize(1745, 917);
        centralWidget = new QWidget(openvideoClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        play = new QPushButton(centralWidget);
        play->setObjectName(QStringLiteral("play"));
        play->setGeometry(QRect(320, 10, 75, 23));
        detector = new QPushButton(centralWidget);
        detector->setObjectName(QStringLiteral("detector"));
        detector->setGeometry(QRect(570, 540, 75, 23));
        yolov3 = new QRadioButton(centralWidget);
        yolov3->setObjectName(QStringLiteral("yolov3"));
        yolov3->setGeometry(QRect(60, 0, 89, 16));
        head = new QRadioButton(centralWidget);
        head->setObjectName(QStringLiteral("head"));
        head->setGeometry(QRect(10, 0, 89, 16));
        rtsp1 = new QTextEdit(centralWidget);
        rtsp1->setObjectName(QStringLiteral("rtsp1"));
        rtsp1->setGeometry(QRect(100, 40, 551, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 50, 31, 20));
        num1 = new QLineEdit(centralWidget);
        num1->setObjectName(QStringLiteral("num1"));
        num1->setGeometry(QRect(100, 60, 551, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 100, 54, 12));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 150, 54, 12));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 200, 54, 12));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 240, 54, 12));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 290, 54, 12));
        rtsp2 = new QTextEdit(centralWidget);
        rtsp2->setObjectName(QStringLiteral("rtsp2"));
        rtsp2->setGeometry(QRect(100, 90, 551, 21));
        rtsp3 = new QTextEdit(centralWidget);
        rtsp3->setObjectName(QStringLiteral("rtsp3"));
        rtsp3->setGeometry(QRect(100, 140, 551, 21));
        rtsp4 = new QTextEdit(centralWidget);
        rtsp4->setObjectName(QStringLiteral("rtsp4"));
        rtsp4->setGeometry(QRect(100, 190, 551, 21));
        rtsp5 = new QTextEdit(centralWidget);
        rtsp5->setObjectName(QStringLiteral("rtsp5"));
        rtsp5->setGeometry(QRect(100, 240, 551, 21));
        rtsp6 = new QTextEdit(centralWidget);
        rtsp6->setObjectName(QStringLiteral("rtsp6"));
        rtsp6->setGeometry(QRect(100, 290, 551, 21));
        num2 = new QLineEdit(centralWidget);
        num2->setObjectName(QStringLiteral("num2"));
        num2->setGeometry(QRect(100, 110, 551, 20));
        rtsp7 = new QTextEdit(centralWidget);
        rtsp7->setObjectName(QStringLiteral("rtsp7"));
        rtsp7->setGeometry(QRect(100, 340, 551, 21));
        rtsp8 = new QTextEdit(centralWidget);
        rtsp8->setObjectName(QStringLiteral("rtsp8"));
        rtsp8->setGeometry(QRect(100, 390, 551, 21));
        rtsp9 = new QTextEdit(centralWidget);
        rtsp9->setObjectName(QStringLiteral("rtsp9"));
        rtsp9->setGeometry(QRect(100, 440, 551, 21));
        rtsp10 = new QTextEdit(centralWidget);
        rtsp10->setObjectName(QStringLiteral("rtsp10"));
        rtsp10->setGeometry(QRect(100, 490, 551, 21));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 350, 41, 16));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(30, 400, 54, 12));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 450, 54, 12));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(30, 500, 54, 12));
        num3 = new QLineEdit(centralWidget);
        num3->setObjectName(QStringLiteral("num3"));
        num3->setGeometry(QRect(100, 160, 551, 20));
        num4 = new QLineEdit(centralWidget);
        num4->setObjectName(QStringLiteral("num4"));
        num4->setGeometry(QRect(100, 210, 551, 20));
        num5 = new QLineEdit(centralWidget);
        num5->setObjectName(QStringLiteral("num5"));
        num5->setGeometry(QRect(100, 260, 551, 20));
        num6 = new QLineEdit(centralWidget);
        num6->setObjectName(QStringLiteral("num6"));
        num6->setGeometry(QRect(100, 310, 551, 20));
        num7 = new QLineEdit(centralWidget);
        num7->setObjectName(QStringLiteral("num7"));
        num7->setGeometry(QRect(100, 360, 551, 20));
        num8 = new QLineEdit(centralWidget);
        num8->setObjectName(QStringLiteral("num8"));
        num8->setGeometry(QRect(100, 410, 551, 20));
        num9 = new QLineEdit(centralWidget);
        num9->setObjectName(QStringLiteral("num9"));
        num9->setGeometry(QRect(100, 460, 551, 20));
        num10 = new QLineEdit(centralWidget);
        num10->setObjectName(QStringLiteral("num10"));
        num10->setGeometry(QRect(100, 510, 551, 20));
        sulv = new QLineEdit(centralWidget);
        sulv->setObjectName(QStringLiteral("sulv"));
        sulv->setGeometry(QRect(30, 550, 41, 20));
        ratio = new QPushButton(centralWidget);
        ratio->setObjectName(QStringLiteral("ratio"));
        ratio->setGeometry(QRect(90, 550, 61, 23));
        rect1 = new QPushButton(centralWidget);
        rect1->setObjectName(QStringLiteral("rect1"));
        rect1->setGeometry(QRect(680, 50, 75, 23));
        rect2 = new QPushButton(centralWidget);
        rect2->setObjectName(QStringLiteral("rect2"));
        rect2->setGeometry(QRect(680, 100, 75, 23));
        rect3 = new QPushButton(centralWidget);
        rect3->setObjectName(QStringLiteral("rect3"));
        rect3->setGeometry(QRect(680, 150, 75, 23));
        rect4 = new QPushButton(centralWidget);
        rect4->setObjectName(QStringLiteral("rect4"));
        rect4->setGeometry(QRect(680, 200, 75, 23));
        rect5 = new QPushButton(centralWidget);
        rect5->setObjectName(QStringLiteral("rect5"));
        rect5->setGeometry(QRect(680, 250, 75, 23));
        rect6 = new QPushButton(centralWidget);
        rect6->setObjectName(QStringLiteral("rect6"));
        rect6->setGeometry(QRect(680, 300, 75, 23));
        rect7 = new QPushButton(centralWidget);
        rect7->setObjectName(QStringLiteral("rect7"));
        rect7->setGeometry(QRect(680, 350, 75, 23));
        rect8 = new QPushButton(centralWidget);
        rect8->setObjectName(QStringLiteral("rect8"));
        rect8->setGeometry(QRect(680, 400, 75, 23));
        rect9 = new QPushButton(centralWidget);
        rect9->setObjectName(QStringLiteral("rect9"));
        rect9->setGeometry(QRect(680, 450, 75, 23));
        rect10 = new QPushButton(centralWidget);
        rect10->setObjectName(QStringLiteral("rect10"));
        rect10->setGeometry(QRect(680, 500, 75, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(690, 20, 91, 20));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(920, 30, 791, 811));
        stackedWidget->setCursor(QCursor(Qt::ArrowCursor));
        stackedWidget->setFrameShape(QFrame::StyledPanel);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        video0 = new QLabel(page_3);
        video0->setObjectName(QStringLiteral("video0"));
        video0->setGeometry(QRect(80, 20, 641, 361));
        video0->setFrameShape(QFrame::Box);
        video1 = new QLabel(page_3);
        video1->setObjectName(QStringLiteral("video1"));
        video1->setGeometry(QRect(80, 420, 641, 361));
        video1->setFrameShape(QFrame::Box);
        label_12 = new QLabel(page_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 230, 41, 20));
        label_13 = new QLabel(page_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 580, 54, 12));
        stackedWidget->addWidget(page_3);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        video2 = new QLabel(page_2);
        video2->setObjectName(QStringLiteral("video2"));
        video2->setGeometry(QRect(80, 20, 641, 361));
        video2->setFrameShape(QFrame::Box);
        video3 = new QLabel(page_2);
        video3->setObjectName(QStringLiteral("video3"));
        video3->setGeometry(QRect(80, 420, 641, 361));
        video3->setFrameShape(QFrame::Box);
        label_14 = new QLabel(page_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 200, 54, 12));
        label_15 = new QLabel(page_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 570, 54, 12));
        stackedWidget->addWidget(page_2);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        video4 = new QLabel(page);
        video4->setObjectName(QStringLiteral("video4"));
        video4->setGeometry(QRect(80, 20, 641, 361));
        video4->setFrameShape(QFrame::Box);
        video5 = new QLabel(page);
        video5->setObjectName(QStringLiteral("video5"));
        video5->setGeometry(QRect(70, 420, 651, 361));
        video5->setFrameShape(QFrame::Box);
        label_16 = new QLabel(page);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(3, 202, 51, 20));
        label_17 = new QLabel(page);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(3, 580, 51, 20));
        stackedWidget->addWidget(page);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        video6 = new QLabel(page_4);
        video6->setObjectName(QStringLiteral("video6"));
        video6->setGeometry(QRect(80, 20, 641, 361));
        video6->setFrameShape(QFrame::Box);
        video7 = new QLabel(page_4);
        video7->setObjectName(QStringLiteral("video7"));
        video7->setGeometry(QRect(80, 420, 641, 361));
        video7->setFrameShape(QFrame::Box);
        label_22 = new QLabel(page_4);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(20, 220, 54, 12));
        label_23 = new QLabel(page_4);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(10, 560, 54, 12));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        video8 = new QLabel(page_5);
        video8->setObjectName(QStringLiteral("video8"));
        video8->setGeometry(QRect(83, 21, 641, 361));
        video8->setFrameShape(QFrame::Box);
        video9 = new QLabel(page_5);
        video9->setObjectName(QStringLiteral("video9"));
        video9->setGeometry(QRect(80, 420, 641, 361));
        video9->setFrameShape(QFrame::Box);
        label_24 = new QLabel(page_5);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(20, 220, 54, 12));
        label_25 = new QLabel(page_5);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(20, 580, 54, 12));
        stackedWidget->addWidget(page_5);
        listWidget = new QListWidget(centralWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(870, 30, 51, 101));
        openvideoClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(openvideoClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        openvideoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(openvideoClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        openvideoClass->setStatusBar(statusBar);
        menuBar = new QMenuBar(openvideoClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1745, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        openvideoClass->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menu->addSeparator();
        menu->addSeparator();
        menu_4->addSeparator();

        retranslateUi(openvideoClass);
        QObject::connect(listWidget, SIGNAL(currentRowChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(openvideoClass);
    } // setupUi

    void retranslateUi(QMainWindow *openvideoClass)
    {
        openvideoClass->setWindowTitle(QApplication::translate("openvideoClass", "openvideo", Q_NULLPTR));
        play->setText(QApplication::translate("openvideoClass", "\346\222\255\346\224\276", Q_NULLPTR));
        detector->setText(QApplication::translate("openvideoClass", "\351\200\200\345\207\272", Q_NULLPTR));
        yolov3->setText(QApplication::translate("openvideoClass", "yolov3", Q_NULLPTR));
        head->setText(QApplication::translate("openvideoClass", "head", Q_NULLPTR));
        label_2->setText(QApplication::translate("openvideoClass", "\346\265\2011\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("openvideoClass", "\346\265\2012\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("openvideoClass", "\346\265\2013\357\274\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("openvideoClass", "\346\265\2014\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("openvideoClass", "\346\265\2015\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("openvideoClass", "\346\265\2016\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("openvideoClass", "\346\265\2017\357\274\232", Q_NULLPTR));
        label_9->setText(QApplication::translate("openvideoClass", "\346\265\2018\357\274\232", Q_NULLPTR));
        label_10->setText(QApplication::translate("openvideoClass", "\346\265\2019\357\274\232", Q_NULLPTR));
        label_11->setText(QApplication::translate("openvideoClass", "\346\265\20110\357\274\232", Q_NULLPTR));
        ratio->setText(QApplication::translate("openvideoClass", "\351\200\237\347\216\207", Q_NULLPTR));
        rect1->setText(QApplication::translate("openvideoClass", "0", Q_NULLPTR));
        rect2->setText(QApplication::translate("openvideoClass", "1", Q_NULLPTR));
        rect3->setText(QApplication::translate("openvideoClass", "2", Q_NULLPTR));
        rect4->setText(QApplication::translate("openvideoClass", "3", Q_NULLPTR));
        rect5->setText(QApplication::translate("openvideoClass", "4", Q_NULLPTR));
        rect6->setText(QApplication::translate("openvideoClass", "5", Q_NULLPTR));
        rect7->setText(QApplication::translate("openvideoClass", "6", Q_NULLPTR));
        rect8->setText(QApplication::translate("openvideoClass", "7", Q_NULLPTR));
        rect9->setText(QApplication::translate("openvideoClass", "8", Q_NULLPTR));
        rect10->setText(QApplication::translate("openvideoClass", "9", Q_NULLPTR));
        label->setText(QApplication::translate("openvideoClass", "\347\224\273\345\215\261\351\231\251\345\214\272\345\237\237", Q_NULLPTR));
        video0->setText(QString());
        video1->setText(QString());
        label_12->setText(QApplication::translate("openvideoClass", "video0", Q_NULLPTR));
        label_13->setText(QApplication::translate("openvideoClass", "video1", Q_NULLPTR));
        video2->setText(QString());
        video3->setText(QString());
        label_14->setText(QApplication::translate("openvideoClass", "video2", Q_NULLPTR));
        label_15->setText(QApplication::translate("openvideoClass", "video3", Q_NULLPTR));
        video4->setText(QString());
        video5->setText(QString());
        label_16->setText(QApplication::translate("openvideoClass", "video4", Q_NULLPTR));
        label_17->setText(QApplication::translate("openvideoClass", "video5", Q_NULLPTR));
        video6->setText(QString());
        video7->setText(QString());
        label_22->setText(QApplication::translate("openvideoClass", "video6", Q_NULLPTR));
        label_23->setText(QApplication::translate("openvideoClass", "video7", Q_NULLPTR));
        video8->setText(QString());
        video9->setText(QString());
        label_24->setText(QApplication::translate("openvideoClass", "video8", Q_NULLPTR));
        label_25->setText(QApplication::translate("openvideoClass", "video9", Q_NULLPTR));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("openvideoClass", "\347\254\254\344\270\200\351\241\265", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("openvideoClass", "\347\254\254\344\272\214\351\241\265", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("openvideoClass", "\347\254\254\344\270\211\351\241\265", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("openvideoClass", "\347\254\254\345\233\233\351\241\265", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("openvideoClass", "\347\254\254\344\272\224\351\241\265", Q_NULLPTR));
        listWidget->setSortingEnabled(__sortingEnabled);

        menu->setTitle(QApplication::translate("openvideoClass", "\346\274\224\347\244\272\347\263\273\347\273\237", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("openvideoClass", "\350\256\276\347\275\256", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("openvideoClass", "\346\226\207\344\273\266", Q_NULLPTR));
        menu_4->setTitle(QApplication::translate("openvideoClass", "\345\270\256\345\212\251", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class openvideoClass: public Ui_openvideoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENVIDEO_H
