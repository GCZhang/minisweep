/*---------------------------------------------------------------------------*/
/*!
 * \file   array_accessors.h
 * \author Wayne Joubert
 * \date   Wed Jan 15 16:06:28 EST 2014
 * \brief  Functions for referencing special-purpose multidimensional arrays.
 * \note   Copyright (C) 2014 Oak Ridge National Laboratory, UT-Battelle, LLC.
 */
/*---------------------------------------------------------------------------*/

#ifndef _serial_c__array_accessors_h_
#define _serial_c__array_accessors_h_

#include "environment.h"
#include "definitions.h"
#include "dimensions.h"

/*---------------------------------------------------------------------------*/
/*---Multidimensional array accessor function---*/

static inline P* ref_state(
    P* __restrict__  v,
    Dimensions       dims,
    int              ix,
    int              iy,
    int              iz,
    int              ie,
    int              im,
    int              iu )
{
  assert( v );
  assert( ix >= 0 && ix < dims.nx );
  assert( iy >= 0 && iy < dims.ny );
  assert( iz >= 0 && iz < dims.nz );
  assert( ie >= 0 && ie < dims.ne );
  assert( im >= 0 && im < dims.nm );
  assert( iu >= 0 && iu < NU );

  return & v[
              im + dims.nm * (
              iu + NU      * (
              ix + dims.nx * (
              iy + dims.ny * (
              iz + dims.nz * (
              ie + dims.ne * (
              0 )))))) ];
}

/*---------------------------------------------------------------------------*/
/*---Multidimensional array accessor function---*/

static inline P* ref_v_local(
    P* __restrict__  v,
    Dimensions       dims,
    int              ia,
    int              iu )
{
  assert( v );
  assert( ia >= 0 && ia < dims.na );
  assert( iu >= 0 && iu < NU );

  return & v[
              ia + dims.na * (
              iu + NU      * (
              0 )) ];
}

/*---------------------------------------------------------------------------*/
/*---Multidimensional array accessor function---*/

static inline P* ref_a_from_m(
    P* __restrict__  v,
    Dimensions       dims,
    int              im,
    int              ia )
{
  assert( v );
  assert( im >= 0 && im < dims.nm );
  assert( ia >= 0 && ia < dims.na );

  return & v[
              im + dims.nm * (
              ia + dims.na * (
              0 )) ];
}

/*---------------------------------------------------------------------------*/
/*---Multidimensional array accessor function---*/

static inline P* ref_m_from_a(
    P* __restrict__  v,
    Dimensions       dims,
    int              im,
    int              ia )
{
  assert( v );
  assert( im >= 0 && im < dims.nm );
  assert( ia >= 0 && ia < dims.na );

  return & v[
              ia + dims.na * (
              im + dims.nm * (
              0 )) ];
}

/*---------------------------------------------------------------------------*/
/*---Multidimensional array accessor function---*/

static inline P* ref_facexy(
    P* __restrict__  v,
    Dimensions       dims,
    int              ix,
    int              iy,
    int              ie,
    int              ia,
    int              iu,
    int              ioctant )
{
  assert( ix >= 0 && ix < dims.nx );
  assert( iy >= 0 && iy < dims.ny );
  assert( ie >= 0 && ie < dims.ne );
  assert( ia >= 0 && ia < dims.na );
  assert( iu >= 0 && iu < NU );
  assert( ioctant >= 0 && ioctant < NOCTANT );

  return & v[
              ia + dims.na * (
              iu + NU      * (
              ix + dims.nx * (
              iy + dims.ny * (
              ie + dims.ne * (
              0 ))))) ];
}

/*---------------------------------------------------------------------------*/
/*---Multidimensional array accessor function---*/

static inline P* ref_facexz(
    P* __restrict__  v,
    Dimensions       dims,
    int              ix,
    int              iz,
    int              ie,
    int              ia,
    int              iu,
    int              ioctant )
{
  assert( ix >= 0 && ix < dims.nx );
  assert( iz >= 0 && iz < dims.nz );
  assert( ie >= 0 && ie < dims.ne );
  assert( ia >= 0 && ia < dims.na );
  assert( iu >= 0 && iu < NU );
  assert( ioctant >= 0 && ioctant < NOCTANT );

  return & v[
              ia + dims.na * (
              iu + NU      * (
              ix + dims.nx * (
              iz + dims.nz * (
              ie + dims.ne * (
              0 ))))) ];
}

/*---------------------------------------------------------------------------*/
/*---Multidimensional array accessor function---*/

static inline P* ref_faceyz(
    P* __restrict__  v,
    Dimensions       dims,
    int              iy,
    int              iz,
    int              ie,
    int              ia,
    int              iu,
    int              ioctant )
{
  assert( v );
  assert( iy >= 0 && iy < dims.ny );
  assert( iz >= 0 && iz < dims.nz );
  assert( ie >= 0 && ie < dims.ne );
  assert( ia >= 0 && ia < dims.na );
  assert( iu >= 0 && iu < NU );
  assert( ioctant >= 0 && ioctant < NOCTANT );

  return & v[
              ia + dims.na * (
              iu + NU      * (
              iy + dims.ny * (
              iz + dims.nz * (
              ie + dims.ne * (
              0 ))))) ];
}

/*---------------------------------------------------------------------------*/

#endif /*---_serial_c__array_accessors_h_---*/

/*---------------------------------------------------------------------------*/
