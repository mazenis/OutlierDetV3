#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // init widgets for graphs
    chartTRAOD = new myChart();
    chartTRAOD->legend()->hide();
    chartTRAOD->setTitle("TRAOD");

    chartIBoat = new myChart();
    chartIBoat->legend()->hide();
    chartIBoat->setTitle("iBoat");

    chartIBoatScore = new myChart();
    chartIBoatScore->legend()->hide();
    chartIBoatScore->setTitle("iBoat Score");

    myChartView *chartViewTRAOD = new myChartView(chartTRAOD);
    ui->horizontalLayoutGraphTRAOD->addWidget(chartViewTRAOD);
    chartViewTRAOD->setRenderHint(QPainter::Antialiasing);

    // init table of anomalous score for iBoat
    connect(ui->tableWidgetIBoat, &QTableWidget::cellClicked, this, &MainWindow::cellIBoatSelected);
    ui->tableWidgetIBoat->setHorizontalHeaderItem(0, new QTableWidgetItem("ID"));
    ui->tableWidgetIBoat->setHorizontalHeaderItem(1, new QTableWidgetItem("Score"));
    QList<QString> list;
    list << "ID" << "Score";
    ui->tableWidgetIBoat->setHorizontalHeaderLabels(list);
    ui->tableWidgetIBoat->horizontalHeader()->setVisible(true);

    myChartView *chartViewIboat = new myChartView(chartIBoat);
    ui->horizontalLayoutGraphIBoat->addWidget(chartViewIboat);
    chartViewIboat->setRenderHint(QPainter::Antialiasing);

    myChartView *chartViewIboatScore = new myChartView(chartIBoatScore);
    chartViewIboatScore->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    chartViewIboatScore->setMinimumHeight(300);
    chartViewIboatScore->setMinimumWidth(300);
    ui->verticalLayoutTrajTable->addWidget(chartViewIboatScore);
    chartViewIboatScore->setRenderHint(QPainter::Antialiasing);
}

void MainWindow::printTrajectoriesTRAOD() {
    QPen pen(QRgb(0xcccccc));
    pen.setWidth(1);
    foreach (Trajectory *traj, traodObject.trajectoryData.listTrajectories) {
        QtCharts::QLineSeries *series = new QtCharts::QLineSeries();
        series->setPen(pen);
        foreach (QPointF seg, traj->listPoints) {
            series->append(seg);
        }
        series->append(traj->listPoints.last());
        chartTRAOD->addSeries(series);
    }
    chartTRAOD->createDefaultAxes();
}

void MainWindow::printCoarseTrajectoryTRAOD() {
    QPen pen(QRgb(0xcc0000));
    pen.setWidth(1);
    foreach (Trajectory *traj, traodObject.trajectoryData.listTrajectories) {
        QtCharts::QLineSeries *series = new QtCharts::QLineSeries();
        series->setPen(pen);
        foreach (CoarseSegment *seg, traj->listCoarseSegments) {
            series->append(seg->startPoint);
        }
        series->append(traj->listCoarseSegments.last()->endPoint);
        chartTRAOD->addSeries(series);
    }
    chartTRAOD->createDefaultAxes();
}

void MainWindow::printTrajectoryOutlierTRAOD() {
    QPen penOutTraj(QRgb(0xcc0000));
    penOutTraj.setWidth(1);
    QPen penOutSeg(QRgb(0x990000));
    penOutSeg.setWidth(2);
    foreach (Trajectory *traj, traodObject.trajectoryData.listTrajectories) {
        if (traj->isOutlier) {
            foreach (Segment *seg, traj->listSegments) {
                if (seg->isOutlier) {
                    QtCharts::QLineSeries *series = new QtCharts::QLineSeries();
                    series->setPen(penOutSeg);
                    series->append(seg->startPoint);
                    series->append(seg->endPoint);
                    chartTRAOD->addSeries(series);
                }
                else {
                    QtCharts::QLineSeries *series = new QtCharts::QLineSeries();
                    series->setPen(penOutTraj);
                    series->append(seg->startPoint);
                    series->append(seg->endPoint);
                    chartTRAOD->addSeries(series);
                }
            }
        }
    }
    chartTRAOD->createDefaultAxes();
}

