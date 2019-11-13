/*
    Register.h 
    All of the registers are listed in the namespace "reg"

    Author: C. Lin (jay@hep1.phys.ntu.edu.tw)
    Date  : 2018.04.10

    Version recommended:
    - Top CDT     : 
    - Fan-out CDT :
    - Local CDT   :
    - ADC         :
    - ET OFC      :
    - Clus OFC    :

*/

#ifndef REGISTER_H
#define REGISTER_H

namespace reg{

   typedef struct control_reg {
           char              name[32];
           unsigned long     size;
           char              type[4];
           unsigned long     address;
           unsigned long     start_bit;
           unsigned long     mask;
           unsigned long     default_value;
           unsigned long     value;
   } Ctrl_Reg;

/*--------------------------------------------------------------------------------------------------------------*/
//// ADC ////


  const Ctrl_Reg adc_reg[300]=
  {
//       Name                     Width  Type Address Start  Mask       Default  Present
//                                                     bit               Value    Value
       { "N_width"               , 10 ,  "rw" ,  1 ,    0 ,  0x03ff     , 0x0008 ,   0 },
       { "sum_mode"              ,  1 ,  "rw" ,  1 ,   10 ,  0x0400     , 0x0001 ,   0 },
       { "pll_reset"             ,  1 ,  "rw" ,  1 ,   11 ,  0x0800     , 0x0000 ,   0 }, // v2175 up and v5128 up
       { "transceiver_enable"    ,  1 ,  "rw" ,  1 ,   12 ,  0x1000     , 0x0001 ,   0 },
       { "clear_fault"           ,  1 ,  "rw" ,  1 ,   13 ,  0x2000     , 0x0000 ,   0 },
       { "board_no"              ,  8 ,  "rw" ,  1 ,   16 ,  0xff0000   , 0x0000 ,   0 }, // v2280 up
       { "pedestal_0"            , 14 ,  "rw" ,  2 ,    0 ,  0x3fff     , 0x0000 ,   0 },
       { "zero_mode_0"           ,  2 ,  "rw" ,  2 ,   14 ,  0xc000     , 0x0000 ,   0 },
       { "pedestal_1"            , 14 ,  "rw" ,  2 ,   16 ,  0x3fff0000 , 0x0000 ,   0 },
       { "zero_mode_1"           ,  2 ,  "rw" ,  2 ,   30 ,  0xc0000000 , 0x0000 ,   0 },
       { "pedestal_2"            , 14 ,  "rw" ,  3 ,    0 ,  0x3fff     , 0x0000 ,   0 },
       { "zero_mode_2"           ,  2 ,  "rw" ,  3 ,   14 ,  0xc000     , 0x0000 ,   0 },
       { "pedestal_3"            , 14 ,  "rw" ,  3 ,   16 ,  0x3fff0000 , 0x0000 ,   0 },
       { "zero_mode_3"           ,  2 ,  "rw" ,  3 ,   30 ,  0xc0000000 , 0x0000 ,   0 },
       { "pedestal_4"            , 14 ,  "rw" ,  4 ,    0 ,  0x3fff     , 0x0000 ,   0 },
       { "zero_mode_4"           ,  2 ,  "rw" ,  4 ,   14 ,  0xc000     , 0x0000 ,   0 },
       { "pedestal_5"            , 14 ,  "rw" ,  4 ,   16 ,  0x3fff0000 , 0x0000 ,   0 },
       { "zero_mode_5"           ,  2 ,  "rw" ,  4 ,   30 ,  0xc0000000 , 0x0000 ,   0 },
       { "pedestal_6"            , 14 ,  "rw" ,  5 ,    0 ,  0x3fff     , 0x0000 ,   0 },
       { "zero_mode_6"           ,  2 ,  "rw" ,  5 ,   14 ,  0xc000     , 0x0000 ,   0 },
       { "pedestal_7"            , 14 ,  "rw" ,  5 ,   16 ,  0x3fff0000 , 0x0000 ,   0 },
       { "zero_mode_7"           ,  2 ,  "rw" ,  5 ,   30 ,  0xc0000000 , 0x0000 ,   0 },
       { "pedestal_8"            , 14 ,  "rw" ,  6 ,    0 ,  0x3fff     , 0x0000 ,   0 },
       { "zero_mode_8"           ,  2 ,  "rw" ,  6 ,   14 ,  0xc000     , 0x0000 ,   0 },
       { "pedestal_9"            , 14 ,  "rw" ,  6 ,   16 ,  0x3fff0000 , 0x0000 ,   0 },
       { "zero_mode_9"           ,  2 ,  "rw" ,  6 ,   30 ,  0xc0000000 , 0x0000 ,   0 },
       { "pedestal_10"           , 14 ,  "rw" ,  7 ,    0 ,  0x3fff     , 0x0000 ,   0 },
       { "zero_mode_10"          ,  2 ,  "rw" ,  7 ,   14 ,  0xc000     , 0x0000 ,   0 },
       { "pedestal_11"           , 14 ,  "rw" ,  7 ,   16 ,  0x3fff0000 , 0x0000 ,   0 },
       { "zero_mode_11"          ,  2 ,  "rw" ,  7 ,   30 ,  0xc0000000 , 0x0000 ,   0 },
       { "pedestal_12"           , 14 ,  "rw" ,  8 ,    0 ,  0x3fff     , 0x0000 ,   0 },
       { "zero_mode_12"          ,  2 ,  "rw" ,  8 ,   14 ,  0xc000     , 0x0000 ,   0 },
       { "pedestal_13"           , 14 ,  "rw" ,  8 ,   16 ,  0x3fff0000 , 0x0000 ,   0 },
       { "zero_mode_13"          ,  2 ,  "rw" ,  8 ,   30 ,  0xc0000000 , 0x0000 ,   0 },
       { "pedestal_14"           , 14 ,  "rw" ,  9 ,    0 ,  0x3fff     , 0x0000 ,   0 },
       { "zero_mode_14"          ,  2 ,  "rw" ,  9 ,   14 ,  0xc000     , 0x0000 ,   0 },
       { "pedestal_15"           , 14 ,  "rw" ,  9 ,   16 ,  0x3fff0000 , 0x0000 ,   0 },
       { "zero_mode_15"          ,  2 ,  "rw" ,  9 ,   30 ,  0xc0000000 , 0x0000 ,   0 },
       { "delay[15:0]"           , 16 ,  "rw" , 11 ,    0 ,  0xffff     , 0x0000 ,   0 },  // adc125&500
//     { "delay[19:16]"          ,  4 ,  "rw" , 10 ,    0 ,  0x000f     , 0x0000 ,   0 },  // adc500 only
       { "delay[31:16]"          , 16 ,  "rw" , 12 ,    0 ,  0xffff     , 0x0000 ,   0 },  // adc125 only
       { "delay[47:32]"          , 16 ,  "rw" , 13 ,    0 ,  0xffff     , 0x0000 ,   0 },  // adc125 only
       { "delay[63:48]"          , 16 ,  "rw" , 14 ,    0 ,  0xffff     , 0x0000 ,   0 },  // adc125 only
//       { "delay[79:64]"          , 16 ,  "rw" , 10 ,    0 ,  0xffff     , 0x0000 ,   0 },  // adc125 only
       { "sc_ad"                 ,  8 ,  "rw" , 16 ,    0 ,  0x00ff     , 0x0000 ,   0 },
       { "sc_wr"                 ,  1 ,  "rw" , 16 ,    8 ,  0x0100     , 0x0000 ,   0 },
       { "sc_dt"                 , 16 ,  "rw" , 17 ,    0 ,  0xffff     , 0x0000 ,   0 },
       { "fault_count"           , 16 ,   "r" , 18 ,    0 ,  0xffff     , 0x0000 ,   0 },
       { "ES_mode_control"       ,  3 ,  "rw" , 19 ,    0 ,  0x0007     , 0x0000 ,   0 },
       { "live_bypass"           ,  1 ,  "rw" , 19 ,    3 ,  0x0008     , 0x0000 ,   0 },
       { "DS_mode_control"       ,  3 ,  "rw" , 19 ,    4 ,  0x0070     , 0x0000 ,   0 },
       { "l1a_bypass"            ,  1 ,  "rw" , 19 ,    7 ,  0x0080     , 0x0000 ,   0 },
       { "clk_sync_mode"         ,  1 ,  "rw" , 19 ,    8 ,  0x0100     , 0x0000 ,   0 },
       { "err_enable"            ,  1 ,  "rw" , 19 ,    9 ,  0x0200     , 0x0000 ,   0 },
       { "loop_back_en_2p5"      ,  1 ,  "rw" , 19 ,   11 ,  0x0800     , 0x0000 ,   0 },
       { "loop_back_en_3p125"    ,  1 ,  "rw" , 19 ,   12 ,  0x1000     , 0x0000 ,   0 },
       { "clk_select_mode"       ,  1 ,  "rw" , 19 ,   13 ,  0x2000     , 0x0000 ,   0 },
       { "live_bypass_mode"      ,  1 ,  "rw" , 19 ,   14 ,  0x4000     , 0x0000 ,   0 },
       { "l1a_bypass_mode"       ,  1 ,  "rw" , 19 ,   15 ,  0x8000     , 0x0000 ,   0 },
       { "ES_buffer_full"        ,  1 ,   "r" , 20 ,    0 ,  0x0001     , 0x0000 ,   0 },
       { "DS_buffer_full"        ,  1 ,   "r" , 20 ,    1 ,  0x0002     , 0x0000 ,   0 },
       { "start(LIVE)"           ,  1 ,   "r" , 20 ,    2 ,  0x0004     , 0x0000 ,   0 },
       { "buffer_empty"          ,  1 ,   "r" , 20 ,    3 ,  0x0008     , 0x0000 ,   0 },
       { "packet_transfer"       ,  1 ,   "r" , 20 ,    4 ,  0x0010     , 0x0000 ,   0 },
       { "loop_back_err_2p5"     ,  1 ,   "r" , 20 ,    5 ,  0x0020     , 0x0000 ,   0 },
       { "loop_back_err_3p125"   ,  1 ,   "r" , 20 ,    6 ,  0x0040     , 0x0000 ,   0 },
       { "DS_buffer_not_empty"   ,  1 ,   "r" , 20 ,    7 ,  0x0080     , 0x0000 ,   0 },
       { "read_crc_error"        ,  1 ,   "r" , 20 ,    8 ,  0x0100     , 0x0000 ,   0 },
       { "almost_full"           ,  1 ,   "r" , 20 ,    9 ,  0x0200     , 0x0000 ,   0 },
       { "out_of_range"          , 16 ,   "r" , 21 ,    0 ,  0xffff     , 0x0000 ,   0 },
       { "data_buffer"           , 32 ,   "r" , 22 ,    0 ,  0xffffffff , 0x0000 ,   0 },
       { "energy_sum"            , 16 ,   "r" , 23 ,    0 ,  0xffff     , 0x0000 ,   0 },
       { "trigger_threshold"     , 16 ,  "rw" , 24 ,    0 ,  0xffff     , 0x0000 ,   0 },
       { "plv1_scan_en"          ,  1 ,  "rw" , 25 ,    0 ,  0x0001     , 0x0000 ,   0 },
       { "dp_chain_en"           ,  1 ,  "rw" , 25 ,    1 ,  0x0002     , 0x0000 ,   0 },
       { "last_slot"             ,  1 ,  "rw" , 25 ,    2 ,  0x0004     , 0x0000 ,   0 },
       { "first_adc"             ,  1 ,  "rw" , 25 ,    3 ,  0x0008     , 0x0000 ,   0 },
       { "lckrefn_l1"            ,  1 ,  "rw" , 25 ,    4 ,  0x0010     , 0x0000 ,   1 },
       { "lckrefn_l2"            ,  1 ,  "rw" , 25 ,    5 ,  0x0020     , 0x0000 ,   1 },

       { "trigger_timing_mode"   ,  1 ,  "rw" , 25 ,    6 ,  0x0040     , 0x0000 ,   0 },
       { "err_sel"               ,  2 ,  "rw" , 25 ,    7 ,  0x0180     , 0x0000 ,   0 },
       { "spill_count_clear"     ,  1 ,  "rw" , 25 ,    9 ,  0x0200     , 0x0000 ,   0 },
       { "trig_count_rst"        ,  1 ,  "rw" , 25 ,   10 ,  0x0400     , 0x0000 ,   0 },
       { "ped_track_en"          ,  1 ,  "rw" , 25 ,   11 ,  0x0800     , 0x0000 ,   0 },
       { "pulse_mode"            ,  1 ,  "rw" , 25 ,   12 ,  0x1000     , 0x0000 ,   0 },
       { "not_empty_signal"      ,  1 ,  "rw" , 25 ,   13 ,  0x2000     , 0x0000 ,   0 },
       { "lp_driver"             ,  1 ,  "rw" , 25 ,   14 ,  0x4000     , 0x0000 ,   0 },
       { "lp_driver_3p125"       ,  1 ,  "rw" , 25 ,   15 ,  0x8000     , 0x0000 ,   0 },
       { "code_revision"         , 16 ,  "r"  , 26 ,    0 ,  0xffff     , 0x0000 ,   0 },
       { "ped_choose"            , 16 ,  "rw" , 27 ,    0 ,  0xffff     , 0x0000 ,   0 },
       { "channel_force"         , 16 ,  "rw" , 28 ,    0 ,  0xffff     , 0x0000 ,   0 },
       { "spill_count"           , 16 ,   "r" , 29 ,    0 ,  0xffff     , 0x0000 ,   0 },
       { "delay_cb_readout"      ,  9 ,  "rw" , 30 ,    0 ,  0x1ff      , 0x0000 ,   0 },
       { "scalar_cnt_en"         ,  1 ,  "rw" , 31 ,    0 ,  0x4000     , 0x0000 ,   0 }, // adc500 only
       { "use_lossless"          ,  1 ,  "rw" , 31 ,    1 ,  0x0002     , 0x0000 ,   0 },
       { "veto_enable"           ,  1 ,  "rw" , 31 ,    2 ,  0x0004     , 0x0000 ,   0 },
       { "loopback_zero"         ,  1 ,  "rw" , 31 ,    3 ,  0x0008     , 0x0000 ,   0 },
       { "pulse_mode2"           ,  3 ,  "rw" , 31 ,    4 ,  0x0070     , 0x0000 ,   0 },
//       { "adc_delay"             ,  3 ,  "rw" , 31 ,    7 ,  0x0380     , 0x0000 ,   0 },
       { "use_zero"              ,  1 ,  "rw" , 31 ,    7 ,  0x0080     , 0x0000 ,   0 },
//       { "lvds_align"            ,  1 ,  "rw" , 31 ,    8 ,  0x0100     , 0x0000 ,   0 }, // v2275 up
       { "pL1A_en"               ,  1 ,  "rw" , 31 ,    9 ,  0x0200     , 0x0000 ,   0 }, // v2275 up
       { "delay_live_en"         ,  1 ,  "rw" , 31 ,   10 ,  0x0400     , 0x0000 ,   0 },
       { "track_ped_sel"         ,  1 ,  "rw" , 31 ,   11 ,  0x0800     , 0x0000 ,   0 },
       { "ena_daq_mode"          ,  1 ,  "rw" , 31 ,   12 ,  0x1000     , 0x0000 ,   0 },
       { "ena_selftrig"          ,  1 ,  "rw" , 31 ,   13 ,  0x2000     , 0x0000 ,   0 },
       { "ena_pedrecord"         ,  1 ,  "rw" , 31 ,   14 ,  0x4000     , 0x0000 ,   0 },
       { "compr_vme_rd"          ,  1 ,  "rw" , 31 ,   15 ,  0x8000     , 0x0000 ,   0 }, // v2063 and v2068 up
       { "cls_thr_0"             , 14 ,  "rw" , 32 ,    0 ,  0x3fff     , 0x0000 ,   0 }, // v2281 up
       { "cls_thr_1"             , 14 ,  "rw" , 32 ,   16 ,  0x3fff0000 , 0x0000 ,   0 }, // v2281 up
       { "cls_thr_2"             , 14 ,  "rw" , 33 ,    0 ,  0x3fff     , 0x0000 ,   0 }, // v2281 up
       { "cls_thr_3"             , 14 ,  "rw" , 33 ,   16 ,  0x3fff0000 , 0x0000 ,   0 }, // v2281 up
       { "cls_thr_4"             , 14 ,  "rw" , 34 ,    0 ,  0x3fff     , 0x0000 ,   0 }, // v2281 up
       { "cls_thr_5"             , 14 ,  "rw" , 34 ,   16 ,  0x3fff0000 , 0x0000 ,   0 }, // v2281 up
       { "cls_thr_6"             , 14 ,  "rw" , 35 ,    0 ,  0x3fff     , 0x0000 ,   0 }, // v2281 up
       { "cls_thr_7"             , 14 ,  "rw" , 35 ,   16 ,  0x3fff0000 , 0x0000 ,   0 }, // v2281 up
       { "cls_thr_8"             , 14 ,  "rw" , 36 ,    0 ,  0x3fff     , 0x0000 ,   0 }, // v2281 up
       { "cls_thr_9"             , 14 ,  "rw" , 36 ,   16 ,  0x3fff0000 , 0x0000 ,   0 }, // v2281 up
       { "cls_thr_10"            , 14 ,  "rw" , 37 ,    0 ,  0x3fff     , 0x0000 ,   0 }, // v2281 up
       { "cls_thr_11"            , 14 ,  "rw" , 37 ,   16 ,  0x3fff0000 , 0x0000 ,   0 }, // v2281 up
       { "cls_thr_12"            , 14 ,  "rw" , 38 ,    0 ,  0x3fff     , 0x0000 ,   0 }, // v2281 up
       { "cls_thr_13"            , 14 ,  "rw" , 38 ,   16 ,  0x3fff0000 , 0x0000 ,   0 }, // v2281 up
       { "cls_thr_14"            , 14 ,  "rw" , 39 ,    0 ,  0x3fff     , 0x0000 ,   0 }, // v2281 up
       { "cls_thr_15"            , 14 ,  "rw" , 39 ,   16 ,  0x3fff0000 , 0x0000 ,   0 }, // v2
       { "cls_mask_0"            ,  1 ,  "rw" , 32 ,   14 ,  0x4000     , 0x0000 ,   0 }, //
       { "cls_mask_1"            ,  1 ,  "rw" , 32 ,   30 ,  0x40000000 , 0x0000 ,   0 }, //
       { "cls_mask_2"            ,  1 ,  "rw" , 33 ,   14 ,  0x4000     , 0x0000 ,   0 }, //
       { "cls_mask_3"            ,  1 ,  "rw" , 33 ,   30 ,  0x40000000 , 0x0000 ,   0 }, //
       { "cls_mask_4"            ,  1 ,  "rw" , 34 ,   14 ,  0x4000     , 0x0000 ,   0 }, //
       { "cls_mask_5"            ,  1 ,  "rw" , 34 ,   30 ,  0x40000000 , 0x0000 ,   0 }, //
       { "cls_mask_6"            ,  1 ,  "rw" , 35 ,   14 ,  0x4000     , 0x0000 ,   0 }, //
       { "cls_mask_7"            ,  1 ,  "rw" , 35 ,   30 ,  0x40000000 , 0x0000 ,   0 }, //
       { "cls_mask_8"            ,  1 ,  "rw" , 36 ,   14 ,  0x4000     , 0x0000 ,   0 }, //
       { "cls_mask_9"            ,  1 ,  "rw" , 36 ,   30 ,  0x40000000 , 0x0000 ,   0 }, //
       { "cls_mask_10"           ,  1 ,  "rw" , 37 ,   14 ,  0x4000     , 0x0000 ,   0 }, //
       { "cls_mask_11"           ,  1 ,  "rw" , 37 ,   30 ,  0x40000000 , 0x0000 ,   0 }, //
       { "cls_mask_12"           ,  1 ,  "rw" , 38 ,   14 ,  0x4000     , 0x0000 ,   0 }, //
       { "cls_mask_13"           ,  1 ,  "rw" , 38 ,   30 ,  0x40000000 , 0x0000 ,   0 }, //
       { "cls_mask_14"           ,  1 ,  "rw" , 39 ,   14 ,  0x4000     , 0x0000 ,   0 }, //
       { "cls_mask_15"           ,  1 ,  "rw" , 39 ,   30 ,  0x40000000 , 0x0000 ,   0 }, //
       { "cls_simu_0"            ,  1 ,  "rw" , 32 ,   15 ,  0x8000     , 0x0000 ,   0 }, //
       { "cls_simu_1"            ,  1 ,  "rw" , 32 ,   31 ,  0x80000000 , 0x0000 ,   0 }, //
       { "cls_simu_2"            ,  1 ,  "rw" , 33 ,   15 ,  0x8000     , 0x0000 ,   0 }, //
       { "cls_simu_3"            ,  1 ,  "rw" , 33 ,   31 ,  0x80000000 , 0x0000 ,   0 }, //
       { "cls_simu_4"            ,  1 ,  "rw" , 34 ,   15 ,  0x8000     , 0x0000 ,   0 }, //
       { "cls_simu_5"            ,  1 ,  "rw" , 34 ,   31 ,  0x80000000 , 0x0000 ,   0 }, //
       { "cls_simu_6"            ,  1 ,  "rw" , 35 ,   15 ,  0x8000     , 0x0000 ,   0 }, //
       { "cls_simu_7"            ,  1 ,  "rw" , 35 ,   31 ,  0x80000000 , 0x0000 ,   0 }, //
       { "cls_simu_8"            ,  1 ,  "rw" , 36 ,   15 ,  0x8000     , 0x0000 ,   0 }, //
       { "cls_simu_9"            ,  1 ,  "rw" , 36 ,   31 ,  0x80000000 , 0x0000 ,   0 }, //
       { "cls_simu_10"           ,  1 ,  "rw" , 37 ,   15 ,  0x8000     , 0x0000 ,   0 }, //
       { "cls_simu_11"           ,  1 ,  "rw" , 37 ,   31 ,  0x80000000 , 0x0000 ,   0 }, //
       { "cls_simu_12"           ,  1 ,  "rw" , 38 ,   15 ,  0x8000     , 0x0000 ,   0 }, //
       { "cls_simu_13"           ,  1 ,  "rw" , 38 ,   31 ,  0x80000000 , 0x0000 ,   0 }, //
       { "cls_simu_14"           ,  1 ,  "rw" , 39 ,   15 ,  0x8000     , 0x0000 ,   0 }, //
       { "cls_simu_15"           ,  1 ,  "rw" , 39 ,   31 ,  0x80000000 , 0x0000 ,   0 }, // 

       { "veto_crate"            ,  1 ,  "rw" , 31 ,    8 ,  0x0100     , 0x0000 ,   0 },

       { "ps_thr_0"              ,  8 ,  "rw" , 40 ,    0 ,  0xFF       , 0x0000 ,   0 },
       { "ps_thr_1"              ,  8 ,  "rw" , 40 ,    8 ,  0xFF00     , 0x0000 ,   0 },
       { "ps_thr_2"              ,  8 ,  "rw" , 40 ,   16 ,  0xFF0000   , 0x0000 ,   0 },
       { "ps_thr_3"              ,  8 ,  "rw" , 40 ,   24 ,  0xFF000000 , 0x0000 ,   0 },

       { "ps_thr_4"              ,  8 ,  "rw" , 41 ,    0 ,  0xFF       , 0x0000 ,   0 },
       { "ps_thr_5"              ,  8 ,  "rw" , 41 ,    8 ,  0xFF00     , 0x0000 ,   0 },
       { "ps_thr_6"              ,  8 ,  "rw" , 41 ,   16 ,  0xFF0000   , 0x0000 ,   0 },
       { "ps_thr_7"              ,  8 ,  "rw" , 41 ,   24 ,  0xFF000000 , 0x0000 ,   0 },

       { "ps_thr_8"              ,  8 ,  "rw" , 42 ,    0 ,  0xFF       , 0x0000 ,   0 },
       { "ps_thr_9"              ,  8 ,  "rw" , 42 ,    8 ,  0xFF00     , 0x0000 ,   0 },
       { "ps_thr_10"             ,  8 ,  "rw" , 42 ,   16 ,  0xFF0000   , 0x0000 ,   0 },
       { "ps_thr_11"             ,  8 ,  "rw" , 42 ,   24 ,  0xFF000000 , 0x0000 ,   0 },

       { "ps_thr_12"             ,  8 ,  "rw" , 43 ,    0 ,  0xFF       , 0x0000 ,   0 },
       { "ps_thr_13"             ,  8 ,  "rw" , 43 ,    8 ,  0xFF00     , 0x0000 ,   0 },
       { "ps_thr_14"             ,  8 ,  "rw" , 43 ,   16 ,  0xFF0000   , 0x0000 ,   0 },
       { "ps_thr_15"             ,  8 ,  "rw" , 43 ,   24 ,  0xFF000000 , 0x0000 ,   0 },

       { "CB_tmin"               ,  6 ,  "rw" , 44 ,    0 ,  0x3F       , 0x0000 ,   0 },
       { "CB_tmax"               ,  6 ,  "rw" , 44 ,    6 ,  0xFC0      , 0x0000 ,   0 },
       { "CB_simu"               ,  1 ,  "rw" , 44 ,   12 ,  0x100      , 0x0000 ,   0 },
       { "CB_block_pl1a"         ,  8 ,  "rw" , 44 ,   13 ,  0x1FE000   , 0x0000 ,   0 },
       { "CB_delay"              ,  9 ,  "rw" , 44 ,   23 ,  0xFF800000 , 0x0000 ,   0 },
       { "LVDS_tx_sel"           ,  2 ,  "rw" , 44 ,   21 ,  0x600000   , 0x0000 ,   0 },
       { "rb_value"              , 32 ,  "rw" , 45 ,    0 ,  0xffffffff , 0x0000 ,   0 },
       { "maxt"                  ,  9 ,  "rw" , 46 ,    0 ,  0x1ff      , 0x0000 ,   0 },
       { "rb_addr"               ,  6 ,  "rw" , 46 ,    9 ,  0x7E00     , 0x0000 ,   0 },
       { "st_raddr"              ,  6 ,  "rw" , 46 ,   15 ,  0x1f8000   , 0x0000 ,   0 }, 
       { "pattern_tx"            , 16 ,  "rw" , 47 ,    0 ,  0xffff     , 0x0000 ,   0 },
       { "pattern_rx"            , 16 ,  "rw" , 47 ,   16 ,  0xffff0000 , 0x0000 ,   0 },
       { "trig_count_rst"        ,  1 ,  "rw" , 25 ,   10 ,  0x0400     , 0x0000 ,   0 },
       { "vme_addr"              ,  6 ,  "rw" , 46 ,   15 ,  0x1f8000   , 0x0000 ,   0 },
 
        { "END"                   ,  0 ,   "x" ,  0 ,    0 ,  0x0000     , 0x0000 ,   0 }
 };

