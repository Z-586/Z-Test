/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_TrackMap;
    QAction *action_FirmWare;
    QAction *action_VersionMsg;
    QAction *action_TempCali;
    QAction *action_PollingData;
    QAction *action_Encryption;
    QAction *action_ProtocolChange;
    QAction *action_CustomCan;
    QAction *action_advanced;
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *label_61;
    QLabel *label_5;
    QComboBox *ComboBox_Port;
    QComboBox *ComboBox_Baud;
    QLabel *label_4;
    QComboBox *ComboBox_BitNum;
    QComboBox *ComboBox_Parity;
    QComboBox *ComboBox_Stop;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QPushButton *PushButton_CheckSerial;
    QPushButton *PushButton_OpenSerial;
    QFrame *frame_4;
    QLabel *label_72;
    QPushButton *PushButton_CaliDialog;
    QFrame *frame_5;
    QLabel *label_53;
    QLabel *Label_SaveSerialData_StateMsg;
    QPushButton *PushButton_SaveSerialData_StartSave;
    QPushButton *PushButton_SaveSerialData_SeletePath;
    QCheckBox *CheckBox_SaveSerialData_WithTime;
    QFrame *frame_6;
    QLabel *label_29;
    QLineEdit *LineEdit_az;
    QLabel *label_85;
    QLabel *label_86;
    QLabel *label_44;
    QLabel *label_21;
    QLabel *label_18;
    QLineEdit *LineEdit_ax;
    QLabel *label_20;
    QLineEdit *LineEdit_ay;
    QLabel *label_28;
    QLabel *label_27;
    QLineEdit *LineEdit_gz;
    QLabel *label_40;
    QLabel *label_26;
    QLabel *label_42;
    QLineEdit *LineEdit_gx;
    QLabel *label_16;
    QLineEdit *LineEdit_gy;
    QFrame *frame_2;
    QLabel *label_51;
    QLabel *label_70;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_50;
    QLineEdit *LineEdit_Lat;
    QLabel *label_64;
    QLabel *label_55;
    QLineEdit *LineEdit_VE;
    QLabel *label_88;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_52;
    QLineEdit *LineEdit_Lon;
    QLabel *label_49;
    QLabel *label_56;
    QLineEdit *LineEdit_VN;
    QLabel *label_48;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_54;
    QLineEdit *LineEdit_Height;
    QLabel *label_71;
    QLabel *label_57;
    QLineEdit *LineEdit_VU;
    QLabel *label_87;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_58;
    QLineEdit *LineEdit_Pitch;
    QLabel *label_68;
    QLabel *label_59;
    QLineEdit *LineEdit_Roll;
    QLabel *label_69;
    QFrame *frameVSMS1000InstallInfo;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_73;
    QLineEdit *LineEditINSVehicleLongitudinal;
    QLabel *label_60;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_76;
    QLineEdit *LineEditINSVehicleLateral;
    QLabel *label_77;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_74;
    QLineEdit *LineEditINSVehicleVertical;
    QLabel *label_75;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_78;
    QLineEdit *LineEditINSVehicleSlideslipangle;
    QLabel *label_79;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_62;
    QLineEdit *LineEdit_Heading;
    QFrame *frame_3;
    QLabel *label_41;
    QLineEdit *LineEdit_VehicleSpeed;
    QLabel *label_43;
    QLabel *label_10;
    QLabel *label_13;
    QLineEdit *LineEdit_RLSpeed;
    QLabel *label_63;
    QLineEdit *LineEdit_FLSpeed;
    QLabel *label_65;
    QLabel *label_15;
    QLabel *label_12;
    QLineEdit *LineEdit_RRSpeed;
    QLineEdit *LineEdit_FRSpeed;
    QLabel *label_67;
    QLabel *label_14;
    QLabel *label_66;
    QToolBar *toolBar;
    QStatusBar *statusBar_position;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1071, 884);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1071, 884));
        MainWindow->setMaximumSize(QSize(1071, 884));
        MainWindow->setFocusPolicy(Qt::NoFocus);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        MainWindow->setAnimated(true);
        action_TrackMap = new QAction(MainWindow);
        action_TrackMap->setObjectName(QString::fromUtf8("action_TrackMap"));
        action_FirmWare = new QAction(MainWindow);
        action_FirmWare->setObjectName(QString::fromUtf8("action_FirmWare"));
        action_VersionMsg = new QAction(MainWindow);
        action_VersionMsg->setObjectName(QString::fromUtf8("action_VersionMsg"));
        action_VersionMsg->setVisible(true);
        action_TempCali = new QAction(MainWindow);
        action_TempCali->setObjectName(QString::fromUtf8("action_TempCali"));
        action_PollingData = new QAction(MainWindow);
        action_PollingData->setObjectName(QString::fromUtf8("action_PollingData"));
        action_Encryption = new QAction(MainWindow);
        action_Encryption->setObjectName(QString::fromUtf8("action_Encryption"));
        action_ProtocolChange = new QAction(MainWindow);
        action_ProtocolChange->setObjectName(QString::fromUtf8("action_ProtocolChange"));
        action_CustomCan = new QAction(MainWindow);
        action_CustomCan->setObjectName(QString::fromUtf8("action_CustomCan"));
        action_advanced = new QAction(MainWindow);
        action_advanced->setObjectName(QString::fromUtf8("action_advanced"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        centralwidget->setStyleSheet(QString::fromUtf8(".QPushButton{\n"
"	background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9,\n"
"		stop:0.494318 rgba(214, 214, 214, 255), stop:0.5 rgba(236, 236, 236, 255));\n"
"	border: 1px solid rgb(124, 124, 124);\n"
"	border-radius:2px;\n"
"}\n"
".QPushButton:hover{\n"
"background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9,\n"
"	stop:0.494318 rgba(181, 225, 250, 255), stop:0.5 rgba(222, 242, 251, 255));\n"
"border: 1px solid #3C80B1;\n"
"}\n"
".QPushButton:pressed{\n"
"	background-color: qconicalgradient(cx:0.5, cy:0.522909, angle:179.9,\n"
"		stop:0.494318 rgba(134, 198, 233, 255), stop:0.5 rgba(206, 234, 248, 255));\n"
"	border: 1px solid #5F92B2;\n"
"}\n"
"\n"
"/* \346\234\252\344\270\213\346\213\211\346\227\266\357\274\214QComboBox\347\232\204\346\240\267\345\274\217 */\n"
"QComboBox {\n"
"    border: 1px solid gray;   /* \350\276\271\346\241\206 */\n"
"    border-radius: 3px;   /* \345\234\206\350\247\222 */\n"
"    padding: 1px 18px 1px 3px;   /* \345\255\227\344\275\223\345\241\253\350\241"
                        "\254 */\n"
"    color: #000;\n"
"    font: normal normal 15px \"Microsoft YaHei\";\n"
"    background: transparent;\n"
"}\n"
"\n"
"/* \344\270\213\346\213\211\345\220\216\357\274\214\346\225\264\344\270\252\344\270\213\346\213\211\347\252\227\344\275\223\346\240\267\345\274\217 */\n"
"QComboBox QAbstractItemView {\n"
"    outline: 0px solid gray;   /* \351\200\211\345\256\232\351\241\271\347\232\204\350\231\232\346\241\206 */\n"
"}\n"
"\n"
"\n"
"/* QComboBox\344\270\255\347\232\204\345\236\202\347\233\264\346\273\232\345\212\250\346\235\241 */\n"
"QComboBox QAbstractScrollArea QScrollBar:vertical {\n"
"    width: 10px;\n"
"    background-color: #d0d2d4;   /* \347\251\272\347\231\275\345\214\272\345\237\237\347\232\204\350\203\214\346\231\257\350\211\262  \347\201\260\350\211\262green */\n"
"}\n"
"\n"
"QComboBox QAbstractScrollArea QScrollBar::handle:vertical {\n"
"    border-radius: 5px;   /* \345\234\206\350\247\222 */\n"
"    background: rgb(160,160,160);   /* \345\260\217\346\226\271\345\235\227\347\232\204"
                        "\350\203\214\346\231\257\350\211\262\346\267\261\347\201\260lightblue */\n"
"}\n"
"\n"
"QComboBox QAbstractScrollArea QScrollBar::handle:vertical:hover {\n"
"    background: rgb(90, 91, 93);   /* \350\266\212\350\277\207\345\260\217\346\226\271\345\235\227\347\232\204\350\203\214\346\231\257\350\211\262yellow */\n"
"}"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 261, 471));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy2);
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        label_61 = new QLabel(frame);
        label_61->setObjectName(QString::fromUtf8("label_61"));
        label_61->setGeometry(QRect(10, 20, 241, 41));
        sizePolicy2.setHeightForWidth(label_61->sizePolicy().hasHeightForWidth());
        label_61->setSizePolicy(sizePolicy2);
        label_61->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(16);
        label_61->setFont(font);
        label_61->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 110, 91, 31));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setPointSize(10);
        label_5->setFont(font1);
        ComboBox_Port = new QComboBox(frame);
        ComboBox_Port->setObjectName(QString::fromUtf8("ComboBox_Port"));
        ComboBox_Port->setGeometry(QRect(120, 110, 131, 31));
        sizePolicy2.setHeightForWidth(ComboBox_Port->sizePolicy().hasHeightForWidth());
        ComboBox_Port->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Microsoft YaHei"));
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        ComboBox_Port->setFont(font2);
        ComboBox_Port->setStyleSheet(QString::fromUtf8(""));
        ComboBox_Baud = new QComboBox(frame);
        ComboBox_Baud->addItem(QString());
        ComboBox_Baud->addItem(QString());
        ComboBox_Baud->addItem(QString());
        ComboBox_Baud->addItem(QString());
        ComboBox_Baud->addItem(QString());
        ComboBox_Baud->addItem(QString());
        ComboBox_Baud->addItem(QString());
        ComboBox_Baud->addItem(QString());
        ComboBox_Baud->addItem(QString());
        ComboBox_Baud->addItem(QString());
        ComboBox_Baud->addItem(QString());
        ComboBox_Baud->addItem(QString());
        ComboBox_Baud->addItem(QString());
        ComboBox_Baud->setObjectName(QString::fromUtf8("ComboBox_Baud"));
        ComboBox_Baud->setGeometry(QRect(120, 170, 131, 31));
        sizePolicy2.setHeightForWidth(ComboBox_Baud->sizePolicy().hasHeightForWidth());
        ComboBox_Baud->setSizePolicy(sizePolicy2);
        ComboBox_Baud->setFont(font2);
        ComboBox_Baud->setStyleSheet(QString::fromUtf8(""));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 170, 91, 31));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setFont(font1);
        ComboBox_BitNum = new QComboBox(frame);
        ComboBox_BitNum->addItem(QString());
        ComboBox_BitNum->addItem(QString());
        ComboBox_BitNum->addItem(QString());
        ComboBox_BitNum->addItem(QString());
        ComboBox_BitNum->setObjectName(QString::fromUtf8("ComboBox_BitNum"));
        ComboBox_BitNum->setGeometry(QRect(120, 230, 131, 31));
        sizePolicy2.setHeightForWidth(ComboBox_BitNum->sizePolicy().hasHeightForWidth());
        ComboBox_BitNum->setSizePolicy(sizePolicy2);
        ComboBox_BitNum->setFont(font2);
        ComboBox_Parity = new QComboBox(frame);
        ComboBox_Parity->addItem(QString());
        ComboBox_Parity->addItem(QString());
        ComboBox_Parity->addItem(QString());
        ComboBox_Parity->addItem(QString());
        ComboBox_Parity->addItem(QString());
        ComboBox_Parity->addItem(QString());
        ComboBox_Parity->setObjectName(QString::fromUtf8("ComboBox_Parity"));
        ComboBox_Parity->setGeometry(QRect(120, 290, 131, 31));
        sizePolicy2.setHeightForWidth(ComboBox_Parity->sizePolicy().hasHeightForWidth());
        ComboBox_Parity->setSizePolicy(sizePolicy2);
        ComboBox_Parity->setFont(font2);
        ComboBox_Stop = new QComboBox(frame);
        ComboBox_Stop->addItem(QString());
        ComboBox_Stop->addItem(QString());
        ComboBox_Stop->setObjectName(QString::fromUtf8("ComboBox_Stop"));
        ComboBox_Stop->setGeometry(QRect(120, 350, 131, 31));
        sizePolicy2.setHeightForWidth(ComboBox_Stop->sizePolicy().hasHeightForWidth());
        ComboBox_Stop->setSizePolicy(sizePolicy2);
        ComboBox_Stop->setFont(font2);
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 230, 91, 31));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setFont(font1);
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 290, 91, 31));
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setFont(font1);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 350, 91, 31));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setFont(font1);
        PushButton_CheckSerial = new QPushButton(frame);
        PushButton_CheckSerial->setObjectName(QString::fromUtf8("PushButton_CheckSerial"));
        PushButton_CheckSerial->setGeometry(QRect(15, 420, 111, 30));
        sizePolicy2.setHeightForWidth(PushButton_CheckSerial->sizePolicy().hasHeightForWidth());
        PushButton_CheckSerial->setSizePolicy(sizePolicy2);
        PushButton_CheckSerial->setMaximumSize(QSize(16777215, 30));
        QFont font3;
        font3.setPointSize(11);
        font3.setBold(false);
        font3.setWeight(50);
        PushButton_CheckSerial->setFont(font3);
        PushButton_CheckSerial->setStyleSheet(QString::fromUtf8(""));
        PushButton_CheckSerial->setCheckable(false);
        PushButton_CheckSerial->setAutoDefault(false);
        PushButton_CheckSerial->setFlat(false);
        PushButton_OpenSerial = new QPushButton(frame);
        PushButton_OpenSerial->setObjectName(QString::fromUtf8("PushButton_OpenSerial"));
        PushButton_OpenSerial->setGeometry(QRect(135, 420, 111, 30));
        sizePolicy2.setHeightForWidth(PushButton_OpenSerial->sizePolicy().hasHeightForWidth());
        PushButton_OpenSerial->setSizePolicy(sizePolicy2);
        PushButton_OpenSerial->setMaximumSize(QSize(16777215, 30));
        PushButton_OpenSerial->setFont(font3);
        PushButton_OpenSerial->setStyleSheet(QString::fromUtf8(""));
        PushButton_OpenSerial->setCheckable(false);
        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(10, 490, 261, 131));
        sizePolicy2.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy2);
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Raised);
        label_72 = new QLabel(frame_4);
        label_72->setObjectName(QString::fromUtf8("label_72"));
        label_72->setEnabled(false);
        label_72->setGeometry(QRect(10, 10, 241, 73));
        sizePolicy2.setHeightForWidth(label_72->sizePolicy().hasHeightForWidth());
        label_72->setSizePolicy(sizePolicy2);
        label_72->setFont(font1);
        label_72->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0)"));
        label_72->setAlignment(Qt::AlignCenter);
        label_72->setWordWrap(true);
        PushButton_CaliDialog = new QPushButton(frame_4);
        PushButton_CaliDialog->setObjectName(QString::fromUtf8("PushButton_CaliDialog"));
        PushButton_CaliDialog->setGeometry(QRect(20, 90, 221, 31));
        sizePolicy2.setHeightForWidth(PushButton_CaliDialog->sizePolicy().hasHeightForWidth());
        PushButton_CaliDialog->setSizePolicy(sizePolicy2);
        PushButton_CaliDialog->setMinimumSize(QSize(100, 25));
        PushButton_CaliDialog->setMaximumSize(QSize(16777215, 16777215));
        QFont font4;
        font4.setPointSize(11);
        PushButton_CaliDialog->setFont(font4);
        PushButton_CaliDialog->setLayoutDirection(Qt::LeftToRight);
        PushButton_CaliDialog->setStyleSheet(QString::fromUtf8(""));
        frame_5 = new QFrame(centralwidget);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setGeometry(QRect(10, 630, 261, 201));
        sizePolicy2.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy2);
        frame_5->setFrameShape(QFrame::Box);
        frame_5->setFrameShadow(QFrame::Raised);
        label_53 = new QLabel(frame_5);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setGeometry(QRect(10, 20, 241, 27));
        sizePolicy2.setHeightForWidth(label_53->sizePolicy().hasHeightForWidth());
        label_53->setSizePolicy(sizePolicy2);
        label_53->setFont(font);
        label_53->setAlignment(Qt::AlignCenter);
        Label_SaveSerialData_StateMsg = new QLabel(frame_5);
        Label_SaveSerialData_StateMsg->setObjectName(QString::fromUtf8("Label_SaveSerialData_StateMsg"));
        Label_SaveSerialData_StateMsg->setEnabled(false);
        Label_SaveSerialData_StateMsg->setGeometry(QRect(10, 60, 241, 61));
        sizePolicy2.setHeightForWidth(Label_SaveSerialData_StateMsg->sizePolicy().hasHeightForWidth());
        Label_SaveSerialData_StateMsg->setSizePolicy(sizePolicy2);
        Label_SaveSerialData_StateMsg->setFont(font1);
        Label_SaveSerialData_StateMsg->setAcceptDrops(false);
        Label_SaveSerialData_StateMsg->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0)"));
        Label_SaveSerialData_StateMsg->setAlignment(Qt::AlignCenter);
        Label_SaveSerialData_StateMsg->setWordWrap(true);
        Label_SaveSerialData_StateMsg->setMargin(0);
        PushButton_SaveSerialData_StartSave = new QPushButton(frame_5);
        PushButton_SaveSerialData_StartSave->setObjectName(QString::fromUtf8("PushButton_SaveSerialData_StartSave"));
        PushButton_SaveSerialData_StartSave->setEnabled(false);
        PushButton_SaveSerialData_StartSave->setGeometry(QRect(135, 160, 111, 30));
        sizePolicy2.setHeightForWidth(PushButton_SaveSerialData_StartSave->sizePolicy().hasHeightForWidth());
        PushButton_SaveSerialData_StartSave->setSizePolicy(sizePolicy2);
        PushButton_SaveSerialData_StartSave->setMinimumSize(QSize(100, 25));
        PushButton_SaveSerialData_StartSave->setMaximumSize(QSize(16777215, 16777215));
        PushButton_SaveSerialData_StartSave->setFont(font4);
        PushButton_SaveSerialData_StartSave->setStyleSheet(QString::fromUtf8(""));
        PushButton_SaveSerialData_SeletePath = new QPushButton(frame_5);
        PushButton_SaveSerialData_SeletePath->setObjectName(QString::fromUtf8("PushButton_SaveSerialData_SeletePath"));
        PushButton_SaveSerialData_SeletePath->setGeometry(QRect(15, 160, 111, 30));
        sizePolicy2.setHeightForWidth(PushButton_SaveSerialData_SeletePath->sizePolicy().hasHeightForWidth());
        PushButton_SaveSerialData_SeletePath->setSizePolicy(sizePolicy2);
        PushButton_SaveSerialData_SeletePath->setMinimumSize(QSize(100, 25));
        PushButton_SaveSerialData_SeletePath->setMaximumSize(QSize(16777215, 16777215));
        PushButton_SaveSerialData_SeletePath->setFont(font4);
        PushButton_SaveSerialData_SeletePath->setStyleSheet(QString::fromUtf8(""));
        CheckBox_SaveSerialData_WithTime = new QCheckBox(frame_5);
        CheckBox_SaveSerialData_WithTime->setObjectName(QString::fromUtf8("CheckBox_SaveSerialData_WithTime"));
        CheckBox_SaveSerialData_WithTime->setGeometry(QRect(20, 130, 111, 19));
        frame_6 = new QFrame(centralwidget);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setGeometry(QRect(280, 10, 781, 261));
        sizePolicy2.setHeightForWidth(frame_6->sizePolicy().hasHeightForWidth());
        frame_6->setSizePolicy(sizePolicy2);
        frame_6->setFrameShape(QFrame::Box);
        frame_6->setFrameShadow(QFrame::Raised);
        label_29 = new QLabel(frame_6);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(10, 20, 761, 41));
        sizePolicy2.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy2);
        label_29->setMaximumSize(QSize(16777215, 16777215));
        label_29->setFont(font);
        label_29->setTextFormat(Qt::AutoText);
        label_29->setAlignment(Qt::AlignCenter);
        LineEdit_az = new QLineEdit(frame_6);
        LineEdit_az->setObjectName(QString::fromUtf8("LineEdit_az"));
        LineEdit_az->setEnabled(false);
        LineEdit_az->setGeometry(QRect(90, 200, 241, 31));
        sizePolicy2.setHeightForWidth(LineEdit_az->sizePolicy().hasHeightForWidth());
        LineEdit_az->setSizePolicy(sizePolicy2);
        LineEdit_az->setFont(font1);
        LineEdit_az->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0)"));
        label_85 = new QLabel(frame_6);
        label_85->setObjectName(QString::fromUtf8("label_85"));
        label_85->setGeometry(QRect(340, 70, 51, 51));
        sizePolicy2.setHeightForWidth(label_85->sizePolicy().hasHeightForWidth());
        label_85->setSizePolicy(sizePolicy2);
        label_85->setFont(font1);
        label_86 = new QLabel(frame_6);
        label_86->setObjectName(QString::fromUtf8("label_86"));
        label_86->setGeometry(QRect(340, 190, 51, 51));
        sizePolicy2.setHeightForWidth(label_86->sizePolicy().hasHeightForWidth());
        label_86->setSizePolicy(sizePolicy2);
        label_86->setFont(font1);
        label_44 = new QLabel(frame_6);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(340, 130, 51, 51));
        sizePolicy2.setHeightForWidth(label_44->sizePolicy().hasHeightForWidth());
        label_44->setSizePolicy(sizePolicy2);
        label_44->setFont(font1);
        label_21 = new QLabel(frame_6);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(30, 190, 51, 51));
        sizePolicy2.setHeightForWidth(label_21->sizePolicy().hasHeightForWidth());
        label_21->setSizePolicy(sizePolicy2);
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(false);
        font5.setWeight(50);
        label_21->setFont(font5);
        label_18 = new QLabel(frame_6);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(30, 70, 51, 51));
        sizePolicy2.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy2);
        label_18->setFont(font5);
        LineEdit_ax = new QLineEdit(frame_6);
        LineEdit_ax->setObjectName(QString::fromUtf8("LineEdit_ax"));
        LineEdit_ax->setEnabled(false);
        LineEdit_ax->setGeometry(QRect(90, 80, 241, 31));
        sizePolicy2.setHeightForWidth(LineEdit_ax->sizePolicy().hasHeightForWidth());
        LineEdit_ax->setSizePolicy(sizePolicy2);
        LineEdit_ax->setFont(font1);
        LineEdit_ax->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0)"));
        label_20 = new QLabel(frame_6);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(30, 130, 51, 51));
        sizePolicy2.setHeightForWidth(label_20->sizePolicy().hasHeightForWidth());
        label_20->setSizePolicy(sizePolicy2);
        label_20->setFont(font5);
        LineEdit_ay = new QLineEdit(frame_6);
        LineEdit_ay->setObjectName(QString::fromUtf8("LineEdit_ay"));
        LineEdit_ay->setEnabled(false);
        LineEdit_ay->setGeometry(QRect(90, 140, 241, 31));
        sizePolicy2.setHeightForWidth(LineEdit_ay->sizePolicy().hasHeightForWidth());
        LineEdit_ay->setSizePolicy(sizePolicy2);
        LineEdit_ay->setFont(font1);
        LineEdit_ay->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0)"));
        label_28 = new QLabel(frame_6);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(410, 190, 51, 51));
        sizePolicy2.setHeightForWidth(label_28->sizePolicy().hasHeightForWidth());
        label_28->setSizePolicy(sizePolicy2);
        label_28->setFont(font5);
        label_27 = new QLabel(frame_6);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(410, 130, 51, 51));
        sizePolicy2.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy2);
        label_27->setFont(font5);
        LineEdit_gz = new QLineEdit(frame_6);
        LineEdit_gz->setObjectName(QString::fromUtf8("LineEdit_gz"));
        LineEdit_gz->setEnabled(false);
        LineEdit_gz->setGeometry(QRect(470, 200, 241, 31));
        sizePolicy2.setHeightForWidth(LineEdit_gz->sizePolicy().hasHeightForWidth());
        LineEdit_gz->setSizePolicy(sizePolicy2);
        LineEdit_gz->setFont(font1);
        LineEdit_gz->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0)"));
        label_40 = new QLabel(frame_6);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(720, 130, 51, 51));
        sizePolicy2.setHeightForWidth(label_40->sizePolicy().hasHeightForWidth());
        label_40->setSizePolicy(sizePolicy2);
        label_40->setFont(font1);
        label_26 = new QLabel(frame_6);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(410, 70, 51, 51));
        sizePolicy2.setHeightForWidth(label_26->sizePolicy().hasHeightForWidth());
        label_26->setSizePolicy(sizePolicy2);
        label_26->setFont(font5);
        label_42 = new QLabel(frame_6);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(720, 190, 51, 51));
        sizePolicy2.setHeightForWidth(label_42->sizePolicy().hasHeightForWidth());
        label_42->setSizePolicy(sizePolicy2);
        label_42->setFont(font1);
        LineEdit_gx = new QLineEdit(frame_6);
        LineEdit_gx->setObjectName(QString::fromUtf8("LineEdit_gx"));
        LineEdit_gx->setEnabled(false);
        LineEdit_gx->setGeometry(QRect(470, 80, 241, 31));
        sizePolicy2.setHeightForWidth(LineEdit_gx->sizePolicy().hasHeightForWidth());
        LineEdit_gx->setSizePolicy(sizePolicy2);
        LineEdit_gx->setFont(font5);
        LineEdit_gx->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0)"));
        LineEdit_gx->setReadOnly(false);
        label_16 = new QLabel(frame_6);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(720, 70, 51, 51));
        sizePolicy2.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy2);
        label_16->setFont(font1);
        LineEdit_gy = new QLineEdit(frame_6);
        LineEdit_gy->setObjectName(QString::fromUtf8("LineEdit_gy"));
        LineEdit_gy->setEnabled(false);
        LineEdit_gy->setGeometry(QRect(470, 140, 241, 31));
        sizePolicy2.setHeightForWidth(LineEdit_gy->sizePolicy().hasHeightForWidth());
        LineEdit_gy->setSizePolicy(sizePolicy2);
        LineEdit_gy->setFont(font1);
        LineEdit_gy->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0)"));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(280, 280, 781, 341));
        sizePolicy2.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy2);
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        label_51 = new QLabel(frame_2);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setGeometry(QRect(150, 20, 341, 21));
        sizePolicy2.setHeightForWidth(label_51->sizePolicy().hasHeightForWidth());
        label_51->setSizePolicy(sizePolicy2);
        label_51->setMaximumSize(QSize(16777215, 16777215));
        QFont font6;
        font6.setPointSize(16);
        font6.setBold(false);
        font6.setWeight(50);
        label_51->setFont(font6);
        label_51->setAlignment(Qt::AlignCenter);
        label_70 = new QLabel(frame_2);
        label_70->setObjectName(QString::fromUtf8("label_70"));
        label_70->setGeometry(QRect(660, 270, 51, 51));
        sizePolicy2.setHeightForWidth(label_70->sizePolicy().hasHeightForWidth());
        label_70->setSizePolicy(sizePolicy2);
        label_70->setFont(font1);
        layoutWidget = new QWidget(frame_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(110, 60, 456, 243));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_50 = new QLabel(layoutWidget);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        sizePolicy2.setHeightForWidth(label_50->sizePolicy().hasHeightForWidth());
        label_50->setSizePolicy(sizePolicy2);
        label_50->setFont(font5);
        label_50->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_50);

        LineEdit_Lat = new QLineEdit(layoutWidget);
        LineEdit_Lat->setObjectName(QString::fromUtf8("LineEdit_Lat"));
        LineEdit_Lat->setEnabled(false);
        sizePolicy2.setHeightForWidth(LineEdit_Lat->sizePolicy().hasHeightForWidth());
        LineEdit_Lat->setSizePolicy(sizePolicy2);
        LineEdit_Lat->setMaximumSize(QSize(16777215, 16777215));
        LineEdit_Lat->setFont(font1);
        LineEdit_Lat->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0)"));

        horizontalLayout->addWidget(LineEdit_Lat);

        label_64 = new QLabel(layoutWidget);
        label_64->setObjectName(QString::fromUtf8("label_64"));
        sizePolicy2.setHeightForWidth(label_64->sizePolicy().hasHeightForWidth());
        label_64->setSizePolicy(sizePolicy2);
        label_64->setFont(font1);

        horizontalLayout->addWidget(label_64);

        label_55 = new QLabel(layoutWidget);
        label_55->setObjectName(QString::fromUtf8("label_55"));
        sizePolicy2.setHeightForWidth(label_55->sizePolicy().hasHeightForWidth());
        label_55->setSizePolicy(sizePolicy2);
        label_55->setFont(font5);

        horizontalLayout->addWidget(label_55);

        LineEdit_VE = new QLineEdit(layoutWidget);
        LineEdit_VE->setObjectName(QString::fromUtf8("LineEdit_VE"));
        LineEdit_VE->setEnabled(false);
        sizePolicy2.setHeightForWidth(LineEdit_VE->sizePolicy().hasHeightForWidth());
        LineEdit_VE->setSizePolicy(sizePolicy2);
        LineEdit_VE->setMaximumSize(QSize(16777215, 16777215));
        LineEdit_VE->setFont(font1);
        LineEdit_VE->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0)"));

        horizontalLayout->addWidget(LineEdit_VE);

        label_88 = new QLabel(layoutWidget);
        label_88->setObjectName(QString::fromUtf8("label_88"));
        sizePolicy2.setHeightForWidth(label_88->sizePolicy().hasHeightForWidth());
        label_88->setSizePolicy(sizePolicy2);
        label_88->setFont(font1);

        horizontalLayout->addWidget(label_88);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_52 = new QLabel(layoutWidget);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        sizePolicy2.setHeightForWidth(label_52->sizePolicy().hasHeightForWidth());
        label_52->setSizePolicy(sizePolicy2);
        label_52->setFont(font5);
        label_52->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_52);

        LineEdit_Lon = new QLineEdit(layoutWidget);
        LineEdit_Lon->setObjectName(QString::fromUtf8("LineEdit_Lon"));
        LineEdit_Lon->setEnabled(false);
        sizePolicy2.setHeightForWidth(LineEdit_Lon->sizePolicy().hasHeightForWidth());
        LineEdit_Lon->setSizePolicy(sizePolicy2);
        LineEdit_Lon->setMaximumSize(QSize(16777215, 16777215));
        LineEdit_Lon->setFont(font1);
        LineEdit_Lon->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0)"));

        horizontalLayout_2->addWidget(LineEdit_Lon);

        label_49 = new QLabel(layoutWidget);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        sizePolicy2.setHeightForWidth(label_49->sizePolicy().hasHeightForWidth());
        label_49->setSizePolicy(sizePolicy2);
        label_49->setFont(font1);

        horizontalLayout_2->addWidget(label_49);

        label_56 = new QLabel(layoutWidget);
        label_56->setObjectName(QString::fromUtf8("label_56"));
        sizePolicy2.setHeightForWidth(label_56->sizePolicy().hasHeightForWidth());
        label_56->setSizePolicy(sizePolicy2);
        label_56->setFont(font5);
        label_56->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_2->addWidget(label_56);

        LineEdit_VN = new QLineEdit(layoutWidget);
        LineEdit_VN->setObjectName(QString::fromUtf8("LineEdit_VN"));
        LineEdit_VN->setEnabled(false);
        sizePolicy2.setHeightForWidth(LineEdit_VN->sizePolicy().hasHeightForWidth());
        LineEdit_VN->setSizePolicy(sizePolicy2);
        LineEdit_VN->setMaximumSize(QSize(16777215, 16777215));
        LineEdit_VN->setFont(font1);
        LineEdit_VN->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0)"));

        horizontalLayout_2->addWidget(LineEdit_VN);

        label_48 = new QLabel(layoutWidget);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        sizePolicy2.setHeightForWidth(label_48->sizePolicy().hasHeightForWidth());
        label_48->setSizePolicy(sizePolicy2);
        label_48->setFont(font1);

        horizontalLayout_2->addWidget(label_48);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_54 = new QLabel(layoutWidget);
        label_54->setObjectName(QString::fromUtf8("label_54"));
        sizePolicy2.setHeightForWidth(label_54->sizePolicy().hasHeightForWidth());
        label_54->setSizePolicy(sizePolicy2);
        label_54->setFont(font5);
        label_54->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_54);

        LineEdit_Height = new QLineEdit(layoutWidget);
        LineEdit_Height->setObjectName(QString::fromUtf8("LineEdit_Height"));
        LineEdit_Height->setEnabled(false);
        sizePolicy2.setHeightForWidth(LineEdit_Height->sizePolicy().hasHeightForWidth());
        LineEdit_Height->setSizePolicy(sizePolicy2);
        LineEdit_Height->setMaximumSize(QSize(16777215, 16777215));
        LineEdit_Height->setFont(font1);
        LineEdit_Height->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0)"));

        horizontalLayout_3->addWidget(LineEdit_Height);

        label_71 = new QLabel(layoutWidget);
        label_71->setObjectName(QString::fromUtf8("label_71"));
        sizePolicy2.setHeightForWidth(label_71->sizePolicy().hasHeightForWidth());
        label_71->setSizePolicy(sizePolicy2);
        label_71->setFont(font1);

        horizontalLayout_3->addWidget(label_71);

        label_57 = new QLabel(layoutWidget);
        label_57->setObjectName(QString::fromUtf8("label_57"));
        sizePolicy2.setHeightForWidth(label_57->sizePolicy().hasHeightForWidth());
        label_57->setSizePolicy(sizePolicy2);
        label_57->setFont(font5);

        horizontalLayout_3->addWidget(label_57);

        LineEdit_VU = new QLineEdit(layoutWidget);
        LineEdit_VU->setObjectName(QString::fromUtf8("LineEdit_VU"));
        LineEdit_VU->setEnabled(false);
        sizePolicy2.setHeightForWidth(LineEdit_VU->sizePolicy().hasHeightForWidth());
        LineEdit_VU->setSizePolicy(sizePolicy2);
        LineEdit_VU->setMaximumSize(QSize(16777215, 16777215));
        LineEdit_VU->setFont(font1);
        LineEdit_VU->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0)"));

        horizontalLayout_3->addWidget(LineEdit_VU);

        label_87 = new QLabel(layoutWidget);
        label_87->setObjectName(QString::fromUtf8("label_87"));
        sizePolicy2.setHeightForWidth(label_87->sizePolicy().hasHeightForWidth());
        label_87->setSizePolicy(sizePolicy2);
        label_87->setFont(font1);

        horizontalLayout_3->addWidget(label_87);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_58 = new QLabel(layoutWidget);
        label_58->setObjectName(QString::fromUtf8("label_58"));
        sizePolicy2.setHeightForWidth(label_58->sizePolicy().hasHeightForWidth());
        label_58->setSizePolicy(sizePolicy2);
        label_58->setFont(font5);
        label_58->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_58);

        LineEdit_Pitch = new QLineEdit(layoutWidget);
        LineEdit_Pitch->setObjectName(QString::fromUtf8("LineEdit_Pitch"));
        LineEdit_Pitch->setEnabled(false);
        sizePolicy2.setHeightForWidth(LineEdit_Pitch->sizePolicy().hasHeightForWidth());
        LineEdit_Pitch->setSizePolicy(sizePolicy2);
        LineEdit_Pitch->setMaximumSize(QSize(16777215, 16777215));
        LineEdit_Pitch->setFont(font1);
        LineEdit_Pitch->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0)"));

        horizontalLayout_4->addWidget(LineEdit_Pitch);

        label_68 = new QLabel(layoutWidget);
        label_68->setObjectName(QString::fromUtf8("label_68"));
        sizePolicy2.setHeightForWidth(label_68->sizePolicy().hasHeightForWidth());
        label_68->setSizePolicy(sizePolicy2);
        label_68->setFont(font1);

        horizontalLayout_4->addWidget(label_68);

        label_59 = new QLabel(layoutWidget);
        label_59->setObjectName(QString::fromUtf8("label_59"));
        sizePolicy2.setHeightForWidth(label_59->sizePolicy().hasHeightForWidth());
        label_59->setSizePolicy(sizePolicy2);
        label_59->setFont(font5);

        horizontalLayout_4->addWidget(label_59);

        LineEdit_Roll = new QLineEdit(layoutWidget);
        LineEdit_Roll->setObjectName(QString::fromUtf8("LineEdit_Roll"));
        LineEdit_Roll->setEnabled(false);
        sizePolicy2.setHeightForWidth(LineEdit_Roll->sizePolicy().hasHeightForWidth());
        LineEdit_Roll->setSizePolicy(sizePolicy2);
        LineEdit_Roll->setMaximumSize(QSize(16777215, 16777215));
        LineEdit_Roll->setFont(font1);
        LineEdit_Roll->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0)"));

        horizontalLayout_4->addWidget(LineEdit_Roll);

        label_69 = new QLabel(layoutWidget);
        label_69->setObjectName(QString::fromUtf8("label_69"));
        sizePolicy2.setHeightForWidth(label_69->sizePolicy().hasHeightForWidth());
        label_69->setSizePolicy(sizePolicy2);
        label_69->setFont(font1);

        horizontalLayout_4->addWidget(label_69);


        verticalLayout->addLayout(horizontalLayout_4);

        frameVSMS1000InstallInfo = new QFrame(layoutWidget);
        frameVSMS1000InstallInfo->setObjectName(QString::fromUtf8("frameVSMS1000InstallInfo"));
        frameVSMS1000InstallInfo->setFrameShape(QFrame::NoFrame);
        frameVSMS1000InstallInfo->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frameVSMS1000InstallInfo);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_73 = new QLabel(frameVSMS1000InstallInfo);
        label_73->setObjectName(QString::fromUtf8("label_73"));
        sizePolicy2.setHeightForWidth(label_73->sizePolicy().hasHeightForWidth());
        label_73->setSizePolicy(sizePolicy2);
        label_73->setFont(font5);
        label_73->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_73);

        LineEditINSVehicleLongitudinal = new QLineEdit(frameVSMS1000InstallInfo);
        LineEditINSVehicleLongitudinal->setObjectName(QString::fromUtf8("LineEditINSVehicleLongitudinal"));
        LineEditINSVehicleLongitudinal->setEnabled(false);
        sizePolicy2.setHeightForWidth(LineEditINSVehicleLongitudinal->sizePolicy().hasHeightForWidth());
        LineEditINSVehicleLongitudinal->setSizePolicy(sizePolicy2);
        LineEditINSVehicleLongitudinal->setMaximumSize(QSize(16777215, 16777215));
        LineEditINSVehicleLongitudinal->setFont(font1);
        LineEditINSVehicleLongitudinal->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0)"));

        horizontalLayout_6->addWidget(LineEditINSVehicleLongitudinal);

        label_60 = new QLabel(frameVSMS1000InstallInfo);
        label_60->setObjectName(QString::fromUtf8("label_60"));
        sizePolicy2.setHeightForWidth(label_60->sizePolicy().hasHeightForWidth());
        label_60->setSizePolicy(sizePolicy2);
        label_60->setFont(font5);

        horizontalLayout_6->addWidget(label_60);


        gridLayout->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_76 = new QLabel(frameVSMS1000InstallInfo);
        label_76->setObjectName(QString::fromUtf8("label_76"));
        sizePolicy2.setHeightForWidth(label_76->sizePolicy().hasHeightForWidth());
        label_76->setSizePolicy(sizePolicy2);
        label_76->setFont(font5);
        label_76->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_76);

        LineEditINSVehicleLateral = new QLineEdit(frameVSMS1000InstallInfo);
        LineEditINSVehicleLateral->setObjectName(QString::fromUtf8("LineEditINSVehicleLateral"));
        LineEditINSVehicleLateral->setEnabled(false);
        sizePolicy2.setHeightForWidth(LineEditINSVehicleLateral->sizePolicy().hasHeightForWidth());
        LineEditINSVehicleLateral->setSizePolicy(sizePolicy2);
        LineEditINSVehicleLateral->setMaximumSize(QSize(16777215, 16777215));
        LineEditINSVehicleLateral->setFont(font1);
        LineEditINSVehicleLateral->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0)"));

        horizontalLayout_8->addWidget(LineEditINSVehicleLateral);

        label_77 = new QLabel(frameVSMS1000InstallInfo);
        label_77->setObjectName(QString::fromUtf8("label_77"));
        sizePolicy2.setHeightForWidth(label_77->sizePolicy().hasHeightForWidth());
        label_77->setSizePolicy(sizePolicy2);
        label_77->setFont(font5);

        horizontalLayout_8->addWidget(label_77);


        gridLayout->addLayout(horizontalLayout_8, 0, 1, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_74 = new QLabel(frameVSMS1000InstallInfo);
        label_74->setObjectName(QString::fromUtf8("label_74"));
        sizePolicy2.setHeightForWidth(label_74->sizePolicy().hasHeightForWidth());
        label_74->setSizePolicy(sizePolicy2);
        label_74->setFont(font5);
        label_74->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_74);

        LineEditINSVehicleVertical = new QLineEdit(frameVSMS1000InstallInfo);
        LineEditINSVehicleVertical->setObjectName(QString::fromUtf8("LineEditINSVehicleVertical"));
        LineEditINSVehicleVertical->setEnabled(false);
        sizePolicy2.setHeightForWidth(LineEditINSVehicleVertical->sizePolicy().hasHeightForWidth());
        LineEditINSVehicleVertical->setSizePolicy(sizePolicy2);
        LineEditINSVehicleVertical->setMaximumSize(QSize(16777215, 16777215));
        LineEditINSVehicleVertical->setFont(font1);
        LineEditINSVehicleVertical->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0)"));

        horizontalLayout_7->addWidget(LineEditINSVehicleVertical);

        label_75 = new QLabel(frameVSMS1000InstallInfo);
        label_75->setObjectName(QString::fromUtf8("label_75"));
        sizePolicy2.setHeightForWidth(label_75->sizePolicy().hasHeightForWidth());
        label_75->setSizePolicy(sizePolicy2);
        label_75->setFont(font5);

        horizontalLayout_7->addWidget(label_75);


        gridLayout->addLayout(horizontalLayout_7, 1, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_78 = new QLabel(frameVSMS1000InstallInfo);
        label_78->setObjectName(QString::fromUtf8("label_78"));
        sizePolicy2.setHeightForWidth(label_78->sizePolicy().hasHeightForWidth());
        label_78->setSizePolicy(sizePolicy2);
        label_78->setFont(font5);
        label_78->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_78);

        LineEditINSVehicleSlideslipangle = new QLineEdit(frameVSMS1000InstallInfo);
        LineEditINSVehicleSlideslipangle->setObjectName(QString::fromUtf8("LineEditINSVehicleSlideslipangle"));
        LineEditINSVehicleSlideslipangle->setEnabled(false);
        sizePolicy2.setHeightForWidth(LineEditINSVehicleSlideslipangle->sizePolicy().hasHeightForWidth());
        LineEditINSVehicleSlideslipangle->setSizePolicy(sizePolicy2);
        LineEditINSVehicleSlideslipangle->setMaximumSize(QSize(16777215, 16777215));
        LineEditINSVehicleSlideslipangle->setFont(font1);
        LineEditINSVehicleSlideslipangle->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0)"));

        horizontalLayout_9->addWidget(LineEditINSVehicleSlideslipangle);

        label_79 = new QLabel(frameVSMS1000InstallInfo);
        label_79->setObjectName(QString::fromUtf8("label_79"));
        sizePolicy2.setHeightForWidth(label_79->sizePolicy().hasHeightForWidth());
        label_79->setSizePolicy(sizePolicy2);
        label_79->setFont(font5);

        horizontalLayout_9->addWidget(label_79);


        gridLayout->addLayout(horizontalLayout_9, 1, 1, 1, 1);


        verticalLayout->addWidget(frameVSMS1000InstallInfo);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_62 = new QLabel(layoutWidget);
        label_62->setObjectName(QString::fromUtf8("label_62"));
        sizePolicy2.setHeightForWidth(label_62->sizePolicy().hasHeightForWidth());
        label_62->setSizePolicy(sizePolicy2);
        label_62->setFont(font5);
        label_62->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_62);

        LineEdit_Heading = new QLineEdit(layoutWidget);
        LineEdit_Heading->setObjectName(QString::fromUtf8("LineEdit_Heading"));
        LineEdit_Heading->setEnabled(false);
        sizePolicy2.setHeightForWidth(LineEdit_Heading->sizePolicy().hasHeightForWidth());
        LineEdit_Heading->setSizePolicy(sizePolicy2);
        LineEdit_Heading->setFont(font1);
        LineEdit_Heading->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0)"));

        horizontalLayout_5->addWidget(LineEdit_Heading);


        verticalLayout->addLayout(horizontalLayout_5);

        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(280, 630, 781, 201));
        sizePolicy2.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy2);
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Raised);
        label_41 = new QLabel(frame_3);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(10, 10, 761, 41));
        sizePolicy2.setHeightForWidth(label_41->sizePolicy().hasHeightForWidth());
        label_41->setSizePolicy(sizePolicy2);
        QFont font7;
        font7.setPointSize(16);
        font7.setBold(false);
        font7.setWeight(50);
        font7.setKerning(true);
        label_41->setFont(font7);
        label_41->setAlignment(Qt::AlignCenter);
        LineEdit_VehicleSpeed = new QLineEdit(frame_3);
        LineEdit_VehicleSpeed->setObjectName(QString::fromUtf8("LineEdit_VehicleSpeed"));
        LineEdit_VehicleSpeed->setEnabled(false);
        LineEdit_VehicleSpeed->setGeometry(QRect(130, 60, 520, 31));
        sizePolicy2.setHeightForWidth(LineEdit_VehicleSpeed->sizePolicy().hasHeightForWidth());
        LineEdit_VehicleSpeed->setSizePolicy(sizePolicy2);
        QFont font8;
        font8.setPointSize(10);
        font8.setBold(false);
        font8.setWeight(50);
        font8.setKerning(true);
        LineEdit_VehicleSpeed->setFont(font8);
        LineEdit_VehicleSpeed->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0)"));
        label_43 = new QLabel(frame_3);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setEnabled(true);
        label_43->setGeometry(QRect(660, 50, 51, 51));
        sizePolicy2.setHeightForWidth(label_43->sizePolicy().hasHeightForWidth());
        label_43->setSizePolicy(sizePolicy2);
        label_43->setFont(font8);
        label_10 = new QLabel(frame_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(40, 50, 51, 51));
        sizePolicy2.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy2);
        label_10->setFont(font8);
        label_10->setAlignment(Qt::AlignCenter);
        label_13 = new QLabel(frame_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(310, 110, 51, 31));
        sizePolicy2.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy2);
        label_13->setFont(font8);
        LineEdit_RLSpeed = new QLineEdit(frame_3);
        LineEdit_RLSpeed->setObjectName(QString::fromUtf8("LineEdit_RLSpeed"));
        LineEdit_RLSpeed->setEnabled(false);
        LineEdit_RLSpeed->setGeometry(QRect(70, 150, 231, 31));
        sizePolicy2.setHeightForWidth(LineEdit_RLSpeed->sizePolicy().hasHeightForWidth());
        LineEdit_RLSpeed->setSizePolicy(sizePolicy2);
        LineEdit_RLSpeed->setMaximumSize(QSize(16777215, 16777215));
        LineEdit_RLSpeed->setFont(font8);
        LineEdit_RLSpeed->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0)"));
        label_63 = new QLabel(frame_3);
        label_63->setObjectName(QString::fromUtf8("label_63"));
        label_63->setGeometry(QRect(30, 110, 31, 31));
        sizePolicy2.setHeightForWidth(label_63->sizePolicy().hasHeightForWidth());
        label_63->setSizePolicy(sizePolicy2);
        label_63->setFont(font8);
        label_63->setAlignment(Qt::AlignCenter);
        LineEdit_FLSpeed = new QLineEdit(frame_3);
        LineEdit_FLSpeed->setObjectName(QString::fromUtf8("LineEdit_FLSpeed"));
        LineEdit_FLSpeed->setEnabled(false);
        LineEdit_FLSpeed->setGeometry(QRect(70, 110, 231, 31));
        sizePolicy2.setHeightForWidth(LineEdit_FLSpeed->sizePolicy().hasHeightForWidth());
        LineEdit_FLSpeed->setSizePolicy(sizePolicy2);
        LineEdit_FLSpeed->setMaximumSize(QSize(16777215, 16777215));
        LineEdit_FLSpeed->setFont(font8);
        LineEdit_FLSpeed->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0)"));
        label_65 = new QLabel(frame_3);
        label_65->setObjectName(QString::fromUtf8("label_65"));
        label_65->setGeometry(QRect(30, 150, 31, 31));
        sizePolicy2.setHeightForWidth(label_65->sizePolicy().hasHeightForWidth());
        label_65->setSizePolicy(sizePolicy2);
        label_65->setFont(font8);
        label_65->setAlignment(Qt::AlignCenter);
        label_15 = new QLabel(frame_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(310, 150, 51, 31));
        sizePolicy2.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy2);
        label_15->setFont(font8);
        label_12 = new QLabel(frame_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(710, 150, 51, 31));
        sizePolicy2.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy2);
        label_12->setFont(font8);
        LineEdit_RRSpeed = new QLineEdit(frame_3);
        LineEdit_RRSpeed->setObjectName(QString::fromUtf8("LineEdit_RRSpeed"));
        LineEdit_RRSpeed->setEnabled(false);
        LineEdit_RRSpeed->setGeometry(QRect(470, 150, 231, 31));
        sizePolicy2.setHeightForWidth(LineEdit_RRSpeed->sizePolicy().hasHeightForWidth());
        LineEdit_RRSpeed->setSizePolicy(sizePolicy2);
        LineEdit_RRSpeed->setMaximumSize(QSize(16777215, 16777215));
        LineEdit_RRSpeed->setFont(font8);
        LineEdit_RRSpeed->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0)"));
        LineEdit_FRSpeed = new QLineEdit(frame_3);
        LineEdit_FRSpeed->setObjectName(QString::fromUtf8("LineEdit_FRSpeed"));
        LineEdit_FRSpeed->setEnabled(false);
        LineEdit_FRSpeed->setGeometry(QRect(470, 110, 231, 31));
        sizePolicy2.setHeightForWidth(LineEdit_FRSpeed->sizePolicy().hasHeightForWidth());
        LineEdit_FRSpeed->setSizePolicy(sizePolicy2);
        LineEdit_FRSpeed->setMaximumSize(QSize(16777215, 16777215));
        LineEdit_FRSpeed->setFont(font8);
        LineEdit_FRSpeed->setStyleSheet(QString::fromUtf8("color:rgb(0, 0, 0)"));
        label_67 = new QLabel(frame_3);
        label_67->setObjectName(QString::fromUtf8("label_67"));
        label_67->setGeometry(QRect(430, 110, 31, 31));
        sizePolicy2.setHeightForWidth(label_67->sizePolicy().hasHeightForWidth());
        label_67->setSizePolicy(sizePolicy2);
        label_67->setFont(font8);
        label_67->setAlignment(Qt::AlignCenter);
        label_14 = new QLabel(frame_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(710, 110, 51, 31));
        sizePolicy2.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy2);
        label_14->setFont(font8);
        label_66 = new QLabel(frame_3);
        label_66->setObjectName(QString::fromUtf8("label_66"));
        label_66->setGeometry(QRect(430, 150, 31, 31));
        sizePolicy2.setHeightForWidth(label_66->sizePolicy().hasHeightForWidth());
        label_66->setSizePolicy(sizePolicy2);
        label_66->setFont(font8);
        label_66->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setEnabled(true);
        toolBar->setFont(font1);
        toolBar->setMovable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        statusBar_position = new QStatusBar(MainWindow);
        statusBar_position->setObjectName(QString::fromUtf8("statusBar_position"));
        MainWindow->setStatusBar(statusBar_position);

        retranslateUi(MainWindow);

        PushButton_CheckSerial->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_TrackMap->setText(QCoreApplication::translate("MainWindow", "\345\261\200\351\203\250\350\275\250\350\277\271", nullptr));
        action_FirmWare->setText(QCoreApplication::translate("MainWindow", "\345\233\272\344\273\266\346\233\264\346\226\260", nullptr));
