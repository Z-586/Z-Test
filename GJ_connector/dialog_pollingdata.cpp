#include "dialog_pollingdata.h"
#include "ui_dialog_pollingdata.h"


Dialog_PollingData::Dialog_PollingData(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::Dialog_PollingData)
{
    ui->setupUi(this);
    Dialog_PollingDataInit();
}

Dialog_PollingData::~Dialog_PollingData()
{
        delete ui;
}


void Dialog_PollingData::Dialog_PollingDataInit()   // 初始化函数
{
    this->setWindowTitle("轮询数据");

    QWidget::setAttribute(Qt::WA_QuitOnClose,false);     // 所有子窗口要写false
    QWidget::setAttribute(Qt::WA_DeleteOnClose);     // 所有子窗口要写false
    setWindowFlags((windowFlags()&~Qt::WindowContextHelpButtonHint) | Qt::WindowMinimizeButtonHint);

}

void Dialog_PollingData::Display_PollingData()      // 显示轮询数据
{
    ui->Label_VehicleSpdFactorErr       ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.VehicleSpdFactorErr       * POLL_RATIO_22  , 'f', 7));
    ui->Label_RearWheelBase             ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.RearWheelBase             * POLL_RATIO_23  , 'f', 7));
    ui->Label_FrontWheelBase            ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.FrontWheelBase            * POLL_RATIO_24  , 'f', 7));
    ui->Label_WheelBase                 ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.WheelBase                 * POLL_RATIO_25  , 'f', 7));
    ui->Label_INS_Db_g1                 ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.INS_Db_g[0]               * POLL_RATIO_114  , 'f', 7));
    ui->Label_INS_Db_g2                 ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.INS_Db_g[1]               * POLL_RATIO_115  , 'f', 7));
    ui->Label_INS_Db_g3                 ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.INS_Db_g[2]               * POLL_RATIO_116  , 'f', 7));
    ui->Label_INS_Eb_radps1             ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.INS_Eb_radps[0]           * POLL_RATIO_117  , 'f', 7));
    ui->Label_INS_Eb_radps2             ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.INS_Eb_radps[1]           * POLL_RATIO_120  , 'f', 7));
    ui->Label_INS_Eb_radps3             ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.INS_Eb_radps[2]           * POLL_RATIO_121  , 'f', 7));

    ui->Label_X_ACC_std_threshold_stop  ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.X_ACC_std_threshold_stop  * POLL_RATIO_132  , 'f', 7));
    ui->Label_Y_ACC_std_threshold_stop  ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.Y_ACC_std_threshold_stop  * POLL_RATIO_133  , 'f', 7));
    ui->Label_Z_ACC_std_threshold_stop  ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.Z_ACC_std_threshold_stop  * POLL_RATIO_136  , 'f', 7));
    ui->Label_X_GYRO_std_threshold_stop ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.X_GYRO_std_threshold_stop * POLL_RATIO_137  , 'f', 7));
    ui->Label_Y_GYRO_std_threshold_stop ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.Y_GYRO_std_threshold_stop * POLL_RATIO_140  , 'f', 7));
    ui->Label_Z_GYRO_std_threshold_stop ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.Z_GYRO_std_threshold_stop * POLL_RATIO_141  , 'f', 7));
    ui->Label_X_ACC_std_threshold_move  ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.X_ACC_std_threshold_move  * POLL_RATIO_144  , 'f', 7));
    ui->Label_Y_ACC_std_threshold_move  ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.Y_ACC_std_threshold_move  * POLL_RATIO_145  , 'f', 7));
    ui->Label_Z_ACC_std_threshold_move  ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.Z_ACC_std_threshold_move  * POLL_RATIO_148  , 'f', 7));
    ui->Label_X_GYRO_std_threshold_move ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.X_GYRO_std_threshold_move * POLL_RATIO_149 , 'f', 7));
    ui->Label_Y_GYRO_std_threshold_move ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.Y_GYRO_std_threshold_move * POLL_RATIO_152 , 'f', 7));
    ui->Label_Z_GYRO_std_threshold_move ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.Z_GYRO_std_threshold_move * POLL_RATIO_153 , 'f', 7));
    ui->Label_X_ACC_dt_threshold_move   ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.X_ACC_dt_threshold_move   * POLL_RATIO_156 , 'f', 7));
    ui->Label_Y_ACC_dt_threshold_move   ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.Y_ACC_dt_threshold_move   * POLL_RATIO_157 , 'f', 7));
    ui->Label_Z_ACC_dt_threshold_move   ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.Z_ACC_dt_threshold_move   * POLL_RATIO_160 , 'f', 7));
    ui->Label_X_GYRO_dt_threshold_move  ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.X_GYRO_dt_threshold_move  * POLL_RATIO_161 , 'f', 7));
    ui->Label_Y_GYRO_dt_threshold_move  ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.Y_GYRO_dt_threshold_move  * POLL_RATIO_164 , 'f', 7));
    ui->Label_Z_GYRO_dt_threshold_move  ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.Z_GYRO_dt_threshold_move  * POLL_RATIO_165 , 'f', 7));

    ui->Label_temp_count                ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.temp_count                * POLL_RATIO_168 , 'f', 7));
    ui->Label_IMU_TEMP                  ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.IMU_TEMP                  * POLL_RATIO_169 , 'f', 7));
    ui->Label_IMU_Tempera_Calib1        ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.IMU_Tempera_Calib1        * POLL_RATIO_170 , 'f', 7));
    ui->Label_IMU_Tempera_Calib2        ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.IMU_Tempera_Calib2        * POLL_RATIO_171 , 'f', 7));
    ui->Label_bax_1                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.ACCBias_g_Calib1[0]       * POLL_RATIO_175 , 'f', 7));
    ui->Label_bay_1                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.ACCBias_g_Calib1[1]       * POLL_RATIO_176 , 'f', 7));
    ui->Label_baz_1                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.ACCBias_g_Calib1[2]       * POLL_RATIO_177 , 'f', 7));
    ui->Label_bgx_1                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.GyroBias_degps_Calib1[0]  * POLL_RATIO_178 , 'f', 7));
    ui->Label_bgy_1                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.GyroBias_degps_Calib1[1]  * POLL_RATIO_181 , 'f', 7));
    ui->Label_bgz_1                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.GyroBias_degps_Calib1[2]  * POLL_RATIO_182 , 'f', 7));

    ui->Label_bax_2                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.ACCBias_g_Calib2[0]       * POLL_RATIO_183 , 'f', 7));
    ui->Label_bay_2                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.ACCBias_g_Calib2[1]       * POLL_RATIO_184 , 'f', 7));
    ui->Label_baz_2                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.ACCBias_g_Calib2[2]       * POLL_RATIO_187 , 'f', 7));
    ui->Label_bgx_2                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.GyroBias_degps_Calib2[0]  * POLL_RATIO_188 , 'f', 7));
    ui->Label_bgy_2                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.GyroBias_degps_Calib2[1]  * POLL_RATIO_189 , 'f', 7));
    ui->Label_bgz_2                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.GyroBias_degps_Calib2[2]  * POLL_RATIO_190 , 'f', 7));

    ui->Label_ka1_1                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKa_Calib1[0]         * POLL_RATIO_193 , 'f', 7));
    ui->Label_ka2_1                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKa_Calib1[1]         * POLL_RATIO_194 , 'f', 7));
    ui->Label_ka3_1                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKa_Calib1[2]         * POLL_RATIO_197 , 'f', 7));
    ui->Label_ka4_1                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKa_Calib1[3]         * POLL_RATIO_198 , 'f', 7));
    ui->Label_ka5_1                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKa_Calib1[4]         * POLL_RATIO_201 , 'f', 7));
    ui->Label_ka6_1                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKa_Calib1[5]         * POLL_RATIO_202 , 'f', 7));
    ui->Label_ka7_1                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKa_Calib1[6]         * POLL_RATIO_205 , 'f', 7));
    ui->Label_ka8_1                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKa_Calib1[7]         * POLL_RATIO_206 , 'f', 7));
    ui->Label_ka9_1                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKa_Calib1[8]         * POLL_RATIO_209 , 'f', 7));
    ui->Label_kg1_1                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKg_Calib1[0]         * POLL_RATIO_213 , 'f', 7));
    ui->Label_kg2_1                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKg_Calib1[1]         * POLL_RATIO_214 , 'f', 7));
    ui->Label_kg3_1                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKg_Calib1[2]         * POLL_RATIO_217 , 'f', 7));
    ui->Label_kg4_1                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKg_Calib1[3]         * POLL_RATIO_218 , 'f', 7));
    ui->Label_kg5_1                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKg_Calib1[4]         * POLL_RATIO_221 , 'f', 7));
    ui->Label_kg6_1                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKg_Calib1[5]         * POLL_RATIO_222 , 'f', 7));
    ui->Label_kg7_1                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKg_Calib1[6]         * POLL_RATIO_225 , 'f', 7));
    ui->Label_kg8_1                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKg_Calib1[7]         * POLL_RATIO_226 , 'f', 7));
    ui->Label_kg9_1                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKg_Calib1[8]         * POLL_RATIO_229 , 'f', 7));
    ui->Label_G1_1                      ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.G_Calib1[0]               * POLL_RATIO_233 , 'f', 7));
    ui->Label_G2_1                      ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.G_Calib1[1]               * POLL_RATIO_234 , 'f', 7));
    ui->Label_G3_1                      ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.G_Calib1[2]               * POLL_RATIO_237 , 'f', 7));
    ui->Label_G4_1                      ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.G_Calib1[3]               * POLL_RATIO_238 , 'f', 7));
    ui->Label_G5_1                      ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.G_Calib1[4]               * POLL_RATIO_241 , 'f', 7));
    ui->Label_G6_1                      ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.G_Calib1[5]               * POLL_RATIO_242 , 'f', 7));
    ui->Label_G7_1                      ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.G_Calib1[6]               * POLL_RATIO_245 , 'f', 7));
    ui->Label_G8_1                      ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.G_Calib1[7]               * POLL_RATIO_246 , 'f', 7));
    ui->Label_G9_1                      ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.G_Calib1[8]               * POLL_RATIO_249 , 'f', 7));

    ui->Label_ka1_2                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKa_Calib2[0]         * POLL_RATIO_253 , 'f', 7));
    ui->Label_ka2_2                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKa_Calib2[1]         * POLL_RATIO_254 , 'f', 7));
    ui->Label_ka3_2                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKa_Calib2[2]         * POLL_RATIO_257 , 'f', 7));
    ui->Label_ka4_2                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKa_Calib2[3]         * POLL_RATIO_258 , 'f', 7));
    ui->Label_ka5_2                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKa_Calib2[4]         * POLL_RATIO_261 , 'f', 7));
    ui->Label_ka6_2                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKa_Calib2[5]         * POLL_RATIO_262 , 'f', 7));
    ui->Label_ka7_2                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKa_Calib2[6]         * POLL_RATIO_265 , 'f', 7));
    ui->Label_ka8_2                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKa_Calib2[7]         * POLL_RATIO_266 , 'f', 7));
    ui->Label_ka9_2                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKa_Calib2[8]         * POLL_RATIO_269 , 'f', 7));
    ui->Label_kg1_2                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKg_Calib2[0]         * POLL_RATIO_273 , 'f', 7));
    ui->Label_kg2_2                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKg_Calib2[1]         * POLL_RATIO_274 , 'f', 7));
    ui->Label_kg3_2                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKg_Calib2[2]         * POLL_RATIO_277 , 'f', 7));
    ui->Label_kg4_2                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKg_Calib2[3]         * POLL_RATIO_278 , 'f', 7));
    ui->Label_kg5_2                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKg_Calib2[4]         * POLL_RATIO_281 , 'f', 7));
    ui->Label_kg6_2                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKg_Calib2[5]         * POLL_RATIO_282 , 'f', 7));
    ui->Label_kg7_2                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKg_Calib2[6]         * POLL_RATIO_285 , 'f', 7));
    ui->Label_kg8_2                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKg_Calib2[7]         * POLL_RATIO_286 , 'f', 7));
    ui->Label_kg9_2                     ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.deltaKg_Calib2[8]         * POLL_RATIO_289 , 'f', 7));
    ui->Label_G1_2                      ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.G_Calib2[0]               * POLL_RATIO_293 , 'f', 7));
    ui->Label_G2_2                      ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.G_Calib2[1]               * POLL_RATIO_294 , 'f', 7));
    ui->Label_G3_2                      ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.G_Calib2[2]               * POLL_RATIO_297 , 'f', 7));
    ui->Label_G4_2                      ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.G_Calib2[3]               * POLL_RATIO_298 , 'f', 7));
    ui->Label_G5_2                      ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.G_Calib2[4]               * POLL_RATIO_301 , 'f', 7));
    ui->Label_G6_2                      ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.G_Calib2[5]               * POLL_RATIO_302 , 'f', 7));
    ui->Label_G7_2                      ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.G_Calib2[6]               * POLL_RATIO_305 , 'f', 7));
    ui->Label_G8_2                      ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.G_Calib2[7]               * POLL_RATIO_306 , 'f', 7));
    ui->Label_G9_2                      ->setText(QString::number(SerialPort::gjDevicePollingData.GJDeVice_Polling_Msg.G_Calib2[8]               * POLL_RATIO_309 , 'f', 7));

}

// SLOTS
// 串口将轮询数据处理完后发的信号，以便实时更新
void Dialog_PollingData::delDone_GJProtocol_PollingData()
{
    Display_PollingData();
}
