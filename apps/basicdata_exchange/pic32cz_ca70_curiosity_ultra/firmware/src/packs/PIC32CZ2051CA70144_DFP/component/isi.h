/*
 * Component description for ISI
 *
 * Copyright (c) 2025 Microchip Technology Inc. and its subsidiaries.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

/*  file generated from device description file (ATDF) version 2025-04-15T17:35:01Z  */
#ifndef _PIC32CZCA70_ISI_COMPONENT_H_
#define _PIC32CZCA70_ISI_COMPONENT_H_

/* ************************************************************************** */
/*                      SOFTWARE API DEFINITION FOR ISI                       */
/* ************************************************************************** */

/* -------- ISI_CFG1 : (ISI Offset: 0x00) (R/W 32) ISI Configuration 1 Register -------- */
#define ISI_CFG1_HSYNC_POL_Pos                _UINT32_(2)                                          /* (ISI_CFG1) Horizontal Synchronization Polarity Position */
#define ISI_CFG1_HSYNC_POL_Msk                (_UINT32_(0x1) << ISI_CFG1_HSYNC_POL_Pos)            /* (ISI_CFG1) Horizontal Synchronization Polarity Mask */
#define ISI_CFG1_HSYNC_POL(value)             (ISI_CFG1_HSYNC_POL_Msk & (_UINT32_(value) << ISI_CFG1_HSYNC_POL_Pos)) /* Assignment of value for HSYNC_POL in the ISI_CFG1 register */
#define ISI_CFG1_VSYNC_POL_Pos                _UINT32_(3)                                          /* (ISI_CFG1) Vertical Synchronization Polarity Position */
#define ISI_CFG1_VSYNC_POL_Msk                (_UINT32_(0x1) << ISI_CFG1_VSYNC_POL_Pos)            /* (ISI_CFG1) Vertical Synchronization Polarity Mask */
#define ISI_CFG1_VSYNC_POL(value)             (ISI_CFG1_VSYNC_POL_Msk & (_UINT32_(value) << ISI_CFG1_VSYNC_POL_Pos)) /* Assignment of value for VSYNC_POL in the ISI_CFG1 register */
#define ISI_CFG1_PIXCLK_POL_Pos               _UINT32_(4)                                          /* (ISI_CFG1) Pixel Clock Polarity Position */
#define ISI_CFG1_PIXCLK_POL_Msk               (_UINT32_(0x1) << ISI_CFG1_PIXCLK_POL_Pos)           /* (ISI_CFG1) Pixel Clock Polarity Mask */
#define ISI_CFG1_PIXCLK_POL(value)            (ISI_CFG1_PIXCLK_POL_Msk & (_UINT32_(value) << ISI_CFG1_PIXCLK_POL_Pos)) /* Assignment of value for PIXCLK_POL in the ISI_CFG1 register */
#define ISI_CFG1_GRAYLE_Pos                   _UINT32_(5)                                          /* (ISI_CFG1) Grayscale Little Endian Position */
#define ISI_CFG1_GRAYLE_Msk                   (_UINT32_(0x1) << ISI_CFG1_GRAYLE_Pos)               /* (ISI_CFG1) Grayscale Little Endian Mask */
#define ISI_CFG1_GRAYLE(value)                (ISI_CFG1_GRAYLE_Msk & (_UINT32_(value) << ISI_CFG1_GRAYLE_Pos)) /* Assignment of value for GRAYLE in the ISI_CFG1 register */
#define ISI_CFG1_EMB_SYNC_Pos                 _UINT32_(6)                                          /* (ISI_CFG1) Embedded Synchronization Position */
#define ISI_CFG1_EMB_SYNC_Msk                 (_UINT32_(0x1) << ISI_CFG1_EMB_SYNC_Pos)             /* (ISI_CFG1) Embedded Synchronization Mask */
#define ISI_CFG1_EMB_SYNC(value)              (ISI_CFG1_EMB_SYNC_Msk & (_UINT32_(value) << ISI_CFG1_EMB_SYNC_Pos)) /* Assignment of value for EMB_SYNC in the ISI_CFG1 register */
#define ISI_CFG1_CRC_SYNC_Pos                 _UINT32_(7)                                          /* (ISI_CFG1) Embedded Synchronization Correction Position */
#define ISI_CFG1_CRC_SYNC_Msk                 (_UINT32_(0x1) << ISI_CFG1_CRC_SYNC_Pos)             /* (ISI_CFG1) Embedded Synchronization Correction Mask */
#define ISI_CFG1_CRC_SYNC(value)              (ISI_CFG1_CRC_SYNC_Msk & (_UINT32_(value) << ISI_CFG1_CRC_SYNC_Pos)) /* Assignment of value for CRC_SYNC in the ISI_CFG1 register */
#define ISI_CFG1_FRATE_Pos                    _UINT32_(8)                                          /* (ISI_CFG1) Frame Rate [0..7] Position */
#define ISI_CFG1_FRATE_Msk                    (_UINT32_(0x7) << ISI_CFG1_FRATE_Pos)                /* (ISI_CFG1) Frame Rate [0..7] Mask */
#define ISI_CFG1_FRATE(value)                 (ISI_CFG1_FRATE_Msk & (_UINT32_(value) << ISI_CFG1_FRATE_Pos)) /* Assignment of value for FRATE in the ISI_CFG1 register */
#define ISI_CFG1_DISCR_Pos                    _UINT32_(11)                                         /* (ISI_CFG1) Disable Codec Request Position */
#define ISI_CFG1_DISCR_Msk                    (_UINT32_(0x1) << ISI_CFG1_DISCR_Pos)                /* (ISI_CFG1) Disable Codec Request Mask */
#define ISI_CFG1_DISCR(value)                 (ISI_CFG1_DISCR_Msk & (_UINT32_(value) << ISI_CFG1_DISCR_Pos)) /* Assignment of value for DISCR in the ISI_CFG1 register */
#define ISI_CFG1_FULL_Pos                     _UINT32_(12)                                         /* (ISI_CFG1) Full Mode is Allowed Position */
#define ISI_CFG1_FULL_Msk                     (_UINT32_(0x1) << ISI_CFG1_FULL_Pos)                 /* (ISI_CFG1) Full Mode is Allowed Mask */
#define ISI_CFG1_FULL(value)                  (ISI_CFG1_FULL_Msk & (_UINT32_(value) << ISI_CFG1_FULL_Pos)) /* Assignment of value for FULL in the ISI_CFG1 register */
#define ISI_CFG1_THMASK_Pos                   _UINT32_(13)                                         /* (ISI_CFG1) Threshold Mask Position */
#define ISI_CFG1_THMASK_Msk                   (_UINT32_(0x3) << ISI_CFG1_THMASK_Pos)               /* (ISI_CFG1) Threshold Mask Mask */
#define ISI_CFG1_THMASK(value)                (ISI_CFG1_THMASK_Msk & (_UINT32_(value) << ISI_CFG1_THMASK_Pos)) /* Assignment of value for THMASK in the ISI_CFG1 register */
#define   ISI_CFG1_THMASK_BEATS_4_Val         _UINT32_(0x0)                                        /* (ISI_CFG1) Only 4 beats AHB burst allowed  */
#define   ISI_CFG1_THMASK_BEATS_8_Val         _UINT32_(0x1)                                        /* (ISI_CFG1) Only 4 and 8 beats AHB burst allowed  */
#define   ISI_CFG1_THMASK_BEATS_16_Val        _UINT32_(0x2)                                        /* (ISI_CFG1) 4, 8 and 16 beats AHB burst allowed  */
#define ISI_CFG1_THMASK_BEATS_4               (ISI_CFG1_THMASK_BEATS_4_Val << ISI_CFG1_THMASK_Pos) /* (ISI_CFG1) Only 4 beats AHB burst allowed Position */
#define ISI_CFG1_THMASK_BEATS_8               (ISI_CFG1_THMASK_BEATS_8_Val << ISI_CFG1_THMASK_Pos) /* (ISI_CFG1) Only 4 and 8 beats AHB burst allowed Position */
#define ISI_CFG1_THMASK_BEATS_16              (ISI_CFG1_THMASK_BEATS_16_Val << ISI_CFG1_THMASK_Pos) /* (ISI_CFG1) 4, 8 and 16 beats AHB burst allowed Position */
#define ISI_CFG1_SLD_Pos                      _UINT32_(16)                                         /* (ISI_CFG1) Start of Line Delay Position */
#define ISI_CFG1_SLD_Msk                      (_UINT32_(0xFF) << ISI_CFG1_SLD_Pos)                 /* (ISI_CFG1) Start of Line Delay Mask */
#define ISI_CFG1_SLD(value)                   (ISI_CFG1_SLD_Msk & (_UINT32_(value) << ISI_CFG1_SLD_Pos)) /* Assignment of value for SLD in the ISI_CFG1 register */
#define ISI_CFG1_SFD_Pos                      _UINT32_(24)                                         /* (ISI_CFG1) Start of Frame Delay Position */
#define ISI_CFG1_SFD_Msk                      (_UINT32_(0xFF) << ISI_CFG1_SFD_Pos)                 /* (ISI_CFG1) Start of Frame Delay Mask */
#define ISI_CFG1_SFD(value)                   (ISI_CFG1_SFD_Msk & (_UINT32_(value) << ISI_CFG1_SFD_Pos)) /* Assignment of value for SFD in the ISI_CFG1 register */
#define ISI_CFG1_Msk                          _UINT32_(0xFFFF7FFC)                                 /* (ISI_CFG1) Register Mask  */


