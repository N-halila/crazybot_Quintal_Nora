/*
 * File:          crazybot_Quintal_Nora.c
 * Date:
 * Description:
 * Author:
 * Modifications:
 */

/*
 * You may need to add include files like <webots/distance_sensor.h> or
 * <webots/differential_wheels.h>, etc.
 */
#include <webots/robot.h>
#include <webots/motor.h>
#include <webots/keyboard.h>
#include <webots/distance_sensor.h>
#include <webots/position_sensor.h>

#include <stdio.h>
/*
 * You may want to add macros here.
 */
#define TIME_STEP 64
#define pi 3.1416

/*
 * This is the main program.
 * The arguments of the main function can be specified by the
 * "controllerArgs" field of the Robot node
 */
int main(int argc, char **argv)
{
  int  key_letter;
  /* necessary to initialize webots stuff */
  wb_robot_init();
  wb_keyboard_enable(TIME_STEP);
  double lin_vel;
  double dis_sen;
  double ps_der;
  double ps_izq;
  double vel;
  double rpm;
  double radio=0.075;  /*
   * You should declare here WbDeviceTag variables for storing
   * robot devices like this:
   *  WbDeviceTag my_sensor = wb_robot_get_device("my_sensor");
   *  WbDeviceTag my_actuator = wb_robot_get_device("my_actuator");
   */
   //llantas
  WbDeviceTag wheel_right = wb_robot_get_device("motor_right");
  WbDeviceTag wheel_left = wb_robot_get_device("motor_left");
 
  WbDeviceTag ds = wb_robot_get_device("ds");
  wb_distance_sensor_enable(ds,TIME_STEP);  
  
  //this is the position sensor device, darle nombre a la variable
  WbDeviceTag ps_r = wb_robot_get_device("ps_right");
  WbDeviceTag ps_l = wb_robot_get_device("ps_left");
  //habilitar el sensor
  wb_position_sensor_enable(ps_r, TIME_STEP);
  wb_position_sensor_enable(ps_l, TIME_STEP);
  
  
  
  
   wb_motor_set_position(wheel_right, INFINITY);   
   wb_motor_set_position(wheel_left, INFINITY);
  /* main loop
   * Perform simulation steps of TIME_STEP milliseconds
   * and leave the loop when the simulation is over
   */
  while (wb_robot_step(TIME_STEP) != -1) {
      key_letter = wb_keyboard_get_key(); 
      
      /*
     * Read the sensors :
     * Enter here functions to read sensor data, like:
     *  double val = wb_distance_sensor_get_value(my_sensor);
     */

    /* Process sensor data here */

    /*
     * Enter here functions to send actuator commands, like:
     * wb_differential_wheels_set_speed(100.0,100.0);
     */
     
     if (key_letter== WB_KEYBOARD_RIGHT){
     vel = 26.6666666666666668;
     wb_motor_set_velocity(wheel_right, -vel);   
     wb_motor_set_velocity(wheel_left, vel);
     rpm= (vel* (2*pi))/60;
     lin_vel= (((2*pi)*radio)/60)*rpm;
     printf("the linear velocity is %lf\n", lin_vel);
     printf("the revolution per minute are %lf\n", rpm);
     }
     
     else if (key_letter== WB_KEYBOARD_LEFT){
     vel = 26.66666666666666668;
     wb_motor_set_velocity(wheel_right, 26.666666666666668);   
     wb_motor_set_velocity(wheel_left, -26.666666666666668);
     rpm= (vel* (2*pi))/60;
     lin_vel= (((2*pi)*radio)/60)*rpm;
     printf("the linear velocity is %lf\n", lin_vel);
     printf("the revolution per minute are %lf\n", rpm);
     }
     
     else if (key_letter== WB_KEYBOARD_UP){
     vel = 40;
     wb_motor_set_velocity(wheel_right, vel);   
     wb_motor_set_velocity(wheel_left, vel);    
     rpm= (vel* (2*pi))/60;
     lin_vel= (((2*pi)*radio)/60)*rpm;
     printf("the linear velocity is %lf\n", lin_vel);
     printf("the revolution per minute are %lf\n", rpm);
    
     
     
     }
     
      else if (key_letter== WB_KEYBOARD_DOWN){
      vel= 1.3333333333333335;
     wb_motor_set_velocity(wheel_right, -vel);   
     wb_motor_set_velocity(wheel_left, -vel);
     
     rpm= (vel* (2*pi))/60;
     lin_vel= (((2*pi)*radio)/60)*rpm;
     printf("the linear velocity is %lf\n", lin_vel);
     printf("the revolution per minute are %lf\n", rpm);
     }
     
     else {
     wb_motor_set_velocity(wheel_right, 0);   
     wb_motor_set_velocity(wheel_left, 0);
   
   
     }
     
     
     
     
     
     
     
     
     
     
  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  
  
  wb_robot_cleanup();

  return 0;
}
