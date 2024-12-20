#ifndef GLOBALSETTING_H
#define GLOBALSETTING_H

#include <QObject>
#include <QScopedPointer>
#include <QVariant>
#include <memory>
#include <QMetaType>
#include <QMutex>
#include "./global/GJ_Protocol.h"

//让QMateType 知道GJDeVice_MsgBuf_1000数据类型
Q_DECLARE_METATYPE(GJDeVice_MsgBuf_1000*)
Q_DECLARE_METATYPE(GJDeVice_MsgBuf*)

enum ProjectMoudel
{
    E_VSMS1000 = 0,
    E_A920,
    E_660,
    E_802,
    E_602
};

class GlobalSetting : public QObject
{
    Q_OBJECT

public:

    static GlobalSetting *getInstance()
    {
        static GlobalSetting obj;
        return &obj;
    }

    void setMoudelType(ProjectMoudel type);
    ProjectMoudel getMoudelType();

    std::unique_ptr<GJDeVice_Dynamic_MsgBuf_t>& getMsg1000DynamicDataRef()
    {
         QMutexLocker locker(&mutex_);
        return msg1000DynamicData_;  // 返回 std::unique_ptr 的引用 指针
    }


    QVariant getMsgBuf()
    {
        QMutexLocker locker(&mutex_);
       if (priProjectMoudel_ == E_VSMS1000)
       {
           return QVariant::fromValue<GJDeVice_MsgBuf_1000Vertion*>(msgType1000_.get());//获取指针
       }
       else
       {
           return QVariant::fromValue<GJDeVice_MsgBuf_920Vertion*>(msgType920_.get());
       }
    }

private:
    ProjectMoudel priProjectMoudel_ = E_VSMS1000;

    GlobalSetting()
        : msgType920_(std::make_unique<GJDeVice_MsgBuf_920Vertion>()),
          msgType1000_(std::make_unique<GJDeVice_MsgBuf_1000Vertion>())
    {

    };
    ~GlobalSetting() = default;
    GlobalSetting(const GlobalSetting &) = delete;
    const GlobalSetting &operator=(const GlobalSetting &) = delete;

    //易变互斥量
    mutable QMutex mutex_;
    //指向<..>内结构体的空指针
    std::unique_ptr<GJDeVice_MsgBuf_920Vertion> msgType920_;
    std::unique_ptr<GJDeVice_MsgBuf_1000Vertion> msgType1000_;
    std::unique_ptr<GJDeVice_Dynamic_MsgBuf_t> msg1000DynamicData_;
};

#endif // GLOBALSETTING_H
