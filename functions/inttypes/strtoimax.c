/* $Id$ */

/* strtoimax( const char *, char * *, int )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <limits.h>
#include <inttypes.h>

#ifndef REGTEST

#include <stddef.h>

intmax_t strtoimax( const char * _PDCLIB_restrict nptr, char ** _PDCLIB_restrict endptr, int base )
{
    intmax_t rc;
    char sign = '+';
    const char * p = _PDCLIB_strtox_prelim( nptr, &sign, &base );
    if ( base < 2 || base > 36 ) return 0;
    if ( sign == '+' )
    {
        rc = (intmax_t)_PDCLIB_strtox_main( &p, (unsigned)base, (uintmax_t)INTMAX_MAX, (uintmax_t)( INTMAX_MAX / base ), (int)( INTMAX_MAX % base ), &sign );
    }
    else
    {
        rc = (intmax_t)_PDCLIB_strtox_main( &p, (unsigned)base, (uintmax_t)INTMAX_MIN, (uintmax_t)( INTMAX_MIN / -base ), (int)( -( INTMAX_MIN % base ) ), &sign );
    }
    if ( endptr != NULL ) *endptr = ( p != NULL ) ? (char *) p : (char *) nptr;
    return ( sign == '+' ) ? rc : -rc;
}

#endif

#ifdef TEST
#include <_PDCLIB_test.h>

#include <errno.h>

int main( void )
{
    char * endptr;
    /* this, to base 36, overflows even a 256 bit integer */
    char overflow[] = "-ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ_";
    /* tricky border case */
    char tricky[] = "+0xz";
    errno = 0;
    /* basic functionality */
    TESTCASE( strtoimax( "123", NULL, 10 ) == 123 );
    /* proper detecting of default base 10 */
    TESTCASE( strtoimax( "456", NULL, 0 ) == 456 );
    /* proper functioning to smaller base */
    TESTCASE( strtoimax( "14", NULL, 8 ) == 12 );
    /* proper autodetecting of octal */
    TESTCASE( strtoimax( "016", NULL, 0 ) == 14 );
    /* proper autodetecting of hexadecimal, lowercase 'x' */
    TESTCASE( strtoimax( "0xFF", NULL, 0 ) == 255 );
    /* proper autodetecting of hexadecimal, uppercase 'X' */
    TESTCASE( strtoimax( "0Xa1", NULL, 0 ) == 161 );
    /* proper handling of border case: 0x followed by non-hexdigit */
    TESTCASE( strtoimax( tricky, &endptr, 0 ) == 0 );
    TESTCASE( endptr == tricky + 2 );
    /* proper handling of border case: 0 followed by non-octdigit */
    TESTCASE( strtoimax( tricky, &endptr, 8 ) == 0 );
    TESTCASE( endptr == tricky + 2 );
    /* errno should still be 0 */
    TESTCASE( errno == 0 );
    /* overflowing subject sequence must still return proper endptr */
    TESTCASE( strtoimax( overflow, &endptr, 36 ) == INTMAX_MIN );
    TESTCASE( errno == ERANGE );
    TESTCASE( ( endptr - overflow ) == 53 );
    /* same for positive */
    errno = 0;
    TESTCASE( strtoimax( overflow + 1, &endptr, 36 ) == INTMAX_MAX );
    TESTCASE( errno == ERANGE );
    TESTCASE( ( endptr - overflow ) == 53 );
    /* testing skipping of leading whitespace */
    TESTCASE( strtoimax( " \n\v\t\f789", NULL, 0 ) == 789 );
    /* testing conversion failure */
    TESTCASE( strtoimax( overflow, &endptr, 10 ) == 0 );
    TESTCASE( endptr == overflow );
    endptr = NULL;
    TESTCASE( strtoimax( overflow, &endptr, 0 ) == 0 );
    TESTCASE( endptr == overflow );
    /* These tests assume two-complement, but conversion should work for   */
    /* one-complement and signed magnitude just as well. Anyone having a   */
    /* platform to test this on?                                           */
    errno = 0;
