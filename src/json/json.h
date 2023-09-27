#ifndef JSON_H
# define JSON_H

typedef struct s_map
{
    void    **table;
    int     size;
}   t_map;

t_map   *json_build(int size);

t_map   *json_parse();

void    json_destroy(t_map *json);

#endif