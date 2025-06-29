/*
 * Component description for I2SC
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
#ifndef _PIC32CZCA70_I2SC_COMPONENT_H_
#define _PIC32CZCA70_I2SC_COMPONENT_H_

/* ************************************************************************** */
/*                      SOFTWARE API DEFINITION FOR I2SC                      */
/* ************************************************************************** */

/* -------- I2SC_CR : (I2SC Offset: 0x00) ( /W 32) Control Register -------- */
#define I2SC_CR_RXEN_Pos                      _UINT32_(0)                                          /* (I2SC_CR) Receiver Enable Position */
#define I2SC_CR_RXEN_Msk                      (_UINT32_(0x1) << I2SC_CR_RXEN_Pos)                  /* (I2SC_CR) Receiver Enable Mask */
#define I2SC_CR_RXEN(value)                   (I2SC_CR_RXEN_Msk & (_UINT32_(value) << I2SC_CR_RXEN_Pos)) /* Assignment of value for RXEN in the I2SC_CR register */
#define I2SC_CR_RXDIS_Pos                     _UINT32_(1)                                          /* (I2SC_CR) Receiver Disable Position */
#define I2SC_CR_RXDIS_Msk                     (_UINT32_(0x1) << I2SC_CR_RXDIS_Pos)                 /* (I2SC_CR) Receiver Disable Mask */
#define I2SC_CR_RXDIS(value)                  (I2SC_CR_RXDIS_Msk & (_UINT32_(value) << I2SC_CR_RXDIS_Pos)) /* Assignment of value for RXDIS in the I2SC_CR register */
#define I2SC_CR_CKEN_Pos                      _UINT32_(2)                                          /* (I2SC_CR) Clocks Enable Position */
#define I2SC_CR_CKEN_Msk                      (_UINT32_(0x1) << I2SC_CR_CKEN_Pos)                  /* (I2SC_CR) Clocks Enable Mask */
#define I2SC_CR_CKEN(value)                   (I2SC_CR_CKEN_Msk & (_UINT32_(value) << I2SC_CR_CKEN_Pos)) /* Assignment of value for CKEN in the I2SC_CR register */
#define I2SC_CR_CKDIS_Pos                     _UINT32_(3)                                          /* (I2SC_CR) Clocks Disable Position */
#define I2SC_CR_CKDIS_Msk                     (_UINT32_(0x1) << I2SC_CR_CKDIS_Pos)                 /* (I2SC_CR) Clocks Disable Mask */
#define I2SC_CR_CKDIS(value)                  (I2SC_CR_CKDIS_Msk & (_UINT32_(value) << I2SC_CR_CKDIS_Pos)) /* Assignment of value for CKDIS in the I2SC_CR register */
#define I2SC_CR_TXEN_Pos                      _UINT32_(4)                                          /* (I2SC_CR) Transmitter Enable Position */
#define I2SC_CR_TXEN_Msk                      (_UINT32_(0x1) << I2SC_CR_TXEN_Pos)                  /* (I2SC_CR) Transmitter Enable Mask */
#define I2SC_CR_TXEN(value)                   (I2SC_CR_TXEN_Msk & (_UINT32_(value) << I2SC_CR_TXEN_Pos)) /* Assignment of value for TXEN in the I2SC_CR register */
#define I2SC_CR_TXDIS_Pos                     _UINT32_(5)                                          /* (I2SC_CR) Transmitter Disable Position */
#define I2SC_CR_TXDIS_Msk                     (_UINT32_(0x1) << I2SC_CR_TXDIS_Pos)                 /* (I2SC_CR) Transmitter Disable Mask */
#define I2SC_CR_TXDIS(value)                  (I2SC_CR_TXDIS_Msk & (_UINT32_(value) << I2SC_CR_TXDIS_Pos)) /* Assignment of value for TXDIS in the I2SC_CR register */
#define I2SC_CR_SWRST_Pos                     _UINT32_(7)                                          /* (I2SC_CR) Software Reset Position */
#define I2SC_CR_SWRST_Msk                     (_UINT32_(0x1) << I2SC_CR_SWRST_Pos)                 /* (I2SC_CR) Software Reset Mask */
#define I2SC_CR_SWRST(value)                  (I2SC_CR_SWRST_Msk & (_UINT32_(value) << I2SC_CR_SWRST_Pos)) /* Assignment of value for SWRST in the I2SC_CR register */
#define I2SC_CR_Msk                           _UINT32_(0x000000BF)                                 /* (I2SC_CR) Register Mask  */


