/*---------------------------------------------------------------------------*/
/*!
 * \file   sweeper_simple.h
 * \author Wayne Joubert
 * \date   Wed Jan 15 16:06:28 EST 2014
 * \brief  Declarations for performing a sweep, simple version.
 * \note   Copyright (C) 2014 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
/*---------------------------------------------------------------------------*/

#ifndef _serial_c__sweeper_simple_h_
#define _serial_c__sweeper_simple_h_

#include "env.h"
#include "definitions.h"
#include "dimensions.h"
#include "arguments.h"
#include "quantities.h"

#ifdef __cplusplus
extern "C"
{
#endif

/*===========================================================================*/
/*---Struct with pointers etc. used to perform sweep---*/

typedef struct
{
  P* __restrict__  facexy;
  P* __restrict__  facexz;
  P* __restrict__  faceyz;
  P* __restrict__  vslocal;

  Dimensions       dims;
} Sweeper;

/*===========================================================================*/
/*---Pseudo-constructor for Sweeper struct---*/

void Sweeper_ctor( Sweeper*          sweeper,
                   Dimensions        dims,
                   const Quantities* quan,
                   Env*              env,
                   Arguments*        args );

/*===========================================================================*/
/*---Pseudo-destructor for Sweeper struct---*/

void Sweeper_dtor( Sweeper*     sweeper,
                   Environment* env );

/*===========================================================================*/
/*---Number of octants in an octant block---*/

static int Sweeper_noctant_per_block( const Sweeper* sweeper )
{
  return 1;
}

/*===========================================================================*/
/*---Perform a sweep---*/

void Sweeper_sweep(
  Sweeper*               sweeper,
  Pointer*               vo,
  Pointer*               vi,
  const Quantities*      quan,
  Env*                   env );

/*===========================================================================*/

#ifdef __cplusplus
} /*---extern "C"---*/
#endif

#endif /*---_sweeper_simple_h_---*/

/*---------------------------------------------------------------------------*/
