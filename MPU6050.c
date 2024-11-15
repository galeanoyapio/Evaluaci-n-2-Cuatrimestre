#include "MKL25Z4.h"
#include "I2C.h"
#include "MPU6050.h"


#define SLAVE_ADDRESS 0b1101000


#define REG_ACCEX_H 0x3B
#define REG_ACCEY_H 0x3D
#define REG_ACCEZ_H 0x3F

#define REG_GYROX_H 0x43
#define REG_GYROY_H 0x45
#define REG_GYROZ_H 0x47


#define REG_ACCEX_L 0x3C
#define REG_ACCEY_L 0x3E
#define REG_ACCEZ_L 0x40

#define REG_GYROX_L 0x44
#define REG_GYROY_L 0x46
#define REG_GYROZ_L 0x48


#define REG_TEMP_H  0x41
#define REG_TEMP_L  0x42

#define REG_RESET 0x68
#define RESET_ALL 0b00000111 

#define LED_X 2
#define LED_Y 5
#define LED_Z 6



void MPU6050_Init(){
    I2C0_Init(); //Aqui se inicializan los puertos necesarios, como el puerto A para los LEDs
    I2C_Start();

    PORTA->PCR[LED_X] = PORT_PCR_MUX(2); //GPIO
    PORTA->PCR[LED_Y] = PORT_PCR_MUX(2);
    PORTA->PCR[LED_Z] = PORT_PCR_MUX(2);
    
    //OUTPUT LEDS
    
    PTA->PDDR|=(1<<LED_X); 
    PTA->PDDR|=(1<<LED_Y); 
    PTA->PDDR|=(1<<LED_Z); 

    PTA->PSOR&=~(1<<3); //Resetea los LEDs
    PTA->PSOR&=~(1<<5);
    PTA->PSOR&=~(1<<6);

    I2C_WriteRegister(SLAVE_ADDRESS, REG_RESET, RESET_ALL);
    
    }

uint16_t MPU6050_AcelX(uint16_t accex){
    uint16_t parteAlta = I2C_ReadRegister(SLAVE_ADDRESS, REG_ACCEX_H);
    uint16_t parteBaja = I2C_ReadRegister(SLAVE_ADDRESS, REG_ACCEX_L);
    accex = (parteAlta<<8) | parteBaja;
    return accex;
}

uint16_t MPU6050_AcelY(uint16_t accey){
    uint16_t parteAlta = I2C_ReadRegister(SLAVE_ADDRESS, REG_ACCEY_H);
    uint16_t parteBaja = I2C_ReadRegister(SLAVE_ADDRESS, REG_ACCEY_L);
    accey = (parteAlta<<8) | parteBaja;
    return accey;
}

uint16_t MPU6050_AcelZ(uint16_t accez){ 
    uint16_t parteAlta = I2C_ReadRegister(SLAVE_ADDRESS, REG_ACCEZ_H);
    uint16_t parteBaja = I2C_ReadRegister(SLAVE_ADDRESS, REG_ACCEZ_L);
    accez = (parteAlta<<8) | parteBaja;
    return accez;
}

uint16_t MPU6050_GiroX(uint16_t gyrox){
    uint16_t parteAlta = I2C_ReadRegister(SLAVE_ADDRESS, REG_GYROX_H);
    uint16_t parteBaja = I2C_ReadRegister(SLAVE_ADDRESS, REG_GYROX_L);
    gyrox = (parteAlta<<8) | parteBaja;
    return gyrox;
}

uint16_t MPU6050_GiroY(uint16_t gyroy){
    uint16_t parteAlta = I2C_ReadRegister(SLAVE_ADDRESS, REG_GYROY_H);
    uint16_t parteBaja = I2C_ReadRegister(SLAVE_ADDRESS, REG_GYROY_L);
    gyroy = (parteAlta<<8) | parteBaja;
    return gyroy;
}

uint16_t MPU6050_GiroZ(uint16_t gyroz){
    uint16_t parteAlta = I2C_ReadRegister(SLAVE_ADDRESS, REG_GYROZ_H);
    uint16_t parteBaja = I2C_ReadRegister(SLAVE_ADDRESS, REG_GYROZ_L);
    gyroz = (parteAlta<<8) | parteBaja;
    return gyroz;
}

uint16_t MPU6050_Temp(uint16_t temp){
    uint16_t parteAlta = I2C_ReadRegister(SLAVE_ADDRESS, REG_TEMP_H);
    uint16_t parteBaja = I2C_ReadRegister(SLAVE_ADDRESS, REG_TEMP_L);
    temp = (parteAlta<<8) | parteBaja;
    return temp;
}