# Nucleo-bare-metal
[WIP] my attempts to develop on my stm32 nuclo board
## Building
1. Install [gnu-arm-none-eabi](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads) toolchain
2. Clone the repo
```
git clone "https://github.com/ayabusa/Nucleo-bare-metal.git"
cd Nucleo-bare-metal
```
3. Build the project (located in build/main.elf)
```
make all
```
## Running/Debuging
```shell
st-util                                 # Download at https://github.com/stlink-org/stlink, it launches the gdb server, port 4242
gdb-multiarch main.elf                  # launch the gdb instance
(gdb) target extended-remote :4242      # connect to the st-util server
(gdb) load                              # load our binary
(gdb) continue                          # run it
```
## Licence 
```
All Rights Reserved

Copyright (c) 2024 ayabusa

Created by ayabusa

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
```