/* -------- I2SC_MR : (I2SC Offset: 0x04) (R/W 32) Mode Register -------- */
#define I2SC_MR_MODE_Pos                      _UINT32_(0)                                          /* (I2SC_MR) Inter-IC Sound Controller Mode Position */
#define I2SC_MR_MODE_Msk                      (_UINT32_(0x1) << I2SC_MR_MODE_Pos)                  /* (I2SC_MR) Inter-IC Sound Controller Mode Mask */
#define I2SC_MR_MODE(value)                   (I2SC_MR_MODE_Msk & (_UINT32_(value) << I2SC_MR_MODE_Pos)) /* Assignment of value for MODE in the I2SC_MR register */
#define   I2SC_MR_MODE_SLAVE_Val              _UINT32_(0x0)                                        /* (I2SC_MR) I2SC_CK and I2SC_WS pin inputs used as bit clock and word select/frame synchronization.  */
#define   I2SC_MR_MODE_MASTER_Val             _UINT32_(0x1)                                        /* (I2SC_MR) Bit clock and word select/frame synchronization generated by I2SC from MCK and output to I2SC_CK and I2SC_WS pins. Peripheral clock or GCLK is output as master clock on I2SC_MCK if I2SC_MR.IMCKMODE is set.  */
#define I2SC_MR_MODE_SLAVE                    (I2SC_MR_MODE_SLAVE_Val << I2SC_MR_MODE_Pos)         /* (I2SC_MR) I2SC_CK and I2SC_WS pin inputs used as bit clock and word select/frame synchronization. Position */
#define I2SC_MR_MODE_MASTER                   (I2SC_MR_MODE_MASTER_Val << I2SC_MR_MODE_Pos)        /* (I2SC_MR) Bit clock and word select/frame synchronization generated by I2SC from MCK and output to I2SC_CK and I2SC_WS pins. Peripheral clock or GCLK is output as master clock on I2SC_MCK if I2SC_MR.IMCKMODE is set. Position */
#define I2SC_MR_DATALENGTH_Pos                _UINT32_(2)                                          /* (I2SC_MR) Data Word Length Position */
#define I2SC_MR_DATALENGTH_Msk                (_UINT32_(0x7) << I2SC_MR_DATALENGTH_Pos)            /* (I2SC_MR) Data Word Length Mask */
#define I2SC_MR_DATALENGTH(value)             (I2SC_MR_DATALENGTH_Msk & (_UINT32_(value) << I2SC_MR_DATALENGTH_Pos)) /* Assignment of value for DATALENGTH in the I2SC_MR register */
#define   I2SC_MR_DATALENGTH_32_BITS_Val      _UINT32_(0x0)                                        /* (I2SC_MR) Data length is set to 32 bits  */
#define   I2SC_MR_DATALENGTH_24_BITS_Val      _UINT32_(0x1)                                        /* (I2SC_MR) Data length is set to 24 bits  */
#define   I2SC_MR_DATALENGTH_20_BITS_Val      _UINT32_(0x2)                                        /* (I2SC_MR) Data length is set to 20 bits  */
#define   I2SC_MR_DATALENGTH_18_BITS_Val      _UINT32_(0x3)                                        /* (I2SC_MR) Data length is set to 18 bits  */
#define   I2SC_MR_DATALENGTH_16_BITS_Val      _UINT32_(0x4)                                        /* (I2SC_MR) Data length is set to 16 bits  */
#define   I2SC_MR_DATALENGTH_16_BITS_COMPACT_Val _UINT32_(0x5)                                        /* (I2SC_MR) Data length is set to 16-bit compact stereo. Left sample in bits 15:0 and right sample in bits 31:16 of same word.  */
#define   I2SC_MR_DATALENGTH_8_BITS_Val       _UINT32_(0x6)                                        /* (I2SC_MR) Data length is set to 8 bits  */
#define   I2SC_MR_DATALENGTH_8_BITS_COMPACT_Val _UINT32_(0x7)                                        /* (I2SC_MR) Data length is set to 8-bit compact stereo. Left sample in bits 7:0 and right sample in bits 15:8 of the same word.  */
#define I2SC_MR_DATALENGTH_32_BITS            (I2SC_MR_DATALENGTH_32_BITS_Val << I2SC_MR_DATALENGTH_Pos) /* (I2SC_MR) Data length is set to 32 bits Position */
#define I2SC_MR_DATALENGTH_24_BITS            (I2SC_MR_DATALENGTH_24_BITS_Val << I2SC_MR_DATALENGTH_Pos) /* (I2SC_MR) Data length is set to 24 bits Position */
#define I2SC_MR_DATALENGTH_20_BITS            (I2SC_MR_DATALENGTH_20_BITS_Val << I2SC_MR_DATALENGTH_Pos) /* (I2SC_MR) Data length is set to 20 bits Position */
#define I2SC_MR_DATALENGTH_18_BITS            (I2SC_MR_DATALENGTH_18_BITS_Val << I2SC_MR_DATALENGTH_Pos) /* (I2SC_MR) Data length is set to 18 bits Position */
#define I2SC_MR_DATALENGTH_16_BITS            (I2SC_MR_DATALENGTH_16_BITS_Val << I2SC_MR_DATALENGTH_Pos) /* (I2SC_MR) Data length is set to 16 bits Position */
#define I2SC_MR_DATALENGTH_16_BITS_COMPACT    (I2SC_MR_DATALENGTH_16_BITS_COMPACT_Val << I2SC_MR_DATALENGTH_Pos) /* (I2SC_MR) Data length is set to 16-bit compact stereo. Left sample in bits 15:0 and right sample in bits 31:16 of same word. Position */
#define I2SC_MR_DATALENGTH_8_BITS             (I2SC_MR_DATALENGTH_8_BITS_Val << I2SC_MR_DATALENGTH_Pos) /* (I2SC_MR) Data length is set to 8 bits Position */
#define I2SC_MR_DATALENGTH_8_BITS_COMPACT     (I2SC_MR_DATALENGTH_8_BITS_COMPACT_Val << I2SC_MR_DATALENGTH_Pos) /* (I2SC_MR) Data length is set to 8-bit compact stereo. Left sample in bits 7:0 and right sample in bits 15:8 of the same word. Position */
#define I2SC_MR_RXMONO_Pos                    _UINT32_(8)                                          /* (I2SC_MR) Receive Mono Position */
#define I2SC_MR_RXMONO_Msk                    (_UINT32_(0x1) << I2SC_MR_RXMONO_Pos)                /* (I2SC_MR) Receive Mono Mask */
#define I2SC_MR_RXMONO(value)                 (I2SC_MR_RXMONO_Msk & (_UINT32_(value) << I2SC_MR_RXMONO_Pos)) /* Assignment of value for RXMONO in the I2SC_MR register */
#define I2SC_MR_RXDMA_Pos                     _UINT32_(9)                                          /* (I2SC_MR) Single or Multiple DMA Controller Channels for Receiver Position */
#define I2SC_MR_RXDMA_Msk                     (_UINT32_(0x1) << I2SC_MR_RXDMA_Pos)                 /* (I2SC_MR) Single or Multiple DMA Controller Channels for Receiver Mask */
#define I2SC_MR_RXDMA(value)                  (I2SC_MR_RXDMA_Msk & (_UINT32_(value) << I2SC_MR_RXDMA_Pos)) /* Assignment of value for RXDMA in the I2SC_MR register */
#define I2SC_MR_RXLOOP_Pos                    _UINT32_(10)                                         /* (I2SC_MR) Loopback Test Mode Position */
#define I2SC_MR_RXLOOP_Msk                    (_UINT32_(0x1) << I2SC_MR_RXLOOP_Pos)                /* (I2SC_MR) Loopback Test Mode Mask */
#define I2SC_MR_RXLOOP(value)                 (I2SC_MR_RXLOOP_Msk & (_UINT32_(value) << I2SC_MR_RXLOOP_Pos)) /* Assignment of value for RXLOOP in the I2SC_MR register */
#define I2SC_MR_TXMONO_Pos                    _UINT32_(12)                                         /* (I2SC_MR) Transmit Mono Position */
#define I2SC_MR_TXMONO_Msk                    (_UINT32_(0x1) << I2SC_MR_TXMONO_Pos)                /* (I2SC_MR) Transmit Mono Mask */
#define I2SC_MR_TXMONO(value)                 (I2SC_MR_TXMONO_Msk & (_UINT32_(value) << I2SC_MR_TXMONO_Pos)) /* Assignment of value for TXMONO in the I2SC_MR register */
#define I2SC_MR_TXDMA_Pos                     _UINT32_(13)                                         /* (I2SC_MR) Single or Multiple DMA Controller Channels for Transmitter Position */
#define I2SC_MR_TXDMA_Msk                     (_UINT32_(0x1) << I2SC_MR_TXDMA_Pos)                 /* (I2SC_MR) Single or Multiple DMA Controller Channels for Transmitter Mask */
#define I2SC_MR_TXDMA(value)                  (I2SC_MR_TXDMA_Msk & (_UINT32_(value) << I2SC_MR_TXDMA_Pos)) /* Assignment of value for TXDMA in the I2SC_MR register */
#define I2SC_MR_TXSAME_Pos                    _UINT32_(14)                                         /* (I2SC_MR) Transmit Data when Underrun Position */
#define I2SC_MR_TXSAME_Msk                    (_UINT32_(0x1) << I2SC_MR_TXSAME_Pos)                /* (I2SC_MR) Transmit Data when Underrun Mask */
#define I2SC_MR_TXSAME(value)                 (I2SC_MR_TXSAME_Msk & (_UINT32_(value) << I2SC_MR_TXSAME_Pos)) /* Assignment of value for TXSAME in the I2SC_MR register */
#define I2SC_MR_IMCKDIV_Pos                   _UINT32_(16)                                         /* (I2SC_MR) Selected Clock to I2SC Master Clock Ratio Position */
#define I2SC_MR_IMCKDIV_Msk                   (_UINT32_(0x3F) << I2SC_MR_IMCKDIV_Pos)              /* (I2SC_MR) Selected Clock to I2SC Master Clock Ratio Mask */
#define I2SC_MR_IMCKDIV(value)                (I2SC_MR_IMCKDIV_Msk & (_UINT32_(value) << I2SC_MR_IMCKDIV_Pos)) /* Assignment of value for IMCKDIV in the I2SC_MR register */
#define I2SC_MR_IMCKFS_Pos                    _UINT32_(24)                                         /* (I2SC_MR) Master Clock to fs Ratio Position */
#define I2SC_MR_IMCKFS_Msk                    (_UINT32_(0x3F) << I2SC_MR_IMCKFS_Pos)               /* (I2SC_MR) Master Clock to fs Ratio Mask */
#define I2SC_MR_IMCKFS(value)                 (I2SC_MR_IMCKFS_Msk & (_UINT32_(value) << I2SC_MR_IMCKFS_Pos)) /* Assignment of value for IMCKFS in the I2SC_MR register */
#define   I2SC_MR_IMCKFS_M2SF32_Val           _UINT32_(0x0)                                        /* (I2SC_MR) Sample frequency ratio set to 32  */
#define   I2SC_MR_IMCKFS_M2SF64_Val           _UINT32_(0x1)                                        /* (I2SC_MR) Sample frequency ratio set to 64  */
#define   I2SC_MR_IMCKFS_M2SF96_Val           _UINT32_(0x2)                                        /* (I2SC_MR) Sample frequency ratio set to 96  */
#define   I2SC_MR_IMCKFS_M2SF128_Val          _UINT32_(0x3)                                        /* (I2SC_MR) Sample frequency ratio set to 128  */
#define   I2SC_MR_IMCKFS_M2SF192_Val          _UINT32_(0x5)                                        /* (I2SC_MR) Sample frequency ratio set to 192  */
#define   I2SC_MR_IMCKFS_M2SF256_Val          _UINT32_(0x7)                                        /* (I2SC_MR) Sample frequency ratio set to 256  */
#define   I2SC_MR_IMCKFS_M2SF384_Val          _UINT32_(0xB)                                        /* (I2SC_MR) Sample frequency ratio set to 384  */
#define   I2SC_MR_IMCKFS_M2SF512_Val          _UINT32_(0xF)                                        /* (I2SC_MR) Sample frequency ratio set to 512  */
#define   I2SC_MR_IMCKFS_M2SF768_Val          _UINT32_(0x17)                                       /* (I2SC_MR) Sample frequency ratio set to 768  */
#define   I2SC_MR_IMCKFS_M2SF1024_Val         _UINT32_(0x1F)                                       /* (I2SC_MR) Sample frequency ratio set to 1024  */
#define   I2SC_MR_IMCKFS_M2SF1536_Val         _UINT32_(0x2F)                                       /* (I2SC_MR) Sample frequency ratio set to 1536  */
#define   I2SC_MR_IMCKFS_M2SF2048_Val         _UINT32_(0x3F)                                       /* (I2SC_MR) Sample frequency ratio set to 2048  */
#define I2SC_MR_IMCKFS_M2SF32                 (I2SC_MR_IMCKFS_M2SF32_Val << I2SC_MR_IMCKFS_Pos)    /* (I2SC_MR) Sample frequency ratio set to 32 Position */
#define I2SC_MR_IMCKFS_M2SF64                 (I2SC_MR_IMCKFS_M2SF64_Val << I2SC_MR_IMCKFS_Pos)    /* (I2SC_MR) Sample frequency ratio set to 64 Position */
#define I2SC_MR_IMCKFS_M2SF96                 (I2SC_MR_IMCKFS_M2SF96_Val << I2SC_MR_IMCKFS_Pos)    /* (I2SC_MR) Sample frequency ratio set to 96 Position */
#define I2SC_MR_IMCKFS_M2SF128                (I2SC_MR_IMCKFS_M2SF128_Val << I2SC_MR_IMCKFS_Pos)   /* (I2SC_MR) Sample frequency ratio set to 128 Position */
#define I2SC_MR_IMCKFS_M2SF192                (I2SC_MR_IMCKFS_M2SF192_Val << I2SC_MR_IMCKFS_Pos)   /* (I2SC_MR) Sample frequency ratio set to 192 Position */
#define I2SC_MR_IMCKFS_M2SF256                (I2SC_MR_IMCKFS_M2SF256_Val << I2SC_MR_IMCKFS_Pos)   /* (I2SC_MR) Sample frequency ratio set to 256 Position */
#define I2SC_MR_IMCKFS_M2SF384                (I2SC_MR_IMCKFS_M2SF384_Val << I2SC_MR_IMCKFS_Pos)   /* (I2SC_MR) Sample frequency ratio set to 384 Position */
#define I2SC_MR_IMCKFS_M2SF512                (I2SC_MR_IMCKFS_M2SF512_Val << I2SC_MR_IMCKFS_Pos)   /* (I2SC_MR) Sample frequency ratio set to 512 Position */
#define I2SC_MR_IMCKFS_M2SF768                (I2SC_MR_IMCKFS_M2SF768_Val << I2SC_MR_IMCKFS_Pos)   /* (I2SC_MR) Sample frequency ratio set to 768 Position */
#define I2SC_MR_IMCKFS_M2SF1024               (I2SC_MR_IMCKFS_M2SF1024_Val << I2SC_MR_IMCKFS_Pos)  /* (I2SC_MR) Sample frequency ratio set to 1024 Position */
#define I2SC_MR_IMCKFS_M2SF1536               (I2SC_MR_IMCKFS_M2SF1536_Val << I2SC_MR_IMCKFS_Pos)  /* (I2SC_MR) Sample frequency ratio set to 1536 Position */
#define I2SC_MR_IMCKFS_M2SF2048               (I2SC_MR_IMCKFS_M2SF2048_Val << I2SC_MR_IMCKFS_Pos)  /* (I2SC_MR) Sample frequency ratio set to 2048 Position */
#define I2SC_MR_IMCKMODE_Pos                  _UINT32_(30)                                         /* (I2SC_MR) Master Clock Mode Position */
#define I2SC_MR_IMCKMODE_Msk                  (_UINT32_(0x1) << I2SC_MR_IMCKMODE_Pos)              /* (I2SC_MR) Master Clock Mode Mask */
#define I2SC_MR_IMCKMODE(value)               (I2SC_MR_IMCKMODE_Msk & (_UINT32_(value) << I2SC_MR_IMCKMODE_Pos)) /* Assignment of value for IMCKMODE in the I2SC_MR register */
#define I2SC_MR_IWS_Pos                       _UINT32_(31)                                         /* (I2SC_MR) I2SC_WS Slot Width Position */
#define I2SC_MR_IWS_Msk                       (_UINT32_(0x1) << I2SC_MR_IWS_Pos)                   /* (I2SC_MR) I2SC_WS Slot Width Mask */
#define I2SC_MR_IWS(value)                    (I2SC_MR_IWS_Msk & (_UINT32_(value) << I2SC_MR_IWS_Pos)) /* Assignment of value for IWS in the I2SC_MR register */
#define I2SC_MR_Msk                           _UINT32_(0xFF3F771D)                                 /* (I2SC_MR) Register Mask  */


