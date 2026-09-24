#include <stdint.h>
#include <stdio.h>

void bCount();
void bCount_test(uint32_t num);
int parse_uint32(const char *s, uint32_t *out);

int main(void)
{
    uint32_t t1 = 0x00000000; // 0
    uint32_t t2 = 0x00000001; // 1
    uint32_t t3 = 0x00000010; // 1
    uint32_t t4 = 0x11111111; // 8
    uint32_t t5 = 0xA0F0F0F5; // 16
    bCount_test(t1);
    bCount_test(t2);
    bCount_test(t3);
    bCount_test(t4);
    bCount_test(t5);
    bCount();

}

void bCount()
{
    printf("Enter a valid uint32_t value: ");
    // AI assistance used to find a way to verify the uint32_t compatability.
    // Comments entirely by me
    char buf[64]; // Create storage for characters in the buffer
    uint32_t num; // Create variable to store user input
    // fgets waits for user input and puts it in the variable buf, max size (sizeof buf), from the...
    //... standard input file stream.
    if (!(fgets(buf, sizeof buf, stdin)) || !(parse_uint32(buf, &num))) { // parse_uint32 is a user defined function
        printf("Invalid uint32_t"); // If either function failed we print that the uint32_t was invalid
        return; // And exit the function
    }

    unsigned int count = 0;
    while (num) {
        num &= (num-1);
        count++;
    }

    printf("Thomas Anderson says: 'Your number had %d bits set to 1.'\n", count);
}

void bCount_test(uint32_t num)
{
    unsigned int count = 0;
    while (num) {
        num &= (num-1);
        count++;
    }

    printf("Thomas Anderson says: 'Your number had %d bits set to 1.'\n", count);
}

// Takes addresses to a character array with the raw input and an empty uint32_t which will store the formated output
int parse_uint32(const char *s, uint32_t *out)
{
    uint32_t v = 0; // empty uint32_t that will store the digits
    int digits = 0; // tracks how many digits have been stored

    if (s == NULL || out == NULL) return 0; // If either address is invalid then return 0

    while (*s == ' ' || *s == '\t') s++; // skip leading whitespace - AI comment but I agree s++ moves the address forward

    for (; *s >= '0' && *s <= '9'; s++) { // Loops while the characters are digits 0-9
        uint32_t d = (uint32_t)(*s - '0'); // Changes the character into a digit value...
        //... (5 is character #53, 0 is character #48, so '5' - '0' gives 53-48 = 5)
        if (v > (UINT32_MAX - d) / 10) return 0;  // v * 10 + d would overflow - AI comment but I agree
        v = v * 10 + d; // each digit is added into the least significant digit place of v after v is shifted by multiplying by 10
        digits++; // Tracks how many digits have been added
    }

    if (digits == 0) return 0; // return 0 if the first character is not a digit

    while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r') s++; // Remove junk on the end of the input
    if (*s != '\0') return 0; // return 0 if the input did not end in a null terminator

    *out = v; // Modify the provided uint32_t before returning 1 to represent a valid uint32_t
    return 1;
}