#if QT_CONFIG(tooltip)
        action_FirmWare->setToolTip(QCoreApplication::translate("MainWindow", "\345\233\272\344\273\266\346\233\264\346\226\260", nullptr));
#endif // QT_CONFIG(tooltip)
        action_VersionMsg->setText(QCoreApplication::translate("MainWindow", "\347\211\210\346\234\254\344\277\241\346\201\257", nullptr));
        action_TempCali->setText(QCoreApplication::translate("MainWindow", "\346\270\251\345\272\246\346\240\207\345\256\232", nullptr));
#if QT_CONFIG(tooltip)
        action_TempCali->setToolTip(QCoreApplication::translate("MainWindow", "\346\270\251\345\272\246\346\240\207\345\256\232", nullptr));
#endif // QT_CONFIG(tooltip)
        action_PollingData->setText(QCoreApplication::translate("MainWindow", "\350\275\256\350\257\242\346\225\260\346\215\256", nullptr));
#if QT_CONFIG(tooltip)
        action_PollingData->setToolTip(QCoreApplication::translate("MainWindow", "\350\275\256\350\257\242\346\225\260\346\215\256", nullptr));
#endif // QT_CONFIG(tooltip)
        action_Encryption->setText(QCoreApplication::translate("MainWindow", "\346\277\200\346\264\273\347\240\201", nullptr));
