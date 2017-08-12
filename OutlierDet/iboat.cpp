#include "iboat.hpp"

iBoat::iBoat()
{

}

void iBoat::loadIBoatHurricane(QString file) {
    trajectoryData.readHurricaneFromFile(file);
}

void iBoat::loadIBoatPortoTaxi(QString file) {
    trajectoryData.readPortoTaxiFromFile(file);
}

void iBoat::loadIBoatBerlin(QString file) { //Mazen
    trajectoryData.readBerlinFromFile(file);
}
void iBoat::loadIBoatBerlinK(QString file){ // Konarek
    trajectoryData.readBerlinFromFileK(file);
}

void iBoat::runIBoat() {
    trajectoryData.initCell();
    process();
}

void iBoat::setParam(double Theta, double Lambda, qint64 CellNumberX, qint64 CellNumberY) {
    this->Theta = Theta;
    this->Lambda = Lambda;
    trajectoryData.setSizeOfCell(CellNumberX, CellNumberY);
}

void iBoat::process() {
    qint64 k = 0;
    QList<TrajectoryIBoat *> *workingSet = &trajectoryData.listTrajectories;
            qDebug() << k << ":" << QDateTime::currentDateTime().time();
    foreach (TrajectoryIBoat *traj, trajectoryData.listTrajectories) {
        // set workingSet to all trajectories
        workingSet = &(trajectoryData.listTrajectories);


        // when we have pointer that is a problem (for now solution is in support method)
        // remove actual testing trajectory
        // so it does not effect results
//        workingSet->removeAll(traj);

        qint64 i = 0;
        QList<CellIBoat *> window;
        double supportV = 0.0;
        PointFTime prevPoint = traj->listPoints.first();

        foreach (PointFTime point, traj->listPoints) {
            i++;
            // map point to cell
            CellIBoat *cell = trajectoryData.listCells[QPair<qint64, qint64>(trajectoryData.computeIndexX(point.x()), trajectoryData.computeIndexY(point.y()))];
            window.append(cell);
            QList<TrajectoryIBoat *> *hasPathSet = hasPathWindowOPT(*workingSet, window);
            supportV = support(hasPathSet, workingSet);
            workingSet = hasPathSet;
            if (isThetaAnomalous(supportV)) {
                // point is anomalous
                // set point as anomalous
                traj->listAnomalousIndex.append(i-1);
                traj->listAnomalousPoints.append(point);
                // reset working set
                workingSet = &(trajectoryData.listTrajectories);
                // remove actual testing trajectory
                // so it does not effect results
//                workingSet->removeAll(traj);
                // reset window
                window.clear();
                window.append(cell);
            }
            // compute score for every point (even if its not anomalous)
            traj->score.append(traj->score[i-1] + sigma(supportV) * euclideanDistanceI(prevPoint, point));
            prevPoint = point;
        }

        k++;
    }
    qDebug() << k << ":" << QDateTime::currentDateTime().time();
}


void iBoat::process_IVNIND() {
    qint64 k = 0;
    QList<TrajectoryIBoat *> *workingSet;
    foreach (TrajectoryIBoat *traj, trajectoryData.listTrajectories) {
        // set working set to set of trajectories which go through cell
        workingSet = &(traj->listCells.first()->listTrajectory);
//        qDebug() << "workingSetFirst: " << workingSet->length();
        // remove actual testing trajectory
        // so it does not effect results
//        workingSet->removeAll(traj);
        qint64 i = 0;
        QList<CellIBoat *> window;
        double supportV = 0.0;
        PointFTime prevPoint = traj->listPoints.first();
        foreach (PointFTime point, traj->listPoints) {
            i++;
            // map point to cell
            CellIBoat *cell = trajectoryData.listCells[QPair<qint64, qint64>(trajectoryData.computeIndexX(point.x()), trajectoryData.computeIndexY(point.y()))];
            window.append(cell);
            QList<TrajectoryIBoat *> *hasPathSet = hasPathWindowOPT(*workingSet, window);
//            qDebug() << "hasPathSet: " << hasPathSet->length();
            supportV = support(hasPathSet, workingSet);
//            qDebug() << "support: " << supportV;
            workingSet = hasPathSet;
//            qDebug() << "workingSetHas: " << workingSet->length();
            if (isThetaAnomalous(supportV)) {
                // point is anomalous
                // set point as anomalous
                traj->listAnomalousIndex.append(i-1);
                traj->listAnomalousPoints.append(point);
                // reset working set to set of trajectories which go through cell
                workingSet = &cell->listTrajectory;
//                qDebug() << "workingSetAfter: " << workingSet->length();
                // remove actual testing trajectory
                // so it does not effect results
//                workingSet->removeAll(traj);
                // reset window
                window.clear();
                window.append(cell);
            }
            // compute score for every point (even if its not anomalous)
            traj->score.append(traj->score[i-1] + sigma(supportV) * euclideanDistanceI(prevPoint, point));
            prevPoint = point;
        }
        qDebug() << k << ":" << QDateTime::currentDateTime().time();
        k++;
    }
}