/* -------- I2SC_SR : (I2SC Offset: 0x08) ( R/ 32) Status Register -------- */
#define I2SC_SR_RXEN_Pos                      _UINT32_(0)                                          /* (I2SC_SR) Receiver Enabled Position */
#define I2SC_SR_RXEN_Msk                      (_UINT32_(0x1) << I2SC_SR_RXEN_Pos)                  /* (I2SC_SR) Receiver Enabled Mask */
#define I2SC_SR_RXEN(value)                   (I2SC_SR_RXEN_Msk & (_UINT32_(value) << I2SC_SR_RXEN_Pos)) /* Assignment of value for RXEN in the I2SC_SR register */
#define I2SC_SR_RXRDY_Pos                     _UINT32_(1)                                          /* (I2SC_SR) Receive Ready Position */
#define I2SC_SR_RXRDY_Msk                     (_UINT32_(0x1) << I2SC_SR_RXRDY_Pos)                 /* (I2SC_SR) Receive Ready Mask */
#define I2SC_SR_RXRDY(value)                  (I2SC_SR_RXRDY_Msk & (_UINT32_(value) << I2SC_SR_RXRDY_Pos)) /* Assignment of value for RXRDY in the I2SC_SR register */
#define I2SC_SR_RXOR_Pos                      _UINT32_(2)                                          /* (I2SC_SR) Receive Overrun Position */
#define I2SC_SR_RXOR_Msk                      (_UINT32_(0x1) << I2SC_SR_RXOR_Pos)                  /* (I2SC_SR) Receive Overrun Mask */
#define I2SC_SR_RXOR(value)                   (I2SC_SR_RXOR_Msk & (_UINT32_(value) << I2SC_SR_RXOR_Pos)) /* Assignment of value for RXOR in the I2SC_SR register */
#define I2SC_SR_TXEN_Pos                      _UINT32_(4)                                          /* (I2SC_SR) Transmitter Enabled Position */
#define I2SC_SR_TXEN_Msk                      (_UINT32_(0x1) << I2SC_SR_TXEN_Pos)                  /* (I2SC_SR) Transmitter Enabled Mask */
#define I2SC_SR_TXEN(value)                   (I2SC_SR_TXEN_Msk & (_UINT32_(value) << I2SC_SR_TXEN_Pos)) /* Assignment of value for TXEN in the I2SC_SR register */
#define I2SC_SR_TXRDY_Pos                     _UINT32_(5)                                          /* (I2SC_SR) Transmit Ready Position */
#define I2SC_SR_TXRDY_Msk                     (_UINT32_(0x1) << I2SC_SR_TXRDY_Pos)                 /* (I2SC_SR) Transmit Ready Mask */
#define I2SC_SR_TXRDY(value)                  (I2SC_SR_TXRDY_Msk & (_UINT32_(value) << I2SC_SR_TXRDY_Pos)) /* Assignment of value for TXRDY in the I2SC_SR register */
#define I2SC_SR_TXUR_Pos                      _UINT32_(6)                                          /* (I2SC_SR) Transmit Underrun Position */
#define I2SC_SR_TXUR_Msk                      (_UINT32_(0x1) << I2SC_SR_TXUR_Pos)                  /* (I2SC_SR) Transmit Underrun Mask */
#define I2SC_SR_TXUR(value)                   (I2SC_SR_TXUR_Msk & (_UINT32_(value) << I2SC_SR_TXUR_Pos)) /* Assignment of value for TXUR in the I2SC_SR register */
#define I2SC_SR_RXORCH_Pos                    _UINT32_(8)                                          /* (I2SC_SR) Receive Overrun Channel Position */
#define I2SC_SR_RXORCH_Msk                    (_UINT32_(0x3) << I2SC_SR_RXORCH_Pos)                /* (I2SC_SR) Receive Overrun Channel Mask */
#define I2SC_SR_RXORCH(value)                 (I2SC_SR_RXORCH_Msk & (_UINT32_(value) << I2SC_SR_RXORCH_Pos)) /* Assignment of value for RXORCH in the I2SC_SR register */
#define I2SC_SR_TXURCH_Pos                    _UINT32_(20)                                         /* (I2SC_SR) Transmit Underrun Channel Position */
#define I2SC_SR_TXURCH_Msk                    (_UINT32_(0x3) << I2SC_SR_TXURCH_Pos)                /* (I2SC_SR) Transmit Underrun Channel Mask */
#define I2SC_SR_TXURCH(value)                 (I2SC_SR_TXURCH_Msk & (_UINT32_(value) << I2SC_SR_TXURCH_Pos)) /* Assignment of value for TXURCH in the I2SC_SR register */
#define I2SC_SR_Msk                           _UINT32_(0x00300377)                                 /* (I2SC_SR) Register Mask  */


