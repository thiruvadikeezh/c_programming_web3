#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"


#include "lwip/tcp.h"
#include "lwip/ip_addr.h"



#define WIFI_SSID	 "Airtel_sudh_1239"
#define WIFI_PASSWORD	 "air19530"

#define SERVER_IP	"192.168.1.3"
#define SERVER_PORT	8008


int delay;

static bool led_state = false;

static inline void led_toggle(void)
{
	led_state = !led_state;
	cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, led_state);
}

void led_off(void)
{
	led_state = false;
	cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);

}
void led_blink(int count)
{
	if (count <= 0){
		printf("NO Proper Input Provided For the leb blink\n");
		return;
	}


	delay = 1000/ (count * 2);
	for (int i = 0; i < count * 2; i++){
		led_toggle();
		sleep_ms(delay);
	}

	led_off();
}

	
void wifi_init(void)
{
	stdio_init_all();
	sleep_ms(4000);
	
	printf("startup delay ended\n");

	if (cyw43_arch_init()) {
		printf("WIFI chip Init Failed\n");
		led_blink(2);
	}
	led_blink(10);
	cyw43_arch_enable_sta_mode();
	printf("Connecting TO Wifi.......\n");

	if(cyw43_arch_wifi_connect_timeout_ms(
				WIFI_SSID,
				WIFI_PASSWORD,
				CYW43_AUTH_WPA2_AES_PSK,
				30000)) {

		printf("WIFI Connection Failed\n");
	}
	
	printf("WIFI Connected\n");
	led_blink(5);
}

static struct tcp_pcb *client_pcb = NULL;

static err_t connected_callback(void *arg, struct tcp_pcb *tpcb, err_t err)
{
	if(err != ERR_OK) {
		printf("Connection Failed\n");
		return err;
	}

	printf("Connected to Server Succesfully\n");

	client_pcb = tpcb;

	return ERR_OK;
}


void tcp_connect_to_server()
{
	ip_addr_t server_ip;
	if(!ipaddr_aton(SERVER_IP, &server_ip)) {
		printf("Invalid Server IP\n");
	}

	struct tcp_pcb *pcb = tcp_new();
	
	if (!pcb)
	{

		printf("Failed to create TCP PCB\n");
		return;
	}

	printf("Connecting tO Server.........\n");

	err_t err = tcp_connect(pcb, &server_ip, SERVER_PORT, connected_callback);

	if (err != ERR_OK){
		printf("tcp Connection Failed\n");
		tcp_close(pcb);
	}

}


int main()
{
    wifi_init();
}


