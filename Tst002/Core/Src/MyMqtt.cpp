/*
 * MyMqtt.cpp
 *
 *  Created on: 16 apr. 2022 г.
 *      Author: a.demykin
 */

/*
 * Example from this
 *
 * https://github.com/xstackman/MQTT_STM32F7
 *
 */

#include "MyMqtt.h"

static void mqtt_pub_request_cb(void *arg, err_t result) {
  if (result != ERR_OK) {
    printf("Publish result: %d\n", result);
  }
}

static void mqtt_connection_cb(mqtt_client_t *client, void *arg,
    mqtt_connection_status_t status) {
  //err_t err;
  if (status == MQTT_CONNECT_ACCEPTED) {
    printf("mqtt_connection_cb: Successfully connected\n");

    /* Setup callback for incoming publish requests */
    // mqtt_set_inpub_callback(client, mqtt_incoming_publish_cb, mqtt_incoming_data_cb, arg);
    /* Subscribe to a topic named "subtopic" with QoS level 1, call mqtt_sub_request_cb with result */
    // err = mqtt_subscribe(client, "subtopic", 1, mqtt_sub_request_cb, arg);
    //if(err != ERR_OK) {
    //  printf("mqtt_subscribe return: %d\n", err);
    //}
  } else {
    printf("mqtt_connection_cb: Disconnected, reason: %d\n", status);

    /* Its more nice to be connected, so try to reconnect */
    example_do_connect(client);
  }
}

void example_do_connect(mqtt_client_t *client) {
  struct mqtt_connect_client_info_t ci;
  err_t err;

  /* Setup an empty client info structure */
  memset(&ci, 0, sizeof(ci));

  /* Minimal amount of information required is client identifier, so set it here */
  ci.client_id = "vkr_device";

  /* Initiate client and connect to server, if this fails immediately an error code is returned
   otherwise mqtt_connection_cb will be called with connection result after attempting
   to establish a connection with the server.
   For now MQTT version 3.1.1 is always used */

  err = mqtt_client_connect(client, &ip_addr, MQTT_PORT, mqtt_connection_cb, 0,
      &ci);

  if (err != ERR_OK) {
    printf("mqtt_connect return %d\n", err);
  }
}

void example_publish(mqtt_client_t *client, void *arg, float *t, float *p,
    float *h) {
  size_t sz = 35;
  char message[sz];
  snprintf(message, sz, "{\"t\": %2.2f,\"p\": %2.2f,\"h\":%2.2f}", *t, *p, *h);

  err_t err;
  u8_t qos = 0; /* 0 1 or 2, see MQTT specification */
  u8_t retain = 0; /* No don't retain such crappy payload... */

  err = mqtt_publish(client, "vkr_topic", message, sz - 1, qos, retain,
      mqtt_pub_request_cb, arg);

  if (err != ERR_OK) {
    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_14);
    //HAL_UART_Transmit(&huart3, &err,1,100);
    printf("Publish err: %d\n", err);
  }

  mqtt_disconnect(client);
}

MyMqtt::MyMqtt() {
}

void MyMqtt::send() {
}

