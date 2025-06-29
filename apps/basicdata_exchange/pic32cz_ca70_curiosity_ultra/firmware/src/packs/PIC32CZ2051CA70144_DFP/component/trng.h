/*
 * Component description for TRNG
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
#ifndef _PIC32CZCA70_TRNG_COMPONENT_H_
#define _PIC32CZCA70_TRNG_COMPONENT_H_

/* ************************************************************************** */
/*                      SOFTWARE API DEFINITION FOR TRNG                      */
/* ************************************************************************** */

/* -------- TRNG_CR : (TRNG Offset: 0x00) ( /W 32) Control Register -------- */
#define TRNG_CR_ENABLE_Pos                    _UINT32_(0)                                          /* (TRNG_CR) Enables the TRNG to Provide Random Values Position */
#define TRNG_CR_ENABLE_Msk                    (_UINT32_(0x1) << TRNG_CR_ENABLE_Pos)                /* (TRNG_CR) Enables the TRNG to Provide Random Values Mask */
#define TRNG_CR_ENABLE(value)                 (TRNG_CR_ENABLE_Msk & (_UINT32_(value) << TRNG_CR_ENABLE_Pos)) /* Assignment of value for ENABLE in the TRNG_CR register */
#define TRNG_CR_KEY_Pos                       _UINT32_(8)                                          /* (TRNG_CR) Security Key Position */
#define TRNG_CR_KEY_Msk                       (_UINT32_(0xFFFFFF) << TRNG_CR_KEY_Pos)              /* (TRNG_CR) Security Key Mask */
#define TRNG_CR_KEY(value)                    (TRNG_CR_KEY_Msk & (_UINT32_(value) << TRNG_CR_KEY_Pos)) /* Assignment of value for KEY in the TRNG_CR register */
#define   TRNG_CR_KEY_PASSWD_Val              _UINT32_(0x524E47)                                   /* (TRNG_CR) Writing any other value in this field aborts the write operation.  */
#define TRNG_CR_KEY_PASSWD                    (TRNG_CR_KEY_PASSWD_Val << TRNG_CR_KEY_Pos)          /* (TRNG_CR) Writing any other value in this field aborts the write operation. Position */
#define TRNG_CR_Msk                           _UINT32_(0xFFFFFF01)                                 /* (TRNG_CR) Register Mask  */


/* -------- TRNG_IER : (TRNG Offset: 0x10) ( /W 32) Interrupt Enable Register -------- */
#define TRNG_IER_DATRDY_Pos                   _UINT32_(0)                                          /* (TRNG_IER) Data Ready Interrupt Enable Position */
#define TRNG_IER_DATRDY_Msk                   (_UINT32_(0x1) << TRNG_IER_DATRDY_Pos)               /* (TRNG_IER) Data Ready Interrupt Enable Mask */
#define TRNG_IER_DATRDY(value)                (TRNG_IER_DATRDY_Msk & (_UINT32_(value) << TRNG_IER_DATRDY_Pos)) /* Assignment of value for DATRDY in the TRNG_IER register */
#define TRNG_IER_Msk                          _UINT32_(0x00000001)                                 /* (TRNG_IER) Register Mask  */


/* -------- TRNG_IDR : (TRNG Offset: 0x14) ( /W 32) Interrupt Disable Register -------- */
#define TRNG_IDR_DATRDY_Pos                   _UINT32_(0)                                          /* (TRNG_IDR) Data Ready Interrupt Disable Position */
#define TRNG_IDR_DATRDY_Msk                   (_UINT32_(0x1) << TRNG_IDR_DATRDY_Pos)               /* (TRNG_IDR) Data Ready Interrupt Disable Mask */
#define TRNG_IDR_DATRDY(value)                (TRNG_IDR_DATRDY_Msk & (_UINT32_(value) << TRNG_IDR_DATRDY_Pos)) /* Assignment of value for DATRDY in the TRNG_IDR register */
#define TRNG_IDR_Msk                          _UINT32_(0x00000001)                                 /* (TRNG_IDR) Register Mask  */


