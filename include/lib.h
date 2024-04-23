/*
** EPITECH PROJECT, 2024
** lib
** File description:
** lib
*/

#ifndef __LIB__
    #define __LIB__

float deg_to_rad(float degrees);
float get_degrees(float degrees);
float rad_to_deg(float radians);
void free_array(char **array);
size_t arraylen(const char **array);
size_t array_strlen(const char **array);
size_t array_lstrlen(const char **array);
char **str_to_word_array(const char *str, const char *delim);
char **file_to_array(const char *filepath, const char *delim);
#endif /* !__LIB__ */
