/********************************************************************************
** Form generated from reading UI file 'HBWalkingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HBWALKINGDIALOG_H
#define UI_HBWALKINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_HBWalkingDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *BT_DATA_SAVE;
    QPushButton *BT_WALK_TEST;
    QLineEdit *LE_STEP_TIME;
    QLineEdit *LE_STEP_STRIDE;
    QPushButton *BT_TORQUE_TEST;
    QPushButton *BT_TEST_START;
    QLineEdit *LE_REF_TORQUE;
    QPushButton *BT_WALK_READY;
    QLineEdit *LE_NO_OF_STEP;
    QLabel *label_4;
    QPushButton *BT_TEST_STOP;
    QPushButton *BTN_APPLY;
    QLabel *label_3;
    QFrame *frame;
    QPushButton *BT_SYSID_INPUT_START;
    QLineEdit *LE_SYSID_INPUT_FREQ;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *LE_SYSID_INPUT_AMP;
    QLabel *label_9;
    QPushButton *BT_SYSID_STOP_SAVE;
    QPushButton *BT_SYSID_INPUT_START_2;
    QPushButton *BT_WALK_TEST_2;
    QLineEdit *LE_IMPACT_TIME;
    QLineEdit *LE_IMPACT_FORCE;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QPushButton *BT_CONTROL_ON;
    QFrame *frame_3;
    QPushButton *BT_OLTORQUE_GO;
    QLineEdit *LE_OLTORQUE_MA;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QPushButton *BT_ZERO_GAIN;
    QPushButton *BT_ONE_LEG_READY;
    QPushButton *BT_INV_DYNAMICS_CON;
    QPushButton *BT_DYN_STANDING;
    QPushButton *BT_POS;
    QPushButton *BT_DYN_WALKING;
    QPushButton *BT_JUMP;
    QPushButton *BT_JUMP_READY;
    QPushButton *BT_COM_HEIGHT;
    QPushButton *BT_LOGGING;
    QPushButton *BT_ONE_LEG_READY_2;
    QPushButton *BT_READY_TO_WALK;

    void setupUi(QDialog *HBWalkingDialog)
    {
        if (HBWalkingDialog->objectName().isEmpty())
            HBWalkingDialog->setObjectName(QStringLiteral("HBWalkingDialog"));
        HBWalkingDialog->resize(979, 598);
        label = new QLabel(HBWalkingDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(660, 510, 81, 17));
        label_2 = new QLabel(HBWalkingDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 90, 81, 17));
        BT_DATA_SAVE = new QPushButton(HBWalkingDialog);
        BT_DATA_SAVE->setObjectName(QStringLiteral("BT_DATA_SAVE"));
        BT_DATA_SAVE->setGeometry(QRect(20, 80, 99, 27));
        BT_WALK_TEST = new QPushButton(HBWalkingDialog);
        BT_WALK_TEST->setObjectName(QStringLiteral("BT_WALK_TEST"));
        BT_WALK_TEST->setGeometry(QRect(140, 150, 171, 51));
        LE_STEP_TIME = new QLineEdit(HBWalkingDialog);
        LE_STEP_TIME->setObjectName(QStringLiteral("LE_STEP_TIME"));
        LE_STEP_TIME->setGeometry(QRect(260, 110, 91, 27));
        LE_STEP_STRIDE = new QLineEdit(HBWalkingDialog);
        LE_STEP_STRIDE->setObjectName(QStringLiteral("LE_STEP_STRIDE"));
        LE_STEP_STRIDE->setGeometry(QRect(360, 110, 91, 27));
        BT_TORQUE_TEST = new QPushButton(HBWalkingDialog);
        BT_TORQUE_TEST->setObjectName(QStringLiteral("BT_TORQUE_TEST"));
        BT_TORQUE_TEST->setGeometry(QRect(20, 120, 99, 27));
        BT_TEST_START = new QPushButton(HBWalkingDialog);
        BT_TEST_START->setObjectName(QStringLiteral("BT_TEST_START"));
        BT_TEST_START->setGeometry(QRect(20, 40, 99, 27));
        LE_REF_TORQUE = new QLineEdit(HBWalkingDialog);
        LE_REF_TORQUE->setObjectName(QStringLiteral("LE_REF_TORQUE"));
        LE_REF_TORQUE->setGeometry(QRect(650, 530, 113, 27));
        BT_WALK_READY = new QPushButton(HBWalkingDialog);
        BT_WALK_READY->setObjectName(QStringLiteral("BT_WALK_READY"));
        BT_WALK_READY->setGeometry(QRect(160, 40, 141, 41));
        LE_NO_OF_STEP = new QLineEdit(HBWalkingDialog);
        LE_NO_OF_STEP->setObjectName(QStringLiteral("LE_NO_OF_STEP"));
        LE_NO_OF_STEP->setGeometry(QRect(160, 110, 91, 27));
        label_4 = new QLabel(HBWalkingDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(360, 90, 101, 17));
        BT_TEST_STOP = new QPushButton(HBWalkingDialog);
        BT_TEST_STOP->setObjectName(QStringLiteral("BT_TEST_STOP"));
        BT_TEST_STOP->setGeometry(QRect(20, 160, 99, 27));
        BTN_APPLY = new QPushButton(HBWalkingDialog);
        BTN_APPLY->setObjectName(QStringLiteral("BTN_APPLY"));
        BTN_APPLY->setGeometry(QRect(780, 530, 99, 27));
        label_3 = new QLabel(HBWalkingDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(260, 90, 91, 17));
        frame = new QFrame(HBWalkingDialog);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(280, 500, 16, 16));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        BT_SYSID_INPUT_START = new QPushButton(frame);
        BT_SYSID_INPUT_START->setObjectName(QStringLiteral("BT_SYSID_INPUT_START"));
        BT_SYSID_INPUT_START->setGeometry(QRect(150, 40, 111, 31));
        LE_SYSID_INPUT_FREQ = new QLineEdit(frame);
        LE_SYSID_INPUT_FREQ->setObjectName(QStringLiteral("LE_SYSID_INPUT_FREQ"));
        LE_SYSID_INPUT_FREQ->setGeometry(QRect(40, 40, 71, 27));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 10, 121, 21));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 40, 31, 17));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(110, 40, 41, 20));
        label_8 = new QLabel(frame);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(110, 80, 41, 20));
        LE_SYSID_INPUT_AMP = new QLineEdit(frame);
        LE_SYSID_INPUT_AMP->setObjectName(QStringLiteral("LE_SYSID_INPUT_AMP"));
        LE_SYSID_INPUT_AMP->setGeometry(QRect(40, 80, 71, 27));
        label_9 = new QLabel(frame);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 80, 31, 17));
        BT_SYSID_STOP_SAVE = new QPushButton(frame);
        BT_SYSID_STOP_SAVE->setObjectName(QStringLiteral("BT_SYSID_STOP_SAVE"));
        BT_SYSID_STOP_SAVE->setGeometry(QRect(150, 76, 111, 31));
        BT_SYSID_INPUT_START_2 = new QPushButton(frame);
        BT_SYSID_INPUT_START_2->setObjectName(QStringLiteral("BT_SYSID_INPUT_START_2"));
        BT_SYSID_INPUT_START_2->setGeometry(QRect(280, 40, 111, 31));
        BT_WALK_TEST_2 = new QPushButton(HBWalkingDialog);
        BT_WALK_TEST_2->setObjectName(QStringLiteral("BT_WALK_TEST_2"));
        BT_WALK_TEST_2->setGeometry(QRect(20, 510, 171, 51));
        QFont font;
        font.setPointSize(15);
        BT_WALK_TEST_2->setFont(font);
        LE_IMPACT_TIME = new QLineEdit(HBWalkingDialog);
        LE_IMPACT_TIME->setObjectName(QStringLiteral("LE_IMPACT_TIME"));
        LE_IMPACT_TIME->setGeometry(QRect(20, 470, 71, 27));
        LE_IMPACT_FORCE = new QLineEdit(HBWalkingDialog);
        LE_IMPACT_FORCE->setObjectName(QStringLiteral("LE_IMPACT_FORCE"));
        LE_IMPACT_FORCE->setGeometry(QRect(125, 469, 71, 27));
        label_10 = new QLabel(HBWalkingDialog);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(95, 474, 41, 20));
        label_11 = new QLabel(HBWalkingDialog);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(200, 474, 41, 20));
        label_12 = new QLabel(HBWalkingDialog);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 450, 51, 17));
        label_13 = new QLabel(HBWalkingDialog);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(130, 450, 51, 17));
        BT_CONTROL_ON = new QPushButton(HBWalkingDialog);
        BT_CONTROL_ON->setObjectName(QStringLiteral("BT_CONTROL_ON"));
        BT_CONTROL_ON->setGeometry(QRect(140, 220, 171, 51));
        frame_3 = new QFrame(HBWalkingDialog);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(300, 500, 16, 16));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        BT_OLTORQUE_GO = new QPushButton(frame_3);
        BT_OLTORQUE_GO->setObjectName(QStringLiteral("BT_OLTORQUE_GO"));
        BT_OLTORQUE_GO->setGeometry(QRect(150, 60, 111, 31));
        LE_OLTORQUE_MA = new QLineEdit(frame_3);
        LE_OLTORQUE_MA->setObjectName(QStringLiteral("LE_OLTORQUE_MA"));
        LE_OLTORQUE_MA->setGeometry(QRect(10, 60, 71, 27));
        label_19 = new QLabel(frame_3);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(10, 10, 121, 21));
        label_20 = new QLabel(frame_3);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(10, 40, 31, 17));
        label_21 = new QLabel(frame_3);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(80, 60, 30, 20));
        BT_ZERO_GAIN = new QPushButton(frame_3);
        BT_ZERO_GAIN->setObjectName(QStringLiteral("BT_ZERO_GAIN"));
        BT_ZERO_GAIN->setGeometry(QRect(150, 20, 111, 31));
        BT_ONE_LEG_READY = new QPushButton(HBWalkingDialog);
        BT_ONE_LEG_READY->setObjectName(QStringLiteral("BT_ONE_LEG_READY"));
        BT_ONE_LEG_READY->setGeometry(QRect(310, 10, 151, 31));
        BT_INV_DYNAMICS_CON = new QPushButton(HBWalkingDialog);
        BT_INV_DYNAMICS_CON->setObjectName(QStringLiteral("BT_INV_DYNAMICS_CON"));
        BT_INV_DYNAMICS_CON->setGeometry(QRect(320, 220, 171, 51));
        BT_DYN_STANDING = new QPushButton(HBWalkingDialog);
        BT_DYN_STANDING->setObjectName(QStringLiteral("BT_DYN_STANDING"));
        BT_DYN_STANDING->setGeometry(QRect(320, 310, 171, 51));
        BT_POS = new QPushButton(HBWalkingDialog);
        BT_POS->setObjectName(QStringLiteral("BT_POS"));
        BT_POS->setGeometry(QRect(140, 310, 171, 51));
        BT_DYN_WALKING = new QPushButton(HBWalkingDialog);
        BT_DYN_WALKING->setObjectName(QStringLiteral("BT_DYN_WALKING"));
        BT_DYN_WALKING->setGeometry(QRect(500, 220, 171, 51));
        BT_JUMP = new QPushButton(HBWalkingDialog);
        BT_JUMP->setObjectName(QStringLiteral("BT_JUMP"));
        BT_JUMP->setGeometry(QRect(320, 390, 171, 51));
        BT_JUMP_READY = new QPushButton(HBWalkingDialog);
        BT_JUMP_READY->setObjectName(QStringLiteral("BT_JUMP_READY"));
        BT_JUMP_READY->setGeometry(QRect(150, 390, 141, 41));
        BT_COM_HEIGHT = new QPushButton(HBWalkingDialog);
        BT_COM_HEIGHT->setObjectName(QStringLiteral("BT_COM_HEIGHT"));
        BT_COM_HEIGHT->setGeometry(QRect(540, 40, 111, 27));
        BT_LOGGING = new QPushButton(HBWalkingDialog);
        BT_LOGGING->setObjectName(QStringLiteral("BT_LOGGING"));
        BT_LOGGING->setGeometry(QRect(540, 70, 111, 27));
        BT_ONE_LEG_READY_2 = new QPushButton(HBWalkingDialog);
        BT_ONE_LEG_READY_2->setObjectName(QStringLiteral("BT_ONE_LEG_READY_2"));
        BT_ONE_LEG_READY_2->setGeometry(QRect(310, 50, 151, 31));
        BT_READY_TO_WALK = new QPushButton(HBWalkingDialog);
        BT_READY_TO_WALK->setObjectName(QStringLiteral("BT_READY_TO_WALK"));
        BT_READY_TO_WALK->setGeometry(QRect(340, 150, 171, 51));

        retranslateUi(HBWalkingDialog);

        QMetaObject::connectSlotsByName(HBWalkingDialog);
    } // setupUi

    void retranslateUi(QDialog *HBWalkingDialog)
    {
        HBWalkingDialog->setWindowTitle(QApplication::translate("HBWalkingDialog", "Dialog", 0));
        label->setText(QApplication::translate("HBWalkingDialog", "Ref torque", 0));
        label_2->setText(QApplication::translate("HBWalkingDialog", "No Of Step", 0));
        BT_DATA_SAVE->setText(QApplication::translate("HBWalkingDialog", "data save", 0));
        BT_WALK_TEST->setText(QApplication::translate("HBWalkingDialog", "Position Walking", 0));
        LE_STEP_TIME->setText(QApplication::translate("HBWalkingDialog", "0.8", 0));
        LE_STEP_STRIDE->setText(QApplication::translate("HBWalkingDialog", "0", 0));
        BT_TORQUE_TEST->setText(QApplication::translate("HBWalkingDialog", "Torque Test", 0));
        BT_TEST_START->setText(QApplication::translate("HBWalkingDialog", "Test Start", 0));
        BT_WALK_READY->setText(QApplication::translate("HBWalkingDialog", "Walk Ready", 0));
        LE_NO_OF_STEP->setText(QApplication::translate("HBWalkingDialog", "5", 0));
        label_4->setText(QApplication::translate("HBWalkingDialog", "Step Stride(m)", 0));
        BT_TEST_STOP->setText(QApplication::translate("HBWalkingDialog", "Stop", 0));
        BTN_APPLY->setText(QApplication::translate("HBWalkingDialog", "Apply", 0));
        label_3->setText(QApplication::translate("HBWalkingDialog", "Step Time(s)", 0));
        BT_SYSID_INPUT_START->setText(QApplication::translate("HBWalkingDialog", "Input Start", 0));
        LE_SYSID_INPUT_FREQ->setText(QApplication::translate("HBWalkingDialog", "1", 0));
        label_5->setText(QApplication::translate("HBWalkingDialog", "COM System ID", 0));
        label_6->setText(QApplication::translate("HBWalkingDialog", "Freq", 0));
        label_7->setText(QApplication::translate("HBWalkingDialog", "Hz", 0));
        label_8->setText(QApplication::translate("HBWalkingDialog", "m", 0));
        LE_SYSID_INPUT_AMP->setText(QApplication::translate("HBWalkingDialog", "0.01", 0));
        label_9->setText(QApplication::translate("HBWalkingDialog", "Amp", 0));
        BT_SYSID_STOP_SAVE->setText(QApplication::translate("HBWalkingDialog", "Stop & save", 0));
        BT_SYSID_INPUT_START_2->setText(QApplication::translate("HBWalkingDialog", "Step Input", 0));
        BT_WALK_TEST_2->setText(QApplication::translate("HBWalkingDialog", "Impact !", 0));
        LE_IMPACT_TIME->setText(QApplication::translate("HBWalkingDialog", "20", 0));
        LE_IMPACT_FORCE->setText(QApplication::translate("HBWalkingDialog", "0.01", 0));
        label_10->setText(QApplication::translate("HBWalkingDialog", "ms", 0));
        label_11->setText(QApplication::translate("HBWalkingDialog", "N", 0));
        label_12->setText(QApplication::translate("HBWalkingDialog", "Time", 0));
        label_13->setText(QApplication::translate("HBWalkingDialog", "Force", 0));
        BT_CONTROL_ON->setText(QApplication::translate("HBWalkingDialog", "Control On", 0));
        BT_OLTORQUE_GO->setText(QApplication::translate("HBWalkingDialog", "mA imput Go", 0));
        LE_OLTORQUE_MA->setText(QApplication::translate("HBWalkingDialog", "1", 0));
        label_19->setText(QApplication::translate("HBWalkingDialog", "OL Torque Tuning", 0));
        label_20->setText(QApplication::translate("HBWalkingDialog", "input", 0));
        label_21->setText(QApplication::translate("HBWalkingDialog", "mA", 0));
        BT_ZERO_GAIN->setText(QApplication::translate("HBWalkingDialog", "ZERO gain", 0));
        BT_ONE_LEG_READY->setText(QApplication::translate("HBWalkingDialog", "Right Stance", 0));
        BT_INV_DYNAMICS_CON->setText(QApplication::translate("HBWalkingDialog", "Inv Dynamics Con", 0));
        BT_DYN_STANDING->setText(QApplication::translate("HBWalkingDialog", "Dyn Standing", 0));
        BT_POS->setText(QApplication::translate("HBWalkingDialog", "Pos Standing", 0));
        BT_DYN_WALKING->setText(QApplication::translate("HBWalkingDialog", "Dynamics Walking", 0));
        BT_JUMP->setText(QApplication::translate("HBWalkingDialog", "Jump", 0));
        BT_JUMP_READY->setText(QApplication::translate("HBWalkingDialog", "Jump Ready", 0));
        BT_COM_HEIGHT->setText(QApplication::translate("HBWalkingDialog", "Get COM Height", 0));
        BT_LOGGING->setText(QApplication::translate("HBWalkingDialog", "Logging", 0));
        BT_ONE_LEG_READY_2->setText(QApplication::translate("HBWalkingDialog", "Left Stance", 0));
        BT_READY_TO_WALK->setText(QApplication::translate("HBWalkingDialog", "Ready to Walk", 0));
    } // retranslateUi

};

namespace Ui {
    class HBWalkingDialog: public Ui_HBWalkingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HBWALKINGDIALOG_H
