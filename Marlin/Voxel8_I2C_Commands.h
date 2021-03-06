/**
 * Voxel8_I2C_Commands.ch - Cartridge Holder / Cartridge I2C Commands.
 * Author: Dan Thompson (danthompson41@gmail.com)
 * Date: 3/9/2016
 * Used to hold the I2C Commands Marlin can send to Voxel8's Cartridges and
 * Cartridge Holder.
 * Copyright (C) 2016 Voxel8
 */

#ifndef MARLIN_VOXEL8_I2C_COMMANDS_H_
#define MARLIN_VOXEL8_I2C_COMMANDS_H_

//===========================================================================
//=============================== Definitions ===============================
//===========================================================================

/* Cartridge and Cartridge Holder Settings/Commands */
// I2C Addresses
#define CART_HOLDER_ADDR        0x2F                  // Cartridge Holder
#define CART_PREFIX_ADDR        0x24
#define CART0_ADDR              CART_PREFIX_ADDR + 0  // Left Cartridge
#define CART1_ADDR              CART_PREFIX_ADDR + 1  // Right Cartridge

// Definitions for unused arguments for various commands
#define I2C_EMPTY_ADDRESS       0xFF
#define I2C_EMPTY_DATA          0xFF

// I2C Commands
#define SET_FAN_DRIVE_PWM       0x01
#define RESERVED_CMD_02         0x02
#define SET_LED_WHITE_PWM       0x03
#define SET_LED_RED_PWM         0x04
#define SET_LED_UV_PWM          0x05

#define EEPROM_WRITE            0x06
#define EEPROM_READ             0x07
#define EEPROM_READ_SERIAL      0x08
#define EEPROM_READ_SIZE        0x09
#define EEPROM_READ_MTRL        0x10
#define EEPROM_READ_TYPE        0x11
#define EEPROM_READ_PRGMR       0x12
#define EEPROM_READ_ERR         0x13
#define EEPROM_READ_FRMWRE      0x14

#define CLEAR_ERROR             0x15

#define EEPROM_READ_TEMP        0x16

#define GET_GPIO_V_SENSE        0x20
#define GET_GPIO_SWITCH         0x21

//===========================================================================
//============================= Public Functions ============================
//===========================================================================
/**
 * Sends a general I2C Command.
 * @param I2C_target_address  Address of the target (cartridge or
 *                                cartridge holder)
 * @param command             The command being sent
 * @param address             The EEPROM address, if applicable
 * @param data                The data used for the command
 */
void I2C__GeneralCommand(uint8_t I2C_target_address, uint8_t command,
                         uint8_t address, uint8_t data);

/**
 * Sets the speed of the fan on the cartrdge holder.
 * @param fanspeed            Speed the fan is set to
 */
void I2C__SetFanDrive0PWM(uint8_t fanSpeed);

/**
 * Turns off the fan on the cartridge holder.
 */
void I2C__SetFanOff(void);

/**
 * Toggles the UV LED
 * @param data                0 to disable, enabled on call otherwise
 */
void I2C__ToggleUV(uint8_t data);

/**
 * Writes data to a specific EEPROM address on a I2C_target_address
 * @param I2C_target_address  Address of the target (cartridge or holder)
 * @param address             The EEPROM address being written to
 * @param data                The data being written
 */
void I2C__EEPROMWrite(uint8_t I2C_target_address, uint8_t eeprom_address, uint8_t data);

/**
 * Reads data from a specific EEPROM address on a I2C_target_address
 * @param I2C_target_address  Address of the target (cartridge or holder)
 * @param address             The EEPROM address being written to
 */
void I2C__EEPROMRead(uint8_t I2C_target_address, uint8_t address);

/**
 * Read the serial number from a I2C_target_address and print it on the serial port
 * @param I2C_target_address  Address of the target (cartridge or holder)
 */
void I2C__GetSerial(uint8_t I2C_target_address);

/**
 * Read the number of the programmer used on a cartridge and print it on
 * the serial port
 * @param I2C_target_address           Address of the target (cartridge)
 */
void I2C__GetProgrammerStation(uint8_t I2C_target_address);

/**
 * Read the variety of peripheral and print it on the serial port
 * @param I2C_target_address           Address of the target (cartridge or holder)
 */
void I2C__GetPeripheralType(uint8_t I2C_target_address);

/**
 * Read the size of the nozzle from cartridge and print it on the serial port
 * @param I2C_target_address           Address of the target (cartridge)
 */ 
void I2C__GetSize(uint8_t I2C_target_address);

/**
 * Read the material contained by a cartridge and print it on the serial port
 * @param I2C_target_address           Address of the target (cartridge)
 */
void I2C__GetMaterial(uint8_t I2C_target_address);

/**
 * Read the error code of an I2C_target_address and print it on the serial port
 * @param I2C_target_address     Address of the target (cartridge or holder)
 */
void I2C__GetErrorCode(uint8_t I2C_target_address);

/**
 * Read the firmware version by a I2C_target_address and print it on the serial port
 * @param I2C_target_address     Address of the target (cartridge or holder)
 */
void I2C__GetFirmwareVersion(uint8_t I2C_target_address);

/**
 * Read the voltage sense pin on a cartridge and print it on the serial port.
 * On the pneumatics cartridge, this should correspond to the solenoid being 
 * active. For FFF, this represents if the hot end is active.
 * @param I2C_target_address           Address of the target (cartridge)
 */
void I2C__GetVoltageSense(uint8_t I2C_target_address);

/**
 * Read the SYRINGE_ACTIVE pin on a pneumatics cartridge and print it on the
 * serial port. This should be a 1 when the syringe is deployed, and a 0 when
 * it's retracted. 
 * @param I2C_target_address           Address of the target (pneumatic cartridge)
 */
void I2C__GetGpioSwitch(uint8_t I2C_target_address);

/**
 * Clear the error flag for a particular I2C_target_address if it's set
 * @param I2C_target_address           Address of the target (I2C_target_address)
 */
void I2C__ClearError(uint8_t I2C_target_address);

#endif  // MARLIN_VOXEL8_I2C_COMMANDS_H_
