/*---------------------------------------------------------------------------*/
/*!
 * \file   definitions_kernels.h
 * \author Wayne Joubert
 * \date   Wed Jan 15 16:06:28 EST 2014
 * \brief  Basic definitions.  Code for device kernels.
 * \note   Copyright (C) 2014 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
/*---------------------------------------------------------------------------*/

#ifndef _definitions_kernels_h_
#define _definitions_kernels_h_

#include "function_attributes.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*===========================================================================*/

/*---Initializations---*/

/*---Number of physical dimensions---*/
enum{ NDIM = 3 };

/*---Number of octant directions---*/
enum{ NOCTANT = 8 };

/*===========================================================================*/
/*---Functions to manipulate sweep directions---*/

enum{ DIR_UP = +1 };
enum{ DIR_DN = -1 };

enum{ DIR_HI = +1 };
enum{ DIR_LO = -1 };

TARGET_HD static inline int Dir_x( int octant ) { return octant & (1<<0)
                                                               ? DIR_DN*1
                                                               : DIR_UP*1; }
TARGET_HD static inline int Dir_y( int octant ) { return octant & (1<<1)
                                                               ? DIR_DN*1
                                                               : DIR_UP*1; }
TARGET_HD static inline int Dir_z( int octant ) { return octant & (1<<2)
                                                               ? DIR_DN*1
                                                               : DIR_UP*1; }

TARGET_HD static inline int Dir_inc( int dir ) { return dir; }

/*===========================================================================*/
/*---Utility functions---*/

TARGET_HD static inline int imin( const int i,
                                  const int j )
{
    return i < j ? i : j;
}

TARGET_HD static inline int imax( const int i,
                                  const int j )
{   
    return i > j ? i : j;
}   

TARGET_HD static inline int ifloor( const int i,
                                    const int j )
{
    Assert( j > 0 );

    return i >= 0 ? i/j : (i-j+1)/j;
}

TARGET_HD static inline int iceil( const int i,
                                   const int j )
{
    Assert( j > 0 );

    return - ifloor( -i, j );
}

/*===========================================================================*/

#ifdef __cplusplus
} /*---extern "C"---*/
#endif

#endif /*---_definitions_kernels_h_---*/

/*---------------------------------------------------------------------------*/