/* -------- ISI_CFG2 : (ISI Offset: 0x04) (R/W 32) ISI Configuration 2 Register -------- */
#define ISI_CFG2_IM_VSIZE_Pos                 _UINT32_(0)                                          /* (ISI_CFG2) Vertical Size of the Image Sensor [0..2047] Position */
#define ISI_CFG2_IM_VSIZE_Msk                 (_UINT32_(0x7FF) << ISI_CFG2_IM_VSIZE_Pos)           /* (ISI_CFG2) Vertical Size of the Image Sensor [0..2047] Mask */
#define ISI_CFG2_IM_VSIZE(value)              (ISI_CFG2_IM_VSIZE_Msk & (_UINT32_(value) << ISI_CFG2_IM_VSIZE_Pos)) /* Assignment of value for IM_VSIZE in the ISI_CFG2 register */
#define ISI_CFG2_GS_MODE_Pos                  _UINT32_(11)                                         /* (ISI_CFG2) Grayscale Pixel Format Mode Position */
#define ISI_CFG2_GS_MODE_Msk                  (_UINT32_(0x1) << ISI_CFG2_GS_MODE_Pos)              /* (ISI_CFG2) Grayscale Pixel Format Mode Mask */
#define ISI_CFG2_GS_MODE(value)               (ISI_CFG2_GS_MODE_Msk & (_UINT32_(value) << ISI_CFG2_GS_MODE_Pos)) /* Assignment of value for GS_MODE in the ISI_CFG2 register */
#define ISI_CFG2_RGB_MODE_Pos                 _UINT32_(12)                                         /* (ISI_CFG2) RGB Input Mode Position */
#define ISI_CFG2_RGB_MODE_Msk                 (_UINT32_(0x1) << ISI_CFG2_RGB_MODE_Pos)             /* (ISI_CFG2) RGB Input Mode Mask */
#define ISI_CFG2_RGB_MODE(value)              (ISI_CFG2_RGB_MODE_Msk & (_UINT32_(value) << ISI_CFG2_RGB_MODE_Pos)) /* Assignment of value for RGB_MODE in the ISI_CFG2 register */
#define ISI_CFG2_GRAYSCALE_Pos                _UINT32_(13)                                         /* (ISI_CFG2) Grayscale Mode Format Enable Position */
#define ISI_CFG2_GRAYSCALE_Msk                (_UINT32_(0x1) << ISI_CFG2_GRAYSCALE_Pos)            /* (ISI_CFG2) Grayscale Mode Format Enable Mask */
#define ISI_CFG2_GRAYSCALE(value)             (ISI_CFG2_GRAYSCALE_Msk & (_UINT32_(value) << ISI_CFG2_GRAYSCALE_Pos)) /* Assignment of value for GRAYSCALE in the ISI_CFG2 register */
#define ISI_CFG2_RGB_SWAP_Pos                 _UINT32_(14)                                         /* (ISI_CFG2) RGB Format Swap Mode Position */
#define ISI_CFG2_RGB_SWAP_Msk                 (_UINT32_(0x1) << ISI_CFG2_RGB_SWAP_Pos)             /* (ISI_CFG2) RGB Format Swap Mode Mask */
#define ISI_CFG2_RGB_SWAP(value)              (ISI_CFG2_RGB_SWAP_Msk & (_UINT32_(value) << ISI_CFG2_RGB_SWAP_Pos)) /* Assignment of value for RGB_SWAP in the ISI_CFG2 register */
#define ISI_CFG2_COL_SPACE_Pos                _UINT32_(15)                                         /* (ISI_CFG2) Color Space for the Image Data Position */
#define ISI_CFG2_COL_SPACE_Msk                (_UINT32_(0x1) << ISI_CFG2_COL_SPACE_Pos)            /* (ISI_CFG2) Color Space for the Image Data Mask */
#define ISI_CFG2_COL_SPACE(value)             (ISI_CFG2_COL_SPACE_Msk & (_UINT32_(value) << ISI_CFG2_COL_SPACE_Pos)) /* Assignment of value for COL_SPACE in the ISI_CFG2 register */
#define ISI_CFG2_IM_HSIZE_Pos                 _UINT32_(16)                                         /* (ISI_CFG2) Horizontal Size of the Image Sensor [0..2047] Position */
#define ISI_CFG2_IM_HSIZE_Msk                 (_UINT32_(0x7FF) << ISI_CFG2_IM_HSIZE_Pos)           /* (ISI_CFG2) Horizontal Size of the Image Sensor [0..2047] Mask */
#define ISI_CFG2_IM_HSIZE(value)              (ISI_CFG2_IM_HSIZE_Msk & (_UINT32_(value) << ISI_CFG2_IM_HSIZE_Pos)) /* Assignment of value for IM_HSIZE in the ISI_CFG2 register */
#define ISI_CFG2_YCC_SWAP_Pos                 _UINT32_(28)                                         /* (ISI_CFG2) YCrCb Format Swap Mode Position */
#define ISI_CFG2_YCC_SWAP_Msk                 (_UINT32_(0x3) << ISI_CFG2_YCC_SWAP_Pos)             /* (ISI_CFG2) YCrCb Format Swap Mode Mask */
#define ISI_CFG2_YCC_SWAP(value)              (ISI_CFG2_YCC_SWAP_Msk & (_UINT32_(value) << ISI_CFG2_YCC_SWAP_Pos)) /* Assignment of value for YCC_SWAP in the ISI_CFG2 register */
#define   ISI_CFG2_YCC_SWAP_DEFAULT_Val       _UINT32_(0x0)                                        /* (ISI_CFG2) Byte 0 Cb(i)Byte 1 Y(i)Byte 2 Cr(i)Byte 3 Y(i+1)  */
#define   ISI_CFG2_YCC_SWAP_MODE1_Val         _UINT32_(0x1)                                        /* (ISI_CFG2) Byte 0 Cr(i)Byte 1 Y(i)Byte 2 Cb(i)Byte 3 Y(i+1)  */
#define   ISI_CFG2_YCC_SWAP_MODE2_Val         _UINT32_(0x2)                                        /* (ISI_CFG2) Byte 0 Y(i)Byte 1 Cb(i)Byte 2 Y(i+1)Byte 3 Cr(i)  */
#define   ISI_CFG2_YCC_SWAP_MODE3_Val         _UINT32_(0x3)                                        /* (ISI_CFG2) Byte 0 Y(i)Byte 1 Cr(i)Byte 2 Y(i+1)Byte 3 Cb(i)  */
#define ISI_CFG2_YCC_SWAP_DEFAULT             (ISI_CFG2_YCC_SWAP_DEFAULT_Val << ISI_CFG2_YCC_SWAP_Pos) /* (ISI_CFG2) Byte 0 Cb(i)Byte 1 Y(i)Byte 2 Cr(i)Byte 3 Y(i+1) Position */
#define ISI_CFG2_YCC_SWAP_MODE1               (ISI_CFG2_YCC_SWAP_MODE1_Val << ISI_CFG2_YCC_SWAP_Pos) /* (ISI_CFG2) Byte 0 Cr(i)Byte 1 Y(i)Byte 2 Cb(i)Byte 3 Y(i+1) Position */
#define ISI_CFG2_YCC_SWAP_MODE2               (ISI_CFG2_YCC_SWAP_MODE2_Val << ISI_CFG2_YCC_SWAP_Pos) /* (ISI_CFG2) Byte 0 Y(i)Byte 1 Cb(i)Byte 2 Y(i+1)Byte 3 Cr(i) Position */
#define ISI_CFG2_YCC_SWAP_MODE3               (ISI_CFG2_YCC_SWAP_MODE3_Val << ISI_CFG2_YCC_SWAP_Pos) /* (ISI_CFG2) Byte 0 Y(i)Byte 1 Cr(i)Byte 2 Y(i+1)Byte 3 Cb(i) Position */
#define ISI_CFG2_RGB_CFG_Pos                  _UINT32_(30)                                         /* (ISI_CFG2) RGB Pixel Mapping Configuration Position */
#define ISI_CFG2_RGB_CFG_Msk                  (_UINT32_(0x3) << ISI_CFG2_RGB_CFG_Pos)              /* (ISI_CFG2) RGB Pixel Mapping Configuration Mask */
#define ISI_CFG2_RGB_CFG(value)               (ISI_CFG2_RGB_CFG_Msk & (_UINT32_(value) << ISI_CFG2_RGB_CFG_Pos)) /* Assignment of value for RGB_CFG in the ISI_CFG2 register */
#define   ISI_CFG2_RGB_CFG_DEFAULT_Val        _UINT32_(0x0)                                        /* (ISI_CFG2) Byte 0 R/G(MSB)Byte 1 G(LSB)/BByte 2 R/G(MSB)Byte 3 G(LSB)/B  */
#define   ISI_CFG2_RGB_CFG_MODE1_Val          _UINT32_(0x1)                                        /* (ISI_CFG2) Byte 0 B/G(MSB)Byte 1 G(LSB)/RByte 2 B/G(MSB)Byte 3 G(LSB)/R  */
#define   ISI_CFG2_RGB_CFG_MODE2_Val          _UINT32_(0x2)                                        /* (ISI_CFG2) Byte 0 G(LSB)/RByte 1 B/G(MSB)Byte 2 G(LSB)/RByte 3 B/G(MSB)  */
#define   ISI_CFG2_RGB_CFG_MODE3_Val          _UINT32_(0x3)                                        /* (ISI_CFG2) Byte 0 G(LSB)/BByte 1 R/G(MSB)Byte 2 G(LSB)/BByte 3 R/G(MSB)  */
#define ISI_CFG2_RGB_CFG_DEFAULT              (ISI_CFG2_RGB_CFG_DEFAULT_Val << ISI_CFG2_RGB_CFG_Pos) /* (ISI_CFG2) Byte 0 R/G(MSB)Byte 1 G(LSB)/BByte 2 R/G(MSB)Byte 3 G(LSB)/B Position */
#define ISI_CFG2_RGB_CFG_MODE1                (ISI_CFG2_RGB_CFG_MODE1_Val << ISI_CFG2_RGB_CFG_Pos) /* (ISI_CFG2) Byte 0 B/G(MSB)Byte 1 G(LSB)/RByte 2 B/G(MSB)Byte 3 G(LSB)/R Position */
#define ISI_CFG2_RGB_CFG_MODE2                (ISI_CFG2_RGB_CFG_MODE2_Val << ISI_CFG2_RGB_CFG_Pos) /* (ISI_CFG2) Byte 0 G(LSB)/RByte 1 B/G(MSB)Byte 2 G(LSB)/RByte 3 B/G(MSB) Position */
#define ISI_CFG2_RGB_CFG_MODE3                (ISI_CFG2_RGB_CFG_MODE3_Val << ISI_CFG2_RGB_CFG_Pos) /* (ISI_CFG2) Byte 0 G(LSB)/BByte 1 R/G(MSB)Byte 2 G(LSB)/BByte 3 R/G(MSB) Position */
#define ISI_CFG2_Msk                          _UINT32_(0xF7FFFFFF)                                 /* (ISI_CFG2) Register Mask  */


/* -------- ISI_PSIZE : (ISI Offset: 0x08) (R/W 32) ISI Preview Size Register -------- */
#define ISI_PSIZE_PREV_VSIZE_Pos              _UINT32_(0)                                          /* (ISI_PSIZE) Vertical Size for the Preview Path Position */
#define ISI_PSIZE_PREV_VSIZE_Msk              (_UINT32_(0x3FF) << ISI_PSIZE_PREV_VSIZE_Pos)        /* (ISI_PSIZE) Vertical Size for the Preview Path Mask */
#define ISI_PSIZE_PREV_VSIZE(value)           (ISI_PSIZE_PREV_VSIZE_Msk & (_UINT32_(value) << ISI_PSIZE_PREV_VSIZE_Pos)) /* Assignment of value for PREV_VSIZE in the ISI_PSIZE register */
#define ISI_PSIZE_PREV_HSIZE_Pos              _UINT32_(16)                                         /* (ISI_PSIZE) Horizontal Size for the Preview Path Position */
#define ISI_PSIZE_PREV_HSIZE_Msk              (_UINT32_(0x3FF) << ISI_PSIZE_PREV_HSIZE_Pos)        /* (ISI_PSIZE) Horizontal Size for the Preview Path Mask */
#define ISI_PSIZE_PREV_HSIZE(value)           (ISI_PSIZE_PREV_HSIZE_Msk & (_UINT32_(value) << ISI_PSIZE_PREV_HSIZE_Pos)) /* Assignment of value for PREV_HSIZE in the ISI_PSIZE register */
#define ISI_PSIZE_Msk                         _UINT32_(0x03FF03FF)                                 /* (ISI_PSIZE) Register Mask  */


/* -------- ISI_PDECF : (ISI Offset: 0x0C) (R/W 32) ISI Preview Decimation Factor Register -------- */
#define ISI_PDECF_DEC_FACTOR_Pos              _UINT32_(0)                                          /* (ISI_PDECF) Decimation Factor Position */
#define ISI_PDECF_DEC_FACTOR_Msk              (_UINT32_(0xFF) << ISI_PDECF_DEC_FACTOR_Pos)         /* (ISI_PDECF) Decimation Factor Mask */
#define ISI_PDECF_DEC_FACTOR(value)           (ISI_PDECF_DEC_FACTOR_Msk & (_UINT32_(value) << ISI_PDECF_DEC_FACTOR_Pos)) /* Assignment of value for DEC_FACTOR in the ISI_PDECF register */
#define ISI_PDECF_Msk                         _UINT32_(0x000000FF)                                 /* (ISI_PDECF) Register Mask  */


