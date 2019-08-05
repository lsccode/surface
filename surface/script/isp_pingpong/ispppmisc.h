#ifndef ISPPPBLACK_LEVEL_H
#define ISPPPBLACK_LEVEL_H

#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>

#define M_NONEQU_GAMMA_SRGB_LUT_COEFF_LUT_NUMBER (0x40 + 1 )
#define M_PF_CORRECTION_SHADING_SHADING_LUT_NUMBER (0x20 + 1 )
#define M_LUMVAR_STATS_PING_MEM_NUMBER (0x1ff + 1 )
class IspPPmisc : public QWidget
{
    Q_OBJECT
public:
    explicit IspPPmisc(QWidget *parent = 0);
public:
    QLabel *ptLabel_sqrtblack_level_in ;
    QLineEdit *ptEdit_sqrtblack_level_in ;

    QLabel *ptLabel_sqrtblack_level_out ;
    QLineEdit *ptEdit_sqrtblack_level_out ;

    QLabel *ptLabel_square_beblack_level_in ;
    QLineEdit *ptEdit_square_beblack_level_in ;

    QLabel *ptLabel_square_beblack_level_out ;
    QLineEdit *ptEdit_square_beblack_level_out ;

    QLabel *ptLabel_defect_pixel_defect_pixel_count_in ;
    QLineEdit *ptEdit_defect_pixel_defect_pixel_count_in ;

    QLabel *ptLabel_lumvar_reg_active_width ;
    QLineEdit *ptEdit_lumvar_reg_active_width ;

    QComboBox *ptCb_nonequ_gamma_srgb_lut_coeff_lut;
    QLineEdit *ptEdit_nonequ_gamma_srgb_lut_coeff_lut;
    QString szQStr_nonequ_gamma_srgb_lut_coeff_lut[M_NONEQU_GAMMA_SRGB_LUT_COEFF_LUT_NUMBER];

    QComboBox *ptCb_pf_correction_shading_shading_lut;
    QLineEdit *ptEdit_pf_correction_shading_shading_lut;
    QString szQStr_pf_correction_shading_shading_lut[M_PF_CORRECTION_SHADING_SHADING_LUT_NUMBER];

    QComboBox *ptCb_lumvar_stats_ping_mem;
    QLineEdit *ptEdit_lumvar_stats_ping_mem;
    QString szQStr_lumvar_stats_ping_mem[M_LUMVAR_STATS_PING_MEM_NUMBER];

    QPushButton *ptPBtn;
signals:

public slots:
    void clickedSlot(bool checked = false);

    void activatedSlot_nonequ_gamma_srgb_lut_coeff_lut(int index);
    void textChangedSlot_nonequ_gamma_srgb_lut_coeff_lut(const QString &text);

    void activatedSlot_pf_correction_shading_shading_lut(int index);
    void textChangedSlot_pf_correction_shading_shading_lut(const QString &text);

    void activatedSlot_lumvar_stats_ping_mem(int index);
    void textChangedSlot_lumvar_stats_ping_mem(const QString &text);
};

#endif // ISPPPBLACK_LEVEL_H
