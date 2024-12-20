#ifndef CONSTANT_H
#define CONSTANT_H

// 发送共迹协议时，要求的协议长度
#define send_GJProtocol_length                          192

// 上位机给底层发送的消息码
#define send_Firmware_Updata                            "AA44CC35"
#define send_Calibration_UserInstallationAngle          "AA44CC11"
#define send_Calibration_SystemInstallationAangle       "AA44CC13"
#define send_Calibration_Static                         "AA44CC15"
#define send_Calibration_Dynamic                        "AA44CC17"
#define send_Calibration_Cancel                         "AA44CC19"
#define send_Calibration_SaveResult                     "AA44CC1A"
#define send_Calibration_DontSaveResult                 "AA44CC1C"
#define send_Calibration_WheelBase                      "AA44CC5C"
#define send_Calibration_LeverINS2Rear                  "AA44CC5E"
#define send_Protocol_Change                            "AA44CC31"
#define Kindof_Protocol                                 9               // 协议种类数
#define send_TempCali_SendData                          "AA44CC51"
#define send_TempCali_StopSendData                      "AA44CC53"
#define send_SN_SendSN                                  "AA44CC55"
#define send_ActCode_SendActCode                        "AA44CC57"
#define send_CustomCan_SendCanMsg                       "AA44CC59"
#define send_RTCMSelectType_SendCanMsg                  "AA44CC5A"
#define send_StaticIPPort_SendMsg                       "AA44CC5B"

// Eth cfg
#define send_ETHCfg_Uartdata                            "AA44CC60"
#define rec_ETHCfg_Resonse                              "AA44DD26"

#define send_ReadETHCfg_data                            "AA44CC61"
#define rec_ReadEHTCfdResponse                          "AA44BB64"
#define ETH_CFG_LEN                                     50

// 接收共迹协议时，收到的协议字头，长度
#define receive_GJProtocol_Head                         "AA44AA45"

#define receive_GJProtocol_length                       172
#define receive_GJProtocol_PollingNumber                62


#define sendCustomProtocolHead                          "AA44CC5D"
#define recCustomProtocolReturnHead                     "AA44DD28"


// 上位机收到底层发送的消息码
#define receive_Firmware_PleaseUpdata                   "AA44BB33"
#define receive_Firmware_PleaseWaitUpdata               "AA44BB35"
#define receive_Firmware_ReceiveError                   "AA44BB43"
#define receive_Firmware_FileError                      "AA44BB45"
#define receive_Firmware_UpdataError                    "AA44BB47"
#define receive_Firmware_UpdataSuccess                  "AA44BB49"
#define receive_Calibration_StaticCalibrating           "AA44BB11"
#define receive_Calibration_StaticSuccess               "AA44BB13"
#define receive_Calibration_DynamicCalibrating          "AA44BB15"
#define receive_Calibration_IncTurningRatio             "AA44BB17"
#define receive_Calibration_IncForwardRatio             "AA44BB19"
#define receive_Calibration_PleaseChangeCaliSites       "AA44BB1A"
#define receive_Calibration_DynamicSuccess              "AA44BB1C"
#define receive_Calibration_DynamicSuccess_length       27              // 该带数据帧的长度
#define receive_TempCali_RequestData                    "AA44BB51"
#define receive_TempCali_RepeatData                     "AA44BB53"
#define receive_TempCali_CompleteData                   "AA44BB55"
#define receive_TempCali_DeviceHasSavedData             "AA44BB57"
#define receive_TempCali_DeviceHasSavedData_length       131            // 该带数据帧的长度

// 上位机收到底层发送的确认消息码
#define receiveACK_Calibration_UserInstallationAngle    "AA44DD11"
#define receiveACK_Calibration_SystemInstallationAangle "AA44DD13"
#define receiveACK_Calibration_Static                   "AA44DD15"
#define receiveACK_Calibration_Dynamic                  "AA44DD17"
#define receiveACK_Calibration_Cancel                   "AA44DD19"
#define receiveACK_Calibration_SaveResult               "AA44DD1A"
#define receiveACK_Calibration_DontSaveResult           "AA44DD1C"
#define receiveACK_Calibration_WheelBase                "AA44DD27"
#define receiveACK_Calibration_LeverINS2Rear            "AA44DD29"
#define receiveACK_ProtocolChange_OK                    "AA44DD1E"
#define receiveACK_CustomCan_OK                         "AA44DD21"
#define receiveACK_RTCMSelect_OK                        "AA44DD25"
#define receiveACK_StaticIPPort_OK                      "AA44DD5B"