/* -------- I2SC_SCR : (I2SC Offset: 0x0C) ( /W 32) Status Clear Register -------- */
#define I2SC_SCR_RXOR_Pos                     _UINT32_(2)                                          /* (I2SC_SCR) Receive Overrun Status Clear Position */
#define I2SC_SCR_RXOR_Msk                     (_UINT32_(0x1) << I2SC_SCR_RXOR_Pos)                 /* (I2SC_SCR) Receive Overrun Status Clear Mask */
#define I2SC_SCR_RXOR(value)                  (I2SC_SCR_RXOR_Msk & (_UINT32_(value) << I2SC_SCR_RXOR_Pos)) /* Assignment of value for RXOR in the I2SC_SCR register */
#define I2SC_SCR_TXUR_Pos                     _UINT32_(6)                                          /* (I2SC_SCR) Transmit Underrun Status Clear Position */
#define I2SC_SCR_TXUR_Msk                     (_UINT32_(0x1) << I2SC_SCR_TXUR_Pos)                 /* (I2SC_SCR) Transmit Underrun Status Clear Mask */
#define I2SC_SCR_TXUR(value)                  (I2SC_SCR_TXUR_Msk & (_UINT32_(value) << I2SC_SCR_TXUR_Pos)) /* Assignment of value for TXUR in the I2SC_SCR register */
#define I2SC_SCR_RXORCH_Pos                   _UINT32_(8)                                          /* (I2SC_SCR) Receive Overrun Per Channel Status Clear Position */
#define I2SC_SCR_RXORCH_Msk                   (_UINT32_(0x3) << I2SC_SCR_RXORCH_Pos)               /* (I2SC_SCR) Receive Overrun Per Channel Status Clear Mask */
#define I2SC_SCR_RXORCH(value)                (I2SC_SCR_RXORCH_Msk & (_UINT32_(value) << I2SC_SCR_RXORCH_Pos)) /* Assignment of value for RXORCH in the I2SC_SCR register */
#define I2SC_SCR_TXURCH_Pos                   _UINT32_(20)                                         /* (I2SC_SCR) Transmit Underrun Per Channel Status Clear Position */
#define I2SC_SCR_TXURCH_Msk                   (_UINT32_(0x3) << I2SC_SCR_TXURCH_Pos)               /* (I2SC_SCR) Transmit Underrun Per Channel Status Clear Mask */
#define I2SC_SCR_TXURCH(value)                (I2SC_SCR_TXURCH_Msk & (_UINT32_(value) << I2SC_SCR_TXURCH_Pos)) /* Assignment of value for TXURCH in the I2SC_SCR register */
#define I2SC_SCR_Msk                          _UINT32_(0x00300344)                                 /* (I2SC_SCR) Register Mask  */