void MainWindow::printSegmentOutlierTRAOD() {
    QPen pen(QRgb(0xcc0000));
    pen.setWidth(1);
    foreach (Trajectory *traj, traodObject.trajectoryData.listTrajectories) {
        foreach (Segment *seg, traj->listSegments) {
            if (seg->isOutlier) {
                QtCharts::QLineSeries *series = new QtCharts::QLineSeries();
                series->setPen(pen);
                series->append(seg->startPoint);
                series->append(seg->endPoint);
                chartTRAOD->addSeries(series);
            }
        }
    }
    chartTRAOD->createDefaultAxes();
}

void MainWindow::runTRAODHurricane() {
    qDebug() << "TRAOD Hur";
    double p = ui->lineEditOutSegP->text().toDouble();
    double F = ui->lineEditOutTrajF->text().toDouble();
    double D = ui->lineEditCloseD->text().toDouble();
    double wa = ui->lineEditWeigthAngle->text().toDouble();
    double wpar = ui->lineEditWeigthPar->text().toDouble();
    double wper = ui->lineEditWeigthPer->text().toDouble();
    traodObject.setParams(p, F, D, wa, wper, wpar);
    traodObject.loadTRAODHurricane(ui->lineEditFilePathT->text());
    traodObject.runTRAOD();
    chartTRAOD->removeAllSeries(); // clean graph
    printTrajectoriesTRAOD();
    //printCoarseTrajectoryTRAOD();
    printTrajectoryOutlierTRAOD();
}

void MainWindow::runTRAODPortoTaxi() {
    qDebug() << "TRAOD Porto";
    double p = ui->lineEditOutSegP->text().toDouble();
    double F = ui->lineEditOutTrajF->text().toDouble();
    double D = ui->lineEditCloseD->text().toDouble();
    double wa = ui->lineEditWeigthAngle->text().toDouble();
    double wpar = ui->lineEditWeigthPar->text().toDouble();
    double wper = ui->lineEditWeigthPer->text().toDouble();
    traodObject.setParams(p, F, D, wa, wper, wpar);
    traodObject.loadTRAODPortoTaxi(ui->lineEditFilePathT->text());
    traodObject.runTRAOD();
    chartTRAOD->removeAllSeries(); // clean graph
    printTrajectoriesTRAOD();
//    printCoarseTrajectoryTRAOD();
    printTrajectoryOutlierTRAOD();;
}

void MainWindow::printTrajIBoat() {
    QPen pen(QRgb(0xcccccc));
    pen.setWidth(1);
    foreach (TrajectoryIBoat *traj, iBoatObject.trajectoryData.listTrajectories) {
        QtCharts::QLineSeries *series = new QtCharts::QLineSeries();
        series->setPen(pen);
        foreach (PointFTime point, traj->listPoints) {
            series->append(static_cast<QPointF>(point));
        }
        chartIBoat->addSeries(series);
    }
    chartIBoat->createDefaultAxes();
}

void MainWindow::printCellIBoat() {
    QPen pen(QRgb(0xcccccc));
    pen.setWidth(1);
    foreach (TrajectoryIBoat *traj, iBoatObject.trajectoryData.listTrajectories) {
        QtCharts::QLineSeries *series = new QtCharts::QLineSeries();
        series->setPen(pen);
        foreach (CellIBoat *cell, traj->listCells) {
            series->append(cell->cell);
        }
        chartIBoat->addSeries(series);
    }
    chartIBoat->createDefaultAxes();
}

