# HW1


// negative command line argument
[cssuwbstudent@LinuxMachine HW1]$ ./a.out -1
Invalid command line argument.

// command line argument is 0
[cssuwbstudent@LinuxMachine HW1]$ ./a.out 0
Please input 9 digits to be randomly shuffled: 123456789

Done.

// command line argument is 2
[cssuwbstudent@LinuxMachine HW1]$ ./a.out 2
Please input 9 digits to be randomly shuffled: 123456789

+-------+
| 3 9 2 |
| 7 6 1 |
| 4 5 8 |
+-------+
+-------+
| 2 3 7 |
| 4 1 5 |
| 9 6 8 |
+-------+
Done.

//command line argument over 9
[cssuwbstudent@LinuxMachine HW1]$ ./a.out 10
Invalid number. Please enter a number less than 10

//command line argument that is not a number
[cssuwbstudent@LinuxMachine HW1]$ ./a.out c
Invalid command line argument.

//command line argument that is a number but has other characters
[cssuwbstudent@LinuxMachine HW1]$ ./a.out 2c
Invalid command line argument.

//showing different user inputs and their errors
[cssuwbstudent@LinuxMachine HW1]$ ./a.out 2
Please input 9 digits to be randomly shuffled: c12345678

Please input 9 digits to be randomly shuffled: 12345

Invalid number. Please input 9 digits to be randomly shuffled: 1234567890

Invalid number. Please input 9 digits to be randomly shuffled: 123456789

+-------+
| 3 8 6 |
| 5 7 4 |
| 1 2 9 |
+-------+
+-------+
| 3 5 1 |
| 2 9 4 |
| 8 6 7 |
+-------+
Done.