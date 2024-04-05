# Zeta (name that might change)
This is a bare metal os attempt on the numworks n0110

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
- [ ] Set clock and all
    - [ ] adapt ms_wait() and us_wait()
- [ ] Screen interface
- [ ] UI toolkit
    - [ ] text display
    - [ ] fill rect
    - [ ] image display