/* -------- I2SC_SSR : (I2SC Offset: 0x10) ( /W 32) Status Set Register -------- */
#define I2SC_SSR_RXOR_Pos                     _UINT32_(2)                                          /* (I2SC_SSR) Receive Overrun Status Set Position */
#define I2SC_SSR_RXOR_Msk                     (_UINT32_(0x1) << I2SC_SSR_RXOR_Pos)                 /* (I2SC_SSR) Receive Overrun Status Set Mask */
#define I2SC_SSR_RXOR(value)                  (I2SC_SSR_RXOR_Msk & (_UINT32_(value) << I2SC_SSR_RXOR_Pos)) /* Assignment of value for RXOR in the I2SC_SSR register */
#define I2SC_SSR_TXUR_Pos                     _UINT32_(6)                                          /* (I2SC_SSR) Transmit Underrun Status Set Position */
#define I2SC_SSR_TXUR_Msk                     (_UINT32_(0x1) << I2SC_SSR_TXUR_Pos)                 /* (I2SC_SSR) Transmit Underrun Status Set Mask */
#define I2SC_SSR_TXUR(value)                  (I2SC_SSR_TXUR_Msk & (_UINT32_(value) << I2SC_SSR_TXUR_Pos)) /* Assignment of value for TXUR in the I2SC_SSR register */
#define I2SC_SSR_RXORCH_Pos                   _UINT32_(8)                                          /* (I2SC_SSR) Receive Overrun Per Channel Status Set Position */
#define I2SC_SSR_RXORCH_Msk                   (_UINT32_(0x3) << I2SC_SSR_RXORCH_Pos)               /* (I2SC_SSR) Receive Overrun Per Channel Status Set Mask */
#define I2SC_SSR_RXORCH(value)                (I2SC_SSR_RXORCH_Msk & (_UINT32_(value) << I2SC_SSR_RXORCH_Pos)) /* Assignment of value for RXORCH in the I2SC_SSR register */
#define I2SC_SSR_TXURCH_Pos                   _UINT32_(20)                                         /* (I2SC_SSR) Transmit Underrun Per Channel Status Set Position */
#define I2SC_SSR_TXURCH_Msk                   (_UINT32_(0x3) << I2SC_SSR_TXURCH_Pos)               /* (I2SC_SSR) Transmit Underrun Per Channel Status Set Mask */
#define I2SC_SSR_TXURCH(value)                (I2SC_SSR_TXURCH_Msk & (_UINT32_(value) << I2SC_SSR_TXURCH_Pos)) /* Assignment of value for TXURCH in the I2SC_SSR register */
#define I2SC_SSR_Msk                          _UINT32_(0x00300344)                                 /* (I2SC_SSR) Register Mask  */


