# Zeta (name that might change)
This is a bare metal os attempt on the numworks n0110

![image](/assets/image_post_numworks.jpg)

## Build
1. Download the arm-none-eabi toolchain
2. run ```make clean && make```
3. the output file is located in build/main.bin
4. you can flash it to slot B using the Web DFU from TI Planet, or by using the command ```make flash``` (unstable)
5. That's it !

## TODO/roadmap
### Zeta bare minimum
- [x] Working thing
- [x] Led interface
- [x] Keyboard interface
- [x] Set clock and all
    - [x] adapt ms_wait() and us_wait()
- [ ] Screen interface
- [ ] UI toolkit
    - [ ] set pixel
    - [ ] text display
    - [ ] fill rect
    - [ ] image display

## Support Me!
If you can and want, you can buy me a coffee :D
[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/S6S6V7DYK)