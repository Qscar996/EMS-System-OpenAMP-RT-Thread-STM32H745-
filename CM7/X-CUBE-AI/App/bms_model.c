/**
  ******************************************************************************
  * @file    bms_model.c
  * @author  AST Embedded Analytics Research Platform
  * @date    2026-07-04T02:09:24+0800
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */


#include "bms_model.h"
#include "bms_model_data.h"

#include "ai_platform.h"
#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"



#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_bms_model
 
#undef AI_BMS_MODEL_MODEL_SIGNATURE
#define AI_BMS_MODEL_MODEL_SIGNATURE     "0xfc17ed6f46df86a6d5cb75b3d16b07a5"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "2026-07-04T02:09:24+0800"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_BMS_MODEL_N_BATCHES
#define AI_BMS_MODEL_N_BATCHES         (1)

static ai_ptr g_bms_model_activations_map[1] = AI_C_ARRAY_INIT;
static ai_ptr g_bms_model_weights_map[1] = AI_C_ARRAY_INIT;



/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  serving_default_sequence_input0_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 120, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  pad_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 122, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  reduce_4_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  reduce_4_Mul_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_6_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  reduce_7_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  reduce_7_Mul_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  nl_9_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_10_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_13_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  nl_5_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_11_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_12_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_14_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  nl_14_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  pad_15_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3904, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  reduce_19_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  reduce_19_Mul_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_21_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  reduce_22_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  reduce_22_Mul_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  nl_24_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_25_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_28_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  nl_20_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_26_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_27_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_29_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_33_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  nl_33_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  pad_34_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3968, AI_STATIC)