// 上海经纬度转米数对应系数
#define Pos_ratio_longi (95312.654);
#define Pos_ratio_lati (111194.925);


// 消息1协议
/*
 * 比例系数
 * */
#define RATIO_01 (1              )
#define RATIO_02 (1e-7           )
#define RATIO_03 (1e-7           )
#define RATIO_04 (1e-3           )
#define RATIO_05 (1e+2/pow(2,15) )
#define RATIO_06 (1e+2/pow(2,15) )
#define RATIO_07 (1e+2/pow(2,15) )
#define RATIO_08 (180/pow(2,15)  )
#define RATIO_09 (180/pow(2,15)  )
#define RATIO_10 (180/pow(2,15)  )

#define RATIO_11 (1              )
#define RATIO_12 (1              )
#define RATIO_13 (1e-3           )
#define RATIO_14 (1              )
#define RATIO_15 (1              )
#define RATIO_16 (1              )
#define RATIO_17 (8/pow(2,15)    )
#define RATIO_18 (8/pow(2,15)    )
#define RATIO_19 (8/pow(2,15)    )
#define RATIO_20 (1e+2/pow(2,15) )

#define RATIO_21 (1e+2/pow(2,15) )
#define RATIO_22 (1e+2/pow(2,15) )
#define RATIO_23 (150/pow(2,15)  )
#define RATIO_24 (100/pow(2,16)  )
#define RATIO_25 (100/pow(2,16)  )
#define RATIO_26 (100/pow(2,16)  )
#define RATIO_27 (100/pow(2,16)  )
#define RATIO_28 (100/pow(2,16)  )
#define RATIO_29 (100/pow(2,16)  )
#define RATIO_30 (1              )

#define RATIO_31 (150/pow(2,15)  )
#define RATIO_32 (8/pow(2,15)    )
#define RATIO_33 (8/pow(2,15)    )
#define RATIO_34 (8/pow(2,15)    )
#define RATIO_35 (1e+2/pow(2,15) )
#define RATIO_36 (1e+2/pow(2,15) )
#define RATIO_37 (1e+2/pow(2,15) )
#define RATIO_38 (1              )
#define RATIO_39 (1              )
#define RATIO_40 (100/pow(2,16)  )

#define RATIO_41 (100/pow(2,16)  )
#define RATIO_42 (100/pow(2,16)  )
#define RATIO_43 (1              )
#define RATIO_44 (1              )


#define RATIO_53 (1              )
#define RATIO_54 (1              )
#define RATIO_55 (1              )
#define RATIO_56 (1              )
#define RATIO_57 (1              )
#define RATIO_58 (1e-3           )
#define RATIO_59 (1e+2/pow(2,15) )
#define RATIO_60 (1e+2/pow(2,15) )

#define RATIO_61 (1e+2/pow(2,15) )
#define RATIO_62 (180/pow(2,15)  )
#define RATIO_63 (180/pow(2,15)  )
#define RATIO_64 (32/pow(2,16)   )
#define RATIO_65 (32/pow(2,16)   )
#define RATIO_66 (32/pow(2,16)   )
#define RATIO_67 (32/pow(2,16)   )
#define RATIO_68 (1              )
#define RATIO_69 (1              )
#define RATIO_70 (1              )

#define RATIO_71 (1e-3           )
#define RATIO_72 (1              )
#define RATIO_73 (1              )
#define RATIO_74 (1              )
#define RATIO_75 (360/pow(2,16)  )
#define RATIO_76 (360/pow(2,16)  )
#define RATIO_77 (360/pow(2,16)  )
#define RATIO_78 (360/pow(2,16)  )
#define RATIO_79 (360/pow(2,16)  )
#define RATIO_80 (720/pow(2,16)  )

#define RATIO_81 (720/pow(2,16)  )
#define RATIO_82 (1/pow(2,8)     )
#define RATIO_83 (1              )
#define RATIO_84 (1              )
#define RATIO_85 (1              )
#define RATIO_86 (1              )
#define RATIO_87 (1              )


// 消息1轮询数据      匹配表格行号
/*
 * 比例系数
 * */
#define POLL_RATIO_04  (20/pow(2,15)  )
#define POLL_RATIO_05  (20/pow(2,15)  )
#define POLL_RATIO_06  (20/pow(2,15)  )
#define POLL_RATIO_07  (180/pow(2,15) )

