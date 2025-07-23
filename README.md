# IW3-sdk
A SDK containing many of the data structures used by Call of Duty 4: Modern Warfare (COD4), as well as some convenience functions.

# Usage
Before using any of the SDKs functions, you must call ```IW3_Init()```, this function is located in ```iw3_init.c``` and all pointers should be updated to point to the correct addresses. I plan to add pattern scanning in the future.

# TODO
- Improve flexability by adding pattern scanning.
- Add some way to modify the way the game renders entities. (this can be achieved by hooking ```R_AddDObjToScene``` in COD6+, however I am not even sure that function exists in COD4.)
- Add weapon definitions and functions.

# Why C?
Since about 90% of the engine was written in C, I would prefer to stick with C, though it doesnt really matter as it is just personal preference. (Psst, you can use the C++ branch)
