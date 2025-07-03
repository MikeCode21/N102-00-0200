#ifndef UART_DEBUG_H
#define UART_DEBUG_H

#ifdef UART1_EN
void _uart1_send_byte(u8_t byte);
void _uart1_send_string(u8_t *string,u8_t bytes);
bit _uart1_get_byte(u8_t *pdat);
#endif
#ifdef UART2_EN
void _uart2_send_byte(u8_t byte);
void _uart2_send_string(u8_t *string,u8_t bytes);
bit _uart2_get_byte(u8_t *pdat);
#endif
#ifdef USE_UART1_DEBUGGING
	#define Debug_UartSendByte(byte)							_uart1_send_byte(byte)	
	#define Debug_UartSendString(string,bytes)		_uart1_send_string(string,bytes)	
	#ifdef DEBUG_PRINTF_EN
		void uart_printf(char *fmt,...); 
	#endif
#elif defined USE_UART2_DEBUGGING
	#define Debug_UartSendByte(byte)							_uart2_send_byte(byte)	
	#define Debug_UartSendString(string,bytes)		_uart2_send_string(string,bytes)	
	#ifdef DEBUG_PRINTF_EN
		void uart_printf(char *fmt,...); 
	#endif
#else
	#define Debug_UartSendByte(byte)							//_nop_()	
	#define Debug_UartSendString(string,bytes)		//_nop_()	
#endif	

#endif