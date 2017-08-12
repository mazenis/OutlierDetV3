/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *qTabWidget;
    QWidget *Page2;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_8;
    QLabel *labelTheta;
    QLabel *labelLambda;
    QVBoxLayout *verticalLayout_7;
    QLineEdit *lineEditTheta;
    QLineEdit *lineEditLambda;
    QVBoxLayout *verticalLayout_9;
    QLabel *labelCellNumberX;
    QLabel *labelCellNumberY;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEditCellNumberX;
    QLineEdit *lineEditCellNumberY;
    QLineEdit *lineEditFilePathI;
    QPushButton *pushButtonBerlin;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButtonIBoatPortoTaxi;
    QPushButton *pushButtonIBoatHurricane;
    QHBoxLayout *horizontalLayoutGraphIBoat;
    QVBoxLayout *verticalLayoutTrajTable;
    QTableWidget *tableWidgetIBoat;
    QWidget *Page1;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_1;
    QLabel *labelCloseD;
    QLabel *labelOutSegP;
    QLabel *labelOutTrajF;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEditCloseD;
    QLineEdit *lineEditOutSegP;
    QLineEdit *lineEditOutTrajF;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelWeigthPar;
    QLabel *labelWeigthAngle;
    QLabel *labelWeigthPer;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *lineEditWeigthPar;
    QLineEdit *lineEditWeigthAngle;
    QLineEdit *lineEditWeigthPer;
    QLineEdit *lineEditFilePathT;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButtonTRAODHurricane;
    QPushButton *pushButtonTRAODPorto;
    QHBoxLayout *horizontalLayoutGraphTRAOD;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1313, 811);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        qTabWidget = new QTabWidget(centralWidget);
        qTabWidget->setObjectName(QStringLiteral("qTabWidget"));
        qTabWidget->setEnabled(true);
        Page2 = new QWidget();
        Page2->setObjectName(QStringLiteral("Page2"));
        verticalLayout_6 = new QVBoxLayout(Page2);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        labelTheta = new QLabel(Page2);
        labelTheta->setObjectName(QStringLiteral("labelTheta"));

        verticalLayout_8->addWidget(labelTheta);

        labelLambda = new QLabel(Page2);
        labelLambda->setObjectName(QStringLiteral("labelLambda"));

        verticalLayout_8->addWidget(labelLambda);


        horizontalLayout_3->addLayout(verticalLayout_8);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        lineEditTheta = new QLineEdit(Page2);
        lineEditTheta->setObjectName(QStringLiteral("lineEditTheta"));

        verticalLayout_7->addWidget(lineEditTheta);

        lineEditLambda = new QLineEdit(Page2);
        lineEditLambda->setObjectName(QStringLiteral("lineEditLambda"));

        verticalLayout_7->addWidget(lineEditLambda);


        horizontalLayout_3->addLayout(verticalLayout_7);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        labelCellNumberX = new QLabel(Page2);
        labelCellNumberX->setObjectName(QStringLiteral("labelCellNumberX"));

        verticalLayout_9->addWidget(labelCellNumberX);

        labelCellNumberY = new QLabel(Page2);
        labelCellNumberY->setObjectName(QStringLiteral("labelCellNumberY"));

        verticalLayout_9->addWidget(labelCellNumberY);


        horizontalLayout_3->addLayout(verticalLayout_9);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEditCellNumberX = new QLineEdit(Page2);
        lineEditCellNumberX->setObjectName(QStringLiteral("lineEditCellNumberX"));

        verticalLayout->addWidget(lineEditCellNumberX);

        lineEditCellNumberY = new QLineEdit(Page2);
        lineEditCellNumberY->setObjectName(QStringLiteral("lineEditCellNumberY"));

        verticalLayout->addWidget(lineEditCellNumberY);


        horizontalLayout_3->addLayout(verticalLayout);


        verticalLayout_6->addLayout(horizontalLayout_3);

        lineEditFilePathI = new QLineEdit(Page2);
        lineEditFilePathI->setObjectName(QStringLiteral("lineEditFilePathI"));

        verticalLayout_6->addWidget(lineEditFilePathI);

        pushButtonBerlin = new QPushButton(Page2);
        pushButtonBerlin->setObjectName(QStringLiteral("pushButtonBerlin"));

        verticalLayout_6->addWidget(pushButtonBerlin);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButtonIBoatPortoTaxi = new QPushButton(Page2);
        pushButtonIBoatPortoTaxi->setObjectName(QStringLiteral("pushButtonIBoatPortoTaxi"));

        horizontalLayout_5->addWidget(pushButtonIBoatPortoTaxi);


        verticalLayout_6->addLayout(horizontalLayout_5);

        pushButtonIBoatHurricane = new QPushButton(Page2);
        pushButtonIBoatHurricane->setObjectName(QStringLiteral("pushButtonIBoatHurricane"));
        pushButtonIBoatHurricane->setEnabled(false);

        verticalLayout_6->addWidget(pushButtonIBoatHurricane);

        horizontalLayoutGraphIBoat = new QHBoxLayout();
        horizontalLayoutGraphIBoat->setSpacing(6);
        horizontalLayoutGraphIBoat->setObjectName(QStringLiteral("horizontalLayoutGraphIBoat"));
        verticalLayoutTrajTable = new QVBoxLayout();
        verticalLayoutTrajTable->setSpacing(6);
        verticalLayoutTrajTable->setObjectName(QStringLiteral("verticalLayoutTrajTable"));
        tableWidgetIBoat = new QTableWidget(Page2);
        if (tableWidgetIBoat->columnCount() < 2)
            tableWidgetIBoat->setColumnCount(2);
        if (tableWidgetIBoat->rowCount() < 10)
            tableWidgetIBoat->setRowCount(10);
        tableWidgetIBoat->setObjectName(QStringLiteral("tableWidgetIBoat"));
        tableWidgetIBoat->setRowCount(10);
        tableWidgetIBoat->setColumnCount(2);
        tableWidgetIBoat->horizontalHeader()->setVisible(false);
        tableWidgetIBoat->horizontalHeader()->setDefaultSectionSize(80);
        tableWidgetIBoat->horizontalHeader()->setMinimumSectionSize(20);
        tableWidgetIBoat->verticalHeader()->setVisible(false);

        verticalLayoutTrajTable->addWidget(tableWidgetIBoat);


        horizontalLayoutGraphIBoat->addLayout(verticalLayoutTrajTable);


        verticalLayout_6->addLayout(horizontalLayoutGraphIBoat);

        qTabWidget->addTab(Page2, QString());
        Page1 = new QWidget();
        Page1->setObjectName(QStringLiteral("Page1"));
        verticalLayout_5 = new QVBoxLayout(Page1);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_1 = new QVBoxLayout();
        verticalLayout_1->setSpacing(6);
        verticalLayout_1->setObjectName(QStringLiteral("verticalLayout_1"));
        labelCloseD = new QLabel(Page1);
        labelCloseD->setObjectName(QStringLiteral("labelCloseD"));

        verticalLayout_1->addWidget(labelCloseD);

        labelOutSegP = new QLabel(Page1);
        labelOutSegP->setObjectName(QStringLiteral("labelOutSegP"));

        verticalLayout_1->addWidget(labelOutSegP);

        labelOutTrajF = new QLabel(Page1);
        labelOutTrajF->setObjectName(QStringLiteral("labelOutTrajF"));

        verticalLayout_1->addWidget(labelOutTrajF);


        horizontalLayout->addLayout(verticalLayout_1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lineEditCloseD = new QLineEdit(Page1);
        lineEditCloseD->setObjectName(QStringLiteral("lineEditCloseD"));

        verticalLayout_2->addWidget(lineEditCloseD);

        lineEditOutSegP = new QLineEdit(Page1);
        lineEditOutSegP->setObjectName(QStringLiteral("lineEditOutSegP"));

        verticalLayout_2->addWidget(lineEditOutSegP);

        lineEditOutTrajF = new QLineEdit(Page1);
        lineEditOutTrajF->setObjectName(QStringLiteral("lineEditOutTrajF"));

        verticalLayout_2->addWidget(lineEditOutTrajF);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        labelWeigthPar = new QLabel(Page1);
        labelWeigthPar->setObjectName(QStringLiteral("labelWeigthPar"));

        verticalLayout_3->addWidget(labelWeigthPar);

        labelWeigthAngle = new QLabel(Page1);
        labelWeigthAngle->setObjectName(QStringLiteral("labelWeigthAngle"));

        verticalLayout_3->addWidget(labelWeigthAngle);

        labelWeigthPer = new QLabel(Page1);
        labelWeigthPer->setObjectName(QStringLiteral("labelWeigthPer"));

        verticalLayout_3->addWidget(labelWeigthPer);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        lineEditWeigthPar = new QLineEdit(Page1);
        lineEditWeigthPar->setObjectName(QStringLiteral("lineEditWeigthPar"));

        verticalLayout_4->addWidget(lineEditWeigthPar);

        lineEditWeigthAngle = new QLineEdit(Page1);
        lineEditWeigthAngle->setObjectName(QStringLiteral("lineEditWeigthAngle"));

        verticalLayout_4->addWidget(lineEditWeigthAngle);

        lineEditWeigthPer = new QLineEdit(Page1);
        lineEditWeigthPer->setObjectName(QStringLiteral("lineEditWeigthPer"));

        verticalLayout_4->addWidget(lineEditWeigthPer);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout);

        lineEditFilePathT = new QLineEdit(Page1);
        lineEditFilePathT->setObjectName(QStringLiteral("lineEditFilePathT"));

        verticalLayout_5->addWidget(lineEditFilePathT);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButtonTRAODHurricane = new QPushButton(Page1);
        pushButtonTRAODHurricane->setObjectName(QStringLiteral("pushButtonTRAODHurricane"));
        pushButtonTRAODHurricane->setEnabled(false);

        horizontalLayout_4->addWidget(pushButtonTRAODHurricane);

        pushButtonTRAODPorto = new QPushButton(Page1);
        pushButtonTRAODPorto->setObjectName(QStringLiteral("pushButtonTRAODPorto"));

        horizontalLayout_4->addWidget(pushButtonTRAODPorto);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayoutGraphTRAOD = new QHBoxLayout();
        horizontalLayoutGraphTRAOD->setSpacing(6);
        horizontalLayoutGraphTRAOD->setObjectName(QStringLiteral("horizontalLayoutGraphTRAOD"));

        verticalLayout_5->addLayout(horizontalLayoutGraphTRAOD);

        qTabWidget->addTab(Page1, QString());

        horizontalLayout_2->addWidget(qTabWidget);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(pushButtonTRAODHurricane, SIGNAL(clicked()), MainWindow, SLOT(runTRAODHurricane()));
        QObject::connect(pushButtonTRAODPorto, SIGNAL(clicked()), MainWindow, SLOT(runTRAODPortoTaxi()));
        QObject::connect(pushButtonIBoatPortoTaxi, SIGNAL(clicked()), MainWindow, SLOT(runIBoatPortoTaxi()));
        QObject::connect(pushButtonIBoatHurricane, SIGNAL(clicked()), MainWindow, SLOT(runIBoatHurricane()));
        QObject::connect(pushButtonBerlin, SIGNAL(clicked()), MainWindow, SLOT(runIBoatBerlin()));

        qTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Outlier Detection", Q_NULLPTR));
        labelTheta->setText(QApplication::translate("MainWindow", "Theta: ", Q_NULLPTR));
        labelLambda->setText(QApplication::translate("MainWindow", "Lambda: ", Q_NULLPTR));
        lineEditTheta->setText(QApplication::translate("MainWindow", "0.01", Q_NULLPTR));
        lineEditLambda->setText(QApplication::translate("MainWindow", "150", Q_NULLPTR));
        labelCellNumberX->setText(QApplication::translate("MainWindow", "Cell count X: ", Q_NULLPTR));
        labelCellNumberY->setText(QApplication::translate("MainWindow", "Cell count Y: ", Q_NULLPTR));
        lineEditCellNumberX->setText(QApplication::translate("MainWindow", "400", Q_NULLPTR));
        lineEditCellNumberY->setText(QApplication::translate("MainWindow", "400", Q_NULLPTR));
        lineEditFilePathI->setText(QApplication::translate("MainWindow", "D:\\Data\\trips.csv", Q_NULLPTR));
        lineEditFilePathI->setPlaceholderText(QApplication::translate("MainWindow", "File Path", Q_NULLPTR));
        pushButtonBerlin->setText(QApplication::translate("MainWindow", "iBOAT BerlinMOD", Q_NULLPTR));
        pushButtonIBoatPortoTaxi->setText(QApplication::translate("MainWindow", "iBoat Porto Taxi", Q_NULLPTR));
        pushButtonIBoatHurricane->setText(QApplication::translate("MainWindow", "iBoat Hurricane", Q_NULLPTR));
        qTabWidget->setTabText(qTabWidget->indexOf(Page2), QApplication::translate("MainWindow", "iBoat", Q_NULLPTR));
        labelCloseD->setText(QApplication::translate("MainWindow", "D: ", Q_NULLPTR));
        labelOutSegP->setText(QApplication::translate("MainWindow", "P: ", Q_NULLPTR));
        labelOutTrajF->setText(QApplication::translate("MainWindow", "F: ", Q_NULLPTR));
        lineEditCloseD->setText(QApplication::translate("MainWindow", "85.0", Q_NULLPTR));
        lineEditOutSegP->setText(QApplication::translate("MainWindow", "0.95", Q_NULLPTR));
        lineEditOutTrajF->setText(QApplication::translate("MainWindow", "0.2", Q_NULLPTR));
        labelWeigthPar->setText(QApplication::translate("MainWindow", "WeigthPar: ", Q_NULLPTR));
        labelWeigthAngle->setText(QApplication::translate("MainWindow", "WeigthAngle: ", Q_NULLPTR));
        labelWeigthPer->setText(QApplication::translate("MainWindow", "WeigthPer:", Q_NULLPTR));
        lineEditWeigthPar->setText(QApplication::translate("MainWindow", "1.0", Q_NULLPTR));
        lineEditWeigthAngle->setText(QApplication::translate("MainWindow", "10.0", Q_NULLPTR));
        lineEditWeigthPer->setText(QApplication::translate("MainWindow", "1.0", Q_NULLPTR));
        lineEditFilePathT->setText(QApplication::translate("MainWindow", "D:\\\\Diplomka\\\\hurricane1990_2006.tra", Q_NULLPTR));
        lineEditFilePathT->setPlaceholderText(QApplication::translate("MainWindow", "File Path", Q_NULLPTR));
        pushButtonTRAODHurricane->setText(QApplication::translate("MainWindow", " TRAOD Hurricane", Q_NULLPTR));
        pushButtonTRAODPorto->setText(QApplication::translate("MainWindow", "TRAOD Porto Taxi", Q_NULLPTR));
        qTabWidget->setTabText(qTabWidget->indexOf(Page1), QApplication::translate("MainWindow", "TRAOD", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
