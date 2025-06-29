/*
 * Component description for WDT
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
#ifndef _PIC32CZCA70_WDT_COMPONENT_H_
#define _PIC32CZCA70_WDT_COMPONENT_H_

/* ************************************************************************** */
/*                      SOFTWARE API DEFINITION FOR WDT                       */
/* ************************************************************************** */

/* -------- WDT_CR : (WDT Offset: 0x00) ( /W 32) Control Register -------- */
#define WDT_CR_WDRSTT_Pos                     _UINT32_(0)                                          /* (WDT_CR) Watchdog Restart Position */
#define WDT_CR_WDRSTT_Msk                     (_UINT32_(0x1) << WDT_CR_WDRSTT_Pos)                 /* (WDT_CR) Watchdog Restart Mask */
#define WDT_CR_WDRSTT(value)                  (WDT_CR_WDRSTT_Msk & (_UINT32_(value) << WDT_CR_WDRSTT_Pos)) /* Assignment of value for WDRSTT in the WDT_CR register */
#define WDT_CR_KEY_Pos                        _UINT32_(24)                                         /* (WDT_CR) Password Position */
#define WDT_CR_KEY_Msk                        (_UINT32_(0xFF) << WDT_CR_KEY_Pos)                   /* (WDT_CR) Password Mask */
#define WDT_CR_KEY(value)                     (WDT_CR_KEY_Msk & (_UINT32_(value) << WDT_CR_KEY_Pos)) /* Assignment of value for KEY in the WDT_CR register */
#define   WDT_CR_KEY_PASSWD_Val               _UINT32_(0xA5)                                       /* (WDT_CR) Writing any other value in this field aborts the write operation.  */
#define WDT_CR_KEY_PASSWD                     (WDT_CR_KEY_PASSWD_Val << WDT_CR_KEY_Pos)            /* (WDT_CR) Writing any other value in this field aborts the write operation. Position */
#define WDT_CR_Msk                            _UINT32_(0xFF000001)                                 /* (WDT_CR) Register Mask  */


/* -------- WDT_MR : (WDT Offset: 0x04) (R/W 32) Mode Register -------- */
#define WDT_MR_WDV_Pos                        _UINT32_(0)                                          /* (WDT_MR) Watchdog Counter Value Position */
#define WDT_MR_WDV_Msk                        (_UINT32_(0xFFF) << WDT_MR_WDV_Pos)                  /* (WDT_MR) Watchdog Counter Value Mask */
#define WDT_MR_WDV(value)                     (WDT_MR_WDV_Msk & (_UINT32_(value) << WDT_MR_WDV_Pos)) /* Assignment of value for WDV in the WDT_MR register */
#define WDT_MR_WDFIEN_Pos                     _UINT32_(12)                                         /* (WDT_MR) Watchdog Fault Interrupt Enable Position */
#define WDT_MR_WDFIEN_Msk                     (_UINT32_(0x1) << WDT_MR_WDFIEN_Pos)                 /* (WDT_MR) Watchdog Fault Interrupt Enable Mask */
#define WDT_MR_WDFIEN(value)                  (WDT_MR_WDFIEN_Msk & (_UINT32_(value) << WDT_MR_WDFIEN_Pos)) /* Assignment of value for WDFIEN in the WDT_MR register */
#define WDT_MR_WDRSTEN_Pos                    _UINT32_(13)                                         /* (WDT_MR) Watchdog Reset Enable Position */
#define WDT_MR_WDRSTEN_Msk                    (_UINT32_(0x1) << WDT_MR_WDRSTEN_Pos)                /* (WDT_MR) Watchdog Reset Enable Mask */
#define WDT_MR_WDRSTEN(value)                 (WDT_MR_WDRSTEN_Msk & (_UINT32_(value) << WDT_MR_WDRSTEN_Pos)) /* Assignment of value for WDRSTEN in the WDT_MR register */
#define WDT_MR_WDDIS_Pos                      _UINT32_(15)                                         /* (WDT_MR) Watchdog Disable Position */
#define WDT_MR_WDDIS_Msk                      (_UINT32_(0x1) << WDT_MR_WDDIS_Pos)                  /* (WDT_MR) Watchdog Disable Mask */
#define WDT_MR_WDDIS(value)                   (WDT_MR_WDDIS_Msk & (_UINT32_(value) << WDT_MR_WDDIS_Pos)) /* Assignment of value for WDDIS in the WDT_MR register */
#define WDT_MR_WDD_Pos                        _UINT32_(16)                                         /* (WDT_MR) Watchdog Delta Value Position */
#define WDT_MR_WDD_Msk                        (_UINT32_(0xFFF) << WDT_MR_WDD_Pos)                  /* (WDT_MR) Watchdog Delta Value Mask */
#define WDT_MR_WDD(value)                     (WDT_MR_WDD_Msk & (_UINT32_(value) << WDT_MR_WDD_Pos)) /* Assignment of value for WDD in the WDT_MR register */
#define WDT_MR_WDDBGHLT_Pos                   _UINT32_(28)                                         /* (WDT_MR) Watchdog Debug Halt Position */
#define WDT_MR_WDDBGHLT_Msk                   (_UINT32_(0x1) << WDT_MR_WDDBGHLT_Pos)               /* (WDT_MR) Watchdog Debug Halt Mask */
#define WDT_MR_WDDBGHLT(value)                (WDT_MR_WDDBGHLT_Msk & (_UINT32_(value) << WDT_MR_WDDBGHLT_Pos)) /* Assignment of value for WDDBGHLT in the WDT_MR register */
#define WDT_MR_WDIDLEHLT_Pos                  _UINT32_(29)                                         /* (WDT_MR) Watchdog Idle Halt Position */
#define WDT_MR_WDIDLEHLT_Msk                  (_UINT32_(0x1) << WDT_MR_WDIDLEHLT_Pos)              /* (WDT_MR) Watchdog Idle Halt Mask */
#define WDT_MR_WDIDLEHLT(value)               (WDT_MR_WDIDLEHLT_Msk & (_UINT32_(value) << WDT_MR_WDIDLEHLT_Pos)) /* Assignment of value for WDIDLEHLT in the WDT_MR register */
#define WDT_MR_Msk                            _UINT32_(0x3FFFBFFF)                                 /* (WDT_MR) Register Mask  */


