# make_course

This course has 5 modules as folders:

### MOD-1:
this is for Binary files
____
### MOD-2:
this is for Dynamic Libraries (.so)
A good practice is to put the header files of shared libs into a separate folder so it may be accessible to multile other source files to use.
___
### MOD-3:
this is for Binraies that uses Dynamic Libraries (.so)
In this case, the test_build folder works as MOD-3. as it uses the shared lib
___
### MOD-4
this is for Static Libraries (.a)
___
### MOD-5
this is for final binaries (bins that can use static and shared (dynamic) libraries)