/* -------- ISI_Y2R_SET0 : (ISI Offset: 0x10) (R/W 32) ISI Color Space Conversion YCrCb To RGB Set 0 Register -------- */
#define ISI_Y2R_SET0_C0_Pos                   _UINT32_(0)                                          /* (ISI_Y2R_SET0) Color Space Conversion Matrix Coefficient C0 Position */
#define ISI_Y2R_SET0_C0_Msk                   (_UINT32_(0xFF) << ISI_Y2R_SET0_C0_Pos)              /* (ISI_Y2R_SET0) Color Space Conversion Matrix Coefficient C0 Mask */
#define ISI_Y2R_SET0_C0(value)                (ISI_Y2R_SET0_C0_Msk & (_UINT32_(value) << ISI_Y2R_SET0_C0_Pos)) /* Assignment of value for C0 in the ISI_Y2R_SET0 register */
#define ISI_Y2R_SET0_C1_Pos                   _UINT32_(8)                                          /* (ISI_Y2R_SET0) Color Space Conversion Matrix Coefficient C1 Position */
#define ISI_Y2R_SET0_C1_Msk                   (_UINT32_(0xFF) << ISI_Y2R_SET0_C1_Pos)              /* (ISI_Y2R_SET0) Color Space Conversion Matrix Coefficient C1 Mask */
#define ISI_Y2R_SET0_C1(value)                (ISI_Y2R_SET0_C1_Msk & (_UINT32_(value) << ISI_Y2R_SET0_C1_Pos)) /* Assignment of value for C1 in the ISI_Y2R_SET0 register */
#define ISI_Y2R_SET0_C2_Pos                   _UINT32_(16)                                         /* (ISI_Y2R_SET0) Color Space Conversion Matrix Coefficient C2 Position */
#define ISI_Y2R_SET0_C2_Msk                   (_UINT32_(0xFF) << ISI_Y2R_SET0_C2_Pos)              /* (ISI_Y2R_SET0) Color Space Conversion Matrix Coefficient C2 Mask */
#define ISI_Y2R_SET0_C2(value)                (ISI_Y2R_SET0_C2_Msk & (_UINT32_(value) << ISI_Y2R_SET0_C2_Pos)) /* Assignment of value for C2 in the ISI_Y2R_SET0 register */
#define ISI_Y2R_SET0_C3_Pos                   _UINT32_(24)                                         /* (ISI_Y2R_SET0) Color Space Conversion Matrix Coefficient C3 Position */
#define ISI_Y2R_SET0_C3_Msk                   (_UINT32_(0xFF) << ISI_Y2R_SET0_C3_Pos)              /* (ISI_Y2R_SET0) Color Space Conversion Matrix Coefficient C3 Mask */
#define ISI_Y2R_SET0_C3(value)                (ISI_Y2R_SET0_C3_Msk & (_UINT32_(value) << ISI_Y2R_SET0_C3_Pos)) /* Assignment of value for C3 in the ISI_Y2R_SET0 register */
#define ISI_Y2R_SET0_Msk                      _UINT32_(0xFFFFFFFF)                                 /* (ISI_Y2R_SET0) Register Mask  */


/* -------- ISI_Y2R_SET1 : (ISI Offset: 0x14) (R/W 32) ISI Color Space Conversion YCrCb To RGB Set 1 Register -------- */
#define ISI_Y2R_SET1_C4_Pos                   _UINT32_(0)                                          /* (ISI_Y2R_SET1) Color Space Conversion Matrix Coefficient C4 Position */
#define ISI_Y2R_SET1_C4_Msk                   (_UINT32_(0x1FF) << ISI_Y2R_SET1_C4_Pos)             /* (ISI_Y2R_SET1) Color Space Conversion Matrix Coefficient C4 Mask */
#define ISI_Y2R_SET1_C4(value)                (ISI_Y2R_SET1_C4_Msk & (_UINT32_(value) << ISI_Y2R_SET1_C4_Pos)) /* Assignment of value for C4 in the ISI_Y2R_SET1 register */
#define ISI_Y2R_SET1_Yoff_Pos                 _UINT32_(12)                                         /* (ISI_Y2R_SET1) Color Space Conversion Luminance Default Offset Position */
#define ISI_Y2R_SET1_Yoff_Msk                 (_UINT32_(0x1) << ISI_Y2R_SET1_Yoff_Pos)             /* (ISI_Y2R_SET1) Color Space Conversion Luminance Default Offset Mask */
#define ISI_Y2R_SET1_Yoff(value)              (ISI_Y2R_SET1_Yoff_Msk & (_UINT32_(value) << ISI_Y2R_SET1_Yoff_Pos)) /* Assignment of value for Yoff in the ISI_Y2R_SET1 register */
#define ISI_Y2R_SET1_Croff_Pos                _UINT32_(13)                                         /* (ISI_Y2R_SET1) Color Space Conversion Red Chrominance Default Offset Position */
#define ISI_Y2R_SET1_Croff_Msk                (_UINT32_(0x1) << ISI_Y2R_SET1_Croff_Pos)            /* (ISI_Y2R_SET1) Color Space Conversion Red Chrominance Default Offset Mask */
#define ISI_Y2R_SET1_Croff(value)             (ISI_Y2R_SET1_Croff_Msk & (_UINT32_(value) << ISI_Y2R_SET1_Croff_Pos)) /* Assignment of value for Croff in the ISI_Y2R_SET1 register */
#define ISI_Y2R_SET1_Cboff_Pos                _UINT32_(14)                                         /* (ISI_Y2R_SET1) Color Space Conversion Blue Chrominance Default Offset Position */
#define ISI_Y2R_SET1_Cboff_Msk                (_UINT32_(0x1) << ISI_Y2R_SET1_Cboff_Pos)            /* (ISI_Y2R_SET1) Color Space Conversion Blue Chrominance Default Offset Mask */
#define ISI_Y2R_SET1_Cboff(value)             (ISI_Y2R_SET1_Cboff_Msk & (_UINT32_(value) << ISI_Y2R_SET1_Cboff_Pos)) /* Assignment of value for Cboff in the ISI_Y2R_SET1 register */
#define ISI_Y2R_SET1_Msk                      _UINT32_(0x000071FF)                                 /* (ISI_Y2R_SET1) Register Mask  */


/* -------- ISI_R2Y_SET0 : (ISI Offset: 0x18) (R/W 32) ISI Color Space Conversion RGB To YCrCb Set 0 Register -------- */
#define ISI_R2Y_SET0_C0_Pos                   _UINT32_(0)                                          /* (ISI_R2Y_SET0) Color Space Conversion Matrix Coefficient C0 Position */
#define ISI_R2Y_SET0_C0_Msk                   (_UINT32_(0x7F) << ISI_R2Y_SET0_C0_Pos)              /* (ISI_R2Y_SET0) Color Space Conversion Matrix Coefficient C0 Mask */
#define ISI_R2Y_SET0_C0(value)                (ISI_R2Y_SET0_C0_Msk & (_UINT32_(value) << ISI_R2Y_SET0_C0_Pos)) /* Assignment of value for C0 in the ISI_R2Y_SET0 register */
#define ISI_R2Y_SET0_C1_Pos                   _UINT32_(8)                                          /* (ISI_R2Y_SET0) Color Space Conversion Matrix Coefficient C1 Position */
#define ISI_R2Y_SET0_C1_Msk                   (_UINT32_(0x7F) << ISI_R2Y_SET0_C1_Pos)              /* (ISI_R2Y_SET0) Color Space Conversion Matrix Coefficient C1 Mask */
#define ISI_R2Y_SET0_C1(value)                (ISI_R2Y_SET0_C1_Msk & (_UINT32_(value) << ISI_R2Y_SET0_C1_Pos)) /* Assignment of value for C1 in the ISI_R2Y_SET0 register */
#define ISI_R2Y_SET0_C2_Pos                   _UINT32_(16)                                         /* (ISI_R2Y_SET0) Color Space Conversion Matrix Coefficient C2 Position */
#define ISI_R2Y_SET0_C2_Msk                   (_UINT32_(0x7F) << ISI_R2Y_SET0_C2_Pos)              /* (ISI_R2Y_SET0) Color Space Conversion Matrix Coefficient C2 Mask */
#define ISI_R2Y_SET0_C2(value)                (ISI_R2Y_SET0_C2_Msk & (_UINT32_(value) << ISI_R2Y_SET0_C2_Pos)) /* Assignment of value for C2 in the ISI_R2Y_SET0 register */
#define ISI_R2Y_SET0_Roff_Pos                 _UINT32_(24)                                         /* (ISI_R2Y_SET0) Color Space Conversion Red Component Offset Position */
#define ISI_R2Y_SET0_Roff_Msk                 (_UINT32_(0x1) << ISI_R2Y_SET0_Roff_Pos)             /* (ISI_R2Y_SET0) Color Space Conversion Red Component Offset Mask */
#define ISI_R2Y_SET0_Roff(value)              (ISI_R2Y_SET0_Roff_Msk & (_UINT32_(value) << ISI_R2Y_SET0_Roff_Pos)) /* Assignment of value for Roff in the ISI_R2Y_SET0 register */
#define ISI_R2Y_SET0_Msk                      _UINT32_(0x017F7F7F)                                 /* (ISI_R2Y_SET0) Register Mask  */


/* -------- ISI_R2Y_SET1 : (ISI Offset: 0x1C) (R/W 32) ISI Color Space Conversion RGB To YCrCb Set 1 Register -------- */
#define ISI_R2Y_SET1_C3_Pos                   _UINT32_(0)                                          /* (ISI_R2Y_SET1) Color Space Conversion Matrix Coefficient C3 Position */
#define ISI_R2Y_SET1_C3_Msk                   (_UINT32_(0x7F) << ISI_R2Y_SET1_C3_Pos)              /* (ISI_R2Y_SET1) Color Space Conversion Matrix Coefficient C3 Mask */
#define ISI_R2Y_SET1_C3(value)                (ISI_R2Y_SET1_C3_Msk & (_UINT32_(value) << ISI_R2Y_SET1_C3_Pos)) /* Assignment of value for C3 in the ISI_R2Y_SET1 register */
#define ISI_R2Y_SET1_C4_Pos                   _UINT32_(8)                                          /* (ISI_R2Y_SET1) Color Space Conversion Matrix Coefficient C4 Position */
#define ISI_R2Y_SET1_C4_Msk                   (_UINT32_(0x7F) << ISI_R2Y_SET1_C4_Pos)              /* (ISI_R2Y_SET1) Color Space Conversion Matrix Coefficient C4 Mask */
#define ISI_R2Y_SET1_C4(value)                (ISI_R2Y_SET1_C4_Msk & (_UINT32_(value) << ISI_R2Y_SET1_C4_Pos)) /* Assignment of value for C4 in the ISI_R2Y_SET1 register */
#define ISI_R2Y_SET1_C5_Pos                   _UINT32_(16)                                         /* (ISI_R2Y_SET1) Color Space Conversion Matrix Coefficient C5 Position */
#define ISI_R2Y_SET1_C5_Msk                   (_UINT32_(0x7F) << ISI_R2Y_SET1_C5_Pos)              /* (ISI_R2Y_SET1) Color Space Conversion Matrix Coefficient C5 Mask */
#define ISI_R2Y_SET1_C5(value)                (ISI_R2Y_SET1_C5_Msk & (_UINT32_(value) << ISI_R2Y_SET1_C5_Pos)) /* Assignment of value for C5 in the ISI_R2Y_SET1 register */
#define ISI_R2Y_SET1_Goff_Pos                 _UINT32_(24)                                         /* (ISI_R2Y_SET1) Color Space Conversion Green Component Offset Position */
#define ISI_R2Y_SET1_Goff_Msk                 (_UINT32_(0x1) << ISI_R2Y_SET1_Goff_Pos)             /* (ISI_R2Y_SET1) Color Space Conversion Green Component Offset Mask */
#define ISI_R2Y_SET1_Goff(value)              (ISI_R2Y_SET1_Goff_Msk & (_UINT32_(value) << ISI_R2Y_SET1_Goff_Pos)) /* Assignment of value for Goff in the ISI_R2Y_SET1 register */
#define ISI_R2Y_SET1_Msk                      _UINT32_(0x017F7F7F)                                 /* (ISI_R2Y_SET1) Register Mask  */


