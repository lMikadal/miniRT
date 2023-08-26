#ifndef UTILS_H
#define UTILS_H

void ft_error(const char *c, t_info *info);
void ft_check_len_data(char **data, int len, t_info *info);
int ft_whitespace(const char c);
int ft_range_int(int min, int max, int num);
int ft_range_double(double min, double max, double num);
int ft_strcmp(const char *s1, const char *s2);
int ft_str_is_digit(const char *s);
void ft_free_2d(char **s);
void ft_free_info(t_info *info);
int ft_count_word(const char *s, char c);
char **ft_split_whitespace(const char *s);
char **ft_split(const char *s, char c);
int ft_strlen(const char *s);
double ft_atod(const char *s, t_info *info);
int ft_atoi(const char *s, t_info *info);
t_rgb ft_set_color(const char *s, t_info *info);
void ft_set_point(t_v3d *point, char *data, t_info *info);
void ft_set_vector(t_v3d *vector, char *data, t_info *info);
int ft_color(t_rgb color);
t_hittable_list *ft_malloc_hittable(int name);

#endif