/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  reduce_41_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  reduce_41_Mul_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_43_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  reduce_44_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  reduce_44_Mul_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  nl_46_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_47_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_50_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  nl_42_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_48_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#45 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_49_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#46 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_51_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#47 */
AI_ARRAY_OBJ_DECLARE(
  nl_51_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#48 */
AI_ARRAY_OBJ_DECLARE(
  pad_52_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3968, AI_STATIC)

/* Array#49 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_55_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#50 */
AI_ARRAY_OBJ_DECLARE(
  reduce_59_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#51 */
AI_ARRAY_OBJ_DECLARE(
  reduce_59_Mul_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#52 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_61_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#53 */
AI_ARRAY_OBJ_DECLARE(
  reduce_62_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#54 */
AI_ARRAY_OBJ_DECLARE(
  reduce_62_Mul_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#55 */
AI_ARRAY_OBJ_DECLARE(
  nl_64_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#56 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_65_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#57 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_68_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#58 */
AI_ARRAY_OBJ_DECLARE(
  nl_60_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#59 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_66_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#60 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_67_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#61 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_69_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#62 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_70_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#63 */
AI_ARRAY_OBJ_DECLARE(
  nl_70_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#64 */
AI_ARRAY_OBJ_DECLARE(
  pad_71_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4096, AI_STATIC)

/* Array#65 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_74_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#66 */
AI_ARRAY_OBJ_DECLARE(
  reduce_78_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#67 */
AI_ARRAY_OBJ_DECLARE(
  reduce_78_Mul_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#68 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_80_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#69 */
AI_ARRAY_OBJ_DECLARE(
  reduce_81_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#70 */
AI_ARRAY_OBJ_DECLARE(
  reduce_81_Mul_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#71 */
AI_ARRAY_OBJ_DECLARE(
  nl_83_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#72 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_84_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#73 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_87_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#74 */
AI_ARRAY_OBJ_DECLARE(
  nl_79_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#75 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_85_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#76 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_86_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#77 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_88_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#78 */
AI_ARRAY_OBJ_DECLARE(
  nl_88_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#79 */
AI_ARRAY_OBJ_DECLARE(
  pad_89_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4096, AI_STATIC)

/* Array#80 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_92_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#81 */
AI_ARRAY_OBJ_DECLARE(
  reduce_96_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#82 */
AI_ARRAY_OBJ_DECLARE(
  reduce_96_Mul_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#83 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_98_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#84 */
AI_ARRAY_OBJ_DECLARE(
  reduce_99_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#85 */
AI_ARRAY_OBJ_DECLARE(
  reduce_99_Mul_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#86 */
AI_ARRAY_OBJ_DECLARE(
  nl_101_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#87 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_102_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#88 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_105_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#89 */
AI_ARRAY_OBJ_DECLARE(
  nl_97_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#90 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_103_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#91 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_104_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#92 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_106_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#93 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_107_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#94 */
AI_ARRAY_OBJ_DECLARE(
  nl_107_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#95 */
AI_ARRAY_OBJ_DECLARE(
  pad_108_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4352, AI_STATIC)

/* Array#96 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_111_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#97 */
AI_ARRAY_OBJ_DECLARE(
  reduce_115_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#98 */
AI_ARRAY_OBJ_DECLARE(
  reduce_115_Mul_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#99 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_117_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#100 */
AI_ARRAY_OBJ_DECLARE(
  reduce_118_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#101 */
AI_ARRAY_OBJ_DECLARE(
  reduce_118_Mul_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#102 */
AI_ARRAY_OBJ_DECLARE(
  nl_120_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#103 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_121_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#104 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_124_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#105 */
AI_ARRAY_OBJ_DECLARE(
  nl_116_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#106 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_122_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#107 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_123_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#108 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_125_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#109 */
AI_ARRAY_OBJ_DECLARE(
  nl_125_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#110 */
AI_ARRAY_OBJ_DECLARE(
  pad_126_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4352, AI_STATIC)

/* Array#111 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_129_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#112 */
AI_ARRAY_OBJ_DECLARE(
  reduce_133_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#113 */
AI_ARRAY_OBJ_DECLARE(
  reduce_133_Mul_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#114 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_135_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#115 */
AI_ARRAY_OBJ_DECLARE(
  reduce_136_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#116 */
AI_ARRAY_OBJ_DECLARE(
  reduce_136_Mul_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#117 */
AI_ARRAY_OBJ_DECLARE(
  nl_138_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#118 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_139_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#119 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_142_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#120 */
AI_ARRAY_OBJ_DECLARE(
  nl_134_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#121 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_140_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#122 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_141_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#123 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_143_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#124 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_144_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#125 */
AI_ARRAY_OBJ_DECLARE(
  nl_144_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#126 */
AI_ARRAY_OBJ_DECLARE(
  pad_145_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4864, AI_STATIC)

/* Array#127 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_148_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#128 */
AI_ARRAY_OBJ_DECLARE(
  reduce_152_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#129 */
AI_ARRAY_OBJ_DECLARE(
  reduce_152_Mul_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#130 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_154_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#131 */
AI_ARRAY_OBJ_DECLARE(
  reduce_155_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#132 */
AI_ARRAY_OBJ_DECLARE(
  reduce_155_Mul_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#133 */
AI_ARRAY_OBJ_DECLARE(
  nl_157_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#134 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_158_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#135 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_161_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#136 */
AI_ARRAY_OBJ_DECLARE(
  nl_153_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#137 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_159_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#138 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_160_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#139 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_162_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#140 */
AI_ARRAY_OBJ_DECLARE(
  nl_162_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#141 */
AI_ARRAY_OBJ_DECLARE(
  pad_163_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4864, AI_STATIC)

/* Array#142 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_166_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#143 */
AI_ARRAY_OBJ_DECLARE(
  reduce_170_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#144 */
AI_ARRAY_OBJ_DECLARE(
  reduce_170_Mul_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#145 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_172_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#146 */
AI_ARRAY_OBJ_DECLARE(
  reduce_173_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#147 */
AI_ARRAY_OBJ_DECLARE(
  reduce_173_Mul_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#148 */
AI_ARRAY_OBJ_DECLARE(
  nl_175_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#149 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_176_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#150 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_179_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#151 */
AI_ARRAY_OBJ_DECLARE(
  nl_171_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#152 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_177_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#153 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_178_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#154 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_180_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#155 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_181_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#156 */
AI_ARRAY_OBJ_DECLARE(
  nl_181_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#157 */
AI_ARRAY_OBJ_DECLARE(
  pad_182_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 5888, AI_STATIC)

/* Array#158 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_185_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#159 */
AI_ARRAY_OBJ_DECLARE(
  reduce_189_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#160 */
AI_ARRAY_OBJ_DECLARE(
  reduce_189_Mul_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#161 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_191_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#162 */
AI_ARRAY_OBJ_DECLARE(
  reduce_192_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#163 */
AI_ARRAY_OBJ_DECLARE(
  reduce_192_Mul_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#164 */
AI_ARRAY_OBJ_DECLARE(
  nl_194_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#165 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_195_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#166 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_198_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#167 */
AI_ARRAY_OBJ_DECLARE(
  nl_190_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#168 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_196_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#169 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_197_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#170 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_199_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#171 */
AI_ARRAY_OBJ_DECLARE(
  nl_199_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#172 */
AI_ARRAY_OBJ_DECLARE(
  pad_200_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 5888, AI_STATIC)

/* Array#173 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_203_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#174 */
AI_ARRAY_OBJ_DECLARE(
  reduce_207_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#175 */
AI_ARRAY_OBJ_DECLARE(
  reduce_207_Mul_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#176 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_209_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#177 */
AI_ARRAY_OBJ_DECLARE(
  reduce_210_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#178 */
AI_ARRAY_OBJ_DECLARE(
  reduce_210_Mul_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#179 */
AI_ARRAY_OBJ_DECLARE(
  nl_212_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#180 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_213_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#181 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_216_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#182 */
AI_ARRAY_OBJ_DECLARE(
  nl_208_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 120, AI_STATIC)

/* Array#183 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_214_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#184 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_215_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#185 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_217_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#186 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_218_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#187 */
AI_ARRAY_OBJ_DECLARE(
  nl_218_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3840, AI_STATIC)

/* Array#188 */
AI_ARRAY_OBJ_DECLARE(
  slice_219_gather_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#189 */
AI_ARRAY_OBJ_DECLARE(
  gemm_220_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#190 */
AI_ARRAY_OBJ_DECLARE(
  nl_220_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#191 */
AI_ARRAY_OBJ_DECLARE(
  gemm_221_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#192 */
AI_ARRAY_OBJ_DECLARE(
  nl_221_nl_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#193 */
AI_ARRAY_OBJ_DECLARE(
  gemm_222_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 1, AI_STATIC)

/* Array#194 */
AI_ARRAY_OBJ_DECLARE(
  slice_219_gather_0_placeholder_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 1, AI_STATIC)

/* Array#195 */
AI_ARRAY_OBJ_DECLARE(
  functional_1_layer_normalization_11_1_Reshape_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#196 */
AI_ARRAY_OBJ_DECLARE(
  functional_1_layer_normalization_10_1_Reshape_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#197 */
AI_ARRAY_OBJ_DECLARE(
  functional_1_layer_normalization_9_1_Reshape_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#198 */
AI_ARRAY_OBJ_DECLARE(
  functional_1_layer_normalization_8_1_Reshape_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#199 */
AI_ARRAY_OBJ_DECLARE(
  functional_1_layer_normalization_7_1_Reshape_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#200 */
AI_ARRAY_OBJ_DECLARE(
  functional_1_layer_normalization_6_1_Reshape_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#201 */
AI_ARRAY_OBJ_DECLARE(
  functional_1_layer_normalization_5_1_Reshape_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#202 */
AI_ARRAY_OBJ_DECLARE(
  functional_1_layer_normalization_4_1_Reshape_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#203 */
AI_ARRAY_OBJ_DECLARE(
  functional_1_layer_normalization_3_1_Reshape_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#204 */
AI_ARRAY_OBJ_DECLARE(
  functional_1_layer_normalization_2_1_Reshape_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#205 */
AI_ARRAY_OBJ_DECLARE(
  functional_1_layer_normalization_1_2_Reshape_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#206 */
AI_ARRAY_OBJ_DECLARE(
  functional_1_layer_normalization_1_Reshape_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#207 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#208 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#209 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)

/* Array#210 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#211 */
AI_ARRAY_OBJ_DECLARE(
  reduce_4_Mul_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)

/* Array#212 */
AI_ARRAY_OBJ_DECLARE(
  reduce_4_Mul_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)

/* Array#213 */
AI_ARRAY_OBJ_DECLARE(
  reduce_7_Mul_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)

/* Array#214 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_12_scale_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#215 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_12_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#216 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3072, AI_STATIC)

/* Array#217 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#218 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_27_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#219 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3072, AI_STATIC)

/* Array#220 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#221 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_49_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#222 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_55_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3072, AI_STATIC)

/* Array#223 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_55_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#224 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_67_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#225 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_74_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3072, AI_STATIC)

/* Array#226 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_74_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#227 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_86_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#228 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_92_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3072, AI_STATIC)

/* Array#229 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_92_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#230 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_104_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#231 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_111_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3072, AI_STATIC)

/* Array#232 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_111_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#233 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_123_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#234 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_129_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3072, AI_STATIC)

/* Array#235 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_129_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#236 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_141_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#237 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_148_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3072, AI_STATIC)

/* Array#238 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_148_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#239 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_160_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#240 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_166_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3072, AI_STATIC)

/* Array#241 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_166_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#242 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_178_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#243 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_185_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3072, AI_STATIC)

/* Array#244 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_185_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#245 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_197_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#246 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_203_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3072, AI_STATIC)

/* Array#247 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_203_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#248 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_215_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#249 */
AI_ARRAY_OBJ_DECLARE(
  gemm_220_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2048, AI_STATIC)

/* Array#250 */
AI_ARRAY_OBJ_DECLARE(
  gemm_220_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#251 */
AI_ARRAY_OBJ_DECLARE(
  gemm_221_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2048, AI_STATIC)

/* Array#252 */
AI_ARRAY_OBJ_DECLARE(
  gemm_221_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#253 */
AI_ARRAY_OBJ_DECLARE(
  gemm_222_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#254 */
AI_ARRAY_OBJ_DECLARE(
  gemm_222_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)

/* Array#255 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)

/* Array#256 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3, AI_STATIC)

/* Array#257 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 96, AI_STATIC)

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_111_bias, AI_STATIC,
  0, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_111_bias_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_111_output, AI_STATIC,
  1, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_111_output_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_111_weights, AI_STATIC,
  2, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 3, 32), AI_STRIDE_INIT(4, 4, 128, 4096, 4096),
  1, &conv2d_111_weights_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_129_bias, AI_STATIC,
  3, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_129_bias_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_129_output, AI_STATIC,
  4, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_129_output_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_129_weights, AI_STATIC,
  5, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 3, 32), AI_STRIDE_INIT(4, 4, 128, 4096, 4096),
  1, &conv2d_129_weights_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_148_bias, AI_STATIC,
  6, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_148_bias_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_148_output, AI_STATIC,
  7, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_148_output_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_148_weights, AI_STATIC,
  8, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 3, 32), AI_STRIDE_INIT(4, 4, 128, 4096, 4096),
  1, &conv2d_148_weights_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_166_bias, AI_STATIC,
  9, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_166_bias_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_166_output, AI_STATIC,
  10, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_166_output_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_166_weights, AI_STATIC,
  11, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 3, 32), AI_STRIDE_INIT(4, 4, 128, 4096, 4096),
  1, &conv2d_166_weights_array, NULL)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_bias, AI_STATIC,
  12, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_17_bias_array, NULL)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_output, AI_STATIC,
  13, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 120, 1), AI_STRIDE_INIT(4, 4, 4, 128, 15360),
  1, &conv2d_17_output_array, NULL)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_output0, AI_STATIC,
  14, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_17_output_array, NULL)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_scratch0, AI_STATIC,
  15, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 3, 1), AI_STRIDE_INIT(4, 4, 4, 128, 384),
  1, &conv2d_17_scratch0_array, NULL)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_weights, AI_STATIC,
  16, 0x0,
  AI_SHAPE_INIT(4, 32, 3, 1, 32), AI_STRIDE_INIT(4, 4, 128, 4096, 12288),
  1, &conv2d_17_weights_array, NULL)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_185_bias, AI_STATIC,
  17, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_185_bias_array, NULL)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_185_output, AI_STATIC,
  18, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_185_output_array, NULL)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_185_weights, AI_STATIC,
  19, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 3, 32), AI_STRIDE_INIT(4, 4, 128, 4096, 4096),
  1, &conv2d_185_weights_array, NULL)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_203_bias, AI_STATIC,
  20, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_203_bias_array, NULL)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_203_output, AI_STATIC,
  21, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_203_output_array, NULL)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_203_weights, AI_STATIC,
  22, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 3, 32), AI_STRIDE_INIT(4, 4, 128, 4096, 4096),
  1, &conv2d_203_weights_array, NULL)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_bias, AI_STATIC,
  23, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_2_bias_array, NULL)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_output, AI_STATIC,
  24, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 120, 1), AI_STRIDE_INIT(4, 4, 4, 128, 15360),
  1, &conv2d_2_output_array, NULL)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_output0, AI_STATIC,
  25, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_2_output_array, NULL)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_scratch0, AI_STATIC,
  26, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 3, 1), AI_STRIDE_INIT(4, 4, 4, 4, 12),
  1, &conv2d_2_scratch0_array, NULL)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_weights, AI_STATIC,
  27, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 1, 32), AI_STRIDE_INIT(4, 4, 4, 128, 384),
  1, &conv2d_2_weights_array, NULL)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_bias, AI_STATIC,
  28, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_31_bias_array, NULL)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_output, AI_STATIC,
  29, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 120, 1), AI_STRIDE_INIT(4, 4, 4, 128, 15360),
  1, &conv2d_31_output_array, NULL)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_output0, AI_STATIC,
  30, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_31_output_array, NULL)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_scratch0, AI_STATIC,
  31, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &conv2d_31_scratch0_array, NULL)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_weights, AI_STATIC,
  32, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 32), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_31_weights_array, NULL)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_bias, AI_STATIC,
  33, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_37_bias_array, NULL)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_output, AI_STATIC,
  34, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_37_output_array, NULL)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_weights, AI_STATIC,
  35, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 3, 32), AI_STRIDE_INIT(4, 4, 128, 4096, 4096),
  1, &conv2d_37_weights_array, NULL)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_55_bias, AI_STATIC,
  36, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_55_bias_array, NULL)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_55_output, AI_STATIC,
  37, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_55_output_array, NULL)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_55_weights, AI_STATIC,
  38, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 3, 32), AI_STRIDE_INIT(4, 4, 128, 4096, 4096),
  1, &conv2d_55_weights_array, NULL)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_74_bias, AI_STATIC,
  39, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_74_bias_array, NULL)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_74_output, AI_STATIC,
  40, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_74_output_array, NULL)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_74_weights, AI_STATIC,
  41, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 3, 32), AI_STRIDE_INIT(4, 4, 128, 4096, 4096),
  1, &conv2d_74_weights_array, NULL)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_92_bias, AI_STATIC,
  42, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_92_bias_array, NULL)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_92_output, AI_STATIC,
  43, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_92_output_array, NULL)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_92_weights, AI_STATIC,
  44, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 3, 32), AI_STRIDE_INIT(4, 4, 128, 4096, 4096),
  1, &conv2d_92_weights_array, NULL)

/* Tensor #45 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_102_output, AI_STATIC,
  45, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_102_output_array, NULL)

/* Tensor #46 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_103_output, AI_STATIC,
  46, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_103_output_array, NULL)

/* Tensor #47 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_104_bias, AI_STATIC,
  47, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_104_bias_array, NULL)

/* Tensor #48 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_104_output, AI_STATIC,
  48, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_104_output_array, NULL)

/* Tensor #49 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_105_output, AI_STATIC,
  49, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_105_output_array, NULL)

/* Tensor #50 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_106_output, AI_STATIC,
  50, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_106_output_array, NULL)

/* Tensor #51 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_107_output, AI_STATIC,
  51, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_107_output_array, NULL)

/* Tensor #52 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_10_output, AI_STATIC,
  52, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_10_output_array, NULL)

/* Tensor #53 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_117_output, AI_STATIC,
  53, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_117_output_array, NULL)

/* Tensor #54 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_11_output, AI_STATIC,
  54, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_11_output_array, NULL)

/* Tensor #55 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_121_output, AI_STATIC,
  55, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_121_output_array, NULL)

/* Tensor #56 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_122_output, AI_STATIC,
  56, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_122_output_array, NULL)

/* Tensor #57 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_123_bias, AI_STATIC,
  57, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_123_bias_array, NULL)

/* Tensor #58 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_123_output, AI_STATIC,
  58, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_123_output_array, NULL)

/* Tensor #59 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_124_output, AI_STATIC,
  59, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_124_output_array, NULL)

/* Tensor #60 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_125_output, AI_STATIC,
  60, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_125_output_array, NULL)

/* Tensor #61 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_12_bias, AI_STATIC,
  61, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_12_bias_array, NULL)

/* Tensor #62 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_12_output, AI_STATIC,
  62, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_12_output_array, NULL)

/* Tensor #63 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_12_scale, AI_STATIC,
  63, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_12_scale_array, NULL)

/* Tensor #64 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_135_output, AI_STATIC,
  64, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_135_output_array, NULL)

/* Tensor #65 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_139_output, AI_STATIC,
  65, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_139_output_array, NULL)

/* Tensor #66 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_13_output, AI_STATIC,
  66, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_13_output_array, NULL)

/* Tensor #67 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_140_output, AI_STATIC,
  67, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_140_output_array, NULL)

/* Tensor #68 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_141_bias, AI_STATIC,
  68, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_141_bias_array, NULL)

/* Tensor #69 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_141_output, AI_STATIC,
  69, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_141_output_array, NULL)

/* Tensor #70 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_142_output, AI_STATIC,
  70, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_142_output_array, NULL)

/* Tensor #71 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_143_output, AI_STATIC,
  71, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_143_output_array, NULL)

/* Tensor #72 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_144_output, AI_STATIC,
  72, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_144_output_array, NULL)

/* Tensor #73 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_14_output, AI_STATIC,
  73, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_14_output_array, NULL)

/* Tensor #74 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_154_output, AI_STATIC,
  74, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_154_output_array, NULL)

/* Tensor #75 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_158_output, AI_STATIC,
  75, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_158_output_array, NULL)

/* Tensor #76 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_159_output, AI_STATIC,
  76, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_159_output_array, NULL)

/* Tensor #77 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_160_bias, AI_STATIC,
  77, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_160_bias_array, NULL)

/* Tensor #78 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_160_output, AI_STATIC,
  78, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_160_output_array, NULL)

/* Tensor #79 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_161_output, AI_STATIC,
  79, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_161_output_array, NULL)

/* Tensor #80 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_162_output, AI_STATIC,
  80, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_162_output_array, NULL)

/* Tensor #81 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_172_output, AI_STATIC,
  81, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_172_output_array, NULL)

/* Tensor #82 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_176_output, AI_STATIC,
  82, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_176_output_array, NULL)

/* Tensor #83 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_177_output, AI_STATIC,
  83, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_177_output_array, NULL)

/* Tensor #84 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_178_bias, AI_STATIC,
  84, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_178_bias_array, NULL)

/* Tensor #85 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_178_output, AI_STATIC,
  85, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_178_output_array, NULL)

/* Tensor #86 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_179_output, AI_STATIC,
  86, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_179_output_array, NULL)

/* Tensor #87 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_180_output, AI_STATIC,
  87, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_180_output_array, NULL)

/* Tensor #88 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_181_output, AI_STATIC,
  88, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_181_output_array, NULL)

/* Tensor #89 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_191_output, AI_STATIC,
  89, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_191_output_array, NULL)

/* Tensor #90 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_195_output, AI_STATIC,
  90, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_195_output_array, NULL)

/* Tensor #91 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_196_output, AI_STATIC,
  91, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_196_output_array, NULL)

/* Tensor #92 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_197_bias, AI_STATIC,
  92, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_197_bias_array, NULL)

/* Tensor #93 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_197_output, AI_STATIC,
  93, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_197_output_array, NULL)

/* Tensor #94 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_198_output, AI_STATIC,
  94, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_198_output_array, NULL)

/* Tensor #95 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_199_output, AI_STATIC,
  95, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_199_output_array, NULL)

/* Tensor #96 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_209_output, AI_STATIC,
  96, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_209_output_array, NULL)

/* Tensor #97 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_213_output, AI_STATIC,
  97, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_213_output_array, NULL)

/* Tensor #98 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_214_output, AI_STATIC,
  98, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_214_output_array, NULL)

/* Tensor #99 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_215_bias, AI_STATIC,
  99, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_215_bias_array, NULL)

/* Tensor #100 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_215_output, AI_STATIC,
  100, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_215_output_array, NULL)

/* Tensor #101 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_216_output, AI_STATIC,
  101, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_216_output_array, NULL)

/* Tensor #102 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_217_output, AI_STATIC,
  102, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_217_output_array, NULL)

/* Tensor #103 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_218_output, AI_STATIC,
  103, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_218_output_array, NULL)

/* Tensor #104 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_21_output, AI_STATIC,
  104, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_21_output_array, NULL)

/* Tensor #105 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_25_output, AI_STATIC,
  105, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_25_output_array, NULL)

/* Tensor #106 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_26_output, AI_STATIC,
  106, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_26_output_array, NULL)

/* Tensor #107 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_27_bias, AI_STATIC,
  107, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_27_bias_array, NULL)

/* Tensor #108 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_27_output, AI_STATIC,
  108, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_27_output_array, NULL)

/* Tensor #109 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_28_output, AI_STATIC,
  109, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_28_output_array, NULL)

/* Tensor #110 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_29_output, AI_STATIC,
  110, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_29_output_array, NULL)

/* Tensor #111 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_33_output, AI_STATIC,
  111, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_33_output_array, NULL)

/* Tensor #112 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_43_output, AI_STATIC,
  112, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_43_output_array, NULL)

/* Tensor #113 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_47_output, AI_STATIC,
  113, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_47_output_array, NULL)

/* Tensor #114 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_48_output, AI_STATIC,
  114, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_48_output_array, NULL)

/* Tensor #115 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_49_bias, AI_STATIC,
  115, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_49_bias_array, NULL)

/* Tensor #116 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_49_output, AI_STATIC,
  116, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_49_output_array, NULL)

/* Tensor #117 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_50_output, AI_STATIC,
  117, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_50_output_array, NULL)

/* Tensor #118 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_51_output, AI_STATIC,
  118, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_51_output_array, NULL)

/* Tensor #119 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_61_output, AI_STATIC,
  119, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_61_output_array, NULL)

/* Tensor #120 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_65_output, AI_STATIC,
  120, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_65_output_array, NULL)

/* Tensor #121 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_66_output, AI_STATIC,
  121, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_66_output_array, NULL)

/* Tensor #122 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_67_bias, AI_STATIC,
  122, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_67_bias_array, NULL)

/* Tensor #123 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_67_output, AI_STATIC,
  123, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_67_output_array, NULL)

/* Tensor #124 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_68_output, AI_STATIC,
  124, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_68_output_array, NULL)

/* Tensor #125 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_69_output, AI_STATIC,
  125, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_69_output_array, NULL)

/* Tensor #126 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_6_output, AI_STATIC,
  126, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_6_output_array, NULL)

/* Tensor #127 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_70_output, AI_STATIC,
  127, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_70_output_array, NULL)

/* Tensor #128 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_80_output, AI_STATIC,
  128, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_80_output_array, NULL)

/* Tensor #129 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_84_output, AI_STATIC,
  129, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_84_output_array, NULL)

/* Tensor #130 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_85_output, AI_STATIC,
  130, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_85_output_array, NULL)

/* Tensor #131 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_86_bias, AI_STATIC,
  131, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_86_bias_array, NULL)

/* Tensor #132 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_86_output, AI_STATIC,
  132, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_86_output_array, NULL)

/* Tensor #133 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_87_output, AI_STATIC,
  133, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_87_output_array, NULL)

/* Tensor #134 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_88_output, AI_STATIC,
  134, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_88_output_array, NULL)

/* Tensor #135 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_98_output, AI_STATIC,
  135, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &eltwise_98_output_array, NULL)

/* Tensor #136 */
AI_TENSOR_OBJ_DECLARE(
  functional_1_layer_normalization_10_1_Reshape, AI_STATIC,
  136, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &functional_1_layer_normalization_10_1_Reshape_array, NULL)

/* Tensor #137 */
AI_TENSOR_OBJ_DECLARE(
  functional_1_layer_normalization_11_1_Reshape, AI_STATIC,
  137, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &functional_1_layer_normalization_11_1_Reshape_array, NULL)

/* Tensor #138 */
AI_TENSOR_OBJ_DECLARE(
  functional_1_layer_normalization_1_2_Reshape, AI_STATIC,
  138, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &functional_1_layer_normalization_1_2_Reshape_array, NULL)

/* Tensor #139 */
AI_TENSOR_OBJ_DECLARE(
  functional_1_layer_normalization_1_Reshape, AI_STATIC,
  139, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &functional_1_layer_normalization_1_Reshape_array, NULL)

/* Tensor #140 */
AI_TENSOR_OBJ_DECLARE(
  functional_1_layer_normalization_2_1_Reshape, AI_STATIC,
  140, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &functional_1_layer_normalization_2_1_Reshape_array, NULL)

/* Tensor #141 */
AI_TENSOR_OBJ_DECLARE(
  functional_1_layer_normalization_3_1_Reshape, AI_STATIC,
  141, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &functional_1_layer_normalization_3_1_Reshape_array, NULL)

/* Tensor #142 */
AI_TENSOR_OBJ_DECLARE(
  functional_1_layer_normalization_4_1_Reshape, AI_STATIC,
  142, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &functional_1_layer_normalization_4_1_Reshape_array, NULL)

/* Tensor #143 */
AI_TENSOR_OBJ_DECLARE(
  functional_1_layer_normalization_5_1_Reshape, AI_STATIC,
  143, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &functional_1_layer_normalization_5_1_Reshape_array, NULL)

/* Tensor #144 */
AI_TENSOR_OBJ_DECLARE(
  functional_1_layer_normalization_6_1_Reshape, AI_STATIC,
  144, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &functional_1_layer_normalization_6_1_Reshape_array, NULL)

/* Tensor #145 */
AI_TENSOR_OBJ_DECLARE(
  functional_1_layer_normalization_7_1_Reshape, AI_STATIC,
  145, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &functional_1_layer_normalization_7_1_Reshape_array, NULL)

/* Tensor #146 */
AI_TENSOR_OBJ_DECLARE(
  functional_1_layer_normalization_8_1_Reshape, AI_STATIC,
  146, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &functional_1_layer_normalization_8_1_Reshape_array, NULL)

/* Tensor #147 */
AI_TENSOR_OBJ_DECLARE(
  functional_1_layer_normalization_9_1_Reshape, AI_STATIC,
  147, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &functional_1_layer_normalization_9_1_Reshape_array, NULL)

/* Tensor #148 */
AI_TENSOR_OBJ_DECLARE(
  gemm_220_bias, AI_STATIC,
  148, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &gemm_220_bias_array, NULL)

/* Tensor #149 */
AI_TENSOR_OBJ_DECLARE(
  gemm_220_output, AI_STATIC,
  149, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &gemm_220_output_array, NULL)

/* Tensor #150 */
AI_TENSOR_OBJ_DECLARE(
  gemm_220_weights, AI_STATIC,
  150, 0x0,
  AI_SHAPE_INIT(4, 32, 64, 1, 1), AI_STRIDE_INIT(4, 4, 128, 8192, 8192),
  1, &gemm_220_weights_array, NULL)

/* Tensor #151 */
AI_TENSOR_OBJ_DECLARE(
  gemm_221_bias, AI_STATIC,
  151, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &gemm_221_bias_array, NULL)

/* Tensor #152 */
AI_TENSOR_OBJ_DECLARE(
  gemm_221_output, AI_STATIC,
  152, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &gemm_221_output_array, NULL)

/* Tensor #153 */
AI_TENSOR_OBJ_DECLARE(
  gemm_221_weights, AI_STATIC,
  153, 0x0,
  AI_SHAPE_INIT(4, 64, 32, 1, 1), AI_STRIDE_INIT(4, 4, 256, 8192, 8192),
  1, &gemm_221_weights_array, NULL)

/* Tensor #154 */
AI_TENSOR_OBJ_DECLARE(
  gemm_222_bias, AI_STATIC,
  154, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &gemm_222_bias_array, NULL)

/* Tensor #155 */
AI_TENSOR_OBJ_DECLARE(
  gemm_222_output, AI_STATIC,
  155, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &gemm_222_output_array, NULL)

/* Tensor #156 */
AI_TENSOR_OBJ_DECLARE(
  gemm_222_weights, AI_STATIC,
  156, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 1, 1), AI_STRIDE_INIT(4, 4, 128, 128, 128),
  1, &gemm_222_weights_array, NULL)

/* Tensor #157 */
AI_TENSOR_OBJ_DECLARE(
  nl_101_output, AI_STATIC,
  157, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &nl_101_output_array, NULL)

/* Tensor #158 */
AI_TENSOR_OBJ_DECLARE(
  nl_107_nl_output, AI_STATIC,
  158, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &nl_107_nl_output_array, NULL)

/* Tensor #159 */
AI_TENSOR_OBJ_DECLARE(
  nl_116_output, AI_STATIC,
  159, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &nl_116_output_array, NULL)

/* Tensor #160 */
AI_TENSOR_OBJ_DECLARE(
  nl_120_output, AI_STATIC,
  160, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &nl_120_output_array, NULL)

/* Tensor #161 */
AI_TENSOR_OBJ_DECLARE(
  nl_125_nl_output, AI_STATIC,
  161, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &nl_125_nl_output_array, NULL)

/* Tensor #162 */
AI_TENSOR_OBJ_DECLARE(
  nl_134_output, AI_STATIC,
  162, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &nl_134_output_array, NULL)

/* Tensor #163 */
AI_TENSOR_OBJ_DECLARE(
  nl_138_output, AI_STATIC,
  163, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &nl_138_output_array, NULL)

/* Tensor #164 */
AI_TENSOR_OBJ_DECLARE(
  nl_144_nl_output, AI_STATIC,
  164, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &nl_144_nl_output_array, NULL)

/* Tensor #165 */
AI_TENSOR_OBJ_DECLARE(
  nl_14_nl_output, AI_STATIC,
  165, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &nl_14_nl_output_array, NULL)

/* Tensor #166 */
AI_TENSOR_OBJ_DECLARE(
  nl_153_output, AI_STATIC,
  166, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &nl_153_output_array, NULL)

/* Tensor #167 */
AI_TENSOR_OBJ_DECLARE(
  nl_157_output, AI_STATIC,
  167, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &nl_157_output_array, NULL)

/* Tensor #168 */
AI_TENSOR_OBJ_DECLARE(
  nl_162_nl_output, AI_STATIC,
  168, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &nl_162_nl_output_array, NULL)

/* Tensor #169 */
AI_TENSOR_OBJ_DECLARE(
  nl_171_output, AI_STATIC,
  169, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &nl_171_output_array, NULL)

/* Tensor #170 */
AI_TENSOR_OBJ_DECLARE(
  nl_175_output, AI_STATIC,
  170, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &nl_175_output_array, NULL)

/* Tensor #171 */
AI_TENSOR_OBJ_DECLARE(
  nl_181_nl_output, AI_STATIC,
  171, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &nl_181_nl_output_array, NULL)

/* Tensor #172 */
AI_TENSOR_OBJ_DECLARE(
  nl_190_output, AI_STATIC,
  172, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &nl_190_output_array, NULL)

/* Tensor #173 */
AI_TENSOR_OBJ_DECLARE(
  nl_194_output, AI_STATIC,
  173, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &nl_194_output_array, NULL)

/* Tensor #174 */
AI_TENSOR_OBJ_DECLARE(
  nl_199_nl_output, AI_STATIC,
  174, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &nl_199_nl_output_array, NULL)

/* Tensor #175 */
AI_TENSOR_OBJ_DECLARE(
  nl_208_output, AI_STATIC,
  175, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &nl_208_output_array, NULL)

/* Tensor #176 */
AI_TENSOR_OBJ_DECLARE(
  nl_20_output, AI_STATIC,
  176, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &nl_20_output_array, NULL)

/* Tensor #177 */
AI_TENSOR_OBJ_DECLARE(
  nl_212_output, AI_STATIC,
  177, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &nl_212_output_array, NULL)

/* Tensor #178 */
AI_TENSOR_OBJ_DECLARE(
  nl_218_nl_output, AI_STATIC,
  178, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &nl_218_nl_output_array, NULL)

/* Tensor #179 */
AI_TENSOR_OBJ_DECLARE(
  nl_220_nl_output, AI_STATIC,
  179, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &nl_220_nl_output_array, NULL)

/* Tensor #180 */
AI_TENSOR_OBJ_DECLARE(
  nl_221_nl_output, AI_STATIC,
  180, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &nl_221_nl_output_array, NULL)

/* Tensor #181 */
AI_TENSOR_OBJ_DECLARE(
  nl_24_output, AI_STATIC,
  181, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &nl_24_output_array, NULL)

/* Tensor #182 */
AI_TENSOR_OBJ_DECLARE(
  nl_33_nl_output, AI_STATIC,
  182, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &nl_33_nl_output_array, NULL)

/* Tensor #183 */
AI_TENSOR_OBJ_DECLARE(
  nl_42_output, AI_STATIC,
  183, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &nl_42_output_array, NULL)

/* Tensor #184 */
AI_TENSOR_OBJ_DECLARE(
  nl_46_output, AI_STATIC,
  184, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &nl_46_output_array, NULL)

/* Tensor #185 */
AI_TENSOR_OBJ_DECLARE(
  nl_51_nl_output, AI_STATIC,
  185, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &nl_51_nl_output_array, NULL)

/* Tensor #186 */
AI_TENSOR_OBJ_DECLARE(
  nl_5_output, AI_STATIC,
  186, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &nl_5_output_array, NULL)

/* Tensor #187 */
AI_TENSOR_OBJ_DECLARE(
  nl_60_output, AI_STATIC,
  187, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &nl_60_output_array, NULL)

/* Tensor #188 */
AI_TENSOR_OBJ_DECLARE(
  nl_64_output, AI_STATIC,
  188, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &nl_64_output_array, NULL)

/* Tensor #189 */
AI_TENSOR_OBJ_DECLARE(
  nl_70_nl_output, AI_STATIC,
  189, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &nl_70_nl_output_array, NULL)

/* Tensor #190 */
AI_TENSOR_OBJ_DECLARE(
  nl_79_output, AI_STATIC,
  190, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &nl_79_output_array, NULL)

/* Tensor #191 */
AI_TENSOR_OBJ_DECLARE(
  nl_83_output, AI_STATIC,
  191, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &nl_83_output_array, NULL)

/* Tensor #192 */
AI_TENSOR_OBJ_DECLARE(
  nl_88_nl_output, AI_STATIC,
  192, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 120), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &nl_88_nl_output_array, NULL)

/* Tensor #193 */
AI_TENSOR_OBJ_DECLARE(
  nl_97_output, AI_STATIC,
  193, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &nl_97_output_array, NULL)

/* Tensor #194 */
AI_TENSOR_OBJ_DECLARE(
  nl_9_output, AI_STATIC,
  194, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &nl_9_output_array, NULL)

/* Tensor #195 */
AI_TENSOR_OBJ_DECLARE(
  pad_0_output, AI_STATIC,
  195, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 122), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &pad_0_output_array, NULL)

/* Tensor #196 */
AI_TENSOR_OBJ_DECLARE(
  pad_0_output0, AI_STATIC,
  196, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 122, 1), AI_STRIDE_INIT(4, 4, 4, 4, 488),
  1, &pad_0_output_array, NULL)

/* Tensor #197 */
AI_TENSOR_OBJ_DECLARE(
  pad_108_output, AI_STATIC,
  197, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 136), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &pad_108_output_array, NULL)

/* Tensor #198 */
AI_TENSOR_OBJ_DECLARE(
  pad_126_output, AI_STATIC,
  198, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 136), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &pad_126_output_array, NULL)

/* Tensor #199 */
AI_TENSOR_OBJ_DECLARE(
  pad_145_output, AI_STATIC,
  199, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 152), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &pad_145_output_array, NULL)

/* Tensor #200 */
AI_TENSOR_OBJ_DECLARE(
  pad_15_output, AI_STATIC,
  200, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 122), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &pad_15_output_array, NULL)

/* Tensor #201 */
AI_TENSOR_OBJ_DECLARE(
  pad_15_output0, AI_STATIC,
  201, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 122, 1), AI_STRIDE_INIT(4, 4, 4, 128, 15616),
  1, &pad_15_output_array, NULL)

/* Tensor #202 */
AI_TENSOR_OBJ_DECLARE(
  pad_163_output, AI_STATIC,
  202, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 152), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &pad_163_output_array, NULL)

/* Tensor #203 */
AI_TENSOR_OBJ_DECLARE(
  pad_182_output, AI_STATIC,
  203, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 184), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &pad_182_output_array, NULL)

/* Tensor #204 */
AI_TENSOR_OBJ_DECLARE(
  pad_200_output, AI_STATIC,
  204, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 184), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &pad_200_output_array, NULL)

/* Tensor #205 */
AI_TENSOR_OBJ_DECLARE(
  pad_34_output, AI_STATIC,
  205, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 124), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &pad_34_output_array, NULL)

/* Tensor #206 */
AI_TENSOR_OBJ_DECLARE(
  pad_52_output, AI_STATIC,
  206, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 124), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &pad_52_output_array, NULL)

/* Tensor #207 */
AI_TENSOR_OBJ_DECLARE(
  pad_71_output, AI_STATIC,
  207, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 128), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &pad_71_output_array, NULL)

/* Tensor #208 */
AI_TENSOR_OBJ_DECLARE(
  pad_89_output, AI_STATIC,
  208, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 128), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &pad_89_output_array, NULL)

/* Tensor #209 */
AI_TENSOR_OBJ_DECLARE(
  reduce_115_Mul_output, AI_STATIC,
  209, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_115_Mul_output_array, NULL)

/* Tensor #210 */
AI_TENSOR_OBJ_DECLARE(
  reduce_115_output, AI_STATIC,
  210, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_115_output_array, NULL)

/* Tensor #211 */
AI_TENSOR_OBJ_DECLARE(
  reduce_118_Mul_output, AI_STATIC,
  211, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_118_Mul_output_array, NULL)

/* Tensor #212 */
AI_TENSOR_OBJ_DECLARE(
  reduce_118_output, AI_STATIC,
  212, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_118_output_array, NULL)

/* Tensor #213 */
AI_TENSOR_OBJ_DECLARE(
  reduce_133_Mul_output, AI_STATIC,
  213, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_133_Mul_output_array, NULL)

/* Tensor #214 */
AI_TENSOR_OBJ_DECLARE(
  reduce_133_output, AI_STATIC,
  214, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_133_output_array, NULL)

/* Tensor #215 */
AI_TENSOR_OBJ_DECLARE(
  reduce_136_Mul_output, AI_STATIC,
  215, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_136_Mul_output_array, NULL)

/* Tensor #216 */
AI_TENSOR_OBJ_DECLARE(
  reduce_136_output, AI_STATIC,
  216, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_136_output_array, NULL)

/* Tensor #217 */
AI_TENSOR_OBJ_DECLARE(
  reduce_152_Mul_output, AI_STATIC,
  217, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_152_Mul_output_array, NULL)

/* Tensor #218 */
AI_TENSOR_OBJ_DECLARE(
  reduce_152_output, AI_STATIC,
  218, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_152_output_array, NULL)

/* Tensor #219 */
AI_TENSOR_OBJ_DECLARE(
  reduce_155_Mul_output, AI_STATIC,
  219, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_155_Mul_output_array, NULL)

/* Tensor #220 */
AI_TENSOR_OBJ_DECLARE(
  reduce_155_output, AI_STATIC,
  220, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_155_output_array, NULL)

/* Tensor #221 */
AI_TENSOR_OBJ_DECLARE(
  reduce_170_Mul_output, AI_STATIC,
  221, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_170_Mul_output_array, NULL)

/* Tensor #222 */
AI_TENSOR_OBJ_DECLARE(
  reduce_170_output, AI_STATIC,
  222, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_170_output_array, NULL)

/* Tensor #223 */
AI_TENSOR_OBJ_DECLARE(
  reduce_173_Mul_output, AI_STATIC,
  223, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_173_Mul_output_array, NULL)

/* Tensor #224 */
AI_TENSOR_OBJ_DECLARE(
  reduce_173_output, AI_STATIC,
  224, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_173_output_array, NULL)

/* Tensor #225 */
AI_TENSOR_OBJ_DECLARE(
  reduce_189_Mul_output, AI_STATIC,
  225, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_189_Mul_output_array, NULL)

/* Tensor #226 */
AI_TENSOR_OBJ_DECLARE(
  reduce_189_output, AI_STATIC,
  226, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_189_output_array, NULL)

/* Tensor #227 */
AI_TENSOR_OBJ_DECLARE(
  reduce_192_Mul_output, AI_STATIC,
  227, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_192_Mul_output_array, NULL)

/* Tensor #228 */
AI_TENSOR_OBJ_DECLARE(
  reduce_192_output, AI_STATIC,
  228, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_192_output_array, NULL)

/* Tensor #229 */
AI_TENSOR_OBJ_DECLARE(
  reduce_19_Mul_output, AI_STATIC,
  229, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_19_Mul_output_array, NULL)

/* Tensor #230 */
AI_TENSOR_OBJ_DECLARE(
  reduce_19_output, AI_STATIC,
  230, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_19_output_array, NULL)

/* Tensor #231 */
AI_TENSOR_OBJ_DECLARE(
  reduce_207_Mul_output, AI_STATIC,
  231, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_207_Mul_output_array, NULL)

/* Tensor #232 */
AI_TENSOR_OBJ_DECLARE(
  reduce_207_output, AI_STATIC,
  232, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_207_output_array, NULL)

/* Tensor #233 */
AI_TENSOR_OBJ_DECLARE(
  reduce_210_Mul_output, AI_STATIC,
  233, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_210_Mul_output_array, NULL)

/* Tensor #234 */
AI_TENSOR_OBJ_DECLARE(
  reduce_210_output, AI_STATIC,
  234, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_210_output_array, NULL)

/* Tensor #235 */
AI_TENSOR_OBJ_DECLARE(
  reduce_22_Mul_output, AI_STATIC,
  235, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_22_Mul_output_array, NULL)

/* Tensor #236 */
AI_TENSOR_OBJ_DECLARE(
  reduce_22_output, AI_STATIC,
  236, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_22_output_array, NULL)

/* Tensor #237 */
AI_TENSOR_OBJ_DECLARE(
  reduce_41_Mul_output, AI_STATIC,
  237, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_41_Mul_output_array, NULL)

/* Tensor #238 */
AI_TENSOR_OBJ_DECLARE(
  reduce_41_output, AI_STATIC,
  238, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_41_output_array, NULL)

/* Tensor #239 */
AI_TENSOR_OBJ_DECLARE(
  reduce_44_Mul_output, AI_STATIC,
  239, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_44_Mul_output_array, NULL)

/* Tensor #240 */
AI_TENSOR_OBJ_DECLARE(
  reduce_44_output, AI_STATIC,
  240, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_44_output_array, NULL)

/* Tensor #241 */
AI_TENSOR_OBJ_DECLARE(
  reduce_4_Mul_bias, AI_STATIC,
  241, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_4_Mul_bias_array, NULL)

/* Tensor #242 */
AI_TENSOR_OBJ_DECLARE(
  reduce_4_Mul_output, AI_STATIC,
  242, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_4_Mul_output_array, NULL)

/* Tensor #243 */
AI_TENSOR_OBJ_DECLARE(
  reduce_4_Mul_scale, AI_STATIC,
  243, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_4_Mul_scale_array, NULL)

/* Tensor #244 */
AI_TENSOR_OBJ_DECLARE(
  reduce_4_output, AI_STATIC,
  244, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_4_output_array, NULL)

/* Tensor #245 */
AI_TENSOR_OBJ_DECLARE(
  reduce_59_Mul_output, AI_STATIC,
  245, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_59_Mul_output_array, NULL)

/* Tensor #246 */
AI_TENSOR_OBJ_DECLARE(
  reduce_59_output, AI_STATIC,
  246, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_59_output_array, NULL)

/* Tensor #247 */
AI_TENSOR_OBJ_DECLARE(
  reduce_62_Mul_output, AI_STATIC,
  247, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_62_Mul_output_array, NULL)

/* Tensor #248 */
AI_TENSOR_OBJ_DECLARE(
  reduce_62_output, AI_STATIC,
  248, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_62_output_array, NULL)

/* Tensor #249 */
AI_TENSOR_OBJ_DECLARE(
  reduce_78_Mul_output, AI_STATIC,
  249, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_78_Mul_output_array, NULL)

/* Tensor #250 */
AI_TENSOR_OBJ_DECLARE(
  reduce_78_output, AI_STATIC,
  250, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_78_output_array, NULL)

/* Tensor #251 */
AI_TENSOR_OBJ_DECLARE(
  reduce_7_Mul_bias, AI_STATIC,
  251, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_7_Mul_bias_array, NULL)

/* Tensor #252 */
AI_TENSOR_OBJ_DECLARE(
  reduce_7_Mul_output, AI_STATIC,
  252, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_7_Mul_output_array, NULL)

/* Tensor #253 */
AI_TENSOR_OBJ_DECLARE(
  reduce_7_output, AI_STATIC,
  253, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_7_output_array, NULL)

/* Tensor #254 */
AI_TENSOR_OBJ_DECLARE(
  reduce_81_Mul_output, AI_STATIC,
  254, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_81_Mul_output_array, NULL)

/* Tensor #255 */
AI_TENSOR_OBJ_DECLARE(
  reduce_81_output, AI_STATIC,
  255, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_81_output_array, NULL)

/* Tensor #256 */
AI_TENSOR_OBJ_DECLARE(
  reduce_96_Mul_output, AI_STATIC,
  256, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_96_Mul_output_array, NULL)

/* Tensor #257 */
AI_TENSOR_OBJ_DECLARE(
  reduce_96_output, AI_STATIC,
  257, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_96_output_array, NULL)

/* Tensor #258 */
AI_TENSOR_OBJ_DECLARE(
  reduce_99_Mul_output, AI_STATIC,
  258, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_99_Mul_output_array, NULL)

/* Tensor #259 */
AI_TENSOR_OBJ_DECLARE(
  reduce_99_output, AI_STATIC,
  259, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &reduce_99_output_array, NULL)

/* Tensor #260 */
AI_TENSOR_OBJ_DECLARE(
  serving_default_sequence_input0_output, AI_STATIC,
  260, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 120), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &serving_default_sequence_input0_output_array, NULL)

/* Tensor #261 */
AI_TENSOR_OBJ_DECLARE(
  serving_default_sequence_input0_output0, AI_STATIC,
  261, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 120, 1), AI_STRIDE_INIT(4, 4, 4, 4, 480),
  1, &serving_default_sequence_input0_output_array, NULL)

/* Tensor #262 */
AI_TENSOR_OBJ_DECLARE(
  slice_219_gather_0_output, AI_STATIC,
  262, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &slice_219_gather_0_output_array, NULL)

/* Tensor #263 */
AI_TENSOR_OBJ_DECLARE(
  slice_219_gather_0_placeholder, AI_STATIC,
  263, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &slice_219_gather_0_placeholder_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  gemm_222_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_221_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_222_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &gemm_222_weights, &gemm_222_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  gemm_222_layer, 222,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &gemm_222_chain,
  NULL, &gemm_222_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_221_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_221_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_221_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_221_nl_layer, 221,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &nl_221_nl_chain,
  NULL, &gemm_222_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  gemm_221_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_220_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_221_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &gemm_221_weights, &gemm_221_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  gemm_221_layer, 221,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &gemm_221_chain,
  NULL, &nl_221_nl_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_220_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_220_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_220_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_220_nl_layer, 220,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &nl_220_nl_chain,
  NULL, &gemm_221_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  gemm_220_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_219_gather_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &gemm_220_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &gemm_220_weights, &gemm_220_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  gemm_220_layer, 220,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &gemm_220_chain,
  NULL, &nl_220_nl_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  slice_219_gather_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_218_nl_output, &slice_219_gather_0_placeholder),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &slice_219_gather_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  slice_219_gather_0_layer, 219,
  GATHER_TYPE, 0x0, NULL,
  gather, forward_gather,
  &slice_219_gather_0_chain,
  NULL, &gemm_220_layer, AI_STATIC, 
  .axis = AI_SHAPE_HEIGHT, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_218_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_218_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_218_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_218_nl_layer, 218,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &nl_218_nl_chain,
  NULL, &slice_219_gather_0_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_218_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_181_nl_output, &eltwise_217_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_218_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_218_layer, 218,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_218_chain,
  NULL, &nl_218_nl_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_217_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_216_output, &eltwise_215_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_217_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_217_layer, 217,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_217_chain,
  NULL, &eltwise_218_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_215_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_214_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_215_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_12_scale, &eltwise_215_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_215_layer, 215,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &eltwise_215_chain,
  NULL, &eltwise_217_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_214_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_208_output, &eltwise_213_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_214_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_214_layer, 214,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_214_chain,
  NULL, &eltwise_215_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_208_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_207_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_208_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_208_layer, 208,
  NL_TYPE, 0x0, NULL,
  nl, forward_neg,
  &nl_208_chain,
  NULL, &eltwise_214_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_216_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_203_output, &eltwise_213_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_216_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_216_layer, 216,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_216_chain,
  NULL, &nl_208_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_213_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_212_output, &functional_1_layer_normalization_11_1_Reshape),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_213_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_213_layer, 213,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_213_chain,
  NULL, &eltwise_216_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_212_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_210_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_212_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_212_layer, 212,
  NL_TYPE, 0x0, NULL,
  nl, forward_rsqrt,
  &nl_212_chain,
  NULL, &eltwise_213_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_210_Mul_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_210_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_210_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &reduce_4_Mul_scale, &reduce_7_Mul_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_210_Mul_layer, 211,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &reduce_210_Mul_chain,
  NULL, &nl_212_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_float reduce_210_neutral_value_data[] = { 0.0f };
AI_ARRAY_OBJ_DECLARE(
    reduce_210_neutral_value, AI_ARRAY_FORMAT_FLOAT,
    reduce_210_neutral_value_data, reduce_210_neutral_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_210_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_209_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_210_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_210_layer, 211,
  REDUCE_TYPE, 0x0, NULL,
  reduce, forward_reduce,
  &reduce_210_chain,
  NULL, &reduce_210_Mul_layer, AI_STATIC, 
  .operation = ai_sum, 
  .neutral_value = &reduce_210_neutral_value, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_209_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_203_output, &reduce_207_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_209_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_209_layer, 209,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_209_chain,
  NULL, &reduce_210_layer, AI_STATIC, 
  .operation = ai_squared_diff, 
  .buffer_operation = ai_squared_diff_buffer, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_207_Mul_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_207_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_207_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &reduce_4_Mul_scale, &reduce_4_Mul_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_207_Mul_layer, 207,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &reduce_207_Mul_chain,
  NULL, &eltwise_209_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_float reduce_207_neutral_value_data[] = { 0.0f };
AI_ARRAY_OBJ_DECLARE(
    reduce_207_neutral_value, AI_ARRAY_FORMAT_FLOAT,
    reduce_207_neutral_value_data, reduce_207_neutral_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_207_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_203_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_207_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_207_layer, 207,
  REDUCE_TYPE, 0x0, NULL,
  reduce, forward_reduce,
  &reduce_207_chain,
  NULL, &reduce_207_Mul_layer, AI_STATIC, 
  .operation = ai_sum, 
  .neutral_value = &reduce_207_neutral_value, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_203_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_200_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_203_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_203_weights, &conv2d_203_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_203_layer, 206,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32_group,
  &conv2d_203_chain,
  NULL, &reduce_207_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 32), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float pad_200_value_data[] = { 0.0 };
AI_ARRAY_OBJ_DECLARE(
    pad_200_value, AI_ARRAY_FORMAT_FLOAT,
    pad_200_value_data, pad_200_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  pad_200_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_199_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_200_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pad_200_layer, 200,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &pad_200_chain,
  NULL, &conv2d_203_layer, AI_STATIC, 
  .value = &pad_200_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 64, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_199_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_199_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_199_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_199_nl_layer, 199,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &nl_199_nl_chain,
  NULL, &pad_200_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_199_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_198_output, &eltwise_197_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_199_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_199_layer, 199,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_199_chain,
  NULL, &nl_199_nl_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_197_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_196_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_197_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_12_scale, &eltwise_197_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_197_layer, 197,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &eltwise_197_chain,
  NULL, &eltwise_199_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_196_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_190_output, &eltwise_195_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_196_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_196_layer, 196,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_196_chain,
  NULL, &eltwise_197_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_190_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_189_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_190_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_190_layer, 190,
  NL_TYPE, 0x0, NULL,
  nl, forward_neg,
  &nl_190_chain,
  NULL, &eltwise_196_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_198_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_185_output, &eltwise_195_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_198_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_198_layer, 198,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_198_chain,
  NULL, &nl_190_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_195_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_194_output, &functional_1_layer_normalization_10_1_Reshape),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_195_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_195_layer, 195,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_195_chain,
  NULL, &eltwise_198_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_194_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_192_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_194_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_194_layer, 194,
  NL_TYPE, 0x0, NULL,
  nl, forward_rsqrt,
  &nl_194_chain,
  NULL, &eltwise_195_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_192_Mul_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_192_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_192_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &reduce_4_Mul_scale, &reduce_7_Mul_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_192_Mul_layer, 193,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &reduce_192_Mul_chain,
  NULL, &nl_194_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_float reduce_192_neutral_value_data[] = { 0.0f };
AI_ARRAY_OBJ_DECLARE(
    reduce_192_neutral_value, AI_ARRAY_FORMAT_FLOAT,
    reduce_192_neutral_value_data, reduce_192_neutral_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_192_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_191_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_192_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_192_layer, 193,
  REDUCE_TYPE, 0x0, NULL,
  reduce, forward_reduce,
  &reduce_192_chain,
  NULL, &reduce_192_Mul_layer, AI_STATIC, 
  .operation = ai_sum, 
  .neutral_value = &reduce_192_neutral_value, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_191_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_185_output, &reduce_189_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_191_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_191_layer, 191,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_191_chain,
  NULL, &reduce_192_layer, AI_STATIC, 
  .operation = ai_squared_diff, 
  .buffer_operation = ai_squared_diff_buffer, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_189_Mul_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_189_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_189_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &reduce_4_Mul_scale, &reduce_4_Mul_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_189_Mul_layer, 189,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &reduce_189_Mul_chain,
  NULL, &eltwise_191_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_float reduce_189_neutral_value_data[] = { 0.0f };
AI_ARRAY_OBJ_DECLARE(
    reduce_189_neutral_value, AI_ARRAY_FORMAT_FLOAT,
    reduce_189_neutral_value_data, reduce_189_neutral_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_189_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_185_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_189_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_189_layer, 189,
  REDUCE_TYPE, 0x0, NULL,
  reduce, forward_reduce,
  &reduce_189_chain,
  NULL, &reduce_189_Mul_layer, AI_STATIC, 
  .operation = ai_sum, 
  .neutral_value = &reduce_189_neutral_value, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_185_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_182_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_185_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_185_weights, &conv2d_185_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_185_layer, 188,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32_group,
  &conv2d_185_chain,
  NULL, &reduce_189_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 32), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float pad_182_value_data[] = { 0.0 };
AI_ARRAY_OBJ_DECLARE(
    pad_182_value, AI_ARRAY_FORMAT_FLOAT,
    pad_182_value_data, pad_182_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  pad_182_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_181_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_182_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pad_182_layer, 182,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &pad_182_chain,
  NULL, &conv2d_185_layer, AI_STATIC, 
  .value = &pad_182_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 64, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_181_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_181_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_181_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_181_nl_layer, 181,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &nl_181_nl_chain,
  NULL, &pad_182_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_181_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_144_nl_output, &eltwise_180_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_181_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_181_layer, 181,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_181_chain,
  NULL, &nl_181_nl_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_180_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_179_output, &eltwise_178_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_180_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_180_layer, 180,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_180_chain,
  NULL, &eltwise_181_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_178_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_177_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_178_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_12_scale, &eltwise_178_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_178_layer, 178,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &eltwise_178_chain,
  NULL, &eltwise_180_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_177_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_171_output, &eltwise_176_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_177_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_177_layer, 177,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_177_chain,
  NULL, &eltwise_178_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_171_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_170_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_171_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_171_layer, 171,
  NL_TYPE, 0x0, NULL,
  nl, forward_neg,
  &nl_171_chain,
  NULL, &eltwise_177_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_179_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_166_output, &eltwise_176_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_179_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_179_layer, 179,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_179_chain,
  NULL, &nl_171_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_176_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_175_output, &functional_1_layer_normalization_9_1_Reshape),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_176_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_176_layer, 176,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_176_chain,
  NULL, &eltwise_179_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_175_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_173_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_175_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_175_layer, 175,
  NL_TYPE, 0x0, NULL,
  nl, forward_rsqrt,
  &nl_175_chain,
  NULL, &eltwise_176_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_173_Mul_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_173_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_173_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &reduce_4_Mul_scale, &reduce_7_Mul_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_173_Mul_layer, 174,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &reduce_173_Mul_chain,
  NULL, &nl_175_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_float reduce_173_neutral_value_data[] = { 0.0f };
AI_ARRAY_OBJ_DECLARE(
    reduce_173_neutral_value, AI_ARRAY_FORMAT_FLOAT,
    reduce_173_neutral_value_data, reduce_173_neutral_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_173_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_172_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_173_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_173_layer, 174,
  REDUCE_TYPE, 0x0, NULL,
  reduce, forward_reduce,
  &reduce_173_chain,
  NULL, &reduce_173_Mul_layer, AI_STATIC, 
  .operation = ai_sum, 
  .neutral_value = &reduce_173_neutral_value, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_172_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_166_output, &reduce_170_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_172_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_172_layer, 172,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_172_chain,
  NULL, &reduce_173_layer, AI_STATIC, 
  .operation = ai_squared_diff, 
  .buffer_operation = ai_squared_diff_buffer, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_170_Mul_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_170_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_170_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &reduce_4_Mul_scale, &reduce_4_Mul_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_170_Mul_layer, 170,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &reduce_170_Mul_chain,
  NULL, &eltwise_172_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_float reduce_170_neutral_value_data[] = { 0.0f };
AI_ARRAY_OBJ_DECLARE(
    reduce_170_neutral_value, AI_ARRAY_FORMAT_FLOAT,
    reduce_170_neutral_value_data, reduce_170_neutral_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_170_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_166_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_170_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_170_layer, 170,
  REDUCE_TYPE, 0x0, NULL,
  reduce, forward_reduce,
  &reduce_170_chain,
  NULL, &reduce_170_Mul_layer, AI_STATIC, 
  .operation = ai_sum, 
  .neutral_value = &reduce_170_neutral_value, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_166_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_163_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_166_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_166_weights, &conv2d_166_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_166_layer, 169,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32_group,
  &conv2d_166_chain,
  NULL, &reduce_170_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 16), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float pad_163_value_data[] = { 0.0 };
AI_ARRAY_OBJ_DECLARE(
    pad_163_value, AI_ARRAY_FORMAT_FLOAT,
    pad_163_value_data, pad_163_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  pad_163_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_162_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_163_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pad_163_layer, 163,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &pad_163_chain,
  NULL, &conv2d_166_layer, AI_STATIC, 
  .value = &pad_163_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 32, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_162_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_162_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_162_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_162_nl_layer, 162,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &nl_162_nl_chain,
  NULL, &pad_163_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_162_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_161_output, &eltwise_160_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_162_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_162_layer, 162,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_162_chain,
  NULL, &nl_162_nl_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_160_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_159_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_160_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_12_scale, &eltwise_160_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_160_layer, 160,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &eltwise_160_chain,
  NULL, &eltwise_162_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_159_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_153_output, &eltwise_158_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_159_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_159_layer, 159,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_159_chain,
  NULL, &eltwise_160_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_153_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_152_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_153_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_153_layer, 153,
  NL_TYPE, 0x0, NULL,
  nl, forward_neg,
  &nl_153_chain,
  NULL, &eltwise_159_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_161_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_148_output, &eltwise_158_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_161_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_161_layer, 161,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_161_chain,
  NULL, &nl_153_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_158_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_157_output, &functional_1_layer_normalization_8_1_Reshape),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_158_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_158_layer, 158,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_158_chain,
  NULL, &eltwise_161_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_157_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_155_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_157_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_157_layer, 157,
  NL_TYPE, 0x0, NULL,
  nl, forward_rsqrt,
  &nl_157_chain,
  NULL, &eltwise_158_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_155_Mul_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_155_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_155_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &reduce_4_Mul_scale, &reduce_7_Mul_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_155_Mul_layer, 156,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &reduce_155_Mul_chain,
  NULL, &nl_157_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_float reduce_155_neutral_value_data[] = { 0.0f };
AI_ARRAY_OBJ_DECLARE(
    reduce_155_neutral_value, AI_ARRAY_FORMAT_FLOAT,
    reduce_155_neutral_value_data, reduce_155_neutral_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_155_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_154_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_155_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_155_layer, 156,
  REDUCE_TYPE, 0x0, NULL,
  reduce, forward_reduce,
  &reduce_155_chain,
  NULL, &reduce_155_Mul_layer, AI_STATIC, 
  .operation = ai_sum, 
  .neutral_value = &reduce_155_neutral_value, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_154_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_148_output, &reduce_152_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_154_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_154_layer, 154,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_154_chain,
  NULL, &reduce_155_layer, AI_STATIC, 
  .operation = ai_squared_diff, 
  .buffer_operation = ai_squared_diff_buffer, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_152_Mul_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_152_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_152_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &reduce_4_Mul_scale, &reduce_4_Mul_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_152_Mul_layer, 152,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &reduce_152_Mul_chain,
  NULL, &eltwise_154_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_float reduce_152_neutral_value_data[] = { 0.0f };
AI_ARRAY_OBJ_DECLARE(
    reduce_152_neutral_value, AI_ARRAY_FORMAT_FLOAT,
    reduce_152_neutral_value_data, reduce_152_neutral_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_152_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_148_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_152_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_152_layer, 152,
  REDUCE_TYPE, 0x0, NULL,
  reduce, forward_reduce,
  &reduce_152_chain,
  NULL, &reduce_152_Mul_layer, AI_STATIC, 
  .operation = ai_sum, 
  .neutral_value = &reduce_152_neutral_value, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_148_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_145_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_148_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_148_weights, &conv2d_148_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_148_layer, 151,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32_group,
  &conv2d_148_chain,
  NULL, &reduce_152_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 16), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float pad_145_value_data[] = { 0.0 };
AI_ARRAY_OBJ_DECLARE(
    pad_145_value, AI_ARRAY_FORMAT_FLOAT,
    pad_145_value_data, pad_145_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  pad_145_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_144_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_145_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pad_145_layer, 145,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &pad_145_chain,
  NULL, &conv2d_148_layer, AI_STATIC, 
  .value = &pad_145_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 32, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_144_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_144_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_144_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_144_nl_layer, 144,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &nl_144_nl_chain,
  NULL, &pad_145_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_144_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_107_nl_output, &eltwise_143_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_144_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_144_layer, 144,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_144_chain,
  NULL, &nl_144_nl_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_143_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_142_output, &eltwise_141_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_143_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_143_layer, 143,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_143_chain,
  NULL, &eltwise_144_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_141_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_140_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_141_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_12_scale, &eltwise_141_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_141_layer, 141,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &eltwise_141_chain,
  NULL, &eltwise_143_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_140_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_134_output, &eltwise_139_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_140_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_140_layer, 140,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_140_chain,
  NULL, &eltwise_141_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_134_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_133_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_134_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_134_layer, 134,
  NL_TYPE, 0x0, NULL,
  nl, forward_neg,
  &nl_134_chain,
  NULL, &eltwise_140_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_142_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_129_output, &eltwise_139_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_142_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_142_layer, 142,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_142_chain,
  NULL, &nl_134_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_139_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_138_output, &functional_1_layer_normalization_7_1_Reshape),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_139_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_139_layer, 139,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_139_chain,
  NULL, &eltwise_142_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_138_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_136_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_138_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_138_layer, 138,
  NL_TYPE, 0x0, NULL,
  nl, forward_rsqrt,
  &nl_138_chain,
  NULL, &eltwise_139_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_136_Mul_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_136_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_136_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &reduce_4_Mul_scale, &reduce_7_Mul_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_136_Mul_layer, 137,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &reduce_136_Mul_chain,
  NULL, &nl_138_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_float reduce_136_neutral_value_data[] = { 0.0f };
AI_ARRAY_OBJ_DECLARE(
    reduce_136_neutral_value, AI_ARRAY_FORMAT_FLOAT,
    reduce_136_neutral_value_data, reduce_136_neutral_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_136_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_135_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_136_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_136_layer, 137,
  REDUCE_TYPE, 0x0, NULL,
  reduce, forward_reduce,
  &reduce_136_chain,
  NULL, &reduce_136_Mul_layer, AI_STATIC, 
  .operation = ai_sum, 
  .neutral_value = &reduce_136_neutral_value, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_135_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_129_output, &reduce_133_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_135_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_135_layer, 135,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_135_chain,
  NULL, &reduce_136_layer, AI_STATIC, 
  .operation = ai_squared_diff, 
  .buffer_operation = ai_squared_diff_buffer, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_133_Mul_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_133_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_133_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &reduce_4_Mul_scale, &reduce_4_Mul_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_133_Mul_layer, 133,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &reduce_133_Mul_chain,
  NULL, &eltwise_135_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_float reduce_133_neutral_value_data[] = { 0.0f };
AI_ARRAY_OBJ_DECLARE(
    reduce_133_neutral_value, AI_ARRAY_FORMAT_FLOAT,
    reduce_133_neutral_value_data, reduce_133_neutral_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_133_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_129_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_133_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_133_layer, 133,
  REDUCE_TYPE, 0x0, NULL,
  reduce, forward_reduce,
  &reduce_133_chain,
  NULL, &reduce_133_Mul_layer, AI_STATIC, 
  .operation = ai_sum, 
  .neutral_value = &reduce_133_neutral_value, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_129_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_126_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_129_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_129_weights, &conv2d_129_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_129_layer, 132,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32_group,
  &conv2d_129_chain,
  NULL, &reduce_133_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 8), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float pad_126_value_data[] = { 0.0 };
AI_ARRAY_OBJ_DECLARE(
    pad_126_value, AI_ARRAY_FORMAT_FLOAT,
    pad_126_value_data, pad_126_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  pad_126_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_125_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_126_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pad_126_layer, 126,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &pad_126_chain,
  NULL, &conv2d_129_layer, AI_STATIC, 
  .value = &pad_126_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 16, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_125_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_125_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_125_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_125_nl_layer, 125,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &nl_125_nl_chain,
  NULL, &pad_126_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_125_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_124_output, &eltwise_123_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_125_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_125_layer, 125,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_125_chain,
  NULL, &nl_125_nl_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_123_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_122_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_123_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_12_scale, &eltwise_123_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_123_layer, 123,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &eltwise_123_chain,
  NULL, &eltwise_125_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_122_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_116_output, &eltwise_121_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_122_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_122_layer, 122,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_122_chain,
  NULL, &eltwise_123_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_116_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_115_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_116_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_116_layer, 116,
  NL_TYPE, 0x0, NULL,
  nl, forward_neg,
  &nl_116_chain,
  NULL, &eltwise_122_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_124_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_111_output, &eltwise_121_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_124_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_124_layer, 124,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_124_chain,
  NULL, &nl_116_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_121_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_120_output, &functional_1_layer_normalization_6_1_Reshape),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_121_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_121_layer, 121,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_121_chain,
  NULL, &eltwise_124_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_120_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_118_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_120_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_120_layer, 120,
  NL_TYPE, 0x0, NULL,
  nl, forward_rsqrt,
  &nl_120_chain,
  NULL, &eltwise_121_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_118_Mul_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_118_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_118_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &reduce_4_Mul_scale, &reduce_7_Mul_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_118_Mul_layer, 119,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &reduce_118_Mul_chain,
  NULL, &nl_120_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_float reduce_118_neutral_value_data[] = { 0.0f };
AI_ARRAY_OBJ_DECLARE(
    reduce_118_neutral_value, AI_ARRAY_FORMAT_FLOAT,
    reduce_118_neutral_value_data, reduce_118_neutral_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_118_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_117_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_118_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_118_layer, 119,
  REDUCE_TYPE, 0x0, NULL,
  reduce, forward_reduce,
  &reduce_118_chain,
  NULL, &reduce_118_Mul_layer, AI_STATIC, 
  .operation = ai_sum, 
  .neutral_value = &reduce_118_neutral_value, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_117_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_111_output, &reduce_115_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_117_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_117_layer, 117,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_117_chain,
  NULL, &reduce_118_layer, AI_STATIC, 
  .operation = ai_squared_diff, 
  .buffer_operation = ai_squared_diff_buffer, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_115_Mul_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_115_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_115_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &reduce_4_Mul_scale, &reduce_4_Mul_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_115_Mul_layer, 115,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &reduce_115_Mul_chain,
  NULL, &eltwise_117_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_float reduce_115_neutral_value_data[] = { 0.0f };
AI_ARRAY_OBJ_DECLARE(
    reduce_115_neutral_value, AI_ARRAY_FORMAT_FLOAT,
    reduce_115_neutral_value_data, reduce_115_neutral_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_115_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_111_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_115_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_115_layer, 115,
  REDUCE_TYPE, 0x0, NULL,
  reduce, forward_reduce,
  &reduce_115_chain,
  NULL, &reduce_115_Mul_layer, AI_STATIC, 
  .operation = ai_sum, 
  .neutral_value = &reduce_115_neutral_value, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_111_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_108_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_111_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_111_weights, &conv2d_111_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_111_layer, 114,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32_group,
  &conv2d_111_chain,
  NULL, &reduce_115_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 8), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float pad_108_value_data[] = { 0.0 };
AI_ARRAY_OBJ_DECLARE(
    pad_108_value, AI_ARRAY_FORMAT_FLOAT,
    pad_108_value_data, pad_108_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  pad_108_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_107_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_108_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pad_108_layer, 108,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &pad_108_chain,
  NULL, &conv2d_111_layer, AI_STATIC, 
  .value = &pad_108_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 16, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_107_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_107_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_107_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_107_nl_layer, 107,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &nl_107_nl_chain,
  NULL, &pad_108_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_107_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_70_nl_output, &eltwise_106_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_107_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_107_layer, 107,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_107_chain,
  NULL, &nl_107_nl_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_106_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_105_output, &eltwise_104_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_106_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_106_layer, 106,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_106_chain,
  NULL, &eltwise_107_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_104_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_103_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_104_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_12_scale, &eltwise_104_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_104_layer, 104,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &eltwise_104_chain,
  NULL, &eltwise_106_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_103_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_97_output, &eltwise_102_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_103_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_103_layer, 103,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_103_chain,
  NULL, &eltwise_104_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_97_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_96_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_97_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_97_layer, 97,
  NL_TYPE, 0x0, NULL,
  nl, forward_neg,
  &nl_97_chain,
  NULL, &eltwise_103_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_105_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_92_output, &eltwise_102_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_105_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_105_layer, 105,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_105_chain,
  NULL, &nl_97_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_102_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_101_output, &functional_1_layer_normalization_5_1_Reshape),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_102_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_102_layer, 102,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_102_chain,
  NULL, &eltwise_105_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_101_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_99_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_101_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_101_layer, 101,
  NL_TYPE, 0x0, NULL,
  nl, forward_rsqrt,
  &nl_101_chain,
  NULL, &eltwise_102_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_99_Mul_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_99_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_99_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &reduce_4_Mul_scale, &reduce_7_Mul_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_99_Mul_layer, 100,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &reduce_99_Mul_chain,
  NULL, &nl_101_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_float reduce_99_neutral_value_data[] = { 0.0f };
AI_ARRAY_OBJ_DECLARE(
    reduce_99_neutral_value, AI_ARRAY_FORMAT_FLOAT,
    reduce_99_neutral_value_data, reduce_99_neutral_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_99_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_98_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_99_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_99_layer, 100,
  REDUCE_TYPE, 0x0, NULL,
  reduce, forward_reduce,
  &reduce_99_chain,
  NULL, &reduce_99_Mul_layer, AI_STATIC, 
  .operation = ai_sum, 
  .neutral_value = &reduce_99_neutral_value, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_98_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_92_output, &reduce_96_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_98_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_98_layer, 98,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_98_chain,
  NULL, &reduce_99_layer, AI_STATIC, 
  .operation = ai_squared_diff, 
  .buffer_operation = ai_squared_diff_buffer, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_96_Mul_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_96_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_96_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &reduce_4_Mul_scale, &reduce_4_Mul_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_96_Mul_layer, 96,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &reduce_96_Mul_chain,
  NULL, &eltwise_98_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_float reduce_96_neutral_value_data[] = { 0.0f };
AI_ARRAY_OBJ_DECLARE(
    reduce_96_neutral_value, AI_ARRAY_FORMAT_FLOAT,
    reduce_96_neutral_value_data, reduce_96_neutral_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_96_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_92_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_96_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_96_layer, 96,
  REDUCE_TYPE, 0x0, NULL,
  reduce, forward_reduce,
  &reduce_96_chain,
  NULL, &reduce_96_Mul_layer, AI_STATIC, 
  .operation = ai_sum, 
  .neutral_value = &reduce_96_neutral_value, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_92_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_89_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_92_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_92_weights, &conv2d_92_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_92_layer, 95,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32_group,
  &conv2d_92_chain,
  NULL, &reduce_96_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 4), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float pad_89_value_data[] = { 0.0 };
AI_ARRAY_OBJ_DECLARE(
    pad_89_value, AI_ARRAY_FORMAT_FLOAT,
    pad_89_value_data, pad_89_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  pad_89_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_88_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_89_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pad_89_layer, 89,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &pad_89_chain,
  NULL, &conv2d_92_layer, AI_STATIC, 
  .value = &pad_89_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 8, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_88_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_88_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_88_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_88_nl_layer, 88,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &nl_88_nl_chain,
  NULL, &pad_89_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_88_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_87_output, &eltwise_86_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_88_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_88_layer, 88,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_88_chain,
  NULL, &nl_88_nl_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_86_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_85_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_86_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_12_scale, &eltwise_86_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_86_layer, 86,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &eltwise_86_chain,
  NULL, &eltwise_88_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_85_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_79_output, &eltwise_84_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_85_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_85_layer, 85,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_85_chain,
  NULL, &eltwise_86_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_79_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_78_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_79_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_79_layer, 79,
  NL_TYPE, 0x0, NULL,
  nl, forward_neg,
  &nl_79_chain,
  NULL, &eltwise_85_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_87_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_74_output, &eltwise_84_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_87_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_87_layer, 87,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_87_chain,
  NULL, &nl_79_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_84_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_83_output, &functional_1_layer_normalization_4_1_Reshape),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_84_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_84_layer, 84,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_84_chain,
  NULL, &eltwise_87_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_83_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_81_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_83_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_83_layer, 83,
  NL_TYPE, 0x0, NULL,
  nl, forward_rsqrt,
  &nl_83_chain,
  NULL, &eltwise_84_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_81_Mul_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_81_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_81_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &reduce_4_Mul_scale, &reduce_7_Mul_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_81_Mul_layer, 82,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &reduce_81_Mul_chain,
  NULL, &nl_83_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_float reduce_81_neutral_value_data[] = { 0.0f };
AI_ARRAY_OBJ_DECLARE(
    reduce_81_neutral_value, AI_ARRAY_FORMAT_FLOAT,
    reduce_81_neutral_value_data, reduce_81_neutral_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_81_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_80_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_81_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_81_layer, 82,
  REDUCE_TYPE, 0x0, NULL,
  reduce, forward_reduce,
  &reduce_81_chain,
  NULL, &reduce_81_Mul_layer, AI_STATIC, 
  .operation = ai_sum, 
  .neutral_value = &reduce_81_neutral_value, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_80_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_74_output, &reduce_78_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_80_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_80_layer, 80,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_80_chain,
  NULL, &reduce_81_layer, AI_STATIC, 
  .operation = ai_squared_diff, 
  .buffer_operation = ai_squared_diff_buffer, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_78_Mul_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_78_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_78_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &reduce_4_Mul_scale, &reduce_4_Mul_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_78_Mul_layer, 78,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &reduce_78_Mul_chain,
  NULL, &eltwise_80_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_float reduce_78_neutral_value_data[] = { 0.0f };
AI_ARRAY_OBJ_DECLARE(
    reduce_78_neutral_value, AI_ARRAY_FORMAT_FLOAT,
    reduce_78_neutral_value_data, reduce_78_neutral_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_78_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_74_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_78_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_78_layer, 78,
  REDUCE_TYPE, 0x0, NULL,
  reduce, forward_reduce,
  &reduce_78_chain,
  NULL, &reduce_78_Mul_layer, AI_STATIC, 
  .operation = ai_sum, 
  .neutral_value = &reduce_78_neutral_value, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_74_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_71_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_74_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_74_weights, &conv2d_74_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_74_layer, 77,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32_group,
  &conv2d_74_chain,
  NULL, &reduce_78_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 4), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float pad_71_value_data[] = { 0.0 };
AI_ARRAY_OBJ_DECLARE(
    pad_71_value, AI_ARRAY_FORMAT_FLOAT,
    pad_71_value_data, pad_71_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  pad_71_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_70_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_71_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pad_71_layer, 71,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &pad_71_chain,
  NULL, &conv2d_74_layer, AI_STATIC, 
  .value = &pad_71_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 8, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_70_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_70_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_70_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_70_nl_layer, 70,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &nl_70_nl_chain,
  NULL, &pad_71_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_70_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_33_nl_output, &eltwise_69_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_70_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_70_layer, 70,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_70_chain,
  NULL, &nl_70_nl_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_69_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_68_output, &eltwise_67_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_69_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_69_layer, 69,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_69_chain,
  NULL, &eltwise_70_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_67_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_66_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_67_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_12_scale, &eltwise_67_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_67_layer, 67,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &eltwise_67_chain,
  NULL, &eltwise_69_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_66_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_60_output, &eltwise_65_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_66_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_66_layer, 66,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_66_chain,
  NULL, &eltwise_67_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_60_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_59_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_60_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_60_layer, 60,
  NL_TYPE, 0x0, NULL,
  nl, forward_neg,
  &nl_60_chain,
  NULL, &eltwise_66_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_68_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_55_output, &eltwise_65_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_68_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_68_layer, 68,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_68_chain,
  NULL, &nl_60_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_65_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_64_output, &functional_1_layer_normalization_3_1_Reshape),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_65_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_65_layer, 65,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_65_chain,
  NULL, &eltwise_68_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_64_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_62_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_64_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_64_layer, 64,
  NL_TYPE, 0x0, NULL,
  nl, forward_rsqrt,
  &nl_64_chain,
  NULL, &eltwise_65_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_62_Mul_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_62_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_62_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &reduce_4_Mul_scale, &reduce_7_Mul_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_62_Mul_layer, 63,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &reduce_62_Mul_chain,
  NULL, &nl_64_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_float reduce_62_neutral_value_data[] = { 0.0f };
AI_ARRAY_OBJ_DECLARE(
    reduce_62_neutral_value, AI_ARRAY_FORMAT_FLOAT,
    reduce_62_neutral_value_data, reduce_62_neutral_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_62_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_61_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_62_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_62_layer, 63,
  REDUCE_TYPE, 0x0, NULL,
  reduce, forward_reduce,
  &reduce_62_chain,
  NULL, &reduce_62_Mul_layer, AI_STATIC, 
  .operation = ai_sum, 
  .neutral_value = &reduce_62_neutral_value, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_61_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_55_output, &reduce_59_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_61_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_61_layer, 61,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_61_chain,
  NULL, &reduce_62_layer, AI_STATIC, 
  .operation = ai_squared_diff, 
  .buffer_operation = ai_squared_diff_buffer, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_59_Mul_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_59_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_59_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &reduce_4_Mul_scale, &reduce_4_Mul_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_59_Mul_layer, 59,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &reduce_59_Mul_chain,
  NULL, &eltwise_61_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_float reduce_59_neutral_value_data[] = { 0.0f };
AI_ARRAY_OBJ_DECLARE(
    reduce_59_neutral_value, AI_ARRAY_FORMAT_FLOAT,
    reduce_59_neutral_value_data, reduce_59_neutral_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_59_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_55_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_59_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_59_layer, 59,
  REDUCE_TYPE, 0x0, NULL,
  reduce, forward_reduce,
  &reduce_59_chain,
  NULL, &reduce_59_Mul_layer, AI_STATIC, 
  .operation = ai_sum, 
  .neutral_value = &reduce_59_neutral_value, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_55_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_52_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_55_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_55_weights, &conv2d_55_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_55_layer, 58,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32_group,
  &conv2d_55_chain,
  NULL, &reduce_59_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 2), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float pad_52_value_data[] = { 0.0 };
AI_ARRAY_OBJ_DECLARE(
    pad_52_value, AI_ARRAY_FORMAT_FLOAT,
    pad_52_value_data, pad_52_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  pad_52_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_51_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_52_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pad_52_layer, 52,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &pad_52_chain,
  NULL, &conv2d_55_layer, AI_STATIC, 
  .value = &pad_52_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 4, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_51_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_51_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_51_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_51_nl_layer, 51,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &nl_51_nl_chain,
  NULL, &pad_52_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_51_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_50_output, &eltwise_49_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_51_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_51_layer, 51,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_51_chain,
  NULL, &nl_51_nl_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_49_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_48_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_49_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_12_scale, &eltwise_49_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_49_layer, 49,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &eltwise_49_chain,
  NULL, &eltwise_51_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_48_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_42_output, &eltwise_47_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_48_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_48_layer, 48,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_48_chain,
  NULL, &eltwise_49_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_42_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_41_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_42_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_42_layer, 42,
  NL_TYPE, 0x0, NULL,
  nl, forward_neg,
  &nl_42_chain,
  NULL, &eltwise_48_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_50_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_37_output, &eltwise_47_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_50_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_50_layer, 50,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_50_chain,
  NULL, &nl_42_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_47_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_46_output, &functional_1_layer_normalization_2_1_Reshape),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_47_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_47_layer, 47,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_47_chain,
  NULL, &eltwise_50_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_46_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_44_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_46_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_46_layer, 46,
  NL_TYPE, 0x0, NULL,
  nl, forward_rsqrt,
  &nl_46_chain,
  NULL, &eltwise_47_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_44_Mul_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_44_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_44_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &reduce_4_Mul_scale, &reduce_7_Mul_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_44_Mul_layer, 45,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &reduce_44_Mul_chain,
  NULL, &nl_46_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_float reduce_44_neutral_value_data[] = { 0.0f };
AI_ARRAY_OBJ_DECLARE(
    reduce_44_neutral_value, AI_ARRAY_FORMAT_FLOAT,
    reduce_44_neutral_value_data, reduce_44_neutral_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_44_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_43_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_44_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_44_layer, 45,
  REDUCE_TYPE, 0x0, NULL,
  reduce, forward_reduce,
  &reduce_44_chain,
  NULL, &reduce_44_Mul_layer, AI_STATIC, 
  .operation = ai_sum, 
  .neutral_value = &reduce_44_neutral_value, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_43_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_37_output, &reduce_41_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_43_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_43_layer, 43,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_43_chain,
  NULL, &reduce_44_layer, AI_STATIC, 
  .operation = ai_squared_diff, 
  .buffer_operation = ai_squared_diff_buffer, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_41_Mul_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_41_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_41_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &reduce_4_Mul_scale, &reduce_4_Mul_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_41_Mul_layer, 41,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &reduce_41_Mul_chain,
  NULL, &eltwise_43_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_float reduce_41_neutral_value_data[] = { 0.0f };
AI_ARRAY_OBJ_DECLARE(
    reduce_41_neutral_value, AI_ARRAY_FORMAT_FLOAT,
    reduce_41_neutral_value_data, reduce_41_neutral_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_41_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_37_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_41_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_41_layer, 41,
  REDUCE_TYPE, 0x0, NULL,
  reduce, forward_reduce,
  &reduce_41_chain,
  NULL, &reduce_41_Mul_layer, AI_STATIC, 
  .operation = ai_sum, 
  .neutral_value = &reduce_41_neutral_value, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_37_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_34_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_37_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_37_weights, &conv2d_37_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv2d_37_layer, 40,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32_group,
  &conv2d_37_chain,
  NULL, &reduce_41_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 2), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float pad_34_value_data[] = { 0.0 };
AI_ARRAY_OBJ_DECLARE(
    pad_34_value, AI_ARRAY_FORMAT_FLOAT,
    pad_34_value_data, pad_34_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  pad_34_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_33_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_34_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pad_34_layer, 34,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &pad_34_chain,
  NULL, &conv2d_37_layer, AI_STATIC, 
  .value = &pad_34_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 4, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_33_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_33_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_33_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_33_nl_layer, 33,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &nl_33_nl_chain,
  NULL, &pad_34_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_33_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_31_output0, &eltwise_29_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_33_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_33_layer, 33,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_33_chain,
  NULL, &nl_33_nl_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_29_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_28_output, &eltwise_27_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_29_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_29_layer, 29,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_29_chain,
  NULL, &eltwise_33_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_27_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_26_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_27_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_12_scale, &eltwise_27_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_27_layer, 27,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &eltwise_27_chain,
  NULL, &eltwise_29_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_26_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_20_output, &eltwise_25_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_26_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_26_layer, 26,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_26_chain,
  NULL, &eltwise_27_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_20_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_19_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_20_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_20_layer, 20,
  NL_TYPE, 0x0, NULL,
  nl, forward_neg,
  &nl_20_chain,
  NULL, &eltwise_26_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_28_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_17_output0, &eltwise_25_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_28_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_28_layer, 28,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_28_chain,
  NULL, &nl_20_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_25_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_24_output, &functional_1_layer_normalization_1_2_Reshape),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_25_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_25_layer, 25,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_25_chain,
  NULL, &eltwise_28_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_24_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_22_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_24_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_24_layer, 24,
  NL_TYPE, 0x0, NULL,
  nl, forward_rsqrt,
  &nl_24_chain,
  NULL, &eltwise_25_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_22_Mul_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_22_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &reduce_4_Mul_scale, &reduce_7_Mul_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_22_Mul_layer, 23,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &reduce_22_Mul_chain,
  NULL, &nl_24_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_float reduce_22_neutral_value_data[] = { 0.0f };
AI_ARRAY_OBJ_DECLARE(
    reduce_22_neutral_value, AI_ARRAY_FORMAT_FLOAT,
    reduce_22_neutral_value_data, reduce_22_neutral_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_22_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_22_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_22_layer, 23,
  REDUCE_TYPE, 0x0, NULL,
  reduce, forward_reduce,
  &reduce_22_chain,
  NULL, &reduce_22_Mul_layer, AI_STATIC, 
  .operation = ai_sum, 
  .neutral_value = &reduce_22_neutral_value, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_21_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_17_output0, &reduce_19_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_21_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_21_layer, 21,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_21_chain,
  NULL, &reduce_22_layer, AI_STATIC, 
  .operation = ai_squared_diff, 
  .buffer_operation = ai_squared_diff_buffer, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_19_Mul_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_19_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &reduce_4_Mul_scale, &reduce_4_Mul_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_19_Mul_layer, 19,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &reduce_19_Mul_chain,
  NULL, &eltwise_21_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_float reduce_19_neutral_value_data[] = { 0.0f };
AI_ARRAY_OBJ_DECLARE(
    reduce_19_neutral_value, AI_ARRAY_FORMAT_FLOAT,
    reduce_19_neutral_value_data, reduce_19_neutral_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_19_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_19_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_19_layer, 19,
  REDUCE_TYPE, 0x0, NULL,
  reduce, forward_reduce,
  &reduce_19_chain,
  NULL, &reduce_19_Mul_layer, AI_STATIC, 
  .operation = ai_sum, 
  .neutral_value = &reduce_19_neutral_value, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_17_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_15_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_17_weights, &conv2d_17_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_17_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_17_layer, 17,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_17_chain,
  NULL, &reduce_19_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float pad_15_value_data[] = { 0.0 };
AI_ARRAY_OBJ_DECLARE(
    pad_15_value, AI_ARRAY_FORMAT_FLOAT,
    pad_15_value_data, pad_15_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  pad_15_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_14_nl_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_15_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pad_15_layer, 15,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &pad_15_chain,
  NULL, &conv2d_17_layer, AI_STATIC, 
  .value = &pad_15_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 2, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_14_nl_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_14_nl_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_14_nl_layer, 14,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &nl_14_nl_chain,
  NULL, &pad_15_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_14_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_13_output, &eltwise_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_14_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_14_layer, 14,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_14_chain,
  NULL, &nl_14_nl_layer, AI_STATIC, 
  .operation = ai_sum_f32, 
  .buffer_operation = ai_sum_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_12_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_12_scale, &eltwise_12_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_12_layer, 12,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &eltwise_12_chain,
  NULL, &eltwise_14_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_11_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_5_output, &eltwise_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_11_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_11_layer, 11,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_11_chain,
  NULL, &eltwise_12_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_4_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_5_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_5_layer, 5,
  NL_TYPE, 0x0, NULL,
  nl, forward_neg,
  &nl_5_chain,
  NULL, &eltwise_11_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_13_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_2_output0, &eltwise_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_13_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_13_layer, 13,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_13_chain,
  NULL, &nl_5_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_10_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &nl_9_output, &functional_1_layer_normalization_1_Reshape),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_10_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_10_layer, 10,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_10_chain,
  NULL, &eltwise_13_layer, AI_STATIC, 
  .operation = ai_mul_f32, 
  .buffer_operation = ai_mul_buffer_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_7_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_9_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_9_layer, 9,
  NL_TYPE, 0x0, NULL,
  nl, forward_rsqrt,
  &nl_9_chain,
  NULL, &eltwise_10_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_7_Mul_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_7_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &reduce_4_Mul_scale, &reduce_7_Mul_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_7_Mul_layer, 8,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &reduce_7_Mul_chain,
  NULL, &nl_9_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_float reduce_7_neutral_value_data[] = { 0.0f };
AI_ARRAY_OBJ_DECLARE(
    reduce_7_neutral_value, AI_ARRAY_FORMAT_FLOAT,
    reduce_7_neutral_value_data, reduce_7_neutral_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_7_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_7_layer, 8,
  REDUCE_TYPE, 0x0, NULL,
  reduce, forward_reduce,
  &reduce_7_chain,
  NULL, &reduce_7_Mul_layer, AI_STATIC, 
  .operation = ai_sum, 
  .neutral_value = &reduce_7_neutral_value, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_2_output0, &reduce_4_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_6_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_6_layer, 6,
  ELTWISE_TYPE, 0x0, NULL,
  eltwise, forward_eltwise,
  &eltwise_6_chain,
  NULL, &reduce_7_layer, AI_STATIC, 
  .operation = ai_squared_diff, 
  .buffer_operation = ai_squared_diff_buffer, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_4_Mul_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_4_Mul_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &reduce_4_Mul_scale, &reduce_4_Mul_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_4_Mul_layer, 4,
  BN_TYPE, 0x0, NULL,
  bn, forward_bn,
  &reduce_4_Mul_chain,
  NULL, &eltwise_6_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_float reduce_4_neutral_value_data[] = { 0.0f };
AI_ARRAY_OBJ_DECLARE(
    reduce_4_neutral_value, AI_ARRAY_FORMAT_FLOAT,
    reduce_4_neutral_value_data, reduce_4_neutral_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  reduce_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &reduce_4_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  reduce_4_layer, 4,
  REDUCE_TYPE, 0x0, NULL,
  reduce, forward_reduce,
  &reduce_4_chain,
  NULL, &reduce_4_Mul_layer, AI_STATIC, 
  .operation = ai_sum, 
  .neutral_value = &reduce_4_neutral_value, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_0_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_2_weights, &conv2d_2_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_2_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_2_layer, 2,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_2_chain,
  NULL, &reduce_4_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


AI_STATIC_CONST ai_float pad_0_value_data[] = { 0.0 };
AI_ARRAY_OBJ_DECLARE(
    pad_0_value, AI_ARRAY_FORMAT_FLOAT,
    pad_0_value_data, pad_0_value_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  pad_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &serving_default_sequence_input0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &pad_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  pad_0_layer, 0,
  PAD_TYPE, 0x0, NULL,
  pad, forward_pad,
  &pad_0_chain,
  NULL, &conv2d_2_layer, AI_STATIC, 
  .value = &pad_0_value, 
  .mode = AI_PAD_CONSTANT, 
  .pads = AI_SHAPE_INIT(4, 2, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_31_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &serving_default_sequence_input0_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_31_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_31_weights, &conv2d_31_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_31_scratch0, NULL)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_31_layer, 31,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv2d_31_chain,
  NULL, &pad_0_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


#if (AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 157460, 1, 1),
    157460, NULL, NULL),
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 54400, 1, 1),
    54400, NULL, NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_BMS_MODEL_IN_NUM, &serving_default_sequence_input0_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_BMS_MODEL_OUT_NUM, &gemm_222_output),
  &conv2d_31_layer, 0x2e2f1570, NULL)

#else

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 157460, 1, 1),
      157460, NULL, NULL)
  ),
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 54400, 1, 1),
      54400, NULL, NULL)
  ),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_BMS_MODEL_IN_NUM, &serving_default_sequence_input0_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_BMS_MODEL_OUT_NUM, &gemm_222_output),
  &conv2d_31_layer, 0x2e2f1570, NULL)

#endif	/*(AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)*/



/******************************************************************************/
AI_DECLARE_STATIC
ai_bool bms_model_configure_activations(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_activations_map(g_bms_model_activations_map, 1, params)) {
    /* Updating activations (byte) offsets */
    
    serving_default_sequence_input0_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 22720);
    serving_default_sequence_input0_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 22720);
    conv2d_31_scratch0_array.data = AI_PTR(g_bms_model_activations_map[0] + 22716);
    conv2d_31_scratch0_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 22716);
    conv2d_31_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 23200);
    conv2d_31_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 23200);
    pad_0_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38560);
    pad_0_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38560);
    conv2d_2_scratch0_array.data = AI_PTR(g_bms_model_activations_map[0] + 39048);
    conv2d_2_scratch0_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 39048);
    conv2d_2_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 7840);
    conv2d_2_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 7840);
    reduce_4_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38580);
    reduce_4_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38580);
    reduce_4_Mul_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 7360);
    reduce_4_Mul_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 7360);
    eltwise_6_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38560);
    eltwise_6_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38560);
    reduce_7_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 53920);
    reduce_7_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 53920);
    reduce_7_Mul_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38560);
    reduce_7_Mul_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38560);
    nl_9_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 53920);
    nl_9_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 53920);
    eltwise_10_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38560);
    eltwise_10_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38560);
    eltwise_13_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 7840);
    eltwise_13_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 7840);
    nl_5_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 53920);
    nl_5_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 53920);
    eltwise_11_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38560);
    eltwise_11_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38560);
    eltwise_12_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38560);
    eltwise_12_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38560);
    eltwise_14_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 7840);
    eltwise_14_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 7840);
    nl_14_nl_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38560);
    nl_14_nl_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38560);
    pad_15_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 7360);
    pad_15_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 7360);
    conv2d_17_scratch0_array.data = AI_PTR(g_bms_model_activations_map[0] + 38560);
    conv2d_17_scratch0_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38560);
    conv2d_17_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 39040);
    conv2d_17_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 39040);
    reduce_19_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 7360);
    reduce_19_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 7360);
    reduce_19_Mul_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 22720);
    reduce_19_Mul_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 22720);
    eltwise_21_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 7360);
    eltwise_21_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 7360);
    reduce_22_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38560);
    reduce_22_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38560);
    reduce_22_Mul_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 7360);
    reduce_22_Mul_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 7360);
    nl_24_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38560);
    nl_24_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38560);
    eltwise_25_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 7360);
    eltwise_25_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 7360);
    eltwise_28_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 39040);
    eltwise_28_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 39040);
    nl_20_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38560);
    nl_20_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38560);
    eltwise_26_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 7360);
    eltwise_26_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 7360);
    eltwise_27_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 7360);
    eltwise_27_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 7360);
    eltwise_29_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 39040);
    eltwise_29_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 39040);
    eltwise_33_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 7360);
    eltwise_33_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 7360);
    nl_33_nl_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 22720);
    nl_33_nl_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 22720);
    pad_34_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38080);
    pad_34_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38080);
    conv2d_37_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 7360);
    conv2d_37_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 7360);
    reduce_41_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38080);
    reduce_41_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38080);
    reduce_41_Mul_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38560);
    reduce_41_Mul_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38560);
    eltwise_43_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 39040);
    eltwise_43_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 39040);
    reduce_44_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38080);
    reduce_44_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38080);
    reduce_44_Mul_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 39040);
    reduce_44_Mul_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 39040);
    nl_46_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38080);
    nl_46_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38080);
    eltwise_47_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 39040);
    eltwise_47_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 39040);
    eltwise_50_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 7360);
    eltwise_50_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 7360);
    nl_42_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38080);
    nl_42_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38080);
    eltwise_48_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 39040);
    eltwise_48_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 39040);
    eltwise_49_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 39040);
    eltwise_49_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 39040);
    eltwise_51_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 7360);
    eltwise_51_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 7360);
    nl_51_nl_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 39040);
    nl_51_nl_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 39040);
    pad_52_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38528);
    pad_52_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38528);
    conv2d_55_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 7360);
    conv2d_55_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 7360);
    reduce_59_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38080);
    reduce_59_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38080);
    reduce_59_Mul_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 53920);
    reduce_59_Mul_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 53920);
    eltwise_61_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38560);
    eltwise_61_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38560);
    reduce_62_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38080);
    reduce_62_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38080);
    reduce_62_Mul_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 53440);
    reduce_62_Mul_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 53440);
    nl_64_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 53440);
    nl_64_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 53440);
    eltwise_65_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38080);
    eltwise_65_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38080);
    eltwise_68_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 7360);
    eltwise_68_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 7360);
    nl_60_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 53440);
    nl_60_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 53440);
    eltwise_66_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38080);
    eltwise_66_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38080);
    eltwise_67_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38080);
    eltwise_67_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38080);
    eltwise_69_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38080);
    eltwise_69_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38080);
    eltwise_70_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 22720);
    eltwise_70_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 22720);
    nl_70_nl_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38080);
    nl_70_nl_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38080);
    pad_71_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 21696);
    pad_71_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 21696);
    conv2d_74_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 21568);
    conv2d_74_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 21568);
    reduce_78_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 53920);
    reduce_78_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 53920);
    reduce_78_Mul_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 53920);
    reduce_78_Mul_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 53920);
    eltwise_80_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 6208);
    eltwise_80_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 6208);
    reduce_81_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 36928);
    reduce_81_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 36928);
    reduce_81_Mul_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 6208);
    reduce_81_Mul_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 6208);
    nl_83_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 21088);
    nl_83_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 21088);
    eltwise_84_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 5728);
    eltwise_84_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 5728);
    eltwise_87_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 21568);
    eltwise_87_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 21568);
    nl_79_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 21088);
    nl_79_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 21088);
    eltwise_85_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 5728);
    eltwise_85_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 5728);
    eltwise_86_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 5728);
    eltwise_86_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 5728);
    eltwise_88_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 21568);
    eltwise_88_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 21568);
    nl_88_nl_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 5728);
    nl_88_nl_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 5728);
    pad_89_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 21088);
    pad_89_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 21088);
    conv2d_92_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 5728);
    conv2d_92_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 5728);
    reduce_96_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 21088);
    reduce_96_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 21088);
    reduce_96_Mul_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 21568);
    reduce_96_Mul_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 21568);
    eltwise_98_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 22048);
    eltwise_98_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 22048);
    reduce_99_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 21088);
    reduce_99_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 21088);
    reduce_99_Mul_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 22048);
    reduce_99_Mul_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 22048);
    nl_101_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 21088);
    nl_101_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 21088);
    eltwise_102_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 22048);
    eltwise_102_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 22048);
    eltwise_105_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 5728);
    eltwise_105_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 5728);
    nl_97_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 21088);
    nl_97_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 21088);
    eltwise_103_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 22048);
    eltwise_103_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 22048);
    eltwise_104_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 22048);
    eltwise_104_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 22048);
    eltwise_106_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 5728);
    eltwise_106_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 5728);
    eltwise_107_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 21088);
    eltwise_107_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 21088);
    nl_107_nl_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 5728);
    nl_107_nl_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 5728);
    pad_108_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 21088);
    pad_108_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 21088);
    conv2d_111_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38496);
    conv2d_111_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38496);
    reduce_115_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 21088);
    reduce_115_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 21088);
    reduce_115_Mul_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 21568);
    reduce_115_Mul_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 21568);
    eltwise_117_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 22048);
    eltwise_117_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 22048);
    reduce_118_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 21088);
    reduce_118_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 21088);
    reduce_118_Mul_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 22048);
    reduce_118_Mul_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 22048);
    nl_120_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 21088);
    nl_120_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 21088);
    eltwise_121_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 22048);
    eltwise_121_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 22048);
    eltwise_124_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38496);
    eltwise_124_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38496);
    nl_116_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 21088);
    nl_116_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 21088);
    eltwise_122_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 22048);
    eltwise_122_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 22048);
    eltwise_123_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 22048);
    eltwise_123_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 22048);
    eltwise_125_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38496);
    eltwise_125_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38496);
    nl_125_nl_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 21088);
    nl_125_nl_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 21088);
    pad_126_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 36448);
    pad_126_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 36448);
    conv2d_129_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 21088);
    conv2d_129_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 21088);
    reduce_133_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 36448);
    reduce_133_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 36448);
    reduce_133_Mul_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 36928);
    reduce_133_Mul_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 36928);
    eltwise_135_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 37408);
    eltwise_135_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 37408);
    reduce_136_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 36448);
    reduce_136_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 36448);
    reduce_136_Mul_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 37408);
    reduce_136_Mul_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 37408);
    nl_138_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 36448);
    nl_138_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 36448);
    eltwise_139_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 37408);
    eltwise_139_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 37408);
    eltwise_142_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 21088);
    eltwise_142_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 21088);
    nl_134_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 36448);
    nl_134_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 36448);
    eltwise_140_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 37408);
    eltwise_140_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 37408);
    eltwise_141_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 37408);
    eltwise_141_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 37408);
    eltwise_143_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 21088);
    eltwise_143_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 21088);
    eltwise_144_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 36448);
    eltwise_144_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 36448);
    nl_144_nl_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 36448);
    nl_144_nl_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 36448);
    pad_145_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 5728);
    pad_145_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 5728);
    conv2d_148_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 5600);
    conv2d_148_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 5600);
    reduce_152_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 20960);
    reduce_152_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 20960);
    reduce_152_Mul_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 51808);
    reduce_152_Mul_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 51808);
    eltwise_154_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 20960);
    eltwise_154_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 20960);
    reduce_155_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 52288);
    reduce_155_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 52288);
    reduce_155_Mul_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 20960);
    reduce_155_Mul_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 20960);
    nl_157_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 52288);
    nl_157_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 52288);
    eltwise_158_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 20960);
    eltwise_158_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 20960);
    eltwise_161_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 5600);
    eltwise_161_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 5600);
    nl_153_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 5120);
    nl_153_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 5120);
    eltwise_159_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 20960);
    eltwise_159_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 20960);
    eltwise_160_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 20960);
    eltwise_160_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 20960);
    eltwise_162_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 5600);
    eltwise_162_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 5600);
    nl_162_nl_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 21088);
    nl_162_nl_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 21088);
    pad_163_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 16992);
    pad_163_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 16992);
    conv2d_166_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 16864);
    conv2d_166_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 16864);
    reduce_170_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 53920);
    reduce_170_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 53920);
    reduce_170_Mul_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 53920);
    reduce_170_Mul_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 53920);
    eltwise_172_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 1504);
    eltwise_172_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 1504);
    reduce_173_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 32224);
    reduce_173_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 32224);
    reduce_173_Mul_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 1504);
    reduce_173_Mul_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 1504);
    nl_175_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 32224);
    nl_175_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 32224);
    eltwise_176_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 1504);
    eltwise_176_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 1504);
    eltwise_179_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 16864);
    eltwise_179_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 16864);
    nl_171_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 32224);
    nl_171_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 32224);
    eltwise_177_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 1504);
    eltwise_177_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 1504);
    eltwise_178_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 1504);
    eltwise_178_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 1504);
    eltwise_180_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 16864);
    eltwise_180_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 16864);
    eltwise_181_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 1504);
    eltwise_181_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 1504);
    nl_181_nl_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 39040);
    nl_181_nl_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 39040);
    pad_182_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 1504);
    pad_182_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 1504);
    conv2d_185_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 1376);
    conv2d_185_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 1376);
    reduce_189_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 16736);
    reduce_189_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 16736);
    reduce_189_Mul_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 17216);
    reduce_189_Mul_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 17216);
    eltwise_191_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 17696);
    eltwise_191_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 17696);
    reduce_192_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 16736);
    reduce_192_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 16736);
    reduce_192_Mul_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 17696);
    reduce_192_Mul_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 17696);
    nl_194_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 16736);
    nl_194_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 16736);
    eltwise_195_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 17696);
    eltwise_195_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 17696);
    eltwise_198_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 1376);
    eltwise_198_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 1376);
    nl_190_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 16736);
    nl_190_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 16736);
    eltwise_196_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 17696);
    eltwise_196_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 17696);
    eltwise_197_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 17696);
    eltwise_197_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 17696);
    eltwise_199_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 1376);
    eltwise_199_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 1376);
    nl_199_nl_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 23680);
    nl_199_nl_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 23680);
    pad_200_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 15488);
    pad_200_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 15488);
    conv2d_203_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 15360);
    conv2d_203_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 15360);
    reduce_207_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38560);
    reduce_207_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38560);
    reduce_207_Mul_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 38560);
    reduce_207_Mul_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 38560);
    eltwise_209_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 0);
    eltwise_209_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 0);
    reduce_210_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 30720);
    reduce_210_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 30720);
    reduce_210_Mul_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 0);
    reduce_210_Mul_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 0);
    nl_212_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 30720);
    nl_212_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 30720);
    eltwise_213_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 0);
    eltwise_213_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 0);
    eltwise_216_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 15360);
    eltwise_216_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 15360);
    nl_208_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 30720);
    nl_208_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 30720);
    eltwise_214_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 0);
    eltwise_214_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 0);
    eltwise_215_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 0);
    eltwise_215_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 0);
    eltwise_217_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 15360);
    eltwise_217_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 15360);
    eltwise_218_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 0);
    eltwise_218_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 0);
    nl_218_nl_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 15360);
    nl_218_nl_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 15360);
    slice_219_gather_0_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 0);
    slice_219_gather_0_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 0);
    gemm_220_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 128);
    gemm_220_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 128);
    nl_220_nl_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 384);
    nl_220_nl_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 384);
    gemm_221_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 0);
    gemm_221_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 0);
    nl_221_nl_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 128);
    nl_221_nl_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 128);
    gemm_222_output_array.data = AI_PTR(g_bms_model_activations_map[0] + 0);
    gemm_222_output_array.data_start = AI_PTR(g_bms_model_activations_map[0] + 0);
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_ACTIVATIONS);
  return false;
}




