#include "workerthread.h"


WorkerThread::WorkerThread(QObject* parent) : QThread(parent)
{
    stop = false;
    pause = false;
}

WorkerThread::~WorkerThread()
{
    stopThread();
    wait();
}

void WorkerThread::run()
{
    while (true) {
        mutex.lock();
        if (stop) {
            mutex.unlock();
            break;
        }

        if (pause) {
            condition.wait(&mutex); // 释放互斥量并等待唤醒
        }
        mutex.unlock(); // 解锁互斥量
        emit updateDynamicCaliData();
        QThread::msleep(10);
    }
}

void WorkerThread::stopThread()
{
    QMutexLocker locker(&mutex);
    stop = true;
    pause = false;
    condition.wakeAll();//唤醒所有等待的线程
}

void WorkerThread::pauseThread()
{
    QMutexLocker locker(&mutex);
    pause = true;
}

void WorkerThread::continueThread() {
    QMutexLocker locker(&mutex);
    pause = false;
    condition.wakeAll();
}
