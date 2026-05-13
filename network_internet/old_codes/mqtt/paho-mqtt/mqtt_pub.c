#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "MQTTClient.h"

#define ADDRESS     "tcp://192.168.1.3:1883"
#define CLIENTID    "counter_publisher"
#define TOPIC       "test/counter"
#define QOS         1
#define TIMEOUT     10000L


int main()
{

	MQTTClient client; // this is an structure;
	MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
	MQTTClient_deliveryToken token;

	int rc;

	rc = MQTTClient_create(&client, ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);

	if (rc != MQTTCLIENT_SUCCESS) {
		printf("Client Create failed\n");
		return -1;
	}

	conn_opts.keepAliveInterval = 20;
	conn_opts.cleansession = 1;

	rc = MQTTClient_connect(client, &conn_opts);

	if (rc != MQTTCLIENT_SUCCESS){
		printf("Connection failed\n");
		return -1;
	}

	printf("Connected to broker\n");

	int counter = 0;

	char payload[50];

	while(1){
		sprintf(payload, "Count: %d", counter++);

		MQTTClient_message pubmsg = MQTTClient_message_initializer;
		pubmsg.payload = payload;
		pubmsg.payloadlen = strlen(payload);
		pubmsg.qos = QOS;
		pubmsg.retained = 0;

		MQTTClient_publishMessage(client, TOPIC, &pubmsg, &token);
		MQTTClient_waitForCompletion(client, token, TIMEOUT);
		printf("Published: %s\n", payload);

		sleep(1);
	}

	MQTTClient_disconnect(client, 1000);
	MQTTClient_destroy(&client);

		return 0;
}