/******************************************************************************/
AI_DECLARE_STATIC
ai_bool bms_model_configure_weights(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_weights_map(g_bms_model_weights_map, 1, params)) {
    /* Updating weights (byte) offsets */
    
    slice_219_gather_0_placeholder_array.format |= AI_FMT_FLAG_CONST;
    slice_219_gather_0_placeholder_array.data = AI_PTR(g_bms_model_weights_map[0] + 0);
    slice_219_gather_0_placeholder_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 0);
    functional_1_layer_normalization_11_1_Reshape_array.format |= AI_FMT_FLAG_CONST;
    functional_1_layer_normalization_11_1_Reshape_array.data = AI_PTR(g_bms_model_weights_map[0] + 4);
    functional_1_layer_normalization_11_1_Reshape_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 4);
    functional_1_layer_normalization_10_1_Reshape_array.format |= AI_FMT_FLAG_CONST;
    functional_1_layer_normalization_10_1_Reshape_array.data = AI_PTR(g_bms_model_weights_map[0] + 132);
    functional_1_layer_normalization_10_1_Reshape_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 132);
    functional_1_layer_normalization_9_1_Reshape_array.format |= AI_FMT_FLAG_CONST;
    functional_1_layer_normalization_9_1_Reshape_array.data = AI_PTR(g_bms_model_weights_map[0] + 260);
    functional_1_layer_normalization_9_1_Reshape_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 260);
    functional_1_layer_normalization_8_1_Reshape_array.format |= AI_FMT_FLAG_CONST;
    functional_1_layer_normalization_8_1_Reshape_array.data = AI_PTR(g_bms_model_weights_map[0] + 388);
    functional_1_layer_normalization_8_1_Reshape_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 388);
    functional_1_layer_normalization_7_1_Reshape_array.format |= AI_FMT_FLAG_CONST;
    functional_1_layer_normalization_7_1_Reshape_array.data = AI_PTR(g_bms_model_weights_map[0] + 516);
    functional_1_layer_normalization_7_1_Reshape_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 516);
    functional_1_layer_normalization_6_1_Reshape_array.format |= AI_FMT_FLAG_CONST;
    functional_1_layer_normalization_6_1_Reshape_array.data = AI_PTR(g_bms_model_weights_map[0] + 644);
    functional_1_layer_normalization_6_1_Reshape_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 644);
    functional_1_layer_normalization_5_1_Reshape_array.format |= AI_FMT_FLAG_CONST;
    functional_1_layer_normalization_5_1_Reshape_array.data = AI_PTR(g_bms_model_weights_map[0] + 772);
    functional_1_layer_normalization_5_1_Reshape_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 772);
    functional_1_layer_normalization_4_1_Reshape_array.format |= AI_FMT_FLAG_CONST;
    functional_1_layer_normalization_4_1_Reshape_array.data = AI_PTR(g_bms_model_weights_map[0] + 900);
    functional_1_layer_normalization_4_1_Reshape_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 900);
    functional_1_layer_normalization_3_1_Reshape_array.format |= AI_FMT_FLAG_CONST;
    functional_1_layer_normalization_3_1_Reshape_array.data = AI_PTR(g_bms_model_weights_map[0] + 1028);
    functional_1_layer_normalization_3_1_Reshape_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 1028);
    functional_1_layer_normalization_2_1_Reshape_array.format |= AI_FMT_FLAG_CONST;
    functional_1_layer_normalization_2_1_Reshape_array.data = AI_PTR(g_bms_model_weights_map[0] + 1156);
    functional_1_layer_normalization_2_1_Reshape_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 1156);
    functional_1_layer_normalization_1_2_Reshape_array.format |= AI_FMT_FLAG_CONST;
    functional_1_layer_normalization_1_2_Reshape_array.data = AI_PTR(g_bms_model_weights_map[0] + 1284);
    functional_1_layer_normalization_1_2_Reshape_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 1284);
    functional_1_layer_normalization_1_Reshape_array.format |= AI_FMT_FLAG_CONST;
    functional_1_layer_normalization_1_Reshape_array.data = AI_PTR(g_bms_model_weights_map[0] + 1412);
    functional_1_layer_normalization_1_Reshape_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 1412);
    conv2d_31_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_31_weights_array.data = AI_PTR(g_bms_model_weights_map[0] + 1540);
    conv2d_31_weights_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 1540);
    conv2d_31_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_31_bias_array.data = AI_PTR(g_bms_model_weights_map[0] + 1668);
    conv2d_31_bias_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 1668);
    conv2d_2_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_weights_array.data = AI_PTR(g_bms_model_weights_map[0] + 1796);
    conv2d_2_weights_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 1796);
    conv2d_2_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_bias_array.data = AI_PTR(g_bms_model_weights_map[0] + 2180);
    conv2d_2_bias_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 2180);
    reduce_4_Mul_scale_array.format |= AI_FMT_FLAG_CONST;
    reduce_4_Mul_scale_array.data = AI_PTR(g_bms_model_weights_map[0] + 2308);
    reduce_4_Mul_scale_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 2308);
    reduce_4_Mul_bias_array.format |= AI_FMT_FLAG_CONST;
    reduce_4_Mul_bias_array.data = AI_PTR(g_bms_model_weights_map[0] + 2312);
    reduce_4_Mul_bias_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 2312);
    reduce_7_Mul_bias_array.format |= AI_FMT_FLAG_CONST;
    reduce_7_Mul_bias_array.data = AI_PTR(g_bms_model_weights_map[0] + 2316);
    reduce_7_Mul_bias_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 2316);
    eltwise_12_scale_array.format |= AI_FMT_FLAG_CONST;
    eltwise_12_scale_array.data = AI_PTR(g_bms_model_weights_map[0] + 2320);
    eltwise_12_scale_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 2320);
    eltwise_12_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_12_bias_array.data = AI_PTR(g_bms_model_weights_map[0] + 2448);
    eltwise_12_bias_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 2448);
    conv2d_17_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_weights_array.data = AI_PTR(g_bms_model_weights_map[0] + 2576);
    conv2d_17_weights_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 2576);
    conv2d_17_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_bias_array.data = AI_PTR(g_bms_model_weights_map[0] + 14864);
    conv2d_17_bias_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 14864);
    eltwise_27_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_27_bias_array.data = AI_PTR(g_bms_model_weights_map[0] + 14992);
    eltwise_27_bias_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 14992);
    conv2d_37_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_37_weights_array.data = AI_PTR(g_bms_model_weights_map[0] + 15120);
    conv2d_37_weights_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 15120);
    conv2d_37_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_37_bias_array.data = AI_PTR(g_bms_model_weights_map[0] + 27408);
    conv2d_37_bias_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 27408);
    eltwise_49_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_49_bias_array.data = AI_PTR(g_bms_model_weights_map[0] + 27536);
    eltwise_49_bias_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 27536);
    conv2d_55_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_55_weights_array.data = AI_PTR(g_bms_model_weights_map[0] + 27664);
    conv2d_55_weights_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 27664);
    conv2d_55_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_55_bias_array.data = AI_PTR(g_bms_model_weights_map[0] + 39952);
    conv2d_55_bias_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 39952);
    eltwise_67_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_67_bias_array.data = AI_PTR(g_bms_model_weights_map[0] + 40080);
    eltwise_67_bias_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 40080);
    conv2d_74_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_74_weights_array.data = AI_PTR(g_bms_model_weights_map[0] + 40208);
    conv2d_74_weights_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 40208);
    conv2d_74_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_74_bias_array.data = AI_PTR(g_bms_model_weights_map[0] + 52496);
    conv2d_74_bias_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 52496);
    eltwise_86_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_86_bias_array.data = AI_PTR(g_bms_model_weights_map[0] + 52624);
    eltwise_86_bias_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 52624);
    conv2d_92_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_92_weights_array.data = AI_PTR(g_bms_model_weights_map[0] + 52752);
    conv2d_92_weights_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 52752);
    conv2d_92_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_92_bias_array.data = AI_PTR(g_bms_model_weights_map[0] + 65040);
    conv2d_92_bias_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 65040);
    eltwise_104_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_104_bias_array.data = AI_PTR(g_bms_model_weights_map[0] + 65168);
    eltwise_104_bias_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 65168);
    conv2d_111_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_111_weights_array.data = AI_PTR(g_bms_model_weights_map[0] + 65296);
    conv2d_111_weights_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 65296);
    conv2d_111_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_111_bias_array.data = AI_PTR(g_bms_model_weights_map[0] + 77584);
    conv2d_111_bias_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 77584);
    eltwise_123_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_123_bias_array.data = AI_PTR(g_bms_model_weights_map[0] + 77712);
    eltwise_123_bias_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 77712);
    conv2d_129_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_129_weights_array.data = AI_PTR(g_bms_model_weights_map[0] + 77840);
    conv2d_129_weights_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 77840);
    conv2d_129_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_129_bias_array.data = AI_PTR(g_bms_model_weights_map[0] + 90128);
    conv2d_129_bias_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 90128);
    eltwise_141_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_141_bias_array.data = AI_PTR(g_bms_model_weights_map[0] + 90256);
    eltwise_141_bias_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 90256);
    conv2d_148_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_148_weights_array.data = AI_PTR(g_bms_model_weights_map[0] + 90384);
    conv2d_148_weights_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 90384);
    conv2d_148_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_148_bias_array.data = AI_PTR(g_bms_model_weights_map[0] + 102672);
    conv2d_148_bias_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 102672);
    eltwise_160_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_160_bias_array.data = AI_PTR(g_bms_model_weights_map[0] + 102800);
    eltwise_160_bias_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 102800);
    conv2d_166_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_166_weights_array.data = AI_PTR(g_bms_model_weights_map[0] + 102928);
    conv2d_166_weights_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 102928);
    conv2d_166_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_166_bias_array.data = AI_PTR(g_bms_model_weights_map[0] + 115216);
    conv2d_166_bias_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 115216);
    eltwise_178_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_178_bias_array.data = AI_PTR(g_bms_model_weights_map[0] + 115344);
    eltwise_178_bias_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 115344);
    conv2d_185_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_185_weights_array.data = AI_PTR(g_bms_model_weights_map[0] + 115472);
    conv2d_185_weights_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 115472);
    conv2d_185_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_185_bias_array.data = AI_PTR(g_bms_model_weights_map[0] + 127760);
    conv2d_185_bias_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 127760);
    eltwise_197_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_197_bias_array.data = AI_PTR(g_bms_model_weights_map[0] + 127888);
    eltwise_197_bias_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 127888);
    conv2d_203_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_203_weights_array.data = AI_PTR(g_bms_model_weights_map[0] + 128016);
    conv2d_203_weights_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 128016);
    conv2d_203_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_203_bias_array.data = AI_PTR(g_bms_model_weights_map[0] + 140304);
    conv2d_203_bias_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 140304);
    eltwise_215_bias_array.format |= AI_FMT_FLAG_CONST;
    eltwise_215_bias_array.data = AI_PTR(g_bms_model_weights_map[0] + 140432);
    eltwise_215_bias_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 140432);
    gemm_220_weights_array.format |= AI_FMT_FLAG_CONST;
    gemm_220_weights_array.data = AI_PTR(g_bms_model_weights_map[0] + 140560);
    gemm_220_weights_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 140560);
    gemm_220_bias_array.format |= AI_FMT_FLAG_CONST;
    gemm_220_bias_array.data = AI_PTR(g_bms_model_weights_map[0] + 148752);
    gemm_220_bias_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 148752);
    gemm_221_weights_array.format |= AI_FMT_FLAG_CONST;
    gemm_221_weights_array.data = AI_PTR(g_bms_model_weights_map[0] + 149008);
    gemm_221_weights_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 149008);
    gemm_221_bias_array.format |= AI_FMT_FLAG_CONST;
    gemm_221_bias_array.data = AI_PTR(g_bms_model_weights_map[0] + 157200);
    gemm_221_bias_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 157200);
    gemm_222_weights_array.format |= AI_FMT_FLAG_CONST;
    gemm_222_weights_array.data = AI_PTR(g_bms_model_weights_map[0] + 157328);
    gemm_222_weights_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 157328);
    gemm_222_bias_array.format |= AI_FMT_FLAG_CONST;
    gemm_222_bias_array.data = AI_PTR(g_bms_model_weights_map[0] + 157456);
    gemm_222_bias_array.data_start = AI_PTR(g_bms_model_weights_map[0] + 157456);
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_WEIGHTS);
  return false;
}


