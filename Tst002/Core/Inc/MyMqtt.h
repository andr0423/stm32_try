/*
 * MyMqtt.h
 *
 *  Created on: 16 apr. 2022 г.
 *      Author: a.demykin
 */

#ifndef SRC_MYMQTT_H_
#define SRC_MYMQTT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <mqtt.h>
#include <string.h>



extern ip_addr_t ip_addr;

void example_do_connect(mqtt_client_t *client);

void example_publish(mqtt_client_t *client, void *arg, float * t, float * p, float * h);



class MyMqtt {
public:
	MyMqtt();
	void send();
};

#ifdef __cplusplus
}
#endif

#endif /* SRC_MYMQTT_H_ */