  const Ctrl_Reg tcdt_reg[350]=
  {
//       Name                     Width  Type Address Start  Mask       Default  Present
//                                                     bit               Value    Value  // reg no.
        { "write_sim_data"        , 16 , "rw" , 0x04 ,   0 , 0xffff     , 0x0000 ,   0 }, //  1
        { "et_thre"               , 16 , "rw" , 0x04 ,  16 , 0xffff0000 , 0x0000 ,   0 }, //  1
        { "et_in_switch"          ,  1 , "rw" , 0x08 ,   0 , 0x1        , 0x0000 ,   0 }, //  2
        { "veto_in_switch"        ,  1 , "rw" , 0x08 ,   1 , 0x2        , 0x0000 ,   0 }, //  2
        { "fiber_sim_mem_switch"  ,  2 , "rw" , 0x08 ,   2 , 0xc        , 0x0000 ,   0 }, //  2
        { "live_mode"             ,  1 , "rw" , 0x08 ,   4 , 0x10       , 0x0000 ,   0 }, //  2
        { "ena_live_sim"          ,  1 , "rw" , 0x08 ,   5 , 0x20       , 0x0000 ,   0 }, //  2
        { "force_live_on"         ,  1 , "rw" , 0x08 ,   6 , 0x40       , 0x0000 ,   0 }, //  2
        { "trig_tag_out_switch"   ,  1 , "rw" , 0x08 ,   7 , 0x80       , 0x0000 ,   0 }, //  2
        { "peek_raw_pulse_flag"   ,  2 , "rw" , 0x08 ,   8 , 0x300      , 0x0000 ,   0 }, //  2
        //{ "lv1a_gen_gap"          , 10 , "rw" , 0x08 ,   8 , 0x3ff00    , 0x0000 ,   0 }, //  2
        { "nspill"                , 10 , "rw" , 0x08 ,  18 , 0xffc0000  , 0x01f4 ,   0 }, //  2
        { "bypass_tlk_err"        ,  1 , "rw" , 0x08 ,  28 , 0x10000000 , 0x0000 ,   0 }, //  2
        { "bypass_dc_err"         ,  1 , "rw" , 0x08 ,  29 , 0x20000000 , 0x0000 ,   0 }, //  2
        { "lvds_sim_mem_switch"   ,  2 , "rw" , 0x08 ,  30 , 0xc0000000 , 0x0000 ,   0 }, //  2

        { "write_sim_addr"        , 12 , "rw" , 0x0c ,   0 , 0xfff      , 0x0000 ,   0 }, //  3
        { "delay_lv1b_req"        ,  8 , "rw" , 0x0c ,  12 , 0xff000    , 0x0000 ,   0 }, //  3
        { "restrict_ntrig"        , 10 , "rw" , 0x0c ,  20 , 0x3ff00000 , 0x0000 ,   0 }, //  3
        { "ena_et_err_sim_trig"   ,  1 , "rw" , 0x0c ,  30 , 0x40000000 , 0x0000 ,   0 }, //  3
        { "et_err_in_switch"      ,  1 , "rw" , 0x0c ,  31 , 0x80000000 , 0x0000 ,   0 }, //  3
      
        { "delay_et_raw"          ,  9 , "rw" , 0x10 ,   0 , 0x1ff      , 0x015e ,   0 }, //  4
        { "delay_veto_raw"        ,  9 , "rw" , 0x10 ,   9 , 0x3fe00    , 0x015e ,   0 }, //  4
        { "fcdt_err_out_sw"       ,  2 , "rw" , 0x10 ,  18 , 0xc0000    , 0x0000 ,   0 }, //  4
        { "ena_delta_factory"     ,  1 , "rw" , 0x10 ,  20 , 0x100000   , 0x0000 ,   0 }, //  4
        { "ena_restrict_ntrig"    ,  1 , "rw" , 0x10 ,  21 , 0x200000   , 0x0000 ,   0 }, //  4
        { "ena_fiber_sim"         ,  1 , "rw" , 0x10 ,  22 , 0x400000   , 0x0000 ,   0 }, //  4
        { "et_latency_sim"        ,  9 , "rw" , 0x10 ,  23 , 0xff800000 , 0x012c ,   0 }, //  4
        { "veto_latency_sim"      ,  9 , "rw" , 0x14 ,   0 , 0x1ff      , 0x012c ,   0 }, //  5
        { "ena_lvds_cnt_debug"    ,  1 , "rw" , 0x14 ,   9 , 0x200      , 0x0000 ,   0 }, //  5
        { "ext_trig_in_switch"    ,  2 , "rw" , 0x14 ,  10 , 0xc00      , 0x0000 ,   0 }, //  5
        { "ena_ext_trig"          ,  4 , "rw" , 0x14 ,  12 , 0xf000     , 0x0000 ,   0 }, //  5
        { "ena_delta_lv1"         ,  1 , "rw" , 0x14 ,  16 , 0x10000    , 0x0000 ,   0 }, //  5
        { "ena_clock_trig"        ,  1 , "rw" , 0x14 ,  17 , 0x20000    , 0x0000 ,   0 }, //  5
        { "nclus_in_switch"       ,  1 , "rw" , 0x14 ,  18 , 0x40000    , 0x0000 ,   0 }, //  5
        { "nclus_simtrig_nwords"  ,  4 , "rw" , 0x14 ,  19 , 0x780000   , 0x0000 ,   0 }, //  5
        { "nclus_latency_sim"     ,  7 , "rw" , 0x14 ,  23 , 0x3f800000 , 0x0000 ,   0 }, //  5
        { "bypass_lv2_full"       ,  1 , "rw" , 0x14 ,  30 , 0x40000000 , 0x0000 ,   0 }, //  5
        { "rraw_sw"               ,  1 , "rw" , 0x14 ,  31 , 0x80000000 , 0x0000 ,   0 }, //  5


        { "jitter_cleaner"        ,  6 , "rw" , 0x18 ,  26 , 0xfc000000 , 0x0000 ,   0 }, //  6

        { "en_live_cleaner"       ,  1 , "rw" , 0x1c ,   0 , 0x1        , 0x0000 ,   0 }, //  7

        { "ena_olrx"              ,  4 , "rw" , 0x20 ,   0 , 0xf        , 0x0000 ,   0 }, //  8

        { "ext0_delay"            ,  8 , "rw" , 0x80 ,   0 , 0xff       , 0x0000 ,   0 }, // 20
        { "ext1_delay"            ,  8 , "rw" , 0x80 ,   8 , 0xff00     , 0x0000 ,   0 }, // 20
        { "ext2_delay"            ,  8 , "rw" , 0x80 ,  16 , 0xff0000   , 0x0000 ,   0 }, // 20
        { "ext3_delay"            ,  8 , "rw" , 0x80 ,  24 , 0xff000000 , 0x0000 ,   0 }, // 20 
        { "ext0_ena"              ,  1 , "rw" , 0x84 ,   0 , 0x1        , 0x0000 ,   0 }, // 21
        { "ext1_ena"              ,  1 , "rw" , 0x84 ,   1 , 0x2        , 0x0000 ,   0 }, // 21
        { "ext2_ena"              ,  1 , "rw" , 0x84 ,   2 , 0x4        , 0x0000 ,   0 }, // 21
        { "ext3_ena"              ,  1 , "rw" , 0x84 ,   3 , 0x8        , 0x0000 ,   0 }, // 21
        { "ext0_spill_on"         ,  1 , "rw" , 0x84 ,   4 , 0x10       , 0x0000 ,   0 }, // 21
        { "ext1_spill_on"         ,  1 , "rw" , 0x84 ,   5 , 0x20       , 0x0000 ,   0 }, // 21
        { "ext2_spill_on"         ,  1 , "rw" , 0x84 ,   6 , 0x40       , 0x0000 ,   0 }, // 21
        { "ext3_spill_on"         ,  1 , "rw" , 0x84 ,   7 , 0x80       , 0x0000 ,   0 }, // 21
        { "ext0_spill_off"        ,  1 , "rw" , 0x84 ,   8 , 0x100      , 0x0000 ,   0 }, // 21
        { "ext1_spill_off"        ,  1 , "rw" , 0x84 ,   9 , 0x200      , 0x0000 ,   0 }, // 21
        { "ext2_spill_off"        ,  1 , "rw" , 0x84 ,  10 , 0x400      , 0x0000 ,   0 }, // 21
        { "ext3_spill_off"        ,  1 , "rw" , 0x84 ,  11 , 0x800      , 0x0000 ,   0 }, // 21
        { "clock_trig_gap"        , 20 , "rw" , 0x84 ,  12 , 0xfffff000 , 0x0000 ,   0 }, // 21
        { "type0_et"              ,  1 , "rw" , 0x88 ,   0 , 0x1        , 0x0000 ,   0 }, // 22
        { "type1_et"              ,  1 , "rw" , 0x88 ,   1 , 0x2        , 0x0000 ,   0 }, // 22
        { "type2_et"              ,  1 , "rw" , 0x88 ,   2 , 0x4        , 0x0000 ,   0 }, // 22
        { "type3_et"              ,  1 , "rw" , 0x88 ,   3 , 0x8        , 0x0000 ,   0 }, // 22
        { "type4_et"              ,  1 , "rw" , 0x88 ,   4 , 0x10       , 0x0000 ,   0 }, // 22
        { "type5_et"              ,  1 , "rw" , 0x88 ,   5 , 0x20       , 0x0000 ,   0 }, // 22
        { "type6_et"              ,  1 , "rw" , 0x88 ,   6 , 0x40       , 0x0000 ,   0 }, // 22
        { "type7_et"              ,  1 , "rw" , 0x88 ,   7 , 0x80       , 0x0000 ,   0 }, // 22
        { "type0_and_or"          ,  1 , "rw" , 0x88 ,   8 , 0x100      , 0x0000 ,   0 }, // 22
        { "type1_and_or"          ,  1 , "rw" , 0x88 ,   9 , 0x200      , 0x0000 ,   0 }, // 22
        { "type2_and_or"          ,  1 , "rw" , 0x88 ,  10 , 0x400      , 0x0000 ,   0 }, // 22
        { "type3_and_or"          ,  1 , "rw" , 0x88 ,  11 , 0x800      , 0x0000 ,   0 }, // 22
        { "type4_and_or"          ,  1 , "rw" , 0x88 ,  12 , 0x1000     , 0x0000 ,   0 }, // 22
        { "type5_and_or"          ,  1 , "rw" , 0x88 ,  13 , 0x2000     , 0x0000 ,   0 }, // 22
        { "type6_and_or"          ,  1 , "rw" , 0x88 ,  14 , 0x4000     , 0x0000 ,   0 }, // 22
        { "type7_and_or"          ,  1 , "rw" , 0x88 ,  15 , 0x8000     , 0x0000 ,   0 }, // 22
        { "type0_ena"             ,  1 , "rw" , 0x88 ,  16 , 0x10000    , 0x0000 ,   0 }, // 22
        { "type1_ena"             ,  1 , "rw" , 0x88 ,  17 , 0x20000    , 0x0000 ,   0 }, // 22
        { "type2_ena"             ,  1 , "rw" , 0x88 ,  18 , 0x40000    , 0x0000 ,   0 }, // 22
        { "type3_ena"             ,  1 , "rw" , 0x88 ,  19 , 0x80000    , 0x0000 ,   0 }, // 22
        { "type4_ena"             ,  1 , "rw" , 0x88 ,  20 , 0x100000   , 0x0000 ,   0 }, // 22
        { "type5_ena"             ,  1 , "rw" , 0x88 ,  21 , 0x200000   , 0x0000 ,   0 }, // 22
        { "type6_ena"             ,  1 , "rw" , 0x88 ,  22 , 0x400000   , 0x0000 ,   0 }, // 22
        { "type7_ena"             ,  1 , "rw" , 0x88 ,  23 , 0x800000   , 0x0000 ,   0 }, // 22
        { "type0_spill_on"        ,  1 , "rw" , 0x88 ,  24 , 0x1000000  , 0x0000 ,   0 }, // 22
        { "type1_spill_on"        ,  1 , "rw" , 0x88 ,  25 , 0x2000000  , 0x0000 ,   0 }, // 22
        { "type2_spill_on"        ,  1 , "rw" , 0x88 ,  26 , 0x4000000  , 0x0000 ,   0 }, // 22
        { "type3_spill_on"        ,  1 , "rw" , 0x88 ,  27 , 0x8000000  , 0x0000 ,   0 }, // 22
        { "type4_spill_on"        ,  1 , "rw" , 0x88 ,  28 , 0x10000000 , 0x0000 ,   0 }, // 22
        { "type5_spill_on"        ,  1 , "rw" , 0x88 ,  29 , 0x20000000 , 0x0000 ,   0 }, // 22
        { "type6_spill_on"        ,  1 , "rw" , 0x88 ,  30 , 0x40000000 , 0x0000 ,   0 }, // 22
        { "type7_spill_on"        ,  1 , "rw" , 0x88 ,  31 , 0x80000000 , 0x0000 ,   0 }, // 22
        { "type0_spill_off"       ,  1 , "rw" , 0x8c ,   0 , 0x1        , 0x0000 ,   0 }, // 23
        { "type1_spill_off"       ,  1 , "rw" , 0x8c ,   1 , 0x2        , 0x0000 ,   0 }, // 23
        { "type2_spill_off"       ,  1 , "rw" , 0x8c ,   2 , 0x4        , 0x0000 ,   0 }, // 23
        { "type3_spill_off"       ,  1 , "rw" , 0x8c ,   3 , 0x8        , 0x0000 ,   0 }, // 23
        { "type4_spill_off"       ,  1 , "rw" , 0x8c ,   4 , 0x10       , 0x0000 ,   0 }, // 23
        { "type5_spill_off"       ,  1 , "rw" , 0x8c ,   5 , 0x20       , 0x0000 ,   0 }, // 23
        { "type6_spill_off"       ,  1 , "rw" , 0x8c ,   6 , 0x40       , 0x0000 ,   0 }, // 23
        { "type7_spill_off"       ,  1 , "rw" , 0x8c ,   7 , 0x80       , 0x0000 ,   0 }, // 23 
        { "type0_ps"              ,  1 , "rw" , 0x8c ,   8 , 0x100      , 0x0000 ,   0 }, // 23
        { "type1_ps"              ,  1 , "rw" , 0x8c ,   9 , 0x200      , 0x0000 ,   0 }, // 23
        { "type2_ps"              ,  1 , "rw" , 0x8c ,  10 , 0x400      , 0x0000 ,   0 }, // 23
        { "type3_ps"              ,  1 , "rw" , 0x8c ,  11 , 0x800      , 0x0000 ,   0 }, // 23
        { "type4_ps"              ,  1 , "rw" , 0x8c ,  12 , 0x1000     , 0x0000 ,   0 }, // 23
        { "type5_ps"              ,  1 , "rw" , 0x8c ,  13 , 0x2000     , 0x0000 ,   0 }, // 23
        { "type6_ps"              ,  1 , "rw" , 0x8c ,  14 , 0x4000     , 0x0000 ,   0 }, // 23
        { "type7_ps"              ,  1 , "rw" , 0x8c ,  15 , 0x8000     , 0x0000 ,   0 }, // 23
        { "delay_lv1"             ,  8 , "rw" , 0x8c ,  16 , 0xff0000   , 0x0000 ,   0 }, // 23
        /////
        { "type0_veto"            , 16 , "rw" , 0x90 ,   0 , 0xffff     , 0x0000 ,   0 }, // 24
        { "type0_veto_as_trig"    , 16 , "rw" , 0x90 ,  16 , 0xffff0000 , 0x0000 ,   0 }, // 24
        { "type1_veto"            , 16 , "rw" , 0x94 ,   0 , 0xffff     , 0x0000 ,   0 }, // 25
        { "type1_veto_as_trig"    , 16 , "rw" , 0x94 ,  16 , 0xffff0000 , 0x0000 ,   0 }, // 25
        { "type2_veto"            , 16 , "rw" , 0x98 ,   0 , 0xffff     , 0x0000 ,   0 }, // 26
        { "type2_veto_as_trig"    , 16 , "rw" , 0x98 ,  16 , 0xffff0000 , 0x0000 ,   0 }, // 26
        { "type3_veto"            , 16 , "rw" , 0x9c ,   0 , 0xffff     , 0x0000 ,   0 }, // 27
        { "type3_veto_as_trig"    , 16 , "rw" , 0x9c ,  16 , 0xffff0000 , 0x0000 ,   0 }, // 27
        { "type4_veto"            , 16 , "rw" , 0xa0 ,   0 , 0xffff     , 0x0000 ,   0 }, // 28
        { "type4_veto_as_trig"    , 16 , "rw" , 0xa0 ,  16 , 0xffff0000 , 0x0000 ,   0 }, // 28
        { "type5_veto"            , 16 , "rw" , 0xa4 ,   0 , 0xffff     , 0x0000 ,   0 }, // 29
        { "type5_veto_as_trig"    , 16 , "rw" , 0xa4 ,  16 , 0xffff0000 , 0x0000 ,   0 }, // 29
        { "type6_veto"            , 16 , "rw" , 0xc0 ,   0 , 0xffff     , 0x0000 ,   0 }, // 30
        { "type6_veto_as_trig"    , 16 , "rw" , 0xc0 ,  16 , 0xffff0000 , 0x0000 ,   0 }, // 30
        { "type7_veto"            , 16 , "rw" , 0xc4 ,   0 , 0xffff     , 0x0000 ,   0 }, // 31
        { "type7_veto_as_trig"    , 16 , "rw" , 0xc4 ,  16 , 0xffff0000 , 0x0000 ,   0 }, // 31
        { "type0_nclus"           , 10 , "rw" , 0xc8 ,   0 , 0x3ff      , 0x0000 ,   0 }, // 32
        { "type0_lv1b_prescale_p" , 10 , "rw" , 0xc8 ,  10 , 0xffc00    , 0x0000 ,   0 }, // 32
        { "type0_lv1b_prescale_q" , 12 , "rw" , 0xc8 ,  20 , 0xfff00000 , 0x0000 ,   0 }, // 32
        { "type1_nclus"           , 10 , "rw" , 0xcc ,   0 , 0x3ff      , 0x0000 ,   0 }, // 33
        { "type1_lv1b_prescale_p" , 10 , "rw" , 0xcc ,  10 , 0xffc00    , 0x0000 ,   0 }, // 33
        { "type1_lv1b_prescale_q" , 12 , "rw" , 0xcc ,  20 , 0xfff00000 , 0x0000 ,   0 }, // 33
        { "type2_nclus"           , 10 , "rw" , 0xd0 ,   0 , 0x3ff      , 0x0000 ,   0 }, // 34
        { "type2_lv1b_prescale_p" , 10 , "rw" , 0xd0 ,  10 , 0xffc00    , 0x0000 ,   0 }, // 34
        { "type2_lv1b_prescale_q" , 12 , "rw" , 0xd0 ,  20 , 0xfff00000 , 0x0000 ,   0 }, // 34
        { "type3_nclus"           , 10 , "rw" , 0xd4 ,   0 , 0x3ff      , 0x0000 ,   0 }, // 35
        { "type3_lv1b_prescale_p" , 10 , "rw" , 0xd4 ,  10 , 0xffc00    , 0x0000 ,   0 }, // 35
        { "type3_lv1b_prescale_q" , 12 , "rw" , 0xd4 ,  20 , 0xfff00000 , 0x0000 ,   0 }, // 35
        { "type4_nclus"           , 10 , "rw" , 0xd8 ,   0 , 0x3ff      , 0x0000 ,   0 }, // 36
        { "type4_lv1b_prescale_p" , 10 , "rw" , 0xd8 ,  10 , 0xffc00    , 0x0000 ,   0 }, // 36
        { "type4_lv1b_prescale_q" , 12 , "rw" , 0xd8 ,  20 , 0xfff00000 , 0x0000 ,   0 }, // 36
        { "type5_nclus"           , 10 , "rw" , 0xdc ,   0 , 0x3ff      , 0x0000 ,   0 }, // 37
        { "type5_lv1b_prescale_p" , 10 , "rw" , 0xdc ,  10 , 0xffc00    , 0x0000 ,   0 }, // 37
        { "type5_lv1b_prescale_q" , 12 , "rw" , 0xdc ,  20 , 0xfff00000 , 0x0000 ,   0 }, // 37
        { "type6_nclus"           , 10 , "rw" , 0xe0 ,   0 , 0x3ff      , 0x0000 ,   0 }, // 38
        { "type6_lv1b_prescale_p" , 10 , "rw" , 0xe0 ,  10 , 0xffc00    , 0x0000 ,   0 }, // 38
        { "type6_lv1b_prescale_q" , 12 , "rw" , 0xe0 ,  20 , 0xfff00000 , 0x0000 ,   0 }, // 38
        { "type7_nclus"           , 10 , "rw" , 0xe4 ,   0 , 0x3ff      , 0x0000 ,   0 }, // 39
        { "type7_lv1b_prescale_p" , 10 , "rw" , 0xe4 ,  10 , 0xffc00    , 0x0000 ,   0 }, // 39
        { "type7_lv1b_prescale_q" , 12 , "rw" , 0xe4 ,  20 , 0xfff00000 , 0x0000 ,   0 }, // 39
        { "send_factory_trig"     ,  1 , "rw" , 0x100,   0 , 0x1        , 0x0000 ,   0 }, // 40
        { "factory_trig_ptn"      ,  3 , "rw" , 0x100,   1 , 0xe        , 0x0000 ,   0 }, // 40
        { "factory_trig_gap"      , 12 , "rw" , 0x100,   4 , 0xfff0     , 0x0000 ,   0 }, // 40
        { "factory_ntrig"         , 16 , "rw" , 0x100,  16 , 0xffff0000 , 0x0000 ,   0 }, // 40
        { "delta_et_thre"         , 16 , "rw" , 0x104,   0 , 0x0000ffff , 0x0000 ,   0 }, // 41
        { "delta_veto_ptn"        , 16 , "rw" , 0x104,  16 , 0xffff0000 , 0x0000 ,   0 }, // 41
        { "type0_lv1a_prescale_p" , 16 , "rw" , 0x108,   0 , 0x0000ffff , 0x0000 ,   0 }, // 42
        { "type0_lv1a_prescale_q" , 16 , "rw" , 0x108,  16 , 0xffff0000 , 0x0000 ,   0 }, // 42
        { "type1_lv1a_prescale_p" , 16 , "rw" , 0x10c,   0 , 0x0000ffff , 0x0000 ,   0 }, // 43
        { "type1_lv1a_prescale_q" , 16 , "rw" , 0x10c,  16 , 0xffff0000 , 0x0000 ,   0 }, // 43
        { "type2_lv1a_prescale_p" , 16 , "rw" , 0x110,   0 , 0x0000ffff , 0x0000 ,   0 }, // 44
        { "type2_lv1a_prescale_q" , 16 , "rw" , 0x110,  16 , 0xffff0000 , 0x0000 ,   0 }, // 44
        { "type3_lv1a_prescale_p" , 16 , "rw" , 0x114,   0 , 0x0000ffff , 0x0000 ,   0 }, // 45
        { "type3_lv1a_prescale_q" , 16 , "rw" , 0x114,  16 , 0xffff0000 , 0x0000 ,   0 }, // 45
        { "type4_lv1a_prescale_p" , 16 , "rw" , 0x118,   0 , 0x0000ffff , 0x0000 ,   0 }, // 46
        { "type4_lv1a_prescale_q" , 16 , "rw" , 0x118,  16 , 0xffff0000 , 0x0000 ,   0 }, // 46
        { "type5_lv1a_prescale_p" , 16 , "rw" , 0x11c,   0 , 0x0000ffff , 0x0000 ,   0 }, // 47
        { "type5_lv1a_prescale_q" , 16 , "rw" , 0x11c,  16 , 0xffff0000 , 0x0000 ,   0 }, // 47
        { "type6_lv1a_prescale_p" , 16 , "rw" , 0x120,   0 , 0x0000ffff , 0x0000 ,   0 }, // 48
        { "type6_lv1a_prescale_q" , 16 , "rw" , 0x120,  16 , 0xffff0000 , 0x0000 ,   0 }, // 48
        { "type7_lv1a_prescale_p" , 16 , "rw" , 0x124,   0 , 0x0000ffff , 0x0000 ,   0 }, // 49
        { "type7_lv1a_prescale_q" , 16 , "rw" , 0x124,  16 , 0xffff0000 , 0x0000 ,   0 }, // 49
        { "wraw_trig_time"        , 32 , "rw" , 0x140,  32 , 0xffffffff , 0x0000 ,   0 }, // 50
        { "delta_factory_gap"     , 32 , "rw" , 0x144,  32 , 0xffffffff , 0x0000 ,   0 }, // 51
        { "spill_off_time"        , 32 , "rw" , 0x148,  32 , 0xffffffff , 0x0000 ,   0 }, // 52
        { "live_period"           , 32 , "rw" , 0x14c,  32 , 0xffffffff , 0x0000 ,   0 }, // 53
        { "live_on_period"        , 32 , "rw" , 0x150, 32 , 0xffffffff , 0x0000 ,   0 }, // 54

        /// only supported by v26 or above
        { "new_type0_ps"          ,  1 , "rw" , 0x154,   0 , 0x1        , 0x0000 ,   0 }, // 55
        { "new_type1_ps"          ,  1 , "rw" , 0x154,   1 , 0x2        , 0x0000 ,   0 }, // 55
        { "new_type2_ps"          ,  1 , "rw" , 0x154,   2 , 0x4        , 0x0000 ,   0 }, // 55
        { "new_type3_ps"          ,  1 , "rw" , 0x154,   3 , 0x8        , 0x0000 ,   0 }, // 55
        { "new_type4_ps"          ,  1 , "rw" , 0x154,   4 , 0x10       , 0x0000 ,   0 }, // 55
        { "new_type5_ps"          ,  1 , "rw" , 0x154,   5 , 0x20       , 0x0000 ,   0 }, // 55
        { "new_type6_ps"          ,  1 , "rw" , 0x154,   6 , 0x40       , 0x0000 ,   0 }, // 55
        { "new_type7_ps"          ,  1 , "rw" , 0x154,   7 , 0x80       , 0x0000 ,   0 }, // 55
        { "ext0_ps"               ,  1 , "rw" , 0x154,   8 , 0x100      , 0x0000 ,   0 }, // 55
        { "ext1_ps"               ,  1 , "rw" , 0x154,   9 , 0x200      , 0x0000 ,   0 }, // 55
        { "ext2_ps"               ,  1 , "rw" , 0x154,  10 , 0x400      , 0x0000 ,   0 }, // 55
        { "ext3_ps"               ,  1 , "rw" , 0x154,  11 , 0x800      , 0x0000 ,   0 }, // 55
        //
        { "lv1_copy_delay"        ,  8 , "rw" , 0x154,  16 , 0xff0000   , 0x0000 ,   0 }, // 55
        { "lv1_copy_en"           ,  1 , "rw" , 0x154,  31 , 0x80000000 , 0x0000 ,   0 }, // 55
        //        
        { "lv1_copy_prescale"     ,  8 , "rw" , 0x158,   0 , 0xff       , 0x0001 ,   0 }, // 56


        ///////////////////////////////
        /////// status register ///////
        ///////////////////////////////

        { "spill_count"           , 10 ,  "r" , 0x28 ,   0 , 0x3ff      , 0x0000 ,   0 }, //  0
        { "live"                  ,  1 ,  "r" , 0x28 ,  10 , 0x400      , 0x0000 ,   0 }, //  0
        { "tlk_err"               ,  1 ,  "r" , 0x28 ,  11 , 0x800      , 0x0000 ,   0 }, //  0
        { "local_align_err"       ,  1 ,  "r" , 0x28 ,  12 , 0x1000     , 0x0000 ,   0 }, //  0
        { "dc_err"                ,  1 ,  "r" , 0x28 ,  13 , 0x2000     , 0x0000 ,   0 }, //  0
        { "delay_et_align_ptn"    ,  9 ,  "r" , 0x28 ,  14 , 0x7fc000   , 0x0000 ,   0 }, //  0
        { "delay_veto_align_ptn"  ,  9 ,  "r" , 0x28 ,  23 , 0xff800000 , 0x0000 ,   0 }, //  0
        { "olrx_err"              ,  4 ,  "r" , 0x2c ,   0 , 0xf        , 0x0000 ,   0 }, //  1
        { "got_olrx_err"          ,  4 ,  "r" , 0x2c ,   4 , 0xf0       , 0x0000 ,   0 }, //  1
        { "got_et_tlk_err"        ,  1 ,  "r" , 0x2c ,   8 , 0x1f0      , 0x0000 ,   0 }, //  1
        { "got_et_dc_err"         ,  1 ,  "r" , 0x2c ,   9 , 0x2f0      , 0x0000 ,   0 }, //  1
        { "is_et_tlk_err"         ,  1 ,  "r" , 0x2c ,  10 , 0x4f0      , 0x0000 ,   0 }, //  1
        { "is_et_dc_err"          ,  1 ,  "r" , 0x2c ,  11 , 0x8f0      , 0x0000 ,   0 }, //  1
        { "got_et_ofc_tlk_err"    ,  1 ,  "r" , 0x2c ,  12 , 0x1000     , 0x0000 ,   0 }, //  1
        { "got_et_ofc_dc_err"     ,  1 ,  "r" , 0x2c ,  13 , 0x2000     , 0x0000 ,   0 }, //  1
        { "peek_et_peak"          ,  1 ,  "r" , 0x2c ,  14 , 0x4000     , 0x0000 ,   0 }, //  1
        { "clus_id_err"           ,  1 ,  "r" , 0x2c ,  15 , 0x8000     , 0x0000 ,   0 }, //  1
        { "got_clus_ofc_tlk_err"  ,  1 ,  "r" , 0x2c ,  16 , 0x10000    , 0x0000 ,   0 }, //  1
        { "is_clus_ofc_tlk_err"   ,  1 ,  "r" , 0x2c ,  17 , 0x20000    , 0x0000 ,   0 }, //  1
        { "got_veto_err"          ,  1 ,  "r" , 0x2c ,  18 , 0x40000    , 0x0000 ,   0 }, //  1
        { "is_veto_err"           ,  1 ,  "r" , 0x2c ,  19 , 0x80000    , 0x0000 ,   0 }, //  1
        { "is_et_ofc_tlk_err"     ,  1 ,  "r" , 0x2c ,  20 , 0x100000   , 0x0000 ,   0 }, //  1
        { "is_et_ofc_dc_err"      ,  1 ,  "r" , 0x2c ,  21 , 0x200000   , 0x0000 ,   0 }, //  1
        { "global_align_err"      ,  1 ,  "r" , 0x2c ,  22 , 0x400000   , 0x0000 ,   0 }, //  1     
        { "delay_clus_result"     ,  9 ,  "r" , 0x2c ,  23 , 0xff800000 , 0x0000 ,   0 }, //  1
        { "lv1_cnt"               , 20 ,  "r" , 0x30 ,   0 , 0xfffff    , 0x0000 ,   0 }, //  2
        { "et_delta_lv1a_t"       ,  9 ,  "r" , 0x30 ,  20 , 0x1ff00000 , 0x0000 ,   0 }, //  2
        { "clus_time_err"         ,  1 ,  "r" , 0x30 ,  29 , 0x20000000 , 0x0000 ,   0 }, //  2
        { "clus_delta_err"        ,  1 ,  "r" , 0x30 ,  30 , 0x40000000 , 0x0000 ,   0 }, //  2
        { "lv2_buff_full"         ,  1 ,  "r" , 0x30 ,  31 , 0x80000000 , 0x0000 ,   0 }, //  2
        { "lv2_rej_cnt"           , 32 ,  "r" , 0x34 ,   0 , 0xffffffff , 0x0000 ,   0 }, //  3 
        { "lv1a_raw_cnt"          , 32 ,  "r" , 0x38 ,   0 , 0xffffffff , 0x0000 ,   0 }, //  4  
        { "delay_et_delta_ptn"    ,  9 ,  "r" , 0x400,   0 , 0x1ff      , 0x0000 ,   0 }, //100
        { "delay_veto_delta_ptn"  ,  9 ,  "r" , 0x400,   9 , 0x3fe00    , 0x0000 ,   0 }, //100
        { "veto_delta_lv1a_t"     ,  9 ,  "r" , 0x400,  18 , 0x7fc0000  , 0x0000 ,   0 }, //100
        ///
        { "exdata0"               , 32 ,  "r" , 0x404,   0 , 0xffffffff , 0x0000 ,   0 }, //101
        { "exdata1"               , 32 ,  "r" , 0x408,   0 , 0xffffffff , 0x0000 ,   0 }, //102
        { "veto0_cnt"             , 32 ,  "r" , 0x40c,  32 , 0xffffffff , 0x0000 ,   0 }, //103
        { "ext0_cnt"              , 16 ,  "r" , 0x410,   0 , 0xffff     , 0x0000 ,   0 }, //104
        { "ext1_cnt"              , 16 ,  "r" , 0x410,  16 , 0xffff0000 , 0x0000 ,   0 }, //104
        { "ext2_cnt"              , 16 ,  "r" , 0x414,   0 , 0xffff     , 0x0000 ,   0 }, //105
        { "ext3_cnt"              , 16 ,  "r" , 0x414,  16 , 0xfff0000  , 0x0000 ,   0 }, //105
        { "lv1a_rej_cnt"          , 32 ,  "r" , 0x418,   0 , 0xffffffff , 0x0000 ,   0 }, //106
        { "raw_clus0_cnt"         , 16 ,  "r" , 0x41c,   0 , 0xffff     , 0x0000 ,   0 }, //107
        { "raw_clus1_cnt"         , 16 ,  "r" , 0x41c,  16 , 0xffff0000 , 0x0000 ,   0 }, //107
        { "raw_clus2_cnt"         , 16 ,  "r" , 0x420,   0 , 0xffff     , 0x0000 ,   0 }, //108
        { "raw_clus3_cnt"         , 16 ,  "r" , 0x420,  16 , 0xffff0000 , 0x0000 ,   0 }, //108
        { "raw_clus4_cnt"         , 16 ,  "r" , 0x424,   0 , 0xffff     , 0x0000 ,   0 }, //109
        { "raw_clus5_cnt"         , 16 ,  "r" , 0x424,  16 , 0xffff0000 , 0x0000 ,   0 }, //109
        { "raw_clus6_cnt"         , 16 ,  "r" , 0x440,   0 , 0xffff     , 0x0000 ,   0 }, //110
        { "raw_clus7_cnt"         , 16 ,  "r" , 0x440,  16 , 0xffff0000 , 0x0000 ,   0 }, //110
        { "raw_clus8_cnt"         , 16 ,  "r" , 0x444,   0 , 0xffff     , 0x0000 ,   0 }, //111
        { "raw_clusN_cnt"         , 16 ,  "r" , 0x444,  16 , 0xffff0000 , 0x0000 ,   0 }, //111
        { "type0_lv1b_raw_cnt"    , 32 ,  "r" , 0x448,   0 , 0xffffffff , 0x0000 ,   0 }, //112
        { "type1_lv1b_raw_cnt"    , 32 ,  "r" , 0x44c,   0 , 0xffffffff , 0x0000 ,   0 }, //113
        { "type2_lv1b_raw_cnt"    , 32 ,  "r" , 0x450,   0 , 0xffffffff , 0x0000 ,   0 }, //114
        { "type3_lv1b_raw_cnt"    , 32 ,  "r" , 0x454,   0 , 0xffffffff , 0x0000 ,   0 }, //115
        { "type4_lv1b_raw_cnt"    , 32 ,  "r" , 0x458,   0 , 0xffffffff , 0x0000 ,   0 }, //116
        { "type5_lv1b_raw_cnt"    , 32 ,  "r" , 0x45c,   0 , 0xffffffff , 0x0000 ,   0 }, //117
        { "type6_lv1b_raw_cnt"    , 32 ,  "r" , 0x460,   0 , 0xffffffff , 0x0000 ,   0 }, //118
        { "type7_lv1b_raw_cnt"    , 32 ,  "r" , 0x464,   0 , 0xffffffff , 0x0000 ,   0 }, //119
        { "et_ofc_tlk_err_bus"    , 18 ,  "r" , 0x480,   0 , 0x3ffff    , 0x0000 ,   0 }, //120

        { "et_ofc_dc_err_bus"     , 18 ,  "r" , 0x484,   0 , 0x3ffff    , 0x0000 ,   0 }, //121
        { "lv1_delay"             , 10 ,  "r" , 0x484,  18 , 0xffc0000  , 0x0000 ,   0 }, //121

        { "clus_ofc_tlk_err_bus"  , 18 ,  "r" , 0x488,   0 , 0x3ffff    , 0x0000 ,   0 }, //122

        { "veto1_cnt"             , 32 ,  "r" , 0x48c,   0 , 0xffffffff , 0x0000 ,   0 }, //123
        { "veto2_cnt"             , 32 ,  "r" , 0x490,   0 , 0xffffffff , 0x0000 ,   0 }, //124
        { "veto3_cnt"             , 32 ,  "r" , 0x494,   0 , 0xffffffff , 0x0000 ,   0 }, //125
        { "veto4_cnt"             , 32 ,  "r" , 0x498,   0 , 0xffffffff , 0x0000 ,   0 }, //126
        { "veto5_cnt"             , 32 ,  "r" , 0x49c,   0 , 0xffffffff , 0x0000 ,   0 }, //127
        { "veto6_cnt"             , 32 ,  "r" , 0x4a0,   0 , 0xffffffff , 0x0000 ,   0 }, //128
        { "veto7_cnt"             , 32 ,  "r" , 0x4a4,   0 , 0xffffffff , 0x0000 ,   0 }, //129
        { "veto8_cnt"             , 32 ,  "r" , 0x4c0,   0 , 0xffffffff , 0x0000 ,   0 }, //130
        { "scaled_clus0_cnt"      , 16 ,  "r" , 0x4c4,   0 , 0xffff     , 0x0000 ,   0 }, //131
        { "scaled_clus1_cnt"      , 16 ,  "r" , 0x4c4,  16 , 0xffff0000 , 0x0000 ,   0 }, //131
        { "scaled_clus2_cnt"      , 16 ,  "r" , 0x4c8,   0 , 0xffff     , 0x0000 ,   0 }, //132
        { "scaled_clus3_cnt"      , 16 ,  "r" , 0x4c8,  16 , 0xffff0000 , 0x0000 ,   0 }, //132
        { "scaled_clus4_cnt"      , 16 ,  "r" , 0x4cc,   0 , 0xffff     , 0x0000 ,   0 }, //133
        { "scaled_clus5_cnt"      , 16 ,  "r" , 0x4cc,  16 , 0xffff0000 , 0x0000 ,   0 }, //133
        { "scaled_clus6_cnt"      , 16 ,  "r" , 0x4d0,   0 , 0xffff     , 0x0000 ,   0 }, //134
        { "scaled_clus7_cnt"      , 16 ,  "r" , 0x4d0,  16 , 0xffff0000 , 0x0000 ,   0 }, //134
        { "scaled_clus8_cnt"      , 16 ,  "r" , 0x4d4,   0 , 0xffff     , 0x0000 ,   0 }, //135
        { "scaled_clusN_cnt"      , 16 ,  "r" , 0x4d4,  16 , 0xffff0000 , 0x0000 ,   0 }, //135
        { "lvds0_err_cnt"         , 16 ,  "r" , 0x4d8,   0 , 0xffff     , 0x0000 ,   0 }, //136
        { "lvds1_err_cnt"         , 16 ,  "r" , 0x4d8,  16 , 0xffff0000 , 0x0000 ,   0 }, //136
        { "lvds2_err_cnt"         , 16 ,  "r" , 0x4dc,   0 , 0xffff     , 0x0000 ,   0 }, //137
        { "lvds3_err_cnt"         , 16 ,  "r" , 0x4dc,  16 , 0xffff0000 , 0x0000 ,   0 }, //137
        { "veto9_cnt"             , 32 ,  "r" , 0x4e0,   0 , 0xffffffff , 0x0000 ,   0 }, //138
        { "veto10_cnt"            , 32 ,  "r" , 0x4e4,   0 , 0xffffffff , 0x0000 ,   0 }, //139
        { "veto11_cnt"            , 32 ,  "r" , 0x500,   0 , 0xffffffff , 0x0000 ,   0 }, //140
        { "veto12_cnt"            , 32 ,  "r" , 0x504,   0 , 0xffffffff , 0x0000 ,   0 }, //141
        { "veto13_cnt"            , 32 ,  "r" , 0x508,   0 , 0xffffffff , 0x0000 ,   0 }, //142
        { "veto14_cnt"            , 32 ,  "r" , 0x50c,   0 , 0xffffffff , 0x0000 ,   0 }, //143
        { "veto15_cnt"            , 32 ,  "r" , 0x510,   0 , 0xffffffff , 0x0000 ,   0 }, //144
        { "delta_et_raw"          , 16 ,  "r" , 0x514,   0 , 0x0000ffff , 0x0000 ,   0 }, //145
        { "delta_veto_raw"        , 16 ,  "r" , 0x514,  16 , 0xffff0000 , 0x0000 ,   0 }, //145
        { "ndelta"                , 16 ,  "r" , 0x518,   0 , 0x0000ffff , 0x0000 ,   0 }, //146
        ////
        { "peek_et_raw"           , 16 ,  "r" , 0x51c,   0 , 0x0000ffff , 0x0000 ,   0 }, //147
        { "peek_veto_raw"         , 16 ,  "r" , 0x51c,  16 , 0xffff0000 , 0x0000 ,   0 }, //147
        { "lv1a_cnt"              , 32 ,  "r" , 0x520,   0 , 0xffffffff , 0x0000 ,   0 }, //148
        { "type0_lv1a_raw_cnt"    , 32 ,  "r" , 0x540,   0 , 0xffffffff , 0x0000 ,   0 }, //150
        { "type0_lv1a_scaled_cnt" , 32 ,  "r" , 0x544,   0 , 0xffffffff , 0x0000 ,   0 }, //151
        { "type1_lv1a_raw_cnt"    , 32 ,  "r" , 0x548,   0 , 0xffffffff , 0x0000 ,   0 }, //152
        { "type1_lv1a_scaled_cnt" , 32 ,  "r" , 0x54c,   0 , 0xffffffff , 0x0000 ,   0 }, //153
        { "type2_lv1a_raw_cnt"    , 32 ,  "r" , 0x550,   0 , 0xffffffff , 0x0000 ,   0 }, //154
        { "type2_lv1a_scaled_cnt" , 32 ,  "r" , 0x554,   0 , 0xffffffff , 0x0000 ,   0 }, //155
        { "type3_lv1a_raw_cnt"    , 32 ,  "r" , 0x558,   0 , 0xffffffff , 0x0000 ,   0 }, //156
        { "type3_lv1a_scaled_cnt" , 32 ,  "r" , 0x55c,   0 , 0xffffffff , 0x0000 ,   0 }, //157
        { "type4_lv1a_raw_cnt"    , 32 ,  "r" , 0x560,   0 , 0xffffffff , 0x0000 ,   0 }, //158
        { "type4_lv1a_scaled_cnt" , 32 ,  "r" , 0x564,   0 , 0xffffffff , 0x0000 ,   0 }, //159
        { "type5_lv1a_raw_cnt"    , 32 ,  "r" , 0x580,   0 , 0xffffffff , 0x0000 ,   0 }, //160
        { "type5_lv1a_scaled_cnt" , 32 ,  "r" , 0x584,   0 , 0xffffffff , 0x0000 ,   0 }, //161
        { "type6_lv1a_raw_cnt"    , 32 ,  "r" , 0x588,   0 , 0xffffffff , 0x0000 ,   0 }, //162
        { "type6_lv1a_scaled_cnt" , 32 ,  "r" , 0x58c,   0 , 0xffffffff , 0x0000 ,   0 }, //163
        { "type7_lv1a_raw_cnt"    , 32 ,  "r" , 0x590,   0 , 0xffffffff , 0x0000 ,   0 }, //164
        { "type7_lv1a_scaled_cnt" , 32 ,  "r" , 0x594,   0 , 0xffffffff , 0x0000 ,   0 }, //165
        { "type0_lv1b_scaled_cnt" , 32 ,  "r" , 0x598,   0 , 0xffffffff , 0x0000 ,   0 }, //166
        { "type1_lv1b_scaled_cnt" , 32 ,  "r" , 0x59c,   0 , 0xffffffff , 0x0000 ,   0 }, //167
        { "type2_lv1b_scaled_cnt" , 32 ,  "r" , 0x5a0,   0 , 0xffffffff , 0x0000 ,   0 }, //168
        { "type3_lv1b_scaled_cnt" , 32 ,  "r" , 0x5a4,   0 , 0xffffffff , 0x0000 ,   0 }, //169
        { "type4_lv1b_scaled_cnt" , 32 ,  "r" , 0x5c0,   0 , 0xffffffff , 0x0000 ,   0 }, //170
        { "type5_lv1b_scaled_cnt" , 32 ,  "r" , 0x5c4,   0 , 0xffffffff , 0x0000 ,   0 }, //171
        { "type6_lv1b_scaled_cnt" , 32 ,  "r" , 0x5c8,   0 , 0xffffffff , 0x0000 ,   0 }, //172
        { "type7_lv1b_scaled_cnt" , 32 ,  "r" , 0x5cc,   0 , 0xffffffff , 0x0000 ,   0 }, //173
        { "lv1_ps_cnt"            , 32 ,  "r" , 0x5d0,   0 , 0xffffffff , 0x0000 ,   0 }, //174
        { "et_cnt"                , 32 ,  "r" , 0x5d4,   0 , 0xffffffff , 0x0000 ,   0 }, //175
 
        { "test_mode"             ,  1 , "rw" , 0x3c ,   0 , 0x1        , 0x0000 ,   0 },
        { "reset"                 ,  1 , "rw" , 0x44 ,   0 , 0x1        , 0x0000 ,   0 },
        { "pll_reset"             ,  1 , "rw" , 0x48 ,   0 , 0x1        , 0x0000 ,   0 },
        { "version"               , 32 ,  "r" , 0x00 ,   0 , 0xffffffff , 0x0000 ,   0 },

        { "END"                   ,  0 ,  "x" ,  0x0 ,   0 , 0x0000     , 0x0000 ,   0 }
  };