#if QT_CONFIG(tooltip)
        action_Encryption->setToolTip(QCoreApplication::translate("MainWindow", "\346\277\200\346\264\273\347\240\201", nullptr));
#endif // QT_CONFIG(tooltip)
        action_ProtocolChange->setText(QCoreApplication::translate("MainWindow", "\345\217\202\346\225\260\351\205\215\347\275\256", nullptr));
#if QT_CONFIG(tooltip)
        action_ProtocolChange->setToolTip(QCoreApplication::translate("MainWindow", "\345\217\202\346\225\260\351\205\215\347\275\256", nullptr));
#endif // QT_CONFIG(tooltip)
        action_CustomCan->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\256\232\344\271\211CAN", nullptr));
#if QT_CONFIG(tooltip)
        action_CustomCan->setToolTip(QCoreApplication::translate("MainWindow", "\350\207\252\345\256\232\344\271\211CAN", nullptr));
#endif // QT_CONFIG(tooltip)
        action_advanced->setText(QCoreApplication::translate("MainWindow", "\351\253\230\347\272\247\345\212\237\350\203\275", nullptr));
#if QT_CONFIG(tooltip)
        action_advanced->setToolTip(QCoreApplication::translate("MainWindow", "\351\253\230\347\272\247\345\212\237\350\203\275", nullptr));
