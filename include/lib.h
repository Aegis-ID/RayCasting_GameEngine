/*
** EPITECH PROJECT, 2024
** lib
** File description:
** lib
*/

#ifndef __LIB__
    #define __LIB__

    #include <stddef.h>
    #include <stdbool.h>

bool is_strfloat(const char *str);
bool is_strdigit(const char *str);

float deg_to_rad(float degrees);
float get_deg(float degrees);
float rad_to_deg(float radians);

void free_array(char **array);

size_t arraylen(const char **array);
size_t array_strlen(const char **array);
size_t array_lstrlen(const char **array);
size_t my_strlen_delim(const char *str, const char delim);

char *clean_str(char *str, const char clean);
char **str_to_word_array(const char *str, const char *delim);
char **file_to_array(const char *filepath, const char *delim);

#endif /* !__LIB__ */
