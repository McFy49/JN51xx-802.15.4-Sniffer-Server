/****************************************************************************
 *
 * Copyright 2017 Lee Mitchell <lee@indigopepper.com>
 * Copyright 2020 Matthieu Guérif <guerif.matthieu@icloud.com>
 *
 * This file is part of JN51xx 802.15.4 Sniffer Server
 *
 * JN51xx 802.15.4 Sniffer Server is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * JN51xx 802.15.4 Sniffer Server is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with JN51xx 802.15.4 Sniffer Server.  If not,
 * see <http://www.gnu.org/licenses/>.
 ****************************************************************************/

/*
Include files
*/

#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>
#include <fcntl.h> 
#include <errno.h>
#include <termios.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/syslog.h>
#include <sys/un.h>
#include "uart.h"

/*
Macro Definitions
*/

#define UART_READ_TIMEOUT     2000    /* timeout time in millisecs    */
#define UART_WRITE_TIMEOUT    2000    /* write timeout in millisecs   */

#define MAX_VALUE_NAME  100 

#define TRUE 1
#define FALSE 0

/*
Exported Functions
*/

void UART_vListPorts(void) {
    printf("The following serial ports are present:\n");
    PrintListPorts("/dev/",0);
    exit(0);

}

void PrintListPorts(char *dir, int depth) {
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    if((dp = opendir(dir)) == NULL) {
        fprintf(stderr,"cannot open directory: %s\n", dir);
        return;
    }
    chdir(dir);
    while((entry = readdir(dp)) != NULL) {

        lstat(entry->d_name,&statbuf);
        if (entry->d_name[0]=='t'&&entry->d_name[1]=='t'&&entry->d_name[2]=='y'&&entry->d_name[3]=='.')
            printf("%*s%s/\n",depth,"",entry->d_name);
   }
    chdir("..");
    closedir(dp);
}


bool UART_bOpen(const char *acPortName, int iBaudRate){

	if(access(acPortName, F_OK )!= 0)
		return(FALSE);
}

 		

bool UART_bClose(HANDLE hUartHandle)
{
    return(TRUE);
}

bool UART_bReadWithTimeout(HANDLE hUartHandle, uint8_t *pu8Data, int iNumBytesToRead, DWORD dwTimeout, DWORD *pdwBytesRead) {
	return(TRUE);
}

bool UART_bRead(HANDLE hUartHandle, uint8_t *pu8Data) {
    return(TRUE);

}


bool UART_bWrite(HANDLE hUartHandle, uint8_t u8Data) {
	return(TRUE);
}

bool UART_bWriteBytes(HANDLE hUartHandle, uint8_t *pu8Data, int iLength) {
	return(TRUE);
}