#if INTMAX_MAX >> 62 == 1
    /* testing "odd" overflow, i.e. base is not a power of two */
    TESTCASE( strtoimax( "9223372036854775807", NULL, 0 ) == INTMAX_MAX );
    TESTCASE( errno == 0 );
    TESTCASE( strtoimax( "9223372036854775808", NULL, 0 ) == INTMAX_MAX );
    TESTCASE( errno == ERANGE );
    errno = 0;
    TESTCASE( strtoimax( "-9223372036854775807", NULL, 0 ) == (INTMAX_MIN + 1) );
    TESTCASE( errno == 0 );
    TESTCASE( strtoimax( "-9223372036854775808", NULL, 0 ) == INTMAX_MIN );
    TESTCASE( errno == 0 );
    TESTCASE( strtoimax( "-9223372036854775809", NULL, 0 ) == INTMAX_MIN );
    TESTCASE( errno == ERANGE );
    /* testing "even" overflow, i.e. base is power of two */
    errno = 0;
    TESTCASE( strtoimax( "0x7fffffffffffffff", NULL, 0 ) == INTMAX_MAX );
    TESTCASE( errno == 0 );
    TESTCASE( strtoimax( "0x8000000000000000", NULL, 0 ) == INTMAX_MAX );
    TESTCASE( errno == ERANGE );
    errno = 0;
    TESTCASE( strtoimax( "-0x7fffffffffffffff", NULL, 0 ) == (INTMAX_MIN + 1) );
    TESTCASE( errno == 0 );
    TESTCASE( strtoimax( "-0x8000000000000000", NULL, 0 ) == INTMAX_MIN );
    TESTCASE( errno == 0 );
    TESTCASE( strtoimax( "-0x8000000000000001", NULL, 0 ) == INTMAX_MIN );
    TESTCASE( errno == ERANGE );
#elif LLONG_MAX >> 126 == 1
    /* testing "odd" overflow, i.e. base is not a power of two */
    TESTCASE( strtoimax( "170141183460469231731687303715884105728", NULL, 0 ) == INTMAX_MAX );
    TESTCASE( errno == 0 );
    TESTCASE( strtoimax( "170141183460469231731687303715884105729", NULL, 0 ) == INTMAX_MAX );
    TESTCASE( errno == ERANGE );
    errno = 0;
    TESTCASE( strtoimax( "-170141183460469231731687303715884105728", NULL, 0 ) == (INTMAX_MIN + 1) );
    TESTCASE( errno == 0 );
    TESTCASE( strtoimax( "-170141183460469231731687303715884105729", NULL, 0 ) == INTMAX_MIN );
    TESTCASE( errno == 0 );
    TESTCASE( strtoimax( "-170141183460469231731687303715884105730", NULL, 0 ) == INTMAX_MIN );
    TESTCASE( errno == ERANGE );
    /* testing "even" overflow, i.e. base is power of two */
    errno = 0;
    TESTCASE( strtoimax( "0x7fffffffffffffffffffffffffffffff", NULL, 0 ) == INTMAX_MAX );
    TESTCASE( errno == 0 );
    TESTCASE( strtoimax( "0x80000000000000000000000000000000", NULL, 0 ) == INTMAX_MAX );
    TESTCASE( errno == ERANGE );
    errno = 0;
    TESTCASE( strtoimax( "-0x7fffffffffffffffffffffffffffffff", NULL, 0 ) == (INTMAX_MIN + 1) );
    TESTCASE( errno == 0 );
    TESTCASE( strtoimax( "-0x80000000000000000000000000000000", NULL, 0 ) == INTMAX_MIN );
    TESTCASE( errno == 0 );
    TESTCASE( strtoimax( "-0x80000000000000000000000000000001", NULL, 0 ) == INTMAX_MIN );
    TESTCASE( errno == ERANGE );
#else
#error Unsupported width of 'intmax_t' (neither 64 nor 128 bit).
#endif
    return TEST_RESULTS;
}

#endif