/* -------- WDT_SR : (WDT Offset: 0x08) ( R/ 32) Status Register -------- */
#define WDT_SR_WDUNF_Pos                      _UINT32_(0)                                          /* (WDT_SR) Watchdog Underflow (cleared on read) Position */
#define WDT_SR_WDUNF_Msk                      (_UINT32_(0x1) << WDT_SR_WDUNF_Pos)                  /* (WDT_SR) Watchdog Underflow (cleared on read) Mask */
#define WDT_SR_WDUNF(value)                   (WDT_SR_WDUNF_Msk & (_UINT32_(value) << WDT_SR_WDUNF_Pos)) /* Assignment of value for WDUNF in the WDT_SR register */
#define WDT_SR_WDERR_Pos                      _UINT32_(1)                                          /* (WDT_SR) Watchdog Error (cleared on read) Position */
#define WDT_SR_WDERR_Msk                      (_UINT32_(0x1) << WDT_SR_WDERR_Pos)                  /* (WDT_SR) Watchdog Error (cleared on read) Mask */
#define WDT_SR_WDERR(value)                   (WDT_SR_WDERR_Msk & (_UINT32_(value) << WDT_SR_WDERR_Pos)) /* Assignment of value for WDERR in the WDT_SR register */
#define WDT_SR_Msk                            _UINT32_(0x00000003)                                 /* (WDT_SR) Register Mask  */


/* WDT register offsets definitions */
#define WDT_CR_REG_OFST                _UINT32_(0x00)      /* (WDT_CR) Control Register Offset */
#define WDT_MR_REG_OFST                _UINT32_(0x04)      /* (WDT_MR) Mode Register Offset */
#define WDT_SR_REG_OFST                _UINT32_(0x08)      /* (WDT_SR) Status Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* WDT register API structure */
typedef struct
{
  __O   uint32_t                       WDT_CR;             /* Offset: 0x00 ( /W  32) Control Register */
  __IO  uint32_t                       WDT_MR;             /* Offset: 0x04 (R/W  32) Mode Register */
  __I   uint32_t                       WDT_SR;             /* Offset: 0x08 (R/   32) Status Register */
} wdt_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CZCA70_WDT_COMPONENT_H_ */