void MainWindow::printAnomalousPointIBoat() {
    QPen pen(QRgb(0xcc0000));
    pen.setWidth(1);
    foreach (TrajectoryIBoat *traj, iBoatObject.trajectoryData.listTrajectories) {
        if (!traj->listAnomalousPoints.isEmpty()) {
            QtCharts::QScatterSeries *series = new QtCharts::QScatterSeries();
            series->setMarkerShape(QtCharts::QScatterSeries::MarkerShapeCircle);
            series->setMarkerSize(3.0);
            series->setPen(pen);
            listAnomalySeries.append(series);
            foreach (PointFTime point, traj->listAnomalousPoints) {
                series->append(static_cast<QPointF>(point));
            }
            chartIBoat->addSeries(series);
        }
    }
    chartIBoat->createDefaultAxes();
}

void MainWindow::printAnomalousTrajIBoat() {
    QPen pen(QRgb(0xcc0000));
    pen.setWidth(1);
    QList<QPointF> listPoints;
    foreach (TrajectoryIBoat *traj, iBoatObject.trajectoryData.listTrajectories) {
        //series->append(traj->listPoints.first());
        bool isAn = false;
        for (qint64 i = 0; i < traj->listAnomalousIndex.size()-1; i++) {
            if ((traj->listAnomalousIndex[i+1] - traj->listAnomalousIndex[i]) == 1) {
                listPoints.append(static_cast<QPointF>(traj->listPoints[traj->listAnomalousIndex[i]]));
                isAn = true;
            }
            else {
                listPoints.append(static_cast<QPointF>(traj->listPoints[traj->listAnomalousIndex[i]]));
                QtCharts::QLineSeries *series = new QtCharts::QLineSeries();
                series->setPen(pen);
                series->append(listPoints);
                chartIBoat->addSeries(series);
                listPoints.clear();
                isAn = false;
            }
        }
        if (isAn) {
            listPoints.append(static_cast<QPointF>(traj->listPoints[traj->listAnomalousIndex.last()]));
            QtCharts::QLineSeries *series = new QtCharts::QLineSeries();
            series->setPen(pen);
            series->append(listPoints);
            chartIBoat->addSeries(series);
        }
        listPoints.clear();
    }
    chartIBoat->createDefaultAxes();
//    QPen pen(QRgb(0xcc0000));
//    pen.setWidth(1);
//    foreach (TrajectoryIBoat *traj, iBoatObject.trajectoryData.listTrajectories) {
//        if (traj->listAnomalousPoints.size() >= traj->listPoints.size()/4) {
//            QtCharts::QLineSeries *series = new QtCharts::QLineSeries();
//            series->setPen(pen);
//            series->append(traj->listPoints);
//            chartIBoat->addSeries(series);
//        }
//    }
//    chartIBoat->createDefaultAxes();
}

void MainWindow::fillTableList() {
    qint64 i = 1;
    ui->tableWidgetIBoat->clear();
    ui->tableWidgetIBoat->setRowCount(iBoatObject.trajectoryData.listTrajectories.size());
    QList<QString> list;        //Mazen
    list << "ID" << "Score";
    ui->tableWidgetIBoat->setHorizontalHeaderLabels(list);
    foreach (TrajectoryIBoat *traj, iBoatObject.trajectoryData.listTrajectories) {
        if (!traj->listAnomalousPoints.isEmpty()) {
            ui->tableWidgetIBoat->setItem(i, 0, new QTableWidgetItem(QString::number(traj->ID)));
            ui->tableWidgetIBoat->setItem(i, 1, new QTableWidgetItem(QString::number(traj->score.last(), 'f')));
            i++;
        }
    }
    ui->tableWidgetIBoat->sortByColumn(1);
}

