/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 15:40:02 by marvin            #+#    #+#             */
/*   Updated: 2020/04/03 15:40:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

#define VECTOR_INIT_CAPACITY 4

#define VECTOR_INIT(vec) t_vector vec; vector_init(&vec)
#define VECTOR_ADD(vec, item) vector_add(&vec, (void *) item)
#define VECTOR_SET(vec, id, item) vector_set(&vec, id, (void *) item)
#define VECTOR_GET(vec, type, id) (type) vector_get(&vec, id)
#define VECTOR_DELETE(vec, id) vector_delete(&vec, id)
#define VECTOR_TOTAL(vec) vector_total(&vec)
#define VECTOR_FREE(vec) vector_free(&vec)

typedef struct  s_vector
{
    void **items;
    int capacity;
    int size;
    void    (*new)(struct s_vector *);
    void    (*push_back)(struct s_vector *this, void *value);
    void    (*set)(struct s_vector *this, int index, void *value);
    void    *(*get)(struct s_vector *this, int index);
    void    (*delete)(struct s_vector *, int);
}               t_vector;

void    new_vector(struct s_vector *this);
void    vector_push_back(t_vector *, void *value);
void    vector_set(t_vector *this, int index, void *value);
void    *vector_get(t_vector *this, int index);
void    vector_delete(t_vector *, int);
void    vector_free(t_vector *);
void vector_resize(t_vector *v, int capacity);
int     vector_find(t_vector *v, t_string value);

#endif