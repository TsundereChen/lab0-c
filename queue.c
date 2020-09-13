#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
 * Create empty queue.
 * Return NULL if could not allocate space.
 */
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    if (q == NULL)
        return NULL;
    q->head = NULL;
    q->tail = NULL;
    q->len = 0;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    if (q == NULL)
        return;
    /* Free every node in the queue */
    for (unsigned int i = 0; i < q->len; i++) {
        list_ele_t *delNode;
        delNode = q->head;
        q->head = q->head->next;
        free(delNode->value);
        free(delNode);
    }
    /* Free queue */
    free(q);
}

/*
 * Attempt to insert element at head of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    list_ele_t *newh;

    /* Return false if q is NULL */
    if (q == NULL)
        return false;

    newh = malloc(sizeof(list_ele_t));
    /* Return false if malloc failed */
    if (newh == NULL)
        return false;
    newh->value = malloc(sizeof(char) * (strlen(s) + 1));
    /* Return false if malloc failed */
    if (newh->value == NULL) {
        free(newh);
        return false;
    }

    strncpy(newh->value, s, strlen(s) + 1);
    newh->next = q->head;
    q->head = newh;

    /* Also set the tail if the tail is NULL */
    /* This is in case of a newly created queue */
    if (q->tail == NULL)
        q->tail = newh;

    q->len += 1;

    return true;
}

/*
 * Attempt to insert element at tail of queue.
 * Return true if successful.
 * Return false if q is NULL or could not allocate space.
 * Argument s points to the string to be stored.
 * The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    list_ele_t *newt;

    /* Return false if q is NULL */
    if (q == NULL)
        return false;

    newt = malloc(sizeof(list_ele_t));
    /* Return false if malloc failed */
    if (newt == NULL)
        return false;
    newt->value = malloc(sizeof(char) * (strlen(s) + 1));
    /* Return false if malloc failed */
    if (newt->value == NULL) {
        free(newt);
        return false;
    }

    strncpy(newt->value, s, strlen(s) + 1);
    newt->next = NULL;
    if (q->tail != NULL)
        q->tail->next = newt;
    q->tail = newt;

    /* Also set the head if the head is NULL */
    /* This is in case of a newly created queue */
    if (q->head == NULL)
        q->head = newt;

    q->len += 1;
    return true;
}

/*
 * Attempt to remove element from head of queue.
 * Return true if successful.
 * Return false if queue is NULL or empty.
 * If sp is non-NULL and an element is removed, copy the removed string to *sp
 * (up to a maximum of bufsize-1 characters, plus a null terminator.)
 * The space used by the list element and the string should be freed.
 */
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    /* Return false if q is NULL */
    if (q == NULL)
        return false;
    /* Return false if q->head or q->tail is false */
    if (q->head == NULL || q->tail == NULL)
        return false;

    /* Copy value from head to sp first */
    if (sp != NULL) {
        strncpy(sp, q->head->value, bufsize - 1);
        sp[bufsize - 1] = '\0';
    }

    /* Create a new variable to track the node */
    list_ele_t *delNode;
    delNode = q->head;

    /* Set q->tail to NULL if there's only one element in queue */
    if (q->head == q->tail)
        q->tail = NULL;
    /* Detach the node from the queue*/
    q->head = q->head->next;

    /* Free the memory used by struct */
    free(delNode->value);
    free(delNode);

    /* Decrease the len of the queue by one */
    q->len -= 1;
    return true;
}

/*
 * Return number of elements in queue.
 * Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    if (q == NULL)
        return 0;
    return q->len;
}

/*
 * Reverse elements in queue
 * No effect if q is NULL or empty
 * This function should not allocate or free any list elements
 * (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
 * It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    if (q == NULL)
        return;
    if (q->head == NULL || q->tail == NULL)
        return;

    list_ele_t *prev, *curr, *next;
    prev = NULL;
    curr = q->head;
    next = NULL;

    q->tail = curr;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    q->head = prev;
    return;
}

/*
 * Sort elements of queue in ascending order
 * No effect if q is NULL or empty. In addition, if q has only one
 * element, do nothing.
 */
void q_sort(queue_t *q)
{
    /* TODO: You need to write the code for this function */
    /* TODO: Remove the above comment when you are about to implement. */
}
