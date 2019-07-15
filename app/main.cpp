/**
* @file main.cpp
* @brief main script
* @details Used to run the system
* @author Indushekhar Singh
* @version 1.0
* @copyright MIT License (c) 2018 Indushekhar Singh
*/

#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include "../include/SystemManager.hpp"
#include <pthread.h>
#include <hidapi/hidapi.h>
void *child(void *data);
double direction;

int main() {

    while(1)
    {
        pthread_t t;
        pthread_create(&t, NULL, child, NULL);

        SystemManager laneDetection;
        laneDetection.runLane("../input/project_video.mp4", 1200, true);

        pthread_join(t,NULL);
     }

    return 0;
}

//
// Logitech G29 wheel controls logic
// Added by YC Lin,2019,MXIC TW
//
void *child(void *data){
    
    int res;
    unsigned char buf[256];
    hid_device *handle;
    int i;

    struct hid_device_info *devs, *cur_dev;

    if (hid_init())
        //return -1;
        goto EXIT;

    // Open the device using the VID, PID,
    // and optionally the Serial number.
    handle = hid_open(0x46D, 0xC24F, NULL);
    if (!handle) {
        printf("unable to open device\n");
        //return 1;
        goto EXIT;
    }


    //
    // G29 Wheel control
    //

    //1. forceOff()// turn off effects (except for auto-center)
    //   relayOS([slot, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00])
    //   slot = 0xf3 or 0x?0
    memset(buf,0x00,sizeof(buf));
    buf[0] = 0xf3;
    buf[1] = 0x00;
    buf[2] = 0x00;
    buf[3] = 0x00;
    buf[4] = 0x00;
    buf[5] = 0x00;
    buf[6] = 0x00;
    res = hid_write(handle, buf,7);
    if (res < 0) {
        printf("Unable to write()\n");
        printf("Error: %ls\n", hid_error(handle));
    }


    //2. if data.length == 12
    //enter listen loop

    //3. setRange()
    //   range = 270~900 (degree)
    //   range1 = options.range & 0x00ff
    //   range2 = (options.range & 0xff00) >> 8
    //   relayOS([0xf8, 0x81, range1, range2, 0x00, 0x00, 0x00])
    memset(buf,0x00,sizeof(buf));
    buf[0] = 0xf8;
    buf[1] = 0x81;
    buf[2] = 450 & 0x00ff;
    buf[3] = (450 & 0xff00)>>8;
    buf[4] = 0x00;
    buf[5] = 0x00;
    buf[6] = 0x00;
    res = hid_write(handle, buf,7);
    if (res < 0) {
        printf("Unable to write()\n");
        printf("Error: %ls\n", hid_error(handle));
    }
 
    //4. autoCenter()
    //   auto-center on
    //   relayOS([0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00])
    memset(buf,0x00,sizeof(buf));
    buf[0] = 0x14;
    buf[1] = 0x00;
    buf[2] = 0x00;
    buf[3] = 0x00;
    buf[4] = 0x00;
    buf[5] = 0x00;
    buf[6] = 0x00;
    res = hid_write(handle, buf,7);
    if (res < 0) {
        printf("Unable to write()\n");
        printf("Error: %ls\n", hid_error(handle));
    }

    //
    // custom auto-center setting
    //
    memset(buf,0x00,sizeof(buf));
    buf[0] = 0xfe;
    buf[1] = 0x0d;
    buf[2] = round(0.4*15);// byte 3-4 is effect strength of auto-centring, 0x00 to 0x0f
    buf[3] = round(0.4*15);//
    buf[4] = round(0.3*255);// byte 5 is the rate the effect strength rises as the wheel turns,
                            // 0x00 to 0xff
    buf[5] = 0x00;
    buf[6] = 0x00;
    res = hid_write(handle, buf,7);
    if (res < 0) {
        printf("Unable to write()\n");
        printf("Error: %ls\n", hid_error(handle));
    }

    // friction present when turning the wheel
    // the first "number" is for left rotation, the second for right rotation
    // 0x00 through 0x07 range,
    // 0x07 is the strongest friction and then 0x08 is no friction
    // relayOS([0x21, 0x02, number, 0x00, number, 0x00, 0x00])
    memset(buf,0x00,sizeof(buf));
    buf[0] = 0x21;
    buf[1] = 0x02;
    buf[2] = 0x02; //friction num, left
    buf[3] = 0x00;
    buf[4] = 0x02; //friction num, right
    buf[5] = 0x00;
    buf[6] = 0x00;
    res = hid_write(handle, buf,7);
    if (res < 0) {
        printf("Unable to write()\n");
        printf("Error: %ls\n", hid_error(handle));
    }

  
    sleep(1); // delay, waiting for video loading

    
    for(int i=0;i<1200;i++) { //TBC, loop count
        if ( (direction > 1) || (direction < -1) ) {
            unsigned char dir=0;

            if (direction > 1)
                dir = 0xff; // left turn 
            else
                dir = 0x00; // right turn

            // force
            // relayOS([0x11, 0x00, number, 0x00, 0x00, 0x00, 0x00])
            memset(buf,0x00,sizeof(buf));
            buf[0] = 0x11;
            buf[1] = 0x00;
            buf[2] = dir;
            buf[3] = 0x00;
            buf[4] = 0x00;
            buf[5] = 0x00;
            buf[6] = 0x00;
            
            res = hid_write(handle, buf,7);
            if (res < 0) {
                printf("Unable to write()\n");
                printf("Error: %ls\n", hid_error(handle));
            }
            
         }else{
            // forceOff(1)
            // => (centering)
            memset(buf,0x00,sizeof(buf));
            buf[0] = 0x10;
            buf[1] = 0x00;
            buf[2] = 0x00;
            buf[3] = 0x00;
            buf[4] = 0x00;
            buf[5] = 0x00;
            buf[6] = 0x00;
            res = hid_write(handle, buf,7);
            if (res < 0) {
                printf("Unable to write()\n");
                printf("Error: %ls\n", hid_error(handle));
            }
         }

         usleep(75000);// sampling rate( about 13 FPS )
    }
    
    hid_close(handle);
    /* Free static HIDAPI objects. */
    hid_exit();
EXIT:          
    pthread_exit(NULL);
}


