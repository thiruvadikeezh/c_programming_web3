#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

#include "lwip/tcp.h"
#include "lwip/ip_addr.h"


#define WIFI_SSID     "Airtel_sudh_1239"
#define WIFI_PASSWORD "air19530"

#define SERVER_IP     "192.168.1.3"
#define SERVER_PORT    8008

static struct tcp_pcb *global_pcb = NULL;

static err_t recv_callback(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err)
{
	if (!p) {
		printf("Server Closed Conencted\n");
		tcp_close(tpcb);
		global_pcb = NULL;
		return ERR_OK;
	}

	printf( "recevied %d bytes from server: ", p->len);

	fwrite(p->payload, 1, p->len, stdout);
	printf("\n");


	tcp_recved(tpcb, p->len);
	pbuf_free(p);

	return ERR_OK;
}

static err_t connected_callback(void *arg, struct tcp_pcb *tpcb, err_t err) {
	if (err != ERR_OK) {
		printf("Conenction Failed\n");
		return err;
	}

	printf("Connected to server!\n");

	global_pcb = tpcb;

	tcp_recv(tpcb, recv_callback);


	return ERR_OK;

}


void wifi_init(void)
{
	stdio_init_all();
	sleep_ms(2000);

	if ( cyw43_arch_init()) {
		printf("Wifi Init Failed\n");
	}

	cyw43_arch_enable_sta_mode();

	printf("Connecting To Wifi.....\n");

	if (cyw43_arch_wifi_connect_timeout_ms(
				WIFI_SSID,
				WIFI_PASSWORD,
				CYW43_AUTH_WPA2_AES_PSK,
				30000)) {
		printf("WIFI Connection Failed\n");
	}

	printf("WIFI COnnected\n");
}

void tcp_connect_to_server(void)
{
	ip_addr_t server_ip;
	ipaddr_aton(SERVER_IP, &server_ip);

	struct tcp_pcb *pcb = tcp_new();

	if (!pcb) {
		printf("TCP Create Failed\n");
		return;
	}

	printf("Connecting To Server.....\n");
	tcp_connect(pcb, &server_ip, SERVER_PORT, connected_callback);
}

int main()
{
	wifi_init();
	
	tcp_connect_to_server();
	
	uint32_t last_send = 0;


	while(true) {
		cyw43_arch_poll();

		if(global_pcb)
		{
			uint32_t now = to_ms_since_boot(get_absolute_time());

			if (now - last_send > 5000) {
				const char *msg= "Periodic Data From Pico";

				err_t e = tcp_write(global_pcb, msg,strlen(msg), TCP_WRITE_FLAG_COPY);

				if ( e == ERR_OK) {
					tcp_output(global_pcb);
					printf("Sendt: %s\n", msg);
				}
				last_send = now;
			}
		}


		sleep_ms(10);
	}
}


