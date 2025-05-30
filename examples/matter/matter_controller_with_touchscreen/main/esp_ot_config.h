/*
 * SPDX-FileCopyrightText: 2021-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 *
 * OpenThread Border Router Example
 *
 * This example code is in the Public Domain (or CC0 licensed, at your option.)
 *
 * Unless required by applicable law or agreed to in writing, this
 * software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 * CONDITIONS OF ANY KIND, either express or implied.
 */

#pragma once

#include "sdkconfig.h"
#if CONFIG_OPENTHREAD_BORDER_ROUTER
#include "esp_openthread_types.h"

#if CONFIG_OPENTHREAD_RADIO_NATIVE
#define ESP_OPENTHREAD_DEFAULT_RADIO_CONFIG() \
    {                                         \
        .radio_mode = RADIO_MODE_NATIVE,      \
    }
#elif CONFIG_OPENTHREAD_RADIO_SPINEL_UART

#define ESP_OPENTHREAD_DEFAULT_RADIO_CONFIG()                        \
    {                                                                \
        .radio_mode = RADIO_MODE_UART_RCP,                           \
        .radio_uart_config = {                                       \
            .port = UART_NUM_1,                                      \
            .uart_config =                                           \
                {                                                    \
                    .baud_rate = 460800,                             \
                    .data_bits = UART_DATA_8_BITS,                   \
                    .parity = UART_PARITY_DISABLE,                   \
                    .stop_bits = UART_STOP_BITS_1,                   \
                    .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,           \
                    .rx_flow_ctrl_thresh = 0,                        \
                    .source_clk = UART_SCLK_DEFAULT,                 \
                },                                                   \
            .rx_pin = static_cast<gpio_num_t>(CONFIG_PIN_TO_RCP_TX), \
            .tx_pin = static_cast<gpio_num_t>(CONFIG_PIN_TO_RCP_RX), \
        },                                                           \
    }
#else
#define ESP_OPENTHREAD_DEFAULT_RADIO_CONFIG()      \
    {                                              \
        .radio_mode = RADIO_MODE_SPI_RCP,          \
        .radio_spi_config = {                      \
            .host_device = SPI2_HOST,              \
            .dma_channel = 2,                      \
            .spi_interface =                       \
                {                                  \
                    .mosi_io_num = 11,             \
                    .sclk_io_num = 12,             \
                    .miso_io_num = 13,             \
                },                                 \
            .spi_device =                          \
                {                                  \
                    .cs_ena_pretrans = 2,          \
                    .input_delay_ns = 100,         \
                    .mode = 0,                     \
                    .clock_speed_hz = 2500 * 1000, \
                    .spics_io_num = 10,            \
                    .queue_size = 5,               \
                },                                 \
            .intr_pin = 8,                         \
        },                                         \
    }
#endif // CONFIG_OPENTHREAD_RADIO_SPINEL_UART OR  CONFIG_OPENTHREAD_RADIO_SPINEL_SPI

#define HOST_BAUD_RATE 115200

#define ESP_OPENTHREAD_DEFAULT_HOST_CONFIG()               \
    {                                                      \
        .host_connection_mode = HOST_CONNECTION_MODE_NONE, \
    }

#define ESP_OPENTHREAD_DEFAULT_PORT_CONFIG()                                            \
    {                                                                                   \
        .storage_partition_name = "nvs", .netif_queue_size = 10, .task_queue_size = 10, \
    }
#endif // CONFIG_OPENTHREAD_BORDER_ROUTER

#if CONFIG_AUTO_UPDATE_RCP
#define ESP_OPENTHREAD_RCP_UPDATE_CONFIG()                                                                           \
    {                                                                                                                \
        .rcp_type = RCP_TYPE_ESP32H2_UART, .uart_rx_pin = CONFIG_PIN_TO_RCP_TX, .uart_tx_pin = CONFIG_PIN_TO_RCP_RX, \
        .uart_port = UART_NUM_1, .uart_baudrate = 115200, .reset_pin = CONFIG_PIN_TO_RCP_RESET,                      \
        .boot_pin = CONFIG_PIN_TO_RCP_BOOT, .update_baudrate = 460800, .firmware_dir = "/rcp_fw/ot_rcp",             \
        .target_chip = ESP32H2_CHIP,                                                                                 \
    }
#endif
