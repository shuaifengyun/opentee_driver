# opentee_driver
This is a secure driver demo, you can follow below operation step by step to integrate this module into OP-TEE
Which have checked in optee+qemu running enviroment

1. cp my_test_common_3.0.0.patch and my_test_qemu_3.0.0.patch to path of "build", and copy 0001-Integrate-secure-driver-test-into-op-tee.patch into patch of optee_os

2. change path to build, and use below command to apply test TA$CA
    git apply my_test_common_3.0.0.patch
    git apply my_test_qemu_3.0.0.patch

3. change path to optee_os, and use below command to apply patch
   git am 0001-Integrate-secure-driver-test-into-op-tee.patch

4. cp opentee_driver/my_test to root path 

5. chang path to build, then use below command to build project
    make -f qemu.mk all

6. use below command to run op-tee and qemu
    make -f qemu.mk run-only

Test demo:
Write data into driver by using below command ：
    my_test writeDev [offset] [len]
       offset：offset of position。
       len: length of data which need to be wrote into driver。
    example:
       my_test writeDev 0 64

Read data from driver by using below command ：
    my_test readDev [offset] [len]
       offset：offset of position。
       len: length of data which need to be read from driver。
    example:
       my_test readDev 0 64

Dump all data in driver:
   my_test dumpDev [len]
   len: length of data which need to be dumped from driver。
    example:
       my_test dumpDev 32
