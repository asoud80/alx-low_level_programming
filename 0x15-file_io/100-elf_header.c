#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <elf.h>
#include <stdio.h>

void print_class(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void check_elf(unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);
void print_abi(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_version(unsigned char *e_ident);

/**
 * check_elf - it will checks for the File Is ELF file or not
 *
 * @e_ident:  Pointer To the Array Contains ELF Magic Nums
 * Description: Exit code 98, if File Isn't ELF File
 */

void check_elf(unsigned char *e_ident)
{
	int indx;

	for (indx = 0; indx < 4; indx++)
	{
		if (e_ident[indx] != 127 &&
		    e_ident[indx] != 'E' &&
		    e_ident[indx] != 'L' &&
		    e_ident[indx] != 'F')
		{
			dprintf(STDERR_FILENO, "error: it's not ELF File\n");
			exit(98);
		}
	}
}


/**
 * print_magic - Magic Numbs Of  ELF Header to be printed
 *
 * @e_ident: Pointer To Array that Contains ELF Magic Numbs
 * Description: the magic Nums Separated By Spaces.
 */

void print_magic(unsigned char *e_ident)
{
	int indx;

	printf("  magic:   ");

	for (indx = 0; indx < EI_NIDENT; indx++)
	{
		printf("%02x", e_ident[indx]);

		if (indx == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}


/**
 * print_class - class Of ELF Header to be printed
 *
 * @e_ident: Pointer To Array that Contains ELF Class.
 */

void print_class(unsigned char *e_ident)
{
	printf("  class:                             ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<Unknown: %x>\n", e_ident[EI_CLASS]);
	}
}


/**
 * print_data - Data Of ELF Header will be printed
 *
 * @e_ident: Pointer To Array that Contains ELF Class.
 */

void print_data(unsigned char *e_ident)
{
	printf("  data:                              ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("None\n");
		break;
	case ELFDATA2LSB:
		printf("2's Complement, Little Endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's Complement, Big Endian\n");
		break;
	default:
		printf("<Unknown: %x>\n", e_ident[EI_CLASS]);
	}
}


/**
 * print_version - Version Of ELF Header to be printed
 *
 * @e_ident: Pointer To Array that Contains ELF Version
 */

void print_version(unsigned char *e_ident)
{
	printf("  version:                           %d",
	       e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (Current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}


/**
 * print_osabi - OS/ABI Of ELF Header to be printed
 *
 * @e_ident: Pointer To Array that Contains ELF Version
 */

void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}


/**
 * print_abi - ABI Version Of ELF Header to be printed
 *
 * @e_ident: Pointer To Array that Containing ELF ABI Version.
 */

void print_abi(unsigned char *e_ident)
{
	printf("  ABI version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}


/**
 * print_type - Type Of ELF Header to be printed
 *
 * @e_type: ELF Type
 *
 * @e_ident: Pointer To Array that Contains ELF Class
 */

void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}


/**
 * print_entry - Entry Point Of ELF Header to be printed
 *
 * @e_entry: Address Of ELF Entry Point
 *
 * @e_ident: Pointer To Array that Contains ELF Class.
 */

void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  entry point Address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}


/**
 * close_elf - ELF File will beclosed
 *
 * @elf: File Descriptor Of ELF File
 * Description: Exit code 98, in case of file can't Be Closed
 */

void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"error: Cannot Close fd %d\n", elf);
		exit(98);
	}
}


/**
 * main - displays Informations that Containing The
 *        ELF Header At The Start Of ELF File
 *
 * @argc: Numb Of Argus that Supplied To a Program
 *
 * @argv: array Of Pointers To Argums
 * Return: for  success 0.
 * Description: Exit code 98,in case of File Isn't ELF file
 *              Or Function Failed 
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(o);
	return (0);
}
