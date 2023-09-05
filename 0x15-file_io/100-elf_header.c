#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define ELF_MAGIC_SIZE 4
#define ELF_CLASS_OFFSET 4
#define ELF_DATA_OFFSET 5
#define ELF_VERSION_OFFSET 6
#define ELF_OSABI_OFFSET 7
#define ELF_ABIVERSION_OFFSET 8
#define ELF_TYPE_OFFSET 16
#define ELF_ENTRY_OFFSET 24

/**
 * print_error - Prints an error message to stderr and exits with status code 98.
 * @message: The error message to print.
 */
void print_error(const char *message)
{
fprintf(stderr, "Error: %s\n", message);
exit(98);
}

int main(int argc, char *argv[])
{
if (argc != 2)
{
print_error("Usage: elf_header elf_filename");
}

const char *filename = argv[1];
int fd = open(filename, O_RDONLY);
if (fd == -1)
{
print_error("Failed to open the ELF file");
}

/* Read the first 4 bytes to check for ELF magic number */
uint8_t elf_magic[ELF_MAGIC_SIZE];
if (read(fd, elf_magic, ELF_MAGIC_SIZE) != ELF_MAGIC_SIZE || memcmp(elf_magic, "\x7fELF", ELF_MAGIC_SIZE) != 0)
{
print_error("Not an ELF file");
}

/* Seek to the beginning of the ELF header */
if (lseek(fd, 0, SEEK_SET) == -1)
{
print_error("Failed to seek to the beginning of the ELF header");
}

/* Read the ELF header */
uint8_t elf_header[64];
if (read(fd, elf_header, sizeof(elf_header)) != sizeof(elf_header))
{
print_error("Failed to read the ELF header");
}

/* Extract and print the ELF header information */
printf("Magic: ");
for (int i = 0; i < ELF_MAGIC_SIZE; i++)
{
printf("%02x ", elf_magic[i]);
}
printf("\nClass: %d-bit\n", elf_header[ELF_CLASS_OFFSET]);
printf("Data: %s-endian\n", elf_header[ELF_DATA_OFFSET] == 1 ? "little" : "big");
printf("Version: %d (current)\n", elf_header[ELF_VERSION_OFFSET]);
printf("OS/ABI: %d\n", elf_header[ELF_OSABI_OFFSET]);
printf("ABI Version: %d\n", elf_header[ELF_ABIVERSION_OFFSET]);
printf("Type: %d\n", *((uint16_t *)(elf_header + ELF_TYPE_OFFSET)));
printf("Entry point address: 0x%lx\n", *((uint64_t *)(elf_header + ELF_ENTRY_OFFSET)));

close(fd);
return (0);
}
