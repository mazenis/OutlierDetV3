#include "iboattrajectory.hpp"

TrajectoryIBoat::TrajectoryIBoat(qint64 ID) : ID(ID) {
    timeNum = 0.0;
    score.append(0.0);
}


CellIBoat::CellIBoat(QPoint cell) : cell(cell) {

}

PointFTime::PointFTime() : QPointF (0,0), timeNump(0), timep() {
}

PointFTime::PointFTime(qreal xpos, qreal ypos, qreal timeNum) : QPointF(xpos, ypos), timeNump(timeNum), timep() {   //Konarek

}

PointFTime::PointFTime(qreal xpos, qreal ypos, QDateTime time) : QPointF(xpos, ypos), timeNump(0)  {    //Konarek
    timep = time;
}

inline QDateTime PointFTime::time() const {
    return timep;
}

inline qreal PointFTime::timeNum() const {
    return timeNump;
}

inline void PointFTime::setTimeNum(qreal timeNum) { //Konarek
    timeNump = timeNum;
}

inline void PointFTime::setTime(QDateTime time) {   //Konarek
    timep = time;
}

void CellIBoat::addTraj(qint64 pos, TrajectoryIBoat *traj) {
    if (listTrajectoryPosition.contains(pos)) {
        listTrajectoryPosition[pos].append(traj);
    }
    else {
        QList<TrajectoryIBoat *> newList;
        newList.append(traj);
        listTrajectoryPosition.insert(pos, newList);
    }
    listTrajectory.append(traj);
}