  const Ctrl_Reg fcdt_reg[300]=
  {
//       Name                     Width  Type Address Start  Mask       Default  Present
//                                                     bit               Value    Value  // reg no.
        { "write_sim_data"        ,  1 , "rw" , 0x04 ,   0 , 0x1        , 0x0000     ,   0 }, //  1
        { "ena_sim_trig"          ,  1 , "rw" , 0x04 ,   1 , 0x2        , 0x0000     ,   0 }, //  1
        { "stat_trig_ptn"         ,  3 , "rw" , 0x04 ,   2 , 0x1c       , 0x0000     ,   0 }, //  1

        { "lvds_in_switch"        ,  1 , "rw" , 0x08 ,   0 , 0x1        , 0x0000     ,   0 }, //  2
        { "ena_digout_debug"      ,  1 , "rw" , 0x08 ,   1 , 0x2        , 0x0000     ,   0 }, //  2
        { "ena_lvds_cnt_debugger" ,  1 , "rw" , 0x08 ,   2 , 0x4        , 0x0000     ,   0 }, //  2

        { "write_sim_addr"        , 12 , "rw" , 0x0c ,   0 , 0xfff      , 0x0000     ,   0 }, //  3

        { "lvds_mem_switch"       ,  4 , "rw" , 0x10 ,   0 , 0xf        , 0x000f     ,   0 }, //  4

        { "err_masking"           , 11 , "rw" , 0x14 ,   0 , 0x7ff      , 0x0000     ,   0 }, //  5

        { "tlk_err_max_time"      , 32 , "rw" , 0x80 ,   0 , 0xffffffff , 0xb532b8   ,   0 }, // 20 
        { "dc_err_max_time"       , 32 , "rw" , 0x84 ,   0 , 0xffffffff , 0xbebe14   ,   0 }, // 21

        { "send_factory_trig"     ,  1 , "rw" , 0xc0 ,   0 , 0x1        , 0x0000     ,   0 }, // 30
        { "factory_trig_ptn"      ,  3 , "rw" , 0xc0 ,   1 , 0xe        , 0x0000     ,   0 }, // 30
        { "factory_trig_gap"      , 12 , "rw" , 0xc0 ,   4 , 0xfff0     , 0x0000     ,   0 }, // 30
        { "factory_ntrig"         , 16 , "rw" , 0xc0 ,  16 , 0xffff0000 , 0x0000     ,   0 }, // 30

        /////////////////////////
        //// status register ////
        /////////////////////////

        { "is_tlk_err_send"       ,  1 , "rw" , 0x28 ,   0 , 0x1        , 0x0000     ,   0 }, //  0
        { "is_dc_err_send"        ,  1 , "rw" , 0x28 ,   1 , 0x2        , 0x0000     ,   0 }, //  0 
        { "tlk_err_bus_cond"      , 11 , "rw" , 0x28 ,   2 , 0x1ffc     , 0x0000     ,   0 }, //  0
        { "dc_err_bus_cond"       , 11 , "rw" , 0x28 ,  13 , 0xffe000   , 0x0000     ,   0 }, //  0
        { "tlk_err_invalid"       ,  1 , "rw" , 0x28 ,  24 , 0x1000000  , 0x0000     ,   0 }, //  0
        { "dc_err_invalid"        ,  1 , "rw" , 0x28 ,  25 , 0x2000000  , 0x0000     ,   0 }, //  0

        { "tlk_err_c0_adc_rx"     , 16 , "rw" , 0x2c ,   0 , 0xffff     , 0x0000     ,   0 }, //  1
        { "tlk_err_c1_adc_rx"     , 16 , "rw" , 0x2c ,  16 , 0xffff0000 , 0x0000     ,   0 }, //  1
        { "tlk_err_c2_adc_rx"     , 16 , "rw" , 0x30 ,   0 , 0xffff     , 0x0000     ,   0 }, //  2
        { "tlk_err_c3_adc_rx"     , 16 , "rw" , 0x30 ,  16 , 0xffff0000 , 0x0000     ,   0 }, //  2
        { "tlk_err_c4_adc_rx"     , 16 , "rw" , 0x34 ,   0 , 0xffff     , 0x0000     ,   0 }, //  3
        { "tlk_err_c5_adc_rx"     , 16 , "rw" , 0x34 ,  16 , 0xffff0000 , 0x0000     ,   0 }, //  3
        { "tlk_err_c6_adc_rx"     , 16 , "rw" , 0x38 ,   0 , 0xffff     , 0x0000     ,   0 }, //  4
        { "tlk_err_c7_adc_rx"     , 16 , "rw" , 0x38 ,  16 , 0xffff0000 , 0x0000     ,   0 }, //  4 
        { "tlk_err_c8_adc_rx"     , 16 , "rw" , 0x400,   0 , 0xffff     , 0x0000     ,   0 }, //100
        { "tlk_err_c9_adc_rx"     , 16 , "rw" , 0x400,  16 , 0xffff0000 , 0x0000     ,   0 }, //100
        { "tlk_err_c10_adc_rx"    , 16 , "rw" , 0x404,   0 , 0xffff     , 0x0000     ,   0 }, //101
        { "dc_err_c0_adc_rx"      , 16 , "rw" , 0x404,  16 , 0xffff0000 , 0x0000     ,   0 }, //101
        { "dc_err_c1_adc_rx"      , 16 , "rw" , 0x408,   0 , 0x0000ffff , 0x0000     ,   0 }, //102
        { "dc_err_c2_adc_rx"      , 16 , "rw" , 0x408,  16 , 0xffff0000 , 0x0000     ,   0 }, //102
        { "dc_err_c3_adc_rx"      , 16 , "rw" , 0x40c,   0 , 0x0000ffff , 0x0000     ,   0 }, //103
        { "dc_err_c4_adc_rx"      , 16 , "rw" , 0x40c,  16 , 0xffff0000 , 0x0000     ,   0 }, //103
        { "dc_err_c5_adc_rx"      , 16 , "rw" , 0x410,   0 , 0x0000ffff , 0x0000     ,   0 }, //104
        { "dc_err_c6_adc_rx"      , 16 , "rw" , 0x410,  16 , 0xffff0000 , 0x0000     ,   0 }, //104
        { "dc_err_c7_adc_rx"      , 16 , "rw" , 0x414,   0 , 0x0000ffff , 0x0000     ,   0 }, //105
        { "dc_err_c8_adc_rx"      , 16 , "rw" , 0x414,  16 , 0xffff0000 , 0x0000     ,   0 }, //105
        { "dc_err_c9_adc_rx"      , 16 , "rw" , 0x418,   0 , 0x0000ffff , 0x0000     ,   0 }, //106
        { "dc_err_c10_adc_rx"     , 16 , "rw" , 0x418,  16 , 0xffff0000 , 0x0000     ,   0 }, //106 
        { "tlk_err_c0_cdt_rx"     ,  4 , "rw" , 0x41c,   0 , 0x0000000f , 0x0000     ,   0 }, //107
        { "tlk_err_c1_cdt_rx"     ,  4 , "rw" , 0x41c,   4 , 0x000000f0 , 0x0000     ,   0 }, //107
        { "tlk_err_c2_cdt_rx"     ,  4 , "rw" , 0x41c,   8 , 0x00000f00 , 0x0000     ,   0 }, //107
        { "tlk_err_c3_cdt_rx"     ,  4 , "rw" , 0x41c,  12 , 0x0000f000 , 0x0000     ,   0 }, //107
        { "tlk_err_c4_cdt_rx"     ,  4 , "rw" , 0x41c,  16 , 0x000f0000 , 0x0000     ,   0 }, //107
        { "tlk_err_c5_cdt_rx"     ,  4 , "rw" , 0x41c,  20 , 0x00f00000 , 0x0000     ,   0 }, //107
        { "tlk_err_c6_cdt_rx"     ,  4 , "rw" , 0x41c,  24 , 0x0f000000 , 0x0000     ,   0 }, //107
        { "tlk_err_c7_cdt_rx"     ,  4 , "rw" , 0x41c,  28 , 0xf0000000 , 0x0000     ,   0 }, //107
        { "tlk_err_c8_cdt_rx"     ,  4 , "rw" , 0x420,   0 , 0x0000000f , 0x0000     ,   0 }, //108
        { "tlk_err_c9_cdt_rx"     ,  4 , "rw" , 0x420,   4 , 0x000000f0 , 0x0000     ,   0 }, //108
        { "tlk_err_c10_cdt_rx"    ,  4 , "rw" , 0x420,   8 , 0x00000f00 , 0x0000     ,   0 }, //108
        { "dc_err_c0_cdt_rx"      ,  4 , "rw" , 0x420,  12 , 0x0000f000 , 0x0000     ,   0 }, //108
        { "dc_err_c1_cdt_rx"      ,  4 , "rw" , 0x420,  16 , 0x000f0000 , 0x0000     ,   0 }, //108
        { "dc_err_c2_cdt_rx"      ,  4 , "rw" , 0x420,  20 , 0x00f00000 , 0x0000     ,   0 }, //108
        { "dc_err_c3_cdt_rx"      ,  4 , "rw" , 0x420,  24 , 0x0f000000 , 0x0000     ,   0 }, //108
        { "dc_err_c4_cdt_rx"      ,  4 , "rw" , 0x420,  28 , 0xf0000000 , 0x0000     ,   0 }, //108
        { "dc_err_c5_cdt_rx"      ,  4 , "rw" , 0x424,   0 , 0x0000000f , 0x0000     ,   0 }, //109
        { "dc_err_c6_cdt_rx"      ,  4 , "rw" , 0x424,   0 , 0x000000f0 , 0x0000     ,   0 }, //109
        { "dc_err_c7_cdt_rx"      ,  4 , "rw" , 0x424,   0 , 0x00000f00 , 0x0000     ,   0 }, //109
        { "dc_err_c8_cdt_rx"      ,  4 , "rw" , 0x424,   0 , 0x0000f000 , 0x0000     ,   0 }, //109
        { "dc_err_c9_cdt_rx"      ,  4 , "rw" , 0x424,   0 , 0x000f0000 , 0x0000     ,   0 }, //109
        { "dc_err_c10_cdt_rx"     ,  4 , "rw" , 0x424,   0 , 0x00f00000 , 0x0000     ,   0 }, //109
        ////
        { "tlk_err_invalid"       , 11 , "rw" , 0x440,   0 , 0x7ff      , 0x0000     ,   0 }, //110
        { "dc_err_invalid"        , 11 , "rw" , 0x440,  11 , 0x3ff800   , 0x0000     ,   0 }, //110
        ////
        { "stat_trig_cnt"         , 16 ,  "r" , 0x444,   0 , 0xffff     , 0x0000     ,   0 }, //111
        ////
        { "lvds_c0_err_cnt"       , 16 ,  "r" , 0x508,   0 , 0xffff     , 0x0000     ,   0 }, //142
        { "lvds_c1_err_cnt"       , 16 ,  "r" , 0x508,  16 , 0xffff0000 , 0x0000     ,   0 }, //142
        { "lvds_c2_err_cnt"       , 16 ,  "r" , 0x50c,   0 , 0xffff     , 0x0000     ,   0 }, //143
        { "lvds_c3_err_cnt"       , 16 ,  "r" , 0x50c,  16 , 0xffff0000 , 0x0000     ,   0 }, //143
        { "lvds_c4_err_cnt"       , 16 ,  "r" , 0x510,   0 , 0xffff     , 0x0000     ,   0 }, //144
        { "lvds_c5_err_cnt"       , 16 ,  "r" , 0x510,  16 , 0xffff0000 , 0x0000     ,   0 }, //144
        { "lvds_c6_err_cnt"       , 16 ,  "r" , 0x514,   0 , 0xffff     , 0x0000     ,   0 }, //145
        { "lvds_c7_err_cnt"       , 16 ,  "r" , 0x514,  16 , 0xffff0000 , 0x0000     ,   0 }, //145
        { "lvds_c8_err_cnt"       , 16 ,  "r" , 0x518,   0 , 0xffff     , 0x0000     ,   0 }, //146
        { "lvds_c9_err_cnt"       , 16 ,  "r" , 0x518,  16 , 0xffff0000 , 0x0000     ,   0 }, //146
        { "lvds_c10_err_cnt"      , 16 ,  "r" , 0x51c,   0 , 0xffff     , 0x0000     ,   0 }, //147

        { "test_mode"             ,  1 , "rw" , 0x3c ,   0 , 0x1        , 0x0000     ,   0 }, 
        { "reset"                 ,  1 , "rw" , 0x44 ,   0 , 0x1        , 0x0000     ,   0 },
        { "pll_reset"             ,  1 , "rw" , 0x48 ,   0 , 0x1        , 0x0000     ,   0 },
	{ "version"               , 32 ,  "r" , 0x00 ,   0 , 0xffffffff , 0x0000 ,   0 },


        { "END"                   ,  0 ,  "x" ,  0x0 ,   0 , 0x0000     , 0x0000     ,   0 }
  };