/* -------- I2SC_IER : (I2SC Offset: 0x14) ( /W 32) Interrupt Enable Register -------- */
#define I2SC_IER_RXRDY_Pos                    _UINT32_(1)                                          /* (I2SC_IER) Receiver Ready Interrupt Enable Position */
#define I2SC_IER_RXRDY_Msk                    (_UINT32_(0x1) << I2SC_IER_RXRDY_Pos)                /* (I2SC_IER) Receiver Ready Interrupt Enable Mask */
#define I2SC_IER_RXRDY(value)                 (I2SC_IER_RXRDY_Msk & (_UINT32_(value) << I2SC_IER_RXRDY_Pos)) /* Assignment of value for RXRDY in the I2SC_IER register */
#define I2SC_IER_RXOR_Pos                     _UINT32_(2)                                          /* (I2SC_IER) Receiver Overrun Interrupt Enable Position */
#define I2SC_IER_RXOR_Msk                     (_UINT32_(0x1) << I2SC_IER_RXOR_Pos)                 /* (I2SC_IER) Receiver Overrun Interrupt Enable Mask */
#define I2SC_IER_RXOR(value)                  (I2SC_IER_RXOR_Msk & (_UINT32_(value) << I2SC_IER_RXOR_Pos)) /* Assignment of value for RXOR in the I2SC_IER register */
#define I2SC_IER_TXRDY_Pos                    _UINT32_(5)                                          /* (I2SC_IER) Transmit Ready Interrupt Enable Position */
#define I2SC_IER_TXRDY_Msk                    (_UINT32_(0x1) << I2SC_IER_TXRDY_Pos)                /* (I2SC_IER) Transmit Ready Interrupt Enable Mask */
#define I2SC_IER_TXRDY(value)                 (I2SC_IER_TXRDY_Msk & (_UINT32_(value) << I2SC_IER_TXRDY_Pos)) /* Assignment of value for TXRDY in the I2SC_IER register */
#define I2SC_IER_TXUR_Pos                     _UINT32_(6)                                          /* (I2SC_IER) Transmit Underflow Interrupt Enable Position */
#define I2SC_IER_TXUR_Msk                     (_UINT32_(0x1) << I2SC_IER_TXUR_Pos)                 /* (I2SC_IER) Transmit Underflow Interrupt Enable Mask */
#define I2SC_IER_TXUR(value)                  (I2SC_IER_TXUR_Msk & (_UINT32_(value) << I2SC_IER_TXUR_Pos)) /* Assignment of value for TXUR in the I2SC_IER register */
#define I2SC_IER_Msk                          _UINT32_(0x00000066)                                 /* (I2SC_IER) Register Mask  */


