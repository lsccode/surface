#ifndef ISPPPFRAME_STITCH_H
#define ISPPPFRAME_STITCH_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>

#include "script/ispcommonstep.h"

#define M_FRAME_STICH_NP_LUT_X_WEIGHT_NUMBER (0x7f + 1)
class IspPPframe_stitch : public QWidget,public IspCommonStep
{
    Q_OBJECT
public:
    explicit IspPPframe_stitch(QWidget *parent = 0);

    QComboBox *ptCb_frame_stitch_np_lut_l_weight_lut;
    QLineEdit *ptEdit_frame_stitch_np_lut_l_weight_lut;
    QString szQStr_frame_stitch_np_lut_l_weight_lut[M_FRAME_STICH_NP_LUT_X_WEIGHT_NUMBER];

    QComboBox *ptCb_frame_stitch_np_lut_m_weight_lut;
    QLineEdit *ptEdit_frame_stitch_np_lut_m_weight_lut;
    QString szQStr_frame_stitch_np_lut_m_weight_lut[M_FRAME_STICH_NP_LUT_X_WEIGHT_NUMBER];

    QComboBox *ptCb_frame_stitch_np_lut_s_weight_lut;
    QLineEdit *ptEdit_frame_stitch_np_lut_s_weight_lut;
    QString szQStr_frame_stitch_np_lut_s_weight_lut[M_FRAME_STICH_NP_LUT_X_WEIGHT_NUMBER];

    QComboBox *ptCb_frame_stitch_np_lut_vs_weight_lut;
    QLineEdit *ptEdit_frame_stitch_np_lut_vs_weight_lut;
    QString szQStr_frame_stitch_np_lut_vs_weight_lut[M_FRAME_STICH_NP_LUT_X_WEIGHT_NUMBER];

    QPushButton *ptPBtn;

public:
    void init_array();
    void init_frame_stitch_np_lut_l_weight_lut();
    void init_frame_stitch_np_lut_m_weight_lut();
    void init_frame_stitch_np_lut_s_weight_lut();
    void init_frame_stitch_np_lut_vs_weight_lut();
    virtual void step1();

signals:

public slots:
    void clickedSlot(bool checked = false);

    void activatedSlot_frame_stitch_np_lut_l_weight_lut(int index);
    void textChangedSlot_frame_stitch_np_lut_l_weight_lut(const QString &text);

    void activatedSlot_frame_stitch_np_lut_m_weight_lut(int index);
    void textChangedSlot_frame_stitch_np_lut_m_weight_lut(const QString &text);

    void activatedSlot_frame_stitch_np_lut_s_weight_lut(int index);
    void textChangedSlot_frame_stitch_np_lut_s_weight_lut(const QString &text);

    void activatedSlot_frame_stitch_np_lut_vs_weight_lut(int index);
    void textChangedSlot_frame_stitch_np_lut_vs_weight_lut(const QString &text);
};

#endif // ISPPPFRAME_STITCH_H