/* -------- ISI_R2Y_SET2 : (ISI Offset: 0x20) (R/W 32) ISI Color Space Conversion RGB To YCrCb Set 2 Register -------- */
#define ISI_R2Y_SET2_C6_Pos                   _UINT32_(0)                                          /* (ISI_R2Y_SET2) Color Space Conversion Matrix Coefficient C6 Position */
#define ISI_R2Y_SET2_C6_Msk                   (_UINT32_(0x7F) << ISI_R2Y_SET2_C6_Pos)              /* (ISI_R2Y_SET2) Color Space Conversion Matrix Coefficient C6 Mask */
#define ISI_R2Y_SET2_C6(value)                (ISI_R2Y_SET2_C6_Msk & (_UINT32_(value) << ISI_R2Y_SET2_C6_Pos)) /* Assignment of value for C6 in the ISI_R2Y_SET2 register */
#define ISI_R2Y_SET2_C7_Pos                   _UINT32_(8)                                          /* (ISI_R2Y_SET2) Color Space Conversion Matrix Coefficient C7 Position */
#define ISI_R2Y_SET2_C7_Msk                   (_UINT32_(0x7F) << ISI_R2Y_SET2_C7_Pos)              /* (ISI_R2Y_SET2) Color Space Conversion Matrix Coefficient C7 Mask */
#define ISI_R2Y_SET2_C7(value)                (ISI_R2Y_SET2_C7_Msk & (_UINT32_(value) << ISI_R2Y_SET2_C7_Pos)) /* Assignment of value for C7 in the ISI_R2Y_SET2 register */
#define ISI_R2Y_SET2_C8_Pos                   _UINT32_(16)                                         /* (ISI_R2Y_SET2) Color Space Conversion Matrix Coefficient C8 Position */
#define ISI_R2Y_SET2_C8_Msk                   (_UINT32_(0x7F) << ISI_R2Y_SET2_C8_Pos)              /* (ISI_R2Y_SET2) Color Space Conversion Matrix Coefficient C8 Mask */
#define ISI_R2Y_SET2_C8(value)                (ISI_R2Y_SET2_C8_Msk & (_UINT32_(value) << ISI_R2Y_SET2_C8_Pos)) /* Assignment of value for C8 in the ISI_R2Y_SET2 register */
#define ISI_R2Y_SET2_Boff_Pos                 _UINT32_(24)                                         /* (ISI_R2Y_SET2) Color Space Conversion Blue Component Offset Position */
#define ISI_R2Y_SET2_Boff_Msk                 (_UINT32_(0x1) << ISI_R2Y_SET2_Boff_Pos)             /* (ISI_R2Y_SET2) Color Space Conversion Blue Component Offset Mask */
#define ISI_R2Y_SET2_Boff(value)              (ISI_R2Y_SET2_Boff_Msk & (_UINT32_(value) << ISI_R2Y_SET2_Boff_Pos)) /* Assignment of value for Boff in the ISI_R2Y_SET2 register */
#define ISI_R2Y_SET2_Msk                      _UINT32_(0x017F7F7F)                                 /* (ISI_R2Y_SET2) Register Mask  */


/* -------- ISI_CR : (ISI Offset: 0x24) ( /W 32) ISI Control Register -------- */
#define ISI_CR_ISI_EN_Pos                     _UINT32_(0)                                          /* (ISI_CR) ISI Module Enable Request Position */
#define ISI_CR_ISI_EN_Msk                     (_UINT32_(0x1) << ISI_CR_ISI_EN_Pos)                 /* (ISI_CR) ISI Module Enable Request Mask */
#define ISI_CR_ISI_EN(value)                  (ISI_CR_ISI_EN_Msk & (_UINT32_(value) << ISI_CR_ISI_EN_Pos)) /* Assignment of value for ISI_EN in the ISI_CR register */
#define ISI_CR_ISI_DIS_Pos                    _UINT32_(1)                                          /* (ISI_CR) ISI Module Disable Request Position */
#define ISI_CR_ISI_DIS_Msk                    (_UINT32_(0x1) << ISI_CR_ISI_DIS_Pos)                /* (ISI_CR) ISI Module Disable Request Mask */
#define ISI_CR_ISI_DIS(value)                 (ISI_CR_ISI_DIS_Msk & (_UINT32_(value) << ISI_CR_ISI_DIS_Pos)) /* Assignment of value for ISI_DIS in the ISI_CR register */
#define ISI_CR_ISI_SRST_Pos                   _UINT32_(2)                                          /* (ISI_CR) ISI Software Reset Request Position */
#define ISI_CR_ISI_SRST_Msk                   (_UINT32_(0x1) << ISI_CR_ISI_SRST_Pos)               /* (ISI_CR) ISI Software Reset Request Mask */
#define ISI_CR_ISI_SRST(value)                (ISI_CR_ISI_SRST_Msk & (_UINT32_(value) << ISI_CR_ISI_SRST_Pos)) /* Assignment of value for ISI_SRST in the ISI_CR register */
#define ISI_CR_ISI_CDC_Pos                    _UINT32_(8)                                          /* (ISI_CR) ISI Codec Request Position */
#define ISI_CR_ISI_CDC_Msk                    (_UINT32_(0x1) << ISI_CR_ISI_CDC_Pos)                /* (ISI_CR) ISI Codec Request Mask */
#define ISI_CR_ISI_CDC(value)                 (ISI_CR_ISI_CDC_Msk & (_UINT32_(value) << ISI_CR_ISI_CDC_Pos)) /* Assignment of value for ISI_CDC in the ISI_CR register */
#define ISI_CR_Msk                            _UINT32_(0x00000107)                                 /* (ISI_CR) Register Mask  */


/* -------- ISI_SR : (ISI Offset: 0x28) ( R/ 32) ISI Status Register -------- */
#define ISI_SR_ENABLE_Pos                     _UINT32_(0)                                          /* (ISI_SR) Module Enable Position */
#define ISI_SR_ENABLE_Msk                     (_UINT32_(0x1) << ISI_SR_ENABLE_Pos)                 /* (ISI_SR) Module Enable Mask */
#define ISI_SR_ENABLE(value)                  (ISI_SR_ENABLE_Msk & (_UINT32_(value) << ISI_SR_ENABLE_Pos)) /* Assignment of value for ENABLE in the ISI_SR register */
#define ISI_SR_DIS_DONE_Pos                   _UINT32_(1)                                          /* (ISI_SR) Module Disable Request has Terminated (cleared on read) Position */
#define ISI_SR_DIS_DONE_Msk                   (_UINT32_(0x1) << ISI_SR_DIS_DONE_Pos)               /* (ISI_SR) Module Disable Request has Terminated (cleared on read) Mask */
#define ISI_SR_DIS_DONE(value)                (ISI_SR_DIS_DONE_Msk & (_UINT32_(value) << ISI_SR_DIS_DONE_Pos)) /* Assignment of value for DIS_DONE in the ISI_SR register */
#define ISI_SR_SRST_Pos                       _UINT32_(2)                                          /* (ISI_SR) Module Software Reset Request has Terminated (cleared on read) Position */
#define ISI_SR_SRST_Msk                       (_UINT32_(0x1) << ISI_SR_SRST_Pos)                   /* (ISI_SR) Module Software Reset Request has Terminated (cleared on read) Mask */
#define ISI_SR_SRST(value)                    (ISI_SR_SRST_Msk & (_UINT32_(value) << ISI_SR_SRST_Pos)) /* Assignment of value for SRST in the ISI_SR register */
#define ISI_SR_CDC_PND_Pos                    _UINT32_(8)                                          /* (ISI_SR) Pending Codec Request Position */
#define ISI_SR_CDC_PND_Msk                    (_UINT32_(0x1) << ISI_SR_CDC_PND_Pos)                /* (ISI_SR) Pending Codec Request Mask */
#define ISI_SR_CDC_PND(value)                 (ISI_SR_CDC_PND_Msk & (_UINT32_(value) << ISI_SR_CDC_PND_Pos)) /* Assignment of value for CDC_PND in the ISI_SR register */
#define ISI_SR_VSYNC_Pos                      _UINT32_(10)                                         /* (ISI_SR) Vertical Synchronization (cleared on read) Position */
#define ISI_SR_VSYNC_Msk                      (_UINT32_(0x1) << ISI_SR_VSYNC_Pos)                  /* (ISI_SR) Vertical Synchronization (cleared on read) Mask */
#define ISI_SR_VSYNC(value)                   (ISI_SR_VSYNC_Msk & (_UINT32_(value) << ISI_SR_VSYNC_Pos)) /* Assignment of value for VSYNC in the ISI_SR register */
#define ISI_SR_PXFR_DONE_Pos                  _UINT32_(16)                                         /* (ISI_SR) Preview DMA Transfer has Terminated (cleared on read) Position */
#define ISI_SR_PXFR_DONE_Msk                  (_UINT32_(0x1) << ISI_SR_PXFR_DONE_Pos)              /* (ISI_SR) Preview DMA Transfer has Terminated (cleared on read) Mask */
#define ISI_SR_PXFR_DONE(value)               (ISI_SR_PXFR_DONE_Msk & (_UINT32_(value) << ISI_SR_PXFR_DONE_Pos)) /* Assignment of value for PXFR_DONE in the ISI_SR register */
#define ISI_SR_CXFR_DONE_Pos                  _UINT32_(17)                                         /* (ISI_SR) Codec DMA Transfer has Terminated (cleared on read) Position */
#define ISI_SR_CXFR_DONE_Msk                  (_UINT32_(0x1) << ISI_SR_CXFR_DONE_Pos)              /* (ISI_SR) Codec DMA Transfer has Terminated (cleared on read) Mask */
#define ISI_SR_CXFR_DONE(value)               (ISI_SR_CXFR_DONE_Msk & (_UINT32_(value) << ISI_SR_CXFR_DONE_Pos)) /* Assignment of value for CXFR_DONE in the ISI_SR register */
#define ISI_SR_SIP_Pos                        _UINT32_(19)                                         /* (ISI_SR) Synchronization in Progress Position */
#define ISI_SR_SIP_Msk                        (_UINT32_(0x1) << ISI_SR_SIP_Pos)                    /* (ISI_SR) Synchronization in Progress Mask */
#define ISI_SR_SIP(value)                     (ISI_SR_SIP_Msk & (_UINT32_(value) << ISI_SR_SIP_Pos)) /* Assignment of value for SIP in the ISI_SR register */
#define ISI_SR_P_OVR_Pos                      _UINT32_(24)                                         /* (ISI_SR) Preview Datapath Overflow (cleared on read) Position */
#define ISI_SR_P_OVR_Msk                      (_UINT32_(0x1) << ISI_SR_P_OVR_Pos)                  /* (ISI_SR) Preview Datapath Overflow (cleared on read) Mask */
#define ISI_SR_P_OVR(value)                   (ISI_SR_P_OVR_Msk & (_UINT32_(value) << ISI_SR_P_OVR_Pos)) /* Assignment of value for P_OVR in the ISI_SR register */
#define ISI_SR_C_OVR_Pos                      _UINT32_(25)                                         /* (ISI_SR) Codec Datapath Overflow (cleared on read) Position */
#define ISI_SR_C_OVR_Msk                      (_UINT32_(0x1) << ISI_SR_C_OVR_Pos)                  /* (ISI_SR) Codec Datapath Overflow (cleared on read) Mask */
#define ISI_SR_C_OVR(value)                   (ISI_SR_C_OVR_Msk & (_UINT32_(value) << ISI_SR_C_OVR_Pos)) /* Assignment of value for C_OVR in the ISI_SR register */
#define ISI_SR_CRC_ERR_Pos                    _UINT32_(26)                                         /* (ISI_SR) CRC Synchronization Error (cleared on read) Position */
#define ISI_SR_CRC_ERR_Msk                    (_UINT32_(0x1) << ISI_SR_CRC_ERR_Pos)                /* (ISI_SR) CRC Synchronization Error (cleared on read) Mask */
#define ISI_SR_CRC_ERR(value)                 (ISI_SR_CRC_ERR_Msk & (_UINT32_(value) << ISI_SR_CRC_ERR_Pos)) /* Assignment of value for CRC_ERR in the ISI_SR register */
#define ISI_SR_FR_OVR_Pos                     _UINT32_(27)                                         /* (ISI_SR) Frame Rate Overrun (cleared on read) Position */
#define ISI_SR_FR_OVR_Msk                     (_UINT32_(0x1) << ISI_SR_FR_OVR_Pos)                 /* (ISI_SR) Frame Rate Overrun (cleared on read) Mask */
#define ISI_SR_FR_OVR(value)                  (ISI_SR_FR_OVR_Msk & (_UINT32_(value) << ISI_SR_FR_OVR_Pos)) /* Assignment of value for FR_OVR in the ISI_SR register */
#define ISI_SR_Msk                            _UINT32_(0x0F0B0507)                                 /* (ISI_SR) Register Mask  */


