/*
 * Copyright (c) 2007, Swedish Institute of Computer Science.
 * All rights reserved. 
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met: 
 * 1. Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer. 
 * 2. Redistributions in binary form must reproduce the above copyright 
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the distribution. 
 * 3. Neither the name of the Institute nor the names of its contributors 
 *    may be used to endorse or promote products derived from this software 
 *    without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND 
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE 
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS 
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) 
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT 
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY 
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF 
 * SUCH DAMAGE. 
 *
 * This file is part of the Contiki operating system.
 * 
 * Author: Oliver Schmidt <ol.sc@web.de>
 *
 */

#include <stdlib.h>
#include <string.h>

#include "contiki-net.h"
#include "cfs/cfs.h"
#include "sys/log.h"
#include "lib/error.h"

#include "lib/config.h"

struct config_t config;

/*-----------------------------------------------------------------------------------*/
#if LOG_CONF_ENABLED
static char *
ipaddrtoa(uip_ipaddr_t *ipaddr, char *buffer)
{
  char *ptr = buffer;
  uint8_t i;

  for(i = 0; i < 4; ++i) {
    *ptr = '.';
    utoa(ipaddr->u8[i], ++ptr, 10);
    ptr += strlen(ptr);
  }

  return buffer + 1;
}
#endif /* LOG_CONF_ENABLED */
/*-----------------------------------------------------------------------------------*/
void
config_read(char *filename)
{
  int file;

  file = cfs_open(filename, CFS_READ);
  if(file < 0) {
    log_message(filename, ": File not found");
    error_exit();
  }

  if(cfs_read(file, &config, sizeof(config)) < sizeof(uip_ipaddr_t) * 4
                                             + sizeof(uint16_t)) {
    log_message(filename, ": No config file");
    error_exit();
  }

  cfs_close(file);

  log_message("IP Address:  ", ipaddrtoa(&config.hostaddr, uip_buf));
  log_message("Subnet Mask: ", ipaddrtoa(&config.netmask, uip_buf));
  log_message("Def. Router: ", ipaddrtoa(&config.draddr, uip_buf));
  log_message("DNS Server:  ", ipaddrtoa(&config.resolvaddr, uip_buf));

#ifdef STATIC_DRIVER
  #define _stringize(arg) #arg
  #define  stringize(arg) _stringize(arg)
#if WITH_SLIP
  log_message("SLIP Driver: ", stringize(STATIC_DRIVER));
#else /* WITH_SLIP */
  log_message("Eth. Driver: ", stringize(STATIC_DRIVER));
#endif /* WITH_SLIP */
  #undef  _stringize
  #undef   stringize
#else /* STATIC_DRIVER */
  log_message("Eth. Driver: ", config.ethernet.name);
#endif /* STATIC_DRIVER */

  uip_sethostaddr(&config.hostaddr);
  uip_setnetmask(&config.netmask);
  uip_setdraddr(&config.draddr);
#if WITH_DNS
  uip_nameserver_update(&config.resolvaddr, UIP_NAMESERVER_INFINITE_LIFETIME);
#endif /* WITH_DNS */
}
/*-----------------------------------------------------------------------------------*/