  const Ctrl_Reg lcdt_reg[300]=
  {
//       Name                     Width  Type Address Start  Mask       Default  Present
//                                                     bit               Value    Value  // reg no.


        { "lvds_mem_switch"       ,  4 , "rw" , 0x10 ,   0 , 0xf        , 0x000f     ,   0 }, //  4
        { "err_adc_masking"       , 16 , "rw" , 0x10 ,   4 , 0xffff0    , 0x0000     ,   0 }, //  4
        { "write_err_sim_addr"    , 12 , "rw" , 0x10 ,  20 , 0xfff00000 , 0x0000     ,   0 }, //  4

        { "stat_trig_ptn"         ,  3 , "rw" , 0x14 ,   0 , 0x7        , 0x0000     ,   0 }, //  5
        { "ena_digout_debug"      ,  4 , "rw" , 0x14 ,   3 , 0x8        , 0x0000     ,   0 }, //  5
 
        { "is_veto_crate"         ,  1 , "rw" , 0x18 ,   0 , 0x1        , 0x0000     ,   0 }, //  6

        { "ena_olrx"              ,  4 , "rw" , 0x20 ,   0 , 0xf        , 0x0000     ,   0 }, //  8

        { "wmem_delay"            ,  8 , "rw" , 0x80 ,   0 , 0xff       , 0x0000     ,   0 }, // 20
        { "wmem_nwords"           ,  9 , "rw" , 0x80 ,   8 , 0x1ff00    , 0x0000     ,   0 }, // 20
        { "wmem_nevents"          ,  7 , "rw" , 0x80 ,  17 , 0xfe0000   , 0x0000     ,   0 }, // 20
        { "wmem_page"             ,  3 , "rw" , 0x80 ,  24 , 0x7000000  , 0x0000     ,   0 }, // 20
        { "wmem_trig_select"      ,  3 , "rw" , 0x80 ,  27 , 0x38000000 , 0x0000     ,   0 }, // 20
        ///
        { "wmem_mode"             ,  1 , "rw" , 0x80 ,  31 , 0x80000000 , 0x0000     ,   0 }, // 20
        { "send_factory_trig"     ,  1 , "rw" , 0x84 ,   0 , 0x1        , 0x0000     ,   0 }, // 21
        { "factory_trig_ptn"      ,  3 , "rw" , 0x84 ,   1 , 0xe        , 0x0000     ,   0 }, // 21
        { "factory_trig_gap"      , 12 , "rw" , 0x84 ,   4 , 0xfff0     , 0x0000     ,   0 }, // 21
        { "factory_ntrig"         , 16 , "rw" , 0x84 ,  16 , 0xffff0000 , 0x0000     ,   0 }, // 21
        ///

 
        { "lvds_debug_mode"       ,  2 , "rw" , 0x9c ,  30 , 0xc0000000 , 0x0000     ,   0 }, // 27

        { "ch0_detbit"            ,  4 , "rw" , 0xa4 ,   0 , 0x0000000f , 0x0000     ,   0 }, // 29
        { "ch1_detbit"            ,  4 , "rw" , 0xa4 ,   4 , 0x000000f0 , 0x0000     ,   0 }, // 29
        { "ch2_detbit"            ,  4 , "rw" , 0xa4 ,   8 , 0x00000f00 , 0x0000     ,   0 }, // 29
        { "ch3_detbit"            ,  4 , "rw" , 0xa4 ,  12 , 0x0000f000 , 0x0000     ,   0 }, // 29
        { "ch4_detbit"            ,  4 , "rw" , 0xa4 ,  16 , 0x000f0000 , 0x0000     ,   0 }, // 29
        { "ch5_detbit"            ,  4 , "rw" , 0xa4 ,  20 , 0x00f00000 , 0x0000     ,   0 }, // 29
        { "ch6_detbit"            ,  4 , "rw" , 0xa4 ,  24 , 0x0f000000 , 0x0000     ,   0 }, // 29
        { "ch7_detbit"            ,  4 , "rw" , 0xa4 ,  28 , 0xf0000000 , 0x0000     ,   0 }, // 29

        { "ch8_detbit"            ,  4 , "rw" , 0xd8 ,   0 , 0x0000000f , 0x0000     ,   0 }, // 36
        { "ch9_detbit"            ,  4 , "rw" , 0xd8 ,   4 , 0x000000f0 , 0x0000     ,   0 }, // 36
        { "ch10_detbit"           ,  4 , "rw" , 0xd8 ,   8 , 0x00000f00 , 0x0000     ,   0 }, // 36
        { "ch11_detbit"           ,  4 , "rw" , 0xd8 ,  12 , 0x0000f000 , 0x0000     ,   0 }, // 36
        { "ch12_detbit"           ,  4 , "rw" , 0xd8 ,  16 , 0x000f0000 , 0x0000     ,   0 }, // 36
        { "ch13_detbit"           ,  4 , "rw" , 0xd8 ,  20 , 0x00f00000 , 0x0000     ,   0 }, // 36
        { "ch14_detbit"           ,  4 , "rw" , 0xd8 ,  24 , 0x0f000000 , 0x0000     ,   0 }, // 36
        { "ch15_detbit"           ,  4 , "rw" , 0xd8 ,  28 , 0xf0000000 , 0x0000     ,   0 }, // 36

        { "lvds_debug_mode"       ,  2 , "rw" , 0x9c ,  30 , 0xc0000000 , 0x0000     ,   0 }, // 27

        { "et_maxt"               ,  8 , "rw" , 0xc8 ,   0 , 0xff       , 0x0000     ,   0 }, // 32
        ///
        { "et_masking"            , 16 , "rw" , 0xc8 ,  16 , 0xffff0000 , 0x0000     ,   0 }, // 32
        { "et_ptn_rx0"            , 16 , "rw" , 0xcc ,   0 , 0xffff     , 0x0000     ,   0 }, // 33
        { "et_ptn_rx1"            , 16 , "rw" , 0xcc ,  16 , 0xffff0000 , 0x0000     ,   0 }, // 33
        { "et_ptn_rx2"            , 16 , "rw" , 0xd0 ,   0 , 0xffff     , 0x0000     ,   0 }, // 34
        { "et_ptn_rx3"            , 16 , "rw" , 0xd0 ,  16 , 0xffff0000 , 0x0000     ,   0 }, // 34
        ///
        { "veto_maxt"             ,  8 , "rw" , 0xd4 ,   0 , 0xff       , 0x0000     ,   0 }, // 35
        ///
        { "veto_masking"          , 16 , "rw" , 0xd4 ,  16 , 0xffff0000 , 0x0000     ,   0 }, // 35 



        { "lvds_in_switch"        ,  1 , "rw" , 0xdc ,   0 , 0x1        , 0x0000     ,   0 }, // 37
        { "write_err_sim_data"    ,  1 , "rw" , 0xdc ,   1 , 0x2        , 0x0000     ,   0 }, // 37
        { "ena_err_sim_trig"      ,  1 , "rw" , 0xdc ,   2 , 0x4        , 0x0000     ,   0 }, // 37
        { "tlk_olrx_masking"      ,  4 , "rw" , 0xdc ,   3 , 0x78       , 0x0000     ,   0 }, // 37
        { "dc_olrx_masking"       ,  4 , "rw" , 0xdc ,   7 , 0x780      , 0x0000     ,   0 }, // 37
        { "ena_lvds_counter"      ,  1 , "rw" , 0xdc ,  11 , 0x800      , 0x0000     ,   0 }, // 37
        
        { "dc_err_max_time"       , 32 , "rw" , 0xe0 ,   0 , 0xffffffff , 0xaba950   ,   0 }, // 38
        { "tlk_err_max_time"      , 32 , "rw" , 0xe4 ,   0 , 0xffffffff , 0x131460   ,   0 }, // 39 

        ///////////////////////
        /// status register ///
        ///////////////////////

        { "stat_trig_cnt"         , 16 ,  "r" , 0x34 ,   0 , 0xffff     , 0x0000     ,   0 }, //  3
        { "buffer_full"           ,  1 ,  "r" , 0x38 ,   0 , 0x1        , 0x0000     ,   0 }, //  4

        { "lvds_debug_in0"        , 32 ,  "r" , 0x400,  32 , 0xffffffff , 0x0000     ,   0 }, //100
        { "lvds_debug_in1"        , 32 ,  "r" , 0x404,  32 , 0xffffffff , 0x0000     ,   0 }, //101
        { "lvds_debug_in2"        , 32 ,  "r" , 0x408,  32 , 0xffffffff , 0x0000     ,   0 }, //102
        { "lvds_debug_in3"        , 32 ,  "r" , 0x40c,  32 , 0xffffffff , 0x0000     ,   0 }, //103
        { "lvds_debug_in4"        , 32 ,  "r" , 0x410,  32 , 0xffffffff , 0x0000     ,   0 }, //104
        { "lvds_debug_in5"        , 32 ,  "r" , 0x414,  32 , 0xffffffff , 0x0000     ,   0 }, //105
        { "lvds_debug_in6"        , 32 ,  "r" , 0x418,  32 , 0xffffffff , 0x0000     ,   0 }, //106
        { "lvds_debug_in7"        , 32 ,  "r" , 0x41c,  32 , 0xffffffff , 0x0000     ,   0 }, //107
        { "lvds_debug_in8"        , 32 ,  "r" , 0x420,  32 , 0xffffffff , 0x0000     ,   0 }, //108
        { "lvds_debug_in9"        , 32 ,  "r" , 0x424,  32 , 0xffffffff , 0x0000     ,   0 }, //109
        { "lvds_debug_in10"       , 32 ,  "r" , 0x440,  32 , 0xffffffff , 0x0000     ,   0 }, //110
        { "lvds_debug_in11"       , 32 ,  "r" , 0x444,  32 , 0xffffffff , 0x0000     ,   0 }, //111
        { "lvds_debug_in12"       , 32 ,  "r" , 0x448,  32 , 0xffffffff , 0x0000     ,   0 }, //112
        { "lvds_debug_in13"       , 32 ,  "r" , 0x44c,  32 , 0xffffffff , 0x0000     ,   0 }, //113
        { "lvds_debug_in14"       , 32 ,  "r" , 0x450,  32 , 0xffffffff , 0x0000     ,   0 }, //114
        { "lvds_debug_in15"       , 32 ,  "r" , 0x454,  32 , 0xffffffff , 0x0000     ,   0 }, //115

        { "is_tlk_err_send"       ,  1 ,  "r" , 0x460,   0 , 0x1        , 0x0000     ,   0 }, //118
        { "tlk_err_invalid"       ,  1 ,  "r" , 0x460,   1 , 0x2        , 0x0000     ,   0 }, //118
        { "is_dc_err_send"        ,  1 ,  "r" , 0x460,   2 , 0x4        , 0x0000     ,   0 }, //118
        { "dc_err_invalid"        ,  1 ,  "r" , 0x460,   3 , 0x8        , 0x0000     ,   0 }, //118
        { "tlk_olrx_err"          ,  4 ,  "r" , 0x460,   4 , 0xf0       , 0x0000     ,   0 }, //118
        { "dc_olrx_err"           ,  4 ,  "r" , 0x460,   8 , 0xf00      , 0x0000     ,   0 }, //118
        { "align_cnt"             , 12 ,  "r" , 0x460,  12 , 0xfff000   , 0x0000     ,   0 }, //118

        { "tlk_err_bus_result"    , 16 ,  "r" , 0x464,   0 , 0xffff     , 0x0000     ,   0 }, //119
        { "dc_err_bus_result"     , 16 ,  "r" , 0x464,  16 , 0xffff0000 , 0x0000     ,   0 }, //119

        { "tlk_err_bus_cond"      , 16 ,  "r" , 0x480,   0 , 0xffff     , 0x0000     ,   0 }, //120
        { "dc_err_bus_cond"       , 16 ,  "r" , 0x480,  16 , 0xffff0000 , 0x0000     ,   0 }, //120

       
        { "test_mode"             ,  1 , "rw" , 0x3c ,   0 , 0x1        , 0x0000     ,   0 },
        { "reset"                 ,  1 , "rw" , 0x44 ,   0 , 0x1        , 0x0000     ,   0 },
        { "pll_reset"             ,  1 , "rw" , 0x48 ,   0 , 0x1        , 0x0000     ,   0 },
	{ "version"               , 32 ,  "r" , 0x00 ,   0 , 0xffffffff , 0x0000 ,   0 },


        { "END"                   ,  0 ,  "x" ,  0x0 ,   0 , 0x0000     , 0x0000     ,   0 }
  };

