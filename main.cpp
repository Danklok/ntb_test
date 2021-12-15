#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>

size_t num_to_str(uint64_t num, char *str, size_t str_size) {
    if (num > ULLONG_MAX) {
        return -1;
    }
    const size_t MAX_NUM_OF_DIGITS = 20;

    uint8_t num_tmp = 0;
    size_t digs_num = 0, bytes_num = 0;
    char str_tmp[MAX_NUM_OF_DIGITS + 1];

    do {
        num_tmp = num % 10;
        num /= 10; 
        str_tmp[digs_num] = num_tmp + 48;
        ++digs_num;
    } while(num);

    for (size_t i = 0; i < str_size - 1; ++i) {
        str[i] = str_tmp[digs_num - i - 1];
        ++bytes_num;
    }

    str[bytes_num] = '\0';

    return ++bytes_num; // includes '\0' symbol
}

uint64_t str_to_num(const char *str, size_t str_len) { // includes '\0' symbol?
    uint64_t num = 0;
    size_t digs_num = 0;

    while(str[digs_num] != '\0') {
        if ((str[digs_num] < 48) || (str[digs_num] > 57)) {
            return -1;
        }
        ++digs_num;
    }
    for (size_t i = 0; i < digs_num; ++i) {
        num += (str[i] - 48) * pow(10.0, digs_num - i - 1); 
    }

    return num;
}

int main(int argc, char const *argv[]) {
    const size_t str_len = 1000;
    char str[str_len];
    uint64_t num;

    num_to_str(123456789, str, str_len);
    printf("%s\n", str);

    num = str_to_num(str, str_len);
    printf("%lu\n", num);
    
    return 0;
}