/* -------- ISI_IER : (ISI Offset: 0x2C) ( /W 32) ISI Interrupt Enable Register -------- */
#define ISI_IER_DIS_DONE_Pos                  _UINT32_(1)                                          /* (ISI_IER) Disable Done Interrupt Enable Position */
#define ISI_IER_DIS_DONE_Msk                  (_UINT32_(0x1) << ISI_IER_DIS_DONE_Pos)              /* (ISI_IER) Disable Done Interrupt Enable Mask */
#define ISI_IER_DIS_DONE(value)               (ISI_IER_DIS_DONE_Msk & (_UINT32_(value) << ISI_IER_DIS_DONE_Pos)) /* Assignment of value for DIS_DONE in the ISI_IER register */
#define ISI_IER_SRST_Pos                      _UINT32_(2)                                          /* (ISI_IER) Software Reset Interrupt Enable Position */
#define ISI_IER_SRST_Msk                      (_UINT32_(0x1) << ISI_IER_SRST_Pos)                  /* (ISI_IER) Software Reset Interrupt Enable Mask */
#define ISI_IER_SRST(value)                   (ISI_IER_SRST_Msk & (_UINT32_(value) << ISI_IER_SRST_Pos)) /* Assignment of value for SRST in the ISI_IER register */
#define ISI_IER_VSYNC_Pos                     _UINT32_(10)                                         /* (ISI_IER) Vertical Synchronization Interrupt Enable Position */
#define ISI_IER_VSYNC_Msk                     (_UINT32_(0x1) << ISI_IER_VSYNC_Pos)                 /* (ISI_IER) Vertical Synchronization Interrupt Enable Mask */
#define ISI_IER_VSYNC(value)                  (ISI_IER_VSYNC_Msk & (_UINT32_(value) << ISI_IER_VSYNC_Pos)) /* Assignment of value for VSYNC in the ISI_IER register */
#define ISI_IER_PXFR_DONE_Pos                 _UINT32_(16)                                         /* (ISI_IER) Preview DMA Transfer Done Interrupt Enable Position */
#define ISI_IER_PXFR_DONE_Msk                 (_UINT32_(0x1) << ISI_IER_PXFR_DONE_Pos)             /* (ISI_IER) Preview DMA Transfer Done Interrupt Enable Mask */
#define ISI_IER_PXFR_DONE(value)              (ISI_IER_PXFR_DONE_Msk & (_UINT32_(value) << ISI_IER_PXFR_DONE_Pos)) /* Assignment of value for PXFR_DONE in the ISI_IER register */
#define ISI_IER_CXFR_DONE_Pos                 _UINT32_(17)                                         /* (ISI_IER) Codec DMA Transfer Done Interrupt Enable Position */
#define ISI_IER_CXFR_DONE_Msk                 (_UINT32_(0x1) << ISI_IER_CXFR_DONE_Pos)             /* (ISI_IER) Codec DMA Transfer Done Interrupt Enable Mask */
#define ISI_IER_CXFR_DONE(value)              (ISI_IER_CXFR_DONE_Msk & (_UINT32_(value) << ISI_IER_CXFR_DONE_Pos)) /* Assignment of value for CXFR_DONE in the ISI_IER register */
#define ISI_IER_P_OVR_Pos                     _UINT32_(24)                                         /* (ISI_IER) Preview Datapath Overflow Interrupt Enable Position */
#define ISI_IER_P_OVR_Msk                     (_UINT32_(0x1) << ISI_IER_P_OVR_Pos)                 /* (ISI_IER) Preview Datapath Overflow Interrupt Enable Mask */
#define ISI_IER_P_OVR(value)                  (ISI_IER_P_OVR_Msk & (_UINT32_(value) << ISI_IER_P_OVR_Pos)) /* Assignment of value for P_OVR in the ISI_IER register */
#define ISI_IER_C_OVR_Pos                     _UINT32_(25)                                         /* (ISI_IER) Codec Datapath Overflow Interrupt Enable Position */
#define ISI_IER_C_OVR_Msk                     (_UINT32_(0x1) << ISI_IER_C_OVR_Pos)                 /* (ISI_IER) Codec Datapath Overflow Interrupt Enable Mask */
#define ISI_IER_C_OVR(value)                  (ISI_IER_C_OVR_Msk & (_UINT32_(value) << ISI_IER_C_OVR_Pos)) /* Assignment of value for C_OVR in the ISI_IER register */
#define ISI_IER_CRC_ERR_Pos                   _UINT32_(26)                                         /* (ISI_IER) Embedded Synchronization CRC Error Interrupt Enable Position */
#define ISI_IER_CRC_ERR_Msk                   (_UINT32_(0x1) << ISI_IER_CRC_ERR_Pos)               /* (ISI_IER) Embedded Synchronization CRC Error Interrupt Enable Mask */
#define ISI_IER_CRC_ERR(value)                (ISI_IER_CRC_ERR_Msk & (_UINT32_(value) << ISI_IER_CRC_ERR_Pos)) /* Assignment of value for CRC_ERR in the ISI_IER register */
#define ISI_IER_FR_OVR_Pos                    _UINT32_(27)                                         /* (ISI_IER) Frame Rate Overflow Interrupt Enable Position */
#define ISI_IER_FR_OVR_Msk                    (_UINT32_(0x1) << ISI_IER_FR_OVR_Pos)                /* (ISI_IER) Frame Rate Overflow Interrupt Enable Mask */
#define ISI_IER_FR_OVR(value)                 (ISI_IER_FR_OVR_Msk & (_UINT32_(value) << ISI_IER_FR_OVR_Pos)) /* Assignment of value for FR_OVR in the ISI_IER register */
#define ISI_IER_Msk                           _UINT32_(0x0F030406)                                 /* (ISI_IER) Register Mask  */


/* -------- ISI_IDR : (ISI Offset: 0x30) ( /W 32) ISI Interrupt Disable Register -------- */
#define ISI_IDR_DIS_DONE_Pos                  _UINT32_(1)                                          /* (ISI_IDR) Disable Done Interrupt Disable Position */
#define ISI_IDR_DIS_DONE_Msk                  (_UINT32_(0x1) << ISI_IDR_DIS_DONE_Pos)              /* (ISI_IDR) Disable Done Interrupt Disable Mask */
#define ISI_IDR_DIS_DONE(value)               (ISI_IDR_DIS_DONE_Msk & (_UINT32_(value) << ISI_IDR_DIS_DONE_Pos)) /* Assignment of value for DIS_DONE in the ISI_IDR register */
#define ISI_IDR_SRST_Pos                      _UINT32_(2)                                          /* (ISI_IDR) Software Reset Interrupt Disable Position */
#define ISI_IDR_SRST_Msk                      (_UINT32_(0x1) << ISI_IDR_SRST_Pos)                  /* (ISI_IDR) Software Reset Interrupt Disable Mask */
#define ISI_IDR_SRST(value)                   (ISI_IDR_SRST_Msk & (_UINT32_(value) << ISI_IDR_SRST_Pos)) /* Assignment of value for SRST in the ISI_IDR register */
#define ISI_IDR_VSYNC_Pos                     _UINT32_(10)                                         /* (ISI_IDR) Vertical Synchronization Interrupt Disable Position */
#define ISI_IDR_VSYNC_Msk                     (_UINT32_(0x1) << ISI_IDR_VSYNC_Pos)                 /* (ISI_IDR) Vertical Synchronization Interrupt Disable Mask */
#define ISI_IDR_VSYNC(value)                  (ISI_IDR_VSYNC_Msk & (_UINT32_(value) << ISI_IDR_VSYNC_Pos)) /* Assignment of value for VSYNC in the ISI_IDR register */
#define ISI_IDR_PXFR_DONE_Pos                 _UINT32_(16)                                         /* (ISI_IDR) Preview DMA Transfer Done Interrupt Disable Position */
#define ISI_IDR_PXFR_DONE_Msk                 (_UINT32_(0x1) << ISI_IDR_PXFR_DONE_Pos)             /* (ISI_IDR) Preview DMA Transfer Done Interrupt Disable Mask */
#define ISI_IDR_PXFR_DONE(value)              (ISI_IDR_PXFR_DONE_Msk & (_UINT32_(value) << ISI_IDR_PXFR_DONE_Pos)) /* Assignment of value for PXFR_DONE in the ISI_IDR register */
#define ISI_IDR_CXFR_DONE_Pos                 _UINT32_(17)                                         /* (ISI_IDR) Codec DMA Transfer Done Interrupt Disable Position */
#define ISI_IDR_CXFR_DONE_Msk                 (_UINT32_(0x1) << ISI_IDR_CXFR_DONE_Pos)             /* (ISI_IDR) Codec DMA Transfer Done Interrupt Disable Mask */
#define ISI_IDR_CXFR_DONE(value)              (ISI_IDR_CXFR_DONE_Msk & (_UINT32_(value) << ISI_IDR_CXFR_DONE_Pos)) /* Assignment of value for CXFR_DONE in the ISI_IDR register */
#define ISI_IDR_P_OVR_Pos                     _UINT32_(24)                                         /* (ISI_IDR) Preview Datapath Overflow Interrupt Disable Position */
#define ISI_IDR_P_OVR_Msk                     (_UINT32_(0x1) << ISI_IDR_P_OVR_Pos)                 /* (ISI_IDR) Preview Datapath Overflow Interrupt Disable Mask */
#define ISI_IDR_P_OVR(value)                  (ISI_IDR_P_OVR_Msk & (_UINT32_(value) << ISI_IDR_P_OVR_Pos)) /* Assignment of value for P_OVR in the ISI_IDR register */
#define ISI_IDR_C_OVR_Pos                     _UINT32_(25)                                         /* (ISI_IDR) Codec Datapath Overflow Interrupt Disable Position */
#define ISI_IDR_C_OVR_Msk                     (_UINT32_(0x1) << ISI_IDR_C_OVR_Pos)                 /* (ISI_IDR) Codec Datapath Overflow Interrupt Disable Mask */
#define ISI_IDR_C_OVR(value)                  (ISI_IDR_C_OVR_Msk & (_UINT32_(value) << ISI_IDR_C_OVR_Pos)) /* Assignment of value for C_OVR in the ISI_IDR register */
#define ISI_IDR_CRC_ERR_Pos                   _UINT32_(26)                                         /* (ISI_IDR) Embedded Synchronization CRC Error Interrupt Disable Position */
#define ISI_IDR_CRC_ERR_Msk                   (_UINT32_(0x1) << ISI_IDR_CRC_ERR_Pos)               /* (ISI_IDR) Embedded Synchronization CRC Error Interrupt Disable Mask */
#define ISI_IDR_CRC_ERR(value)                (ISI_IDR_CRC_ERR_Msk & (_UINT32_(value) << ISI_IDR_CRC_ERR_Pos)) /* Assignment of value for CRC_ERR in the ISI_IDR register */
#define ISI_IDR_FR_OVR_Pos                    _UINT32_(27)                                         /* (ISI_IDR) Frame Rate Overflow Interrupt Disable Position */
#define ISI_IDR_FR_OVR_Msk                    (_UINT32_(0x1) << ISI_IDR_FR_OVR_Pos)                /* (ISI_IDR) Frame Rate Overflow Interrupt Disable Mask */
#define ISI_IDR_FR_OVR(value)                 (ISI_IDR_FR_OVR_Msk & (_UINT32_(value) << ISI_IDR_FR_OVR_Pos)) /* Assignment of value for FR_OVR in the ISI_IDR register */
#define ISI_IDR_Msk                           _UINT32_(0x0F030406)                                 /* (ISI_IDR) Register Mask  */