void MainWindow::runIBoatHurricane() {
    qDebug() << "IBoat Hur";
    double Theta = ui->lineEditTheta->text().toDouble();
    double Lambda = ui->lineEditLambda->text().toDouble();
    qint64 CellNumberX = ui->lineEditCellNumberX->text().toLongLong();
    qint64 CellNumberY = ui->lineEditCellNumberY->text().toLongLong();
    iBoatObject.setParam(Theta, Lambda, CellNumberX, CellNumberY);
    iBoatObject.loadIBoatHurricane(ui->lineEditFilePathI->text());
    iBoatObject.runIBoat();
    chartIBoat->removeAllSeries(); // clean graph
    fillTableList();
    printTrajIBoat();
    //printAnomalousPointIBoat();
    printAnomalousTrajIBoat();
}

void MainWindow::runIBoatPortoTaxi() {
    qDebug() << "IBoat Porto";
    double Theta = ui->lineEditTheta->text().toDouble();
    double Lambda = ui->lineEditLambda->text().toDouble();
    qint64 CellNumberX = ui->lineEditCellNumberX->text().toLongLong();
    qint64 CellNumberY = ui->lineEditCellNumberY->text().toLongLong();
    iBoatObject.setParam(Theta, Lambda, CellNumberX, CellNumberY);
    iBoatObject.loadIBoatPortoTaxi(ui->lineEditFilePathI->text());
    iBoatObject.runIBoat();
    chartIBoat->removeAllSeries(); // clean graph
    fillTableList();
    printTrajIBoat();
    //printAnomalousPointIBoat();
    printAnomalousTrajIBoat();

}

void MainWindow::runIBoatBerlin() {
    qDebug() << "IBoat Berlin";
    double Theta = ui->lineEditTheta->text().toDouble();
    double Lambda = ui->lineEditLambda->text().toDouble();
    qint64 CellNumberX = ui->lineEditCellNumberX->text().toLongLong();
    qint64 CellNumberY = ui->lineEditCellNumberY->text().toLongLong();
    iBoatObject.setParam(Theta, Lambda, CellNumberX, CellNumberY);
    //iBoatObject.loadIBoatBerlin(ui->lineEditFilePathI->text());
    iBoatObject.loadIBoatBerlinK(ui->lineEditFilePathI->text());
    iBoatObject.runIBoat();
    chartIBoat->removeAllSeries(); // clean graph
    fillTableList();
    printTrajIBoat();
    printAnomalousTrajIBoat();
}

void MainWindow::cellIBoatSelected(qint64 row, qint64 column) {
    foreach (QtCharts::QScatterSeries *series, listAnomalySeries) {
        chartIBoat->removeSeries(series);
    }

    listAnomalySeries.clear();
    qDebug() << row << column;
    QPen pen(QRgb(0xcc0000));
    pen.setWidth(1);
    TrajectoryIBoat *traj;
    // change to load by ID search through all trajectories, beacause ID and index its not the same // konarek
    qint64 selectedID = ui->tableWidgetIBoat->item(row,0)->text().toLongLong();
    foreach (TrajectoryIBoat *trajlook, iBoatObject.trajectoryData.listTrajectories) {
        if (selectedID == trajlook->ID) {
            traj = trajlook;
            break;
        }
    }
    QtCharts::QScatterSeries *series = new QtCharts::QScatterSeries();
    series->setMarkerShape(QtCharts::QScatterSeries::MarkerShapeCircle);
    series->setMarkerSize(4.0);
    series->setPen(pen);
    foreach (PointFTime point, traj->listAnomalousPoints) {
        series->append(static_cast<QPointF>(point));
    }
    chartIBoat->addSeries(series);
    listAnomalySeries.append(series);
    chartIBoat->createDefaultAxes();

    chartIBoatScore->removeAllSeries();
    QtCharts::QLineSeries *seriesScore = new QtCharts::QLineSeries();
    seriesScore->setPen(pen);
    qint64 i = 0;
    foreach (double score, traj->score) {
        seriesScore->append(i, score);
        i++;
    }
    chartIBoatScore->addSeries(seriesScore);
    chartIBoatScore->createDefaultAxes();
}

MainWindow::~MainWindow()
{
    delete ui;
}