/* -------- I2SC_IDR : (I2SC Offset: 0x18) ( /W 32) Interrupt Disable Register -------- */
#define I2SC_IDR_RXRDY_Pos                    _UINT32_(1)                                          /* (I2SC_IDR) Receiver Ready Interrupt Disable Position */
#define I2SC_IDR_RXRDY_Msk                    (_UINT32_(0x1) << I2SC_IDR_RXRDY_Pos)                /* (I2SC_IDR) Receiver Ready Interrupt Disable Mask */
#define I2SC_IDR_RXRDY(value)                 (I2SC_IDR_RXRDY_Msk & (_UINT32_(value) << I2SC_IDR_RXRDY_Pos)) /* Assignment of value for RXRDY in the I2SC_IDR register */
#define I2SC_IDR_RXOR_Pos                     _UINT32_(2)                                          /* (I2SC_IDR) Receiver Overrun Interrupt Disable Position */
#define I2SC_IDR_RXOR_Msk                     (_UINT32_(0x1) << I2SC_IDR_RXOR_Pos)                 /* (I2SC_IDR) Receiver Overrun Interrupt Disable Mask */
#define I2SC_IDR_RXOR(value)                  (I2SC_IDR_RXOR_Msk & (_UINT32_(value) << I2SC_IDR_RXOR_Pos)) /* Assignment of value for RXOR in the I2SC_IDR register */
#define I2SC_IDR_TXRDY_Pos                    _UINT32_(5)                                          /* (I2SC_IDR) Transmit Ready Interrupt Disable Position */
#define I2SC_IDR_TXRDY_Msk                    (_UINT32_(0x1) << I2SC_IDR_TXRDY_Pos)                /* (I2SC_IDR) Transmit Ready Interrupt Disable Mask */
#define I2SC_IDR_TXRDY(value)                 (I2SC_IDR_TXRDY_Msk & (_UINT32_(value) << I2SC_IDR_TXRDY_Pos)) /* Assignment of value for TXRDY in the I2SC_IDR register */
#define I2SC_IDR_TXUR_Pos                     _UINT32_(6)                                          /* (I2SC_IDR) Transmit Underflow Interrupt Disable Position */
#define I2SC_IDR_TXUR_Msk                     (_UINT32_(0x1) << I2SC_IDR_TXUR_Pos)                 /* (I2SC_IDR) Transmit Underflow Interrupt Disable Mask */
#define I2SC_IDR_TXUR(value)                  (I2SC_IDR_TXUR_Msk & (_UINT32_(value) << I2SC_IDR_TXUR_Pos)) /* Assignment of value for TXUR in the I2SC_IDR register */
#define I2SC_IDR_Msk                          _UINT32_(0x00000066)                                 /* (I2SC_IDR) Register Mask  */


/* -------- I2SC_IMR : (I2SC Offset: 0x1C) ( R/ 32) Interrupt Mask Register -------- */
#define I2SC_IMR_RXRDY_Pos                    _UINT32_(1)                                          /* (I2SC_IMR) Receiver Ready Interrupt Disable Position */
#define I2SC_IMR_RXRDY_Msk                    (_UINT32_(0x1) << I2SC_IMR_RXRDY_Pos)                /* (I2SC_IMR) Receiver Ready Interrupt Disable Mask */
#define I2SC_IMR_RXRDY(value)                 (I2SC_IMR_RXRDY_Msk & (_UINT32_(value) << I2SC_IMR_RXRDY_Pos)) /* Assignment of value for RXRDY in the I2SC_IMR register */
#define I2SC_IMR_RXOR_Pos                     _UINT32_(2)                                          /* (I2SC_IMR) Receiver Overrun Interrupt Disable Position */
#define I2SC_IMR_RXOR_Msk                     (_UINT32_(0x1) << I2SC_IMR_RXOR_Pos)                 /* (I2SC_IMR) Receiver Overrun Interrupt Disable Mask */
#define I2SC_IMR_RXOR(value)                  (I2SC_IMR_RXOR_Msk & (_UINT32_(value) << I2SC_IMR_RXOR_Pos)) /* Assignment of value for RXOR in the I2SC_IMR register */
#define I2SC_IMR_TXRDY_Pos                    _UINT32_(5)                                          /* (I2SC_IMR) Transmit Ready Interrupt Disable Position */
#define I2SC_IMR_TXRDY_Msk                    (_UINT32_(0x1) << I2SC_IMR_TXRDY_Pos)                /* (I2SC_IMR) Transmit Ready Interrupt Disable Mask */
#define I2SC_IMR_TXRDY(value)                 (I2SC_IMR_TXRDY_Msk & (_UINT32_(value) << I2SC_IMR_TXRDY_Pos)) /* Assignment of value for TXRDY in the I2SC_IMR register */
#define I2SC_IMR_TXUR_Pos                     _UINT32_(6)                                          /* (I2SC_IMR) Transmit Underflow Interrupt Disable Position */
#define I2SC_IMR_TXUR_Msk                     (_UINT32_(0x1) << I2SC_IMR_TXUR_Pos)                 /* (I2SC_IMR) Transmit Underflow Interrupt Disable Mask */
#define I2SC_IMR_TXUR(value)                  (I2SC_IMR_TXUR_Msk & (_UINT32_(value) << I2SC_IMR_TXUR_Pos)) /* Assignment of value for TXUR in the I2SC_IMR register */
#define I2SC_IMR_Msk                          _UINT32_(0x00000066)                                 /* (I2SC_IMR) Register Mask  */