QList<TrajectoryIBoat *> *iBoat::hasPathWindow(QList<TrajectoryIBoat *> &workingSet, QList<CellIBoat *> window) {
    QList<TrajectoryIBoat *> *listTrajHasPath = new QList<TrajectoryIBoat *>();
    foreach (TrajectoryIBoat *traj, workingSet) {
        bool allCellOk = true;
        bool allCellOrderOk = true;
        bool findNeighbor = false;
        foreach (CellIBoat *cell, window) {
            // check if all cells in window are in trajecotry
            foreach (CellIBoat *cellHis, traj->listCells) {
                if (trajectoryData.isCellsNeighbor(cell->cell, cellHis->cell)) {
                    findNeighbor = true;
                    break;
                }
            }
            if (!findNeighbor) {
                allCellOk = false;
                allCellOrderOk = false;
                break;
            }
            findNeighbor = false;
        }
        if (allCellOk) {
            // check if all cells in window are in trajecotry in correct order
            for (qint64 i = 0; i < window.size()-1; i++) {
                if (!(pos(traj, neighborsCells(window[i])) <= pos(traj, neighborsCells(window[i+1])))) {
                    allCellOrderOk = false;
                    break;
                }
            }
        }
        if (allCellOrderOk)
            listTrajHasPath->append(traj);
    }
    return listTrajHasPath;
}

QList<TrajectoryIBoat *> *iBoat::hasPathWindowOPT(QList<TrajectoryIBoat *> &workingSet, QList<CellIBoat *> window) {
    QList<TrajectoryIBoat *> *listTrajHasPath = new QList<TrajectoryIBoat *>();
    foreach (TrajectoryIBoat *traj, workingSet) {
        bool findNeighbor = false;
        bool findNeighbor2 = false;

        foreach (CellIBoat *cellHis, traj->listCells) {
            if (trajectoryData.isCellsNeighbor(window.last()->cell, cellHis->cell)) {
                findNeighbor = true;
                break;
            }
        }

        if (findNeighbor && window.size() >= 2) {
            foreach (CellIBoat *cellHis, traj->listCells) {
                if (trajectoryData.isCellsNeighbor(window[window.size()-2]->cell, cellHis->cell)) {
                    findNeighbor2 = true;
                    break;
                }
            }
            // check if last two cells in window are in trajecotry in correct order
            if (findNeighbor2) {
                if (pos(traj, neighborsCells(window[window.size()-2])) <= pos(traj, neighborsCells(window.last()))) {
                    listTrajHasPath->append(traj);
                }
            }
        }
        else if (findNeighbor && window.size() == 1) { // only one cell so trajectory is neighbor
            listTrajHasPath->append(traj);
        }
    }
    return listTrajHasPath;
}

double iBoat::support(QList<TrajectoryIBoat *> *hasPathSet, QList<TrajectoryIBoat *> *workingSet) {
    if (workingSet->size() == 0)
        return 0;
    // -1 because one trajectory is the same
    return double(hasPathSet->size()-1) / double(workingSet->size()-1);
}

qint64 iBoat::pos(TrajectoryIBoat *traj, QList<QPoint> listNeighborsCells) {
    qint64 i = 0;
    foreach (CellIBoat *cellTraj, traj->listCells) {
        foreach (QPoint cell, listNeighborsCells) {
            if (cell == cellTraj->cell) {
                return i;
            }
        }
        i++;
    }
    return -1;
}

QList<QPoint> iBoat::neighborsCells(CellIBoat *cell) {
    QList<QPoint> listNeighoborsPoint;
    for (qint64 x = -1; x < 2; x++) {
        for (qint64 y = -1; y < 2; y++) {
            QPoint point(cell->cell.x() + x, cell->cell.y() + y);
            listNeighoborsPoint.append(point);
        }
    }
    return listNeighoborsPoint;
}

bool iBoat::isThetaAnomalous(double supportV) {
    if (supportV < Theta)
        return true;
    return false;
}

double iBoat::sigma(double supportV) {
    return 1.0 / (1.0 + qExp(Lambda * (supportV - Theta)));
}

double euclideanDistanceI(QPointF startPoint, QPointF endPoint) {
    return qSqrt( qPow(endPoint.x()-startPoint.x(), 2) + qPow(endPoint.y()-startPoint.y(), 2) );
}
