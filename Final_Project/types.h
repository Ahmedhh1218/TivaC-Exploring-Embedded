/************************************************************************************************************************************************
*
*	File Name: types.h
*
*	Author: Ahmed Hisham Fathy Hassabou
*
*	Description: 	Header file containing typedefs for various data types with specific bit widths.
*								These typedefs provide portable and descriptive names for fundamental data types.
*								The intention is to enhance code readability, maintainability, and cross-platform compatibility.
*								Data Types:
*								- int_8:    8-bit signed integer
*								- uint_8:   8-bit unsigned integer
*								- int_8_ptr: Pointer to 8-bit signed integer
*								- uint_8_ptr: Pointer to 8-bit unsigned integer
*								- int_16:   16-bit signed integer
*								- uint_16:  16-bit unsigned integer
*								- int_16_ptr: Pointer to 16-bit signed integer
*								- uint_16_ptr: Pointer to 16-bit unsigned integer
*								- int_32:   32-bit signed integer
*								- uint_32:  32-bit unsigned integer
*								- int_32_ptr: Pointer to 32-bit signed integer
*								- uint_32_ptr: Pointer to 32-bit unsigned integer
*								- int_64:   64-bit signed integer
*								- uint_64:  64-bit unsigned integer
*								- int_64_ptr: Pointer to 64-bit signed integer
*								- uint_64_ptr: Pointer to 64-bit unsigned integer
*								- float_32: Single-precision 32-bit floating point
*								- float_32_ptr: Pointer to single-precision 32-bit floating point
*								- float_64: Double-precision 64-bit floating point
*								- float_64_ptr: Pointer to double-precision 64-bit floating point
*
*************************************************************************************************************************************************/

#ifndef TYPES_H
#define TYPES_H

typedef signed char 				int_8;
typedef unsigned char 			uint_8;
typedef signed char* 				int_8_ptr;
typedef unsigned char* 			uint_8_ptr;

typedef signed short 				int_16;
typedef unsigned short 			uint_16;
typedef signed short* 			int_16_ptr;
typedef unsigned short* 		uint_16_ptr;

typedef signed int 					int_32;
typedef unsigned int 				uint_32;
typedef signed int* 				int_32_ptr;
typedef unsigned int* 			uint_32_ptr;

typedef signed long long 		int_64;
typedef unsigned long long 	uint_64;
typedef signed long long* 	int_64_ptr;
typedef unsigned long long* uint_64_ptr;

typedef float 							float_32;
typedef float* 							float_32_ptr;
typedef double 							float_64;
typedef double* 						float_64_ptr;

#endif