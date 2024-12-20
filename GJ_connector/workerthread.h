#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#endif // WORKERTHREAD_H

#include <QThread>
#include <QObject>
#include <QMutex>
#include <QWaitCondition>

class WorkerThread : public QThread {
    Q_OBJECT

public:
    WorkerThread(QObject* parent = nullptr);

    ~WorkerThread();


    void run() override ;

    void stopThread();
    void pauseThread();
    void continueThread();

signals:
    void updateDynamicCaliData();

private:
    bool stop;
    bool pause;
    QMutex mutex;
    QWaitCondition condition;
};
