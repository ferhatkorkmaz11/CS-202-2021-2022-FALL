1-) Compile the program using the command "g++ -o hw2 *.cpp"
2-) To run the program on Windows terminal type "hw2 INPUT_FILE_NAME.txt n". Here n stands for the n-gram's value.
3-) To run the program on Linux terminal type "./hw2 INPUT_FILE_NAME.txt n". Here n stands for the n-gram's value.
4-) If you want to check the possible memory leaks in the program, you can execute this command "valgrind ./hw2 INPUT_FILE_NAME.txt n". Here n stands for the n-gram's value.

In the program, INPUT_FILE_NAME.txt will be stored at "argv[1]" and n will be stored at "argv[2]". 
In order to convert the string value of n to integer, you can use atoi(string str) function, which is included in the standart library.
** Note That option 4 is only available in Linux and it requires the tool installed on your machine. **
