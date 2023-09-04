ONOYIMA BONIFACE

. Tread lightly, she is near
mandatory

Write a function that reads a text file and prints it to the POSIX standard output.

 

1. Under the snow
mandatory

Create a function that creates a file.

   

2. Speak gently, she can hear
mandatory

Write a function that appends text at the end of a file.

  


3. cp
mandatory

Write a program that copies the content of a file to another file.

    Usage: cp file_from file_to
    if the number of argument is not the correct one, exit with code 97 and print Usage: cp file_from file_to, followed by a new line, on the POSIX standard error
    if file_to already exists, truncate it
    if file_from does not exist, or if you can not read it, exit with code 98 and print Error: Can't read from file NAME_OF_THE_FILE, followed by a new line, on the POSIX standard error
    


4. elf
#advanced

Write a program that displays the information contained in the ELF header at the start of an ELF file.

    Usage: elf_header elf_filename
    Displayed information: (no less, no more, do not include trailing whitespace)
        Magic
        Class
        Data
        Version
        OS/ABI
        ABI Version
        Type
        Entry point address
    

man elf, readelf

