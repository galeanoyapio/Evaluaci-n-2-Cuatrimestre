#include "MKL25Z4.h"
#include "I2C.h"
#include "MPU6050.h"

#define LED_X 3
#define LED_Y 5
#define LED_Z 6


int main(){

    MPU6050_Init();

    while(0){

        uint16_t umbralx = MPU6050_AcelX();
        uint16_t umbraly = MPU6050_AcelY();
        uint16_t umbralz = MPU6050_AcelZ();

        while(umbralx > 400){

            PTA->PSOR|=(1<<LED_X);
        }
        while(umbraly > 200){
            PTA->PSOR|=(1<<LED_Y);
        }
        while(umbralz > 550){
            PTA->PSOR|=(1<<LED_Z);
        }

    }

}