  const Ctrl_Reg eofc_reg[300]=
  {
//       Name                     Width  Type Address Start  Mask       Default  Present
//                                                     bit               Value    Value  // reg no.

        { "ena_lvds_cnt"          ,  1 , "rw" , 0x1c ,   1 , 0x2        , 0x0        , 0 }, // 7

        { "ena_olrx"              , 18 , "rw" , 0x20 ,   0 , 0x3ffff    , 0x3ffff    , 0 }, // 8

        { "et_ptn_rx"             , 16 , "rw" , 0xc0 ,   0 , 0xffff     , 0xfefe     , 0 }, // 30
        { "veto_ptn_rx"           , 16 , "rw" , 0xc0 ,  16 , 0xffff0000 , 0xfefe     , 0 }, // 30

        { "et_maxt"               ,  8 , "rw" , 0xc4 ,   0 , 0xff       , 0x20       , 0 }, // 31
        { "et_masking"            , 16 , "rw" , 0xc4 ,  16 , 0xffff0000 , 0x0000     , 0 }, // 31

        { "veto_maxt"             ,  8 , "rw" , 0xc8 ,   0 , 0xff       , 0x20       , 0 }, // 32
        { "veto_masking"          , 16 , "rw" , 0xc8 ,  16 , 0xffff0000 , 0x20       , 0 }, // 32

        { "err_maxt"              ,  9 , "rw" , 0xcc ,   0 , 0x1ff      , 0x00       , 0 }, // 33

        { "rawfile_et_thr"        , 16 , "rw" , 0xe4 ,   0 , 0xffff     , 0x0        , 0 }, // 39
        { "rawfile_en"            ,  1 , "rw" , 0xe4 ,  31 , 0x80000000 , 0x0        , 0 }, // 39 

        ///////////////////////
        /// status register ///
        ///////////////////////

        { "rawfile_ntrig"         , 32 , "rw" , 0x28 ,   0 , 0xffffffff , 0x0000     ,   0 }, //  0
        { "rawfile_data"          , 32 , "rw" , 0x2c ,   0 , 0xffffffff , 0x0000     ,   0 }, //  1

        { "lv1_cnt"               , 32 ,  "r" , 0x454,   0 , 0xffffffff , 0x00000000 , 0 }, //115
        { "plv1_cnt"              , 32 ,  "r" , 0x458,   0 , 0xffffffff , 0x00000000 , 0 }, //116
        { "ps_cnt"                , 32 ,  "r" , 0x45c,   0 , 0xffffffff , 0x00000000 , 0 }, //117
        { "align_cnt"             , 32 ,  "r" , 0x460,   0 , 0xffffffff , 0x00000000 , 0 }, //118
        { "delta_cnt"             , 32 ,  "r" , 0x464,   0 , 0xffffffff , 0x00000000 , 0 }, //119
        { "tlk_err"               , 18 ,  "r" , 0x480,   0 , 0x0003ffff , 0x00000000 , 0 }, //120

        { "test_mode"             ,  1 , "rw" , 0x3c ,   0 , 0x1        , 0x0000     , 0 },
        { "reset"                 ,  1 , "rw" , 0x44 ,   0 , 0x1        , 0x0000     , 0 },
        { "pll_reset"             ,  1 , "rw" , 0x48 ,   0 , 0x1        , 0x0000     , 0 },
        { "version"               , 32 ,  "r" , 0x00 ,   0 , 0xffffffff , 0x0000 ,   0 },


        { "END"                   ,  0 ,  "x" ,  0x0 ,   0 , 0x0000     , 0x0000     , 0 }
  };

