/************************************************************
 * up_leds.c
 *
 *   Copyright (C) 2007 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <spudmonkey@racsa.co.cr>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name Gregory Nutt nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ************************************************************/

/************************************************************
 * Included Files
 ************************************************************/

#include <nuttx/config.h>
#include <sys/types.h>
#include "up_internal.h"

/************************************************************
 * Definitions
 ************************************************************/

#define CS2  *(volatile uint32*)0xffff2e08
#define LEDS *(volatile uint32*)0x01000000

/************************************************************
 * Private Data
 ************************************************************/

static uint32 g_ledstate;

/************************************************************
 * Private Functions
 ************************************************************/

/************************************************************
 * Public Funtions
 ************************************************************/

/************************************************************
 * Name: up_ledinit
 ************************************************************/

#ifdef CONFIG_ARCH_LEDS
void up_ledinit(void)
{
  GIO_OUTPUT(GIO_LED_GREEN);
  GIO_OUTPUT(GIO_LED_RED);
  GIO_SET_OUTPUT(GIO_LED_GREEN);
  GIO_CLEAR_OUTPUT(GIO_LED_RED);
}

/************************************************************
 * Name: up_ledon
 ************************************************************/

void up_ledon(int led)
{
  if (led == GIO_LED_GREEN)
    {
      GIO_SET_OUTPUT(GIO_LED_GREEN);
    }
  else if (led == GIO_LED_RED)
    {
      GIO_SET_OUTPUT(GIO_LED_RED);
    }
}

/************************************************************
 * Name: up_ledoff
 ************************************************************/

void up_ledoff(int led)
{
  if (led == GIO_LED_GREEN)
    {
      GIO_CLEAR_OUTPUT(GIO_LED_GREEN);
    }
  else if (led == GIO_LED_RED)
    {
      GIO_CLEAR_OUTPUT(GIO_LED_RED);
    }
}
#endif /* CONFIG_ARCH_LEDS */
