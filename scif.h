/** \mainpage Driver Overview
  *
  * \section section_drv_info Driver Information
  * This Sensor Controller Interface driver has been generated by the Texas Instruments Sensor Controller
  * Studio tool:
  * - <b>Project name</b>:     Accelerometer Project
  * - <b>Project file</b>:     C:/Users/Ashwin Rohit/Documents/sensor_controller_projects/sc_accelerometer/accelerometer.scp
  * - <b>Code prefix</b>:      -
  * - <b>Operating system</b>: TI-RTOS
  * - <b>Tool version</b>:     2.9.0.208
  * - <b>Tool patches</b>:     None
  * - <b>Target chip</b>:      CC2650, package QFN48 7x7 RGZ, revision -
  * - <b>Created</b>:          2024-02-26 23:43:58.302
  * - <b>Computer</b>:         SV
  * - <b>User</b>:             Ashwin Rohit
  *
  * No user-provided resource definitions were used to generate this driver.
  *
  * No user-provided procedure definitions were used to generate this driver.
  *
  * Do not edit the generated source code files other than temporarily for debug purposes. Any
  * modifications will be overwritten by the Sensor Controller Studio when generating new output.
  *
  * \section section_drv_modules Driver Modules
  * The driver is divided into three modules:
  * - \ref module_scif_generic_interface, providing the API for:
  *     - Initializing and uninitializing the driver
  *     - Task control (for starting, stopping and executing Sensor Controller tasks)
  *     - Task data exchange (for producing input data to and consume output data from Sensor Controller
  *       tasks)
  * - \ref module_scif_driver_setup, containing:
  *     - The AUX RAM image (Sensor Controller code and data)
  *     - I/O mapping information
  *     - Task data structure information
  *     - Driver setup data, to be used in the driver initialization
  *     - Project-specific functionality
  * - \ref module_scif_osal, for flexible OS support:
  *     - Interfaces with the selected operating system
  *
  * It is possible to use output from multiple Sensor Controller Studio projects in one application. Only
  * one driver setup may be active at a time, but it is possible to switch between these setups. When
  * using this option, there is one instance of the \ref module_scif_generic_interface and
  * \ref module_scif_osal modules, and multiple instances of the \ref module_scif_driver_setup module.
  * This requires that:
  * - The outputs must be generated using the same version of Sensor Controller Studio
  * - The outputs must use the same operating system
  * - The outputs must use different source code prefixes (inserted into all globals of the
  *   \ref module_scif_driver_setup)
  *
  *
  * \section section_project_info Project Description
  * No description entered
  *
  *
  * \subsection section_io_mapping I/O Mapping
  * Task I/O functions are mapped to the following pins:
  * - Read Accelerometer Values Task:
  *     - <b>XS: Enables the Haptic Actuator</b>: DIO25
  *     - <b>I2C SCL</b>: DIO4
  *     - <b>I2C SDA</b>: DIO5
  *
  *
  * \section section_task_info Task Description(s)
  * This driver supports the following task(s):
  *
  *
  * \subsection section_task_desc_read_accelerometer_values_task Read Accelerometer Values Task
  * Read the accelerometer values
  *
  */




/** \addtogroup module_scif_driver_setup Driver Setup
  *
  * \section section_driver_setup_overview Overview
  *
  * This driver setup instance has been generated for:
  * - <b>Project name</b>:     Accelerometer Project
  * - <b>Code prefix</b>:      -
  *
  * The driver setup module contains the generated output from the Sensor Controller Studio project:
  * - Location of task control and scheduling data structures in AUX RAM
  * - The AUX RAM image, and the size the image
  * - Task data structure information (location, size and buffer count)
  * - I/O pin mapping translation table
  * - Task resource initialization and uninitialization functions
  * - Hooks for run-time logging
  *
  * @{
  */
#ifndef SCIF_H
#define SCIF_H

#include <stdint.h>
#include <stdbool.h>
#include "scif_framework.h"
#include "scif_osal_tirtos.h"


/// Target chip name
#define SCIF_TARGET_CHIP_NAME_CC2650
/// Target chip package
#define SCIF_TARGET_CHIP_PACKAGE_QFN48_7X7_RGZ

/// Number of tasks implemented by this driver
#define SCIF_TASK_COUNT 1

/// Read Accelerometer Values Task: Task ID
#define SCIF_READ_ACCELEROMETER_VALUES_TASK_TASK_ID 0


/// Read Accelerometer Values Task: 
#define SCIF_READ_ACCELEROMETER_VALUES_TASK_HAPTIC_THRESHOLD 10000
/// Read Accelerometer Values Task: MPU Buffer Address for I2C
#define SCIF_READ_ACCELEROMETER_VALUES_TASK_MPU_ADDR 104
/// Read Accelerometer Values Task: 
#define SCIF_READ_ACCELEROMETER_VALUES_TASK_MPU_GYRO_CONFIG 27
/// Read Accelerometer Values Task: 
#define SCIF_READ_ACCELEROMETER_VALUES_TASK_MPU_GYRO_XOUT 59
/// Read Accelerometer Values Task: 
#define SCIF_READ_ACCELEROMETER_VALUES_TASK_MPU_GYRO_YOUT 61
/// Read Accelerometer Values Task: 
#define SCIF_READ_ACCELEROMETER_VALUES_TASK_MPU_PWR_MGMT 107
/// Read Accelerometer Values Task: 
#define SCIF_READ_ACCELEROMETER_VALUES_TASK_MPU_WHOAMI 117
/// Read Accelerometer Values Task I/O mapping: Enables the Haptic Actuator
#define SCIF_READ_ACCELEROMETER_VALUES_TASK_DIO_XS_EN_HAPTIC 25
/// Read Accelerometer Values Task I/O mapping: I2C SCL
#define SCIF_READ_ACCELEROMETER_VALUES_TASK_DIO_I2C_SCL 4
/// Read Accelerometer Values Task I/O mapping: I2C SDA
#define SCIF_READ_ACCELEROMETER_VALUES_TASK_DIO_I2C_SDA 5


// All shared data structures in AUX RAM need to be packed
#pragma pack(push, 2)


/// Read Accelerometer Values Task: Task output data structure
typedef struct {
    int16_t  gyroX; ///< 
    int16_t  gyroY; ///< 
} SCIF_READ_ACCELEROMETER_VALUES_TASK_OUTPUT_T;


/// Read Accelerometer Values Task: Task state structure
typedef struct {
    uint16_t gyroStatus; ///< 
    uint16_t i2cStatus;  ///< I2C master status
} SCIF_READ_ACCELEROMETER_VALUES_TASK_STATE_T;


/// Sensor Controller task data (configuration, input buffer(s), output buffer(s) and internal state)
typedef struct {
    struct {
        SCIF_READ_ACCELEROMETER_VALUES_TASK_OUTPUT_T output;
        SCIF_READ_ACCELEROMETER_VALUES_TASK_STATE_T state;
    } readAccelerometerValuesTask;
} SCIF_TASK_DATA_T;

/// Sensor Controller task generic control (located in AUX RAM)
#define scifTaskData    (*((volatile SCIF_TASK_DATA_T*) 0x400E00EA))


// Initialized internal driver data, to be used in the call to \ref scifInit()
extern const SCIF_DATA_T scifDriverSetup;


// Restore previous struct packing setting
#pragma pack(pop)


// AUX I/O re-initialization functions
void scifReinitTaskIo(uint32_t bvTaskIds);


// No task-specific API available


#endif
//@}


// Generated by SV at 2024-02-26 23:43:58.302
