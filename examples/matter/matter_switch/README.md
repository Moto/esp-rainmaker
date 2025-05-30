# Matter + Rainmaker Switch Example

## What to expect in this example?

- This demonstrates a Matter + RainMaker Switch. Matter is used for commissioning (also known as Wi-Fi provisioning) and local control, whereas RainMaker is used for remote control and OTA upgrades.
- This example uses the BOOT button and RGB LED on the ESP32-C3-DevKitC board to demonstrate a switch.
- To commission the device, scan the QR Code generated by the mfg_tool script using ESP RainMaker app.
- Pressing the BOOT button will send a toggle the power state of switch and send an on/off command to the remote device. This will also reflect on the phone app.
- Toggling the button on the phone app should toggle the LED on your board.
- To test remote control, change the network connection of the mobile.

> Please refer to the [README in the parent folder](../README.md) for instructions.

#### Optimization

TO optimize the DRAM usage, this example uses the following optimizations:

- Disables the chip shell, `CONFIG_ENABLE_CHIP_SHELL=n`, it adds approx 10KB or RAM.
- As this example has two endpoints (Endpoint 0: Root endpoint, Endpoint 1: Extended Color Light), the default dynamic endpoint count is set to 2. This is done by setting `CONFIG_ESP_MATTER_MAX_ENDPOINT_COUNT=2` in the menuconfig.

For more optimizations please refer [esp-matter’s RAM Flash optimization guide](https://docs.espressif.com/projects/esp-matter/en/latest/esp32/optimizations.html)
