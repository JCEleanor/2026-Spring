    .data
NA: .asciz "na "
BATMAN: .asciz "Batman!\n"
    .text
main:

#  for (int i=0; i<8 ; i++)
#    printf("na ");
#  printf("Batman!\n");
    addi t0, zero, 0  # i = 0
for_na:
    # print na
    addi a7, zero, 4
    la a0, NA
    ecall
    
    addi t0, t0, 1   # i++
    slti t1, t0, 8   # t1 = i < 8
    bne t1, zero, for_na # if (i<8) goto for_na
    
    # exited for loop
    #print Batman!
    addi a7, zero, 4
    la a0, BATMAN
    ecall
    
    # exit cleanly
    addi a7, zero, 10
    ecall 
