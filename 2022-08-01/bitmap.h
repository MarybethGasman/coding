/**
 * @file bitmap.h
 * @author meng Tan (tannal.cn@gmail.com)
 * @brief int type for bitmap usage
 * @version 0.1
 * @date 2022-08-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * @brief clear all bit
 * 
 * @param bits pointer of int for bitmap structure 
 */
void bitmap_clear(int *bits);


/**
 * @brief set pos-th bit 1
 * 
 * @param bits pointer of int for bitmap structure 
 * @param pos start from 0
 */
void bitmap_set(int *bits, int pos);


/**
 * @brief reset pos-th bit 0
 * 
 * @param bits pointer of int for bitmap structure 
 * @param pos start from 0
 */
void bitmap_reset(int *bits, int pos);

/**
 * @brief get pos-th bits
 * 
 * @param bits pointer of int for bitmap structure 
 * @param pos start from 0
 * @return int 
 */
int bitmap_get(int *bits, int pos);

/**
 * @brief flip pos-th bit
 * 
 * @param bits pointer of int for bitmap structure 
 * @param pos start from 0
 * @return int 
 */
void bitmap_flip(int *bits, int pos);


