#include "traodtrajecotrydata.hpp"

TRAODTrajecotryData::TRAODTrajecotryData() {
//    listTrajectories = new QList<Trajectory *>();
}

void TRAODTrajecotryData::readHurricaneFromFile(QString filePath) {
    cleanLists();
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        qDebug() << "error load file";
        return;
    }
    file.readLine();
    file.readLine();
    while(!file.atEnd()) {
        Trajectory *newTraj = new Trajectory();
        QString line = file.readLine();
        QStringList data = line.split(" ");
        for (qint64 i = 2; i < data.size()-1; i+=2) {
            newTraj->addPoint(QPointF(data[i].toDouble(), data[i+1].toDouble()));
        }
        listTrajectories.append(newTraj);
    }
    file.close();
}

void TRAODTrajecotryData::readPortoTaxiFromFile(QString filePath) {
    cleanLists();
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        qDebug() << "error load file";
        return ;
    }
    while(!file.atEnd()) {
        Trajectory *newTraj = new Trajectory();
        QString line = file.readLine();
        QStringList data = line.split(";");
        newTraj->time = data[0].toDouble();
        for (qint64 i = 1; i < data.size(); i++) {
            QStringList data2 = data[i].split(",");
            double x = (data2[0].toDouble()-(-8.8))/((-8.5)-(-8.8)) * 1000;
            double y = (data2[1].toDouble()-41.09)/(41.27-41.09) * 1000;
            newTraj->addPoint(QPointF(x, y));
        }
        listTrajectories.append(newTraj);
    }
    file.close();
}

void TRAODTrajecotryData::cleanLists() {
    foreach (Trajectory *traj, listTrajectories) {
        qDeleteAll(traj->listCoarseSegments.begin(), traj->listCoarseSegments.end());
        traj->listCoarseSegments.clear();
        qDeleteAll(traj->listSegments.begin(), traj->listSegments.end());
        traj->listSegments.clear();
    }
    qDeleteAll(listTrajectories.begin(), listTrajectories.end());
    listTrajectories.clear();
}