#define POLL_RATIO_10  (180/pow(2,15) )
#define POLL_RATIO_11  (180/pow(2,15) )
#define POLL_RATIO_12  (180/pow(2,15) )
#define POLL_RATIO_13  (180/pow(2,15) )

#define POLL_RATIO_16  (180/pow(2,15) )
#define POLL_RATIO_17  (20/pow(2,15)  )
#define POLL_RATIO_18  (20/pow(2,15)  )
#define POLL_RATIO_19  (20/pow(2,15)  )

#define POLL_RATIO_22  (1/pow(2,15)   )
#define POLL_RATIO_23  (20/pow(2,15)  )
#define POLL_RATIO_24  (20/pow(2,15)  )
#define POLL_RATIO_25  (20/pow(2,15)  )

#define POLL_RATIO_28  (20/pow(2,15)  )
#define POLL_RATIO_29  (20/pow(2,15)  )
#define POLL_RATIO_30  (20/pow(2,15)  )
#define POLL_RATIO_31  (180/pow(2,15) )

#define POLL_RATIO_34  (180/pow(2,15) )
#define POLL_RATIO_35  (180/pow(2,15) )
#define POLL_RATIO_36  (180/pow(2,15) )
#define POLL_RATIO_37  (180/pow(2,15) )

#define POLL_RATIO_40  (180/pow(2,15) )
#define POLL_RATIO_41  (1             )
#define POLL_RATIO_42  (1             )
#define POLL_RATIO_43  (1             )

#define POLL_RATIO_46  (20/pow(2,15)  )
#define POLL_RATIO_47  (20/pow(2,15)  )
#define POLL_RATIO_48  (20/pow(2,15)  )
#define POLL_RATIO_49  (1             )

#define POLL_RATIO_52  (1             )
#define POLL_RATIO_53  (1             )
#define POLL_RATIO_54  (1             )
#define POLL_RATIO_55  (1             )

#define POLL_RATIO_58  (1             )
#define POLL_RATIO_59  (1             )
#define POLL_RATIO_60  (1             )
#define POLL_RATIO_61  (1             )

#define POLL_RATIO_64  (1             )
#define POLL_RATIO_65  (1             )
#define POLL_RATIO_66  (1             )
#define POLL_RATIO_67  (1             )

#define POLL_RATIO_70  (1             )
#define POLL_RATIO_71  (1             )
#define POLL_RATIO_72  (1             )
#define POLL_RATIO_73  (1             )
#define POLL_RATIO_74  (1             )
#define POLL_RATIO_75  (1             )
#define POLL_RATIO_76  (1             )

#define POLL_RATIO_79  (1             )
#define POLL_RATIO_80  (1             )
#define POLL_RATIO_81  (1             )
#define POLL_RATIO_82  (1             )
#define POLL_RATIO_83  (1             )
#define POLL_RATIO_84  (1             )
#define POLL_RATIO_85  (1             )

#define POLL_RATIO_88  (1             )
#define POLL_RATIO_89  (1             )
#define POLL_RATIO_90  (1             )
#define POLL_RATIO_91  (1             )
#define POLL_RATIO_92  (1             )
#define POLL_RATIO_93  (1             )
#define POLL_RATIO_94  (1             )
#define POLL_RATIO_95  (1             )

#define POLL_RATIO_98  (1             )
#define POLL_RATIO_99  (1             )
#define POLL_RATIO_100 (1             )
#define POLL_RATIO_101 (1             )
#define POLL_RATIO_102 (1             )
#define POLL_RATIO_103 (1             )
#define POLL_RATIO_104 (1             )

#define POLL_RATIO_107 (1             )
#define POLL_RATIO_108 (1             )
#define POLL_RATIO_109 (1             )
#define POLL_RATIO_110 (1             )
#define POLL_RATIO_111 (1             )

#define POLL_RATIO_114 (1/pow(2,15)   )
#define POLL_RATIO_115 (1/pow(2,15)   )
#define POLL_RATIO_116 (1/pow(2,15)   )
#define POLL_RATIO_117 (10/pow(2,15)  )

#define POLL_RATIO_120 (10/pow(2,15)  )
#define POLL_RATIO_121 (10/pow(2,15)  )
#define POLL_RATIO_122 (1             )
#define POLL_RATIO_123 (1             )

#define POLL_RATIO_126 (1             )
#define POLL_RATIO_127 (1             )
#define POLL_RATIO_128 (1             )
#define POLL_RATIO_129 (1             )

#define POLL_RATIO_132 (1             )
#define POLL_RATIO_133 (1             )

