#ifndef MPU6050_H
#define MPU6050_H

void MPU6050_Init(); 
uint16_t MPU6050_AcelX();
uint16_t MPU6050_AcelY();
uint16_t MPU6050_AcelZ();
uint16_t MPU6050_GiroX();
uint16_t MPU6050_GiroY();
uint16_t MPU6050_GiroZ();
uint16_t MPU6050_Temp();

#endif 
