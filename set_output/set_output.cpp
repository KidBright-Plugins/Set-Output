#include "esp_system.h"
#include "kidbright32.h"
#include "set_output.h"
#include <stdio.h>

set_output::set_output(void) {
	//
}

void set_output::init(void) {
	gpio_config_t io_conf;

	// outputs init
	io_conf.intr_type = GPIO_INTR_DISABLE; // disable interrupt
	io_conf.mode = GPIO_MODE_OUTPUT ; // set as output mode
	io_conf.pin_bit_mask = (1ULL << OUT1_GPIO); // pin bit mask
	io_conf.pin_bit_mask = (1ULL << OUT2_GPIO); // pin bit mask
	io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE; // disable pull-down mode
	io_conf.pull_up_en = GPIO_PULLUP_DISABLE; // disable pull-up mode
	set_output_status = 1;
	gpio_config(&io_conf);

	set_output_flag = false;
	state = s_detect;
}

int set_output::prop_count(void) {
	// not supported
	return 0;
}

bool set_output::prop_name(int index, char *name) {
	// not supported
	return false;
}

bool set_output::prop_unit(int index, char *unit) {
	// not supported
	return false;
}

bool set_output::prop_attr(int index, char *attr) {
	// not supported
	return false;
}

bool set_output::prop_read(int index, char *value) {
	// not supported
	return false;
}

bool set_output::prop_write(int index, char *value) {
	// not supported
	return false;
}

void set_output::process(Driver *drv) {
	switch (state) {
		case s_detect:
			// clear error flag
			error = false;
			// set initialized flag
			initialized = true;
			// go to read state
			state = s_set;
			break;
		case s_set:
			break;
		case s_wait:
			break;
	}
}

void set_output::on(int dev_addr) {
	myaddr = dev_addr;
	state = s_set;
	if(dev_addr==26){
		gpio_set_level(OUT1_GPIO, 1);
	}else if(dev_addr==27){
		gpio_set_level(OUT2_GPIO, 1);
	}
}

void set_output::off(int dev_addr) {
	myaddr = dev_addr;
	state = s_wait;
	if(dev_addr==26){
		gpio_set_level(OUT1_GPIO, 0);
	}else if(dev_addr==27){
		gpio_set_level(OUT2_GPIO, 0);
	}
}

void set_output::pump(int ctrl) {
	//printf("pump\n");
	if(ctrl==1){
		gpio_set_level(OUT1_GPIO, 1);
		//printf("ON\n");
	}else if(ctrl==0){
		//printf("OFF\n");
		gpio_set_level(OUT1_GPIO, 0);
	}
}