/* -------- ISI_IMR : (ISI Offset: 0x34) ( R/ 32) ISI Interrupt Mask Register -------- */
#define ISI_IMR_DIS_DONE_Pos                  _UINT32_(1)                                          /* (ISI_IMR) Module Disable Operation Completed Position */
#define ISI_IMR_DIS_DONE_Msk                  (_UINT32_(0x1) << ISI_IMR_DIS_DONE_Pos)              /* (ISI_IMR) Module Disable Operation Completed Mask */
#define ISI_IMR_DIS_DONE(value)               (ISI_IMR_DIS_DONE_Msk & (_UINT32_(value) << ISI_IMR_DIS_DONE_Pos)) /* Assignment of value for DIS_DONE in the ISI_IMR register */
#define ISI_IMR_SRST_Pos                      _UINT32_(2)                                          /* (ISI_IMR) Software Reset Completed Position */
#define ISI_IMR_SRST_Msk                      (_UINT32_(0x1) << ISI_IMR_SRST_Pos)                  /* (ISI_IMR) Software Reset Completed Mask */
#define ISI_IMR_SRST(value)                   (ISI_IMR_SRST_Msk & (_UINT32_(value) << ISI_IMR_SRST_Pos)) /* Assignment of value for SRST in the ISI_IMR register */
#define ISI_IMR_VSYNC_Pos                     _UINT32_(10)                                         /* (ISI_IMR) Vertical Synchronization Position */
#define ISI_IMR_VSYNC_Msk                     (_UINT32_(0x1) << ISI_IMR_VSYNC_Pos)                 /* (ISI_IMR) Vertical Synchronization Mask */
#define ISI_IMR_VSYNC(value)                  (ISI_IMR_VSYNC_Msk & (_UINT32_(value) << ISI_IMR_VSYNC_Pos)) /* Assignment of value for VSYNC in the ISI_IMR register */
#define ISI_IMR_PXFR_DONE_Pos                 _UINT32_(16)                                         /* (ISI_IMR) Preview DMA Transfer Completed Position */
#define ISI_IMR_PXFR_DONE_Msk                 (_UINT32_(0x1) << ISI_IMR_PXFR_DONE_Pos)             /* (ISI_IMR) Preview DMA Transfer Completed Mask */
#define ISI_IMR_PXFR_DONE(value)              (ISI_IMR_PXFR_DONE_Msk & (_UINT32_(value) << ISI_IMR_PXFR_DONE_Pos)) /* Assignment of value for PXFR_DONE in the ISI_IMR register */
#define ISI_IMR_CXFR_DONE_Pos                 _UINT32_(17)                                         /* (ISI_IMR) Codec DMA Transfer Completed Position */
#define ISI_IMR_CXFR_DONE_Msk                 (_UINT32_(0x1) << ISI_IMR_CXFR_DONE_Pos)             /* (ISI_IMR) Codec DMA Transfer Completed Mask */
#define ISI_IMR_CXFR_DONE(value)              (ISI_IMR_CXFR_DONE_Msk & (_UINT32_(value) << ISI_IMR_CXFR_DONE_Pos)) /* Assignment of value for CXFR_DONE in the ISI_IMR register */
#define ISI_IMR_P_OVR_Pos                     _UINT32_(24)                                         /* (ISI_IMR) Preview FIFO Overflow Position */
#define ISI_IMR_P_OVR_Msk                     (_UINT32_(0x1) << ISI_IMR_P_OVR_Pos)                 /* (ISI_IMR) Preview FIFO Overflow Mask */
#define ISI_IMR_P_OVR(value)                  (ISI_IMR_P_OVR_Msk & (_UINT32_(value) << ISI_IMR_P_OVR_Pos)) /* Assignment of value for P_OVR in the ISI_IMR register */
#define ISI_IMR_C_OVR_Pos                     _UINT32_(25)                                         /* (ISI_IMR) Codec FIFO Overflow Position */
#define ISI_IMR_C_OVR_Msk                     (_UINT32_(0x1) << ISI_IMR_C_OVR_Pos)                 /* (ISI_IMR) Codec FIFO Overflow Mask */
#define ISI_IMR_C_OVR(value)                  (ISI_IMR_C_OVR_Msk & (_UINT32_(value) << ISI_IMR_C_OVR_Pos)) /* Assignment of value for C_OVR in the ISI_IMR register */
#define ISI_IMR_CRC_ERR_Pos                   _UINT32_(26)                                         /* (ISI_IMR) CRC Synchronization Error Position */
#define ISI_IMR_CRC_ERR_Msk                   (_UINT32_(0x1) << ISI_IMR_CRC_ERR_Pos)               /* (ISI_IMR) CRC Synchronization Error Mask */
#define ISI_IMR_CRC_ERR(value)                (ISI_IMR_CRC_ERR_Msk & (_UINT32_(value) << ISI_IMR_CRC_ERR_Pos)) /* Assignment of value for CRC_ERR in the ISI_IMR register */
#define ISI_IMR_FR_OVR_Pos                    _UINT32_(27)                                         /* (ISI_IMR) Frame Rate Overrun Position */
#define ISI_IMR_FR_OVR_Msk                    (_UINT32_(0x1) << ISI_IMR_FR_OVR_Pos)                /* (ISI_IMR) Frame Rate Overrun Mask */
#define ISI_IMR_FR_OVR(value)                 (ISI_IMR_FR_OVR_Msk & (_UINT32_(value) << ISI_IMR_FR_OVR_Pos)) /* Assignment of value for FR_OVR in the ISI_IMR register */
#define ISI_IMR_Msk                           _UINT32_(0x0F030406)                                 /* (ISI_IMR) Register Mask  */


/* -------- ISI_DMA_CHER : (ISI Offset: 0x38) ( /W 32) DMA Channel Enable Register -------- */
#define ISI_DMA_CHER_P_CH_EN_Pos              _UINT32_(0)                                          /* (ISI_DMA_CHER) Preview Channel Enable Position */
#define ISI_DMA_CHER_P_CH_EN_Msk              (_UINT32_(0x1) << ISI_DMA_CHER_P_CH_EN_Pos)          /* (ISI_DMA_CHER) Preview Channel Enable Mask */
#define ISI_DMA_CHER_P_CH_EN(value)           (ISI_DMA_CHER_P_CH_EN_Msk & (_UINT32_(value) << ISI_DMA_CHER_P_CH_EN_Pos)) /* Assignment of value for P_CH_EN in the ISI_DMA_CHER register */
#define ISI_DMA_CHER_C_CH_EN_Pos              _UINT32_(1)                                          /* (ISI_DMA_CHER) Codec Channel Enable Position */
#define ISI_DMA_CHER_C_CH_EN_Msk              (_UINT32_(0x1) << ISI_DMA_CHER_C_CH_EN_Pos)          /* (ISI_DMA_CHER) Codec Channel Enable Mask */
#define ISI_DMA_CHER_C_CH_EN(value)           (ISI_DMA_CHER_C_CH_EN_Msk & (_UINT32_(value) << ISI_DMA_CHER_C_CH_EN_Pos)) /* Assignment of value for C_CH_EN in the ISI_DMA_CHER register */
#define ISI_DMA_CHER_Msk                      _UINT32_(0x00000003)                                 /* (ISI_DMA_CHER) Register Mask  */


/* -------- ISI_DMA_CHDR : (ISI Offset: 0x3C) ( /W 32) DMA Channel Disable Register -------- */
#define ISI_DMA_CHDR_P_CH_DIS_Pos             _UINT32_(0)                                          /* (ISI_DMA_CHDR) Preview Channel Disable Request Position */
#define ISI_DMA_CHDR_P_CH_DIS_Msk             (_UINT32_(0x1) << ISI_DMA_CHDR_P_CH_DIS_Pos)         /* (ISI_DMA_CHDR) Preview Channel Disable Request Mask */
#define ISI_DMA_CHDR_P_CH_DIS(value)          (ISI_DMA_CHDR_P_CH_DIS_Msk & (_UINT32_(value) << ISI_DMA_CHDR_P_CH_DIS_Pos)) /* Assignment of value for P_CH_DIS in the ISI_DMA_CHDR register */
#define ISI_DMA_CHDR_C_CH_DIS_Pos             _UINT32_(1)                                          /* (ISI_DMA_CHDR) Codec Channel Disable Request Position */
#define ISI_DMA_CHDR_C_CH_DIS_Msk             (_UINT32_(0x1) << ISI_DMA_CHDR_C_CH_DIS_Pos)         /* (ISI_DMA_CHDR) Codec Channel Disable Request Mask */
#define ISI_DMA_CHDR_C_CH_DIS(value)          (ISI_DMA_CHDR_C_CH_DIS_Msk & (_UINT32_(value) << ISI_DMA_CHDR_C_CH_DIS_Pos)) /* Assignment of value for C_CH_DIS in the ISI_DMA_CHDR register */
#define ISI_DMA_CHDR_Msk                      _UINT32_(0x00000003)                                 /* (ISI_DMA_CHDR) Register Mask  */


