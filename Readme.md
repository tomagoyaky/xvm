XVM
==========
A stack virtual machine written in pure C.

## Specification
1. Data Types Supported  
Currently, the only data type supported is the 64-bit signed integer, or 
"xvm_int".

2. Instructions  
    * `push <value>`  
    Push <value> (an xvm_int) onto the stack.
    * `load <register>`  
    Load the value in <register> on the stack.
    * `pop`  
    Pop the value at the top of the stack.
    * `sav <register>`  
    Pop the value at the top of the stack and save it to <register>.
    * `add`  
    Pop two values from the stack, add them, and push the result back onto 
    the stack.
    * `sub`  
    Pop two values from the stack, subtract the second from the first, and 
    push the result back onto the stack.
    * `mult`  
    Pop two values from the stack, multiply them, and push the result back 
    onto the stack.
    * `div`  
    Pop two values from the stack, divide the first by the second, and 
    push the result back onto the stack.
    * `ifgt <label>`  
    Pop two values from the stack. If the first value is greater than the 
    second value, jump to <label>.
    * `ifeq <label>`  
    Pop two values from the stack. If the first value is equal to the 
    second value, jump to <label>.
    * `iflt <label>`  
    Pop two values from the stack. If the first value is less than the 
    second value, jump to <label>.
    * `jmp <label>`  
    Unconditionally jump to <label>.
    * `prt`  
    Pop the value at the top of the stack and print it to standard output.  
    * `read`
    Read a value from standard input and push it on the stack.  
    * `halt`  
    Halt the execution of the program.

3. Registers  
    * r1, r2, r3, r4, r5  
    For use, such as loading onto stack or saving from stack. 
    * pc  
    The program counter. You should (normally) not access this register.

4. Errors  
All errors result in the program to print the error and exit with a nonzero 
exit state immediately.  
    * Stack Overflow (ERROVR)  
    The stack is nomally limited to 65,536 (2^16) bytes (64MB), or 1,024 
    xvm_int's. Attempting to store more values will cause a stack overflow 
    error to be raised.  
    * Invalid Jump (ERRJMP)  
    The instructions `ifgt`, `ifeq`, `iflt` and `jmp` might jump to invalid 
    addresses. If such a jump is attempted, this error will be raised.  
    * Stack Underflow (ERRUND)  
    If the current instruction will cause a pop from an empty stack, this 
    error will be raised.  

5. Future  
After all work to implement the current specification, support for user-
defined functions will be added. A second data type, the 8-bit unsigned 
integer, or "xvm_char", will also be added.


## License
XVM is licensed under the Mozilla Public License. Please refer to the "License" 
file for details.