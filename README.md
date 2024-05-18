# STM32-GPS-Neo6M
Get GPS location with U-blox module Neo-6M, interfacing with STM32.
Package : F103C8T6.
Software: CubeIDE : Code for stm32.
          u-blox : Config neo6m.
Hardware: STM32F103C8T6.
          Neo-6M.
          USB-TTL.
1. Download u-blox and config Neo6m to chose which gps message you want to received from satellite.
2. Add .h and .c library file to your project.
3. If you using other UART Pin, change it in file.
4. Change gps.buffer size. It might need bigger size than i define.
5. Run project.
6. Remember, module neo-6m may not get gps signal while you in house.
Hope you enjoy it :))
