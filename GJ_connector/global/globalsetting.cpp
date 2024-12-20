#include "globalsetting.h"

void GlobalSetting::setMoudelType(ProjectMoudel type)
{
    QMutexLocker locker(&mutex_);
    priProjectMoudel_ = type;
}

ProjectMoudel GlobalSetting::getMoudelType()
{
    QMutexLocker locker(&mutex_);
    return priProjectMoudel_;
}

