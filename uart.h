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
 *
 ****************************************************************************/

#ifndef UART_H_INCLUDED
#define UART_H_INCLUDED

/*
ignore windows specific API
*/

#ifndef DWORD
#define WINAPI
typedef unsigned long DWORD;
typedef short WCHAR;
typedef int * HANDLE;
#define MAX_PATH    PATH_MAX
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int BOOL;
typedef const char * LPCSTR;
typedef const char * LPCTSTR;
typedef const char * LPCWSTR;
typedef const char * LPCH;
typedef char * LPTSTR;
typedef char * LPSTR;
typedef char * LPWSTR;
#endif

/*
	Include files
*/

#include <stdint.h>


/*
	Classes
*/

void UART_vListPorts(void);
void PrintListPorts(char *dir, int depth);
bool UART_bOpen(const char *acPortName, int iBaudRate);
bool UART_bClose(HANDLE hUartHandle);
bool UART_bRead(HANDLE hUartHandle, uint8_t *pu8Data);
bool UART_bReadWithTimeout(HANDLE hUartHandle, uint8_t *pu8Data, int iNumBytesToRead, DWORD dwTimeout, DWORD *pdwBytesRead);
bool UART_bWrite(HANDLE hUartHandle, uint8_t u8Data);
bool UART_bWriteBytes(HANDLE hUartHandle, uint8_t *pu8Data, int iLength);


#endif /* UART_H_INCLUDED */