#define POLL_RATIO_136 (1             )
#define POLL_RATIO_137 (1             )

#define POLL_RATIO_140 (1             )
#define POLL_RATIO_141 (1             )

#define POLL_RATIO_144 (1             )
#define POLL_RATIO_145 (1             )

#define POLL_RATIO_148 (1             )
#define POLL_RATIO_149 (1             )

#define POLL_RATIO_152 (1             )
#define POLL_RATIO_153 (1             )

#define POLL_RATIO_156 (1             )
#define POLL_RATIO_157 (1             )

#define POLL_RATIO_160 (1             )
#define POLL_RATIO_161 (1             )

#define POLL_RATIO_164 (1             )
#define POLL_RATIO_165 (1             )

#define POLL_RATIO_168 (1             )
#define POLL_RATIO_169 (150/pow(2,15) )
#define POLL_RATIO_170 (150/pow(2,15) )
#define POLL_RATIO_171 (150/pow(2,15) )
#define POLL_RATIO_172 (1             )

#define POLL_RATIO_175 (1/pow(2,15)   )
#define POLL_RATIO_176 (1/pow(2,15)   )
#define POLL_RATIO_177 (1/pow(2,15)   )
#define POLL_RATIO_178 (10/pow(2,15)  )

#define POLL_RATIO_181 (10/pow(2,15)  )
#define POLL_RATIO_182 (10/pow(2,15)  )
#define POLL_RATIO_183 (1/pow(2,15)   )
#define POLL_RATIO_184 (1/pow(2,15)   )

#define POLL_RATIO_187 (1/pow(2,15)   )
#define POLL_RATIO_188 (10/pow(2,15)  )
#define POLL_RATIO_189 (10/pow(2,15)  )
#define POLL_RATIO_190 (10/pow(2,15)  )

#define POLL_RATIO_193 (1             )
#define POLL_RATIO_194 (1             )
#define POLL_RATIO_197 (1             )
#define POLL_RATIO_198 (1             )
#define POLL_RATIO_201 (1             )
#define POLL_RATIO_202 (1             )
#define POLL_RATIO_205 (1             )
#define POLL_RATIO_206 (1             )
#define POLL_RATIO_209 (1             )
#define POLL_RATIO_210 (1             )
#define POLL_RATIO_213 (1             )
#define POLL_RATIO_214 (1             )
#define POLL_RATIO_217 (1             )
#define POLL_RATIO_218 (1             )
#define POLL_RATIO_221 (1             )
#define POLL_RATIO_222 (1             )
#define POLL_RATIO_225 (1             )
#define POLL_RATIO_226 (1             )
#define POLL_RATIO_229 (1             )
#define POLL_RATIO_230 (1             )
#define POLL_RATIO_233 (1             )
#define POLL_RATIO_234 (1             )
#define POLL_RATIO_237 (1             )
#define POLL_RATIO_238 (1             )
#define POLL_RATIO_241 (1             )
#define POLL_RATIO_242 (1             )
#define POLL_RATIO_245 (1             )
#define POLL_RATIO_246 (1             )
#define POLL_RATIO_249 (1             )
#define POLL_RATIO_250 (1             )
#define POLL_RATIO_253 (1             )
#define POLL_RATIO_254 (1             )
#define POLL_RATIO_257 (1             )
#define POLL_RATIO_258 (1             )
#define POLL_RATIO_261 (1             )
#define POLL_RATIO_262 (1             )
#define POLL_RATIO_265 (1             )
#define POLL_RATIO_266 (1             )
#define POLL_RATIO_269 (1             )
#define POLL_RATIO_270 (1             )
#define POLL_RATIO_273 (1             )
#define POLL_RATIO_274 (1             )
#define POLL_RATIO_277 (1             )
#define POLL_RATIO_278 (1             )
#define POLL_RATIO_281 (1             )
#define POLL_RATIO_282 (1             )
#define POLL_RATIO_285 (1             )
#define POLL_RATIO_286 (1             )
#define POLL_RATIO_289 (1             )
#define POLL_RATIO_290 (1             )
#define POLL_RATIO_293 (1             )
#define POLL_RATIO_294 (1             )
#define POLL_RATIO_297 (1             )
#define POLL_RATIO_298 (1             )
#define POLL_RATIO_301 (1             )
#define POLL_RATIO_302 (1             )
#define POLL_RATIO_305 (1             )
#define POLL_RATIO_306 (1             )
#define POLL_RATIO_309 (1             )
#define POLL_RATIO_310 (1             )

#endif // CONSTANT_H
