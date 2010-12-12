/* $Id$ */

/* ftell( FILE * )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <stdio.h>
#include <limits.h>

#ifndef REGTEST

long int ftell( struct _PDCLIB_file_t * stream )
{
    /* If offset is too large for return type, report error instead of wrong
       offset value.
       FIXME: A bit too fuzzy in the head right now; stream->ungetidx should be
       in here somewhere.
    */
    if ( stream->pos.offset > ( LONG_MAX - stream->bufidx ) )
    {
        /* integer overflow */
        _PDCLIB_errno = _PDCLIB_EINVAL;
        return -1;
    }
    /* ftell() must take into account:
       - the actual *physical* offset of the file, i.e. the offset as recognized
         by the operating system (and stored in stream->pos.offset); and
       - any buffers held by PDCLib, which
         - in case of unwritten buffers, count in *addition* to the offset; or
         - in case of unprocessed pre-read buffers, count in *substraction* to
           the offset. (Remember to count ungetidx into this number.)
       Conveniently, the calculation ( ( bufend - bufidx ) + ungetidx ) results
       in just the right number in both cases:
         - in case of unwritten buffers, ( ( 0 - unwritten ) + 0 )
           i.e. unwritten bytes as negative number
         - in case of unprocessed pre-read, ( ( preread - processed ) + unget )
           i.e. unprocessed bytes as positive number.
       That is how the somewhat obscure return-value calculation works.
    */
    return (long int)( stream->pos.offset - ( ( stream->bufend - stream->bufidx ) + stream->ungetidx ) );
}

#endif

#ifdef TEST
#include <_PDCLIB_test.h>

#include <stdlib.h>

int main( void )
{
    /* Testing all the basic I/O functions individually would result in lots
       of duplicated code, so I took the liberty of lumping it all together
       here.
    */
    /* The following functions delegate their tests to here:
       fgetc fflush rewind fputc ungetc fseek
       flushbuffer seek fillbuffer prepread prepwrite
    */
    char * buffer = (char*)malloc( 4 );
    FILE * fh;
    TESTCASE( ( fh = tmpfile() ) != NULL );
    TESTCASE( setvbuf( fh, buffer, _IOLBF, 4 ) == 0 );
    TESTCASE( fputc( '1', fh ) == '1' );
    TESTCASE( fputc( '2', fh ) == '2' );
    TESTCASE( fputc( '3', fh ) == '3' );
    /* Positions incrementing as expected? */
    TESTCASE( ftell( fh ) == 3l );
    TESTCASE_NOREG( fh->pos.offset == 0l );
    TESTCASE_NOREG( fh->bufidx == 3l );
    /* Buffer properly flushed when full? */
    TESTCASE( fputc( '4', fh ) == '4' );
    TESTCASE_NOREG( fh->pos.offset == 4l );
    TESTCASE_NOREG( fh->bufidx == 0 );
    /* fflush() resetting positions as expected? */
    TESTCASE( fputc( '5', fh ) == '5' );
    TESTCASE( fflush( fh ) == 0 );
    TESTCASE( ftell( fh ) == 5l );
    TESTCASE_NOREG( fh->pos.offset == 5l );
    TESTCASE_NOREG( fh->bufidx == 0l );
    /* rewind() resetting positions as expected? */
    rewind( fh );
    TESTCASE( ftell( fh ) == 0l );
    TESTCASE_NOREG( fh->pos.offset == 0 );
    TESTCASE_NOREG( fh->bufidx == 0 );
    /* Reading back first character after rewind for basic read check */
    TESTCASE( fgetc( fh ) == '1' );
    /* TODO: t.b.c. */
    TESTCASE( fclose( fh ) == 0 );
    return TEST_RESULTS;
}

#endif