/* -------- TRNG_IMR : (TRNG Offset: 0x18) ( R/ 32) Interrupt Mask Register -------- */
#define TRNG_IMR_DATRDY_Pos                   _UINT32_(0)                                          /* (TRNG_IMR) Data Ready Interrupt Mask Position */
#define TRNG_IMR_DATRDY_Msk                   (_UINT32_(0x1) << TRNG_IMR_DATRDY_Pos)               /* (TRNG_IMR) Data Ready Interrupt Mask Mask */
#define TRNG_IMR_DATRDY(value)                (TRNG_IMR_DATRDY_Msk & (_UINT32_(value) << TRNG_IMR_DATRDY_Pos)) /* Assignment of value for DATRDY in the TRNG_IMR register */
#define TRNG_IMR_Msk                          _UINT32_(0x00000001)                                 /* (TRNG_IMR) Register Mask  */


/* -------- TRNG_ISR : (TRNG Offset: 0x1C) ( R/ 32) Interrupt Status Register -------- */
#define TRNG_ISR_DATRDY_Pos                   _UINT32_(0)                                          /* (TRNG_ISR) Data Ready Position */
#define TRNG_ISR_DATRDY_Msk                   (_UINT32_(0x1) << TRNG_ISR_DATRDY_Pos)               /* (TRNG_ISR) Data Ready Mask */
#define TRNG_ISR_DATRDY(value)                (TRNG_ISR_DATRDY_Msk & (_UINT32_(value) << TRNG_ISR_DATRDY_Pos)) /* Assignment of value for DATRDY in the TRNG_ISR register */
#define TRNG_ISR_Msk                          _UINT32_(0x00000001)                                 /* (TRNG_ISR) Register Mask  */


/* -------- TRNG_ODATA : (TRNG Offset: 0x50) ( R/ 32) Output Data Register -------- */
#define TRNG_ODATA_ODATA_Pos                  _UINT32_(0)                                          /* (TRNG_ODATA) Output Data Position */
#define TRNG_ODATA_ODATA_Msk                  (_UINT32_(0xFFFFFFFF) << TRNG_ODATA_ODATA_Pos)       /* (TRNG_ODATA) Output Data Mask */
#define TRNG_ODATA_ODATA(value)               (TRNG_ODATA_ODATA_Msk & (_UINT32_(value) << TRNG_ODATA_ODATA_Pos)) /* Assignment of value for ODATA in the TRNG_ODATA register */
#define TRNG_ODATA_Msk                        _UINT32_(0xFFFFFFFF)                                 /* (TRNG_ODATA) Register Mask  */


/* TRNG register offsets definitions */
#define TRNG_CR_REG_OFST               _UINT32_(0x00)      /* (TRNG_CR) Control Register Offset */
#define TRNG_IER_REG_OFST              _UINT32_(0x10)      /* (TRNG_IER) Interrupt Enable Register Offset */
#define TRNG_IDR_REG_OFST              _UINT32_(0x14)      /* (TRNG_IDR) Interrupt Disable Register Offset */
#define TRNG_IMR_REG_OFST              _UINT32_(0x18)      /* (TRNG_IMR) Interrupt Mask Register Offset */
#define TRNG_ISR_REG_OFST              _UINT32_(0x1C)      /* (TRNG_ISR) Interrupt Status Register Offset */
#define TRNG_ODATA_REG_OFST            _UINT32_(0x50)      /* (TRNG_ODATA) Output Data Register Offset */

#if !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__))
/* TRNG register API structure */
typedef struct
{
  __O   uint32_t                       TRNG_CR;            /* Offset: 0x00 ( /W  32) Control Register */
  __I   uint8_t                        Reserved1[0x0C];
  __O   uint32_t                       TRNG_IER;           /* Offset: 0x10 ( /W  32) Interrupt Enable Register */
  __O   uint32_t                       TRNG_IDR;           /* Offset: 0x14 ( /W  32) Interrupt Disable Register */
  __I   uint32_t                       TRNG_IMR;           /* Offset: 0x18 (R/   32) Interrupt Mask Register */
  __I   uint32_t                       TRNG_ISR;           /* Offset: 0x1C (R/   32) Interrupt Status Register */
  __I   uint8_t                        Reserved2[0x30];
  __I   uint32_t                       TRNG_ODATA;         /* Offset: 0x50 (R/   32) Output Data Register */
} trng_registers_t;


#endif /* !(defined(__ASSEMBLER__) || defined(__IAR_SYSTEMS_ASM__)) */
#endif /* _PIC32CZCA70_TRNG_COMPONENT_H_ */
