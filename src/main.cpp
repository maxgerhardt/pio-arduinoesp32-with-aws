#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
#include "sdkconfig.h"
#include <Arduino.h>
#include "aws_iot_config.h"
#include "aws_iot_log.h"
#include "aws_iot_version.h"
#include "aws_iot_mqtt_client_interface.h"

static const char *TAG = "subpub";

#ifndef LED_BUILTIN
#define LED_BUILTIN 4
#endif

void setup() {
    Serial.begin(115200);
}

void loop() {
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    Serial.println("Hello!");
    ESP_LOGI(TAG, "AWS IoT SDK Version %d.%d.%d-%s", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH, VERSION_TAG);
    // just an example call, won't work of course
    // integrate https://github.com/platformio/platform-espressif32/blob/develop/examples/espidf-aws-iot/src/subscribe_publish_sample.c
    IoT_Error_t rc = aws_iot_mqtt_init(NULL, NULL);
    delay(1000);
}
