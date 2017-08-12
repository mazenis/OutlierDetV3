#ifndef IBOATTRAJECTORY_HPP
#define IBOATTRAJECTORY_HPP

#include <QObject>
#include <QPoint>
#include <QList>
#include <QDateTime>

class TrajectoryIBoat;
class PointFTime;

class CellIBoat
{
    public:
	// X and Y of cell
        CellIBoat(QPoint cell);
        // trajectories wich are in cell
        QPoint cell;
        
        // where key is position of cell in trajectory
        QMap<qint64, QList<TrajectoryIBoat *>> listTrajectoryPosition;
        QList<TrajectoryIBoat *> listTrajectory;
        // add new trajecoty to cell
        void addTraj(qint64 pos, TrajectoryIBoat *traj);
};

class TrajectoryIBoat
{
    public:
        TrajectoryIBoat(qint64 ID);
        qint64 ID;
        // list of cells via trajectories go
        QList<CellIBoat *> listCells;
        // list of trajectory points
        QList<PointFTime> listPoints;
        // anomaly scores, list for all points
        QList<double> score;
        // list of anomalous points
        QList<PointFTime> listAnomalousPoints;
        // list of index to listPoints
        // for anomalous points
        QList<qint64> listAnomalousIndex;
        // time of trajectory start
        qreal timeNum;
        QDateTime time;
};

class PointFTime : public QPointF       //Konarek
{
    private:
        qreal timeNump;
        QDateTime timep;
    public:
        PointFTime();
        PointFTime(qreal xpos, qreal ypos, qreal timeNum);
        PointFTime(qreal xpos, qreal ypos, QDateTime time);
        inline QDateTime time() const;
        inline qreal timeNum() const;

        inline void setTimeNum(qreal timeNum);
        inline void setTime(QDateTime time);




};



#endif // IBOATTRAJECTORY_HPP
