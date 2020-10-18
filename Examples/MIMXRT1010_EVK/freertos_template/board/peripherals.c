/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Peripherals v8.0
processor: MIMXRT1011xxxxx
package_id: MIMXRT1011DAE5A
mcu_data: ksdk2_0
processor_version: 8.0.2
board: MIMXRT1010-EVK
functionalGroups:
- name: BOARD_InitPeripherals
  UUID: 5e519eed-bd94-4950-84de-0f29de85bcea
  called_from_default_init: true
  selectedCore: core0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'system'
- type_id: 'system'
- global_system_definitions:
  - user_definitions: ''
  - user_includes: ''
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "peripherals.h"

/***********************************************************************************************************************
 * BOARD_InitPeripherals functional group
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * DebugConsole initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'DebugConsole'
- type: 'debug_console'
- mode: 'general'
- custom_name_enabled: 'false'
- type_id: 'debug_console_51864e4f3ac859dae7b603e07bc4ae33'
- functional_group: 'BOARD_InitPeripherals'
- config_sets:
  - fsl_debug_console:
    - config:
      - SDK_DEBUGCONSOLE: 'DEBUGCONSOLE_REDIRECT_TO_TOOLCHAIN'
      - SDK_DEBUGCONSOLE_UART: 'serial_port'
      - DEBUG_CONSOLE_RX_ENABLE: 'true'
      - DEBUG_CONSOLE_PRINTF_MAX_LOG_LEN: '128'
      - DEBUG_CONSOLE_SCANF_MAX_LOG_LEN: '20'
      - DEBUG_CONSOLE_ENABLE_ECHO: 'false'
      - PRINTF_FLOAT_ENABLE: 'false'
      - SCANF_FLOAT_ENABLE: 'false'
      - PRINTF_ADVANCED_ENABLE: 'false'
      - SCANF_ADVANCED_ENABLE: 'false'
      - DEBUG_CONSOLE_TRANSFER_NON_BLOCKING: 'false'
      - DEBUG_CONSOLE_TRANSMIT_BUFFER_LEN: '512'
      - DEBUG_CONSOLE_RECEIVE_BUFFER_LEN: '1024'
      - DEBUG_CONSOLE_TX_RELIABLE_ENABLE: 'true'
      - DEBUG_CONSOLE_DISABLE_RTOS_SYNCHRONIZATION: 'false'
    - peripheral_config:
      - serial_port_type: 'kSerialPort_Uart'
      - uart_config:
        - peripheralUART: 'LPUART1'
        - clockSource: 'genericUartClockSource'
        - clockSourceFreq: 'BOARD_BootClockRUN'
        - baudRate_Bps: '115200'
        - quick_selection: 'QuickSelection1'
    - debug_console_codegenerator: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

static void DebugConsole_init(void) {
  /* Debug console initialization */
  status_t result;
  result = DbgConsole_Init(DEBUGCONSOLE_INSTANCE, DEBUGCONSOLE_BAUDRATE, DEBUGCONSOLE_TYPE, DEBUGCONSOLE_CLK_FREQ);
  assert(kStatus_Success == result);
}

/***********************************************************************************************************************
 * USER_LED initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'USER_LED'
- type: 'igpio'
- mode: 'GPIO'
- custom_name_enabled: 'true'
- type_id: 'igpio_b1c1fa279aa7069dca167502b8589cb7'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'GPIO1'
- config_sets:
  - fsl_gpio:
    - enable_irq_comb_0_15: 'true'
    - gpio_interrupt_comb_0_15:
      - IRQn: 'GPIO1_Combined_0_15_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
    - enable_irq_comb_16_31: 'true'
    - gpio_interrupt_comb_16_31:
      - IRQn: 'GPIO1_Combined_16_31_IRQn'
      - enable_interrrupt: 'enabled'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

static void USER_LED_init(void) {
  /* Make sure, the clock gate for GPIO1 is enabled (e. g. in pin_mux.c) */
  /* Enable interrupt GPIO1_Combined_0_15_IRQn request in the NVIC */
  EnableIRQ(GPIO1_Combined_0_15_IRQn);
  /* Enable interrupt GPIO1_Combined_16_31_IRQn request in the NVIC */
  EnableIRQ(GPIO1_Combined_16_31_IRQn);
}

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/
void BOARD_InitPeripherals(void)
{
  /* Initialize components */
  DebugConsole_init();
  USER_LED_init();
}

/***********************************************************************************************************************
 * BOARD_InitBootPeripherals function
 **********************************************************************************************************************/
void BOARD_InitBootPeripherals(void)
{
  BOARD_InitPeripherals();
}