/* -------- ISI_DMA_CHSR : (ISI Offset: 0x40) ( R/ 32) DMA Channel Status Register -------- */
#define ISI_DMA_CHSR_P_CH_S_Pos               _UINT32_(0)                                          /* (ISI_DMA_CHSR) Preview DMA Channel Status Position */
#define ISI_DMA_CHSR_P_CH_S_Msk               (_UINT32_(0x1) << ISI_DMA_CHSR_P_CH_S_Pos)           /* (ISI_DMA_CHSR) Preview DMA Channel Status Mask */
#define ISI_DMA_CHSR_P_CH_S(value)            (ISI_DMA_CHSR_P_CH_S_Msk & (_UINT32_(value) << ISI_DMA_CHSR_P_CH_S_Pos)) /* Assignment of value for P_CH_S in the ISI_DMA_CHSR register */
#define ISI_DMA_CHSR_C_CH_S_Pos               _UINT32_(1)                                          /* (ISI_DMA_CHSR) Code DMA Channel Status Position */
#define ISI_DMA_CHSR_C_CH_S_Msk               (_UINT32_(0x1) << ISI_DMA_CHSR_C_CH_S_Pos)           /* (ISI_DMA_CHSR) Code DMA Channel Status Mask */
#define ISI_DMA_CHSR_C_CH_S(value)            (ISI_DMA_CHSR_C_CH_S_Msk & (_UINT32_(value) << ISI_DMA_CHSR_C_CH_S_Pos)) /* Assignment of value for C_CH_S in the ISI_DMA_CHSR register */
#define ISI_DMA_CHSR_Msk                      _UINT32_(0x00000003)                                 /* (ISI_DMA_CHSR) Register Mask  */


/* -------- ISI_DMA_P_ADDR : (ISI Offset: 0x44) (R/W 32) DMA Preview Base Address Register -------- */
#define ISI_DMA_P_ADDR_P_ADDR_Pos             _UINT32_(2)                                          /* (ISI_DMA_P_ADDR) Preview Image Base Address Position */
#define ISI_DMA_P_ADDR_P_ADDR_Msk             (_UINT32_(0x3FFFFFFF) << ISI_DMA_P_ADDR_P_ADDR_Pos)  /* (ISI_DMA_P_ADDR) Preview Image Base Address Mask */
#define ISI_DMA_P_ADDR_P_ADDR(value)          (ISI_DMA_P_ADDR_P_ADDR_Msk & (_UINT32_(value) << ISI_DMA_P_ADDR_P_ADDR_Pos)) /* Assignment of value for P_ADDR in the ISI_DMA_P_ADDR register */
#define ISI_DMA_P_ADDR_Msk                    _UINT32_(0xFFFFFFFC)                                 /* (ISI_DMA_P_ADDR) Register Mask  */


/* -------- ISI_DMA_P_CTRL : (ISI Offset: 0x48) (R/W 32) DMA Preview Control Register -------- */
#define ISI_DMA_P_CTRL_P_FETCH_Pos            _UINT32_(0)                                          /* (ISI_DMA_P_CTRL) Descriptor Fetch Control Bit Position */
#define ISI_DMA_P_CTRL_P_FETCH_Msk            (_UINT32_(0x1) << ISI_DMA_P_CTRL_P_FETCH_Pos)        /* (ISI_DMA_P_CTRL) Descriptor Fetch Control Bit Mask */
#define ISI_DMA_P_CTRL_P_FETCH(value)         (ISI_DMA_P_CTRL_P_FETCH_Msk & (_UINT32_(value) << ISI_DMA_P_CTRL_P_FETCH_Pos)) /* Assignment of value for P_FETCH in the ISI_DMA_P_CTRL register */
#define ISI_DMA_P_CTRL_P_WB_Pos               _UINT32_(1)                                          /* (ISI_DMA_P_CTRL) Descriptor Writeback Control Bit Position */
#define ISI_DMA_P_CTRL_P_WB_Msk               (_UINT32_(0x1) << ISI_DMA_P_CTRL_P_WB_Pos)           /* (ISI_DMA_P_CTRL) Descriptor Writeback Control Bit Mask */
#define ISI_DMA_P_CTRL_P_WB(value)            (ISI_DMA_P_CTRL_P_WB_Msk & (_UINT32_(value) << ISI_DMA_P_CTRL_P_WB_Pos)) /* Assignment of value for P_WB in the ISI_DMA_P_CTRL register */
#define ISI_DMA_P_CTRL_P_IEN_Pos              _UINT32_(2)                                          /* (ISI_DMA_P_CTRL) Transfer Done Flag Control Position */
#define ISI_DMA_P_CTRL_P_IEN_Msk              (_UINT32_(0x1) << ISI_DMA_P_CTRL_P_IEN_Pos)          /* (ISI_DMA_P_CTRL) Transfer Done Flag Control Mask */
#define ISI_DMA_P_CTRL_P_IEN(value)           (ISI_DMA_P_CTRL_P_IEN_Msk & (_UINT32_(value) << ISI_DMA_P_CTRL_P_IEN_Pos)) /* Assignment of value for P_IEN in the ISI_DMA_P_CTRL register */
#define ISI_DMA_P_CTRL_P_DONE_Pos             _UINT32_(3)                                          /* (ISI_DMA_P_CTRL) Preview Transfer Done Position */
#define ISI_DMA_P_CTRL_P_DONE_Msk             (_UINT32_(0x1) << ISI_DMA_P_CTRL_P_DONE_Pos)         /* (ISI_DMA_P_CTRL) Preview Transfer Done Mask */
#define ISI_DMA_P_CTRL_P_DONE(value)          (ISI_DMA_P_CTRL_P_DONE_Msk & (_UINT32_(value) << ISI_DMA_P_CTRL_P_DONE_Pos)) /* Assignment of value for P_DONE in the ISI_DMA_P_CTRL register */
#define ISI_DMA_P_CTRL_Msk                    _UINT32_(0x0000000F)                                 /* (ISI_DMA_P_CTRL) Register Mask  */


/* -------- ISI_DMA_P_DSCR : (ISI Offset: 0x4C) (R/W 32) DMA Preview Descriptor Address Register -------- */
#define ISI_DMA_P_DSCR_P_DSCR_Pos             _UINT32_(2)                                          /* (ISI_DMA_P_DSCR) Preview Descriptor Base Address Position */
#define ISI_DMA_P_DSCR_P_DSCR_Msk             (_UINT32_(0x3FFFFFFF) << ISI_DMA_P_DSCR_P_DSCR_Pos)  /* (ISI_DMA_P_DSCR) Preview Descriptor Base Address Mask */
#define ISI_DMA_P_DSCR_P_DSCR(value)          (ISI_DMA_P_DSCR_P_DSCR_Msk & (_UINT32_(value) << ISI_DMA_P_DSCR_P_DSCR_Pos)) /* Assignment of value for P_DSCR in the ISI_DMA_P_DSCR register */
#define ISI_DMA_P_DSCR_Msk                    _UINT32_(0xFFFFFFFC)                                 /* (ISI_DMA_P_DSCR) Register Mask  */


/* -------- ISI_DMA_C_ADDR : (ISI Offset: 0x50) (R/W 32) DMA Codec Base Address Register -------- */
#define ISI_DMA_C_ADDR_C_ADDR_Pos             _UINT32_(2)                                          /* (ISI_DMA_C_ADDR) Codec Image Base Address Position */
#define ISI_DMA_C_ADDR_C_ADDR_Msk             (_UINT32_(0x3FFFFFFF) << ISI_DMA_C_ADDR_C_ADDR_Pos)  /* (ISI_DMA_C_ADDR) Codec Image Base Address Mask */
#define ISI_DMA_C_ADDR_C_ADDR(value)          (ISI_DMA_C_ADDR_C_ADDR_Msk & (_UINT32_(value) << ISI_DMA_C_ADDR_C_ADDR_Pos)) /* Assignment of value for C_ADDR in the ISI_DMA_C_ADDR register */
#define ISI_DMA_C_ADDR_Msk                    _UINT32_(0xFFFFFFFC)                                 /* (ISI_DMA_C_ADDR) Register Mask  */


/* -------- ISI_DMA_C_CTRL : (ISI Offset: 0x54) (R/W 32) DMA Codec Control Register -------- */
#define ISI_DMA_C_CTRL_C_FETCH_Pos            _UINT32_(0)                                          /* (ISI_DMA_C_CTRL) Descriptor Fetch Control Bit Position */
#define ISI_DMA_C_CTRL_C_FETCH_Msk            (_UINT32_(0x1) << ISI_DMA_C_CTRL_C_FETCH_Pos)        /* (ISI_DMA_C_CTRL) Descriptor Fetch Control Bit Mask */
#define ISI_DMA_C_CTRL_C_FETCH(value)         (ISI_DMA_C_CTRL_C_FETCH_Msk & (_UINT32_(value) << ISI_DMA_C_CTRL_C_FETCH_Pos)) /* Assignment of value for C_FETCH in the ISI_DMA_C_CTRL register */
#define ISI_DMA_C_CTRL_C_WB_Pos               _UINT32_(1)                                          /* (ISI_DMA_C_CTRL) Descriptor Writeback Control Bit Position */
#define ISI_DMA_C_CTRL_C_WB_Msk               (_UINT32_(0x1) << ISI_DMA_C_CTRL_C_WB_Pos)           /* (ISI_DMA_C_CTRL) Descriptor Writeback Control Bit Mask */
#define ISI_DMA_C_CTRL_C_WB(value)            (ISI_DMA_C_CTRL_C_WB_Msk & (_UINT32_(value) << ISI_DMA_C_CTRL_C_WB_Pos)) /* Assignment of value for C_WB in the ISI_DMA_C_CTRL register */
#define ISI_DMA_C_CTRL_C_IEN_Pos              _UINT32_(2)                                          /* (ISI_DMA_C_CTRL) Transfer Done Flag Control Position */
#define ISI_DMA_C_CTRL_C_IEN_Msk              (_UINT32_(0x1) << ISI_DMA_C_CTRL_C_IEN_Pos)          /* (ISI_DMA_C_CTRL) Transfer Done Flag Control Mask */
#define ISI_DMA_C_CTRL_C_IEN(value)           (ISI_DMA_C_CTRL_C_IEN_Msk & (_UINT32_(value) << ISI_DMA_C_CTRL_C_IEN_Pos)) /* Assignment of value for C_IEN in the ISI_DMA_C_CTRL register */
#define ISI_DMA_C_CTRL_C_DONE_Pos             _UINT32_(3)                                          /* (ISI_DMA_C_CTRL) Codec Transfer Done Position */
#define ISI_DMA_C_CTRL_C_DONE_Msk             (_UINT32_(0x1) << ISI_DMA_C_CTRL_C_DONE_Pos)         /* (ISI_DMA_C_CTRL) Codec Transfer Done Mask */
#define ISI_DMA_C_CTRL_C_DONE(value)          (ISI_DMA_C_CTRL_C_DONE_Msk & (_UINT32_(value) << ISI_DMA_C_CTRL_C_DONE_Pos)) /* Assignment of value for C_DONE in the ISI_DMA_C_CTRL register */
#define ISI_DMA_C_CTRL_Msk                    _UINT32_(0x0000000F)                                 /* (ISI_DMA_C_CTRL) Register Mask  */


/* -------- ISI_DMA_C_DSCR : (ISI Offset: 0x58) (R/W 32) DMA Codec Descriptor Address Register -------- */
#define ISI_DMA_C_DSCR_C_DSCR_Pos             _UINT32_(2)                                          /* (ISI_DMA_C_DSCR) Codec Descriptor Base Address Position */
#define ISI_DMA_C_DSCR_C_DSCR_Msk             (_UINT32_(0x3FFFFFFF) << ISI_DMA_C_DSCR_C_DSCR_Pos)  /* (ISI_DMA_C_DSCR) Codec Descriptor Base Address Mask */
#define ISI_DMA_C_DSCR_C_DSCR(value)          (ISI_DMA_C_DSCR_C_DSCR_Msk & (_UINT32_(value) << ISI_DMA_C_DSCR_C_DSCR_Pos)) /* Assignment of value for C_DSCR in the ISI_DMA_C_DSCR register */
#define ISI_DMA_C_DSCR_Msk                    _UINT32_(0xFFFFFFFC)                                 /* (ISI_DMA_C_DSCR) Register Mask  */