/**  PUBLIC APIs SECTION  *****************************************************/



AI_DEPRECATED
AI_API_ENTRY
ai_bool ai_bms_model_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_BMS_MODEL_MODEL_NAME,
      .model_signature   = AI_BMS_MODEL_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 4678497,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .params            = AI_STRUCT_INIT,
      .activations       = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x2e2f1570,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}



AI_API_ENTRY
ai_bool ai_bms_model_get_report(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_BMS_MODEL_MODEL_NAME,
      .model_signature   = AI_BMS_MODEL_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 4678497,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .map_signature     = AI_MAGIC_SIGNATURE,
      .map_weights       = AI_STRUCT_INIT,
      .map_activations   = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x2e2f1570,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}


AI_API_ENTRY
ai_error ai_bms_model_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}


AI_API_ENTRY
ai_error ai_bms_model_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    AI_CONTEXT_OBJ(&AI_NET_OBJ_INSTANCE),
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}


AI_API_ENTRY
ai_error ai_bms_model_create_and_init(
  ai_handle* network, const ai_handle activations[], const ai_handle weights[])
{
  ai_error err;
  ai_network_params params;

  err = ai_bms_model_create(network, AI_BMS_MODEL_DATA_CONFIG);
  if (err.type != AI_ERROR_NONE) {
    return err;
  }
  
  if (ai_bms_model_data_params_get(&params) != true) {
    err = ai_bms_model_get_error(*network);
    return err;
  }
#if defined(AI_BMS_MODEL_DATA_ACTIVATIONS_COUNT)
  /* set the addresses of the activations buffers */
  for (ai_u16 idx=0; activations && idx<params.map_activations.size; idx++) {
    AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_activations, idx, activations[idx]);
  }
#endif
#if defined(AI_BMS_MODEL_DATA_WEIGHTS_COUNT)
  /* set the addresses of the weight buffers */
  for (ai_u16 idx=0; weights && idx<params.map_weights.size; idx++) {
    AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_weights, idx, weights[idx]);
  }
#endif
  if (ai_bms_model_init(*network, &params) != true) {
    err = ai_bms_model_get_error(*network);
  }
  return err;
}


AI_API_ENTRY
ai_buffer* ai_bms_model_inputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    AI_NETWORK_OBJ(network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_inputs_get(network, n_buffer);
}


AI_API_ENTRY
ai_buffer* ai_bms_model_outputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    AI_NETWORK_OBJ(network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_outputs_get(network, n_buffer);
}


AI_API_ENTRY
ai_handle ai_bms_model_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}


AI_API_ENTRY
ai_bool ai_bms_model_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = AI_NETWORK_OBJ(ai_platform_network_init(network, params));
  ai_bool ok = true;

  if (!net_ctx) return false;
  ok &= bms_model_configure_weights(net_ctx, params);
  ok &= bms_model_configure_activations(net_ctx, params);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_bms_model_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}


AI_API_ENTRY
ai_i32 ai_bms_model_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_BMS_MODEL_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

