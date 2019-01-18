#ifndef __set_output_H__
#define __set_output_H__

#include "driver.h"
#include "device.h"
#include "driver/gpio.h"

class set_output : public Device {
	private:
		enum {
			s_detect, s_set, s_wait
		} state;
		int set_output_status;
		bool set_output_flag;
		int val;
		int myaddr;

	public:
		TickType_t tickcnt;
		// constructor
		set_output(void);
		// override
		void init(void);
		void process(Driver *drv);
		int prop_count(void);
		bool prop_name(int index, char *name);
		bool prop_unit(int index, char *unit);
		bool prop_attr(int index, char *attr);
		bool prop_read(int index, char *value);
		bool prop_write(int index, char *value);
		// method
		void on(int dev_addr);
		void off(int dev_addr);
		void pump(int ctrl);
};

#endif