/* -------- ISI_WPMR : (ISI Offset: 0xE4) (R/W 32) Write Protection Mode Register -------- */
#define ISI_WPMR_WPEN_Pos                     _UINT32_(0)                                          /* (ISI_WPMR) Write Protection Enable Position */
#define ISI_WPMR_WPEN_Msk                     (_UINT32_(0x1) << ISI_WPMR_WPEN_Pos)                 /* (ISI_WPMR) Write Protection Enable Mask */
#define ISI_WPMR_WPEN(value)                  (ISI_WPMR_WPEN_Msk & (_UINT32_(value) << ISI_WPMR_WPEN_Pos)) /* Assignment of value for WPEN in the ISI_WPMR register */
#define ISI_WPMR_WPKEY_Pos                    _UINT32_(8)                                          /* (ISI_WPMR) Write Protection Key Password Position */
#define ISI_WPMR_WPKEY_Msk                    (_UINT32_(0xFFFFFF) << ISI_WPMR_WPKEY_Pos)           /* (ISI_WPMR) Write Protection Key Password Mask */
#define ISI_WPMR_WPKEY(value)                 (ISI_WPMR_WPKEY_Msk & (_UINT32_(value) << ISI_WPMR_WPKEY_Pos)) /* Assignment of value for WPKEY in the ISI_WPMR register */
#define   ISI_WPMR_WPKEY_PASSWD_Val           _UINT32_(0x495349)                                   /* (ISI_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.Always reads as 0.  */
#define ISI_WPMR_WPKEY_PASSWD                 (ISI_WPMR_WPKEY_PASSWD_Val << ISI_WPMR_WPKEY_Pos)    /* (ISI_WPMR) Writing any other value in this field aborts the write operation of the WPEN bit.Always reads as 0. Position */
#define ISI_WPMR_Msk                          _UINT32_(0xFFFFFF01)                                 /* (ISI_WPMR) Register Mask  */


/* -------- ISI_WPSR : (ISI Offset: 0xE8) ( R/ 32) Write Protection Status Register -------- */
#define ISI_WPSR_WPVS_Pos                     _UINT32_(0)                                          /* (ISI_WPSR) Write Protection Violation Status Position */
#define ISI_WPSR_WPVS_Msk                     (_UINT32_(0x1) << ISI_WPSR_WPVS_Pos)                 /* (ISI_WPSR) Write Protection Violation Status Mask */
#define ISI_WPSR_WPVS(value)                  (ISI_WPSR_WPVS_Msk & (_UINT32_(value) << ISI_WPSR_WPVS_Pos)) /* Assignment of value for WPVS in the ISI_WPSR register */
#define ISI_WPSR_WPVSRC_Pos                   _UINT32_(8)                                          /* (ISI_WPSR) Write Protection Violation Source Position */
#define ISI_WPSR_WPVSRC_Msk                   (_UINT32_(0xFFFF) << ISI_WPSR_WPVSRC_Pos)            /* (ISI_WPSR) Write Protection Violation Source Mask */
#define ISI_WPSR_WPVSRC(value)                (ISI_WPSR_WPVSRC_Msk & (_UINT32_(value) << ISI_WPSR_WPVSRC_Pos)) /* Assignment of value for WPVSRC in the ISI_WPSR register */
#define ISI_WPSR_Msk                          _UINT32_(0x00FFFF01)                                 /* (ISI_WPSR) Register Mask  */


/* ISI register offsets definitions */
#define ISI_CFG1_REG_OFST              _UINT32_(0x00)      /* (ISI_CFG1) ISI Configuration 1 Register Offset */
#define ISI_CFG2_REG_OFST              _UINT32_(0x04)      /* (ISI_CFG2) ISI Configuration 2 Register Offset */
#define ISI_PSIZE_REG_OFST             _UINT32_(0x08)      /* (ISI_PSIZE) ISI Preview Size Register Offset */
#define ISI_PDECF_REG_OFST             _UINT32_(0x0C)      /* (ISI_PDECF) ISI Preview Decimation Factor Register Offset */
#define ISI_Y2R_SET0_REG_OFST          _UINT32_(0x10)      /* (ISI_Y2R_SET0) ISI Color Space Conversion YCrCb To RGB Set 0 Register Offset */
#define ISI_Y2R_SET1_REG_OFST          _UINT32_(0x14)      /* (ISI_Y2R_SET1) ISI Color Space Conversion YCrCb To RGB Set 1 Register Offset */
#define ISI_R2Y_SET0_REG_OFST          _UINT32_(0x18)      /* (ISI_R2Y_SET0) ISI Color Space Conversion RGB To YCrCb Set 0 Register Offset */
#define ISI_R2Y_SET1_REG_OFST          _UINT32_(0x1C)      /* (ISI_R2Y_SET1) ISI Color Space Conversion RGB To YCrCb Set 1 Register Offset */
#define ISI_R2Y_SET2_REG_OFST          _UINT32_(0x20)      /* (ISI_R2Y_SET2) ISI Color Space Conversion RGB To YCrCb Set 2 Register Offset */
#define ISI_CR_REG_OFST                _UINT32_(0x24)      /* (ISI_CR) ISI Control Register Offset */
#define ISI_SR_REG_OFST                _UINT32_(0x28)      /* (ISI_SR) ISI Status Register Offset */
#define ISI_IER_REG_OFST               _UINT32_(0x2C)      /* (ISI_IER) ISI Interrupt Enable Register Offset */
#define ISI_IDR_REG_OFST               _UINT32_(0x30)      /* (ISI_IDR) ISI Interrupt Disable Register Offset */
#define ISI_IMR_REG_OFST               _UINT32_(0x34)      /* (ISI_IMR) ISI Interrupt Mask Register Offset */
#define ISI_DMA_CHER_REG_OFST          _UINT32_(0x38)      /* (ISI_DMA_CHER) DMA Channel Enable Register Offset */
#define ISI_DMA_CHDR_REG_OFST          _UINT32_(0x3C)      /* (ISI_DMA_CHDR) DMA Channel Disable Register Offset */
#define ISI_DMA_CHSR_REG_OFST          _UINT32_(0x40)      /* (ISI_DMA_CHSR) DMA Channel Status Register Offset */
#define ISI_DMA_P_ADDR_REG_OFST        _UINT32_(0x44)      /* (ISI_DMA_P_ADDR) DMA Preview Base Address Register Offset */
#define ISI_DMA_P_CTRL_REG_OFST        _UINT32_(0x48)      /* (ISI_DMA_P_CTRL) DMA Preview Control Register Offset */
#define ISI_DMA_P_DSCR_REG_OFST        _UINT32_(0x4C)      /* (ISI_DMA_P_DSCR) DMA Preview Descriptor Address Register Offset */
#define ISI_DMA_C_ADDR_REG_OFST        _UINT32_(0x50)      /* (ISI_DMA_C_ADDR) DMA Codec Base Address Register Offset */
#define ISI_DMA_C_CTRL_REG_OFST        _UINT32_(0x54)      /* (ISI_DMA_C_CTRL) DMA Codec Control Register Offset */
#define ISI_DMA_C_DSCR_REG_OFST        _UINT32_(0x58)      /* (ISI_DMA_C_DSCR) DMA Codec Descriptor Address Register Offset */
#define ISI_WPMR_REG_OFST              _UINT32_(0xE4)      /* (ISI_WPMR) Write Protection Mode Register Offset */
#define ISI_WPSR_REG_OFST              _UINT32_(0xE8)      /* (ISI_WPSR) Write Protection Status Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* ISI register API structure */
typedef struct
{
  __IO  uint32_t                       ISI_CFG1;           /* Offset: 0x00 (R/W  32) ISI Configuration 1 Register */
  __IO  uint32_t                       ISI_CFG2;           /* Offset: 0x04 (R/W  32) ISI Configuration 2 Register */
  __IO  uint32_t                       ISI_PSIZE;          /* Offset: 0x08 (R/W  32) ISI Preview Size Register */
  __IO  uint32_t                       ISI_PDECF;          /* Offset: 0x0C (R/W  32) ISI Preview Decimation Factor Register */
  __IO  uint32_t                       ISI_Y2R_SET0;       /* Offset: 0x10 (R/W  32) ISI Color Space Conversion YCrCb To RGB Set 0 Register */
  __IO  uint32_t                       ISI_Y2R_SET1;       /* Offset: 0x14 (R/W  32) ISI Color Space Conversion YCrCb To RGB Set 1 Register */
  __IO  uint32_t                       ISI_R2Y_SET0;       /* Offset: 0x18 (R/W  32) ISI Color Space Conversion RGB To YCrCb Set 0 Register */
  __IO  uint32_t                       ISI_R2Y_SET1;       /* Offset: 0x1C (R/W  32) ISI Color Space Conversion RGB To YCrCb Set 1 Register */
  __IO  uint32_t                       ISI_R2Y_SET2;       /* Offset: 0x20 (R/W  32) ISI Color Space Conversion RGB To YCrCb Set 2 Register */
  __O   uint32_t                       ISI_CR;             /* Offset: 0x24 ( /W  32) ISI Control Register */
  __I   uint32_t                       ISI_SR;             /* Offset: 0x28 (R/   32) ISI Status Register */
  __O   uint32_t                       ISI_IER;            /* Offset: 0x2C ( /W  32) ISI Interrupt Enable Register */
  __O   uint32_t                       ISI_IDR;            /* Offset: 0x30 ( /W  32) ISI Interrupt Disable Register */
  __I   uint32_t                       ISI_IMR;            /* Offset: 0x34 (R/   32) ISI Interrupt Mask Register */
  __O   uint32_t                       ISI_DMA_CHER;       /* Offset: 0x38 ( /W  32) DMA Channel Enable Register */
  __O   uint32_t                       ISI_DMA_CHDR;       /* Offset: 0x3C ( /W  32) DMA Channel Disable Register */
  __I   uint32_t                       ISI_DMA_CHSR;       /* Offset: 0x40 (R/   32) DMA Channel Status Register */
  __IO  uint32_t                       ISI_DMA_P_ADDR;     /* Offset: 0x44 (R/W  32) DMA Preview Base Address Register */
  __IO  uint32_t                       ISI_DMA_P_CTRL;     /* Offset: 0x48 (R/W  32) DMA Preview Control Register */
  __IO  uint32_t                       ISI_DMA_P_DSCR;     /* Offset: 0x4C (R/W  32) DMA Preview Descriptor Address Register */
  __IO  uint32_t                       ISI_DMA_C_ADDR;     /* Offset: 0x50 (R/W  32) DMA Codec Base Address Register */
  __IO  uint32_t                       ISI_DMA_C_CTRL;     /* Offset: 0x54 (R/W  32) DMA Codec Control Register */
  __IO  uint32_t                       ISI_DMA_C_DSCR;     /* Offset: 0x58 (R/W  32) DMA Codec Descriptor Address Register */
  __I   uint8_t                        Reserved1[0x88];
  __IO  uint32_t                       ISI_WPMR;           /* Offset: 0xE4 (R/W  32) Write Protection Mode Register */
  __I   uint32_t                       ISI_WPSR;           /* Offset: 0xE8 (R/   32) Write Protection Status Register */
} isi_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CZCA70_ISI_COMPONENT_H_ */