  const Ctrl_Reg cofc_reg[300]=
  {
//       Name                     Width  Type Address Start  Mask       Default  Present
//                                                     bit               Value    Value  // reg no.

        { "ena_lvds_cnt"          ,  1 , "rw" , 0x1c  ,   1 , 0x2        , 0x0        , 0 }, // 7

        { "ena_olrx"              , 18 , "rw" , 0x20  ,   0 , 0x3ffff    , 0x7ff      , 0 }, // 8

        { "wmem_delay"            ,  8 , "rw" , 0x80  ,   0 , 0x000000ff , 0x00000000 , 0 }, //20
        { "wmem_nwords"           ,  8 , "rw" , 0x80  ,   8 , 0x0000ff00 , 0x00000000 , 0 }, //20
        { "wmem_nevents"          ,  8 , "rw" , 0x80  ,  16 , 0x00ff0000 , 0x00000000 , 0 }, //20
        { "wmem_page"             ,  3 , "rw" , 0x80  ,  24 , 0x07000000 , 0x00000000 , 0 }, //20
        ///
        { "wmem_mode"             ,  1 , "rw" , 0x80  ,  31 , 0x80000000 , 0x00000000 , 0 }, //20
        ///
        { "evtID_delay"           ,  8 , "rw" , 0x8c  ,   0 , 0x800000ff , 0x00000000 , 0 }, //23
  
 
        ///////////////////////
        /// status register ///
        ///////////////////////

        { "buffer_full"           ,  1 ,  "r" , 0x38 ,   0 , 0x1        , 0x0000     ,   0 }, //  4



        { "lv1_cnt"               , 32 ,  "r" , 0x454,   0 , 0xffffffff , 0x00000000 , 0 }, //115
        { "plv1_cnt"              , 32 ,  "r" , 0x458,   0 , 0xffffffff , 0x00000000 , 0 }, //116
        { "ps_cnt"                , 32 ,  "r" , 0x45c,   0 , 0xffffffff , 0x00000000 , 0 }, //117
        { "align_cnt"             , 32 ,  "r" , 0x460,   0 , 0xffffffff , 0x00000000 , 0 }, //118
        { "delta_cnt"             , 32 ,  "r" , 0x464,   0 , 0xffffffff , 0x00000000 , 0 }, //119
        { "tlk_err"               , 18 ,  "r" , 0x480,   0 , 0x0003ffff , 0x00000000 , 0 }, //120

        { "test_mode"             ,  1 , "rw" , 0x3c ,   0 , 0x1        , 0x0000     ,   0 },
        { "reset"                 ,  1 , "rw" , 0x44 ,   0 , 0x1        , 0x0000     ,   0 },
        { "pll_reset"             ,  1 , "rw" , 0x48 ,   0 , 0x1        , 0x0000     ,   0 },
	{ "version"               , 32 ,  "r" , 0x00 ,   0 , 0xffffffff , 0x0000 ,   0 },


        { "END"                   ,  0 ,  "x" ,  0x0 ,   0 , 0x0000     , 0x0000     ,   0 }
  };





};

#endif
