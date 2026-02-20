#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

#include "lwip/tcp.h"
#include "lwip/ip_addr.h"


#define WIFI_SSID     "Airtel_sudh_1239"
#define WIFI_PASSWORD "air19530"

#define SERVER_IP     "192.168.1.3"
#define SERVER_PORT    8008


static err_t connected_callback(void *arg, struct tcp_pcb *tpcb, err_t err) {
	if (err != ERR_OK) {
		printf("Conenction Failed\n");
		return err;
	}

	printf("Connected to server!\n");



	const char *msg = "Hello from Pico 2W!";
	tcp_write(tpcb, msg, strlen(msg), TCP_WRITE_FLAG_COPY);
	tcp_output(tpcb);

	printf("Message Sent\n");

	return ERR_OK;

}

int main()
{
	stdio_init_all();
	sleep_ms(2000);

	if (cyw43_arch_init()) {
		printf("WIFI Init Failed\n");
		return -1;
	}

	cyw43_arch_enable_sta_mode();

	printf("Conencting to WIFI....\n");
	

	if (cyw43_arch_wifi_connect_timeout_ms(
				WIFI_SSID,
				WIFI_PASSWORD,
				CYW43_AUTH_WPA2_AES_PSK,
				30000)) {
		printf("Wifi Failed\n");
		return -1;
	}

	printf("WIFI Conented \n");
	
	ip_addr_t server_ip;
	ipaddr_aton(SERVER_IP, &server_ip);

	struct tcp_pcb *pcb = tcp_new();
	
	if (!pcb) {
		printf("TCP Crete Failed\n");
		return -1;
	}

	printf("Connecting To Server....\n");

	tcp_connect(pcb, &server_ip, SERVER_PORT, connected_callback);

	while(true) {
		cyw43_arch_poll();
		sleep_ms(10);
	}
}


