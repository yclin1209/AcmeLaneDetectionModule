
#include <stdio.h>
#include <wchar.h>
#include <string.h>
#include <stdlib.h>
#include <hidapi/hidapi.h>
#include <unistd.h>
#include <math.h>
//#include <linux/delay.h>

int main(int argc, char* argv[])
{
	int res;
	unsigned char buf[256];
	#define MAX_STR 255
	wchar_t wstr[MAX_STR];
	hid_device *handle;
	int i;


	struct hid_device_info *devs, *cur_dev;
	
	if (hid_init())
		return -1;

	// Open the device using the VID, PID,
	// and optionally the Serial number.
	handle = hid_open(0x46D, 0xC24F, NULL);
	if (!handle) {
		printf("unable to open device\n");
 		return 1;
	}

	// Read the Manufacturer String
	wstr[0] = 0x0000;
	res = hid_get_manufacturer_string(handle, wstr, MAX_STR);
	if (res < 0)
		printf("Unable to read manufacturer string\n");
	printf("Manufacturer String: %ls\n", wstr);

	// Read the Product String
	wstr[0] = 0x0000;
	res = hid_get_product_string(handle, wstr, MAX_STR);
	if (res < 0)
		printf("Unable to read product string\n");
	printf("Product String: %ls\n", wstr);


    //1. forceOff()// turn off effects (except for auto-center)
    //   relayOS([slot, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00])
    //   slot = 0xf3 or 0x?0

    //init command buffer
    memset(buf,0x00,sizeof(buf));

    buf[0] = 0xf3;
    buf[1] = 0;
    buf[2] = 0;
    buf[3] = 0;
    buf[4] = 0;
    buf[5] = 0;
    buf[6] = 0;
    res = hid_write(handle, buf,7);
    if (res < 0) {
        printf("Unable to write()\n");
        printf("Error: %ls\n", hid_error(handle));
    }

    //2. if data.length == 12
    //enter listen loop

    //3. setRange()
    //   range1 = options.range & 0x00ff
    //   range2 = (options.range & 0xff00) >> 8
    // relayOS([0xf8, 0x81, range1, range2, 0x00, 0x00, 0x00])
   
    memset(buf,0x00,sizeof(buf));
    buf[0] = 0xf8;
    buf[1] = 0x81;
    buf[2] = 300 & 0x00ff;
    buf[3] = (300 & 0xff00)>>8;
    buf[4] = 0;
    buf[5] = 0;
    buf[6] = 0;
    res = hid_write(handle, buf,7);
    if (res < 0) {
        printf("Unable to write()\n");
        printf("Error: %ls\n", hid_error(handle));
    }

  
    //4. autoCenter()
    //  auto-center on
    //  relayOS([0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00])

    memset(buf,0x00,sizeof(buf));
    buf[0] = 0xf5;//off
    //buf[0] = 0x14;//on
    buf[1] = 0x00;
    buf[2] = 0x00;
    buf[3] = 0x00;
    buf[4] = 0x00;
    buf[5] = 0;
    buf[6] = 0;
    res = hid_write(handle, buf,7);
    if (res < 0) {
        printf("Unable to write()\n");
        printf("Error: %ls\n", hid_error(handle));
    }
/*
    // custom auto-center
    memset(buf,0x00,sizeof(buf));
    buf[0] = 0xfe;
    buf[1] = 0x0d;
    buf[2] = round(0.4*15);
    buf[3] = round(0.4*15);
    buf[4] = round(0.3*255);
    buf[5] = 0;
    buf[6] = 0;
    res = hid_write(handle, buf,7);
    if (res < 0) {
        printf("Unable to write()\n");
        printf("Error: %ls\n", hid_error(handle));
    }
*/


    // friction present when turning the wheel
    // the first "number" is for left rotation, the second for right rotation
    // 0x00 through 0x07 range,
    // 0x07 is the strongest friction and then 0x08 is no friction
    // relayOS([0x21, 0x02, number, 0x00, number, 0x00, 0x00])
    memset(buf,0x00,sizeof(buf));
    buf[0] = 0x21;
    buf[1] = 0x02;
    buf[2] = 0x01; //friction num, left
    buf[3] = 0x00;
    buf[4] = 0x01; //friction num, right
    buf[5] = 0x00;
    buf[6] = 0x00;
    res = hid_write(handle, buf,7);
    if (res < 0) {
        printf("Unable to write()\n");
        printf("Error: %ls\n", hid_error(handle));
    }

    for(int i=0;i<1;i++)
    {
        //force
        //relayOS([0x11, 0x00, number, 0x00, 0x00, 0x00, 0x00])

        memset(buf,0x00,sizeof(buf));
        buf[0] = 0x11;
        buf[1] = 0x00;
        buf[2] = 0xff;
        buf[3] = 0x00;
        buf[4] = 0x00;
        buf[5] = 0;
        buf[6] = 0;
        res = hid_write(handle, buf,7);
        if (res < 0) {
            printf("Unable to write()\n");
            printf("Error: %ls\n", hid_error(handle));
        }
    usleep(75000);// sampling rate( about 13 FPS )
    // forceOff(1)
    memset(buf,0x00,sizeof(buf));
    buf[0] = 0x10;
    buf[1] = 0x00;
    buf[2] = 0x00;
    buf[3] = 0x00;
    buf[4] = 0x00;
    buf[5] = 0;
    buf[6] = 0;
    res = hid_write(handle, buf,7);
    if (res < 0) {
        printf("Unable to write()\n");
        printf("Error: %ls\n", hid_error(handle));
    }

        //usleep(75000);// sampling rate( about 13 FPS )
     }
       
/*
        //force
        //relayOS([0x11, 0x00, number, 0x00, 0x00, 0x00, 0x00])

        memset(buf,0x00,sizeof(buf));
        buf[0] = 0x10;
        buf[1] = 0x00;
        buf[2] = 0x00;
        buf[3] = 0x00;
        buf[4] = 0x00;
        buf[5] = 0;
        buf[6] = 0;
        res = hid_write(handle, buf,7);
        if (res < 0) {
            printf("Unable to write()\n");
            printf("Error: %ls\n", hid_error(handle));
        }
        usleep(300000);
*/
    
/*
    // forceOff(1)
    memset(buf,0x00,sizeof(buf));
    buf[0] = 0x10;
    buf[1] = 0x00;
    buf[2] = 0x00;
    buf[3] = 0x00;
    buf[4] = 0x00;
    buf[5] = 0;
    buf[6] = 0;
    res = hid_write(handle, buf,7);
    if (res < 0) {
        printf("Unable to write()\n");
        printf("Error: %ls\n", hid_error(handle));
    }
*/

	hid_close(handle);
	/* Free static HIDAPI objects. */
	hid_exit();

	return 0;
}