#endif // QT_CONFIG(tooltip)
        label_61->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\346\250\241\345\235\227", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243", nullptr));
        ComboBox_Baud->setItemText(0, QCoreApplication::translate("MainWindow", "1200", nullptr));
        ComboBox_Baud->setItemText(1, QCoreApplication::translate("MainWindow", "2400", nullptr));
        ComboBox_Baud->setItemText(2, QCoreApplication::translate("MainWindow", "4800", nullptr));
        ComboBox_Baud->setItemText(3, QCoreApplication::translate("MainWindow", "9600", nullptr));
        ComboBox_Baud->setItemText(4, QCoreApplication::translate("MainWindow", "14400", nullptr));
        ComboBox_Baud->setItemText(5, QCoreApplication::translate("MainWindow", "19200", nullptr));
        ComboBox_Baud->setItemText(6, QCoreApplication::translate("MainWindow", "28800", nullptr));
        ComboBox_Baud->setItemText(7, QCoreApplication::translate("MainWindow", "38400", nullptr));
        ComboBox_Baud->setItemText(8, QCoreApplication::translate("MainWindow", "57600", nullptr));
        ComboBox_Baud->setItemText(9, QCoreApplication::translate("MainWindow", "115200", nullptr));
        ComboBox_Baud->setItemText(10, QCoreApplication::translate("MainWindow", "230400", nullptr));
        ComboBox_Baud->setItemText(11, QCoreApplication::translate("MainWindow", "460800", nullptr));
        ComboBox_Baud->setItemText(12, QCoreApplication::translate("MainWindow", "921600", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
        ComboBox_BitNum->setItemText(0, QCoreApplication::translate("MainWindow", "8", nullptr));
        ComboBox_BitNum->setItemText(1, QCoreApplication::translate("MainWindow", "5", nullptr));
        ComboBox_BitNum->setItemText(2, QCoreApplication::translate("MainWindow", "6", nullptr));
        ComboBox_BitNum->setItemText(3, QCoreApplication::translate("MainWindow", "7", nullptr));

        ComboBox_Parity->setItemText(0, QCoreApplication::translate("MainWindow", "0", nullptr));
        ComboBox_Parity->setItemText(1, QCoreApplication::translate("MainWindow", "-1", nullptr));
        ComboBox_Parity->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        ComboBox_Parity->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        ComboBox_Parity->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        ComboBox_Parity->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));

        ComboBox_Stop->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        ComboBox_Stop->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215\346\225\260", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", nullptr));
        PushButton_CheckSerial->setText(QCoreApplication::translate("MainWindow", "\346\243\200\346\265\213\344\270\262\345\217\243", nullptr));
        PushButton_OpenSerial->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        label_72->setText(QCoreApplication::translate("MainWindow", "\347\202\271\345\207\273\350\277\233\345\205\245\351\205\215\347\275\256\347\225\214\351\235\242", nullptr));
        PushButton_CaliDialog->setText(QCoreApplication::translate("MainWindow", "\346\240\207\345\256\232\346\250\241\345\235\227", nullptr));
        label_53->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\277\235\345\255\230", nullptr));
        Label_SaveSerialData_StateMsg->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\347\202\271\345\207\273\351\200\211\346\213\251\350\267\257\345\276\204\346\214\211\351\222\256<br/>\345\217\257\351\200\211\346\213\251\346\225\260\346\215\256\345\255\230\350\267\257\345\276\204\357\274\201</p></body></html>", nullptr));
        PushButton_SaveSerialData_StartSave->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\344\277\235\345\255\230", nullptr));
        PushButton_SaveSerialData_SeletePath->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\350\267\257\345\276\204", nullptr));
        CheckBox_SaveSerialData_WithTime->setText(QCoreApplication::translate("MainWindow", "\345\242\236\345\212\240\346\227\266\351\227\264\346\210\263", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "\346\203\257\345\257\274\344\277\241\346\201\257", nullptr));
        label_85->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>g</p></body></html>", nullptr));
        label_86->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>g</p></body></html>", nullptr));
        label_44->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>g</p></body></html>", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "acc_z", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "acc_x", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "acc_y", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "w_z", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "w_y", nullptr));
        label_40->setText(QCoreApplication::translate("MainWindow", "\302\260/s", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "w_x", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "\302\260/s", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\302\260/s", nullptr));
        label_51->setText(QCoreApplication::translate("MainWindow", "\350\236\215\345\220\210\344\277\241\346\201\257", nullptr));
        label_70->setText(QCoreApplication::translate("MainWindow", "\302\260", nullptr));
        label_50->setText(QCoreApplication::translate("MainWindow", "\347\272\254\345\272\246", nullptr));
        label_64->setText(QCoreApplication::translate("MainWindow", "\302\260", nullptr));
        label_55->setText(QCoreApplication::translate("MainWindow", "VE", nullptr));
        label_88->setText(QCoreApplication::translate("MainWindow", "m/s", nullptr));
        label_52->setText(QCoreApplication::translate("MainWindow", "\347\273\217\345\272\246", nullptr));
        label_49->setText(QCoreApplication::translate("MainWindow", "\302\260", nullptr));
        label_56->setText(QCoreApplication::translate("MainWindow", "VN", nullptr));
        label_48->setText(QCoreApplication::translate("MainWindow", "m/s", nullptr));
        label_54->setText(QCoreApplication::translate("MainWindow", "\351\253\230\345\272\246", nullptr));
        label_71->setText(QCoreApplication::translate("MainWindow", "m", nullptr));
        label_57->setText(QCoreApplication::translate("MainWindow", "VU", nullptr));
        label_87->setText(QCoreApplication::translate("MainWindow", "m/s", nullptr));
        label_58->setText(QCoreApplication::translate("MainWindow", "Pitch", nullptr));
        label_68->setText(QCoreApplication::translate("MainWindow", "\302\260", nullptr));
        label_59->setText(QCoreApplication::translate("MainWindow", "Roll", nullptr));
        label_69->setText(QCoreApplication::translate("MainWindow", "\302\260", nullptr));
        label_73->setText(QCoreApplication::translate("MainWindow", "\347\272\265\345\220\221\351\200\237\345\272\246", nullptr));
        label_60->setText(QCoreApplication::translate("MainWindow", "m/s", nullptr));
        label_76->setText(QCoreApplication::translate("MainWindow", "\344\276\247\345\220\221\351\200\237\345\272\246", nullptr));
        label_77->setText(QCoreApplication::translate("MainWindow", "m/s", nullptr));
        label_74->setText(QCoreApplication::translate("MainWindow", "\345\236\202\345\220\221\351\200\237\345\272\246", nullptr));
        label_75->setText(QCoreApplication::translate("MainWindow", "m/s", nullptr));
        label_78->setText(QCoreApplication::translate("MainWindow", "\344\276\247\345\201\217\350\247\222", nullptr));
        label_79->setText(QCoreApplication::translate("MainWindow", "deg", nullptr));
        label_62->setText(QCoreApplication::translate("MainWindow", "Heading", nullptr));
        label_41->setText(QCoreApplication::translate("MainWindow", "\350\275\246\350\276\206\344\277\241\346\201\257", nullptr));
        label_43->setText(QCoreApplication::translate("MainWindow", "km/h", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\351\200\237\345\272\246", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "km/h", nullptr));
        label_63->setText(QCoreApplication::translate("MainWindow", "FL", nullptr));
        label_65->setText(QCoreApplication::translate("MainWindow", "RL", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "km/h", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "km/h", nullptr));
        label_67->setText(QCoreApplication::translate("MainWindow", "FR", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "km/h", nullptr));
        label_66->setText(QCoreApplication::translate("MainWindow", "RR", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