/* -------- I2SC_RHR : (I2SC Offset: 0x20) ( R/ 32) Receiver Holding Register -------- */
#define I2SC_RHR_RHR_Pos                      _UINT32_(0)                                          /* (I2SC_RHR) Receiver Holding Register Position */
#define I2SC_RHR_RHR_Msk                      (_UINT32_(0xFFFFFFFF) << I2SC_RHR_RHR_Pos)           /* (I2SC_RHR) Receiver Holding Register Mask */
#define I2SC_RHR_RHR(value)                   (I2SC_RHR_RHR_Msk & (_UINT32_(value) << I2SC_RHR_RHR_Pos)) /* Assignment of value for RHR in the I2SC_RHR register */
#define I2SC_RHR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (I2SC_RHR) Register Mask  */


/* -------- I2SC_THR : (I2SC Offset: 0x24) ( /W 32) Transmitter Holding Register -------- */
#define I2SC_THR_THR_Pos                      _UINT32_(0)                                          /* (I2SC_THR) Transmitter Holding Register Position */
#define I2SC_THR_THR_Msk                      (_UINT32_(0xFFFFFFFF) << I2SC_THR_THR_Pos)           /* (I2SC_THR) Transmitter Holding Register Mask */
#define I2SC_THR_THR(value)                   (I2SC_THR_THR_Msk & (_UINT32_(value) << I2SC_THR_THR_Pos)) /* Assignment of value for THR in the I2SC_THR register */
#define I2SC_THR_Msk                          _UINT32_(0xFFFFFFFF)                                 /* (I2SC_THR) Register Mask  */


/* I2SC register offsets definitions */
#define I2SC_CR_REG_OFST               _UINT32_(0x00)      /* (I2SC_CR) Control Register Offset */
#define I2SC_MR_REG_OFST               _UINT32_(0x04)      /* (I2SC_MR) Mode Register Offset */
#define I2SC_SR_REG_OFST               _UINT32_(0x08)      /* (I2SC_SR) Status Register Offset */
#define I2SC_SCR_REG_OFST              _UINT32_(0x0C)      /* (I2SC_SCR) Status Clear Register Offset */
#define I2SC_SSR_REG_OFST              _UINT32_(0x10)      /* (I2SC_SSR) Status Set Register Offset */
#define I2SC_IER_REG_OFST              _UINT32_(0x14)      /* (I2SC_IER) Interrupt Enable Register Offset */
#define I2SC_IDR_REG_OFST              _UINT32_(0x18)      /* (I2SC_IDR) Interrupt Disable Register Offset */
#define I2SC_IMR_REG_OFST              _UINT32_(0x1C)      /* (I2SC_IMR) Interrupt Mask Register Offset */
#define I2SC_RHR_REG_OFST              _UINT32_(0x20)      /* (I2SC_RHR) Receiver Holding Register Offset */
#define I2SC_THR_REG_OFST              _UINT32_(0x24)      /* (I2SC_THR) Transmitter Holding Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* I2SC register API structure */
typedef struct
{
  __O   uint32_t                       I2SC_CR;            /* Offset: 0x00 ( /W  32) Control Register */
  __IO  uint32_t                       I2SC_MR;            /* Offset: 0x04 (R/W  32) Mode Register */
  __I   uint32_t                       I2SC_SR;            /* Offset: 0x08 (R/   32) Status Register */
  __O   uint32_t                       I2SC_SCR;           /* Offset: 0x0C ( /W  32) Status Clear Register */
  __O   uint32_t                       I2SC_SSR;           /* Offset: 0x10 ( /W  32) Status Set Register */
  __O   uint32_t                       I2SC_IER;           /* Offset: 0x14 ( /W  32) Interrupt Enable Register */
  __O   uint32_t                       I2SC_IDR;           /* Offset: 0x18 ( /W  32) Interrupt Disable Register */
  __I   uint32_t                       I2SC_IMR;           /* Offset: 0x1C (R/   32) Interrupt Mask Register */
  __I   uint32_t                       I2SC_RHR;           /* Offset: 0x20 (R/   32) Receiver Holding Register */
  __O   uint32_t                       I2SC_THR;           /* Offset: 0x24 ( /W  32) Transmitter Holding Register */
} i2sc_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CZCA70_I2SC_COMPONENT_H_ */
